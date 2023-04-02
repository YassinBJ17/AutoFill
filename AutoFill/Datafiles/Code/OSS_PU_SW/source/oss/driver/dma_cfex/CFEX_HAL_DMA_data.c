/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : <short description of the operations of the .c file>
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "driver/dma_cfex/CFEX_HAL_DMA_public.h"

/* ---------- include required interface: ----------------------------------- */
#include "driver/dma/DMA_CFEX_public.h"
#include "driver/dma/DMA_HAL_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* DMA configuration table size */
const uint32_t FDX_c_DMA_CFEX_tab_SIZE = e_DMA_CFEX_ELT_NB;

/* */
/* DMA configuration table                   */
/*  0 - DMA 0 line 16 : TX SPI_1-Master-ADC1 */
/*  1 - DMA 0 line 17 : RX SPI_1-Master-ADC1 */
/*  2 - DMA 0 line 24 : TX SPI_2-Master-ADC2 */
/*  3 - DMA 0 line 25 : RX SPI_2-Master-ADC2 */
/*  4 - DMA 0 line 32 : TX SPI_3-Master-ADC3 */
/*  5 - DMA 0 line 33 : RX SPI_3-Master-ADC3 */
/**************************************************/
const ts_DMA_CFEX_ELT FDX_c_DMA_CFEX_tab[e_DMA_CFEX_ELT_NB] =
{
   /* 0 - DMA 0 line 16 : TX SPI_1-Master-ADC1 */
   {
      e_DMA_CFEX_DMA_0,                 /* eDMA_0 or eDMA_1    */
      e_DMA_CFEX_DMA_LINE_16,           /* Line [0..63]        */
      e_DMA_CFEX_MUX_2,                 /* Mux [0..9]          */
      e_DMA_CFEX_MUX_LINE_0,            /* Mux Line [0..15]    */
      e_DMA_CFEX_MUX_SOURCE_4           /* Mux Source [0..63]  */
   },
   /* 1 - DMA 0 line 17 : RX SPI_1-Master-ADC1 */
   {
      e_DMA_CFEX_DMA_0,                 /* eDMA_0 or eDMA_1    */
      e_DMA_CFEX_DMA_LINE_17,           /* Line [0..63]        */
      e_DMA_CFEX_MUX_2,                 /* Mux [0..9]          */
      e_DMA_CFEX_MUX_LINE_1,            /* Mux Line [0..15]    */
      e_DMA_CFEX_MUX_SOURCE_3           /* Mux Source [0..63]  */
   },
   /* 2 - DMA 0 line 24 : TX SPI_2-Master-ADC2 */
   {
      e_DMA_CFEX_DMA_0,                 /* eDMA_0 or eDMA_1    */
      e_DMA_CFEX_DMA_LINE_24,           /* Line [0..63]        */
      e_DMA_CFEX_MUX_3,                 /* Mux [0..9]          */
      e_DMA_CFEX_MUX_LINE_0,            /* Mux Line [0..15]    */
      e_DMA_CFEX_MUX_SOURCE_3           /* Mux Source [0..63]  */
   },
   /* 3 - DMA 0 line 25 : RX SPI_2-Master-ADC2 */
   {
      e_DMA_CFEX_DMA_0,                 /* eDMA_0 or eDMA_1    */
      e_DMA_CFEX_DMA_LINE_25,           /* Line [0..63]        */
      e_DMA_CFEX_MUX_3,                 /* Mux [0..9]          */
      e_DMA_CFEX_MUX_LINE_1,            /* Mux Line [0..15]    */
      e_DMA_CFEX_MUX_SOURCE_2           /* Mux Source [0..63]  */
   },
   /* 4 - DMA 0 line 32 : TX SPI_3-Master-ADC3 */
   {
      e_DMA_CFEX_DMA_0,                 /* eDMA_0 or eDMA_1    */
      e_DMA_CFEX_DMA_LINE_32,           /* Line [0..63]        */
      e_DMA_CFEX_MUX_4,                 /* Mux [0..9]          */
      e_DMA_CFEX_MUX_LINE_0,            /* Mux Line [0..15]    */
      e_DMA_CFEX_MUX_SOURCE_6           /* Mux Source [0..63]  */
   },
   /* 5 - DMA 0 line 33 : RX SPI_3-Master-ADC3 */
   {
      e_DMA_CFEX_DMA_0,                 /* eDMA_0 or eDMA_1    */
      e_DMA_CFEX_DMA_LINE_33,           /* Line [0..63]        */
      e_DMA_CFEX_MUX_4,                 /* Mux [0..9]          */
      e_DMA_CFEX_MUX_LINE_1,            /* Mux Line [0..15]    */
      e_DMA_CFEX_MUX_SOURCE_5           /* Mux Source [0..63]  */
   },
   /* 0 - DMA 0 line  8 MUX 1 line 0 src  4 : TX LINFlexD_0-UART   */
   {
      e_DMA_CFEX_DMA_0,                 /* eDMA_0 or eDMA_1    */
      e_DMA_CFEX_DMA_LINE_8,            /* Line [0..63]        */
      e_DMA_CFEX_MUX_1,                 /* Mux [0..9]          */
      e_DMA_CFEX_MUX_LINE_0,            /* Mux Line [0..15]    */
      e_DMA_CFEX_MUX_SOURCE_4           /* Mux Source [0..63]  */
   },
   /* 1 - DMA 0 line  9 MUX 1 line 1 src  3 : RX LINFlexD_0-UART   */
   {
      e_DMA_CFEX_DMA_0,                 /* eDMA_0 or eDMA_1    */
      e_DMA_CFEX_DMA_LINE_9,            /* Line [0..63]        */
      e_DMA_CFEX_MUX_1,                 /* Mux [0..9]          */
      e_DMA_CFEX_MUX_LINE_1,            /* Mux Line [0..15]    */
      e_DMA_CFEX_MUX_SOURCE_3           /* Mux Source [0..63]  */
   }
};

