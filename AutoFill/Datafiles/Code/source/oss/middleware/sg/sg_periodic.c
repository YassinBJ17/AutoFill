/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Sample and consolidate sensors reading
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "type/common_type.h"
#include "middleware/sg/sg_public.h"

/* ---------- include required interface: ----------------------------------- */
#include "middleware/sg/sg_private.h"
#include "middleware/sg/sg_adc_ext_read_avg.h"
#include "middleware/sg/sg_adc_int_read_avg.h"
#include "middleware/sg/sg_get_thresholds.h"
#include "middleware/sg/sg_shmem_write.h"
#include "driver/adc/ADC_HAL_public.h"

/* ---------- internal define constants: ------------------------------------ */
/* Sum of error status flags to be considered as an invalid status */
#define C_MASK_INVALD_STATUS ((uint32_t)0xA0FC0090)

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* Calibrated voltage for P3/SG/SAI for logs */
float32_t p3_sg_sai_calibrated_voltage[C_SENSOR_COUNT];

/* Calibrated voltage excitation for P3/SG/SAI for logs */
float32_t p3_sg_sai_calibrated_voltage_exc[C_SENSOR_COUNT];

/* Low side voltage for P3/SG/SAI for logs */
float32_t p3_sg_sai_ls_current[C_SENSOR_COUNT];

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Sample and consolidate sensors reading, then establish status word for each sensor */
/* Implements REQ_FADEX_OS_SRD-SG-0020 */
/* Implements REQ_FADEX_OS_SRD-SG-0030 */
/* Implements REQ_FADEX_OS_SRD-SG-0050 */
void sg_periodic(void)
{
   uint8_t  v_index;


   /* Start process */
   for (v_index = (uint8_t)0; v_index < C_SENSOR_COUNT; v_index++)
   {
      ts_sg_sensor_info       *pv_sensor;
      ts_sg_fault_word_u_bit  *pv_status;
      const ts_sg_thresholds  *pv_check;


      pv_sensor = &v_sg_sensors[v_index];
      pv_status = &v_sg_sensors[v_index].s_value.s_fault_word.u_bit;
      pv_check  = sg_get_thresholds(v_index);

      pv_sensor->s_value.s_fault_word.u_word = (uint32_t)0;

      if (FALSE == pv_sensor->s_is_other_channel)
      {
         float32_t v_sig_avg_volt;
         float32_t v_gnd_avg_volt;
         float32_t v_lowside_avg_volt;
         float32_t v_exc_avg_volt;
         float32_t v_signal;
         float32_t v_ground;
         float32_t v_excitation;
         float32_t v_lowside_a;
         boolean_t v_flag;


         /*=========================*/
         /* Local values processing */
         /*=========================*/
         /* Sampling + average */
         v_sig_avg_volt     = sg_adc_ext_read_avg(pv_sensor, C_SOURCE_SIGNAL);
         v_gnd_avg_volt     = sg_adc_ext_read_avg(pv_sensor, C_SOURCE_GROUND);
         v_exc_avg_volt     = sg_adc_ext_read_avg(pv_sensor, C_SOURCE_EXCITATION);
         v_lowside_avg_volt = sg_adc_int_read_avg(pv_sensor);

         /* Calculate all needed variables to process measured ratio */
         v_ground     = v_gnd_avg_volt;
         v_signal     = (v_sig_avg_volt * pv_sensor->s_sig_gain) + pv_sensor->s_sig_offset - v_ground;
         v_excitation = v_exc_avg_volt - v_ground;

         if (e_sg5b >= pv_sensor->s_input_id)
         {
            if (e_p3b >= pv_sensor->s_input_id)
            {
               /*------------*/
               /* P3 sensors */
               /*------------*/
               /* Computed voltage Calculation (unit: mV / V) */
               pv_sensor->s_value.s_measure = ((v_signal * C_VOLT_TO_MILLIVOLT) / v_excitation) / ((float32_t)241.0f);
            }
            else
            {
               /*------------*/
               /* SG sensors */
               /*------------*/
               /* Computed voltage Calculation (unit: mV / V) */
               pv_sensor->s_value.s_measure = ((v_signal * C_VOLT_TO_MILLIVOLT) / v_excitation) / ((float32_t)57.0f);
            }
         }
         else
         {
            /*-------------*/
            /* SAI sensors */
            /*-------------*/
            /* Computed voltage Calculation (unit: V) */
            pv_sensor->s_value.s_measure = v_signal;
         }

         /* Mid-range Calculation (unit: A) */
         v_lowside_a = v_lowside_avg_volt * ADC_CONVERT_VALUE / C_LOWSIDE_OHM;

         /* Store signal, excitation and low side voltage for logs */
         p3_sg_sai_calibrated_voltage[v_index] = v_signal;
         p3_sg_sai_calibrated_voltage_exc[v_index] = v_excitation;
         p3_sg_sai_ls_current[v_index] = v_lowside_a;

         /*------------------*/
         /* Statuses setting */
         /* Gnd Voltage checking */
         v_flag = (v_ground < pv_check->s_threshold_1 || v_ground > pv_check->s_threshold_2);
         pv_status->s_out_of_range_gnd = (uint32_t)v_flag;

         /* Signal checking */
         if (e_sg5b >= pv_sensor->s_input_id)
         {
            v_flag = (v_signal < pv_check->s_threshold_4 || v_signal > pv_check->s_threshold_3);
            pv_status->s_open_circuit_sig     = (uint32_t)v_flag;
            pv_status->s_short_to_gnd_sig     = (uint32_t)v_flag;
            pv_status->s_greater_than_max_sig = (uint32_t)v_flag;
         }
         else
         {
            v_flag = (v_signal < pv_check->s_threshold_4);
            pv_status->s_short_to_gnd_sig = (uint32_t)v_flag;

            v_flag = (v_signal > pv_check->s_threshold_3);
            pv_status->s_open_circuit_sig = (uint32_t)v_flag;
         }

         /* Excitation checking */
         v_flag = (v_excitation < pv_check->s_threshold_5 || v_excitation > pv_check->s_threshold_6);
         pv_status->s_greater_than_max_exc = (uint32_t)v_flag;
         /* Low Side Voltage checking */
         v_flag = (v_lowside_a > pv_check->s_threshold_7);
         pv_status->s_short_diff_ls =  (uint32_t)v_flag;

         if (e_sg5b >= pv_sensor->s_input_id)
         {
            /* SG & P3 Sensors */
            v_flag = (v_lowside_a < pv_check->s_threshold_10);
            pv_status->s_short_to_gnd_ls  = (uint32_t)v_flag;
            pv_status->s_open_circuit_exc = (uint32_t)v_flag;
            pv_status->s_short_to_gnd_exc = (uint32_t)v_flag;
         }
         else
         {
            /* SAI Sensors */
            v_flag = (v_lowside_a < pv_check->s_threshold_8);
            pv_status->s_short_to_gnd_ls = (uint32_t)v_flag;

            /* Excitation and Low side */
            v_flag = (v_excitation < pv_check->s_threshold_9 && v_lowside_a < pv_check->s_threshold_10);
            pv_status->s_open_circuit_exc = (uint32_t)v_flag;
            pv_status->s_short_to_gnd_exc = (uint32_t)v_flag;
         }

         /* Computed voltage checking */
         if (e_sg5b >= pv_sensor->s_input_id
         ||  (e_sg5b < pv_sensor->s_input_id && FALSE == pv_status->s_out_of_range_gnd))
         {
            v_flag = (pv_sensor->s_value.s_measure < pv_check->s_threshold_11
                   || pv_sensor->s_value.s_measure > pv_check->s_threshold_12);
            pv_status->s_out_of_range_final = (uint32_t)v_flag;
         }

         /* Check general invalid status */
         v_flag = ((pv_sensor->s_value.s_fault_word.u_word & C_MASK_INVALD_STATUS) != (uint32_t)0);
         pv_status->s_invalid = (uint32_t)v_flag;
      }

      /*======================*/
      /* Shared memory update */
      /*======================*/
/* note: for Blue label, all measures should be written to shared memory */
#if 0
      if (FALSE == (boolean_t)pv_status->s_invalid)
      {
         sg_shmem_write((int32_t)pv_sensor->s_input_id,
                        &pv_sensor->s_value);
      }
#else
      sg_shmem_write((int32_t)pv_sensor->s_input_id,
                     &pv_sensor->s_value);
#endif
   }
}

/* ---------- internal operations: ------------------------------------------ */
