/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : tmot periodic function (CBIT)
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "memory/lib_critical_service_section_def_data.h"
#include "middleware/tmot/tmot_public.h"
#include "middleware/tmot/tmot_private.h"
#include "middleware/tmot/tmot_fpga_reg_common.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-TMOT-0010 */
/* tmot periodic function (CBIT) */
void tmot_periodic(const boolean_t channel_is_a)
{
   /* Tmot acquired high side voltage from SARADC_B */
   float32_t tmot_acquired_hs_voltage_feedback;

   /* Tmot acquired low side current from SARADC_B */
   float32_t tmot_acquired_ls_current_feedback;

   /* Tmot shmem pointer */
   ts_tmot_r * shmem_tmot = channel_is_a ? &(shmem.s_tmot_r_a) : &(shmem.s_tmot_r_b);

   /* Acquire the tmot data feedback */
   tmot_acquire_samples(&tmot_acquired_hs_voltage_feedback, &tmot_acquired_ls_current_feedback);

   /* Initialize the fault word to no fault */
   shmem_tmot->s_fault_word.u_word = (uint32_t)0;

   /* If the tmot computed low side current feedback is out of range */
   if (tmot_acquired_ls_current_feedback < TMOT_CURRENT_MIN || tmot_acquired_ls_current_feedback > TMOT_CURRENT_MAX)
   {
      /* Indicate the current feedback is out of range to the CSS_PU */
      shmem_tmot->s_fault_word.u_bit.s_out_of_range_current = (uint32_t)1;

      /* Indicate one of the feedback data is out of range */
      shmem_tmot->s_fault_word.u_bit.s_out_of_range_final = (uint32_t)1;
   }

   /* If the tmot computed high side voltage feedback is out of range */
   if (tmot_acquired_hs_voltage_feedback < TMOT_VOLTAGE_MIN || tmot_acquired_hs_voltage_feedback > TMOT_VOLTAGE_MAX)
   {
      /* Indicate the voltage feedback is out of range to the CSS_PU */
      shmem_tmot->s_fault_word.u_bit.s_out_of_range_voltage = (uint32_t)1;

      /* Indicate one of the feedback data is out of range */
      shmem_tmot->s_fault_word.u_bit.s_out_of_range_final = (uint32_t)1;
   }

   /* If at least one fault is detected */
   if ((uint32_t)0 != shmem_tmot->s_fault_word.u_word)
   {
      /* Indicate at least one fault is detected to the CSS_PU */
      shmem_tmot->s_fault_word.u_bit.s_invalid = (uint32_t)1;
   }

   /* If the tmot current feedback is in the expected range */
   if ((uint32_t)0 == shmem_tmot->s_fault_word.u_bit.s_out_of_range_current)
   {
      /* Transmit the current feedback to the CSS_PU */
      shmem_tmot->s_current = tmot_acquired_ls_current_feedback;
   }

   /* Transmit the voltage feedback to the CSS_PU (Whatever the fault) */
   shmem_tmot->s_voltage = tmot_acquired_hs_voltage_feedback;
}

/* ---------- internal operations: ------------------------------------------ */
