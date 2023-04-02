/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2021                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBUTI_NAND_FS_GLOBAL_H
#define LIBUTI_NAND_FS_GLOBAL_H

#include "LIBUTI_NAND_FS.h"
#include "LIBUTI_NAND_FS_Types.h"

/*==== Definitions =====================================================================*/

#define C_SIZE_HEADER_FS (uint32_t)sizeof(TS_LIBUTI_NAND_FS_HEADER)    /* Header size */
#define C_SIZE_FS	     (uint32_t)((uint32_t)C_NAND_FS_SIZE - C_SIZE_HEADER_FS) /* FS size without the header */
#define C_SIZE_ZONE_FS   (uint32_t)sizeof(TS_NAND_FS_ZONE)			   /* Size of one zone (without subzone) */

#define C_SIZE_CRC		(uint32_t)sizeof(uint16_t)

extern uint8_t* P_addrFSRam;
extern TS_LIBUTI_NAND_FS_HEADER* P_NAND_FS_Header;
extern TS_NAND_FS_MRAM_ADDR V_NAND_FS_MRAM_Addr;

#endif
