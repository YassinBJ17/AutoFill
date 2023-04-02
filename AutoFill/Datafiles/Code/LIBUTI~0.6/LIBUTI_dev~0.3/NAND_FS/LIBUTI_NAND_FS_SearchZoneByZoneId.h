/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2021                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBUTI_NAND_FS_SEARCHZONEBYZONEID_H
#define LIBUTI_NAND_FS_SEARCHZONEBYZONEID_H

#include "LIBUTI_NAND_FS.h"
#include "LIBUTI_NAND_FS_Global.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
boolean_t LIBUTI_NAND_FS_SearchZoneByZoneId(const uint8_t* const p_ZoneID, TS_NAND_FS_ADDR_ZONE* const p_Addr);
/*==== END =============================================================================*/
#endif
