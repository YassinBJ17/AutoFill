/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Acquire tmot samples from internal ADC (SARADC_B)
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "type/mcp_types.h"
#include "driver/adc/ADC_HAL_public.h"
#include "middleware/tmot/tmot_private.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------- */
/* Implements REQ_FADEX_OS_SRD-TMOT-0010 */
/* Acquire tmot current and voltage from internal ADC (SARADC_B) */
void tmot_acquire_samples(float32_t* p_tmot_computed_volt,    /* out */
                          float32_t* p_tmot_computed_current) /* out */
{

   uint16_t tmot_voltage;            /* Tmot voltage */
   uint16_t tmot_current;            /* Tmot current */
   uint16_t ref_2v5;                 /* REF_2V5 */
   float32_t cal_gain;               /* Calibration gain for the tmot current */
   float32_t tmot_current_raw_sum;   /* Tmot current raw sum */
   float32_t tmot_current_raw_avg;   /* Tmot current raw samples average */
   float32_t tmot_cal_mon_current;   /* Tmot calibrated monitoring curent */
   uint32_t i;                       /* Iterator for loop */

   /* Initialize the local variables */
   tmot_cal_mon_current = 0;
   tmot_current_raw_sum = 0;

   /* Acquire REF_2V5 on the line AN8 of the internal ADC (SARADC_B) */
   ADC_BUFFER_READ ((uint32_t)e_CFEX_ADC_INT_AN8, &ref_2v5);

   /* Acquire tmot voltage on the line AN47 of the internal ADC (SARADC_B) */
   ADC_BUFFER_READ ((uint32_t)e_CFEX_ADC_INT_AN47, &tmot_voltage);

   for(i = (uint32_t)0; i < TMOT_CURRENT_NB_SAMPLES; i++)
   {
   /* Acquire tmot current on the line AN50 of the internal ADC (SARADC_B) */
   ADC_BUFFER_READ (e_CFEX_ADC_INT_AN50, &tmot_current);

      /* Compute the sum of the tmot current raw samples */
      tmot_current_raw_sum += (float32_t)tmot_current;
   }

   /* Compute the tmot current raw samples average */
   tmot_current_raw_avg = tmot_current_raw_sum/(float32_t)TMOT_CURRENT_NB_SAMPLES;

   /* Compute the calibration gain */
   cal_gain = (float32_t)(EXPECTED_REF_2V5/((float32_t)ref_2v5 * ADC_CONVERT_VALUE));

   /* Convert the tmot voltage to analog value */
   *p_tmot_computed_volt = (float32_t)((tmot_voltage-SARADC_GND_OFFSET) * ADC_CONVERT_VALUE/GAIN_TMOT_VOLT);

   /* Compute the tmot calibrated monitoring current */
   tmot_cal_mon_current = tmot_current_raw_avg * cal_gain;

   /* Convert the tmot calibrated current to analog value */
   *p_tmot_computed_current = (float32_t)(((tmot_cal_mon_current-SARADC_GND_OFFSET) * ADC_CONVERT_VALUE/CONV_VOLT_TO_CURRENT)*1000);

}

/* ---------- internal operations: ------------------------------------------ */
