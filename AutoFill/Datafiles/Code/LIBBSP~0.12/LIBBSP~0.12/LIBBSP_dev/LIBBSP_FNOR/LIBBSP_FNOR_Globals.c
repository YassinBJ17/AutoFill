/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/

#include "LIBBSP_FNOR_Globals.h"

/* Standard FLASH operating code */
/* const uint8_t C_FNOR_RSTE              = 0x66; */  /* Reset enable */
/* const uint8_t C_FNOR_RSTM              = 0x99; */  /* Reset memory */
/* const uint8_t C_FNOR_RNCR              = 0xB5; */  /* Read non volatile configuration register */
/* const uint8_t C_FNOR_WNCR              = 0xB1; */  /* Write non volatile configuration register */
/* const uint8_t C_FNOR_RVCR              = 0x85; */  /* Read volatile configuration register */
/* const uint8_t C_FNOR_WVCR              = 0x81; */  /* Write volatile configuration register */
/* const uint8_t C_FNOR_RDID              = 0x9F; */  /* Read Identification */
/* const uint8_t C_FNOR_RFSR              = 0x70; */  /* Read flag status register */
const uint8_t C_FNOR_CFSR              = 0x50;     /* Clear flag status register */
const uint8_t C_FNOR_WREN              = 0x06;     /* Write enable */
/* const uint8_t C_FNOR_WRDIS             = 0x04; */  /* Write disable */
/* const uint8_t C_FNOR_DIEE              = 0xC4; */  /* Die Erase only for FLASHPART1 */
/* const uint8_t C_FNOR_BULKE             = 0xC7; */  /* Bulk Erase only for FLASHPART2 */
/* const uint8_t C_FNOR_SE                = 0xD8; */     /* Sector Erase */
/* const uint8_t C_FNOR_SUBSE             = 0x20; */     /* Sub-Sector Erase */
/* const uint8_t C_FNOR_PAGEP             = 0x02; */     /* Write command (page program) */
/* const uint8_t C_FNOR_READ              = 0x13; */     /* Read command 4-byte address */
/* const uint8_t C_FNOR_DUALREAD          = 0x3C; */     /* Dual read command 4-byte address */
const uint8_t C_FNOR_ENTER4B           = 0xB7;     /* Enter 4 bytes addressing mode */
/* const uint8_t C_FNOR_EXIT4B            = 0xE9; */     /* Exit 4 bytes addressing mode */
/* const uint8_t C_FNOR_RDSR              = 0x05; */     /* Read status register */

const uint32_t C_FNOR_CHAR_LENGTH = 7;
const uint32_t C_FNOR_CS_CLOCK_GAP = 2;

const uint32_t C_FNOR_SHIFT_24_BITS = 24;
const uint32_t C_FNOR_SHIFT_16_BITS = 16;
const uint32_t C_FNOR_SHIFT_8_BITS = 8;

const uint32_t C_FNOR_MASK_FIRST_LSB_BYTE = 0xFF000000;
const uint32_t C_FNOR_MASK_SECOND_LSB_BYTE = 0x00FF0000;
const uint32_t C_FNOR_MASK_SECOND_MSB_BYTE = 0x0000FF00;
const uint32_t C_FNOR_MASK_FIRST_MSB_BYTE = 0x000000FF;
uint8_t V_FNOR_WriteBuffer[C_FNOR_EXCHANGE_SIZE_OUT];
const uint32_t C_FNOR_TIMEOUT = 1000;
