/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_MRAM_WRITE_BLOCK_H
#define LIBBSP_MRAM_WRITE_BLOCK_H

#include "LIBBSP_MRAM_Globals.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
TE_LIBBSP_MRAM_ErrorCode LIBBSP_MRAM_WriteBlock(const uint32_t        mramAddress,
                                                const uint32_t        size,
                                                const uint8_t * const buffer);
/*==== END =============================================================================*/
#endif
