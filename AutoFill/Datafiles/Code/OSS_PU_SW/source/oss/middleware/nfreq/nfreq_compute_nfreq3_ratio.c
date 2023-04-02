/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION :
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "type/common_type.h"
#include "memory/memory_address_public.h"
#include "conf/oss_conf_public.h"

/* ---------- include required interface: ----------------------------------- */
#include "middleware/nfreq/nfreq_private.h"
#include "middleware/nfreq/nfreq_compute_nfreq3_ratio.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/*  */
/* Implements REQ_FADEX_OS_SRD-FREQUENCY-0090 */
/* Implements REQ_FADEX_OS_SRD-FREQUENCY-0110 */
float32_t nfreq_compute_nfreq3_ratio(ts_nfreq_sensor_info * p_sensor,
                                     uint32_t               p_period_count)
{
   float32_t           v_measure;
   float32_t           v_sum;
   uint32_t            v_sample_index;
   uint32_t            v_period_loop;
   uint32_t            v_width_loop;
   ts_oss_conf_table * pv_oss_conf = (ts_oss_conf_table *)OSS_CONF_START_ADDR;


   /* Init */
   v_sample_index = p_sensor->s_sample_count - (uint32_t)1;
   v_measure      = (uint32_t)0;
   v_sum          = (uint32_t)0;

   /* parsing process */
   for (v_period_loop = (uint32_t)0; v_period_loop < p_period_count; v_period_loop++)
   {
      v_measure += p_sensor->s_samples[v_sample_index];

      for (v_width_loop = (uint32_t)0; v_width_loop < p_sensor->s_width; v_width_loop++)
      {
         v_sum += p_sensor->s_samples[v_sample_index];
         v_sample_index--;
      }
   }
   /* Calculate frequency from sum of periods */
   v_measure /= v_sum;
   if (v_measure < ((float32_t)pv_oss_conf->s_nfreq3_ratio / (float32_t)100.0))
      v_measure = (float32_t)1.0 - v_measure;

   /* limit calculated measure to valid bounds */
   if (v_measure < C_NFREQ3_LOWER_RATIO)
   {
      v_measure = C_NFREQ3_LOWER_RATIO;
      p_sensor->s_status_word.u_bit.s_out_of_range_duty = C_SET;
   }
   else if (v_measure > C_NFREQ3_UPPER_RATIO)
   {
      v_measure = C_NFREQ3_UPPER_RATIO;
      p_sensor->s_status_word.u_bit.s_out_of_range_duty = C_SET;
   }
   else
   {
      p_sensor->s_status_word.u_bit.s_out_of_range_duty = C_UNSET;
   }

   /* return calculated ratio */
   return v_measure;
}


/* ---------- internal operations: ------------------------------------------ */
