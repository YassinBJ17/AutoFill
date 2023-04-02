/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : logbook_trigger_streams function which allows logbook management at
 *               each RTC
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/logbook/logbook_public.h"
#include "middleware/logbook/logbook_private.h"

/* ---------- include required interface: ----------------------------------- */
#include "conf/oss_conf_public.h"
#include "memory/memory_address_public.h"

#include "middleware/tecu/tecu_public.h"

/* ---------- internal define constants: ------------------------------------ */
#define SPARE_VALUE     ((uint32_t)0)

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* Hashmap associating trigger log address to a function*/
ts_trigger_lgbk_hashmap trigger_lgbk_hashmap;

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Create trigger logs when a function short occurrence counter has reached the CSS_PU trigger value */
void logbook_trigger_streams(void)
{
   /* Iterator */
   uint32_t i;

   /* Configuration table */
   const ts_oss_conf_table *oss_conf = (ts_oss_conf_table *)OSS_CONF_START_ADDR;

   /* For all the functions */
   for (i = (uint32_t)0; FUNCTION_NB > i; i++)
   {
      /* If a function short occurrence counter has reached the CSS_PU trigger value */
      if (oss_conf->s_shortoccurrencetrigger <= registered_lgbk_hashmap[i].s_short_occurrence_counter)
      {
         /* Create a trigger log */
         logbook_fill_event_block(&(trigger_lgbk_hashmap.s_trigger_logs[trigger_lgbk_hashmap.s_write_index]),
                                  i, registered_lgbk_hashmap[i].s_reg_lgbk_addr->s_last_log.s_flt_wrd_calc_mode,
                                  SPARE_VALUE, SPARE_VALUE, SPARE_VALUE,
                                  registered_lgbk_hashmap[i].s_short_occurrence_counter,
                                  registered_lgbk_hashmap[i].s_reg_lgbk_addr->s_long_occurrence_counter,
                                  int_ext_temp, SPEED_PREBLUE_VALUE);

         /* If the new log is written over a log that has not been read yet */
         if ((trigger_lgbk_hashmap.s_write_index == trigger_lgbk_hashmap.s_read_index)
             && ((uint32_t)0 != trigger_lgbk_hashmap.s_logs_to_read_counter))
         {
            /* Increment the read index to the next older log in the circular buffer */
            trigger_lgbk_hashmap.s_read_index = (trigger_lgbk_hashmap.s_read_index + (uint32_t)1) % TRIGGER_LOGS_NB;

            /* Remove the log that has been overwritten from the logs to read counter */
            trigger_lgbk_hashmap.s_logs_to_read_counter--;
         }

         /* Indicate there is a new log to read in the trigger logbook */
         trigger_lgbk_hashmap.s_logs_to_read_counter++;

         /* Increment the write index to the next log */
         trigger_lgbk_hashmap.s_write_index = (trigger_lgbk_hashmap.s_write_index + (uint32_t)1) % TRIGGER_LOGS_NB;
      }
   }
}

/* ---------- internal operations: ------------------------------------------ */
