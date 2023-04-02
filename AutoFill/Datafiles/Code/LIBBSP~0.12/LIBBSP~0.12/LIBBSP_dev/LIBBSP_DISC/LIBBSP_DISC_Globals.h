/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */

#ifndef LIBBSP_DISC_GLOBALS_H
#define LIBBSP_DISC_GLOBALS_H

#include "LIBBSP_DISC.h"

#define C_DISC_NB_MAX7312_CONF (5)

extern const uint16_t C_DISC_MASK_FIRST_BYTE;
extern const uint8_t C_DISC_MAX7312_IO_EXP1_ADDR;
extern const uint8_t C_DISC_MAX7312_IO_EXP2_ADDR;
extern const TE_LIBBSP_I2C_Bus C_DISC_MAX7312_USED_BUS;
extern const TE_LIBBSP_I2C_FreqDiv C_DISC_MAX7312_DIVISOR_VALUE;
extern const uint8_t C_DISC_MAX7312_DIGITAL_FILTER;

extern const TS_LIBBSP_DISC_Max7312ConfCouple C_DISC_MAX7312_CONF_EXP_1 [C_DISC_NB_MAX7312_CONF];
extern const TS_LIBBSP_DISC_Max7312ConfCouple C_DISC_MAX7312_CONF_EXP_2 [C_DISC_NB_MAX7312_CONF];

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

/*==== END =============================================================================*/

#endif