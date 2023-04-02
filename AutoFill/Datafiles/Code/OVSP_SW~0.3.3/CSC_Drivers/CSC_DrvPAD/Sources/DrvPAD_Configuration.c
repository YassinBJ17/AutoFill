/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the ...
 * -------------------------------------------------------------------------- */

/* ---------- include predefined types: ------------------------------------- */
#include "MCP_Types.h"

/* ---------- include provided interface: ----------------------------------- */
#include "DrvPAD_Private.h"

/* ---------- include required interface: ----------------------------------- */
/* None */

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */
/* None */

/* ---------- internal operations: ------------------------------------------ */
/* None */

/* ---------- provided data: ------------------------------------------------ */
/* None */

/* ---------- provided  constants: ------------------------------------------ */

/* set PAD configuration according to target (HS side) */
const uint32_t C_DrvPAD_HS_Config[DRVPAD_MAX_PORTS_NB][DRVPAD_MAX_PINS_NB] =
{
   /* Port A */
   {
      /* PTA 0  - 64 & 100 packaging */
      DRVPAD_PIN_USED | DRVPAD_MUX_GPIO,
      /* PTA 1  - 64 & 100 packaging */
      DRVPAD_PIN_USED | DRVPAD_MUX_GPIO,
      /* PTA 2  - 64 & 100 packaging */
      DRVPAD_PIN_USED | DRVPAD_MUX_ALTER_2,
      /* PTA 3  - 64 & 100 packaging */
      DRVPAD_PIN_USED | DRVPAD_MUX_PIN_DIS_ANAL,
      /* PTA 4  - 64 & 100 packaging */
      DRVPAD_PIN_USED | DRVPAD_MUX_ALTER_7,
      /* PTA 5  - 64 & 100 packaging */
      DRVPAD_PIN_USED | DRVPAD_MUX_ALTER_7,
      /* PTA 6  - 64 & 100 packaging */
      DRVPAD_PIN_USED | DRVPAD_MUX_GPIO,
      /* PTA 7  - 64 & 100 packaging */
      DRVPAD_PIN_USED | DRVPAD_MUX_GPIO,
      /* PTA 8  - Only 100 packaging */     /* LPSPI2_SOUT for S32K144EVB & S32K148EVB */
      DRVPAD_PIN_USED | DRVPAD_MUX_ALTER_3,
      /* PTA 9  - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTA 10 - 64 & 100 packaging */
      DRVPAD_PIN_USED | DRVPAD_MUX_ALTER_7,
      /* PTA 11 - 64 & 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTA 12 - 64 & 100 packaging */
      DRVPAD_PIN_USED | DRVPAD_MUX_ALTER_3,
      /* PTA 13 - 64 & 100 packaging */
      DRVPAD_PIN_USED | DRVPAD_MUX_ALTER_3,
      /* PTA 14 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTA 15 - Only 100 packaging */     /* LPSPI2_PCS3 for S32K148EVB */
      DRVPAD_PIN_USED | DRVPAD_MUX_ALTER_4,
      /* PTA 16 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTA 17 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTA 18 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTA 19 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTA 20 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTA 21 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTA 22 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTA 23 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTA 24 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTA 25 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTA 26 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTA 27 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTA 28 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTA 29 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTA 30 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTA 31 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED
   },
   /* Port B */
   {
      /* PTB 0  - 64 & 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTB 1  - 64 & 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTB 2  - 64 & 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTB 3  - 64 & 100 packaging */
      DRVPAD_PIN_USED | DRVPAD_MUX_ALTER_2,
      /* PTB 4  - 64 & 100 packaging */
      DRVPAD_PIN_USED | DRVPAD_MUX_ALTER_2,
      /* PTB 5  - 64 & 100 packaging */
      DRVPAD_PIN_USED | DRVPAD_MUX_GPIO,
      /* PTB 6  - 64 & 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTB 7  - 64 & 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTB 8  - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTB 9  - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTB 10 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTB 11 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTB 12 - 64 & 100 packaging */
      DRVPAD_PIN_USED | DRVPAD_MUX_ALTER_4,
      /* PTB 13 - 64 & 100 packaging */ /* For FTM0_CH1*/
      DRVPAD_PIN_USED | DRVPAD_MUX_ALTER_2,
      /* PTB 14 - Only 100 packaging */ /* For LSPI1 for CAN HI LO Transceiver SBC*/
      DRVPAD_PIN_USED | DRVPAD_MUX_ALTER_3,
      /* PTB 15 - Only 100 packaging */
      DRVPAD_PIN_USED | DRVPAD_MUX_ALTER_3,
      /* PTB 16 - Only 100 packaging */ /* For LSPI1 for CAN HI LO Transceiver SBC*/
      DRVPAD_PIN_USED | DRVPAD_MUX_ALTER_3,
      /* PTB 17 - Only 100 packaging */ /* For LSPI1 for CAN HI LO Transceiver SBC*/
      // DRVPAD_PIN_NOT_USED,
      DRVPAD_PIN_USED | DRVPAD_MUX_ALTER_3,
      /* PTB 18 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTB 19 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTB 20 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTB 21 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTB 22 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTB 23 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTB 24 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTB 25 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTB 26 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTB 27 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTB 28 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTB 29 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTB 30 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTB 31 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED
   },
   /* Port C */
   {
      /* PTC 0 - Only 100 packaging */     /* LPSPI2_SIN for S32K144EVB & S32K148EVB */
      DRVPAD_PIN_USED | DRVPAD_MUX_ALTER_3,
      /* PTC 1 - Only 100 packaging */     /* LPSPI2_SCK for S32K144EVB & S32K148EVB */
      DRVPAD_PIN_USED | DRVPAD_MUX_ALTER_3,
      /* PTC 2  - 64 & 100 packaging */
      DRVPAD_PIN_USED | DRVPAD_MUX_ALTER_2,
      /* PTC 3  - 64 & 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTC 4  - 64 & 100 packaging */    /* JTAG_TCLK/SWD_CLK */
      DRVPAD_PIN_USED | DRVPAD_MUX_ALTER_7,
      /* PTC 5  - 64 & 100 packaging */    /* JTAG_TDI */
      DRVPAD_PIN_USED | DRVPAD_MUX_ALTER_7,
      /* PTC 6  - 64 & 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTC 7  - 64 & 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTC 8  - 64 & 100 packaging */
      DRVPAD_PIN_USED | DRVPAD_MUX_GPIO,
      /* PTC 9  - 64 & 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTC 10 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTC 11 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTC 12 - Only 100 packaging */      /* Switch 2 demo board */
      DRVPAD_PIN_USED | DRVPAD_MUX_GPIO,
      /* PTC 13 - Only 100 packaging */      /* Switch 3 demo board */
      DRVPAD_PIN_USED | DRVPAD_MUX_GPIO,
      /* PTC 14 - 64 & 100 packaging */
      DRVPAD_PIN_USED | DRVPAD_MUX_ALTER_3, /* LPSPI2_SCK for S32K144EVB & S32K148EVB */
      /* PTC 15 - 64 & 100 packaging */
      DRVPAD_PIN_USED | DRVPAD_MUX_ALTER_3, /* LPSPI2_SCK for S32K144EVB & S32K148EVB */
      /* PTC 16 - 64 & 100 packaging */
      DRVPAD_PIN_USED | DRVPAD_MUX_GPIO,
      /* PTC 17 - 64 & 100 packaging */
      DRVPAD_PIN_USED | DRVPAD_MUX_PIN_DIS_ANAL,
      /* PTC 18 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTC 19 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTC 20 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTC 21 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTC 22 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTC 23 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTC 24 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTC 25 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTC 26 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTC 27 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTC 28 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTC 29 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTC 30 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTC 31 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED
   },
   /* Port D */
   {
      /* PTD 0  - 64 & 100 packaging */      /* LED Blue demo board S32K144 */
      (DRVPAD_PIN_USED | DRVPAD_MUX_ALTER_6),
      /* PTD 1  - 64 & 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTD 2  - 64 & 100 packaging */
      DRVPAD_PIN_USED | DRVPAD_MUX_ALTER_2,
      /* PTD 3  - 64 & 100 packaging */
      DRVPAD_PIN_USED | DRVPAD_MUX_GPIO,
      /* PTD 4  - 64 & 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTD 5  - 64 & 100 packaging */     /* PTD5 For HS_DININHIB_N input signal*/
      DRVPAD_PIN_USED | DRVPAD_MUX_GPIO,
      /* PTD 6  - 64 & 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTD 7  - 64 & 100 packaging */
      DRVPAD_PIN_USED | DRVPAD_MUX_GPIO,
      /* PTD 8  - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTD 9  - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTD 10 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTD 11 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTD 12 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTD 13 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTD 14 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTD 15 - 64 & 100 packaging */      /* LED Red demo board S32K144 */
      (DRVPAD_PIN_USED | DRVPAD_MUX_ALTER_2),
      /* PTD 16 - 64 & 100 packaging */      /* LED Green demo board S32K144 */
      (DRVPAD_PIN_USED | DRVPAD_MUX_GPIO),
      /* PTD 17 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTD 18 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTD 19 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTD 20 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTD 21 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTD 22 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTD 23 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTD 24 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTD 25 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTD 26 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTD 27 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTD 28 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTD 29 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTD 30 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTD 31 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED
   },
   /* Port E */
   {
      /* PTE 0  - 64 & 100 packaging */      /* HS_DOUTINHIB_FB */
      DRVPAD_PIN_USED | DRVPAD_MUX_GPIO,
      /* PTE 1  - 64 & 100 packaging */      /* HS_DININHIB_TEST_H */
      DRVPAD_PIN_USED | DRVPAD_MUX_GPIO,
      /* PTE 2  - 64 & 100 packaging */      /* LPSPI0_SOUT for S32K144EVB & S32K148EVB */
      DRVPAD_PIN_NOT_USED,
      /* PTE 3  - 64 & 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTE 4  - 64 & 100 packaging */     /* CAN0 RX */
      DRVPAD_PIN_NOT_USED,
      /* PTE 5  - 64 & 100 packaging */     /* CAN0 TX */
      DRVPAD_PIN_NOT_USED,
      /* PTE 6  - 64 & 100 packaging */     /* PTE6 for HS_DOUTINHIB_CMD output signal */
      DRVPAD_PIN_USED | DRVPAD_MUX_GPIO,
      /* PTE 7  - 64 & 100 packaging */     /* PTE7 For HS_OSARM_STATUS input signal*/
      DRVPAD_PIN_USED | DRVPAD_MUX_GPIO,
      /* PTE 8  - 64 & 100 packaging */     /* HS_OSARM_CMD_N */
      DRVPAD_PIN_USED | DRVPAD_MUX_GPIO,
      /* PTE 9  - 64 & 100 packaging */     /* HS_OSREARM_N */
      DRVPAD_PIN_USED | DRVPAD_MUX_GPIO,
      /* PTE 10 - 64 & 100 packaging */     /* HS_CAM_CMD1_PWM */
      DRVPAD_PIN_USED | DRVPAD_MUX_ALTER_4,
      /* PTE 11 - 64 & 100 packaging */   /* HS_CAMLOW2_STATUS */
      DRVPAD_PIN_USED | DRVPAD_MUX_GPIO,
      /* PTE 12 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTE 13 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTE 14 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTE 15 - Only 100 packaging */     /* LPSPI2_SCK for S32K144EVB & S32K148EVB */
      DRVPAD_PIN_NOT_USED,
      /* PTE 16 - Only 100 packaging */     /* LPSPI2_SIN for S32K144EVB & S32K148EVB */
      DRVPAD_PIN_NOT_USED,
      /* !!!!  PTE 17  No existing on all version !!! */
      DRVPAD_PIN_NOT_USED,
      /* PTE 18 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTE 19 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTE 20 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTE 21 - Only 100 packaging */      /* LED Red demo board S32K144 */
      (DRVPAD_PIN_USED | DRVPAD_MUX_GPIO),
      /* PTE 22 - Only 100 packaging */      /* LED Green demo board S32K144 */
      (DRVPAD_PIN_USED | DRVPAD_MUX_GPIO),
      /* PTE 23 - Only 100 packaging */      /* LED Blue demo board S32K144 */
      (DRVPAD_PIN_USED | DRVPAD_MUX_GPIO),
      /* PTE 24 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTE 25 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTE 26 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTE 27 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* !!!!  PTE 28 - No existing on all version !!! */
      DRVPAD_PIN_NOT_USED,
      /* !!!!  PTE 29 - No existing on all version !!! */
      DRVPAD_PIN_NOT_USED,
      /* !!!!  PTE 30 - No existing on all version !!! */
      DRVPAD_PIN_NOT_USED,
      /* !!!!  PTE 31 - No existing on all version !!! */
      DRVPAD_PIN_NOT_USED
   }
};


/* set PAD configuration according to target (LS side) */
const uint32_t C_DrvPAD_LS_Config[DRVPAD_MAX_PORTS_NB][DRVPAD_MAX_PINS_NB] =
{
   /* Port A */
   {
      /* PTA 0  - 64 & 100 packaging */
      DRVPAD_PIN_USED | DRVPAD_MUX_GPIO,
      /* PTA 1  - 64 & 100 packaging */
      DRVPAD_PIN_USED | DRVPAD_MUX_GPIO,
      /* PTA 2  - 64 & 100 packaging */
      DRVPAD_PIN_USED | DRVPAD_MUX_ALTER_2,
      /* PTA 3  - 64 & 100 packaging */
      DRVPAD_PIN_USED | DRVPAD_MUX_PIN_DIS_ANAL,
      /* PTA 4  - 64 & 100 packaging */
      DRVPAD_PIN_USED | DRVPAD_MUX_ALTER_7,
      /* PTA 5  - 64 & 100 packaging */
      DRVPAD_PIN_USED | DRVPAD_MUX_ALTER_7,
      /* PTA 6  - 64 & 100 packaging */
      DRVPAD_PIN_USED | DRVPAD_MUX_GPIO,
      /* PTA 7  - 64 & 100 packaging */
      DRVPAD_PIN_USED | DRVPAD_MUX_GPIO,
      /* PTA 8  - Only 100 packaging */     /* LPSPI2_SOUT for S32K144EVB & S32K148EVB */
      DRVPAD_PIN_USED | DRVPAD_MUX_ALTER_3,
      /* PTA 9  - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTA 10 - 64 & 100 packaging */
      DRVPAD_PIN_USED | DRVPAD_MUX_ALTER_7,
      /* PTA 11 - 64 & 100 packaging */     /* For FTM1_CH5 */
      DRVPAD_PIN_USED | DRVPAD_MUX_ALTER_2,
      /* PTA 12 - 64 & 100 packaging */
      DRVPAD_PIN_USED | DRVPAD_MUX_ALTER_3,
      /* PTA 13 - 64 & 100 packaging */
      DRVPAD_PIN_USED | DRVPAD_MUX_ALTER_3,
      /* PTA 14 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTA 15 - Only 100 packaging */     /* LPSPI2_PCS3 for S32K148EVB */
      DRVPAD_PIN_USED | DRVPAD_MUX_ALTER_4,
      /* PTA 16 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTA 17 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTA 18 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTA 19 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTA 20 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTA 21 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTA 22 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTA 23 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTA 24 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTA 25 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTA 26 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTA 27 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTA 28 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTA 29 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTA 30 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTA 31 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED
   },
   /* Port B */
   {
      /* PTB 0  - 64 & 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTB 1  - 64 & 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTB 2  - 64 & 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTB 3  - 64 & 100 packaging */
      DRVPAD_PIN_USED | DRVPAD_MUX_GPIO,
      /* PTB 4  - 64 & 100 packaging */
      DRVPAD_PIN_USED | DRVPAD_MUX_ALTER_2,
      /* PTB 5  - 64 & 100 packaging */
      DRVPAD_PIN_USED | DRVPAD_MUX_GPIO,
      /* PTB 6  - 64 & 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTB 7  - 64 & 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTB 8  - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTB 9  - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTB 10 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTB 11 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTB 12 - 64 & 100 packaging */
      DRVPAD_PIN_USED | DRVPAD_MUX_ALTER_4,
      /* PTB 13 - 64 & 100 packaging */
      DRVPAD_PIN_USED | DRVPAD_MUX_ALTER_4,
      /* PTB 14 - Only 100 packaging */ /* For LSPI1 for CAN HI LO Transceiver SBC*/
      DRVPAD_PIN_USED | DRVPAD_MUX_ALTER_3,
      /* PTB 15 - Only 100 packaging */
      DRVPAD_PIN_USED | DRVPAD_MUX_ALTER_3,
      /* PTB 16 - Only 100 packaging */ /* For LSPI1 for CAN HI LO Transceiver SBC*/
      DRVPAD_PIN_USED | DRVPAD_MUX_ALTER_3,
      /* PTB 17 - Only 100 packaging */ /* For LSPI1 for CAN HI LO Transceiver SBC*/
      // DRVPAD_PIN_NOT_USED,
      DRVPAD_PIN_USED | DRVPAD_MUX_ALTER_3,
      /* PTB 18 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTB 19 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTB 20 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTB 21 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTB 22 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTB 23 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTB 24 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTB 25 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTB 26 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTB 27 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTB 28 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTB 29 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTB 30 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTB 31 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED
   },
   /* Port C */
   {
      /* PTC 0 - Only 100 packaging */     /* LPSPI2_SIN for S32K144EVB & S32K148EVB */
      DRVPAD_PIN_USED | DRVPAD_MUX_ALTER_3,
      /* PTC 1 - Only 100 packaging */     /* LPSPI2_SCK for S32K144EVB & S32K148EVB */
      DRVPAD_PIN_USED | DRVPAD_MUX_ALTER_3,
      /* PTC 2  - 64 & 100 packaging */
      DRVPAD_PIN_USED | DRVPAD_MUX_ALTER_2,
      /* PTC 3  - 64 & 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTC 4  - 64 & 100 packaging */    /* JTAG_TCLK/SWD_CLK */
      DRVPAD_PIN_USED | DRVPAD_MUX_ALTER_7,
      /* PTC 5  - 64 & 100 packaging */    /* JTAG_TDI */
      DRVPAD_PIN_USED | DRVPAD_MUX_ALTER_7,
      /* PTC 6  - 64 & 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTC 7  - 64 & 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTC 8  - 64 & 100 packaging */
      DRVPAD_PIN_USED | DRVPAD_MUX_GPIO,
      /* PTC 9  - 64 & 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTC 10 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTC 11 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTC 12 - Only 100 packaging */      /* Switch 2 demo board */
      DRVPAD_PIN_USED | DRVPAD_MUX_GPIO,
      /* PTC 13 - Only 100 packaging */      /* Switch 3 demo board */
      DRVPAD_PIN_USED | DRVPAD_MUX_GPIO,
      /* PTC 14 - 64 & 100 packaging */
      DRVPAD_PIN_USED | DRVPAD_MUX_ALTER_3, /* LPSPI2_SCK for S32K144EVB & S32K148EVB */
      /* PTC 15 - 64 & 100 packaging */
      DRVPAD_PIN_USED | DRVPAD_MUX_ALTER_3, /* LPSPI2_SCK for S32K144EVB & S32K148EVB */
      /* PTC 16 - 64 & 100 packaging */
      DRVPAD_PIN_USED | DRVPAD_MUX_GPIO,
      /* PTC 17 - 64 & 100 packaging */
      DRVPAD_PIN_USED | DRVPAD_MUX_PIN_DIS_ANAL,
      /* PTC 18 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTC 19 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTC 20 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTC 21 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTC 22 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTC 23 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTC 24 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTC 25 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTC 26 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTC 27 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTC 28 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTC 29 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTC 30 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTC 31 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED
   },
   /* Port D */
   {
      /* PTD 0  - 64 & 100 packaging */      /* LED Blue demo board S32K144 */
      (DRVPAD_PIN_USED | DRVPAD_MUX_ALTER_6),
      /* PTD 1  - 64 & 100 packaging */       /* FTM0_CH3 for LS Triggtest acquisitions */
      DRVPAD_PIN_USED | DRVPAD_MUX_ALTER_2,
      /* PTD 2  - 64 & 100 packaging */
      DRVPAD_PIN_USED | DRVPAD_MUX_ALTER_2,
      /* PTD 3  - 64 & 100 packaging */
      DRVPAD_PIN_USED | DRVPAD_MUX_GPIO,
      /* PTD 4  - 64 & 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTD 5  - 64 & 100 packaging */     /* PTD5 For LS_DININHIB_N input signal*/
      DRVPAD_PIN_USED | DRVPAD_MUX_GPIO,
      /* PTD 6  - 64 & 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTD 7  - 64 & 100 packaging */
      DRVPAD_PIN_USED | DRVPAD_MUX_GPIO,
      /* PTD 8  - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTD 9  - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTD 10 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTD 11 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTD 12 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTD 13 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTD 14 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTD 15 - 64 & 100 packaging */      /* LS_CAM_CMD1 */
      (DRVPAD_PIN_USED | DRVPAD_MUX_GPIO),
      /* PTD 16 - 64 & 100 packaging */      /* LED Green demo board S32K144 */
      (DRVPAD_PIN_USED | DRVPAD_MUX_GPIO),
      /* PTD 17 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTD 18 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTD 19 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTD 20 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTD 21 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTD 22 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTD 23 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTD 24 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTD 25 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTD 26 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTD 27 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTD 28 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTD 29 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTD 30 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTD 31 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED
   },
   /* Port E */
   {
      /* PTE 0  - 64 & 100 packaging */      /* LS_DOUTINHIB_FB */
      DRVPAD_PIN_USED | DRVPAD_MUX_GPIO,
      /* PTE 1  - 64 & 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTE 2  - 64 & 100 packaging */      /* LPSPI0_SOUT for S32K144EVB & S32K148EVB */
      DRVPAD_PIN_USED | DRVPAD_MUX_ALTER_2,
      /* PTE 3  - 64 & 100 packaging */
      DRVPAD_PIN_USED | DRVPAD_MUX_GPIO,
      /* PTE 4  - 64 & 100 packaging */     /* CAN0 RX */
      DRVPAD_PIN_USED | DRVPAD_MUX_ALTER_5,
      /* PTE 5  - 64 & 100 packaging */     /* CAN0 TX */
      DRVPAD_PIN_USED | DRVPAD_MUX_ALTER_5,
      /* PTE 6  - 64 & 100 packaging */     /* PTE6 for LS_DOUTINHIB_CMD output signal */
      DRVPAD_PIN_USED | DRVPAD_MUX_GPIO,
      /* PTE 7  - 64 & 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTE 8  - 64 & 100 packaging */     /* LS_OSARM_CMD_N */
      DRVPAD_PIN_USED | DRVPAD_MUX_GPIO,
      /* PTE 9  - 64 & 100 packaging */     /* LS_OSREARM_N */
      DRVPAD_PIN_USED | DRVPAD_MUX_GPIO,
      /* PTE 10 - 64 & 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTE 11 - 64 & 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTE 12 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTE 13 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTE 14 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTE 15 - Only 100 packaging */     /* LPSPI2_SCK for S32K144EVB & S32K148EVB */
      DRVPAD_PIN_NOT_USED,
      /* PTE 16 - Only 100 packaging */     /* LPSPI2_SIN for S32K144EVB & S32K148EVB */
      DRVPAD_PIN_NOT_USED,
      /* !!!!  PTE 17  No existing on all version !!! */
      DRVPAD_PIN_NOT_USED,
      /* PTE 18 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTE 19 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTE 20 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTE 21 - Only 100 packaging */      /* LED Red demo board S32K144 */
      (DRVPAD_PIN_USED | DRVPAD_MUX_GPIO),
      /* PTE 22 - Only 100 packaging */      /* LED Green demo board S32K144 */
      (DRVPAD_PIN_USED | DRVPAD_MUX_GPIO),
      /* PTE 23 - Only 100 packaging */      /* LED Blue demo board S32K144 */
      (DRVPAD_PIN_USED | DRVPAD_MUX_GPIO),
      /* PTE 24 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTE 25 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTE 26 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* PTE 27 - Only 100 packaging */
      DRVPAD_PIN_NOT_USED,
      /* !!!!  PTE 28 - No existing on all version !!! */
      DRVPAD_PIN_NOT_USED,
      /* !!!!  PTE 29 - No existing on all version !!! */
      DRVPAD_PIN_NOT_USED,
      /* !!!!  PTE 30 - No existing on all version !!! */
      DRVPAD_PIN_NOT_USED,
      /* !!!!  PTE 31 - No existing on all version !!! */
      DRVPAD_PIN_NOT_USED
   }
};


/* Controler register mapping */
ts_DrvPAD_PortCtrl * const C_DrvPAD_PortCtrl = (ts_DrvPAD_PortCtrl *) DRVPAD_PAD_ADDRESS;
/* -------------------------------------------------------------------------- */


/* ---------- internal datas: ------------------------------------------------*/


/* ---------- provided operation bodies: ------------------------------------ */
/* None */


