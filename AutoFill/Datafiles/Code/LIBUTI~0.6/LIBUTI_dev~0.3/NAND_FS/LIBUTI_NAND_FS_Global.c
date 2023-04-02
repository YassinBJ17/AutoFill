/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2021                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBUTI_NAND_FS_Global.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

uint8_t* P_addrFSRam; /* Address where start the filesystem after the filesystem header */
TS_LIBUTI_NAND_FS_HEADER* P_NAND_FS_Header; /* Address where start the filesystem header */
TS_NAND_FS_MRAM_ADDR V_NAND_FS_MRAM_Addr;

/*==== Services ========================================================================*/

/*==== END =============================================================================*/
