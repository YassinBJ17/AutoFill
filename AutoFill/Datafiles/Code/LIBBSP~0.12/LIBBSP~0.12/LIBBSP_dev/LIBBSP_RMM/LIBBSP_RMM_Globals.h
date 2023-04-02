/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2022                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_RMM_GLOBALS_H
#define LIBBSP_RMM_GLOBALS_H

#include "LIBBSP_RMM.h"
#include "Memcpy.h"

/*==== Definitions =====================================================================*/
extern const uint8_t C_RMM_24FC1025_B0_ADDR;
extern const uint8_t C_RMM_24FC1025_B1_ADDR;
extern const TE_LIBBSP_I2C_Bus C_RMM_USED_BUS;
extern const TE_LIBBSP_I2C_FreqDiv C_RMM_DIVISOR_VALUE;
extern const uint8_t C_RMM_DIGITAL_FILTER;

extern uint8_t V_RMMWriteBuffer[C_RMM_PAGE_SIZE + 2];

extern TE_LIBBSP_RMM_State V_RMM_State;
/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

/*==== END =============================================================================*/
#endif
