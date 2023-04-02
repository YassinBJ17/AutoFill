/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2021                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBUTI_NAND_FS_CheckSubZone.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
/*
 * ---- LIBUTI_NAND_FS_CheckSubZone ----
 * Look if the currently subzone updated erase another subzone.
 * parameters : 
 * 		- p_Zone (TS_NAND_FS_ADDR_ZONE*) : address of the zone which is currently updated.
 * return : void
 */

/*{{RELAX<SYNCHRONe_C_Code_17.4>*/
/* Array indexing are done on p_Zone->addrSubZoneStart and p_Zone->addrSubZoneEnd to calculate  */
/* addrSubZoneStart and addrSubZoneEnd of the other subzones. */ 
/* Array index is tested by the instruction for to avoid overflow */
 
void LIBUTI_NAND_FS_CheckSubZone(TS_NAND_FS_ADDR_ZONE* const p_Zone) /* %RELAX<SYNCHRONe_C_Code_8.18> p_Zone is input/output */
{
	uint32_t i;	
	uint32_t v_CurrentZone = (p_Zone->addrZone->lastSubZone % p_Zone->addrZone->nbrSubZone);

	for(i = 0ul; i < p_Zone->addrZone->nbrSubZone; i++)
	{
		if(i != v_CurrentZone)
		{
			/* start or end i > start and < end current */
			/* Subzone was erased by the current subzone */
			if(*(p_Zone->addrSubZoneStart + v_CurrentZone) > *(p_Zone->addrSubZoneEnd + v_CurrentZone))
			{
				if(*(p_Zone->addrSubZoneStart + i) < *(p_Zone->addrSubZoneEnd + v_CurrentZone))
				{
					*(p_Zone->addrSubZoneStart + i) = 0ull;
					*(p_Zone->addrSubZoneEnd + i) = 0ull;
				}
				else
				{
					/* Nothing to do */
				}
			}
			else
			{
				if((*(p_Zone->addrSubZoneEnd + i) > *(p_Zone->addrSubZoneStart + v_CurrentZone)) &&
				  (*(p_Zone->addrSubZoneStart + i) < *(p_Zone->addrSubZoneEnd + v_CurrentZone)))
				{
					*(p_Zone->addrSubZoneStart + i) = 0ull;
					*(p_Zone->addrSubZoneEnd + i) = 0ull;
				}
				else
				{
					/* Nothing to do */
				}
			}
		}
		else
		{
			/* Ignore the current zone */
		}
	}
}

/*}}RELAX<SYNCHRONe_C_Code_17.4> */
/*==== END =============================================================================*/
