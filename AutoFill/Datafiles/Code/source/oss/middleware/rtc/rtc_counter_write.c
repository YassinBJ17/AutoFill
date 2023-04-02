/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Write in MRAM values of RTC counter
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/rtc/rtc_private.h"

/* ---------- include required interface: ----------------------------------- */
#include "memory/lib_critical_service_section_def_data.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-SCHED-0070 */
/* Write in MRAM RTC values of elapsed RTC */
void rtc_counter_write(void)
{
   /* Local Variable Declaration */
   ts_MRAM_counter volatile *              pt_mram_counter;

   /* Initialization Variable */
   pt_mram_counter                         = (ts_MRAM_counter volatile *)MRAM_OSS_CRITICAL_DATA_ADDR ;

   /* Source code start */
   /* number of power up counter */
   pt_mram_counter->s_first_power_up_time  = shmem.s_oss_counter.s_first_power_up_time;
   pt_mram_counter->s_power_up_count       = shmem.s_oss_counter.s_pw_up_count;


   pt_mram_counter->s_ft_count             = shmem.s_oss_counter.s_fast_task_count;
   pt_mram_counter->s_last_max_ft_time     = shmem.s_oss_counter.s_last_max_ft_time;

   /* Fast task sequence upload */

   pt_mram_counter->s_max_last_max_ft_time                       = shmem.s_oss_counter.s_max_last_max_ft_time;
   pt_mram_counter->s_max_last_max_ft_date.s_first_power_up_time = shmem.s_oss_counter.s_max_last_max_ft_date.s_first_power_up_time;
   pt_mram_counter->s_max_last_max_ft_date.s_last_power_up_time  = shmem.s_oss_counter.s_max_last_max_ft_date.s_last_power_up_time;
   pt_mram_counter->s_max_last_max_ft_date.s_power_up_count      = shmem.s_oss_counter.s_max_last_max_ft_date.s_power_up_count;

   /* Slow task sequence upload */

   pt_mram_counter->s_max_last_max_st_time                       = shmem.s_oss_counter.s_max_last_max_st_time;
   pt_mram_counter->s_max_last_max_st_date.s_first_power_up_time = shmem.s_oss_counter.s_max_last_max_st_date.s_first_power_up_time;
   pt_mram_counter->s_max_last_max_st_date.s_last_power_up_time  = shmem.s_oss_counter.s_max_last_max_st_date.s_last_power_up_time;
   pt_mram_counter->s_max_last_max_st_date.s_power_up_count      = shmem.s_oss_counter.s_max_last_max_st_date.s_power_up_count;

   /* Very slow task sequence upload */

   pt_mram_counter->s_max_last_max_vst_time                        = shmem.s_oss_counter.s_max_last_max_vst_time;
   pt_mram_counter->s_max_last_max_vst_date.s_first_power_up_time  = shmem.s_oss_counter.s_max_last_max_vst_date.s_first_power_up_time;
   pt_mram_counter->s_max_last_max_vst_date.s_last_power_up_time   = shmem.s_oss_counter.s_max_last_max_vst_date.s_last_power_up_time;
   pt_mram_counter->s_max_last_max_vst_date.s_power_up_count       = shmem.s_oss_counter.s_max_last_max_vst_date.s_power_up_count;

   /* Background task sequence upload */

   pt_mram_counter->s_max_last_max_bg_time                        = shmem.s_oss_counter.s_max_last_max_bg_time;
   pt_mram_counter->s_max_last_max_bg_date.s_first_power_up_time  = shmem.s_oss_counter.s_max_last_max_bg_date.s_first_power_up_time;
   pt_mram_counter->s_max_last_max_bg_date.s_last_power_up_time   = shmem.s_oss_counter.s_max_last_max_bg_date.s_last_power_up_time;
   pt_mram_counter->s_max_last_max_bg_date.s_power_up_count       = shmem.s_oss_counter.s_max_last_max_bg_date.s_power_up_count;

   /* Time execution of the OSS_PU sequence upload */
   pt_mram_counter->s_max_last_max_oa_time                        = shmem.s_oss_counter.s_max_last_max_oa_time;

   /* Initialized the TECU to the share memory */
   pt_mram_counter->s_max_tecu_date.s_first_power_up_time   = shmem.s_oss_counter.s_max_tecu_date.s_first_power_up_time;
   pt_mram_counter->s_max_tecu_date.s_last_power_up_time    = shmem.s_oss_counter.s_max_tecu_date.s_last_power_up_time;
   pt_mram_counter->s_max_tecu_date.s_power_up_count        = shmem.s_oss_counter.s_max_tecu_date.s_power_up_count;


   return;
}

/* ---------- internal operations: ------------------------------------------ */
