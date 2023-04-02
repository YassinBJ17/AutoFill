/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : ADC configuration
 * --------------------------------------------------------------------------
 * -------------------------------------------------------------------------- */



/* ---------- include required interface: ----------------------------------- */
#include "driver/adc/ADC_HAL_private.h"
#include "driver/adc/ADC_CFEX_common.h"
#include "driver/adc/ADC_REG_common.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* */
void ADC_ELT_CONF( CMN_IOSP_ID_t const p_adc_conf_id )
{
   /* Local variables */
   ts_ADC_CFEX_ELT_TYPE      const * c_adc_elt_conf_pt;
   ts_ADC_CFEX_GEN_CONF_TYPE const * c_adc_gen_conf_pt;
   ts_ADC_CTRL_TYPE                * pt_adc_reg_descr;
   te_ADC_CFEX_DMA_TYPE              v_dma_enable;
   te_ADC_CFEX_IRQ_TYPE              v_irq_enable;
   uint32_t                          v_adc_nb;
   uint32_t                          v_adc_to_configure;
   uint32_t                          v_bit_nb;
   uint32_t                          v_channel_nb;
   uint32_t                          v_shift;
   uint32_t                          v_mask;

   /*{{RELAX<SYNCHRONe_C_Code_10.7>: cast is safe, element is consistent with pointer type */
   c_adc_gen_conf_pt = ADC_CFEX_st.s_adc_gen_conf_pt;
   c_adc_elt_conf_pt = &ADC_CFEX_st.s_adc_elt_tab[p_adc_conf_id];
   pt_adc_reg_descr = c_ADC_ctrler_pt[c_adc_gen_conf_pt->s_adc_line];
   /*}}<SYNCHRONe_C_Code_10.7> */

   v_dma_enable = c_adc_elt_conf_pt->s_dma_enable;
   v_irq_enable = e_ADC_CFEX_IRQ_DISABLE; /* IRQ disable by default */
   v_adc_nb = c_adc_elt_conf_pt->s_adc_number;

   if ( v_adc_nb > ADC_LAST_ADC_NORMAL_CHANNEL )
   {
      /* Test channels */
      v_adc_to_configure = v_adc_nb - ADC_LAST_ADC_NORMAL_CHANNEL - 1UL;
   }
   else
   {
      /* Normal channels */
      v_adc_to_configure = v_adc_nb;
   }

   v_channel_nb = v_adc_to_configure / ADC_WORD_SIZE;
   v_bit_nb = v_adc_to_configure - (v_channel_nb * ADC_WORD_SIZE);
   v_shift = v_bit_nb;
   /* >RELAX<SYNCHRONe_C_Code_10.7>: No loss, 2's complement of an uint32_t fits on an uint32_t */
   v_mask = ~( 1UL << v_shift );

   if ( v_adc_nb <= ADC_LAST_ADC_NORMAL_CHANNEL )
   {
      /* Normal channels */
      /* Enable/disable DMA transfer */
      pt_adc_reg_descr->s_ICDSR[v_channel_nb].u_B.s_DS_CHx =
      /* >RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_12.14>: no loss, uint32_t fits on reg32_t, enum is 0 or 1 */
        ( pt_adc_reg_descr->s_ICDSR[v_channel_nb].u_B.s_DS_CHx & (reg32_t)v_mask ) | (reg32_t)( v_dma_enable << v_shift );

      /* Enable/disable interrupt */
      pt_adc_reg_descr->s_ICIMR[v_channel_nb].u_B.s_IM_CHx =
      /* >RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_12.14>: no loss, uint32_t fits on reg32_t, enum is 0 or 1 */
        ( pt_adc_reg_descr->s_ICIMR[v_channel_nb].u_B.s_IM_CHx & (reg32_t)v_mask ) | (reg32_t)( v_irq_enable << v_shift );

      /* Set reset value and precharge phase */
      pt_adc_reg_descr->s_ICDR[v_adc_nb].u_R = (reg32_t)0x00000000;
      pt_adc_reg_descr->s_ICDR[v_adc_nb].u_B.s_PCE = (reg32_t)1;
      /* >RELAX<SYNCHRONe_C_Code_10.7>: no loss, uint32_t fits on reg32_t */
      pt_adc_reg_descr->s_ICDR[v_adc_nb].u_B.s_CTSEL = (reg32_t)c_adc_elt_conf_pt->s_ctr_index;
   }
   else
   {
      /* Test channels */
      /* Enable/disable DMA transfer */
      pt_adc_reg_descr->s_TCDSR.u_B.s_DS_CHx =
      /* >RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_12.14>: no loss, uint32_t fits on reg32_t, enum is 0 or 1 */
        ( pt_adc_reg_descr->s_TCDSR.u_B.s_DS_CHx & (reg32_t)v_mask ) | (reg32_t)( v_dma_enable << v_shift );

      /* Enable/disable interrupt */
      pt_adc_reg_descr->s_TCIMR.u_B.s_IM_CHx =
      /* >RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_12.14>: no loss, uint32_t fits on reg32_t, enum is 0 or 1 */
        ( pt_adc_reg_descr->s_TCIMR.u_B.s_IM_CHx & (reg32_t)v_mask ) | (reg32_t)( v_irq_enable << v_shift );

      /* Set reset value and precharge phase */
      pt_adc_reg_descr->s_TCDR[v_adc_to_configure].u_R = (reg32_t)0x00000000;
      pt_adc_reg_descr->s_TCDR[v_adc_to_configure].u_B.s_PCE = (reg32_t)1;
      /* >RELAX<SYNCHRONe_C_Code_10.7>: no loss, uint32_t fits on reg32_t */
      pt_adc_reg_descr->s_TCDR[v_adc_to_configure].u_B.s_CTSEL = (reg32_t)c_adc_elt_conf_pt->s_ctr_index;
   }

}

/* ---------- internal operation bodies: ------------------------------------ */
