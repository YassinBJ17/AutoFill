/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Acquisition of the control processing core die temperature (tcu2)
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "middleware/tecu/tecu_private.h"
#include "middleware/tecu/tecu_public.h"
#include "driver/adc/ADC_HAL_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* Temperature sensor output sampled by the SARADC_B */
uint16_t   tcu2_raw_temperature;
/* bandgap reference voltage sampled by the SARADC_B */
uint16_t tcu2_vbg_data;

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------- */
/* Implements REQ_FADEX_OS_SRD-TECU_0001 */
/*  Acquisition of the control processing core die temperature (tcu2) */
void tecu_acq_tcu2(void)
{
   /* Local variables */
   uint16_t      local_tsens_data;
   uint16_t    local_vbg_data;

   /* Read vbg_data (bandgap reference voltage sampled by the SARADC_B) */
   ADC_BUFFER_READ((CMN_IOSP_ID_t)e_CFEX_ADC_INT_AN121, &local_vbg_data);

   /* Read tsens_data (temperature sensor output sampled by the SARADC_B) */
   ADC_BUFFER_READ((CMN_IOSP_ID_t)e_CFEX_ADC_INT_AN120, &local_tsens_data);

   /**** FOR IVV TEST ****/
   /* Set global vbg_data to the value of the local_vbg_data */
   tcu2_vbg_data = local_vbg_data;
   /* Set global tsens_data to the value of the local_tsens_data */
   tcu2_raw_temperature = local_tsens_data;
   /**********************/

   /* Compute temperature in Celsius */
   tcu2  = (232 + (TECU_tcsa * 0.015625)) * ((float32_t)local_tsens_data / (float32_t)local_vbg_data) - (273 + (TECU_tcsb * 0.0625));

}

/* ---------- internal operations: ------------------------------------------ */
