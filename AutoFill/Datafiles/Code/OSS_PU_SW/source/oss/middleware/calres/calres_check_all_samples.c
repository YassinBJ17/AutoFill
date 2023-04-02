/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : The OSS_PU shall at each RTC performs the following checks
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/calres/calres_private.h"
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

/* Implements REQ_FADEX_OS_SRD-CALRES-0020 */
/* Implements REQ_FADEX_OS_SRD-CALRES-0030 */
/**
 * Perform range checks on the acquired Calres signals.
 */
tu_calres_fault_word calres_check_all_samples(
                                    const ts_calres_measures * const s_measures)
{
/*   boolean_t is_gnd_faulty;*/
/*   boolean_t is_ref_faulty;*/
   tu_calres_fault_word s_fault_word;
   s_fault_word.u_word = 0u;

   /* Range check on Ground and Ref values */
/*   is_gnd_faulty =    CALRES_EXPECTED_GROUND_RANGE_MIN >= s_measures->v_gnd*/
/*                   || CALRES_EXPECTED_GROUND_RANGE_MAX <= s_measures->v_gnd;*/
/*   is_ref_faulty =    CALRES_EXPECTED_REF_RANGE_MIN >= s_measures->v_ref*/
/*                   || CALRES_EXPECTED_REF_RANGE_MAX <= s_measures->v_ref;*/
/*   if (is_gnd_faulty || is_ref_faulty)*/
/*   {*/
/*      s_fault_word.u_bit.s_int_failure        = 1;*/
/*   }*/

   /* Range check on the Voltage value */
   if      (CALRES_EXPECTED_VOLTAGE_RANGE_MIN >= s_measures->v_signal)
   {
      s_fault_word.u_bit.s_meas1_short_gnd    = 1;
   }
   else if (CALRES_EXPECTED_VOLTAGE_RANGE_MAX <= s_measures->v_signal)
   {
      s_fault_word.u_bit.s_meas1_oc_fault     = 1;
   }

   /* Range checks on the Resistance value (final measure) */
   if (    (CALRES_EXPECTED_RESIST_RANGE_MIN >= s_measures->r_measure)
        || (CALRES_EXPECTED_RESIST_RANGE_MAX <= s_measures->r_measure))
   {
      s_fault_word.u_bit.s_meas1_out_of_range = 1;
      s_fault_word.u_bit.s_out_of_range       = 1;
   }

   /* Turn on the INVALID flag if at least 1 error has been detected. */
   if (0u != s_fault_word.u_word)
   {
      s_fault_word.u_bit.s_invalid = 1;
   }
   return s_fault_word;
}
