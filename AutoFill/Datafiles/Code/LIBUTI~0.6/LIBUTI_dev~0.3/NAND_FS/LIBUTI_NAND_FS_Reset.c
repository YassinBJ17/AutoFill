/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2021                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBUTI_NAND_FS_Reset.h"
#include "LIBUTI_NAND_FS_SearchZoneByZoneId.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
/* 
 * ---- LIBUTI_NAND_FS_Reset ----
 * Reset to 0 the address of the area or a specific subzone in this area.
 * parameters :
 * 		- p_ZoneID (uint8_t*)  : pointer on the zoneID of the zone which should be found in the filesystem.
 *		- v_SubZone (uint32_t) : OPTIONAL If different to 0 look for the v_SubZone last subzone (1 is the last subzone) in the zone find with p_ZoneID.
 * return : (boolean_t) TRUE when the zone has been reset, FALSE otherwise.
 */
/*{{RELAX<SYNCHRONe_C_Code_17.4> Array indexing used on pointer because explicit computation of the adresse addrSubZoneStart .*/
/* and addrSubZoneEnd*/
boolean_t LIBUTI_NAND_FS_Reset(const uint8_t* const v_ZoneID, const uint32_t v_SubZone)
{
	boolean_t v_Result;
	TS_NAND_FS_ADDR_ZONE v_Zone;
	TS_NAND_FS_ADDR_ZONE* p_Zone = &v_Zone;
	uint32_t i, v_LastSubZone;
	
	/*uint8_t* p_allString = "ALL"; Reset all zones - To be implemented */
	
	v_Result = LIBUTI_NAND_FS_SearchZoneByZoneId(v_ZoneID, p_Zone);
	if(v_Result)
	{
		if(v_SubZone == 0ul) /* Reset all the area */
		{
			for(i = 0ul; i < p_Zone->addrZone->nbrSubZone; i++)
			{
				*(p_Zone->addrSubZoneStart + i) = 0ull;
				*(p_Zone->addrSubZoneEnd + i) = 0ull;
				p_Zone->addrZone->lastSubZone = 0ul;
			}
		}
		else /* Reset a specific subzone */
		{
			v_LastSubZone = ((p_Zone->addrZone->lastSubZone - v_SubZone) + 1ul) % p_Zone->addrZone->nbrSubZone;
			*(p_Zone->addrSubZoneStart + v_LastSubZone) = 0ull;
			*(p_Zone->addrSubZoneEnd + v_LastSubZone) = 0ull;
		}
	}
	else
	{ 
		/* Error : ZoneId not found in the filesystem */
		/* Nothing to do */
	}
	return v_Result;
} 
/*}}RELAX<SYNCHRONe_C_Code_17.4> */
/*==== END =============================================================================*/
