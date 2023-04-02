/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : logbook_periodic_logs_calres function which allows logbook management at
 *               each RTC
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "logbook_public.h"
#include "logbook_private.h"

/* ---------- include required interface: ----------------------------------- */
#include "memory/lib_critical_service_section_def_data.h" /* Access to shared memory */

#include "middleware/tecu/tecu_public.h"
#include "middleware/calres/calres_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-LOGBOOK-0040 */
void logbook_periodic_logs_calres(const boolean_t p_channel_is_a)
{
   /* Event block used for every log */
   ts_event_block log;

   /* Compute exception context */
   const uint32_t exception_context = (uint32_t)0;

   /* Unions used for every raw data [1:4] */
   tu_raw_data    raw_data_3;
   tu_raw_data    raw_data_4;

   /* When the channel is A */
   if (p_channel_is_a)
   {
      /* CALRES 1 log */
      raw_data_3.u_float = calres_signal_1_3;
      raw_data_4.u_float = shmem.s_calres_1_2.s_calres_measure1;
      logbook_fill_event_block(&log, FCT_ID_CALRES1, shmem.s_calres_1_2.s_fault_word.u_word,
                              exception_context, SPARE_VALUE, SPARE_VALUE, raw_data_3.u_integer, raw_data_4.u_integer,
                              int_ext_temp, SPEED_PREBLUE_VALUE);
      logbook_save_log(&log);

      /* CALRES 2 log */
      raw_data_3.u_float = calres_signal_2_4;
      raw_data_4.u_float = shmem.s_calres_1_2.s_calres_measure2;
      logbook_fill_event_block(&log, FCT_ID_CALRES2, shmem.s_calres_1_2.s_fault_word.u_word,
                              exception_context, SPARE_VALUE, SPARE_VALUE, raw_data_3.u_integer, raw_data_4.u_integer,
                              int_ext_temp, SPEED_PREBLUE_VALUE);
      logbook_save_log(&log);
   }
   /* When the channel is B */
   else
   {
      /* CALRES 3 log */
      raw_data_3.u_float = calres_signal_1_3;
      raw_data_4.u_float = shmem.s_calres_3_4.s_calres_measure1;
      logbook_fill_event_block(&log, FCT_ID_CALRES3, shmem.s_calres_3_4.s_fault_word.u_word,
                              exception_context, SPARE_VALUE, SPARE_VALUE, raw_data_3.u_integer, raw_data_4.u_integer,
                              int_ext_temp, SPEED_PREBLUE_VALUE);
      logbook_save_log(&log);

      /* CALRES 4 log */
      raw_data_3.u_float = calres_signal_2_4;
      raw_data_4.u_float = shmem.s_calres_3_4.s_calres_measure2;
      logbook_fill_event_block(&log, FCT_ID_CALRES4, shmem.s_calres_3_4.s_fault_word.u_word,
                              exception_context, SPARE_VALUE, SPARE_VALUE, raw_data_3.u_integer, raw_data_4.u_integer,
                              int_ext_temp, SPEED_PREBLUE_VALUE);
      logbook_save_log(&log);
   }
}

/* ---------- internal operations: ------------------------------------------ */
