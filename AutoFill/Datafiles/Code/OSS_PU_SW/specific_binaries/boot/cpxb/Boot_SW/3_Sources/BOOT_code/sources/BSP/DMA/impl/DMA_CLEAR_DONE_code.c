/* --------------------------------------------------------------------------
 *                           Sagem Defense Securite
 *                               SAFRAN Group
 * --------------------------------------------------------------------------
 * PROJECT : CHRONOS_MOCKUP
 * CSU name :
 * %name: DMA_CLEAR_DONE_code.c %
 * %full_name: fadex#1/csrc/DMA_CLEAR_DONE_code.c/1 %
 * DESCRIPTION : short description of the operations of the .c file
 *
 * Creation information:
 *   Created by: F073297
 *   Date : Thu May 31 09:55:00 CEST 2018
 *
 * Modification information:
 *   %derived_by: F605763 %
 *   %date_created:Thu May 12 18:18:07 CEST 2022 %
 * --------------------------------------------------------------------------
 * SAGEM Defense Securite document. Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "DMA_HAL_public.h"

/* ---------- include required interface: ----------------------------------- */
/* LPOS Common Interface */
#include "CMN_TYPES_common.h"
#include "DMA_CFEX_public.h"

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
/* Used to start or stop dma */
void DMA_CLEAR_DONE ( CMN_IOSP_ID_t const p_dma_conf_id,
                      te_CMN_FLAG_RUN const p_dma_done  )
{
   /* Local variable declaration */
   ts_DMA_REG volatile * pt_dma_reg_descr;
   te_DMA_CFEX_DMA_LINE v_dma_line_descr;
   /* */

   /* Writes the datas contained in the CPU internal write buffer  */
   /* >RELAX<SYNCHRONe_C_Code_14.2> Assembler instruction */
   asm("msync");

   /* Local variable initialization */
   /* Get the DMA register descriptor */
   pt_dma_reg_descr = DMA_descr[p_dma_conf_id].s_dma_addr;
   /* Get the DMA line descriptor */
   v_dma_line_descr = DMA_descr[p_dma_conf_id].s_line_nb;

   /* Enable request signal */
   /* {{RELAX<SYNCHRONe_C_Code_10.2,SYNCHRONe_C_Code_10.7> Initialisation Litteral value for s_CSR.u_B.s_START coded in short. There is no lost of precision */
   if ( p_dma_done == e_CMN_FLAG_DONE )
   {
      /* DMA start */
      pt_dma_reg_descr->s_TCD[v_dma_line_descr].s_CSR.u_B.s_DONE = 1;
   }
   else
   {
      /* DMA stop */
      pt_dma_reg_descr->s_TCD[v_dma_line_descr].s_CSR.u_B.s_DONE = 0;
   }
   /* }}<SYNCHRONe_C_Code_10.2,SYNCHRONe_C_Code_10.7> */
}

/* ---------- internal operation bodies: ------------------------------------ */
/* none */
