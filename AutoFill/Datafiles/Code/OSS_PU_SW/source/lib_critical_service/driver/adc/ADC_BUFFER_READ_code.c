/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : <short description of the operations of the .c file>
 * -------------------------------------------------------------------------- */

#include "driver/adc/ADC_HAL_public.h"
#include "driver/adc/ADC_REG_common.h"
#include "driver/adc/ADC_CFEX_common.h"

void ADC_BUFFER_READ ( CMN_IOSP_ID_t       const p_adc_conf_id,
                       CMN_SYSTEM_ADDR_t   const p_buff_addr )
{
   /* Local variables declaration */
   ts_ADC_CFEX_ELT_TYPE      const * c_adc_elt_conf_pt;
   ts_ADC_CFEX_GEN_CONF_TYPE const * c_adc_gen_conf_pt;
   ts_ADC_CTRL_TYPE                * pt_adc_reg_descr;
   uint32_t                        v_adc_nb;
   uint16_t *                      pt_read_value;

   /* {{RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_10.2>: cast is safe, element is consistent with pointer type */
   c_adc_gen_conf_pt = ADC_CFEX_st.s_adc_gen_conf_pt;
   c_adc_elt_conf_pt = &ADC_CFEX_st.s_adc_elt_tab[p_adc_conf_id];
   pt_adc_reg_descr = c_ADC_ctrler_pt[c_adc_gen_conf_pt->s_adc_line];
   /*}}<SYNCHRONe_C_Code_10.7> */

   v_adc_nb = c_adc_elt_conf_pt->s_adc_number;

   /*>RELAX<SYNCHRONe_C_Code_11.1>: cast is safe, buffer is handled as a half-word array */
   pt_read_value = (uint16_t *) p_buff_addr;

   /* Normal channels */
   if ( v_adc_nb <= ADC_LAST_ADC_NORMAL_CHANNEL )
   {
      /* >RELAX<SYNCHRONe_C_Code_10.7>: this reg32_t is a 16b bitfiled, volatile qualifier is willingly lost */
      *pt_read_value = (uint16_t)(pt_adc_reg_descr->s_ICDR[v_adc_nb].u_B.s_CDATA);
   }
   else
   {
      /* Test channels */
      if ( v_adc_nb <= ADC_LAST_ADC_TEST_CHANNEL )
      {
         /* >RELAX<SYNCHRONe_C_Code_10.7>: this reg32_t is a 16b bitfiled, volatile qualifier is willingly lost */
         *pt_read_value = (uint16_t)(pt_adc_reg_descr->s_TCDR[v_adc_nb - ADC_LAST_ADC_NORMAL_CHANNEL - 1UL].u_B.s_CDATA);
      }
   }

}
