/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Compute OVSP high side temperature filter function
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
/* Previous overspeed high side filtered temperature */
float32_t filt_tohs;

/* Preivous overspeed high side filtered temperature */
float32_t prev_filt_tohs;

/* The completion of the overspeed high side temperature filtering computation indication */
boolean_t tohs_filt_completed;

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------- */
/* Implements REQ_FADEX_OS_SRD-TECU-0010 */
/* Compute OVSP high side temperature filter function*/
void tecu_compute_tohs(const boolean_t channel_is_a)
{

   ts_tecu* shmem_tecu;        /* Pointer to the TECU status of the actual channel */
   ts_tecu* prev_shmem_tecu;   /* Pointer to the TECU status of the previous RTC */

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

   /* If the previous OVSP high side temperature was out of range or inconsistent or is the first RTC */
   if((uint32_t)1 == prev_shmem_tecu->s_fault_word.u_bit.s_err_tohs || (uint32_t)1 == rtc_counter)
   {
      /* Store the instantaneous OVSP high side temperature to the previous filtered OVSP high side temperature */
      prev_filt_tohs = tohs;
   }

   /* If the OVSP high side temperature is in the expected range and consistent */
   if((uint32_t)0 == shmem_tecu->s_fault_word.u_bit.s_err_tohs)
   {
      /* Compute the OVSP high side filtered temperature */
      filt_tohs = TOHS_FILTER_COEFF * prev_filt_tohs + ((1 - TOHS_FILTER_COEFF) * tohs);

      /* Set the previous OVSP high side filtered temperature to the current OVSP high side filtered temp */
      prev_filt_tohs = filt_tohs;

      /* Indicate that the computation of the OVSP high side filtered temperature has been completed */
      tohs_filt_completed = (uint32_t)1;
   }
   else
   {
      /* Indicate that the computation of the OVSP high side filtered temperature has not been completed */
      tohs_filt_completed = (uint32_t)0;
   }
}

/* ---------- internal operations: ------------------------------------------ */
