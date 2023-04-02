/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/

#include "LIBMCP_Types.h"

/*==== Types ===========================================================================*/

/* Standard FLASH operating code */
typedef enum {
    E_LIBBSP_FNOR_RSTE              = 0x66,     /* Reset enable */
    E_LIBBSP_FNOR_RSTM              = 0x99,     /* Reset memory */
    E_LIBBSP_FNOR_RNCR              = 0xB5,     /* Read non volatile configuration register */
    E_LIBBSP_FNOR_WNCR              = 0xB1,     /* Write non volatile configuration register */
    E_LIBBSP_FNOR_RVCR              = 0x85,     /* Read volatile configuration register */
    E_LIBBSP_FNOR_WVCR              = 0x81,     /* Write volatile configuration register */
    E_LIBBSP_FNOR_RDID              = 0x9F,     /* Read Identification */
    E_LIBBSP_FNOR_RFSR              = 0x70,     /* Read flag status register */
    E_LIBBSP_FNOR_CFSR              = 0x50,     /* Clear flag status register */
    E_LIBBSP_FNOR_WREN              = 0x06,     /* Write enable */
    E_LIBBSP_FNOR_WRDIS             = 0x04,     /* Write disable */
    E_LIBBSP_FNOR_DIEE              = 0xC4,     /* Die Erase only for FLASHPART1 */
    E_LIBBSP_FNOR_BULKE             = 0xC7,     /* Bulk Erase only for FLASHPART2 */
    E_LIBBSP_FNOR_SE                = 0xD8,     /* Sector Erase */
    E_LIBBSP_FNOR_SUBSE             = 0x20,     /* Sub-Sector Erase */
    E_LIBBSP_FNOR_PAGEP             = 0x02,     /* Write command (page program) */
    E_LIBBSP_FNOR_READ              = 0x13,     /* Read command 4-byte address */
    E_LIBBSP_FNOR_DUALREAD          = 0x3C,     /* Dual read command 4-byte address */
    E_LIBBSP_FNOR_ENTER4B           = 0xB7,     /* Enter 4 bytes addressing mode */
    E_LIBBSP_FNOR_EXIT4B            = 0xE9,     /* Exit 4 bytes addressing mode */
    E_LIBBSP_FNOR_RDSR              = 0x05      /* Read status register */
} TE_LIBBSP_FNOR_FlashCommand;

/* Registers of Flash */
typedef union
{
    uint8_t R;
    struct                      /* Status Register */
    {
        uint8_t WREN:1;           /* Write Enable (0 = enable, 1 = disabled) */
        uint8_t BPROT:5;          /* Block protection dtat */
        uint8_t WEL:1;            /* Write enabled latch */
        uint8_t WIP:1;            /* Write in progress (0 = ready, 1 = busy) */
    } STATUS;
    struct                      /* Flag Status Register */
    {
        uint8_t PEC:1;            /* Programm or Erase Controller (0 = busy, 1 = ready) */
        uint8_t ERSUS:1;          /* Erase suspend (0 = not in effect, 1 = in effect) */
        uint8_t ER:1;             /* Erase (0 = clear, 1 = failure or protection error) */
        uint8_t PG:1;             /* Program (0 = clear, 1 = failure or protection error) */
        uint8_t VPP:1;            /* Vpp (0 = enabled, 1 = disabled) */
        uint8_t PSUS:1;           /* Program suspend (0 = not in effect, 1 = in effect) */
        uint8_t PROT:1;           /* Protection (0 = clear, 1 = failure or protection error) */
        uint8_t ADDR:1;           /* Addressing (0 = 3 bytes, 1 = 4 bytes) */
    } FLAGSTATUS;
} TU_LIBBSP_FNOR_FlashRegister;


typedef union
{
    uint32_t R;
    struct                      /* Non Volatile Configuration Register */
    {
        uint8_t DCC:4;            /* Number of dummy clock cycles */
        uint8_t XIP:3;            /* XIP mode at Power-On */
        uint8_t ODS:3;            /* Output driver strength */
        uint8_t :1;               /* Reserved */
        uint8_t RST:1;            /* Reset / Hold */
        uint8_t QUAD:1;           /* Quad IO Protocol */
        uint8_t DUAL:1;           /* Dual IO Protocol*/
        uint8_t SEG:1;            /* Selection of segment of 128M */
        uint8_t ADDR:1;           /* Addressing bytes (0 4 bytes, 1 3 bytes) */
        uint32_t :16;                   /* Reserved */
    } NVCONFIGURATION;
    struct                      /* Volatile Configuration Register */
    {
        uint8_t DCC:4;            /* Number of dummy clock cycles */
        uint8_t XIP:1;            /* XIP mode at Power-On */
        uint8_t :1;               /* Reserved */
        uint8_t WRAP:2;           /* Alignment */
        uint32_t :24;                   /* Reserved */
    } VCONFIGURATION;
	union {
        uint32_t       u32;
        uint16_t      u16;
        uint8_t       u8;
    } FLASHCONFREG;
} TU_LIBBSP_FNOR_FlashConfRegister;
