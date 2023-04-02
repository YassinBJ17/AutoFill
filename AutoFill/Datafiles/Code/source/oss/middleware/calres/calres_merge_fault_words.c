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
 * Function to merge two fault words' data, into their respective place.
 */
tu_calres_fault_word calres_merge_fault_words(
                             const tu_calres_fault_word* const p_fault_word_2_4,
                             const tu_calres_fault_word* const p_fault_word_1_3)
{
   tu_calres_fault_word s_merged;
   /* Merge the data common to both fault words. */
   s_merged.u_word = p_fault_word_2_4->u_word | p_fault_word_1_3->u_word;

   /* Take the data specific to p_fault_word_1_3, already at the correct place. */
   s_merged.u_bit.s_meas1_oc_fault     = p_fault_word_1_3->u_bit.s_meas1_oc_fault;
   s_merged.u_bit.s_meas1_out_of_range = p_fault_word_1_3->u_bit.s_meas1_out_of_range;
   s_merged.u_bit.s_meas1_short_gnd    = p_fault_word_1_3->u_bit.s_meas1_short_gnd;

   /* Take the data specific to p_fault_word_2_4, and put it at the correct place. */
   s_merged.u_bit.s_meas2_oc_fault     = p_fault_word_2_4->u_bit.s_meas1_oc_fault;
   s_merged.u_bit.s_meas2_out_of_range = p_fault_word_2_4->u_bit.s_meas1_out_of_range;
   s_merged.u_bit.s_meas2_short_gnd    = p_fault_word_2_4->u_bit.s_meas1_short_gnd;

   return s_merged;
}


/* ---------- internal operations: ------------------------------------------ */
