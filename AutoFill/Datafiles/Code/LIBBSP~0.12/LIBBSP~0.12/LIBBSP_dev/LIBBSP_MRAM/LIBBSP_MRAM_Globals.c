/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_MRAM_Globals.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/
const uint32_t C_MRAM_PRESCALE = 0x2;
const uint32_t C_MRAM_CHAR_LENGTH = 0x7;
const uint8_t C_MRAM_STATUS_REGISTER = 0x2;

const uint32_t C_MRAM_FIRST_MSB_BYTE = 0x000000FF;
const uint32_t C_MRAM_SECOND_MSB_BYTE = 0x0000FF00;
const uint32_t C_MRAM_SECOND_LSB_BYTE = 0x00FF0000;

const uint32_t C_MRAM_SHIFT_16_BITS = 16;
const uint32_t C_MRAM_SHIFT_8_BITS = 8;

/*==== Services ========================================================================*/

/*==== END =============================================================================*/
