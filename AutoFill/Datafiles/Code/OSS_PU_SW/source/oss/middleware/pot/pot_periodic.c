/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : The OSS_PU shall at each RTC performs the following checks
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/pot/pot_public.h"
#include "middleware/pot/pot_private.h"
#include "driver/adc_over_spi/adc_over_spi_public.h"

/* ---------- include required interface: ----------------------------------- */

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* Signals to be measured */
ts_pot_measures s_measures_1_2;
ts_pot_measures s_measures_3;

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */

/* Implements REQ_FADEX_OS_SRD-POT-0010 */
/* Implements REQ_FADEX_OS_SRD-POT-0020 */
/* Implements REQ_FADEX_OS_SRD-POT-0030 */
/**
 *   This function orchestrates signals' measurement, calculations and checks.
 */
void pot_periodic(const boolean_t current_channel_is_a)
{
   boolean_t current_channel_is_b =  !(current_channel_is_a);

   /* Initialize signals to be measured */
   s_measures_1_2.v_signal = 0;
   s_measures_1_2.v_measure = 0;
   s_measures_1_2.v_ref = 0;
   s_measures_1_2.v_gnd = 0;
   s_measures_1_2.v_exc = 0;
   s_measures_1_2.v_low_side = 0;
   s_measures_1_2.is_sensor_type_diff = 0;

   s_measures_3.v_signal = 0;
   s_measures_3.v_measure = 0;
   s_measures_3.v_ref = 0;
   s_measures_3.v_gnd = 0;
   s_measures_3.v_exc = 0;
   s_measures_3.v_low_side = 0;
   s_measures_3.is_sensor_type_diff = 0;

   /*   ACQUISITIONS   */

   /** Acquisition of main signals has been done by the ADC3, over SPI;
     *  the functions in charge of the measure are adc_over_spi_retrieve_acquired_voltages()
     *  and adc_over_spi_program_voltages_acquisitions() */

   /*  For Pot_1 or Pot_2 */
   s_measures_1_2.v_signal    = pot_compute_mean_float(pot_signal_1_2_raw);
   s_measures_1_2.v_exc       = pot_compute_mean_float(pot_exc_1_2_raw);
   s_measures_1_2.v_gnd       = pot_compute_mean_float(pot_gnd_raw);
   s_measures_1_2.v_ref       = pot_compute_mean_float(pot_ref_raw);
   s_measures_1_2.is_sensor_type_diff = is_sensor_type_diff;

   /* For Pot_3 */
   if (current_channel_is_b)
   {
      s_measures_3.v_signal   = pot_compute_mean_float(pot_signal_3_raw);
      s_measures_3.v_exc      = pot_compute_mean_float(pot_exc_3_raw);
      s_measures_3.v_gnd      = s_measures_1_2.v_gnd; /* GND is common */
      s_measures_3.v_ref      = s_measures_1_2.v_ref; /* REF is common */
      /* Pot_3's type never changes */
      s_measures_3.is_sensor_type_diff = POT_K_POTENTIOMETER;
   }

   /* Acquisition of low-side signals
    *  (those acquisitions are done even if no sensor is connected, in order to
    *   keep simple the measurement of the worst execution time). */

   /** For Pot_1 and Pot_2 (resp. on channel A or B), the low-side measure
     * matters only if the sensor is **NOT** of Differential type. */
      /* Do the acquisitions on pin 78 for Pot_1 or Pot_2 */
   s_measures_1_2.v_low_side = pot_acquire_low_side_1_2_measure(); /* pot_acquire_low_side_x_measure(e_CFEX_ADC_INT_AN78); */
   /** For Pot_3 (on channel B only),
     * get also the low-side measure, on the pin 79. */
   s_measures_3.v_low_side   = pot_acquire_low_side_3_measure(); /* pot_acquire_low_side_x_measure(e_CFEX_ADC_INT_AN79); */



   /*   SIGNALS CALIBRATION   */

   /* For Pot_1 or Pot_2 */

   /** Calibrate the Excitation, Low-side and Signal measures,
     *   according to the Reference and Ground voltages already measured. */
   pot_compute_calibrated_measures(&s_measures_1_2);

   /* For Pot_3 */
   if (current_channel_is_b)
   {
      /** Calibrate the Excitation, Low-side and Signal measures,
        *  according to the Reference and Ground voltages already measured. */
      pot_compute_calibrated_measures(&s_measures_3);
   }


   /*      SIGNALS CHECKS      */

   /** For Pot_1 or Pot_2 :
     * Compute, check and write either a fault word or the measure,
     *  in the register corresponding to either Pot_1 or Pot_2,
     *  accordingly to the type of sensor (DIF or POT) */
   pot_checks_handler(p_1_2_register, &s_measures_1_2);

   /* For Pot_3: */
   if (current_channel_is_b)
   {
      /** Compute, check and write either a fault word or the measure,
        *  in the register corresponding to Pot_3. */
      pot_checks_handler(p_3_register, &s_measures_3);
   }
}

/* ---------- internal operations: ------------------------------------------ */
