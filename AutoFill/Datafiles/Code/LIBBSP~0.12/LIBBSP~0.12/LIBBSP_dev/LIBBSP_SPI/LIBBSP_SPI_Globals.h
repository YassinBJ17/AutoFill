/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_SPI_GLOBALS_H
#define LIBBSP_SPI_GLOBALS_H

#include "LIBBSP_SPI.h"
#include "LIBBSP_CCSR.h"
#include "LIBBSP_CMN.h"
#include "LIBBSP_CCSR.h"


/*==== Definitions =====================================================================*/
/*READ 1 BYTE*/
#define C_SPI_SPCOM_RX_NORMAL_1CHAR  0x00010001ul
/* V_SPI_Regs->spcom.R = (((uint32_t)SpiDevice)<<C_SPI_SHIFT_30_BITS) | C_SPI_SPCOM_RX_NORMAL_1CHAR; */
#define C_SPI_RX_FLASH_PROGRAM_1CHAR  0x00010001ul
#define C_SPI_RX_MRAM_1CHAR           0x40010001ul
#define C_SPI_RX_FLASH_BITE_1CHAR     0x80010001ul
#define C_SPI_RX_DEFAULT_1CHAR        0xC0010001ul

/*READ 2 BYTES*/
#define C_SPI_SPCOM_RX_NORMAL_2CHAR  0x00040005ul
/* V_SPI_Regs->spcom.R =(((uint32_t)SpiDevice)<<C_SPI_SHIFT_30_BITS) | C_SPI_SPCOM_RX_NORMAL_2CHAR; */
#define C_SPI_RX_FLASH_PROGRAM_2CHAR  0x00040005ul
#define C_SPI_RX_MRAM_2CHAR           0x40040005ul
#define C_SPI_RX_FLASH_BITE_2CHAR     0x80040005ul
#define C_SPI_RX_DEFAULT_2CHAR        0xC0040005ul

/*WRITE 1 BYTE*/
#define C_SPI_SPCOM_TX_NORMAL_1CHAR  0x08000000ul
/* V_SPI_Regs->spcom.R = (((uint32_t)SpiDevice) << C_SPI_SHIFT_30_BITS) | C_SPI_SPCOM_TX_NORMAL_1CHAR; */
#define C_SPI_BUS_FLASH_PROGRAM_1CHAR  0x08000000ul
#define C_SPI_BUS_MRAM_1CHAR           0x48000000ul
#define C_SPI_BUS_FLASH_BITE_1CHAR     0x88000000ul
#define C_SPI_BUS_DEFAULT_1CHAR        0xC8000000ul

/*WRITE 2 BYTES*/
#define C_SPI_SPCOM_TX_NORMAL_2CHAR  0x08000001ul
/* V_SPI_Regs->spcom.R = (((uint32_t)SpiDevice) << C_SPI_SHIFT_30_BITS) | C_SPI_SPCOM_TX_NORMAL_2CHAR; */
#define C_SPI_BUS_FLASH_PROGRAM_2CHAR  0x08000001ul
#define C_SPI_BUS_MRAM_2CHAR           0x48000001ul
#define C_SPI_BUS_FLASH_BITE_2CHAR     0x88000001ul
#define C_SPI_BUS_DEFAULT_2CHAR        0xC8000001ul

/*WRITE 4 BYTES*/
#define C_SPI_SPCOM_TX_NORMAL_4CHAR  0x08000003ul
/* V_SPI_Regs->spcom.R = (((uint32_t)SpiDevice)<<C_SPI_SHIFT_30_BITS) | C_SPI_SPCOM_TX_NORMAL_4CHAR; */
#define C_SPI_BUS_FLASH_PROGRAM_4CHAR  0x08000003ul
#define C_SPI_BUS_MRAM_4CHAR           0x48000003ul
#define C_SPI_BUS_FLASH_BITE_4CHAR     0x88000003ul
#define C_SPI_BUS_DEFAULT_4CHAR        0xC8000003ul

/*WRITE 6 BYTES*/
/* #define C_SPI_SHIFT_30_BITS 30 */
#define C_SPI_SPCOM_TX_NORMAL_6CHAR  0x08000005ul
/* V_SPI_Regs->spcom.R = (((uint32_t)SpiDevice)<<C_SPI_SHIFT_30_BITS) | C_SPI_SPCOM_TX_NORMAL_6CHAR; */
#define C_SPI_BUS_FLASH_PROGRAM_6CHAR  0x08000005ul
#define C_SPI_BUS_MRAM_6CHAR           0x48000005ul
#define C_SPI_BUS_FLASH_BITE_6CHAR     0x88000005ul
#define C_SPI_BUS_DEFAULT_6CHAR        0xC8000005ul

/*==== Variables =======================================================================*/
extern volatile TS_LIBBSP_SPI_RegisterSet* const V_SPI_Regs;
/*==== Services ========================================================================*/

/*==== END =============================================================================*/
#endif
