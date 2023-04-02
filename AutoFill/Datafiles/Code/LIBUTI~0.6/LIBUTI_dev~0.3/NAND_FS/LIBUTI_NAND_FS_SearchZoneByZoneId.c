/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2021                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBUTI_NAND_FS_SearchZoneByZoneId.h"
#include "LIBUTI_MEM.h"
/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
/*
 * ---- LIBUTI_NAND_FS_SearchZoneByZoneId ----
 * Search in the filesystem the address(in the filesystem) of a specific zone.
 * parameters : 
 * 		- p_ZoneID (uint8_t*) : pointer on the zoneID of the zone which should be found in the filesystem.
 * 		- p_Addr (TS_NAND_FS_ADDR_ZONE*) : pointer where to save the address of the zone founded.
 * return : (boolean_t) TRUE if the zoneID in parameters was found in the filesystem, FALSE otherwise.
 */
boolean_t LIBUTI_NAND_FS_SearchZoneByZoneId(const uint8_t* const p_ZoneID, TS_NAND_FS_ADDR_ZONE* const p_Addr)
{
	boolean_t v_Result = TRUE;
	TS_NAND_FS_ZONE* p_TabZoneFS[C_NAND_FS_MAX_ZONE] = {0};
	uint32_t i, v_NbrZone, v_SizeFS;
	
	v_SizeFS = LIBUTI_NAND_FS_Info((uint32_t*)&v_NbrZone, (TS_NAND_FS_ZONE**)p_TabZoneFS);
	
	if (v_SizeFS != 0ul)
	{
		for(i = 0ul; i < v_NbrZone; i++)
		{
			v_Result = LIBUTI_MEM_MemsNotEqual((uint8_t*)((*(p_TabZoneFS + i))->zoneID), p_ZoneID, (uint32_t)C_NAND_FS_LEN_ZONE_ID); /* %RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_17.4> Array indexxing because explicit computation of address */
			if(v_Result == FALSE) /* Zone id is the same */
			{
				p_Addr->addrZone = p_TabZoneFS[i];
				p_Addr->addrSubZoneStart = (uint64_t*)((uint32_t)p_Addr->addrZone + C_SIZE_ZONE_FS); /* %RELAX<SYNCHRONe_C_Code_10.3,SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1,SYNCHRONe_C_Code_17.4> Pointer conversion because explicit computation of address */
				p_Addr->addrSubZoneEnd = (uint64_t*)(p_Addr->addrSubZoneStart + p_Addr->addrZone->nbrSubZone); /* %RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_17.4> Array indexxing because explicit computation of address */
				break;
			}
			else
			{
				/* Nothing to do */
			}
		}
	}
	v_Result = !v_Result;
	return v_Result;
}
/*==== END =============================================================================*/
