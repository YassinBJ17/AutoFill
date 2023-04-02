/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Compute primary supply function temperature filter function
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
/* Primary power supply filtered temperature */
float32_t filt_tpsf;

/* Previous primary power supply filtered temperature */
float32_t prev_filt_tpsf;

/* The completion of the primary supply function temperature filtering computation indication */
boolean_t tpsf_filt_completed;

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------- */
/* Implements REQ_FADEX_OS_SRD-TECU-0010 */
/* Compute primary supply function temperature filter function */
void tecu_compute_tpsf(const boolean_t channel_is_a)
{

   ts_tecu* shmem_tecu;                 /* Pointer to the TECU status of the actual channel */
   ts_tecu* prev_shmem_tecu;            /* Pointer to the TECU status of the previous RTC */

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

   /* If the previous primary supply function temperature was out of range or inconsistent or is the first RTC */
   if((uint32_t)1 == prev_shmem_tecu->s_fault_word.u_bit.s_err_tpsf || (uint32_t)1 == rtc_counter)
   {
      /* Store the instantaneous primary supply function temperature to the previous filtered primary supply function temperature */
      prev_filt_tpsf = tpsf;
   }

   /* If the primary supply function temperature is in the expected range and consistent */
   if((uint32_t)0 == shmem_tecu->s_fault_word.u_bit.s_err_tpsf)
   {
      /* Compute the primary supply function filtered temperature */
      filt_tpsf = TPSF_FILTER_COEFF * prev_filt_tpsf + ((1 - TPSF_FILTER_COEFF) * tpsf);

      /* Set the previous primary supply fct filtered temperature to the current primary supply fct filtered temp */
      prev_filt_tpsf = filt_tpsf;

      /* Indicate that the computation of the primary supply function filtered temperature has been completed */
      tpsf_filt_completed = (boolean_t)1;
   }
   else
   {
      /* Indicate that the computation of the primary supply function filtered temperature has not been completed */
      tpsf_filt_completed = (boolean_t)0;
   }
}

/* ---------- internal operations: ------------------------------------------ */
