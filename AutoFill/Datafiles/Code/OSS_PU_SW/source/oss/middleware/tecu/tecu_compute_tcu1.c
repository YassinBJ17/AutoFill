/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : TECU computation and status management function
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
/* Control unit filtered temperature */
float32_t filt_tcu1;

/* Previous control unit filtered temperature */
float32_t prev_filt_tcu1;

/* The completion of the control unit temperature filtering computation indication */
boolean_t tcu1_filt_completed;

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------- */
/* Implements REQ_FADEX_OS_SRD-TECU-0010 */
/* TECU computation and status management function */
void tecu_compute_tcu1(const boolean_t channel_is_a)
{

   ts_tecu* shmem_tecu;       /* Pointer to the TECU status of the actual channel */
   ts_tecu* prev_shmem_tecu;  /* Pointer to the TECU status of the previous RTC */


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


   /* If the previous control unit temperature was out of range or inconsistent or is the first RTC */
   if((uint32_t)1 == prev_shmem_tecu->s_fault_word.u_bit.s_err_tcu1 || (uint32_t)1 == rtc_counter)
   {
      /* Store the instantaneous control unit temperature to the previous filtered control unit temperature */
      prev_filt_tcu1 = tcu1;
   }

   /* If the control unit temperature is in the expected range and consistent */
   if((uint32_t)0 == shmem_tecu->s_fault_word.u_bit.s_err_tcu1)
   {
      /* Compute the control unit filtered temperature */
      filt_tcu1 = TCU1_FILTER_COEFF * prev_filt_tcu1 + ((1 - TCU1_FILTER_COEFF) * tcu1);
      /* Set the previous control unit filtered temperature to the current control unit filtered temperature */
      prev_filt_tcu1 = filt_tcu1;
      /* Indicate that the computation of the control unit filtered temperature has been completed */
      tcu1_filt_completed = (uint32_t)1;
   }
   else
   {
      /* Indicate that the computation of the control unit filtered temperature has not been completed */
      tcu1_filt_completed = (uint32_t)0;
   }

}

/* ---------- internal operations: ------------------------------------------ */
