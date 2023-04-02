/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : logbook_periodic_logs_p3_sg_sai function which allows logbook management at
 *               each RTC
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "logbook_public.h"
#include "logbook_private.h"

/* ---------- include required interface: ----------------------------------- */
#include "memory/lib_critical_service_section_def_data.h" /* Access to shared memory */
#include "conf/oss_conf_public.h"

#include "middleware/tecu/tecu_public.h"
#include "middleware/sg/sg_public.h"

/* ---------- internal define constants: ------------------------------------ */
/* SG configuration */
#define SG_CONFIGURATION      ((uint32_t)0)

/* Indexes of P3/SG/SAI data */
#define INDEX_P3_A            ((uint32_t)0)
#define INDEX_P3_B            ((uint32_t)1)
#define INDEX_SG1             ((uint32_t)2)
#define INDEX_SG2             ((uint32_t)3)
#define INDEX_SG3             ((uint32_t)4)
#define INDEX_SG4             ((uint32_t)5)
#define INDEX_SG5             ((uint32_t)6)

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-LOGBOOK-0040 */
void logbook_periodic_logs_p3_sg_sai(const boolean_t p_channel_is_a)
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
      /* P3 log */
      raw_data_1.u_float = p3_sg_sai_calibrated_voltage[INDEX_P3_A];
      raw_data_2.u_float = p3_sg_sai_calibrated_voltage_exc[INDEX_P3_A];
      raw_data_3.u_float = p3_sg_sai_ls_current[INDEX_P3_A];
      raw_data_4.u_float = shmem.s_p3_a.s_measure;
      logbook_fill_event_block(&log, FCT_ID_P3, shmem.s_p3_a.s_fault_word.u_word, exception_context,
                              raw_data_1.u_integer, raw_data_2.u_integer, raw_data_3.u_integer, raw_data_4.u_integer,
                              int_ext_temp, SPEED_PREBLUE_VALUE);
      logbook_save_log(&log);

      /* SG1 log */
      raw_data_1.u_float = p3_sg_sai_calibrated_voltage[INDEX_SG1];
      raw_data_2.u_float = p3_sg_sai_calibrated_voltage_exc[INDEX_SG1];
      raw_data_3.u_float = p3_sg_sai_ls_current[INDEX_SG1];
      raw_data_4.u_float = shmem.s_sg1_a.s_measure;
      /* When the configuration is SG */
      if (SG_CONFIGURATION == oss_conf->s_sai1_select)
      {
         /* SG1 log */
         logbook_fill_event_block(&log, FCT_ID_SG1, shmem.s_sg1_a.s_fault_word.u_word, exception_context,
                                 raw_data_1.u_integer, raw_data_2.u_integer, raw_data_3.u_integer, raw_data_4.u_integer,
                                 int_ext_temp, SPEED_PREBLUE_VALUE);
         logbook_save_log(&log);
      }
      /* When the configuration is SAI */
      else
      {
         /* SAI1 log */
         logbook_fill_event_block(&log, FCT_ID_SAI1, shmem.s_sg1_a.s_fault_word.u_word, exception_context,
                                 raw_data_1.u_integer, raw_data_2.u_integer, raw_data_3.u_integer, raw_data_4.u_integer,
                                 int_ext_temp, SPEED_PREBLUE_VALUE);
         logbook_save_log(&log);
      }

      /* SG2 log */
      raw_data_1.u_float = p3_sg_sai_calibrated_voltage[INDEX_SG2];
      raw_data_2.u_float = p3_sg_sai_calibrated_voltage_exc[INDEX_SG2];
      raw_data_3.u_float = p3_sg_sai_ls_current[INDEX_SG2];
      raw_data_4.u_float = shmem.s_sg2_a.s_measure;
      /* When the configuration is SG */
      if (SG_CONFIGURATION == oss_conf->s_sai2_select)
      {
         /* SG2 log */
         logbook_fill_event_block(&log, FCT_ID_SG2, shmem.s_sg2_a.s_fault_word.u_word, exception_context,
                                 raw_data_1.u_integer, raw_data_2.u_integer, raw_data_3.u_integer, raw_data_4.u_integer,
                                 int_ext_temp, SPEED_PREBLUE_VALUE);
         logbook_save_log(&log);
      }
      /* When the configuration is SAI */
      else
      {
         /* SAI2 log */
         logbook_fill_event_block(&log, FCT_ID_SAI2, shmem.s_sg2_a.s_fault_word.u_word, exception_context,
                                 raw_data_1.u_integer, raw_data_2.u_integer, raw_data_3.u_integer, raw_data_4.u_integer,
                                 int_ext_temp, SPEED_PREBLUE_VALUE);
         logbook_save_log(&log);
      }
   }
   /* When the channel is B */
   else
   {
      /* P3 log */
      raw_data_1.u_float = p3_sg_sai_calibrated_voltage[INDEX_P3_B];
      raw_data_2.u_float = p3_sg_sai_calibrated_voltage_exc[INDEX_P3_B];
      raw_data_3.u_float = p3_sg_sai_ls_current[INDEX_P3_B];
      raw_data_4.u_float = shmem.s_p3_b.s_measure;
      logbook_fill_event_block(&log, FCT_ID_P3, shmem.s_p3_b.s_fault_word.u_word, exception_context,
                              raw_data_1.u_integer, raw_data_2.u_integer, raw_data_3.u_integer, raw_data_4.u_integer,
                              int_ext_temp, SPEED_PREBLUE_VALUE);
      logbook_save_log(&log);

      /* SG3 log */
      raw_data_1.u_float = p3_sg_sai_calibrated_voltage[INDEX_SG3];
      raw_data_2.u_float = p3_sg_sai_calibrated_voltage_exc[INDEX_SG3];
      raw_data_3.u_float = p3_sg_sai_ls_current[INDEX_SG3];
      raw_data_4.u_float = shmem.s_sg3_b.s_measure;
      /* When the configuration is SG */
      if (SG_CONFIGURATION == oss_conf->s_sai3_select)
      {
         /* SG3 log */
         logbook_fill_event_block(&log, FCT_ID_SG3, shmem.s_sg3_b.s_fault_word.u_word, exception_context,
                                 raw_data_1.u_integer, raw_data_2.u_integer, raw_data_3.u_integer, raw_data_4.u_integer,
                                 int_ext_temp, SPEED_PREBLUE_VALUE);
         logbook_save_log(&log);
      }
      /* When the configuration is SAI */
      else
      {
         /* SAI3 log */
         logbook_fill_event_block(&log, FCT_ID_SAI3, shmem.s_sg3_b.s_fault_word.u_word, exception_context,
                                 raw_data_1.u_integer, raw_data_2.u_integer, raw_data_3.u_integer, raw_data_4.u_integer,
                                 int_ext_temp, SPEED_PREBLUE_VALUE);
         logbook_save_log(&log);
      }

      /* SG4 log */
      raw_data_1.u_float = p3_sg_sai_calibrated_voltage[INDEX_SG4];
      raw_data_2.u_float = p3_sg_sai_calibrated_voltage_exc[INDEX_SG4];
      raw_data_3.u_float = p3_sg_sai_ls_current[INDEX_SG4];
      raw_data_4.u_float = shmem.s_sg4_b.s_measure;
      logbook_fill_event_block(&log, FCT_ID_SG4, shmem.s_sg4_b.s_fault_word.u_word, exception_context,
                              raw_data_1.u_integer, raw_data_2.u_integer, raw_data_3.u_integer, raw_data_4.u_integer,
                              int_ext_temp, SPEED_PREBLUE_VALUE);
      logbook_save_log(&log);

      /* SG5 log */
      raw_data_1.u_float = p3_sg_sai_calibrated_voltage[INDEX_SG5];
      raw_data_2.u_float = p3_sg_sai_calibrated_voltage_exc[INDEX_SG5];
      raw_data_3.u_float = p3_sg_sai_ls_current[INDEX_SG5];
      raw_data_4.u_float = shmem.s_sg5_b.s_measure;
      /* When the configuration is SG */
      if (SG_CONFIGURATION == oss_conf->s_sai4_select)
      {
         /* SG5 log */
         logbook_fill_event_block(&log, FCT_ID_SG5, shmem.s_sg5_b.s_fault_word.u_word, exception_context,
                                 raw_data_1.u_integer, raw_data_2.u_integer, raw_data_3.u_integer, raw_data_4.u_integer,
                                 int_ext_temp, SPEED_PREBLUE_VALUE);
         logbook_save_log(&log);
      }
      /* When the configuration is SAI */
      else
      {
         /* SAI4 log */
         logbook_fill_event_block(&log, FCT_ID_SAI4, shmem.s_sg5_b.s_fault_word.u_word, exception_context,
                                 raw_data_1.u_integer, raw_data_2.u_integer, raw_data_3.u_integer, raw_data_4.u_integer,
                                 int_ext_temp, SPEED_PREBLUE_VALUE);
         logbook_save_log(&log);
      }
   }
}

/* ---------- internal operations: ------------------------------------------ */
