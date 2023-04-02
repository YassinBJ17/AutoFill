/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Incrementation of RTC counter
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
/* Implements REQ_FADEX_OS_SRD-SCHED-0100 */
/* Reset every counter of elapsed RTC */
void rtc_counter_reset(void)
{
   /* Local Variable Declaration */

   /* Initialization Variable */

   /* Source code start */
   /* TODO - rtc_counter_reset function need to be revised */

   /* Fast task sequence reset */
   shmem.s_oss_counter.s_max_last_max_ft_time                        = K_RTC_COUNTER_INIT_UINT_32VALUE;
   shmem.s_oss_counter.s_max_last_max_ft_date.s_first_power_up_time  = K_RTC_COUNTER_INIT_UINT_32VALUE;
   shmem.s_oss_counter.s_max_last_max_ft_date.s_last_power_up_time   = K_RTC_COUNTER_INIT_UINT_32VALUE;
   shmem.s_oss_counter.s_max_last_max_ft_date.s_power_up_count       = K_RTC_COUNTER_INIT_UINT_32VALUE;

   /* Slow task sequence reset */
   shmem.s_oss_counter.s_max_last_max_st_time                        = K_RTC_COUNTER_INIT_UINT_32VALUE;
   shmem.s_oss_counter.s_max_last_max_st_date.s_first_power_up_time  = K_RTC_COUNTER_INIT_UINT_32VALUE;
   shmem.s_oss_counter.s_max_last_max_st_date.s_last_power_up_time   = K_RTC_COUNTER_INIT_UINT_32VALUE;
   shmem.s_oss_counter.s_max_last_max_st_date.s_power_up_count       = K_RTC_COUNTER_INIT_UINT_32VALUE;

   /* Very slow task sequence reset */
   shmem.s_oss_counter.s_max_last_max_vst_time                       = K_RTC_COUNTER_INIT_UINT_32VALUE;
   shmem.s_oss_counter.s_max_last_max_vst_date.s_first_power_up_time = K_RTC_COUNTER_INIT_UINT_32VALUE;
   shmem.s_oss_counter.s_max_last_max_vst_date.s_last_power_up_time  = K_RTC_COUNTER_INIT_UINT_32VALUE;
   shmem.s_oss_counter.s_max_last_max_vst_date.s_power_up_count      = K_RTC_COUNTER_INIT_UINT_32VALUE;

   /* Background task sequence reset */
   shmem.s_oss_counter.s_max_last_max_bg_time                        = K_RTC_COUNTER_INIT_UINT_32VALUE;
   shmem.s_oss_counter.s_max_last_max_bg_date.s_first_power_up_time  = K_RTC_COUNTER_INIT_UINT_32VALUE;
   shmem.s_oss_counter.s_max_last_max_bg_date.s_last_power_up_time   = K_RTC_COUNTER_INIT_UINT_32VALUE;
   shmem.s_oss_counter.s_max_last_max_bg_date.s_power_up_count       = K_RTC_COUNTER_INIT_UINT_32VALUE;

   /* Time execution of the OSS_PU sequence reset */
   shmem.s_oss_counter.s_max_last_max_oa_time                        = K_RTC_COUNTER_INIT_UINT_32VALUE;

   return;
}

/* ---------- internal operations: ------------------------------------------ */
