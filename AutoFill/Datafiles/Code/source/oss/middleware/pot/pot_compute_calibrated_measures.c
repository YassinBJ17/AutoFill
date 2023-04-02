/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : The OSS_PU shall at each RTC performs the following checks
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/pot/pot_private.h"

/* ---------- include required interface: ----------------------------------- */

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */

/* Implements REQ_FADEX_OS_SRD-POT-0010 */
/* Implements REQ_FADEX_OS_SRD-POT-0020 */
/**
 * Compute the Excitation and Signal measures,
 *   according to the Reference and Ground signals,
 *   multiplying by the appropriate gain. */
void pot_compute_calibrated_measures(ts_pot_measures * const s_measure)
{
   float32_t numerator_sig;
   float32_t numerator_exc;
   float32_t denominator;

   /*   LOW-SIDE SIGNAL   */

   /** Convert and Calibrate Low side currents,
    *    according to the already calculated constant. */
   s_measure->v_low_side *= POT_LOW_SIDE_VOLTAGE_TO_CURRENT;


   /*   MAIN SIGNAL   */

   denominator = s_measure->v_ref - s_measure->v_gnd;
   /* Avoid any division by Zero */
   if (0.0f == denominator)
   {
      /** Return a measured voltage of 20.0 V,
       *    which will be handled as an erroneous measure and discarded.
       *  In any case, the internal_fail flag will be set in the fault word.*/
      s_measure->v_measure = 20.0f;
      s_measure->v_exc     = 20.0f;
      return;
   }

   /* Write the calibrated value for the Signal. */
   numerator_sig = s_measure->v_signal - s_measure->v_gnd;
   s_measure->v_signal = POT_REF * numerator_sig / denominator;


   /*   EXCITATION SIGNAL & MAIN MEASURE   */

   /** Write the calibrated value for the Excitation,
    *    only if the sensor is NOT in differential type. */
   if ( ! s_measure->is_sensor_type_diff)
   {
      numerator_exc = (s_measure->v_exc * POT_EXC_CONST)  - s_measure->v_gnd;
      s_measure->v_exc = POT_REF * numerator_exc / denominator;
      /* Normalize the signal by the Excitation value. */
      s_measure->v_measure = s_measure->v_signal / s_measure->v_exc;
   }
   else
   {
      /** Clear the Excitation value,
       *   since it has no meaning in DIFFERENTIAL mode. */
      s_measure->v_exc = 0.0f;
      /* The signal doesn't need a normalization. */
      s_measure->v_measure = s_measure->v_signal;
   }
}

/* ---------- internal operations: ------------------------------------------ */
