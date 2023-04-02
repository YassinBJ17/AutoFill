/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : logbook_save_log function which allows to save a log in the
 *               registered and critical logbooks
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/logbook/logbook_public.h"
#include "middleware/logbook/logbook_private.h"

/* ---------- include required interface: ----------------------------------- */

/* ---------- internal define constants: ------------------------------------ */
/* Value used to initialize the registered logbook area */
#define INIT_VALUE            ((uint32_t)0)           /* TBD */

/* Value of status word when it indicates no fault */
#define STATUS_VALID          ((uint32_t)0)

/* Position of the activity of the channel in the origin ID */
#define CHANNEL_ACTIVE_SHIFT  ((uint32_t)27)

/* Number of PBIT functions */
#define NB_PBIT_FCT_ID        ((uint32_t)10)

/* Start ID of CBIT function */
#define CBIT_START_ID         ((uint32_t)256)

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* Hash map associating each origin of event to a registered log address and a short occurrence counter */
ts_registered_lgbk_hashmap registered_lgbk_hashmap[FUNCTION_NB];

/* Hash map associating critical log address to an appearance index */
ts_critical_lgbk_hashmap   critical_lgbk_hashmap;

/* Table of the fault word of the previous RTC */
uint32_t previous_rtc_flt_wrd[FUNCTION_NB];

/* Table of the two previous fault words for each function */
uint32_t previous_critical_flt_wrd[FUNCTION_NB][PREVIOUS_FAULT_WORD_NB];

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Save a new event in the registered logbook and in the critical logbook */
/* Implements REQ_FADEX_OS_SRD-LOGBOOK-0010 */
/* Implements REQ_FADEX_OS_SRD-LOGBOOK-0020 */
void logbook_save_log(const ts_event_block * const p_event_block)
{
   /* Identifier of the function saving log */
   uint32_t fct_id;

   /* Function's registered logbook address */
   ts_registered_lgbk *reg_lgbk_addr;

   /* Get the function identifier from the event */
   fct_id = p_event_block->s_id;

   /* Compute index in registered logbook */
   if (fct_id >= CBIT_START_ID)
   {
      fct_id = (fct_id + NB_PBIT_FCT_ID) - CBIT_START_ID;
   }

   /* Save the address associated to the given function id */
   reg_lgbk_addr = registered_lgbk_hashmap[fct_id].s_reg_lgbk_addr;

   /* REGISTERED FIRST LOG */

   /* When no log has been logged in the first log slot of the registered logbook for the function since last MRAM */
   /* erase and the status indicates a fault */
   if ((INIT_VALUE == reg_lgbk_addr->s_first_log.s_id) && (STATUS_VALID != p_event_block->s_flt_wrd_calc_mode))
   {
      /* Save the event in the blocks of first occurrence block */
      reg_lgbk_addr->s_first_log = *p_event_block;

      /* Check MRAM corruption */
      logbook_check_mram_corruption(&reg_lgbk_addr->s_first_log, p_event_block);
   }

   /* REGISTERED LAST LOG */

   /* When no previous status for the function has been logged since last powerup and the status indicates a fault */
   /* or when the status is different from the previous status logged in the last log slot for the function */
   if (     (((uint32_t)0 == registered_lgbk_hashmap[fct_id].s_short_occurrence_counter)
         &&  (STATUS_VALID != p_event_block->s_flt_wrd_calc_mode))
         || (((uint32_t)0 != registered_lgbk_hashmap[fct_id].s_short_occurrence_counter)
         &&  (reg_lgbk_addr->s_last_log.s_flt_wrd_calc_mode != p_event_block->s_flt_wrd_calc_mode)))
   {
      /* Save the event in the last occurrence block */
      reg_lgbk_addr->s_last_log = *p_event_block;

      /* Check MRAM corruption */
      logbook_check_mram_corruption(&reg_lgbk_addr->s_last_log, p_event_block);
   }

   /* CRITICAL LOGBOOK */

   /* When no previous status for the function has been logged since last powerup and the status indicates a fault */
   /* or only one log has been logged in the critical logbook for the function since last power-up and the previous
      fault status logged in the critical logbook is different from the current status */
   /* At least two logs have been logged in the critical logbook for the function since last power-up and the current
      status is different from both last two status logged in the critical logbook for the function */
   if (     (((uint32_t)0 == registered_lgbk_hashmap[fct_id].s_short_occurrence_counter)
         &&  (STATUS_VALID != p_event_block->s_flt_wrd_calc_mode))
         || (((uint32_t)0 < registered_lgbk_hashmap[fct_id].s_short_occurrence_counter)
         &&  ((p_event_block->s_flt_wrd_calc_mode != previous_critical_flt_wrd[fct_id][0])
         &&   (p_event_block->s_flt_wrd_calc_mode != previous_critical_flt_wrd[fct_id][1]))))
   {
      /* Save the event in the critical logbook */
      critical_lgbk_hashmap.s_event_block_buffer[critical_lgbk_hashmap.s_write_index] = *p_event_block;

      /* Check MRAM corruption */
      logbook_check_mram_corruption(&critical_lgbk_hashmap.s_event_block_buffer[critical_lgbk_hashmap.s_write_index],
                                    p_event_block);

      /* If the new log is written over a log that has not been read yet */
      if ((critical_lgbk_hashmap.s_write_index == critical_lgbk_hashmap.s_read_index)
          && ((uint32_t)0 != critical_lgbk_hashmap.s_logs_to_read_counter))
      {
         /* Increment the read index to the next older log in the circular buffer */
         critical_lgbk_hashmap.s_read_index = (critical_lgbk_hashmap.s_read_index + (uint32_t)1) % CRITICAL_LOGS_NB;

         /* Remove the log that has been overwritten from the logs to read counter */
         critical_lgbk_hashmap.s_logs_to_read_counter--;
      }
      /* Indicate there is a new log to read in the critical logbook */
      critical_lgbk_hashmap.s_logs_to_read_counter++;
      /* Increment the write index to the next block */
      critical_lgbk_hashmap.s_write_index = (critical_lgbk_hashmap.s_write_index + (uint32_t)1) % CRITICAL_LOGS_NB;

      /* Replace the n-2 fault word with the n-1 fault word */
      previous_critical_flt_wrd[fct_id][1] = previous_critical_flt_wrd[fct_id][0];

      /* Replace the n-1 fault word with the n fault word */
      previous_critical_flt_wrd[fct_id][0] = p_event_block->s_flt_wrd_calc_mode;
   }

   /* SHORT AND LONG OCCURRENCE COUNTERS */

   /* When no previous status for the function has been logged and the status indicates a fault */
   /* or when the status word is different from the one identified in the previous RTC  */
   if (previous_rtc_flt_wrd[fct_id] != p_event_block->s_flt_wrd_calc_mode)
   {
      /* Increment the counter of the registered log identifier by its origin */
      reg_lgbk_addr->s_long_occurrence_counter++;
      /* Increment the short occurrence counter (stored in flash) */
      registered_lgbk_hashmap[fct_id].s_short_occurrence_counter++;
   }

   /* Save the identified status of the current RTC */
   previous_rtc_flt_wrd[fct_id] = p_event_block->s_flt_wrd_calc_mode;
}

/* ---------- internal operations: ------------------------------------------ */
