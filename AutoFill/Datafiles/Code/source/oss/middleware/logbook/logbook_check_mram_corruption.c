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
/* Bit that indicate the log is corrupted or uncorrupted in the exception context */
#define CORRUPTED_VALUE    ((uint32_t)0x80000000)

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-LOGBOOK-0020 */
void logbook_check_mram_corruption(ts_event_block * const p_mram_log, const ts_event_block * const p_local_log)
{
   /* Used for reading the previously written logs in MRAM */
   ts_event_block read_event_block;

   /* Read the previously written logs in MRAM */
   read_event_block = *p_mram_log;

   /* When the log is different to the previously written logs read in MRAM */
   /* The condition is divided in multiple parts to satisfy the Rule* 22.2 */
   if (   (read_event_block.s_id != p_local_log->s_id)
       || (read_event_block.s_flt_wrd_calc_mode != p_local_log->s_flt_wrd_calc_mode)
       || (read_event_block.s_timestamp != p_local_log->s_timestamp)
       || (read_event_block.s_pwr_up_counter != p_local_log->s_pwr_up_counter)
       || (read_event_block.s_exc_context_spare != p_local_log->s_exc_context_spare))
   {
      /* Indicate the log is corrupted */
      p_mram_log->s_exc_context_spare |= CORRUPTED_VALUE;
   }
   else if (   (read_event_block.s_raw_data_1 != p_local_log->s_raw_data_1)
            || (read_event_block.s_raw_data_2 != p_local_log->s_raw_data_2)
            || (read_event_block.s_raw_data_3 != p_local_log->s_raw_data_3)
            || (read_event_block.s_raw_data_4 != p_local_log->s_raw_data_4)
            || (read_event_block.s_accom_info != p_local_log->s_accom_info))
   {
      /* Indicate the log is corrupted */
      p_mram_log->s_exc_context_spare |= CORRUPTED_VALUE;
   }
   else if (   (read_event_block.s_temp_calc_pn != p_local_log->s_temp_calc_pn)
            || (read_event_block.s_speed_calc_sn != p_local_log->s_speed_calc_sn)
            || (read_event_block.s_mission_id != p_local_log->s_mission_id))
   {
      /* Indicate the log is corrupted */
      p_mram_log->s_exc_context_spare |= CORRUPTED_VALUE;
   }
   else
   {
      /* Indicate the log is uncorrupted (~ is the NOT bit operator, i.e. one's complement) */
      p_mram_log->s_exc_context_spare &= (uint32_t)(~CORRUPTED_VALUE);
   }
}

/* ---------- internal operations: ------------------------------------------ */
