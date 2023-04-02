/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2022                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBUTI_NAND_FS_Update_No_Loop.h"
#include "LIBUTI_NAND_FS_CheckSubZone.h"
#include "LIBUTI_NAND_FS_SearchZoneByZoneId.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/


void LIBUTI_NAND_FS_Update_No_Loop(uint64_t * const v_CurrentZoneStart, uint64_t * const v_CurrentZoneEnd, const uint64_t v_Size, const uint64_t v_TotalSize,TS_NAND_FS_ADDR_ZONE* const p_Zone)
{

	/* Test should be made before compute the new v_CurrentZoneEnd */
	if((*(v_CurrentZoneStart) > *(v_CurrentZoneEnd)) && 
	((*(v_CurrentZoneEnd) + v_TotalSize) > *(v_CurrentZoneStart)))
	{
		*(v_CurrentZoneEnd) += v_Size;
		/* v_CurrentZoneStart should be compute after compute the new v_CurrentZoneEnd */
		*(v_CurrentZoneStart) = *(v_CurrentZoneEnd) + p_Zone->addrZone->margin;
	}
	else
	{
		*(v_CurrentZoneEnd) += v_Size;
	}
	
	if(p_Zone->addrZone->nbrSubZone > 1ul)
	{
		LIBUTI_NAND_FS_CheckSubZone(p_Zone);
	}
	else
	{
		/* Nothing to do */
	}
	
}