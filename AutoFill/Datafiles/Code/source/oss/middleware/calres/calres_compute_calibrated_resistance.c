/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : The OSS_PU shall at each RTC performs the following checks
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/calres/calres_private.h"

/* ---------- include required interface: ----------------------------------- */

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */

/* Implements REQ_FADEX_OS_SRD-CALRES-0020 */
/* Implements REQ_FADEX_OS_SRD-CALRES-0030 */
/** Function to calibrate the measured voltage, using the GND and REF values ;
 *  then convert it into a resistance value,
 *    using the already calculated constants.
 */
void calres_compute_calibrated_resistance(ts_calres_measures * const p_measures)
{
   float32_t v_voltage;
   float32_t v_numerator;
   float32_t v_denominator;

   /* Part 1 - VOLTAGE CALIBRATION */
   /* Compute the measure according to the ref and ground signals. */

   v_denominator = p_measures->v_ref -  p_measures->v_gnd;
   /* Avoid any division by Zero */
   if (0.0f == v_denominator)
   {
      /** Return a measured voltage of 20.0 V,
       *    and a resistance of 1 MegaOhm (1e3 kOhm),
       *    which will be handled as erroneous measures and discarded.
       *  In any case, the internal_fail flag will be set in the fault word.*/
      p_measures->v_signal  =  20.0f;
      p_measures->r_measure = 1.0E3f;
   }
   v_numerator = p_measures->v_signal - p_measures->v_gnd;
   /* From now on, the v_voltage is calibrated. */
   v_voltage   = CALRES_REF * v_numerator / v_denominator ;
   p_measures->v_signal = v_voltage;


   /* Part 2 - RESISTANCE */
   /* Compute the resistance using the already calculated constants. */

   v_denominator = CALRES_A2 - CALRES_A3 * v_voltage;
   /* Avoid any division by Zero */
   if (0.0f == v_denominator)
   {
      /** Return a resistance of 1 MegaOhm (1e3 kOhm),
       *    which will be handled as an erroneous measure and discarded.
       *  Other error flags will be set in the fault word. */
      p_measures->r_measure = 1.0E3f;
   }
   v_numerator =  CALRES_A1 * v_voltage;

   /** From now on, the resistance value is available,
    *    and is expressed in kOhm. */
   p_measures->r_measure = CALRES_OHM_TO_KOHM * v_numerator / v_denominator ;
}

/* ---------- internal operations: ------------------------------------------ */
