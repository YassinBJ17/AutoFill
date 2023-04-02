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
/* Implements REQ_FADEX_OS_SRD-SCHED-0090 */
void rtc_counter_read(
      /* OUTPUT */
      uint32_t* const p_cmd_rst)
{
   /* Local Variable Declaration */
   uint32_t                         v_last_time_rtc;
   uint32_t                         v_delta_time;

   /* Initialization Variable */
   v_last_time_rtc                  = K_RTC_COUNTER_INIT_UINT_32VALUE;

   /* Source code start */
   /* STEP FRIST CYCLE -- If SW start at the first real time cycle */
   if ( K_RTC_COUNTER_INIT_UINT_32VALUE == shmem.s_oss_counter.s_last_power_up_time )
   {
      /* Read FPGA time lapse value to set INIT MODE time in RTC */
      shmem.s_oss_counter.s_last_power_up_time = K_FIRST_COUNTER_INIT_UINT_32VALUE;

   }else
   {
      /* In normal cycle, last_power_up_time rise to RTC */
      v_last_time_rtc                           = shmem.s_oss_counter.s_last_power_up_time ;
      shmem.s_oss_counter.s_last_power_up_time++;
   }

   /* STEP RESET RTC COUNTERS */
   /* In case of CSS_PU request to reset, SHMEM variable shall set to a different value than 0 */
   if ( K_RTC_COUNTER_INIT_UINT_32VALUE != shmem.s_oss_counter_reset )
   {
      /* Send the command to reset */
      *p_cmd_rst                                = K_RESET_UINT_32VALUE;

      /* CSS reset request initialized */
      shmem.s_oss_counter_reset                 = K_RTC_COUNTER_INIT_UINT_32VALUE ;
   }else
   {
      /* STEP READ COUNTER FOR CSS -- Write RTC counter in share memory for CSS */

      /* Compare the present time in RTC to last time converted in second */

      v_delta_time = (uint32_t)(shmem.s_oss_counter.s_last_power_up_time / K_SEC_TO_RTC_CONV_UINT_32VALUE)
                    - (uint32_t)( v_last_time_rtc / K_SEC_TO_RTC_CONV_UINT_32VALUE);

      while ( v_delta_time > 0 )
      {
         /* Increasing time in second since the first power up */
         shmem.s_oss_counter.s_first_power_up_time++;

         /* Decreasing compare time */
         v_delta_time--;
      }
   }

   return;
}

/* ---------- internal operations: ------------------------------------------ */
