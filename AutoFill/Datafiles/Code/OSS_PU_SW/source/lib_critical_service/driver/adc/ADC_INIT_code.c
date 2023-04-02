/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : <short description of the operations of the .c file>
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "driver/adc/ADC_HAL_public.h"

/* ---------- include required interface: ----------------------------------- */
#include "driver/adc/ADC_CFEX_common.h"
#include "driver/adc/ADC_REG_common.h"
#include "driver/adc/ADC_HAL_private.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* */
void ADC_INIT(void)
{
   ts_ADC_CFEX_GEN_CONF_TYPE const  * c_adc_gen_conf_pt;
   uint32_t                           v_index_adc_elt;
   uint32_t                  const    c_adc_nb = ADC_CFEX_st.s_adc_nb;
   ts_ADC_CTRL_TYPE                 * pt_adc_reg_descr;
   te_ADC_CFEX_MODE_TYPE              v_mode;
   te_ADC_CFEX_DMA_TYPE               v_dma_enable;
   te_ADC_CFEX_IRQ_TYPE               v_irq_enable;

   /* {{RELAX<SYNCHRONe_C_Code_10.7>: cast is safe, element is consistent with pointer type */
   c_adc_gen_conf_pt = ADC_CFEX_st.s_adc_gen_conf_pt;
   pt_adc_reg_descr = c_ADC_ctrler_pt[c_adc_gen_conf_pt->s_adc_line];
   /* }}<SYNCHRONe_C_Code_10.7> */

   /* Reset value */
   pt_adc_reg_descr->s_MCR.u_R = (reg32_t)0x80008011;
   /* Enable ADC */
   pt_adc_reg_descr->s_MCR.u_B.s_PWDN = (reg32_t)0;

   /* Apply generic configuration */
   v_mode = c_adc_gen_conf_pt->s_mode;
   v_dma_enable = c_adc_gen_conf_pt->s_dma_enable;
   v_irq_enable = c_adc_gen_conf_pt->s_irq_enable;

   /*{{RELAX<SYNCHRONe_C_Code_10.7>: cast is safe, these enums are equal to 0 or 1, and fit on a reg32_t */
   /* scan or one-shot mode */
   pt_adc_reg_descr->s_MCR.u_B.s_MODE = (reg32_t)v_mode;
   /* enable/disable EOC interrupt */
   pt_adc_reg_descr->s_IMR.u_B.s_MSKNEOC = (reg32_t)v_irq_enable;
   /* enable/disable DMA */
   pt_adc_reg_descr->s_DMAE.u_B.s_DMAEN = (reg32_t)v_dma_enable;
   /*}}<SYNCHRONe_C_Code_10.7> */

   pt_adc_reg_descr->s_CTR[0].u_R = (reg32_t)c_adc_gen_conf_pt->s_ctr[0];
   pt_adc_reg_descr->s_CTR[1].u_R = (reg32_t)c_adc_gen_conf_pt->s_ctr[1];
   /*{{RELAX<SYNCHRONe_C_Code_7.2>: literals are used to assign the 4 elements of this table and avoid a loop */
   pt_adc_reg_descr->s_CTR[2].u_R = (reg32_t)c_adc_gen_conf_pt->s_ctr[2];
   pt_adc_reg_descr->s_CTR[3].u_R = (reg32_t)c_adc_gen_conf_pt->s_ctr[3];
   /*}}<SYNCHRONe_C_Code_7.2> */

   for ( v_index_adc_elt = 0UL ; v_index_adc_elt < c_adc_nb ; v_index_adc_elt++ )
   {
      /* Apply special ADC configuration */
      ADC_ELT_CONF( v_index_adc_elt );
   }

   if ( c_adc_gen_conf_pt->s_all == e_CMN_FLAG_ACTIVATE )
   {
      for ( v_index_adc_elt = 0UL; v_index_adc_elt < c_adc_nb ;  v_index_adc_elt++ )
      {
         /* Enable conversion for all ADCs */
         ADC_START( v_index_adc_elt );
      }
   }
}

/* ---------- internal operation bodies: ------------------------------------ */
