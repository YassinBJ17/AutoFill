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
#include "driver/DMA/DMA_CFEX_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */
reg16_t const FDX_c_tab_ATTR_CONVERTION[e_DMA_REQUEST_NB_VAL] =
{
   0x0000, /* value for DMA_REQUEST_8_BIT  */
   0x0101, /* value for DMA_REQUEST_16_BIT */
   0x0202  /* value for DMA_REQUEST_32_BIT */
};

reg32_t const FDX_c_tab_NBYTES_REQUEST[e_DMA_REQUEST_NB_VAL] =
{
   0x0001, /* NBytes for DMA_REQUEST_8_BIT  */
   0x0002, /* NBytes for DMA_REQUEST_16_BIT */
   0x0004  /* NBytes for DMA_REQUEST_32_BIT */
};


/* ---------- provided operation bodies: ------------------------------------ */
/* */
/* Used to configure dma */
void FDX_DMA_CFG ( CMN_IOSP_ID_t             const p_dma_conf_id,
                      ts_DMA_PROG const * const p_dma_prog )
{
   /* Local variable declaration */
   volatile ts_DMA_REG * pt_dma_reg_descr;
   te_DMA_CFEX_DMA_LINE     v_dma_line_descr;
   /* */

   /* Local variable initialization */
   /* Get the DMA register descriptor */
   pt_dma_reg_descr = FDX_DMA_descr[p_dma_conf_id].s_dma_addr;
   /* Get the DMA line descriptor */
   v_dma_line_descr = FDX_DMA_descr[p_dma_conf_id].s_line_nb;

   /* Source address */
   /* >RELAX<SYNCHRONe_C_Code_10.7> The cast is safe : casting from (uint32_t) to (reg32_t). */
   pt_dma_reg_descr->s_TCD[v_dma_line_descr].s_SADDR.u_R = (reg32_t)p_dma_prog->s_src_addr;
   /* Source address offset after each transfer (32-bit transfer ) */
   pt_dma_reg_descr->s_TCD[v_dma_line_descr].s_SOFF.u_R = p_dma_prog->s_src_off;
   /* Source address last */
   /* >RELAX<SYNCHRONe_C_Code_10.7> The cast is safe : casting from (uint32_t) to (reg32_t). */
   pt_dma_reg_descr->s_TCD[v_dma_line_descr].s_SLAST.u_R = (reg32_t)(p_dma_prog->s_src_addr - p_dma_prog->s_src_last_addr);

   /* s_SSIZE and s_DSIZE set to (xx-bit transfer ) */
   pt_dma_reg_descr->s_TCD[v_dma_line_descr].s_ATTR.u_R = FDX_c_tab_ATTR_CONVERTION[p_dma_prog->s_nb_byte_req];

   /* Number of bytes to transfer per request */
   pt_dma_reg_descr->s_TCD[v_dma_line_descr].s_NBYTES.u_MLNO.u_R = FDX_c_tab_NBYTES_REQUEST[p_dma_prog->s_nb_byte_req];

   /* Destination address */
   /* >RELAX<SYNCHRONe_C_Code_10.7> The cast is safe : casting from (uint32_t) to (reg32_t). */
   pt_dma_reg_descr->s_TCD[v_dma_line_descr].s_DADDR.u_R = (reg32_t)p_dma_prog->s_dest_addr;
   /* Number of minor loops */
   /* >RELAX<SYNCHRONe_C_Code_10.7> The cast is safe : casting from (uint16_t) to (reg16_t). */
   pt_dma_reg_descr->s_TCD[v_dma_line_descr].s_CITER.u_ELINKNO.u_R = (reg16_t)p_dma_prog->s_nb_cycle;

   /* Destination offset after each transfer (32-bit transfer ) */
   /* >RELAX<SYNCHRONe_C_Code_10.7> The cast is safe : casting from (uint16_t) to (reg16_t). */
   pt_dma_reg_descr->s_TCD[v_dma_line_descr].s_DOFF.u_R = (reg16_t)p_dma_prog->s_dest_off ;

   /* Destination address last seg : 0->adjust of source size */
   /* >RELAX<SYNCHRONe_C_Code_10.7> The cast is safe : casting from (uint32_t) to (reg32_t). */
   pt_dma_reg_descr->s_TCD[v_dma_line_descr].s_DLASTSGA.u_R = (reg32_t)(p_dma_prog->s_dest_addr - p_dma_prog->s_dest_last_addr);
   /* Has to be the same as s_CITER*/
   /* >RELAX<SYNCHRONe_C_Code_10.7> The cast is safe : casting from (uint16_t) to (reg16_t). */
   pt_dma_reg_descr->s_TCD[v_dma_line_descr].s_BITER.u_ELINKNO.u_R = (reg16_t)p_dma_prog->s_nb_cycle;
   /* s_CSR register */
   /* {{RELAX<SYNCHRONe_C_Code_10.2,SYNCHRONe_C_Code_10.7> Initialisation Litteral constant : no problem of implicit cast. The Enumerate te_DMA_BUFFER_MGT  is coded in a short. */
   pt_dma_reg_descr->s_TCD[v_dma_line_descr].s_CSR.u_B.s_ESG = 0;
   /* >RELAX<SYNCHRONe_C_Code_12.14> The enumeration 's_buff_type' is either 1 or 0 (1 bit). 's_DREQ' field is waiting for only one bit. */
   pt_dma_reg_descr->s_TCD[v_dma_line_descr].s_CSR.u_B.s_DREQ = p_dma_prog->s_buff_type;
   pt_dma_reg_descr->s_TCD[v_dma_line_descr].s_CSR.u_B.s_INTHALF = 0;
   pt_dma_reg_descr->s_TCD[v_dma_line_descr].s_CSR.u_B.s_INTMAJOR = 0;
   /* }}<SYNCHRONe_C_Code_10.2,SYNCHRONe_C_Code_10.7> */
}

/* ---------- internal operation bodies: ------------------------------------ */
