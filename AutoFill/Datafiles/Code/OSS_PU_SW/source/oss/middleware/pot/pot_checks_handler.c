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

/* Implements REQ_FADEX_OS_SRD-POT-0010 */
/* Implements REQ_FADEX_OS_SRD-POT-0020 */
/* Implements REQ_FADEX_OS_SRD-POT-0030 */
/**
 * Function to perform relevant checks on all signals range :
 *   - If a signal is out of range, its last valid value is kept,
 *      and the fault word is written accordingly;
 *   - Otherwise, the signal is updated in shared memory.
 */
void pot_checks_handler(ts_pot* const p_pot_register,
                        const ts_pot_measures * const measures)
{
   tu_pot_fault_word fault_word;
   tu_potdiff_fault_word fault_word_diff;

   /*       TESTS       */

   /* Test all signal ranges, according to the sensor type */
   if (POT_K_DIFFERENTIAL == measures->is_sensor_type_diff)
   {
      fault_word_diff = pot_check_all_samples_diff(measures);
      /** This "cast" is safe : the type tu_potdiff_fault_word has strictly
        *    the same size as tu_pot_fault_word. */
      fault_word.u_word = fault_word_diff.u_word;
   }
   else /* POT_K_POTENTIOMETER == measures->is_sensor_type_diff */
   {
      fault_word = pot_check_all_samples_pot(measures);
   }

   /*       RESULTS       */
   /** TODO The following commented lines of code are to be uncommented when
     *  the "overdrive" (keeping the last correct value) is needed again ;
     *  and the last 'if' condition is also temporary and to be removed.
     * But for now, we "return" the measures, whatever their value is. */
   /*if (0 == fault_word.u_word)*/
   /*{*/
      /** All signals are in range :
        *  Write and return the measure, without error */
      p_pot_register->s_measure = measures->v_measure;
      p_pot_register->s_fault_word.u_word = (uint32_t) 0u;
   /*}*/
        /** The measure, or one of its signals, is out of range :
          *  Don't write the measure, keep the old one untouched,
          *  and return the fault word. */
   /* TODO ALSO DELETE THE FOLLOWING CONDITION, keeping it as an "else" block.*/
   if (0 != fault_word.u_word)
   /*else*/
   {
      p_pot_register->s_fault_word.u_word = fault_word.u_word;
      /* TODO log in the generic event block */
   }
}


/* ---------- internal operations: ------------------------------------------ */
