/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : logbook_read_oldest_critical_log function which allows to read
 *               the oldest log in the critical logbook
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/logbook/logbook_public.h"
#include "middleware/logbook/logbook_private.h"

/* ---------- include required interface: ----------------------------------- */

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Read the oldest critical log and return TRUE if a log has been read, FALSE otherwise */
boolean_t logbook_read_oldest_critical_log(ts_event_block * const p_event_block)
{
   /* Status indicating if a log has been read (or not) */
   boolean_t read_state = FALSE;

   /* If there are logs to read */
   if ((uint32_t)0 < critical_lgbk_hashmap.s_logs_to_read_counter)
   {
      /* Read a log in the critical logbook */
      *p_event_block = critical_lgbk_hashmap.s_event_block_buffer[critical_lgbk_hashmap.s_read_index];

      /* Increment the read index for the next read */
      critical_lgbk_hashmap.s_read_index = ((critical_lgbk_hashmap.s_read_index + (uint32_t)1) % CRITICAL_LOGS_NB);

      /* Indicate a log has been read */
      critical_lgbk_hashmap.s_logs_to_read_counter--;
      read_state = TRUE;
   }

   /* Indicate to the caller if a log has been read or not */
   return read_state;
}

/* ---------- internal operations: ------------------------------------------ */
