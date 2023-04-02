/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "driver/dma/DMA_HAL_public.h"

/* ---------- include required interface: ----------------------------------- */
#include "DMA_CFEX_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* */
/* Used to configure dma */
void FDX_DMA_GET_CFG ( CMN_IOSP_ID_t       const p_dma_conf_id,
                          ts_DMA_PROG *  const p_dma_prog )
{
   /* Local variable declaration */
   volatile ts_DMA_REG * pt_dma_reg_descr;
   te_DMA_CFEX_DMA_LINE   v_dma_line_descr;
   /* */

   /* Local variable initialization */
   /* Get the DMA register descriptor */
   pt_dma_reg_descr = FDX_DMA_descr[p_dma_conf_id].s_dma_addr;
   /* Get the DMA line descriptor */
   v_dma_line_descr = FDX_DMA_descr[p_dma_conf_id].s_line_nb;

   /* Source address */
   /* {{RELAX<SYNCHRONe_C_Code_10.7> The cast is safe : casting from (reg32_t) to (uint32_t). */
   p_dma_prog->s_src_addr = (uint32_t)pt_dma_reg_descr->s_TCD[v_dma_line_descr].s_SADDR.u_R ;
   p_dma_prog->s_src_last_addr = p_dma_prog->s_src_addr - (uint32_t)pt_dma_reg_descr->s_TCD[v_dma_line_descr].s_SLAST.u_R ;
   /* }}<SYNCHRONe_C_Code_10.7>   */

   /* Source address offset after each transfer (32-bit transfer ) */
   p_dma_prog->s_src_off = pt_dma_reg_descr->s_TCD[v_dma_line_descr].s_SOFF.u_R;

   /* Number of bytes to transfer per request */
   /* >RELAX<SYNCHRONe_C_Code_10.7> The value can be coded in unsigned value. */
   /* >RELAX<SYNCHRONe_C_Code_10.3,SYNCHRONe_C_Code_12.14> : 'u_MLNO.u_R' filed is either 1, 2 or 4. Operation 'u_MLNO.u_R - 1u' corresponds to the possible values of the 's_nb_byte_req'. */
   p_dma_prog->s_nb_byte_req = (te_DMA_BYTE_REQ)(pt_dma_reg_descr->s_TCD[v_dma_line_descr].s_NBYTES.u_MLNO.u_R - 1u);

   /* Destination address */
   /* {{RELAX<SYNCHRONe_C_Code_10.7> The cast is safe : casting from (reg32_t) to (uint32_t). */
   p_dma_prog->s_dest_addr = (uint32_t)pt_dma_reg_descr->s_TCD[v_dma_line_descr].s_DADDR.u_R ;
   p_dma_prog->s_dest_last_addr = p_dma_prog->s_dest_addr - (uint32_t)pt_dma_reg_descr->s_TCD[v_dma_line_descr].s_DLASTSGA.u_R ;
   /* }}<SYNCHRONe_C_Code_10.7>   */

   /* Number of minor loops */
   p_dma_prog->s_nb_cycle = pt_dma_reg_descr->s_TCD[v_dma_line_descr].s_CITER.u_ELINKNO.u_R ;
   /* Destination offset after each transfer (32-bit transfer ) */
   p_dma_prog->s_dest_off = pt_dma_reg_descr->s_TCD[v_dma_line_descr].s_DOFF.u_R ;
   /* Has to be the same as s_CITER*/
   p_dma_prog->s_nb_cycle = pt_dma_reg_descr->s_TCD[v_dma_line_descr].s_BITER.u_ELINKNO.u_R;
   /* s_CSR register */
   /* >RELAX<SYNCHRONe_C_Code_10.7, SYNCHRONe_C_Code_12.14> : The 's_DREQ' field is only one bit. The enumeration 's_buff_type' is waiting for either 1 or 0 (1 bit). */
   p_dma_prog->s_buff_type = ( te_DMA_BUFFER_MGT )( pt_dma_reg_descr->s_TCD[v_dma_line_descr].s_CSR.u_B.s_DREQ );

}
