/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_ENVM_READ_MEGATICE_H
#define LIBBSP_ENVM_READ_MEGATICE_H

#include "LIBBSP_ENVM_Globals.h"

/*==== Definitions =====================================================================*/
/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
void LIBBSP_ENVM_Read_Megatice(const uint32_t address, const uint32_t size, uint8_t * const buffer, TE_LIBBSP_ENVM_ErrorCode * const v_ret);

/*==== END =============================================================================*/
#endif
