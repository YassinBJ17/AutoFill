#ifndef DRV_ESPI_INTERFACE_H_
#define DRV_ESPI_INTERFACE_H_

/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2017                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/

/* _BEGIN_INCLUDE ========================================== INCLUDE FILES ========================================== */
#include "LIBMCP_Types.h"
/* _END_INCLUDE ===================================================================================================== */


/*==== Definitions =====================================================================*/
#define C_SPI_SHIFT_30_BITS 30
#define C_SPI_TIMEOUT_US 10ul

#define C_SPI_DEVICES_COUNT 4ul

#define C_SPI_RESERVED_REG_SIZE 2
#define C_SPI_SPMODEX_REG_SIZE 4

#define C_SPI_CLEAR_GLOBAL_REG_MASK 0xFFFFFFFFul
/*==== Types ===========================================================================*/

typedef enum {
    E_LIBBSP_SPI_VALID_ADDR,
	E_LIBBSP_SPI_INVALID_ADDR
} TE_LIBBSP_SPI_AddrStatus;

/* Chip select value for each devices on SPI GANAV board */
typedef enum {
    E_LIBBSP_SPI_FLASH_PROGRAM = 0,
	E_LIBBSP_SPI_MRAM = 1,
    E_LIBBSP_SPI_FLASH_BITE    = 2
} TE_LIBBSP_SPI_Device;

/* Quick Command for SPI BUS */
typedef enum {
   E_LIBBSP_SPI_WRITE6 = 0,
   E_LIBBSP_SPI_WRITE4 = 1,
   E_LIBBSP_SPI_WRITE2 = 2,
   E_LIBBSP_SPI_WRITE1 = 3,
   E_LIBBSP_SPI_READ2 =  4,
   E_LIBBSP_SPI_READ1 =  5
} TE_LIBBSP_SPI_Command ;

/* Return codes of eSPI layer */
typedef enum {
    E_LIBBSP_SPI_OK                   = 0,
    E_LIBBSP_SPI_INVALID_ID           = 1,
    E_LIBBSP_SPI_TIMEOUT_TNF          = 2,
    E_LIBBSP_SPI_TIMEOUT_DON          = 3,
    E_LIBBSP_SPI_TIMEOUT_TXCNT        = 4,
    E_LIBBSP_SPI_TIMEOUT_RXCNT        = 5,
    E_LIBBSP_SPI_TIMEOUT_WRONG_CMD    = 6
} TE_LIBBSP_SPI_ErrorCode;

/* Modes for sending commands */
/*#define NORMAL_MODE 0x1*/
/*#define DUAL_MODE 0x2*/

typedef enum {
    E_LIBBSP_SPI_NORMAL_MODE          = 1,
    E_LIBBSP_SPI_DUAL_MODE            = 2
} TE_LIBBSP_SPI_Mode;

/* Registers of eSPI P1011 interface */
typedef union
{
    uint32_t R;
    struct                      /* SPMODE mode espiRegsiter */
    {
        uint32_t EN:1;                 /* Enable eSPI */
        uint32_t LOOP:1;               /* Loop mode */
        uint32_t :16;                  /* Reserved */
        uint32_t TXTHR:6;              /* Tx FIFO threshold */
        uint32_t :3;                   /* Reserved */
        uint32_t RXTHR:5;              /* Rx FIFO threshold */
    } B;
} TU_LIBBSP_SPI_Spmode;

typedef union
{
   uint32_t R;
   struct                      /* SPIE event register */
   {
        uint32_t :2;                   /* Reserved */
        uint32_t RXCNT:6;              /* The current number of full Rx FIFO bytes */
        uint32_t :2;                   /* Reserved */
        uint32_t TXCNT:6;              /* The current number of free Tx FIFO bytes */
        uint32_t TXE:1;                /* Tx FIFO is empty */
        uint32_t DON:1;                /* Last character was transmitted */
        uint32_t RXT:1;                /* Rx FIFO has more than RXTHR bytes */
        uint32_t RXF:1;                /* Rx FIFO is full */
        uint32_t TXT:1;                /* Tx FIFO has less then TXTHR bytes */
        uint32_t :1;                   /* Reserved */
        uint32_t RNE:1;                /* Not empty. Indicates that the Rx FIFO register contains received character */
        uint32_t TNF:1;                /* Tx FIFO not full */
        uint32_t :8;                   /* Reserved */
    } B;
} TU_LIBBSP_SPI_Spie;

