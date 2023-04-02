/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2021                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBUTI_NAND_FS_Read.h"
#include "LIBUTI_NAND_FS_SearchZoneByZoneId.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
/* 
 * ---- LIBUTI_NAND_FS_Read ----
 * Get the address of the data in NAND flash memory for a specific zone. If the field <size1> returned is equal to 0 the zone or the subzone is empty.
 * parameters :
 * 		- p_ZoneID (uint8_t*) : pointer on the zoneID of the zone which should be found in the filesystem.
 * 		- p_AddrNAND (TS_NAND_FS_RW*) : pointer on struct where save the address of the data in the NAND memory.
 *		- v_SubZone (uint32_t) : OPTIONAL If different to 0 look for the v_SubZone last subzone (1 is the last subzone written) in the zone find with p_ZoneID.
 * return : (boolean_t) TRUE if the p_ZoneID has been found in the filesystem and the {v_SubZone} exist (if different from 0), FALSE otherwise.
 */
boolean_t LIBUTI_NAND_FS_Read(const uint8_t* const p_ZoneID, const uint32_t v_SubZone, TS_NAND_FS_RW* const p_AddrNAND)
{
	boolean_t v_Result;
	TS_NAND_FS_ADDR_ZONE v_Zone;
	TS_NAND_FS_ADDR_ZONE* p_Zone = &v_Zone;
	uint64_t v_StartAddrZone;
	uint64_t v_EndAddrZone;
	uint32_t v_LastSubZone;
	uint64_t * p_StartAddrZone;
	uint64_t * p_EndAddrZone;
	
	v_StartAddrZone = 0ull;
	v_EndAddrZone = 0ull;
	v_Result = LIBUTI_NAND_FS_SearchZoneByZoneId(p_ZoneID, p_Zone);
	if(v_Result)
	{
		if(v_SubZone == 0ul) /* Look for the entire zone*/
		{
			v_StartAddrZone = p_Zone->addrZone->addrStart;
			v_EndAddrZone = p_Zone->addrZone->addrEnd;
		}
		else /* Look for a particular subzone*/
		{
			/* Robustess test : if the user ask for a subzone outside the range */
			if(v_SubZone <= (p_Zone->addrZone->lastSubZone + 1ul)) 
			{				
				v_LastSubZone = ((p_Zone->addrZone->lastSubZone + 1ul) - v_SubZone) % p_Zone->addrZone->nbrSubZone;

				/*{{RELAX<SYNCHRONe_C_Code_17.4,SYNCHRONe_C_Code_10.7> Array indexing used on pointer because explicit computation of the adresse p_StartAddrZone .*/
				/* and p_EndAddrZone*/				
				p_StartAddrZone = (p_Zone->addrSubZoneStart + v_LastSubZone);
				v_StartAddrZone = *p_StartAddrZone;
				p_EndAddrZone = (p_Zone->addrSubZoneEnd + v_LastSubZone);
				v_EndAddrZone = *p_EndAddrZone;
				/*}}RELAX<SYNCHRONe_C_Code_17.4,SYNCHRONe_C_Code_10.7> */
			}
			else
			{
				v_Result = FALSE;
			}
		}
		
		if(v_Result)
		{
			if((v_EndAddrZone > v_StartAddrZone) || /* No loop */
			  ((v_EndAddrZone == v_StartAddrZone) && (p_Zone->addrZone->margin != 0ull))) /* Zone isn't initialized */
			{
				p_AddrNAND->address1 = v_StartAddrZone;
				p_AddrNAND->size1 = v_EndAddrZone - v_StartAddrZone;	
				p_AddrNAND->address2 = 0ull;
				p_AddrNAND->size2 = 0ull;
			}
			else
			{   /* Zone is initialized or (subzone > 1 and isn't initialized) */
				if(p_Zone->addrZone->nbrSubZone > (uint32_t)1)
				{
					p_AddrNAND->address1 = v_StartAddrZone;
					p_AddrNAND->size1 = v_EndAddrZone - v_StartAddrZone;	
					p_AddrNAND->address2 = 0ull;
					p_AddrNAND->size2 = 0ull;
				}
				else
				{
					p_AddrNAND->address1 = v_StartAddrZone;
					p_AddrNAND->size1 = (p_Zone->addrZone->addrEnd - v_StartAddrZone);
					p_AddrNAND->address2 = (p_Zone->addrZone->addrStart);
					p_AddrNAND->size2 = (v_EndAddrZone - p_Zone->addrZone->addrStart);					
				}
			}
		}
		else
		{
			/* Error : v_SubZone is out of range */
			/* Nothing to do */
		}
	}
	else
	{
		/* Error : ZoneId not found in the filesystem */
		/* Nothing to do */
	}
	return v_Result;
}
/*==== END =============================================================================*/
