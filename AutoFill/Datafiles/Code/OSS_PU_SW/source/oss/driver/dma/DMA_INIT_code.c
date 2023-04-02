/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : <short description of the operations of the .c file>
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "driver/dma/DMA_HAL_public.h"

/* ---------- include required interface: ----------------------------------- */
#include "type/common_type.h"
#include "driver/dma/DMA_CFEX_public.h"
/* ---------- internal define constants: ------------------------------------ */
/* s_ECP=0, s_DPA=0, s_GRPPRI (RO), s_CHPRI=0*/
#define DMA_DCHPRI_MASK      0x30u

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */
/* MPC577 DMA specific controller register mapping */
ts_DMA_REG volatile * const FDX_DMA_ctrl_addr[DMA_MAX_NB] =
{
   DMA_0_REG_ADDR,     /* eDMA_0  */
   DMA_1_REG_ADDR      /* eDMA_1  */
};
/* MPC577 DMA specific controller register mapping */
ts_DMA_MUX_REG volatile * const FDX_DMA_MUX_ctrl_addr[DMA_MUX_MAX_NB] =
{
   DMA_MUX_0_REG_ADDR,     /* MUX_0  */
   DMA_MUX_1_REG_ADDR,     /* MUX_1  */
   DMA_MUX_2_REG_ADDR,     /* MUX_2  */
   DMA_MUX_3_REG_ADDR,     /* MUX_3  */
   DMA_MUX_4_REG_ADDR,     /* MUX_4  */
   DMA_MUX_5_REG_ADDR,     /* MUX_5  */
   DMA_MUX_6_REG_ADDR,     /* MUX_6  */
   DMA_MUX_7_REG_ADDR,     /* MUX_7  */
   DMA_MUX_8_REG_ADDR,     /* MUX_8  */
   DMA_MUX_9_REG_ADDR      /* MUX_9  */
};

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* */
void FDX_DMA_INIT( void )
{
   /* Local variable declaration */
   uint32_t v_index;
   uint32_t v_dma_ind;
   uint32_t v_line_ind;
   uint32_t v_offset_tab;
   ts_DMA_CFEX_ELT const * pt_dma_conf;
   ts_DMA_REG volatile * pt_dma_reg;
   ts_DMA_MUX_REG volatile * pt_mux_reg;


   /* */
   /* General DMA configuration */
   /* The configuration of general DMA is equal at reset value */
   /* */
   /* Except Priority Channel */
   for ( v_dma_ind = 0ul ; v_dma_ind < DMA_MAX_NB ; v_dma_ind++ )
   {
      /* Get DMA registers descriptor */
      pt_dma_reg = FDX_DMA_ctrl_addr[v_dma_ind];
      v_offset_tab =  v_dma_ind * DMA_LINE_MAX_NB;

      for ( v_line_ind = 0ul ; v_line_ind < DMA_LINE_MAX_NB ; v_line_ind++ )
      {
         /* {{RELAX<SYNCHRONe_C_Code_10.7> No loss of precision as the table c_DMA_CFEX_PRIORITY_tab contains only Enumerate which maximum value is 15 , and the DMA_DCHPRI_MASK is coded in 8 bits. */
         pt_dma_reg->s_DCHPRI[v_line_ind].u_R = ( pt_dma_reg->s_DCHPRI[v_line_ind].u_R & ( ( reg8_t ) DMA_DCHPRI_MASK ) )
                                                  | (reg8_t)FDX_c_DMA_CFEX_PRIORITY_tab[v_line_ind + v_offset_tab];
         /* }}<SYNCHRONe_C_Code_10.7> */
      }
   }
   /* */

   /* Mux configuration */
   for ( v_index = 0ul ; v_index < FDX_c_DMA_CFEX_tab_SIZE ; v_index++ )
   {
      /* Get DMA configuration descriptor */
      pt_dma_conf = &(FDX_c_DMA_CFEX_tab[v_index]);
      /* Get DMA registers descriptor */
      pt_dma_reg = FDX_DMA_ctrl_addr[pt_dma_conf->s_dma_nb];
      /* Get MUX registers descriptor */
      pt_mux_reg = FDX_DMA_MUX_ctrl_addr[pt_dma_conf->s_dma_mux_nb];

      /* Descriptor init       */
      /*  - DMA number address */
      FDX_DMA_descr[v_index].s_dma_addr = pt_dma_reg;
      /*  - DMA line number    */
      FDX_DMA_descr[v_index].s_line_nb  = pt_dma_conf->s_dma_line_nb;

      /* Configuration init */
      /* Mux : Enable line and select source */
      /* >RELAX<SYNCHRONe_C_Code_10.7> No lost of precision whereas  s_dma_mux_source_nb is less than 127 */
      pt_mux_reg->s_CHCFG[pt_dma_conf->s_dma_mux_line_nb].u_R = (reg8_t)DMA_MUX_LINE_ENABLE + (reg8_t)pt_dma_conf->s_dma_mux_source_nb;
   }

}

/* ---------- internal operation bodies: ------------------------------------ */
