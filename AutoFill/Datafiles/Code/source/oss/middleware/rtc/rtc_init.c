/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : RTC counter initialization
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/rtc/rtc_public.h"
#include "middleware/rtc/rtc_private.h"

/* ---------- include required interface: ----------------------------------- */
/* #include "memory/lib_critical_service_section_def_data.h" */

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-SCHED-0020 */
/* Implements REQ_FADEX_OS_SRD-SCHED-0090 */
/* Initialize the counter of elapsed RTC */
void rtc_init(void)
{
   /* Local Variable Declaration */
   /* ts_MRAM_counter volatile *       pt_mram_counter; */

   /* Initialization Variable */
   /* pt_mram_counter                  = (ts_MRAM_counter volatile *)MRAM_OSS_CRITICAL_DATA_ADDR; */
   rtc_counter                      = K_RTC_COUNTER_INIT_UINT_32VALUE;

   /* Source code start */
   /* TODO - Just for test, TBD */
   /* Initialized MRAM area to 0 */
   /* pt_mram_counter->s_power_up_count       = K_RTC_COUNTER_INIT_UINT_32VALUE; */
   /* pt_mram_counter->s_first_power_up_time  = K_RTC_COUNTER_INIT_UINT_32VALUE; */

   /* Number of power up since the first power up retrieved from MRAM to the share memory */
   /* shmem.s_oss_counter.s_pw_up_count                               = pt_mram_counter->s_power_up_count ; */

   /* Increasing the number of power up to the share memory */
   /* shmem.s_oss_counter.s_pw_up_count++; */

   /* Retrieve the time in second since the first power up from MRAM to the share memory */
   /* shmem.s_oss_counter.s_first_power_up_time                        = pt_mram_counter->s_first_power_up_time; */

   /* Restart the number of RTC to the share memory */
   /* shmem.s_oss_counter.s_last_power_up_time                         = K_RTC_COUNTER_INIT_UINT_32VALUE; */
   /* shmem.s_oss_counter.s_fast_task_count                            = K_RTC_COUNTER_INIT_UINT_32VALUE; */

   /* Fast task sequence initialization */
   /* shmem.s_oss_counter.s_last_max_ft_time                            = K_RTC_COUNTER_INIT_UINT_32VALUE; */
   /* shmem.s_oss_counter.s_last_max_ft_date.s_first_power_up_time      = pt_mram_counter->s_last_max_ft_date.s_first_power_up_time; */
   /* shmem.s_oss_counter.s_last_max_ft_date.s_last_power_up_time       = K_RTC_COUNTER_INIT_UINT_32VALUE; */
   /* shmem.s_oss_counter.s_last_max_ft_date.s_power_up_count           = K_RTC_COUNTER_INIT_UINT_32VALUE; */

   /* shmem.s_oss_counter.s_max_last_max_ft_time                        = pt_mram_counter->s_max_last_max_ft_time; */
   /* shmem.s_oss_counter.s_max_last_max_ft_date.s_first_power_up_time  = pt_mram_counter->s_max_last_max_ft_date.s_first_power_up_time; */
   /* shmem.s_oss_counter.s_max_last_max_ft_date.s_last_power_up_time   = pt_mram_counter->s_max_last_max_ft_date.s_last_power_up_time; */
   /* shmem.s_oss_counter.s_max_last_max_ft_date.s_power_up_count       = pt_mram_counter->s_max_last_max_ft_date.s_power_up_count; */

   /* Slow task sequence reset */
   /* shmem.s_oss_counter.s_last_max_st_time                            = K_RTC_COUNTER_INIT_UINT_32VALUE; */
   /* shmem.s_oss_counter.s_last_max_st_date.s_first_power_up_time      = pt_mram_counter->s_last_max_st_date.s_first_power_up_time; */
   /* shmem.s_oss_counter.s_last_max_st_date.s_last_power_up_time       = K_RTC_COUNTER_INIT_UINT_32VALUE; */
   /* shmem.s_oss_counter.s_last_max_st_date.s_power_up_count           = K_RTC_COUNTER_INIT_UINT_32VALUE; */

   /* shmem.s_oss_counter.s_max_last_max_st_time                        = pt_mram_counter->s_max_last_max_st_time ; */
   /* shmem.s_oss_counter.s_max_last_max_st_date.s_first_power_up_time  = pt_mram_counter->s_max_last_max_st_date.s_first_power_up_time; */
   /* shmem.s_oss_counter.s_max_last_max_st_date.s_last_power_up_time   = pt_mram_counter->s_max_last_max_st_date.s_last_power_up_time; */
   /* shmem.s_oss_counter.s_max_last_max_st_date.s_power_up_count       = pt_mram_counter->s_max_last_max_st_date.s_power_up_count; */

   /* Very slow task sequence reset */
   /* shmem.s_oss_counter.s_last_max_vst_time                           = K_RTC_COUNTER_INIT_UINT_32VALUE; */
   /* shmem.s_oss_counter.s_last_max_vst_date.s_first_power_up_time     = pt_mram_counter->s_last_max_vst_date.s_first_power_up_time; */
   /* shmem.s_oss_counter.s_last_max_vst_date.s_last_power_up_time      = K_RTC_COUNTER_INIT_UINT_32VALUE; */
   /* shmem.s_oss_counter.s_last_max_vst_date.s_power_up_count          = K_RTC_COUNTER_INIT_UINT_32VALUE; */

   /* shmem.s_oss_counter.s_max_last_max_vst_time                       = pt_mram_counter->s_max_last_max_vst_time ; */
   /* shmem.s_oss_counter.s_max_last_max_vst_date.s_first_power_up_time = pt_mram_counter->s_max_last_max_vst_date.s_first_power_up_time ; */
   /* shmem.s_oss_counter.s_max_last_max_vst_date.s_last_power_up_time  = pt_mram_counter->s_max_last_max_vst_date.s_last_power_up_time ; */
   /* shmem.s_oss_counter.s_max_last_max_vst_date.s_power_up_count      = pt_mram_counter->s_max_last_max_vst_date.s_power_up_count ; */

   /* Background task sequence reset */
   /* shmem.s_oss_counter.s_last_max_bg_time                            = K_RTC_COUNTER_INIT_UINT_32VALUE; */
   /* shmem.s_oss_counter.s_last_max_bg_date.s_first_power_up_time      = pt_mram_counter->s_last_max_bg_date.s_first_power_up_time; */
   /* shmem.s_oss_counter.s_last_max_bg_date.s_last_power_up_time       = K_RTC_COUNTER_INIT_UINT_32VALUE; */
   /* shmem.s_oss_counter.s_last_max_bg_date.s_power_up_count           = K_RTC_COUNTER_INIT_UINT_32VALUE; */

   /* shmem.s_oss_counter.s_max_last_max_bg_time                        = pt_mram_counter->s_max_last_max_bg_time ; */
   /* shmem.s_oss_counter.s_max_last_max_bg_date.s_first_power_up_time  = pt_mram_counter->s_max_last_max_bg_date.s_first_power_up_time ; */
   /* shmem.s_oss_counter.s_max_last_max_bg_date.s_last_power_up_time   = pt_mram_counter->s_max_last_max_bg_date.s_last_power_up_time ; */
   /* shmem.s_oss_counter.s_max_last_max_bg_date.s_power_up_count       = pt_mram_counter->s_max_last_max_bg_date.s_power_up_count ; */

   /* Time execution of the OSS_PU sequence reset */
   /* shmem.s_oss_counter.s_last_max_oa_time                            = K_RTC_COUNTER_INIT_UINT_32VALUE; */
   /* shmem.s_oss_counter.s_max_last_max_oa_time                        = pt_mram_counter->s_max_last_max_oa_time ; */

   /* Initialized the TECU to the share memory */
   /* shmem.s_oss_counter.s_max_tecu                                    = K_RTC_COUNTER_INIT_FLOAT_32VALUE; */

   /* shmem.s_oss_counter.s_max_tecu_date.s_first_power_up_time         = pt_mram_counter->s_max_tecu_date.s_first_power_up_time ; */
   /* shmem.s_oss_counter.s_max_tecu_date.s_last_power_up_time          = pt_mram_counter->s_max_tecu_date.s_last_power_up_time ; */
   /* shmem.s_oss_counter.s_max_tecu_date.s_power_up_count              = pt_mram_counter->s_max_tecu_date.s_power_up_count ; */

   return;
}

/* ---------- internal operations: ------------------------------------------ */
