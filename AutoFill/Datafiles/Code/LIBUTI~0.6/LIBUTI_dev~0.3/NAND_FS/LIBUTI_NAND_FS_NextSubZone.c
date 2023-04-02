/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2021                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBUTI_NAND_FS_NextSubZone.h"
#include "LIBUTI_NAND_FS_SearchZoneByZoneId.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
/*
 * ---- LIBUTI_NAND_FS_NextSubZone ----
 * Increment the last subzone and initialize it. Function is uses for zone with multiple subzone. 
 * This function need to be used before each new flight after the first flight.
 * parameters :
 * 		- p_ZoneID (uint8_t*) : pointer on the zoneID of the zone which should be incremented in the filesystem.
 * return : (boolean_t) TRUE if the v_ZoneID has been found in the filesystem, FALSE otherwise (not found or the zone contain only one subzone).
 */
/*{{RELAX<SYNCHRONe_C_Code_17.4> Array indexing used on pointer because explicit computation of the adresse v_NextZoneStart, .*/
/* v_NextZoneEnd and v_PreviousZoneEnd*/
boolean_t LIBUTI_NAND_FS_NextSubZone(const uint8_t* const p_ZoneID)
{
	boolean_t v_Result;
	TS_NAND_FS_ADDR_ZONE v_Zone;
	TS_NAND_FS_ADDR_ZONE* p_Zone = &v_Zone;
	uint64_t *v_NextZoneStart, *v_PreviousZoneEnd, *v_NextZoneEnd;
	
	v_Result = LIBUTI_NAND_FS_SearchZoneByZoneId(p_ZoneID, p_Zone);
	if((v_Result) && (p_Zone->addrZone->nbrSubZone > 1ul))
	{
		p_Zone->addrZone->lastSubZone = p_Zone->addrZone->lastSubZone + 1;
		v_NextZoneStart = p_Zone->addrSubZoneStart + (p_Zone->addrZone->lastSubZone % p_Zone->addrZone->nbrSubZone);
		v_NextZoneEnd = p_Zone->addrSubZoneEnd + (p_Zone->addrZone->lastSubZone % p_Zone->addrZone->nbrSubZone);
		
		v_PreviousZoneEnd = p_Zone->addrSubZoneEnd + ((p_Zone->addrZone->lastSubZone - 1ul) % p_Zone->addrZone->nbrSubZone);
		*(v_NextZoneStart) = *(v_PreviousZoneEnd);
		*(v_NextZoneEnd) = *(v_PreviousZoneEnd);
	}
	else
	{ 
		/* Error : ZoneId not found in the filesystem or only one subzone in this area */
		v_Result = FALSE;
	}
	return v_Result;
}
/*}}RELAX<SYNCHRONe_C_Code_17.4> */
/*==== END =============================================================================*/
