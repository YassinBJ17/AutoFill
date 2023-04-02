/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : mram_periodic function which allows MRAM management at each RTC
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/mram/mram_public.h"

/* ---------- include required interface: ----------------------------------- */
#include "memory/lib_critical_service_section_def_data.h" /* Access to shared memory */
#include "conf/oss_conf_public.h"

#include "middleware/reset/reset_public.h"
#include "middleware/rtc/rtc_public.h"

/* ---------- internal define constants: ------------------------------------ */
/* Value to request DLD at reset */
#define DLD_REQUEST_VALUE           ((uint32_t)0xFADEC000)

/* Period of thermal wear counter computing */
#define THERMAL_WEAR_COUNTER_PERIOD ((uint32_t)36000)

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Data-loading request management, thermal wear counter computation and direct access services */
/* Implements REQ_FADEX_OS_SRD-MRAM-0020 */
/* Implements REQ_FADEX_OS_SRD-MRAM-0040 */
/* Implements REQ_FADEX_OS_SRD-MRAM-0050 */
void mram_periodic(const boolean_t p_channel_is_a)
{
   /* Configuration table */
   const ts_oss_conf_table *oss_conf = (ts_oss_conf_table *)OSS_CONF_START_ADDR;

   /* TECU measure */
   float32_t tecu_measure;
   /* Increment of the thermal wear counter */
   float32_t thermal_wear_counter_inc;

   /* Data-loading request management */
   if ((uint32_t)0 != shmem.s_dld_request)
   {
      /* Decrement the channel mission identifier  */
      mram_oss_critical_data->s_mission_id--;

      /* Request the data-loading mode from the BOOT */
      mram_oss_critical_data->s_dld_request = DLD_REQUEST_VALUE;

      /* Prepare calculator reset */
      reset_critical();
   }

   /* When the CSS_PU request to reset the OSS_PU counters */
   if ((uint32_t)0 != shmem.s_oss_counter_reset)
   {
      /* Reset the OSS PU counters by setting it to 0 */
      mram_oss_critical_data->s_oss_pu_counters.s_max_last_max_ft_time = (uint32_t)0;
      mram_oss_critical_data->s_oss_pu_counters.s_max_last_max_ft_date.s_power_up_count = (uint32_t)0;
      mram_oss_critical_data->s_oss_pu_counters.s_max_last_max_ft_date.s_first_power_up_time = (uint32_t)0;
      mram_oss_critical_data->s_oss_pu_counters.s_max_last_max_ft_date.s_last_power_up_time = (uint32_t)0;

      mram_oss_critical_data->s_oss_pu_counters.s_max_last_max_st_time = (uint32_t)0;
      mram_oss_critical_data->s_oss_pu_counters.s_max_last_max_st_date.s_power_up_count = (uint32_t)0;
      mram_oss_critical_data->s_oss_pu_counters.s_max_last_max_st_date.s_first_power_up_time = (uint32_t)0;
      mram_oss_critical_data->s_oss_pu_counters.s_max_last_max_st_date.s_last_power_up_time = (uint32_t)0;

      mram_oss_critical_data->s_oss_pu_counters.s_max_last_max_vst_time = (uint32_t)0;
      mram_oss_critical_data->s_oss_pu_counters.s_max_last_max_vst_date.s_power_up_count = (uint32_t)0;
      mram_oss_critical_data->s_oss_pu_counters.s_max_last_max_vst_date.s_first_power_up_time = (uint32_t)0;
      mram_oss_critical_data->s_oss_pu_counters.s_max_last_max_vst_date.s_last_power_up_time = (uint32_t)0;

      mram_oss_critical_data->s_oss_pu_counters.s_max_last_max_bg_time = (uint32_t)0;
      mram_oss_critical_data->s_oss_pu_counters.s_max_last_max_bg_date.s_power_up_count = (uint32_t)0;
      mram_oss_critical_data->s_oss_pu_counters.s_max_last_max_bg_date.s_first_power_up_time = (uint32_t)0;
      mram_oss_critical_data->s_oss_pu_counters.s_max_last_max_bg_date.s_last_power_up_time = (uint32_t)0;

      mram_oss_critical_data->s_oss_pu_counters.s_max_last_max_oa_time = (uint32_t)0;

      /* Indicate the request has been taken into account */
      shmem.s_oss_counter_reset = (uint32_t)0;
   }

   /* Every 36000 RTC (first RTC is 1) */
   if ((uint32_t)1 == (rtc_counter % THERMAL_WEAR_COUNTER_PERIOD))
   {
      /* When the channel is A */
      if (p_channel_is_a)
      {
         /* Get the TECU measure of channel A */
         tecu_measure = shmem.s_tecua.s_measure;
      }
      /* When the channel is B */
      else
      {
         /* Get the TECU measure of channel B */
         tecu_measure = shmem.s_tecub.s_measure;
      }

      /* Compute the increment of the thermal wear counter  */
      thermal_wear_counter_inc = oss_conf->s_twear_a + (oss_conf->s_twear_b * tecu_measure);

      /* When thermal_wear_counter_inc is strictly greater than 0 */
      if (0.0f < thermal_wear_counter_inc)
      {
         /* Compute the thermal wear counter */
         shmem.s_oss_counter.s_twear += thermal_wear_counter_inc;
      }
   }
}

/* ---------- internal operations: ------------------------------------------ */
