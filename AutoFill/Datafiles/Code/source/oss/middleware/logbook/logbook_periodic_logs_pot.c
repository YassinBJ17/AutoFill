/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : logbook_periodic_logs_pot function which allows logbook management at
 *               each RTC
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "logbook_public.h"
#include "logbook_private.h"

/* ---------- include required interface: ----------------------------------- */
#include "memory/lib_critical_service_section_def_data.h" /* Access to shared memory */
#include "conf/oss_conf_public.h"

#include "middleware/tecu/tecu_public.h"
#include "middleware/pot/pot_public.h"

/* ---------- internal define constants: ------------------------------------ */
/* POT configuration */
#define POT_CONFIGURATION     ((uint32_t)0)

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-LOGBOOK-0040 */
void logbook_periodic_logs_pot(const boolean_t p_channel_is_a)
{
   /* Configuration table */
   const ts_oss_conf_table *oss_conf = (ts_oss_conf_table *)OSS_CONF_START_ADDR;

   /* Event block used for every log */
   ts_event_block log;

   /* Compute exception context */
   const uint32_t exception_context = (uint32_t)0;

   /* Unions used for every raw data [1:4] */
   tu_raw_data    raw_data_1;
   tu_raw_data    raw_data_2;
   tu_raw_data    raw_data_3;
   tu_raw_data    raw_data_4;

   /* When the channel is A */
   if (p_channel_is_a)
   {
      /* When the configuration is POT */
      if (POT_CONFIGURATION == oss_conf->s_pot1_sensor_type)
      {
         /* POT1 log */
         raw_data_1.u_float = s_measures_1_2.v_signal;
         raw_data_2.u_float = s_measures_1_2.v_exc;
         raw_data_3.u_float = s_measures_1_2.v_low_side;
         raw_data_4.u_float = shmem.s_pot1.s_measure;
         logbook_fill_event_block(&log, FCT_ID_POT1, shmem.s_pot1.s_fault_word.u_word, exception_context,
                                 raw_data_1.u_integer, raw_data_2.u_integer, raw_data_3.u_integer, raw_data_4.u_integer,
                                 int_ext_temp, SPEED_PREBLUE_VALUE);
         logbook_save_log(&log);
      }
      /* When the configuration is POTDIFF */
      else
      {
         /* POTDIFF1 log */
         raw_data_1.u_float = s_measures_1_2.v_signal;
         raw_data_4.u_float = shmem.s_potdiff1.s_measure;
         logbook_fill_event_block(&log, FCT_ID_POT1_DIFF, shmem.s_potdiff1.s_fault_word.u_word, exception_context,
                                 raw_data_1.u_integer, SPARE_VALUE, SPARE_VALUE, raw_data_4.u_integer,
                                 int_ext_temp, SPEED_PREBLUE_VALUE);
         logbook_save_log(&log);
      }
   }
   /* When the channel is B */
   else
   {
      /* When the configuration is POT */
      if (POT_CONFIGURATION == oss_conf->s_pot2_sensor_type)
      {
         /* POT2 log */
         raw_data_1.u_float = s_measures_1_2.v_signal;
         raw_data_2.u_float = s_measures_1_2.v_exc;
         raw_data_3.u_float = s_measures_1_2.v_low_side;
         raw_data_4.u_float = shmem.s_pot2.s_measure;
         logbook_fill_event_block(&log, FCT_ID_POT2, shmem.s_pot2.s_fault_word.u_word, exception_context,
                                 raw_data_1.u_integer, raw_data_2.u_integer, raw_data_3.u_integer, raw_data_4.u_integer,
                                 int_ext_temp, SPEED_PREBLUE_VALUE);
         logbook_save_log(&log);
      }
      /* When the configuration is POTDIFF */
      else
      {
         /* POTDIFF2 log */
         raw_data_1.u_float = s_measures_1_2.v_signal;
         raw_data_4.u_float = shmem.s_potdiff2.s_measure;
         logbook_fill_event_block(&log, FCT_ID_POT2_DIFF, shmem.s_potdiff2.s_fault_word.u_word, exception_context,
                                 raw_data_1.u_integer, SPARE_VALUE, SPARE_VALUE, raw_data_4.u_integer,
                                 int_ext_temp, SPEED_PREBLUE_VALUE);
         logbook_save_log(&log);
      }

      /* POT3 log */
      raw_data_1.u_float = s_measures_3.v_signal;
      raw_data_2.u_float = s_measures_3.v_exc;
      raw_data_3.u_float = s_measures_3.v_low_side;
      raw_data_4.u_float = shmem.s_pot3.s_measure;
      logbook_fill_event_block(&log, FCT_ID_POT3, shmem.s_pot3.s_fault_word.u_word, exception_context,
                              raw_data_1.u_integer, raw_data_2.u_integer, raw_data_3.u_integer, raw_data_4.u_integer,
                              int_ext_temp, SPEED_PREBLUE_VALUE);
      logbook_save_log(&log);
   }
}

/* ---------- internal operations: ------------------------------------------ */
