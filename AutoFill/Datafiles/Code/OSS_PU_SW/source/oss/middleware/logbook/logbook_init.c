/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : logbook_init function which allows logbook initialization.
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/logbook/logbook_public.h"
#include "middleware/logbook/logbook_private.h"

/* ---------- include required interface: ----------------------------------- */
#include "middleware/mram/mram_public.h"

/* ---------- internal define constants: ------------------------------------ */
/* Max value for the power up counter */
#define LOGBOOK_POWER_UP_COUNTER_MAX_VALUE ((uint32_t)0xFFFFFFFF)

/* Impossible value for status words */
#define IMPOSSIBLE_STATUS_WORD             ((uint32_t)0xFFFFFFFE)

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */
/* Position of the channel ID bit in the function ID */
#define CHANNEL_A_B_FCT_SHIFT ((uint32_t)8)

/* ---------- provided data: ------------------------------------------------ */
/* Number of OS power-up */
uint32_t power_up_counter;

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Initialize the variables used for logbook */
/* Implements REQ_FADEX_OS_SRD-LOGBOOK-0010 */
/* Implements REQ_FADEX_OS_SRD-LOGBOOK-0030 */
void logbook_init(void)
{
   /* Iterator */
   uint32_t i;

   /* Read in memory the power-up counter */
   power_up_counter = mram_oss_critical_data->s_oss_pu_counters.s_pw_up_count;
   /* If the the power up counter reaches the max value, reset to 0 */
   if (LOGBOOK_POWER_UP_COUNTER_MAX_VALUE == power_up_counter)
   {
      power_up_counter = (uint32_t)0;
   }
   /* Increment by one the power-up counter */
   power_up_counter++;
   /* Write the updated power-up counter in the NVM */
   mram_oss_critical_data->s_oss_pu_counters.s_pw_up_count = power_up_counter;

   /* For all the functions */
   for (i = (uint32_t)0; FUNCTION_NB > i; i++)
   {
      /* Associate each origin (represented by the index) to a registered log address */
      registered_lgbk_hashmap[i].s_reg_lgbk_addr = (ts_registered_lgbk *)(REGISTERED_LGBK_START_ADDR
                                                                        + (i * REGISTERED_LGBK_OFFSET_ADDR));

      /* Initialize the short occurrence counter to 0 */
      registered_lgbk_hashmap[i].s_short_occurrence_counter = (uint32_t)0;

      /* Initalize the two previous logged fault word to 0*/
      previous_critical_flt_wrd[i][0] = IMPOSSIBLE_STATUS_WORD;
      previous_critical_flt_wrd[i][1] = IMPOSSIBLE_STATUS_WORD;

      /* Initialize the previous RTC fault word to 0 */
      previous_rtc_flt_wrd[i] = (uint32_t)0;
   }

   /* Make reading and writing index begin at the start of the critical logbook */
   critical_lgbk_hashmap.s_event_block_buffer   = (ts_event_block *)CRITICAL_LGBK_START_ADDR;
   critical_lgbk_hashmap.s_read_index           = (uint32_t)0;
   critical_lgbk_hashmap.s_write_index          = (uint32_t)0;
   critical_lgbk_hashmap.s_logs_to_read_counter = (uint32_t)0;

   /* Make reading and writing index begin at the start of the trigger logbook */
   trigger_lgbk_hashmap.s_read_index           = (uint32_t)0;
   trigger_lgbk_hashmap.s_write_index          = (uint32_t)0;
   trigger_lgbk_hashmap.s_logs_to_read_counter = (uint32_t)0;
}

/* ---------- internal operations: ------------------------------------------ */
