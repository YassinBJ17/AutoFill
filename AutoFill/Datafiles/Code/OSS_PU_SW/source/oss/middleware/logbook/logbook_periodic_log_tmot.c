/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : logbook_periodic_log_tmot function which allows logbook management at
 *               each RTC
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "logbook_public.h"
#include "logbook_private.h"

/* ---------- include required interface: ----------------------------------- */
#include "memory/lib_critical_service_section_def_data.h" /* Access to shared memory */

#include "middleware/tecu/tecu_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-LOGBOOK-0040 */
void logbook_periodic_log_tmot(const boolean_t p_channel_is_a)
{
   /* Event block used for every log */
   ts_event_block log;

   /* Compute exception context */
   const uint32_t exception_context = (uint32_t)0;

   /* Unions used for every raw data [1:4] */
   tu_raw_data    raw_data_1;
   tu_raw_data    raw_data_3;
   tu_raw_data    raw_data_4;

   /* When the channel is A */
   if (p_channel_is_a)
   {
      /* TMOT log */
      raw_data_1.u_float = shmem.s_tmot_w.s_current;
      raw_data_3.u_float = shmem.s_tmot_r_a.s_voltage;
      raw_data_4.u_float = shmem.s_tmot_r_a.s_current;
      logbook_fill_event_block(&log, FCT_ID_TMOT, shmem.s_tmot_r_a.s_fault_word.u_word,
                              exception_context, raw_data_1.u_integer, SPARE_VALUE, raw_data_3.u_integer,
                              raw_data_4.u_integer, int_ext_temp, SPEED_PREBLUE_VALUE);
      logbook_save_log(&log);
   }
   /* When the channel is B */
   else
   {
      /* TMOT log */
      raw_data_1.u_float = shmem.s_tmot_w.s_current;
      raw_data_3.u_float = shmem.s_tmot_r_b.s_voltage;
      raw_data_4.u_float = shmem.s_tmot_r_b.s_current;
      logbook_fill_event_block(&log, FCT_ID_TMOT, shmem.s_tmot_r_b.s_fault_word.u_word,
                              exception_context, raw_data_1.u_integer, SPARE_VALUE, raw_data_3.u_integer,
                              raw_data_4.u_integer, int_ext_temp, SPEED_PREBLUE_VALUE);
      logbook_save_log(&log);

   }
}

/* ---------- internal operations: ------------------------------------------ */
