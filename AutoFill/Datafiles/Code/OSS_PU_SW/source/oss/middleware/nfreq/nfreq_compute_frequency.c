/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION :
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "type/common_type.h"

/* ---------- include required interface: ----------------------------------- */
#include "middleware/nfreq/nfreq_private.h"
#include "middleware/nfreq/nfreq_compute_frequency.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/*  */
/* Implements REQ_FADEX_OS_SRD-FREQUENCY-0030 */
/* Implements REQ_FADEX_OS_SRD-FREQUENCY-0090 */
float32_t nfreq_compute_frequency(ts_nfreq_sensor_info * p_sensor,
                                  te_nfreq_sensor        p_sensor_id)
{
   float32_t   v_measure;
   uint32_t    v_sample_index;
   uint32_t    v_flag_out_of_range;


   /* Determine available samples to process */
   if (p_sensor->s_sample_count >= (p_sensor->s_n_max * p_sensor->s_width))
   {
      p_sensor->s_periods = p_sensor->s_n_max;
   }
   else if (p_sensor->s_sample_count >= (p_sensor->s_n_rev * p_sensor->s_width))
   {
      uint32_t v_nrev_samples;

      v_nrev_samples = p_sensor->s_n_rev * p_sensor->s_width;

      /* get integer number of periods */
      p_sensor->s_periods = (p_sensor->s_sample_count / v_nrev_samples) * p_sensor->s_n_rev;
   }
   else if (p_sensor->s_sample_count >= (p_sensor->s_n_min * p_sensor->s_width))
   {
      p_sensor->s_periods = p_sensor->s_sample_count / p_sensor->s_width;
   }
   else
   {
      p_sensor->s_periods = (uint32_t)0;
   }

   /* Frequency calculation */
   v_measure = (float32_t)0.0;

   if (p_sensor->s_periods > (uint32_t)0)
   {
      /* sum periods samples from most recent to older */
      for (v_sample_index = (uint32_t)1; v_sample_index <= (p_sensor->s_periods * p_sensor->s_width); v_sample_index++)
      {
         v_measure += (float32_t)p_sensor->s_samples[p_sensor->s_sample_count - v_sample_index];
      }

      /* Calculate frequency from sum of periods */
      v_measure = ((float32_t)p_sensor->s_periods) / (v_measure * C_PERIOD_TICK_TO_SEC);

      /* limit calculated measure to valid bounds */
      if (v_measure < p_sensor->s_freq_min)
      {
         v_measure = (float32_t)0.0;
         v_flag_out_of_range = C_SET;
      }
      else if (v_measure > p_sensor->s_freq_max)
      {
         v_measure = p_sensor->s_freq_max;
         v_flag_out_of_range = C_SET;
      }
      else
      {
         v_flag_out_of_range = C_UNSET;
      }

      /* Update Status word */
      if (e_nfreq_3 == p_sensor_id)
         p_sensor->s_status_word.u_bit.s_out_of_range_freq = v_flag_out_of_range;
      else
         p_sensor->s_status_word.u_bit.s_out_of_range = v_flag_out_of_range;
   }

   /* return calculated frequency */
   return v_measure;
}

/* ---------- internal operations: ------------------------------------------ */
