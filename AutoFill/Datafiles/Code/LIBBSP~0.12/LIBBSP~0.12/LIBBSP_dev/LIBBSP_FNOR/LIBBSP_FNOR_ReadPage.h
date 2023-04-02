/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_FNOR_READ_PAGE_H
#define LIBBSP_FNOR_READ_PAGE_H

#include "LIBBSP_FNOR_Globals.h"
#include "LIBBSP_FNOR_ReadPageSeg.h"
#include "LIBBSP_FNOR_ReadEnable.h"
#include "LIBBSP_FNOR_ReadCheckAvailability.h"
#include "LIBBSP_FNOR_PrepareCommand.h"
#include "LIBBSP_FNOR_EnableWrite.h"
#include "LIBBSP_FNOR_Enter4B.h"
#include "LIBBSP_FNOR_Exit4B.h"
/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
TE_LIBBSP_FNOR_ErrorCode LIBBSP_FNOR_ReadPage(const TE_LIBBSP_SPI_Device devID, const uint32_t flashAddress, const uint32_t size, uint8_t * const buffer, const boolean_t fastRead);
/*==== END =============================================================================*/
#endif
