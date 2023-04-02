/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_ETR_Globals.h"


/*==== Definitions =====================================================================*/
const uint8_t C_ETR_DS1682_ADDRESS = 0x6B;
const TE_LIBBSP_I2C_Bus C_ETR_DS1682_USED_BUS      = E_LIBBSP_I2C_BUS_1;
const TE_LIBBSP_I2C_FreqDiv C_ETR_DS1682_DIVISOR_VALUE = E_LIBBSP_I2C_DIV_1024;
const uint8_t C_ETR_DS1682_DIGITAL_FILTER = 0x10;


TE_LIBBSP_ETR_Ds1682State V_ETR_DS1682_State;


const uint32_t C_ETR_SHIFT_8_BITS = 8;
const uint32_t C_ETR_SHIFT_16_BITS = 16;
const uint32_t C_ETR_SHIFT_24_BITS = 24;
/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

/*==== END =============================================================================*/
