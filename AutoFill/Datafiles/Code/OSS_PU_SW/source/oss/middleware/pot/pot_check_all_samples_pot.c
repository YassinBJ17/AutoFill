/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : The OSS_PU shall at each RTC performs the following checks
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/pot/pot_private.h"
#include "memory/shared_memory_public.h"

/* ---------- include required interface: ----------------------------------- */

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */

/* ---------- internal operations: ------------------------------------------ */

/* Implements REQ_FADEX_OS_SRD-POT-0010 */
/* Implements REQ_FADEX_OS_SRD-POT-0020 */
/**
 * Perform range checks on the acquired POTENTIOMETERS signals.
 */
tu_pot_fault_word pot_check_all_samples_pot(
                                         const ts_pot_measures * const measures)
{
   tu_pot_fault_word fault_word;
   boolean_t gnd_fault;
   boolean_t ref_fault;

   fault_word.u_word = 0u;

   /* Range checks on Ground and Ref signals */
   gnd_fault =    measures->v_gnd < POT_GROUND_EXPECTED_RANGE_MIN * POT_DIVIDER_BRIDGE
               || measures->v_gnd > POT_GROUND_EXPECTED_RANGE_MAX * POT_DIVIDER_BRIDGE;
   ref_fault =    measures->v_ref < POT_REF_EXPECTED_RANGE_MIN
               || measures->v_ref > POT_REF_EXPECTED_RANGE_MAX;
   if (gnd_fault || ref_fault)
   {
      fault_word.u_bit.s_internal_failure    = 1;
   }

   /* Range check on main Signal */
   if (measures->v_signal < POT_SIGNAL_EXPECTED_RANGE_MIN)
   {
      fault_word.u_bit.s_meas_oc_fault       = 1;
      fault_word.u_bit.s_meas_short_diff     = 1;
   }
   else if (measures->v_signal > POT_SIGNAL_EXPECTED_RANGE_MAX)
   {
      fault_word.u_bit.s_exc_short_to_signal = 1;
   }

   /* Range check on Excitation signal */
   if (   measures->v_exc < POT_EXC_EXPECTED_RANGE_MIN
       || measures->v_exc > POT_EXC_EXPECTED_RANGE_MAX)
   {
      fault_word.u_bit.s_exc_out_of_range    = 1;
   }

   /* Range check on Low-side signal */
   if      (measures->v_low_side < POT_LOW_SIDE_EXPECTED_RANGE_MIN){
      fault_word.u_bit.s_exc_oc_fault        = 1;
      fault_word.u_bit.s_exc_short_gnd       = 1;
      fault_word.u_bit.s_meas_short_gnd      = 1;
   }
   else if (measures->v_low_side > POT_LOW_SIDE_EXPECTED_RANGE_MAX)
   {
      fault_word.u_bit.s_exc_short_diff      = 1;
   }

   /* Range check on final Measure */
   if (   measures->v_measure < POT_MEASURE_EXPECTED_FRACTION_RANGE_MIN
       || measures->v_measure > POT_MEASURE_EXPECTED_FRACTION_RANGE_MAX)
   {
      fault_word.u_bit.s_out_of_range        = 1;
   }

   /* Turn on the INVALID flag if at least 1 error has been detected. */
   if (0 != fault_word.u_word)
   {
      fault_word.u_bit.s_invalid = 1;
   }
   return fault_word;
}
