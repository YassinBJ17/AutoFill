/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : The OSS_PU shall at each RTC performs the following checks
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/calres/calres_public.h"
#include "middleware/calres/calres_private.h"
#include "driver/adc_over_spi/adc_over_spi_public.h"

/* ---------- include required interface: ----------------------------------- */

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* CALRES calibrated voltages */
float32_t calres_signal_1_3;
float32_t calres_signal_2_4;

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */

/* Implements REQ_FADEX_OS_SRD-CALRES-0020 */
/* Implements REQ_FADEX_OS_SRD-CALRES-0030 */
/**
 * Function to orchestrate the signals' measurement, calculations and checks.
 */
void calres_periodic(const boolean_t current_channel_is_a)
{
   ts_calres_measures s_calres_measures_2_4; /* Measures for Calres_2 or 4 */
   ts_calres_measures s_calres_measures_1_3; /* Measures for Calres_1 or 3 */

   /* If XRB is activated, calres is disabled. */
   if ( ! is_calres_sensor_enabled)
   {
      return;
   }

   /*   ACQUISITIONS   */

   /** Acquisition of the main signals has been done by the ADC1 and ADC2, over SPI;
    *   the functions in charge of the measures are adc_over_spi_retrieve_acquired_voltages()
    *   and adc_over_spi_program_voltages_acquisitions(). */
   /* Signals for Calres_2 (channel A) or Calres_4 (channel B) */
   s_calres_measures_2_4.v_signal = calres_compute_mean_float(calres_signal_2_4_raw);
   s_calres_measures_2_4.v_ref    = calres_compute_mean_float(calres_ref_2_4_raw);
   s_calres_measures_2_4.v_gnd    = calres_compute_mean_float(calres_gnd_2_4_raw);
   /* Signals for Calres_1 (channel A) or Calres_3 (channel B) */
   s_calres_measures_1_3.v_signal = calres_compute_mean_float(calres_signal_1_3_raw);
   s_calres_measures_1_3.v_ref    = calres_compute_mean_float(calres_ref_1_3_raw);
   s_calres_measures_1_3.v_gnd    = calres_compute_mean_float(calres_gnd_1_3_raw);

   /*   COMPUTATIONS   */

   /** Calibrate the measured voltages, according to the Reference and Ground
     *  already measured ; then convert them into Resistance values (in Ohm). */
   calres_compute_calibrated_resistance(&s_calres_measures_2_4);
   calres_compute_calibrated_resistance(&s_calres_measures_1_3);

   /*      CHECKS      */

   /** For Calres_2_4 and Calres_1_3 :
     * Compute, check and write either a fault word or the measures,
     *  in the register corresponding to either Calres_2_4 or Calres_1_3. */
   calres_checks_handler(p_calres_fault_word, current_channel_is_a,
                         p_calres_2_4_value,  &s_calres_measures_2_4,
                         p_calres_1_3_value,  &s_calres_measures_1_3);

   calres_signal_1_3 = s_calres_measures_1_3.v_signal;
   calres_signal_2_4 = s_calres_measures_2_4.v_signal;
}

/* ---------- internal operations: ------------------------------------------ */
