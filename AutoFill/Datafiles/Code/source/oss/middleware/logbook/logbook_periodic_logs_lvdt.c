/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : logbook_periodic_logs_lvdt function which allows logbook management at
 *               each RTC
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "logbook_public.h"
#include "logbook_private.h"

/* ---------- include required interface: ----------------------------------- */
#include "memory/lib_critical_service_section_def_data.h" /* Access to shared memory */
#include "conf/oss_conf_public.h"

#include "middleware/tecu/tecu_public.h"
#include "middleware/lvdt/lvdt_public.h"

/* ---------- internal define constants: ------------------------------------ */
/* LVDT Type 1 configuration */
#define LVDT_1_CONFIGURATION  ((uint32_t)0)

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-LOGBOOK-0040 */
void logbook_periodic_logs_lvdt(const boolean_t p_channel_is_a)
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
      /* LVDT A log */
      raw_data_1.u_float = lvdt_exc_a;
      raw_data_2.u_float = shmem.s_lvdta.s_vs1_measure;
      raw_data_3.u_float = shmem.s_lvdta.s_vs2_measure;
      raw_data_4.u_float = shmem.s_lvdta.s_measure;
      /* When the configuration is type 1 */
      if (LVDT_1_CONFIGURATION == oss_conf->s_lvdta_exc_freq)
      {
         logbook_fill_event_block(&log, FCT_ID_LVDTA_1, shmem.s_lvdta.s_fault_word.u_word, exception_context,
                                 raw_data_1.u_integer, raw_data_2.u_integer, raw_data_3.u_integer, raw_data_4.u_integer,
                                 int_ext_temp, SPEED_PREBLUE_VALUE);
         logbook_save_log(&log);
      }
      /* When the configuration is type 2 */
      else
      {
         logbook_fill_event_block(&log, FCT_ID_LVDTA_2, shmem.s_lvdta.s_fault_word.u_word, exception_context,
                                 raw_data_1.u_integer, raw_data_2.u_integer, raw_data_3.u_integer, raw_data_4.u_integer,
                                 int_ext_temp, SPEED_PREBLUE_VALUE);
         logbook_save_log(&log);
      }

      /* LVDT C log */
      raw_data_1.u_float = lvdt_exc_c;
      raw_data_2.u_float = shmem.s_lvdtc.s_vs1_measure;
      raw_data_3.u_float = shmem.s_lvdtc.s_vs2_measure;
      raw_data_4.u_float = shmem.s_lvdtc.s_measure;
      /* When the configuration is type 1 */
      if (LVDT_1_CONFIGURATION == oss_conf->s_lvdtc_exc_freq)
      {
         logbook_fill_event_block(&log, FCT_ID_LVDTC_1, shmem.s_lvdtc.s_fault_word.u_word, exception_context,
                                 raw_data_1.u_integer, raw_data_2.u_integer, raw_data_3.u_integer, raw_data_4.u_integer,
                                 int_ext_temp, SPEED_PREBLUE_VALUE);
         logbook_save_log(&log);
      }
      /* When the configuration is type 2 */
      else
      {
         logbook_fill_event_block(&log, FCT_ID_LVDTC_2, shmem.s_lvdtc.s_fault_word.u_word, exception_context,
                                 raw_data_1.u_integer, raw_data_2.u_integer, raw_data_3.u_integer, raw_data_4.u_integer,
                                 int_ext_temp, SPEED_PREBLUE_VALUE);
         logbook_save_log(&log);
      }
   }
   /* When the channel is B */
   else
   {
      /* LVDT B log */
      raw_data_1.u_float = lvdt_exc_b;
      raw_data_2.u_float = shmem.s_lvdtb.s_vs1_measure;
      raw_data_3.u_float = shmem.s_lvdtb.s_vs2_measure;
      raw_data_4.u_float = shmem.s_lvdtb.s_measure;
      /* When the configuration is type 1 */
      if (LVDT_1_CONFIGURATION == oss_conf->s_lvdtb_exc_freq)
      {
         logbook_fill_event_block(&log, FCT_ID_LVDTB_1, shmem.s_lvdtb.s_fault_word.u_word, exception_context,
                                 raw_data_1.u_integer, raw_data_2.u_integer, raw_data_3.u_integer, raw_data_4.u_integer,
                                 int_ext_temp, SPEED_PREBLUE_VALUE);
         logbook_save_log(&log);
      }
      /* When the configuration is type 2 */
      else
      {
         logbook_fill_event_block(&log, FCT_ID_LVDTB_2, shmem.s_lvdtb.s_fault_word.u_word, exception_context,
                                 raw_data_1.u_integer, raw_data_2.u_integer, raw_data_3.u_integer, raw_data_4.u_integer,
                                 int_ext_temp, SPEED_PREBLUE_VALUE);
         logbook_save_log(&log);
      }
   }
}

/* ---------- internal operations: ------------------------------------------ */