/* DMA Priority table                      */
/* Group 3 is highest priority group       */
/* Priority 15 is highest priority channel */
/*   !!! One level priority by group !!!   */
const te_DMA_CFEX_PRIORITY FDX_c_DMA_CFEX_PRIORITY_tab[DMA_MAX_NB*DMA_LINE_MAX_NB]=
{
  /* Priority : eDMA 0 */
  /* Group 0 - Line [0..15] */
  e_P_15, e_P_14, e_P_13, e_P_12, e_P_11, e_P_10, e_P_09, e_P_08, e_P_07, e_P_06, e_P_05, e_P_04, e_P_03, e_P_02, e_P_01, e_P_00,
  /* Group 1 - Line [16..31] */
  e_P_15, e_P_14, e_P_13, e_P_12, e_P_11, e_P_10, e_P_09, e_P_08, e_P_07, e_P_06, e_P_05, e_P_04, e_P_03, e_P_02, e_P_01, e_P_00,
  /* Group 2 - Line [32..47] */
  e_P_15, e_P_14, e_P_13, e_P_12, e_P_11, e_P_10, e_P_09, e_P_08, e_P_07, e_P_06, e_P_05, e_P_04, e_P_03, e_P_02, e_P_01, e_P_00,
  /* Group 3 - Line [48..63] */
  e_P_15, e_P_14, e_P_13, e_P_12, e_P_11, e_P_10, e_P_09, e_P_08, e_P_07, e_P_06, e_P_05, e_P_04, e_P_03, e_P_02, e_P_01, e_P_00,
  /* Priority : eDMA 1 */
  /* Group 0 - Line [0..15] */
  e_P_15, e_P_14, e_P_13, e_P_12, e_P_11, e_P_10, e_P_09, e_P_08, e_P_07, e_P_06, e_P_05, e_P_04, e_P_03, e_P_02, e_P_01, e_P_00,
  /* Group 1 - Line [16..31] */
  e_P_15, e_P_14, e_P_13, e_P_12, e_P_11, e_P_10, e_P_09, e_P_08, e_P_07, e_P_06, e_P_05, e_P_04, e_P_03, e_P_02, e_P_01, e_P_00,
  /* Group 2 - Line [32..47] */
  e_P_15, e_P_14, e_P_13, e_P_12, e_P_11, e_P_10, e_P_09, e_P_08, e_P_07, e_P_06, e_P_05, e_P_04, e_P_03, e_P_02, e_P_01, e_P_00,
  /* Group 3 - Line [48..63] */
  e_P_15, e_P_14, e_P_13, e_P_12, e_P_11, e_P_10, e_P_09, e_P_08, e_P_07, e_P_06, e_P_05, e_P_04, e_P_03, e_P_02, e_P_01, e_P_00
};

/* ---------- internal data: ------------------------------------------------ */
/* DMA descriptor declaration */
ts_DMA_DESCR FDX_DMA_descr[e_DMA_CFEX_ELT_NB];

/* ---------- provided operation bodies: ------------------------------------ */

/* ---------- internal operation bodies: ------------------------------------ */
