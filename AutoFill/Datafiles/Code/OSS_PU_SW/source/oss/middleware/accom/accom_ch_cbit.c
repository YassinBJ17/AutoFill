/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : CBIT on channel identifier
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/accom/accom_public.h"
#include "middleware/accom/accom_private.h"

/* ---------- include required interface: ----------------------------------- */

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* Channel identifier status */
tu_accom_ch_bit_fault_word accom_ch_bit_fault_word;

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */

/* Implements REQ_FADEX_OS_SRD-ACCOM-0070 */
/**
 * Function to perform CBIT checks on the channel identifier, every RTC.
 */
tu_accom_ch_bit_fault_word accom_ch_cbit(void)
{
   accom_ch_bit_fault_word.u_word = 0;

   if (CHANNEL_ID_A == ch_id)
   {
      accom_ch_bit_fault_word.u_bit.s_ch_id_is_invalid= (uint32_t) FALSE;
      ch_id_backup = ch_id;
      accom_ch_bit_fault_word.u_bit.s_ch_id = ACCOM_CHANNEL_ID_IS_A;
   }
   else if (CHANNEL_ID_B == ch_id)
   {
      accom_ch_bit_fault_word.u_bit.s_ch_id_is_invalid = (uint32_t) FALSE;
      ch_id_backup = ch_id;
      accom_ch_bit_fault_word.u_bit.s_ch_id = ACCOM_CHANNEL_ID_IS_B;
   }
   /* if ch_id has an invalid value, try to use the backup */
   else if (CHANNEL_ID_A == ch_id_backup)
   {
      accom_ch_bit_fault_word.u_bit.s_ch_id_is_invalid = (uint32_t) FALSE;
      ch_id = ch_id_backup;
      accom_ch_bit_fault_word.u_bit.s_ch_id = ACCOM_CHANNEL_ID_IS_A;
   }
   else if (CHANNEL_ID_B == ch_id_backup)
   {
      accom_ch_bit_fault_word.u_bit.s_ch_id_is_invalid = (uint32_t) FALSE;
      ch_id = ch_id_backup;
      accom_ch_bit_fault_word.u_bit.s_ch_id = ACCOM_CHANNEL_ID_IS_B;
   }
   else
   /* Both stored values are obviously unusable... */
   {
      accom_ch_bit_fault_word.u_bit.s_ch_id_is_invalid = (uint32_t) TRUE;
      /* TODO to be logged in logbook and go in fail_safe mode to wait reset */
   }
   return accom_ch_bit_fault_word;
}

/* ---------- internal operations: ------------------------------------------ */
