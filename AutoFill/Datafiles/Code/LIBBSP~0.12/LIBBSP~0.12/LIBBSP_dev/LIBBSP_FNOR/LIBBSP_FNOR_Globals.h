/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_FNOR_GLOBALS_H_
#define LIBBSP_FNOR_GLOBALS_H_
#include "LIBBSP_FNOR.h"
#include "LIBBSP_FNOR_Types.h"
#include "LIBBSP_SPI.h"
#include "LIBBSP_CMN.h"


#define C_FNOR_PAGE_SIZE 256ul

#define C_FNOR_ADDRESS_MIN 0x00000000
#define C_FNOR_ADDRESS_MAX 0x03FFFFFF

/* Standard FLASH operating code */
/* extern uint8_t C_FNOR_RSTE; */     /* Reset enable */
/* extern uint8_t C_FNOR_RSTM; */     /* Reset memory */
/* extern uint8_t C_FNOR_RNCR; */    /* Read non volatile configuration register */
/* extern uint8_t C_FNOR_WNCR; */    /* Write non volatile configuration register */
/* extern uint8_t C_FNOR_RVCR; */    /* Read volatile configuration register */
/* extern uint8_t C_FNOR_WVCR; */     /* Write volatile configuration register */
/* extern uint8_t C_FNOR_RDID; */    /* Read Identification */
/* extern uint8_t C_FNOR_RFSR; */     /* Read flag status register */
/*extern uint8_t C_FNOR_CFSR;*/    /* Clear flag status register */
/*extern uint8_t C_FNOR_WREN;    */ /* Write enable */
/* extern uint8_t C_FNOR_WRDIS; */   /* Write disable */
/* extern uint8_t C_FNOR_DIEE;  */   /* Die Erase only for FLASHPART1 */
/* extern uint8_t C_FNOR_BULKE; */    /* Bulk Erase only for FLASHPART2 */
/* extern uint8_t C_FNOR_SE;    */    /* Sector Erase */
/* extern uint8_t C_FNOR_SUBSE; */    /* Sub-Sector Erase */
/* extern uint8_t C_FNOR_PAGEP;  */    /* Write command (page program) */
/* extern uint8_t C_FNOR_READ;   */     /* Read command 4-byte address */
/* extern uint8_t C_FNOR_DUALREAD; */ /* Dual read command 4-byte address */
/*extern uint8_t C_FNOR_ENTER4B; */ /* Enter 4 bytes addressing mode */
/* extern uint8_t C_FNOR_EXIT4B; */   /* Exit 4 bytes addressing mode */
/* extern uint8_t C_FNOR_RDSR; */     /* Read status register */

extern const uint8_t C_FNOR_CFSR;
extern const uint8_t C_FNOR_WREN;
extern const uint8_t C_FNOR_ENTER4B;
extern const uint32_t C_FNOR_CHAR_LENGTH;
extern const uint32_t C_FNOR_CS_CLOCK_GAP;
extern uint8_t V_FNOR_WriteBuffer[C_FNOR_EXCHANGE_SIZE_OUT];
extern uint8_t V_FNOR_WriteBuffer[C_FNOR_EXCHANGE_SIZE_OUT];
extern const uint32_t C_FNOR_SHIFT_24_BITS;
extern const uint32_t C_FNOR_SHIFT_16_BITS;
extern const uint32_t C_FNOR_SHIFT_8_BITS;

extern const uint32_t C_FNOR_MASK_FIRST_LSB_BYTE;
extern const uint32_t C_FNOR_MASK_SECOND_LSB_BYTE;
extern const uint32_t C_FNOR_MASK_SECOND_MSB_BYTE;
extern const uint32_t C_FNOR_MASK_FIRST_MSB_BYTE;

extern const uint32_t C_FNOR_TIMEOUT;

#endif
