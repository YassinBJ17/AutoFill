/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_ENVM_READADDRS_MEGATICE_H
#define LIBBSP_ENVM_READADDRS_MEGATICE_H

#include "LIBBSP_ENVM_Globals.h"
#include "LIBBSP_ENVM_ReadAddrs.h"
#include "LIBBSP_ENVM_Configure.h"

/*==== Definitions =====================================================================*/
/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
void LIBBSP_ENVM_ReadAddrs_Megatice(const uint32_t * const v_read_add_envm, const uint32_t v_nb_word,
							uint32_t * const v_read_data, TE_LIBBSP_ENVM_ErrorCode * const v_ret);

/*==== END =============================================================================*/
#endif
