/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : logbook_periodic_logs_vrt function which allows logbook management at
 *               each RTC
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "logbook_public.h"
#include "logbook_private.h"

/* ---------- include required interface: ----------------------------------- */
#include "memory/lib_critical_service_section_def_data.h" /* Access to shared memory */
#include "conf/oss_conf_public.h"

#include "middleware/tecu/tecu_public.h"
#include "middleware/vrt/vrt_public.h"

/* ---------- internal define constants: ------------------------------------ */
/* PT100 configuration */
#define PT100_CONFIGURATION   ((uint32_t)0)

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-LOGBOOK-0040 */
void logbook_periodic_logs_vrt(const boolean_t p_channel_is_a)
{
   /* Configuration table */
   const ts_oss_conf_table *oss_conf = (ts_oss_conf_table *)OSS_CONF_START_ADDR;

   /* Event block used for every log */
   ts_event_block log;

   /* Compute exception context */
   const uint32_t exception_context = (uint32_t)0;

   /* Unions used for every raw data [1:4] */
   tu_raw_data    raw_data_2;
   tu_raw_data    raw_data_3;
   tu_raw_data    raw_data_4;

   /* When the channel is A */
   if (p_channel_is_a)
   {
      /* VRT1 log */
      raw_data_2.u_float = vrt1_cal_voltage;
      raw_data_3.u_float = vrt1_shunt_cal_current;
      raw_data_4.u_float = shmem.s_t1a.s_measure;
      /* When the configuration is PT100 */
      if (PT100_CONFIGURATION == oss_conf->s_t1_configuration)
      {
         /* VRT1 log */
         logbook_fill_event_block(&log, FCT_ID_VRT1_PT100, shmem.s_t1a.s_fault_word.u_word, exception_context,
                                 SPARE_VALUE, raw_data_2.u_integer, raw_data_3.u_integer, raw_data_4.u_integer,
                                 int_ext_temp, SPEED_PREBLUE_VALUE);
         logbook_save_log(&log);
      }
      /* When the configuration is PT1000 */
      else
      {
         /* VRT1 log */
         logbook_fill_event_block(&log, FCT_ID_VRT1_PT1000, shmem.s_t1a.s_fault_word.u_word, exception_context,
                                 SPARE_VALUE, raw_data_2.u_integer, raw_data_3.u_integer, raw_data_4.u_integer,
                                 int_ext_temp, SPEED_PREBLUE_VALUE);
         logbook_save_log(&log);
      }

      /* VRT2 log */
      raw_data_2.u_float = vrt2_cal_voltage;
      raw_data_3.u_float = vrt2_shunt_cal_current;
      raw_data_4.u_float = shmem.s_t2a.s_measure;
      /* When the configuration is PT100 */
      if (PT100_CONFIGURATION == oss_conf->s_t2_configuration)
      {
         /* VRT2 log */
         logbook_fill_event_block(&log, FCT_ID_VRT2_PT100, shmem.s_t2a.s_fault_word.u_word, exception_context,
                                 SPARE_VALUE, raw_data_2.u_integer, raw_data_3.u_integer, raw_data_4.u_integer,
                                 int_ext_temp, SPEED_PREBLUE_VALUE);
         logbook_save_log(&log);
      }
      /* When the configuration is PT1000 */
      else
      {
         /* VRT2 log */
         logbook_fill_event_block(&log, FCT_ID_VRT2_PT1000, shmem.s_t2a.s_fault_word.u_word, exception_context,
                                 SPARE_VALUE, raw_data_2.u_integer, raw_data_3.u_integer, raw_data_4.u_integer,
                                 int_ext_temp, SPEED_PREBLUE_VALUE);
         logbook_save_log(&log);
      }

      /* VRTFF log */
      raw_data_2.u_float = vrtff_cal_voltage;
      raw_data_3.u_float = vrtff_shunt_cal_current;
      raw_data_4.u_float = shmem.s_tffa.s_measure;
      /* When the configuration is PT100 */
      if (PT100_CONFIGURATION == oss_conf->s_tff_configuration)
      {
         /* VRTFF log */
         logbook_fill_event_block(&log, FCT_ID_VRTFF_PT100, shmem.s_tffa.s_fault_word.u_word, exception_context,
                                 SPARE_VALUE, raw_data_2.u_integer, raw_data_3.u_integer, raw_data_4.u_integer,
                                 int_ext_temp, SPEED_PREBLUE_VALUE);
         logbook_save_log(&log);
      }
      /* When the configuration is PT1000 */
      else
      {
         /* VRTFF log */
         logbook_fill_event_block(&log, FCT_ID_VRTFF_PT1000, shmem.s_tffa.s_fault_word.u_word, exception_context,
                                 SPARE_VALUE, raw_data_2.u_integer, raw_data_3.u_integer, raw_data_4.u_integer,
                                 int_ext_temp, SPEED_PREBLUE_VALUE);
         logbook_save_log(&log);
      }
   }
   /* When the channel is B */
   else
   {
      /* VRT1 log */
      raw_data_2.u_float = vrt1_cal_voltage;
      raw_data_3.u_float = vrt1_shunt_cal_current;
      raw_data_4.u_float = shmem.s_t1b.s_measure;
      /* When the configuration is PT100 */
      if (PT100_CONFIGURATION == oss_conf->s_t1_configuration)
      {
         /* VRT1 log */
         logbook_fill_event_block(&log, FCT_ID_VRT1_PT100, shmem.s_t1b.s_fault_word.u_word, exception_context,
                                 SPARE_VALUE, raw_data_2.u_integer, raw_data_3.u_integer, raw_data_4.u_integer,
                                 int_ext_temp, SPEED_PREBLUE_VALUE);
         logbook_save_log(&log);
      }
      /* When the configuration is PT1000 */
      else
      {
         /* VRT1 log */
         logbook_fill_event_block(&log, FCT_ID_VRT1_PT1000, shmem.s_t1b.s_fault_word.u_word, exception_context,
                                 SPARE_VALUE, raw_data_2.u_integer, raw_data_3.u_integer, raw_data_4.u_integer,
                                 int_ext_temp, SPEED_PREBLUE_VALUE);
         logbook_save_log(&log);
      }

      /* VRT2 log */
      raw_data_2.u_float = vrt2_cal_voltage;
      raw_data_3.u_float = vrt2_shunt_cal_current;
      raw_data_4.u_float = shmem.s_t2b.s_measure;
      /* When the configuration is PT100 */
      if (PT100_CONFIGURATION == oss_conf->s_t2_configuration)
      {
         /* VRT2 log */
         logbook_fill_event_block(&log, FCT_ID_VRT2_PT100, shmem.s_t2b.s_fault_word.u_word, exception_context,
                                 SPARE_VALUE, raw_data_2.u_integer, raw_data_3.u_integer, raw_data_4.u_integer,
                                 int_ext_temp, SPEED_PREBLUE_VALUE);
         logbook_save_log(&log);
      }
      /* When the configuration is PT1000 */
      else
      {
         /* VRT2 log */
         logbook_fill_event_block(&log, FCT_ID_VRT2_PT1000, shmem.s_t2b.s_fault_word.u_word, exception_context,
                                 SPARE_VALUE, raw_data_2.u_integer, raw_data_3.u_integer, raw_data_4.u_integer,
                                 int_ext_temp, SPEED_PREBLUE_VALUE);
         logbook_save_log(&log);
      }

      /* VRTFF log */
      raw_data_2.u_float = vrtff_cal_voltage;
      raw_data_3.u_float = vrtff_shunt_cal_current;
      raw_data_4.u_float = shmem.s_tffb.s_measure;
      /* When the configuration is PT100 */
      if (PT100_CONFIGURATION == oss_conf->s_tff_configuration)
      {
         /* VRTFF log */
         logbook_fill_event_block(&log, FCT_ID_VRTFF_PT100, shmem.s_tffb.s_fault_word.u_word, exception_context,
                                 SPARE_VALUE, raw_data_2.u_integer, raw_data_3.u_integer, raw_data_4.u_integer,
                                 int_ext_temp, SPEED_PREBLUE_VALUE);
         logbook_save_log(&log);
      }
      /* When the configuration is PT1000 */
      else
      {
         /* VRTFF log */
         logbook_fill_event_block(&log, FCT_ID_VRTFF_PT1000, shmem.s_tffb.s_fault_word.u_word, exception_context,
                                 SPARE_VALUE, raw_data_2.u_integer, raw_data_3.u_integer, raw_data_4.u_integer,
                                 int_ext_temp, SPEED_PREBLUE_VALUE);
         logbook_save_log(&log);
      }
   }
}

/* ---------- internal operations: ------------------------------------------ */
