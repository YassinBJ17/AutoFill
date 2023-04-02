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

/* Implements REQ_FADEX_OS_SRD-CALRES-0020 */
/* Implements REQ_FADEX_OS_SRD-CALRES-0030 */
/**
 * Function to perform relevant checks on all signals range :
 *   - If a signal is out of range, its last valid value is kept,
 *      and the fault word is written accordingly;
 *   - Otherwise, the signal is updated in shared memory.
 */
void calres_checks_handler(tu_calres_fault_word* const p_calres_fault_word,
                           const boolean_t             current_channel_is_a,
                           float32_t * const           p_calres_2_4_value,
                           ts_calres_measures * const  p_calres_measures_2_4,
                           float32_t * const           p_calres_1_3_value,
                           ts_calres_measures * const  p_calres_measures_1_3)
{
   tu_calres_fault_word fault_word_2_4;
   tu_calres_fault_word fault_word_1_3;
   boolean_t oc_fault_2_4;
   boolean_t oc_fault_1_3;


   /*  CALRES PIB's 50 Ohm COMPENSATION  */

   /**
    * On the channel B, the Calres measures are overestimated by approx. 50 Ohm,
    *   which corresponds to the image of the PIB impedance.
    * Because they have some circuit nodes in common, this impedance has been
    *   proven to be "seen" twice by the measure when two sensors are connected;
    *   thus we have to take in account open-circuit faults.
    */
   if ( ! current_channel_is_a)
   {
      /* Tests before compensation */
      oc_fault_2_4 = calres_check_before_compensation(p_calres_measures_2_4);
      oc_fault_1_3 = calres_check_before_compensation(p_calres_measures_1_3);

      /* If no OC fault is to deplore
       *   (ie. if no voltage is over 2.2V, that being approx. 12.3 kOhm),
       *   both measures can be compensated by approx. 2*50 Ohm (= 0.100 kOhm).*/
      if ( ! (oc_fault_2_4 || oc_fault_1_3))
      {
         p_calres_measures_2_4->r_measure -= 2.0f * CALRES_PIB_COMPENSATION;
         p_calres_measures_1_3->r_measure -= 2.0f * CALRES_PIB_COMPENSATION;
      }
      /* if one OC fault is detected,
       *   only the other sensor is compensated by 50 Ohm. */
      else if (   oc_fault_2_4  && !(oc_fault_1_3))
      {
         p_calres_measures_1_3->r_measure -= CALRES_PIB_COMPENSATION;

      }
      /* if one OC fault is detected,
       *   only the other sensor is compensated by 50 Ohm. */
      else if ( !(oc_fault_2_4) &&   oc_fault_1_3 )
      {
         p_calres_measures_2_4->r_measure -= CALRES_PIB_COMPENSATION;
      }
      /* If OC faults are detected on both sensors,
       *   no compensation is applied. */
   }


   /*     ACTUAL CHECKS    */

   /* Test all signals' range. */
   fault_word_2_4 = calres_check_all_samples(p_calres_measures_2_4);
   fault_word_1_3 = calres_check_all_samples(p_calres_measures_1_3);


   /*       RESULTS       */

   /** If all signals are in range,
     *  write and return both measures, without error */
   /** TODO The following commented lines of code are to be uncommented when
     *  the "overdrive" (keeping the last correct value) is needed again.
     *  But for now, we "return" the measures whatever their value is. */
   /*if (0 == s_fault_word_2_4.u_word)*/
   /*{*/
      *p_calres_2_4_value = p_calres_measures_2_4->r_measure;
   /*}*/
   /*if (0 == s_fault_word_1_3.u_word)*/
   /*{*/
      *p_calres_1_3_value = p_calres_measures_1_3->r_measure;
   /*}*/

   /** The measure, or one of its signals, is out of range :
     *  Don't write any erroneous measure, keep the old (correct) one untouched,
     *  and return the merged fault word. */
   if (0 != (fault_word_2_4.u_word | fault_word_1_3.u_word))
   {
      *p_calres_fault_word = calres_merge_fault_words(&fault_word_2_4,
                                                      &fault_word_1_3);
      /* TODO log in the generic event block */
   }
   else /* If there is no error, write 0 in the shared_memory's fault word. */
   {
      p_calres_fault_word->u_word = 0;
   }
}


/* ---------- internal operations: ------------------------------------------ */
