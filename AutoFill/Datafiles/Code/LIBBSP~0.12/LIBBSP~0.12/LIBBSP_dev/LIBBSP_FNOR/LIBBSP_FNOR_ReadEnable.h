/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_FNOR_READ_ENABLE_H
#define LIBBSP_FNOR_READ_ENABLE_H

#include "LIBBSP_FNOR_Globals.h"
#include "LIBBSP_FNOR_PrepareCommand.h"
#include "LIBBSP_FNOR_EnableWrite.h"
#include "LIBBSP_FNOR_Exit4B.h"
/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
void LIBBSP_FNOR_ReadEnable(const TE_LIBBSP_SPI_Device devID, TE_LIBBSP_FNOR_ErrorCode * const v_StatusFlash);
/*==== END =============================================================================*/
#endif
