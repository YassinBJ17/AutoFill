/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_FNOR_WRITE_CHECK_AVAILABILITY_H
#define LIBBSP_FNOR_WRITE_CHECK_AVAILABILITY_H

#include "LIBBSP_FNOR_Globals.h"
#include "LIBBSP_FNOR_PrepareCommand.h"
#include "LIBBSP_FNOR_WritePage.h"
/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
void LIBBSP_FNOR_WriteCheckAvailability(const TE_LIBBSP_SPI_Device devID, TE_LIBBSP_FNOR_ErrorCode * const v_StatusFlash);
/*==== END =============================================================================*/
#endif
