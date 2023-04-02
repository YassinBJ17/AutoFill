/* --------------------------------------------------------------------------
 *                           Sagem Defense Securite
 *                               SAFRAN Group
 * --------------------------------------------------------------------------
 * PROJECT : CHRONOS_MOCKUP
 * CSU name :
 * %name: HWCRC_CFG_code.c %
 * %full_name: fadex#1/csrc/HWCRC_CFG_code.c/1 %
 * DESCRIPTION : short description of the operations of the .c file
 *
 * Creation information:
 *   Created by: F073297
 *   Date : Thu May 31 09:54:56 CEST 2018
 *
 * Modification information:
 *   %derived_by: F605763 %
 *   %date_created:Thu May 12 18:18:29 CEST 2022 %
 * --------------------------------------------------------------------------
 * SAGEM Defense Securite document. Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "HWCRC_HAL_public.h"
#include "HWCRC_REG_common.h"


/* LPOS Public Interface */
/* none */

/* LPOS Private Interface */
/* none */

/* ---------- internal define constants: ------------------------------------ */
/* none */

/* ---------- internal types: ----------------------------------------------- */
/* none */

/* ---------- internal operations: ------------------------------------------ */
/* none */

/* ---------- internal constants: ------------------------------------------- */
/* none */

/* ---------- internal data: ------------------------------------------------ */
/* none */



/* ---------- provided operation bodies: ------------------------------------ */
/* */
/* Used to configure dma */
void HWCRC_CFG ( te_HWCRC_POLYG const * const p_HWCRC_POLYG )
{
   /* Local variable declaration */
    ts_HWCRC_REG volatile * pt_hwcrc_reg_descr = (ts_HWCRC_REG volatile *) HWCRC_0_BASE_ADDR;
   /* */

   /* Local variable initialization */
   /* Set the Polynomial selection */
   pt_hwcrc_reg_descr->s_CRC_CFG.u_B.s_POLYG = (reg32_t)p_HWCRC_POLYG;

}

/* ---------- internal operation bodies: ------------------------------------ */
/* none */
