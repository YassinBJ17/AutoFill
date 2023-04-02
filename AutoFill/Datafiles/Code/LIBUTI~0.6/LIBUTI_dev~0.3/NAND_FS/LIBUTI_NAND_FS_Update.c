/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2021                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBUTI_NAND_FS_Update.h"
#include "LIBUTI_NAND_FS_CheckSubZone.h"
#include "LIBUTI_NAND_FS_SearchZoneByZoneId.h"
#include "LIBUTI_NAND_FS_Update_No_Loop.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
/*
 * ---- LIBUTI_NAND_FS_Update ----
 * Return where write data ine NAND memory and update the filesystem (in RAM) with these informations.
 * parameters : 
 *		- p_ZoneID (uint8_t*) : pointer on the zoneID of the zone which should be updated in the filesystem.
 * 		- v_Size (uint32_t)   : number of sectors will be written in NAND memory.
 *		- p_AddrNAND (TS_NAND_FS_RW*) : pointer on structure which contain the informations on the write location in NAND memory.
 * return : (TE_NAND_FS_UPDATE) E_NAND_FS_UPDATE_OK if the filesystem is successfully updated in MRAM.
 *								E_NAND_FS_NO_MEM_SPACE if the zone which sould be updated is full.
 *								E_NAND_FS_ZONE_NOT_FOUND if the zone indicate is not found in the filesystem.
 */
TE_NAND_FS_UPDATE LIBUTI_NAND_FS_Update(const uint8_t* const p_ZoneID, const uint64_t v_Size, TS_NAND_FS_RW* const p_AddrNAND)
{
	TE_NAND_FS_UPDATE v_Err;
	boolean_t v_Result, v_PushStart;
	TS_NAND_FS_ADDR_ZONE v_Zone;
	TS_NAND_FS_ADDR_ZONE* p_Zone = &v_Zone;
	uint64_t v_TotalSize, v_SizeLoop, v_SizeBeforeLoop;
	uint64_t *v_CurrentZoneStart, *v_CurrentZoneEnd;
	
	v_Result = LIBUTI_NAND_FS_SearchZoneByZoneId(p_ZoneID, p_Zone);
	if(v_Result)
	{
		/*{{RELAX<SYNCHRONe_C_Code_17.4,SYNCHRONe_C_Code_10.7> Array indexing used on pointer because explicit computation of the adresse v_CurrentZoneStart .*/
		/* and v_CurrentZoneEnd*/
		v_CurrentZoneStart = p_Zone->addrSubZoneStart + (p_Zone->addrZone->lastSubZone % p_Zone->addrZone->nbrSubZone);
		v_CurrentZoneEnd = p_Zone->addrSubZoneEnd + (p_Zone->addrZone->lastSubZone % p_Zone->addrZone->nbrSubZone);
		/*}}RELAX<SYNCHRONe_C_Code_17.4,SYNCHRONe_C_Code_10.7> */
		v_TotalSize = v_Size + p_Zone->addrZone->margin;
		
		/* This occur only for the first subzone */
		if((*(v_CurrentZoneStart) == 0ull) && (*(v_CurrentZoneEnd) == 0ull))
		{
			*(v_CurrentZoneStart) = p_Zone->addrZone->addrStart;
			*(v_CurrentZoneEnd) = p_Zone->addrZone->addrStart;
		}
		else
		{
			/* Nothing to do */
		}

		if((*(v_CurrentZoneEnd) + v_TotalSize) <= p_Zone->addrZone->addrEnd)
		{
			/* No Memory Loop */
			p_AddrNAND->address1 = *(v_CurrentZoneEnd);
			p_AddrNAND->size1 = v_Size;
			p_AddrNAND->address2 = 0ull;
			p_AddrNAND->size2 = 0ull;
			
			LIBUTI_NAND_FS_Update_No_Loop(v_CurrentZoneStart, v_CurrentZoneEnd, v_Size, v_TotalSize, p_Zone);
			
			v_Err = E_NAND_FS_UPDATE_OK;
			
		}
		else
		{
			/* Memory Loop */
			v_SizeBeforeLoop = p_Zone->addrZone->addrEnd - *(v_CurrentZoneEnd);
			v_SizeLoop = v_Size - v_SizeBeforeLoop;
			if(p_Zone->addrZone->way != FALSE) 
			{
				p_AddrNAND->address1 = *(v_CurrentZoneEnd);
				p_AddrNAND->size1 = v_SizeBeforeLoop;
				p_AddrNAND->address2 = p_Zone->addrZone->addrStart;
				p_AddrNAND->size2 = v_SizeLoop;
				
				/* Test should be made before compute the new v_CurrentZoneEnd */
				if(*(v_CurrentZoneEnd) <= *(v_CurrentZoneStart)) /* This is true at the first loop */
				{					
					v_PushStart = TRUE;
				}
				else
				{
					v_PushStart = FALSE;
				}
				
				if(v_SizeLoop == 0ull)
				{
					*(v_CurrentZoneEnd) = p_Zone->addrZone->addrStart + v_SizeLoop;
				}
				else
				{
					*(v_CurrentZoneEnd) = (p_Zone->addrZone->addrStart + v_SizeLoop) - 1ull;
				}
				
				/* Test should be made after compute the new v_CurrentZoneEnd */
				if((*(v_CurrentZoneEnd) >= *(v_CurrentZoneStart)) || /* This is true at the first loop */
				  (v_PushStart))  /* This is true at the second or more loop */
				{					
					*(v_CurrentZoneStart) = *(v_CurrentZoneEnd) + p_Zone->addrZone->margin;
				}
				else
				{
					/* Nothing to do */
				}
				
				if(p_Zone->addrZone->nbrSubZone > 1ul)
				{
					LIBUTI_NAND_FS_CheckSubZone(p_Zone);
				}
				else
				{
					/* Nothing to do */
				}
				v_Err = E_NAND_FS_UPDATE_OK;
			}
			else
			{
				p_AddrNAND->address1 = *(v_CurrentZoneEnd);
				p_AddrNAND->size1 = v_SizeBeforeLoop;
				p_AddrNAND->address2 = 0ull;
				p_AddrNAND->size2 = 0ull;				
				*(v_CurrentZoneEnd) = p_Zone->addrZone->addrEnd;
				/* Error : Memory area is full */
				v_Err = E_NAND_FS_NO_MEM_SPACE;
			}
		}
	}
	else
	{ 
		/* Error : ZoneId not found in the filesystem */
		v_Err = E_NAND_FS_ZONE_NOT_FOUND;
	}
	return (v_Err);
}
/*==== END =============================================================================*/
