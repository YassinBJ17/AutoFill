/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2021                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_ENVM_WRITECTRL_COMPAGNON_H
#define LIBBSP_ENVM_WRITECTRL_COMPAGNON_H

#include "LIBBSP_ENVM_Globals.h"
#include "LIBBSP_ENVM_Configure.h"
#include "LIBBSP_ENVM_Read_Compagnon.h"
#include "LIBBSP_ENVM_Write.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

extern void LIBBSP_ENVM_WriteCtrl_Compagnon(const uint32_t address, const uint32_t size, const uint8_t * const buffer, TE_LIBBSP_ENVM_ErrorCode * const v_ret);

/*==== END =============================================================================*/
#endif
