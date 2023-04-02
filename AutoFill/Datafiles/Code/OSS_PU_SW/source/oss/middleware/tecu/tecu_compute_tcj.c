/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Compute cold junction temperature filter
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "middleware/tecu/tecu_public.h"
#include "middleware/t4/t4_public.h"
#include "middleware/rtc/rtc_public.h"
#include "memory/lib_critical_service_section_def_data.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* Cold junction filtered temperature */
float32_t filt_tcj;

/* Previous cold junction filtered temperature */
float32_t prev_filt_tcj;

/* The completion of the cold junction temperature filtering computation indication */
boolean_t tcj_filt_completed;

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------- */
/* Implements REQ_FADEX_OS_SRD-TECU-0010 */
/* Compute cold junction temperature filter */
void tecu_compute_tcj(const boolean_t channel_is_a)
{

   ts_tecu* shmem_tecu;                      /* Pointer to the TECU status of the actual channel */
   ts_tecu* prev_shmem_tecu;                 /* Pointer to the TECU status of the previous RTC */

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

   /* If the previous cold junction temperature was out of range or inconsistent or is the first RTC */
   if((uint32_t)0 == prev_shmem_tecu->s_fault_word.u_bit.s_err_tcj || (uint32_t)1 == rtc_counter)
   {
      /* Store the instantaneous cold junction temperature to the previous cold junction filtered temperature */
      prev_filt_tcj = tcj_conv;
   }

   /* If the cold junction temperature is in the expected range and consistent */
   if((uint32_t)0 == shmem_tecu->s_fault_word.u_bit.s_err_tcj)
   {
      /* Compute the cold junction filtered temperature */
      filt_tcj = TCJ_FILTER_COEFF * prev_filt_tcj + ((1 - TCJ_FILTER_COEFF) * tcj_conv);
      /* Set the previous cold junction filtered temperature to the current cold junction filtered temperature */
      prev_filt_tcj = filt_tcj;
      /* Indicate that the computation of the cold junction filtered temperature has been completed */
      tcj_filt_completed = (uint32_t)1;
   }
   else
   {
      /* Indicate that the computation of the cold junction filtered temperature has not been completed */
      tcj_filt_completed = (uint32_t)0;
   }
}

/* ---------- internal operations: ------------------------------------------ */
