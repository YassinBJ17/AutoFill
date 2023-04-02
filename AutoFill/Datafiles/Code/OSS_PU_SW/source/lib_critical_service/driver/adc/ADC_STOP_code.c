/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : <short description of the operations of the .c file>
 * --------------------------------------------------------------------------
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "driver/adc/ADC_HAL_public.h"
#include "driver/adc/ADC_REG_common.h"

#include "driver/dma/DMA_HAL_public.h"

/* ---------- include required interface: ----------------------------------- */
/* LPOS Public Interface */

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */

/* Disable conversion */
void ADC_STOP( CMN_IOSP_ID_t const p_adc_conf_id )
{
   /* Local variables declaration */
   ts_ADC_CFEX_GEN_CONF_TYPE const  * c_adc_gen_conf_pt;
   ts_ADC_CFEX_ELT_TYPE      const  * c_adc_elt_conf_pt;
   ts_ADC_CTRL_TYPE                 * pt_adc_reg_descr;
   uint32_t                         v_adc_nb;
   uint32_t                         v_adc_to_disable;
   uint32_t                         v_bit_nb;
   uint32_t                         v_channel_nb;
   uint32_t                         v_shift;
   uint32_t                         v_mask;

   /*{{RELAX<SYNCHRONe_C_Code_10.7>: cast is safe, element is consistent with pointer type */
   c_adc_gen_conf_pt = ADC_CFEX_st.s_adc_gen_conf_pt;
   c_adc_elt_conf_pt = &ADC_CFEX_st.s_adc_elt_tab[p_adc_conf_id];
   pt_adc_reg_descr = c_ADC_ctrler_pt[c_adc_gen_conf_pt->s_adc_line];
   /*}}<SYNCHRONe_C_Code_10.7> */
   v_adc_nb = c_adc_elt_conf_pt->s_adc_number;

   if ( v_adc_nb > ADC_LAST_ADC_NORMAL_CHANNEL )
   {
      /* Test channels */
      v_adc_to_disable = v_adc_nb - ADC_LAST_ADC_NORMAL_CHANNEL - 1UL;
   }
   else
   {
      /* Normal channels */
      v_adc_to_disable = v_adc_nb;
   }

   /* Find channel and correct bit to disable ADC */
   v_channel_nb = v_adc_to_disable / ADC_WORD_SIZE;
   v_bit_nb = v_adc_to_disable - (v_channel_nb * ADC_WORD_SIZE);
   v_shift = v_bit_nb;
   /* >RELAX<SYNCHRONe_C_Code_10.7>: No loss, 2's complement of an uint32_t fits on an uint32_t */
   v_mask = ~( 1UL << v_shift );

   /* Disable normal conversion */
   if ( c_adc_gen_conf_pt->s_conversion == e_ADC_CFEX_NORM_CH_CONV )
   {
      if ( v_adc_nb <= ADC_LAST_ADC_NORMAL_CHANNEL )
      {
         /* Normal channels */
         pt_adc_reg_descr->s_ICNCMR[v_channel_nb].u_B.s_NCE_CHx =
           ( pt_adc_reg_descr->s_ICNCMR[v_channel_nb].u_B.s_NCE_CHx & (reg32_t)v_mask );
      }
      else
      {
         /* Test channels */
         pt_adc_reg_descr->s_TCNCMR.u_B.s_NCE_CHx =
           ( pt_adc_reg_descr->s_TCNCMR.u_B.s_NCE_CHx & (reg32_t)v_mask );
      }
      /* Disable start flag  */
      if ( pt_adc_reg_descr->s_MCR.u_B.s_NSTART != (reg32_t)0 )
      {
         pt_adc_reg_descr->s_MCR.u_B.s_NSTART = (reg32_t)0;
      }
   }
   else
   {
      if ( v_adc_nb <= ADC_LAST_ADC_NORMAL_CHANNEL )
      {
         /* Normal channels */
         pt_adc_reg_descr->s_ICJCMR[v_channel_nb].u_B.s_JCE_CH =
           ( pt_adc_reg_descr->s_ICJCMR[v_channel_nb].u_B.s_JCE_CH & (reg32_t)v_mask );
      }
      else
      {
         /* Test channels */
         pt_adc_reg_descr->s_TCJCMR.u_B.s_JCE_CHx =
           ( pt_adc_reg_descr->s_TCJCMR.u_B.s_JCE_CHx & (reg32_t)v_mask );
      }
      /* Disable start flag  */
      if ( pt_adc_reg_descr->s_MCR.u_B.s_JSTART != (reg32_t)0 )
      {
         pt_adc_reg_descr->s_MCR.u_B.s_JSTART = (reg32_t)0;
      }
   }
   if(c_adc_elt_conf_pt->s_dma_enable == e_ADC_CFEX_DMA_ENABLE)
   {
      FDX_DMA_START(  ADC_CFEX_st.s_adc_elt_tab[p_adc_conf_id].s_dma_conf_nb, e_CMN_FLAG_STOP);
   }
}

/* ---------- internal operation bodies: ------------------------------------ */
