/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : lvdt_compute_values function which computes lvdt
 *               related fault word for CSS
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/lvdt/lvdt_public.h"
#include "middleware/lvdt/lvdt_private.h"
#include "driver/adc/ADC_HAL_public.h"

/* ---------- include required interface: ----------------------------------- */

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/*  Fault words LVDT */
tu_lvdt_fault_word lvdt_fault_word;

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */

/* Implements REQ_FADEX_OS_SRD-LVTD-xxxx */
void lvdt_compute_fault_word(const boolean_t                             use_data_from_lvdt_a_or_lvdt_b ,
                             float32_t * const                           voltage_lvdt_dc_raw_s1         ,
                             float32_t * const                           voltage_lvdt_dc_raw_s2         ,
                             float32_t                                   lvdt_exc    ,
                             const ts_lvdt_fault_word_thresholds * const thresholds)
{
   /* Acquire lvdt DC RAW voltage of the internal ADC (SARADC_B) */
   {
     uint32_t adc_id_s1;
     uint32_t adc_id_s2;
     uint16_t adc_raw_value_s1;
     uint16_t adc_raw_value_s2;
     if(FALSE == use_data_from_lvdt_a_or_lvdt_b)
     {
       adc_id_s1 = (uint32_t)e_CFEX_ADC_INT_AN24;
       adc_id_s2 = (uint32_t)e_CFEX_ADC_INT_AN17;
     }
     else
     {
       adc_id_s1 = (uint32_t)e_CFEX_ADC_INT_AN44;
       adc_id_s2 = (uint32_t)e_CFEX_ADC_INT_AN25;
     }
     ADC_BUFFER_READ ((uint32_t)adc_id_s1, &adc_raw_value_s1);
     ADC_BUFFER_READ ((uint32_t)adc_id_s2, &adc_raw_value_s2);
     *voltage_lvdt_dc_raw_s1 = (float32_t)((adc_raw_value_s1) * ADC_CONVERT_VALUE);
     *voltage_lvdt_dc_raw_s2 = (float32_t)((adc_raw_value_s2) * ADC_CONVERT_VALUE);
   }
   /* 2022-05-13 : pb hardware sur CBP -> voltage_lvdt_dc_raw _sx sont INEXPLOITABLES ! */

   /* Build fault word */
   {
      lvdt_fault_word.u_word = (uint32_t) 0;  /* Sets noticeably all spares to 0 */

      lvdt_fault_word.u_bit.s_meas1_oc_fault               = (*voltage_lvdt_dc_raw_s1 < thresholds->t12);
      lvdt_fault_word.u_bit.s_meas1_short_diff             = (lvdt_vs1_measure + lvdt_vs2_measure) < thresholds->t18;
      lvdt_fault_word.u_bit.s_meas1_short_gnd              = (*voltage_lvdt_dc_raw_s1 < thresholds->t11);
      lvdt_fault_word.u_bit.s_meas1_out_of_range           = (lvdt_s1 <  thresholds->t100) || (lvdt_s1 >  thresholds->t101);
      lvdt_fault_word.u_bit.s_meas2_oc_fault               = (*voltage_lvdt_dc_raw_s2 < thresholds->t14);
      lvdt_fault_word.u_bit.s_meas2_short_diff             = (lvdt_vs1_measure + lvdt_vs2_measure) < thresholds->t18;
      lvdt_fault_word.u_bit.s_meas2_short_gnd              = (*voltage_lvdt_dc_raw_s2 < thresholds->t13);
      lvdt_fault_word.u_bit.s_meas2_out_of_range           = (lvdt_s2 <  thresholds->t102) || (lvdt_s2 >  thresholds->t103);
      lvdt_fault_word.u_bit.s_exc_oc_fault                 = (lvdt_vs1_measure + lvdt_vs2_measure) < thresholds->t18;
      lvdt_fault_word.u_bit.s_exc_short_diff               = (lvdt_exc < thresholds->t17);
      lvdt_fault_word.u_bit.s_exc_short_to_gnd             = (lvdt_exc < thresholds->t17);
      lvdt_fault_word.u_bit.s_exc_out_of_range             = (lvdt_exc < thresholds->t15) ||
                                                             (lvdt_exc > thresholds->t16);
      lvdt_fault_word.u_bit.s_out_of_range                 = (lvdt_vs1_measure    <  thresholds->t19) ||
                                                             (lvdt_vs1_measure    >  thresholds->t20) ||
                                                             (lvdt_vs2_measure    <  thresholds->t21) ||
                                                             (lvdt_vs2_measure    >  thresholds->t22) ||
                                                             (lvdt_ratio_measure  <  thresholds->t23) ||
                                                             (lvdt_ratio_measure  >  thresholds->t24);
      lvdt_fault_word.u_bit.s_int_failure                  = (lvdt_s1_gnd_avg <  thresholds->t1) || (lvdt_s1_gnd_avg >  thresholds->t2) ||
                                                             (lvdt_s1_ref_avg <  thresholds->t3) || (lvdt_s1_ref_avg >  thresholds->t4) ||
                                                             (lvdt_s2_gnd_avg <  thresholds->t5) || (lvdt_s2_gnd_avg >  thresholds->t6) ||
                                                             (lvdt_s2_ref_avg <  thresholds->t7) || (lvdt_s2_ref_avg >  thresholds->t8);
      lvdt_fault_word.u_bit.s_unavailable                  = 0;
      lvdt_fault_word.u_bit.s_invalid                      = 0;
      if(lvdt_fault_word.u_word != 0)
      {
         lvdt_fault_word.u_bit.s_invalid                   = 1;
      }
   }
}

/* ---------- internal operations: ------------------------------------------ */

