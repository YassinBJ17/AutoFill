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
#include "middleware/smot/smot_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */
/* Conversion from voltage to current */
#define CONV_VOLT_TO_CURRENT (float32_t)(2.0/4.688)

/* Gain to apply for obtain tmot computed voltage */
#define GAIN_SMOT_VOLT (float32_t)(0.048)

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------- */
/* Implements REQ_FADEX_OS_SRD-TMOT-0010 */
/* Acquire tmot current and voltage from internal ADC (SARADC_B) */
void smot_acquire_samples(float32_t* p_smot_computed_volt,    /* out */
                          float32_t* p_smot_computed_current) /* out */
{
   /* Tmot voltage */
   uint16_t smot_voltage;

   /* Tmot current */
   uint16_t smot_current;

   /* Acquire tmot voltage on the line AN65 of the internal ADC (SARADC_B) */
   ADC_BUFFER_READ ((uint32_t)e_CFEX_ADC_INT_AN65, &smot_voltage);

   /* Acquire tmot current on the line AN64 of the internal ADC (SARADC_B) */
   ADC_BUFFER_READ (e_CFEX_ADC_INT_AN64, &smot_current);

   /* Convert the tmot voltage to analog value */
   *p_smot_computed_volt = (float32_t)(smot_voltage * ADC_CONVERT_VALUE/GAIN_SMOT_VOLT);

   /* Convert the tmot current to analog value */
   *p_smot_computed_current = (float32_t)(smot_current * ADC_CONVERT_VALUE * CONV_VOLT_TO_CURRENT);
}

/* ---------- internal operations: ------------------------------------------ */
