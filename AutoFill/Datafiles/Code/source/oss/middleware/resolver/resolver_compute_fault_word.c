/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : resolver_compute_values function which computes resolver
 *               related fault word for CSS
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/resolver/resolver_public.h"
#include "middleware/resolver/resolver_private.h"
#include "driver/adc/ADC_HAL_public.h"

/* ---------- include required interface: ----------------------------------- */

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/*  Fault word XR */
tu_xr_fault_word xr_fault_word;

/* ---------- internal constants: ------------------------------------------- */
#define threshold_tbc1   ((float32_t) -0.040 )
#define threshold_tbc2   ((float32_t) +0.040 )
#define threshold_tbc3   ((float32_t) +2.4   )
#define threshold_tbc4   ((float32_t) +2.55  )
#define threshold_tbc5   ((float32_t) -0.040 )
#define threshold_tbc6   ((float32_t) +0.040 )
#define threshold_tbc7   ((float32_t) +2.4   )
#define threshold_tbc8   ((float32_t) +2.55  )
#define threshold_tbc9   ((float32_t) UNKNOWN)
#define threshold_tbc10  ((float32_t) UNKNOWN)
#define threshold_tbc11  ((float32_t) +0.3   )
#define threshold_tbc12  ((float32_t) +2.55  )
#define threshold_tbc13  ((float32_t) UNKNOWN)
#define threshold_tbc14  ((float32_t) UNKNOWN)
#define threshold_tbc15  ((float32_t) +3.0   )
#define threshold_tbc16  ((float32_t) +9.7   )
#define threshold_tbc17  ((float32_t) +2.0   )
#define threshold_tbc18  ((float32_t) +0.07  )
#define threshold_tbc19  ((float32_t) -0.6025)
#define threshold_tbc20  ((float32_t) +0.6025)
#define threshold_tbc21  ((float32_t) -0.6025)
#define threshold_tbc22  ((float32_t) +0.6025)
#define threshold_tbc23  ((float32_t) -166.4 ) /*deg*/
#define threshold_tbc24  ((float32_t) +166.4 ) /*deg*/
#define threshold_tbc100 ((float32_t) -5.52  )
#define threshold_tbc101 ((float32_t) +5.52  )
#define threshold_tbc102 ((float32_t) -5.36  )
#define threshold_tbc103 ((float32_t) +5.52  )

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */

/* Implements REQ_FADEX_OS_SRD-RESOLVER-0020 */
void resolver_compute_fault_word(const boolean_t channel_is_a     ,
                                 float32_t * const voltage_dc_raw ,
                                 float32_t xr_xrb_exc)
{
   /* Acquire XR DC RAW voltage on the line AN46 / AN45 of the internal ADC (SARADC_B) */
   {
     uint32_t adc_id;
     uint16_t adc_raw_value;
     if(channel_is_a)
     {
       adc_id = (uint32_t)e_CFEX_ADC_INT_AN46;
     }
     else
     {
       adc_id = (uint32_t)e_CFEX_ADC_INT_AN45;
     }
     ADC_BUFFER_READ ((uint32_t)adc_id, &adc_raw_value);
     *voltage_dc_raw = (float32_t)((adc_raw_value) * ADC_CONVERT_VALUE);
   }

   /* Build fault word */
   {
      xr_fault_word.u_word = (uint32_t) 0; /* Sets noticeably all spares to 0 */

      xr_fault_word.u_bit.s_open_circuit_sin               = (*voltage_dc_raw < threshold_tbc12);
      xr_fault_word.u_bit.s_short_diff_sin                 = (xr_vsin_measure * xr_vsin_measure + xr_vcos_measure * xr_vcos_measure) < threshold_tbc18;
      xr_fault_word.u_bit.s_short_to_gnd_sin               = (*voltage_dc_raw < threshold_tbc11);
      xr_fault_word.u_bit.s_out_of_range_sin               = (xr_vsin < threshold_tbc100) || (xr_vsin > threshold_tbc101);
      xr_fault_word.u_bit.s_open_circuit_cos               = (*voltage_dc_raw < threshold_tbc12);
      xr_fault_word.u_bit.s_short_diff_cos                 = (xr_vsin_measure * xr_vsin_measure + xr_vcos_measure * xr_vcos_measure) < threshold_tbc18;
      xr_fault_word.u_bit.s_short_to_gnd_cos               = (*voltage_dc_raw < threshold_tbc11);
      xr_fault_word.u_bit.s_out_of_range_cos               = (xr_vcos < threshold_tbc102) || (xr_vcos > threshold_tbc103);
      xr_fault_word.u_bit.s_open_circuit_exc               = (xr_vsin_measure * xr_vsin_measure + xr_vcos_measure * xr_vcos_measure) < threshold_tbc18;
      xr_fault_word.u_bit.s_short_diff_exc                 = (xr_xrb_exc < threshold_tbc17);
      xr_fault_word.u_bit.s_short_to_gnd_exc               = (xr_xrb_exc < threshold_tbc17);
      xr_fault_word.u_bit.s_out_of_range_exc               = (xr_xrb_exc < threshold_tbc15) ||
                                                             (xr_xrb_exc > threshold_tbc16);
      xr_fault_word.u_bit.s_out_of_range_final             = (xr_vsin_measure < threshold_tbc19) ||
                                                             (xr_vsin_measure > threshold_tbc20) ||
                                                             (xr_vcos_measure < threshold_tbc21) ||
                                                             (xr_vcos_measure > threshold_tbc22) ||
                                                             (xr_measure      < threshold_tbc23) ||
                                                             (xr_measure      > threshold_tbc24);
      xr_fault_word.u_bit.s_internal_failure               = (xr_vsin_gnd_avg < threshold_tbc1) || (xr_vsin_gnd_avg > threshold_tbc2) ||
                                                             (xr_vsin_ref_avg < threshold_tbc3) || (xr_vsin_ref_avg > threshold_tbc4) ||
                                                             (xr_vcos_gnd_avg < threshold_tbc5) || (xr_vcos_gnd_avg > threshold_tbc6) ||
                                                             (xr_vcos_ref_avg < threshold_tbc7) || (xr_vcos_ref_avg > threshold_tbc8);
      xr_fault_word.u_bit.s_unavailable                    = 0;
      xr_fault_word.u_bit.s_invalid                        = 0;
      if(xr_fault_word.u_word != 0)
      {
         xr_fault_word.u_bit.s_invalid                     = 1;
      }
   }
}

/* ---------- internal operations: ------------------------------------------ */
