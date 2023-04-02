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
/* Used to read the status dma */
void FDX_DMA_STATUS ( CMN_IOSP_ID_t         const p_dma_conf_id,
                         ts_DMA_STATUS * const p_dma_status  )
{
   /* Local variable declaration */
   ts_DMA_REG volatile * pt_dma_reg_descr;
   te_DMA_CFEX_DMA_LINE v_dma_line_descr;

   /* Local variable initialization */
   /* Get the DMA register descriptor */
   pt_dma_reg_descr = FDX_DMA_descr[p_dma_conf_id].s_dma_addr;
   /* Get the DMA line descriptor */
   v_dma_line_descr = FDX_DMA_descr[p_dma_conf_id].s_line_nb;

   /* Read Done status */
   /* {{RELAX<SYNCHRONe_C_Code_10.7> The cast is safe : casting from (reg16_t) to (uint16_t) */
   p_dma_status->s_read_done = (uint16_t)pt_dma_reg_descr->s_TCD[v_dma_line_descr].s_CSR.u_B.s_DONE;

   /* Read in progress status */
   p_dma_status->s_read_in_progress = (uint16_t)pt_dma_reg_descr->s_TCD[v_dma_line_descr].s_CSR.u_B.s_ACTIVE;

   /* Read cycle counter status */
   p_dma_status->s_cycle_count = (uint16_t)pt_dma_reg_descr->s_TCD[v_dma_line_descr].s_CITER.u_ELINKNO.u_R;

   /* Read number of cycle status */
   p_dma_status->s_cycle_nb = (uint16_t)pt_dma_reg_descr->s_TCD[v_dma_line_descr].s_BITER.u_ELINKNO.u_R;
   /* }}<SYNCHRONe_C_Code_10.7> */
}

/* ---------- internal operation bodies: ------------------------------------ */
