/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Start measurements
 * --------------------------------------------------------------------------
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "driver/adc/ADC_HAL_public.h"
#include "driver/adc/ADC_REG_common.h"


/* ---------- include required interface: ----------------------------------- */
#include "driver/dma/DMA_HAL_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* */
void ADC_DMA_START( CMN_IOSP_ID_t const p_adc_conf_id )
{
   /* Local variables declaration */
   ts_ADC_CFEX_ELT_TYPE      const * c_adc_elt_conf_pt;
   ts_ADC_CFEX_GEN_CONF_TYPE const * c_adc_gen_conf_pt;
   ts_DMA_PROG                   v_adc_dma_config;
   uint32_t                      v_adc_nb;
   uint32_t                      v_itcdr_addr;
   uint32_t                      * pt_adc_read;
   ts_ADC_CTRL_TYPE              * pt_adc_reg_descr;

   /* Get configuration */
   /* {{RELAX<SYNCHRONe_C_Code_10.7>: cast is safe, element is consistent with pointer type */
   c_adc_gen_conf_pt = ADC_CFEX_st.s_adc_gen_conf_pt;
   c_adc_elt_conf_pt = &ADC_CFEX_st.s_adc_elt_tab[p_adc_conf_id];
   pt_adc_reg_descr = c_ADC_ctrler_pt[c_adc_gen_conf_pt->s_adc_line];
   /* }}RELAX<SYNCHRONe_C_Code_10.7> */

   v_adc_nb = c_adc_elt_conf_pt->s_adc_number;

   /* Enable conversion + start flags */
   ADC_START(p_adc_conf_id);

   /* Get I/TCDR address */
   if ( v_adc_nb <= ADC_LAST_ADC_NORMAL_CHANNEL )
   {
      /* >RELAX<SYNCHRONe_C_Code_11.1>: cast is safe, addr of a structure is stored in an uint32_t */
      v_itcdr_addr = (uint32_t) &(pt_adc_reg_descr->s_ICDR[v_adc_nb]);
   }
   else
   {
      /* >RELAX<SYNCHRONe_C_Code_11.1>: cast is safe, addr of a structure is stored in an uint32_t */
      v_itcdr_addr = (uint32_t) &(pt_adc_reg_descr->s_TCDR[v_adc_nb - ADC_LAST_ADC_NORMAL_CHANNEL - 1UL]);
   }

   /* */
   FDX_DMA_REQUEST( ADC_CFEX_st.s_adc_elt_tab[p_adc_conf_id].s_dma_conf_nb,
                   e_CMN_FLAG_NOT_ACTIVATE );

   /* >RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1>: table element's address is consistent with ptr type */
   pt_adc_read = (uint32_t * )( &v_adc_int_buffer[p_adc_conf_id] );

   /* 32-bits transfer by default */
   v_adc_dma_config.s_nb_byte_req    = e_DMA_REQUEST_32_BIT;
   v_adc_dma_config.s_src_addr       = v_itcdr_addr;
   v_adc_dma_config.s_src_last_addr  = v_adc_dma_config.s_src_addr;
   v_adc_dma_config.s_src_off        = (uint16_t)0;
   /*{{RELAX<SYNCHRONe_C_Code_11.1> cast is safe, address is stored in an uint32_t */
   v_adc_dma_config.s_dest_addr      = (uint32_t)pt_adc_read;
   v_adc_dma_config.s_dest_last_addr =
   /* >RELAX<SYNCHRONe_C_Code_10.7>: No loss, size_t fits on an uint32_t */
       (uint32_t)pt_adc_read + ((uint32_t)ADC_INT_NB_MEAS * (uint32_t)sizeof(uint32_t));
   /*}}RELAX<SYNCHRONe_C_Code_11.1> */
   /* >RELAX<SYNCHRONe_C_Code_10.7>: No loss, size_t fits on an uint32_t */
   v_adc_dma_config.s_dest_off       = (uint16_t)sizeof(uint32_t);
   v_adc_dma_config.s_nb_cycle       = (uint16_t)ADC_INT_NB_MEAS;
   v_adc_dma_config.s_buff_type      = e_DMA_BUFFER_ONE_SHOT; /* one shot by default */

   /* */
   FDX_DMA_CFG( ADC_CFEX_st.s_adc_elt_tab[p_adc_conf_id].s_dma_conf_nb, &v_adc_dma_config );

   /* */
   FDX_DMA_REQUEST( ADC_CFEX_st.s_adc_elt_tab[p_adc_conf_id].s_dma_conf_nb,
                   e_CMN_FLAG_ACTIVATE );

   FDX_DMA_START( ADC_CFEX_st.s_adc_elt_tab[p_adc_conf_id].s_dma_conf_nb, e_CMN_FLAG_RUN);
}

/* ---------- internal operation bodies: ------------------------------------ */
