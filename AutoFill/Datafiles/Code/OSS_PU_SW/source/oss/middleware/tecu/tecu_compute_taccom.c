/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : TECU computation of the accomodation temperature
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
/* Accommodation filtered temperature */
float32_t filt_taccom;

/* Previous accommodation filtered temperature */
float32_t prev_filt_taccom;

/* The completion of the accomodation temperature filtering computation indication */
boolean_t taccom_filt_completed;

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------- */
/* Implements REQ_FADEX_OS_SRD-TECU-0010 */
/* Compute accomodation temperature filter */
void tecu_compute_taccom(const boolean_t channel_is_a)
{
   /********************ACCOM TEMPERATURE IS NOT REQUIRED ON THE BLUE LABEL ****************************/
   /* Pointer to the TECU status of the actual channel */
   ts_tecu* shmem_tecu;
   /* Pointer to the TECU status of the previous RTC */
   ts_tecu* prev_shmem_tecu;

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

   /* If the previous accomodation temperature was out of range or inconsistent or is the first RTC */
   if((uint32_t)0 == prev_shmem_tecu->s_fault_word.u_bit.s_err_taccom ||(uint32_t)1 == rtc_counter)
   {
      /* Store the instantaneous accomodation temperature to the previous filtered accomodation temperature */
      prev_filt_taccom = taccom;
   }

   /* If the accomodation temperature is in the expected range and consistent */
   if((uint32_t)0 == shmem_tecu->s_fault_word.u_bit.s_err_taccom)
   {
      /* Compute the accomodation filtered temperature */
      filt_taccom = TACCOM_FILTER_COEFF * prev_filt_taccom + ((1 - TACCOM_FILTER_COEFF) * taccom);

      /* Set the previous accomodation filtered temperature to the current accomodation filtered temperature */
      prev_filt_taccom = filt_taccom;

      /* Indicate that the computation of the accomodation filtered temperature has been completed */
      taccom_filt_completed = (uint32_t)1;
   }
   else
   {
      /* Indicate that the computation of the accomodation filtered temperature has not been completed */
      taccom_filt_completed = (uint32_t)0;
   }
}

/* ---------- internal operations: ------------------------------------------ */
