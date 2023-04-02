/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_FNOR_WRITE_NEXT_BLOCK_H
#define LIBBSP_FNOR_WRITE_NEXT_BLOCK_H

#include "LIBBSP_FNOR_Globals.h"
#include "LIBBSP_FNOR_PrepareCommand.h"
#include "LIBBSP_FNOR_WritePage.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
void LIBBSP_FNOR_WriteNextBlock(const TE_LIBBSP_SPI_Device devID, uint32_t * const v_SizeRemaining, uint32_t * const v_CurrentFlashAddress,
		                        const uint32_t v_SizeInFirstBlock, uint32_t *const v_BlockIndForLast, const uint8_t * const buffer, TE_LIBBSP_FNOR_ErrorCode * const v_StatusFlash);
/*==== END =============================================================================*/
#endif
