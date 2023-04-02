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
/* Implements REQ_FADEX_OS_SRD-POT-0030 */
/**
 * Perform range checks on the acquired DIFFERENTIAL pot signals.
 */
tu_potdiff_fault_word pot_check_all_samples_diff(
                                         const ts_pot_measures * const measures)
{
   tu_potdiff_fault_word fault_word;
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
   if (measures->v_signal < POT_DIFF_OPEN_CIRCUIT)
   {
      fault_word.u_bit.s_meas_oc_fault       = 1;
   }

   /* Range check on final Measure */
   if (   measures->v_measure < POT_DIFF_MEASURE_EXPECTED_RANGE_MIN
       || measures->v_measure > POT_DIFF_MEASURE_EXPECTED_RANGE_MAX)
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
