/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_MRAM_GLOBALS_H
#define LIBBSP_MRAM_GLOBALS_H

#include "LIBBSP_MRAM.h"
#include "LIBBSP_CMN.h"

/*==== Definitions =====================================================================*/
#define C_MRAM_ADDRESS_MIN 0x0000
#define C_MRAM_ADDRESS_MAX 0x80000

extern const uint32_t C_MRAM_PRESCALE;
extern const uint32_t C_MRAM_CHAR_LENGTH;
extern const uint8_t C_MRAM_STATUS_REGISTER;

extern const uint32_t C_MRAM_FIRST_MSB_BYTE;
extern const uint32_t C_MRAM_SECOND_MSB_BYTE;
extern const uint32_t C_MRAM_SECOND_LSB_BYTE;

extern const uint32_t C_MRAM_SHIFT_16_BITS;
extern const uint32_t C_MRAM_SHIFT_8_BITS;
/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

/*==== END =============================================================================*/
#endif
