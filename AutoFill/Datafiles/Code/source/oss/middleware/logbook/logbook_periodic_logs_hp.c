/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : logbook_periodic_logs_hp function which allows logbook management at
 *               each RTC
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "logbook_public.h"
#include "logbook_private.h"

/* ---------- include required interface: ----------------------------------- */
#include "memory/lib_critical_service_section_def_data.h" /* Access to shared memory */

#include "middleware/tecu/tecu_public.h"
#include "middleware/hpdisc/hpdisc_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-LOGBOOK-0040 */
void logbook_periodic_logs_hp(void)
{
   /* Event block used for every log */
   ts_event_block log;

   /* Compute exception context */
   const uint32_t exception_context = (uint32_t)0;

   /* Unions used for every raw data [1:4] */
   tu_raw_data    raw_data_2;
   tu_raw_data    raw_data_3;

   /* HP1 log */
   logbook_fill_event_block(&log, FCT_ID_HP1, shmem.s_hp_w.s_hp_status[e_hp_1].u_word,
                           exception_context, SPARE_VALUE, SPARE_VALUE, SPARE_VALUE, (uint32_t)hpdisc_mon_state[e_hp_1],
                           int_ext_temp, SPEED_PREBLUE_VALUE);
   logbook_save_log(&log);

   /* HP2 log */
   logbook_fill_event_block(&log, FCT_ID_HP2, shmem.s_hp_w.s_hp_status[e_hp_2].u_word,
                           exception_context, SPARE_VALUE, SPARE_VALUE, SPARE_VALUE, (uint32_t)hpdisc_mon_state[e_hp_2],
                           int_ext_temp, SPEED_PREBLUE_VALUE);
   logbook_save_log(&log);

   /* HP3 log */
   logbook_fill_event_block(&log, FCT_ID_HP3, shmem.s_hp_w.s_hp_status[e_hp_3].u_word,
                           exception_context, SPARE_VALUE, SPARE_VALUE, SPARE_VALUE, (uint32_t)hpdisc_mon_state[e_hp_3],
                           int_ext_temp, SPEED_PREBLUE_VALUE);
   logbook_save_log(&log);

   /* HP5 log */
   logbook_fill_event_block(&log, FCT_ID_HP5, shmem.s_hp_w.s_hp_status[e_hp_5].u_word,
                           exception_context, SPARE_VALUE, SPARE_VALUE, SPARE_VALUE, (uint32_t)hpdisc_mon_state[e_hp_5],
                           int_ext_temp, SPEED_PREBLUE_VALUE);
   logbook_save_log(&log);

   /* HP4 log */
   raw_data_2.u_float = hpdisc_voltage_mon;
   raw_data_3.u_float = hpdisc_current_mon;
   logbook_fill_event_block(&log, FCT_ID_HP4, shmem.s_hp_w.s_hp_status[e_hp_4].u_word, exception_context,
                           shmem.s_hp_w.s_hp_command[e_hp_4], raw_data_2.u_integer, raw_data_3.u_integer, SPARE_VALUE,
                           int_ext_temp, SPEED_PREBLUE_VALUE);
   logbook_save_log(&log);
}

/* ---------- internal operations: ------------------------------------------ */
