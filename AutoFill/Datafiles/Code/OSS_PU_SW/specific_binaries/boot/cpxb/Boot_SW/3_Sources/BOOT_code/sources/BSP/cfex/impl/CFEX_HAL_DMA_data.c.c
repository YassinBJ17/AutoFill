/* --------------------------------------------------------------------------
 *                           Sagem Defense Securite
 *                               SAFRAN Group
 * --------------------------------------------------------------------------
 * PROJECT : CHRONOS_MOCKUP
 * CSU name :
 * %name: CFEX_HAL_DMA_data.c.c %
 * %full_name: fadex#1/csrc/CFEX_HAL_DMA_data.c.c/1 %
 * DESCRIPTION : short description of the operations of the .c file
 *
 * Creation information:
 *   Created by: F576176
 *   Date : Fri Mar 22 10:45:26 CET 2019
 *
 * Modification information:
 *   %derived_by: F605763 %
 *   %date_created:Thu May 12 18:17:59 CEST 2022 %
 * --------------------------------------------------------------------------
 * SAGEM Defense Securite document. Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "DMA_CFEX_public.h"
#include "DMA_HAL_public.h"


/* ---------- include required interface: ----------------------------------- */
/* LPOS Common Interface */
/*  */
#include "CFEX_HAL_private.h"

/* LPOS Public Interface */
/* none */

/* LPOS Private Interface */
/* none */

/* ---------- internal define constants: ------------------------------------ */
/* */


/* ---------- internal types: ----------------------------------------------- */
/* none */

/* ---------- internal operations: ------------------------------------------ */
/* none */

/* ---------- internal constants: ------------------------------------------- */
/* */
/* DMA configuration table size */
uint32_t const c_DMA_CFEX_tab_SIZE = e_CFEX_DMA_CONF_NB;

/* */
/* DMA configuration table                                       */
/*  0 - DMA 0 line  0 MUX 0 line 0 src  63 : HW CRC0 */
/*****************************************************************/
ts_DMA_CFEX_ELT const c_DMA_CFEX_tab[ e_CFEX_DMA_CONF_NB ] =
{
   /* 0 - DMA 0 line 0 : HW CRC0 */
   {
      e_DMA_CFEX_DMA_0,                   /* eDMA_0 or eDMA_1    */
      e_DMA_CFEX_DMA_LINE_0,              /* Line [0..63]        */
      e_DMA_CFEX_MUX_0,                   /* Mux [0..9]          */
      e_DMA_CFEX_MUX_LINE_0,              /* Mux Line [0..15]    */
      e_DMA_CFEX_MUX_SOURCE_63            /* Mux Source [0..63]  */
   }
};

/* DMA Priority table                      */
/* Group 3 is highest priority group       */
/* Priority 15 is highest priority channel */
/*   !!! One level priority by group !!!   */
te_DMA_CFEX_PRIORITY const c_DMA_CFEX_PRIORITY_tab[DMA_MAX_NB * DMA_LINE_MAX_NB]=
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
ts_DMA_DESCR DMA_descr[e_CFEX_DMA_CONF_NB];

/* ---------- provided operation bodies: ------------------------------------ */
/* none */

/* ---------- internal operation bodies: ------------------------------------ */
/* none */
