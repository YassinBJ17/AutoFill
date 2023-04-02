/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * SAGEM Defense Securite document. Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "driver/dma/DMA_HAL_public.h"

/* ---------- include required interface: ----------------------------------- */
#include "type/common_type.h"
#include "driver/dma/DMA_CFEX_public.h"
/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Used to start or stop dma */
void FDX_DMA_START ( CMN_IOSP_ID_t const p_dma_conf_id,
                        te_CMN_FLAG_RUN const p_dma_start  )
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
   pt_dma_reg_descr = FDX_DMA_descr[p_dma_conf_id].s_dma_addr;
   /* Get the DMA line descriptor */
   v_dma_line_descr = FDX_DMA_descr[p_dma_conf_id].s_line_nb;

   /* Enable request signal */
   /* {{RELAX<SYNCHRONe_C_Code_10.2,SYNCHRONe_C_Code_10.7> Initialisation Litteral value for s_CSR.u_B.s_START coded in short. There is no lost of precision */
   if ( p_dma_start == e_CMN_FLAG_RUN )
   {
      /* DMA start */
      pt_dma_reg_descr->s_TCD[v_dma_line_descr].s_CSR.u_B.s_START = 1;
   }
   else
   {
      /* DMA stop */
      pt_dma_reg_descr->s_TCD[v_dma_line_descr].s_CSR.u_B.s_START = 0;
   }
   /* }}<SYNCHRONe_C_Code_10.2,SYNCHRONe_C_Code_10.7> */
}

/* ---------- internal operation bodies: ------------------------------------ */
