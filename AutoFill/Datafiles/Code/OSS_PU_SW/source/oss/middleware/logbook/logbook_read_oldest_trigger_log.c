/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : logbook_read_oldest_trigger_log function which allows to read
 *               the oldest log in the trigger logbook
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
/* Read the oldest trigger log and return TRUE if a log has been read, FALSE otherwise */
boolean_t logbook_read_oldest_trigger_log(ts_event_block * const p_trigger_log)
{
   /* Status indicating if a log has been read (or not) */
   boolean_t read_state = FALSE;

   /* If there are logs to read */
   if ((uint32_t)0 < trigger_lgbk_hashmap.s_logs_to_read_counter)
   {
      /* Read a log in the trigger logbook */
      *p_trigger_log = trigger_lgbk_hashmap.s_trigger_logs[trigger_lgbk_hashmap.s_read_index];

      /* Increment the read index for the next read */
      trigger_lgbk_hashmap.s_read_index = ((trigger_lgbk_hashmap.s_read_index + (uint32_t)1) % TRIGGER_LOGS_NB);

      /* Indicate a log has been read */
      trigger_lgbk_hashmap.s_logs_to_read_counter--;
      read_state = TRUE;
   }

   /* Indicate to the caller if a log has been read or not */
   return read_state;
}

/* ---------- internal operations: ------------------------------------------ */
