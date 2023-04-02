/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_FNOR_READ_PAGE_SEG_H
#define LIBBSP_FNOR_READ_PAGE_SEG_H

#include "LIBBSP_FNOR_Globals.h"
#include "LIBBSP_FNOR_PrepareCommand.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
void LIBBSP_FNOR_ReadPageSeg(const TE_LIBBSP_SPI_Device devID, const uint32_t flashAddress, const uint32_t size, uint8_t * const buffer, TE_LIBBSP_FNOR_ErrorCode * const v_StatusFlash, const boolean_t fastRead);
/*==== END =============================================================================*/
#endif
