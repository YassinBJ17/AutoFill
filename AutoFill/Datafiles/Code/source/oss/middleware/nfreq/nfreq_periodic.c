/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION :
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "type/common_type.h"
#include "libtools/memory/LIB_MEM_public.h"
#include "middleware/nfreq/nfreq_public.h"

/* ---------- include required interface: ----------------------------------- */
#include "middleware/nfreq/nfreq_private.h"
#include "middleware/nfreq/nfreq_parse_samples.h"
#include "middleware/nfreq/nfreq_maintain_counter.h"
#include "middleware/nfreq/nfreq_set_power_status.h"
#include "middleware/nfreq/nfreq_compute_frequency.h"
#include "middleware/nfreq/nfreq_compute_nfreq3_ratio.h"
#include "middleware/nfreq/nfreq_shmem_write_measure.h"
#include "middleware/nfreq/nfreq_shmem_write_status.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* Index of first inconsistent period (with 1 the most recent sample) */
int32_t nfreq_inconsistent_index[e_SensorMax];

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/*  */
/* Implements REQ_FADEX_OS_SRD-FREQUENCY-0010 */
/* Implements REQ_FADEX_OS_SRD-FREQUENCY-0030 */
/* Implements REQ_FADEX_OS_SRD-FREQUENCY-0040 */
/* Implements REQ_FADEX_OS_SRD-FREQUENCY-0050 */
/* Implements REQ_FADEX_OS_SRD-FREQUENCY-0060 */
/* Implements REQ_FADEX_OS_SRD-FREQUENCY-0070 */
/* Implements REQ_FADEX_OS_SRD-FREQUENCY-0080 */
/* Implements REQ_FADEX_OS_SRD-FREQUENCY-0090 */
/* Implements REQ_FADEX_OS_SRD-FREQUENCY-0100 */
/* Implements REQ_FADEX_OS_SRD-FREQUENCY-0110 */
/* Implements REQ_FADEX_OS_SRD-FREQUENCY-0120 */
void nfreq_periodic(const boolean_t channel_is_a)
{
   te_nfreq_sensor         v_sensor_index;
   ts_nfreq_sensor_info *  pv_sensor;
   ts_nfreq_registers   *  pv_register;
   ts_nfreq_data        *  pv_rx_data;
   uint32_t                v_loop;

   /* Process all sensors */
   for (v_sensor_index = (te_nfreq_sensor)0; v_sensor_index < e_SensorMax; v_sensor_index++)
   {
      /* Get pointer to current sensor parameters */
      pv_sensor   = &v_nfreq_sensors[v_sensor_index];
      pv_register = (ts_nfreq_registers *)pv_sensor->s_fpga_register;
      pv_rx_data  = (ts_nfreq_data *)pv_sensor->s_fpga_data;

      pv_sensor->s_status_word.u_word = (uint32_t)0;

      /* Update Status word */
      pv_sensor->s_status_word.u_bit.s_freq_overflow      = pv_register->s_status_register.s_overflow;
      pv_sensor->s_status_word.u_bit.s_freq_parity_err    = pv_register->s_status_register.s_parity_error;
      pv_sensor->s_status_word.u_bit.s_freq_inconsistency = (uint32_t)
                       ((v_sensor_index != e_nfreq_3 && pv_register->s_status_register.s_glb_inconsistency_1 == C_SET)
                     || (v_sensor_index == e_nfreq_3 && pv_register->s_status_register.s_glb_inconsistency_2 == C_SET));

      nfreq_set_power_status(channel_is_a, v_sensor_index, pv_sensor);

      /* Process based on data validity */
      if (pv_register->s_status_register.s_parity_error       == C_UNSET
      &&  pv_register->s_status_register.s_overflow           == C_UNSET
      &&  pv_sensor->s_status_word.u_bit.s_freq_inconsistency == C_UNSET
      &&  pv_register->s_status_register.s_sample_number_last > (uint32_t)0)
      {
         /*----------------------*/
         /* Valid data available */
         /*----------------------*/
         uint32_t  v_sample_count;
         int32_t   v_sample_start;
         boolean_t v_consistency;
         float32_t v_measure;

         /* Init parsing */
         v_sample_start = (int32_t)pv_register->s_status_register.s_sample_number_last - (int32_t)1;

         /* Parse rx_data[] from most recent to less recent */
         /* stop when inconsistency, max length or first sample reached */
         nfreq_parse_samples(&v_sample_start,
                             &v_sample_count,
                             &v_consistency,
                             pv_sensor->s_n_max * pv_sensor->s_width,
                             C_CONSISTENT,
                             v_sensor_index,
                             pv_rx_data);

         /* When there is an inconsistency */
         if (C_INCONSISTENT == v_consistency)
         {
            /* Store index of first inconsistent sample in FPGA (with 1 the most recent sample) */
            nfreq_inconsistent_index[v_sensor_index] = v_sample_start;
         }
         else
         {
            /* Store -1 to indicate there is no inconsistency */
            nfreq_inconsistent_index[v_sensor_index] = (int32_t)-1;
         }

         if (v_sample_count < (pv_sensor->s_n_min * pv_sensor->s_width) && v_sample_start >= (int32_t)0)
         {
            /* Inform of inconsistency detection */
            pv_sensor->s_status_word.u_bit.s_freq_inconsistency = C_SET;

            /* Pass over inconsistent samples (from most recent to less recent) */
            nfreq_parse_samples(&v_sample_start,
                                &v_sample_count,
                                &v_consistency,
                                C_NFREQ_MAX_RX_DATA,
                                C_INCONSISTENT,
                                v_sensor_index,
                                pv_rx_data);

            /* Second parsing (from most recent to less recent) previously scanned valid samples are not used */
            /* stop when inconsistency, max length or first sample reached */
            nfreq_parse_samples(&v_sample_start,
                                &v_sample_count,
                                &v_consistency,
                                pv_sensor->s_n_max * pv_sensor->s_width,
                                C_CONSISTENT,
                                v_sensor_index,
                                pv_rx_data);
         }

         /* Index on first useful sample */
         v_sample_start++;

         /* Copy value field of parsed samples */
         for (v_loop = (uint32_t)0; v_loop < v_sample_count; v_loop++)
         {
            pv_sensor->s_samples[pv_sensor->s_sample_count + v_loop] = pv_rx_data[v_sample_start + v_loop].s_period;
         }
         pv_sensor->s_sample_count += v_sample_count;

         /* Check if 1 valid sample at least */
         v_measure = (uint32_t)0;
         if (pv_sensor->s_sample_count > (uint32_t)0)
            v_measure = nfreq_compute_frequency(pv_sensor, v_sensor_index);  /* Calculate measure if enough data */
         else
            pv_sensor->s_periods = (uint32_t)0;

         /* Process current RTC */
         if (pv_sensor->s_periods > (uint32_t)0)
         {
            /* Store calculated value */
            pv_sensor->s_measure_freq = v_measure;

            /* Calculate RatioMeasure for nFreq3 */
            if (e_nfreq_3 == v_sensor_index)
               pv_sensor->s_measure_ratio = nfreq_compute_nfreq3_ratio(pv_sensor, pv_sensor->s_periods);

            /* Finalize operation */
            pv_sensor->s_sample_count     = (uint32_t)0;          /* revoke all stored samples */
            pv_sensor->s_maintain_counter = pv_sensor->s_timeout; /* reset maintain counter */

            pv_sensor->s_status_word.u_bit.s_freq_time_out = C_UNSET;
         }
         else
         {
            /* In case of incoherency: revoke all stored samples */
            if (C_SET == pv_sensor->s_status_word.u_bit.s_freq_inconsistency)
               pv_sensor->s_sample_count = (uint32_t)0;

            /* Inform AS no measure available */
            pv_sensor->s_status_word.u_bit.s_unavailable = C_SET;

            /* Update maintain timeout */
            nfreq_maintain_counter(pv_sensor);
         }
      }
      else
      {
         /*-----------------------*/
         /* Invalid data detected */
         /*-----------------------*/
         /* Inform AS no measure available */
         pv_sensor->s_status_word.u_bit.s_unavailable = C_SET;
         /* Update maintain timeout */
         nfreq_maintain_counter(pv_sensor);

         /* Clear parity error, if any */
         if (pv_register->s_status_register.s_parity_error != C_UNSET)
            pv_register->s_control_register.s_parity_error_ack = C_SET;
      }

      /* Transfer data to shared memory */
      nfreq_shmem_write_status(channel_is_a, v_sensor_index, pv_sensor);
      nfreq_shmem_write_measure(channel_is_a, v_sensor_index, pv_sensor);
   }
}

/* ---------- internal operations: ------------------------------------------ */
