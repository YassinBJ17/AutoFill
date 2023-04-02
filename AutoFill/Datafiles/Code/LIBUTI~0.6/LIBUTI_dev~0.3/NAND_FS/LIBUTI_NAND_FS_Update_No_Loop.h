/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2022                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBUTI_NAND_FS_UPDATE_NO_LOOP_H
#define LIBUTI_NAND_FS_UPDATE_NO_LOOP_H

#include "LIBUTI_NAND_FS.h"
#include "LIBUTI_NAND_FS_Global.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
void LIBUTI_NAND_FS_Update_No_Loop(uint64_t * const v_CurrentZoneStart, uint64_t * const v_CurrentZoneEnd, const uint64_t v_Size, const uint64_t v_TotalSize,TS_NAND_FS_ADDR_ZONE* const p_Zone);
/*==== END =============================================================================*/
#endif