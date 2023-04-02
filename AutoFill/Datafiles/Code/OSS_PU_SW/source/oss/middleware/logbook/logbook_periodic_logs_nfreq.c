/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : logbook_periodic_logs_nfreq function which allows logbook management at
 *               each RTC
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "logbook_public.h"
#include "logbook_private.h"

/* ---------- include required interface: ----------------------------------- */
#include "memory/lib_critical_service_section_def_data.h" /* Access to shared memory */
#include "memory/shared_memory_public.h"
#include "middleware/tecu/tecu_public.h"
#include "middleware/nfreq/nfreq_public.h"

/* ---------- internal define constants: ------------------------------------ */
#define NFREQ3_PERIOD_WIDTH   ((uint32_t)2)

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-LOGBOOK-0040 */
void logbook_periodic_logs_nfreq(const boolean_t p_channel_is_a)
{
   /* Event block used for every log */
   ts_event_block log;

   /* Compute exception context */
   const uint32_t exception_context = (uint32_t)0;

   /* Unions used for every raw data [1:4] */
   tu_raw_data    raw_data_1;
   tu_raw_data    raw_data_2;
   tu_raw_data    raw_data_3;
   tu_raw_data    raw_data_4;

   /* Index of first inconsistent period */
   int32_t inconsistency_index;

   /* Pointers on shared memory */
   ts_ngalt  * shmem_ngalt;
   ts_nfreq2 * shmem_nfreq2;
   ts_nfreq3 * shmem_nfreq3;

   /* When the channel is A */
   if (p_channel_is_a)
   {
      shmem_ngalt  = &(shmem.s_ngalt_a);
      shmem_nfreq2 = &(shmem.s_nfreq2_a);
      shmem_nfreq3 = &(shmem.s_nfreq3_a);
   }
   /* When the channel is B */
   else
   {
      shmem_ngalt  = &(shmem.s_ngalt_b);
      shmem_nfreq2 = &(shmem.s_nfreq2_b);
      shmem_nfreq3 = &(shmem.s_nfreq3_b);
   }

   /* NGALT log */
   /* When there was no inconsistency */
   if ((int32_t)-1 == nfreq_inconsistent_index[e_ngalt])
   {
      /* Raw data 1 : last valid period */
      raw_data_1.u_float = shmem_ngalt->s_t_measure[0];
      /* Raw data 2 : first inconsistent period */
      raw_data_2.u_float = 0.0f;
   }
   else
   {
      /* Compute index of first inconsistent period */
      inconsistency_index = shmem_ngalt->s_t_sample_count - nfreq_inconsistent_index[e_ngalt];
      /* Raw data 1 : last valid period */
      raw_data_1.u_float = shmem_ngalt->s_t_measure[inconsistency_index + (int32_t)1];
      /* Raw data 2 : first inconsistent period */
      raw_data_2.u_float = shmem_ngalt->s_t_measure[inconsistency_index];
   }
   raw_data_4.u_float = shmem_ngalt->s_measure;
   logbook_fill_event_block(&log, FCT_ID_NGALT, shmem_ngalt->s_fault_word.u_word, exception_context,
                           raw_data_1.u_integer, raw_data_2.u_integer, SPARE_VALUE, raw_data_4.u_integer,
                           int_ext_temp, SPEED_PREBLUE_VALUE);
   logbook_save_log(&log);

   /* NFREQ 2 log */
   /* When there was no inconsistency */
   if ((int32_t)-1 == nfreq_inconsistent_index[e_nfreq_2])
   {
      /* Raw data 1 : last valid period */
      raw_data_1.u_float = shmem_nfreq2->s_t_measure[0];
      /* Raw data 2 : first inconsistent period */
      raw_data_2.u_float = 0.0f;
   }
   else
   {
      /* Compute index of first inconsistent period */
      inconsistency_index = shmem_nfreq2->s_t_sample_count - nfreq_inconsistent_index[e_nfreq_2];
      /* Raw data 1 : last valid period */
      raw_data_1.u_float = shmem_nfreq2->s_t_measure[inconsistency_index + (int32_t)1];
      /* Raw data 2 : first inconsistent period */
      raw_data_2.u_float = shmem_nfreq2->s_t_measure[inconsistency_index];
   }
   raw_data_4.u_float = shmem_nfreq2->s_measure;
   logbook_fill_event_block(&log, FCT_ID_NFREQ2, shmem_nfreq2->s_fault_word.u_word, exception_context,
                           raw_data_1.u_integer, raw_data_2.u_integer, SPARE_VALUE, raw_data_4.u_integer,
                           int_ext_temp, SPEED_PREBLUE_VALUE);
   logbook_save_log(&log);

   /* NFREQ 3 log */
   /* When there was no inconsistency */
   if ((int32_t)-1 == nfreq_inconsistent_index[e_nfreq_3])
   {
      /* When there is an even number of period */
      if ((uint32_t)0 == (shmem_nfreq3->s_t_sample_count % NFREQ3_PERIOD_WIDTH))
      {
         /* Raw data 1 : last valid period */
         raw_data_1.u_float = shmem_nfreq3->s_t_measure[0];
      }
      else
      {
         /* Raw data 1 : last valid period */
         raw_data_1.u_float = shmem_nfreq3->s_tpn_measure[0];
      }
      /* Raw data 2 : first inconsistent period */
      raw_data_2.u_float = 0.0f;
   }
   else
   {
      /* Compute index of first inconsistent period */
      inconsistency_index = (shmem_nfreq3->s_t_sample_count - nfreq_inconsistent_index[e_nfreq_3]);
      /* When the index of first inconsistent period is even */
      if ((uint32_t)0 == (inconsistency_index % NFREQ3_PERIOD_WIDTH))
      {
         /* Raw data 1 : last valid period */
         raw_data_1.u_float = shmem_nfreq3->s_tpn_measure[inconsistency_index / NFREQ3_PERIOD_WIDTH];
         /* Raw data 2 : first inconsistent period */
         raw_data_2.u_float = shmem_nfreq3->s_t_measure[inconsistency_index / NFREQ3_PERIOD_WIDTH];
      }
      else
      {
         /* Raw data 1 : last valid period */
         raw_data_1.u_float = shmem_nfreq3->s_t_measure[(inconsistency_index / NFREQ3_PERIOD_WIDTH) + 1];
         /* Raw data 2 : first inconsistent period */
         raw_data_2.u_float = shmem_nfreq3->s_tpn_measure[inconsistency_index / NFREQ3_PERIOD_WIDTH];
      }
   }
   raw_data_3.u_float = shmem_nfreq3->s_ratio;
   raw_data_4.u_float = shmem_nfreq3->s_measure;
   logbook_fill_event_block(&log, FCT_ID_NFREQ3, shmem_nfreq3->s_fault_word.u_word, exception_context,
                           raw_data_1.u_integer, raw_data_2.u_integer, raw_data_3.u_integer, raw_data_4.u_integer,
                           int_ext_temp, SPEED_PREBLUE_VALUE);
   logbook_save_log(&log);

   /* NFREQ 4 log */
   /* When there was no inconsistency */
   if ((int32_t)-1 == nfreq_inconsistent_index[e_nfreq_4])
   {
      /* Raw data 1 : last valid period */
      raw_data_1.u_float = shmem.s_nfreq4.s_t_measure[0];
      /* Raw data 2 : first inconsistent period */
      raw_data_2.u_float = 0.0f;
   }
   else
   {
      /* Compute index of first inconsistent period */
      inconsistency_index = shmem.s_nfreq4.s_t_sample_count - nfreq_inconsistent_index[e_nfreq_4];
      /* Raw data 1 : last valid period */
      raw_data_1.u_float = shmem.s_nfreq4.s_t_measure[inconsistency_index + (int32_t)1];
      /* Raw data 2 : first inconsistent period */
      raw_data_2.u_float = shmem.s_nfreq4.s_t_measure[inconsistency_index];
   }
   raw_data_4.u_float = shmem.s_nfreq4.s_measure;
   logbook_fill_event_block(&log, FCT_ID_NFREQ4, shmem.s_nfreq4.s_fault_word.u_word, exception_context,
                           raw_data_1.u_integer, raw_data_2.u_integer, SPARE_VALUE, raw_data_4.u_integer,
                           int_ext_temp, SPEED_PREBLUE_VALUE);
   logbook_save_log(&log);
}

/* ---------- internal operations: ------------------------------------------ */
