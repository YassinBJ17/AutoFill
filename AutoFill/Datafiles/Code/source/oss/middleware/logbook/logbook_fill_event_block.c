/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : logbook_fill_event_block function which allows to fill the event
 *               block with the logbook data
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/logbook/logbook_public.h"
#include "middleware/logbook/logbook_private.h"

/* ---------- include required interface: ----------------------------------- */
#include "middleware/mram/mram_public.h"
#include "middleware/rtc/rtc_public.h"
#include "middleware/accom/accom_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Fill the event block with logbook data */
/* Implements REQ_FADEX_OS_SRD-LOGBOOK-0010 */
void logbook_fill_event_block(ts_event_block * const p_event_block, const uint32_t p_id,
                              const uint32_t p_flt_wrd_calc_mode, const uint32_t p_exc_context_spare,
                              const uint32_t p_raw_data_1, const uint32_t p_raw_data_2,
                              const uint32_t p_raw_data_3, const uint32_t p_raw_data_4,
                              const uint32_t p_temp_calc_pn, const uint32_t p_speed_calc_sn)
{
   p_event_block->s_id = p_id;

   p_event_block->s_flt_wrd_calc_mode = p_flt_wrd_calc_mode;

   p_event_block->s_timestamp = rtc_counter;
   p_event_block->s_pwr_up_counter = power_up_counter;

   p_event_block->s_exc_context_spare = p_exc_context_spare;

   p_event_block->s_raw_data_1 = p_raw_data_1;
   p_event_block->s_raw_data_2 = p_raw_data_2;
   p_event_block->s_raw_data_3 = p_raw_data_3;
   p_event_block->s_raw_data_4 = p_raw_data_4;

   p_event_block->s_accom_info = accom_info.u_word;

   p_event_block->s_temp_calc_pn = p_temp_calc_pn;
   p_event_block->s_speed_calc_sn = p_speed_calc_sn;

   p_event_block->s_mission_id = mram_oss_critical_data->s_mission_id;
}

/* ---------- internal operations: ------------------------------------------ */
