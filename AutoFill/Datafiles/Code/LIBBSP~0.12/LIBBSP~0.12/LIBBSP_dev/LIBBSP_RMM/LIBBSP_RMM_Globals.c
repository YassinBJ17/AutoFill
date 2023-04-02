/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_RMM_Globals.h"

/*==== Definitions =====================================================================*/

const uint8_t C_RMM_24FC1025_B0_ADDR            = 0x53;
const uint8_t C_RMM_24FC1025_B1_ADDR            = 0x57;
const TE_LIBBSP_I2C_Bus C_RMM_USED_BUS          = E_LIBBSP_I2C_BUS_2;
const TE_LIBBSP_I2C_FreqDiv C_RMM_DIVISOR_VALUE = E_LIBBSP_I2C_DIV_1024;
const uint8_t C_RMM_DIGITAL_FILTER              = 0x10;

uint8_t V_RMMWriteBuffer[C_RMM_PAGE_SIZE + 2];

TE_LIBBSP_RMM_State V_RMM_State;

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

/*==== END =============================================================================*/
