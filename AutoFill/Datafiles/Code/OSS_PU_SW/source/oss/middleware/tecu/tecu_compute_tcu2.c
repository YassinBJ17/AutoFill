/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Compute control processing core die temperature filter function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "middleware/tecu/tecu_public.h"
#include "middleware/rtc/rtc_public.h"
#include "memory/lib_critical_service_section_def_data.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* Control processing core die temperature filtered temperature */
float32_t filt_tcu2;

/* Previous control processing core die temperature filtered temperature */
float32_t prev_filt_tcu2;

/* The completion of the control processing core die temperature filtering computation indication */
boolean_t tcu2_filt_completed;

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------- */
/* Implements REQ_FADEX_OS_SRD-TECU-0010 */
/* Compute control processing core die temperature filter function */
void tecu_compute_tcu2(const boolean_t channel_is_a)
{

   ts_tecu* shmem_tecu;         /* Pointer to the TECU status of the actual channel */
   ts_tecu* prev_shmem_tecu;    /* Pointer to the TECU status of the previous RTC */


   /* If channel A */
   if(channel_is_a)
   {
      /* The TECU status of the channel A is affected to the status of the actual channel */
      shmem_tecu = &(shmem.s_tecua);

      /* The previous TECU status of channel A is affected to the previous TECu status fo the actual channel */
      prev_shmem_tecu = &(prev_tecua_status);

   }
   /* If channel B */
   else
   {
      /* The TECU status of the channel B is affected to the status of the actual channel */
      shmem_tecu = &(shmem.s_tecub);

      /* The previous TECU status of channel B is affected to the previous TECu status fo the actual channel */
      prev_shmem_tecu = &(prev_tecub_status);
   }

   /* If the previous control processing core die temperature was out of range or inconsistent or is the first RTC */
   if((uint32_t)1 == prev_shmem_tecu->s_fault_word.u_bit.s_err_tcu2 || (uint32_t)1 == rtc_counter)
   {
      /* Store the instantaneous control processing core die temperature to the previous filtered control processing core die temperature */
      prev_filt_tcu2 = tcu2;
   }

   /* If the control processing core die temperature is in the expected range and consistent */
   if((uint32_t)0 == shmem_tecu->s_fault_word.u_bit.s_err_tcu2)
   {
      /* Compute the control processing core die filtered temperature */
      filt_tcu2 = TCU2_FILTER_COEFF * prev_filt_tcu2 + ((1 - TCU2_FILTER_COEFF) * tcu2);

      /* Set the previous control processing core die filtered temperature to the current control processing core die filtered temp */
      prev_filt_tcu2 = filt_tcu2;

      /* Indicate the computation of the control processing core die filtered temperature has been completed */
      tcu2_filt_completed = (uint32_t)1;
   }
   else
   {
      /* Indicate the computation of the control processing core die filtered temperature has not been completed */
      tcu2_filt_completed = (uint32_t)0;
   }
}

/* ---------- internal operations: ------------------------------------------ */