typedef union
{
   uint32_t R;
   struct                      /* SPIM mask register */
   {
        uint32_t :16;                  /* Reserved */
        uint32_t TXE:1;                /* Tx FIFO empty Interrupt mask */
        uint32_t DON:1;                /* Last character transmitted mask */
        uint32_t RXT:1;                /* Rx threshold Interrupt mask */
        uint32_t RXF:1;                /* Rx FIFO full Interrupt mask */
        uint32_t TXT:1;                /* Tx threshold Interrupt mask */
        uint32_t :1;                   /* Reserved */
        uint32_t RNE:1;                /* Rx not empty Interrupt mask */
        uint32_t TNF:1;                /* Tx not full Interrupt mask */
        uint32_t :8;                   /* Reserved */
    } B;
} TU_LIBBSP_SPI_Spim;

typedef union
{
   uint32_t R;
   struct                      /* SPCOM command register */
   {
        uint32_t CS:2;                 /* Chip select */
        uint32_t RxDelay:1;            /* RxDelay */
        uint32_t DO:1;                 /* Winbond dual output read */
        uint32_t TO:1;                 /* Transmit only */
        uint32_t HLD:1;                /* HLD */
        uint32_t :2;                   /* Reserved */
        uint32_t RxSKIP:8;             /* Number of characters skipped for reception frame start */
        uint32_t TRANLEN:16;           /* Transaction length */
   } B;
} TU_LIBBSP_SPI_Spcom;

typedef union
{
   uint32_t R;
   struct                      /* SPMODE CSx mode */
   {
        uint32_t CI:1;                 /* Clock Invert */
        uint32_t CP:1;                 /* Clock phase */
        uint32_t REV:1;                /* Reverse data mode */
        uint32_t DIV16:1;              /* Divide by 16 */
        uint32_t PM:4;                 /* Prescale module select */
        uint32_t ODD:1;                /* 0: Even division, 1: Odd division */
        uint32_t :2;                   /* Reserved */
        uint32_t POL:1;                /* CSx polarity */
        uint32_t LEN:4;                /* Character length in bits per character */
        uint32_t CSBEF:4;              /* CS assertion time in bits before frame start */
        uint32_t CSAFT:4;              /* CS assertion time in bits after frame end */
        uint32_t CSCG:5;               /* Clock gap */
        uint32_t :3;                   /* Reserved */
   } B;
} TU_LIBBSP_SPI_Config;

typedef union
{
        uint32_t       u32;
        uint16_t      u16;
        uint8_t       u8;
} TU_LIBBSP_SPI_Sprxreg;

/* Mapping of eSPI registers*/
typedef struct {
    TU_LIBBSP_SPI_Spmode spmode;           /* 0x000 eSPI mode register R/W 0x0000_100F */
    TU_LIBBSP_SPI_Spie spie;             /* 0x004 eSPI event register Mixed 0x0020_0000 */
    TU_LIBBSP_SPI_Spim spim;             /* 0x008 eSPI mask register R/W All zeros */
    TU_LIBBSP_SPI_Spcom spcom;            /* 0x00C eSPI command register W All zeros */
    TU_LIBBSP_SPI_Sprxreg spitf;            /* 0x010 eSPI transmit FIFO access register W All zeros */
    TU_LIBBSP_SPI_Sprxreg spirf;            /* 0x014 eSPI receive FIFO access register R All zeros */
    uint32_t reserved[C_SPI_RESERVED_REG_SIZE];     /* 0x01C-0x018 Reserved */
    TU_LIBBSP_SPI_Config spmodex[C_SPI_SPMODEX_REG_SIZE];       /* 0x020-0x02C eSPI CSx mode register R/W 0x0010_0000 */
} TS_LIBBSP_SPI_RegisterSet;

/*==== Variables========================================================================*/
extern volatile TS_LIBBSP_SPI_RegisterSet* const V_SPI_Regs;

/*==== Services ========================================================================*/

extern TE_LIBBSP_SPI_ErrorCode LIBBSP_SPI_Open(const TE_LIBBSP_SPI_Device SpiID, const TU_LIBBSP_SPI_Config * const bus_Config);
extern TE_LIBBSP_SPI_ErrorCode LIBBSP_SPI_Exchange(const TE_LIBBSP_SPI_Device SpiID,
                                                   const uint32_t inSize, uint8_t * const inBuffer,
                                                   const uint32_t cmdSize, const uint8_t * const cmdBuffer,
                                                   const uint32_t dataSize, const uint8_t * const dataBuffer,
                                                   const TE_LIBBSP_SPI_Mode mode);
extern void LIBBSP_SPI_Close(void);
extern TE_LIBBSP_SPI_ErrorCode LIBBSP_SPI_IOCtrl(const TE_LIBBSP_SPI_Device SpiDevice, const TE_LIBBSP_SPI_Command SpiCmd, uint8_t * const Buffer);

/*==== END =============================================================================*/
#endif
