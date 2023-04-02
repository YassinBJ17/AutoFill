/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : T4 periodic function acquisition and CBIT
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "driver/adc_over_spi/adc_over_spi_public.h"
/* ---------- include required interface: ----------------------------------- */
#include "memory/lib_critical_service_section_def_data.h"
#include "middleware/t4/t4_public.h"
#include "middleware/t4/t4_private.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* Final TCJ value */
float32_t t4_tcj;

/* Average of the 8 T4 signal voltage acquisition */
float32_t t4_sig_voltage_avg;

/* T4 computed voltage */
float32_t t4_voltage_cmp_value;

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-T4-0010 */
/* Implements REQ_FADEX_OS_SRD-T4-0020 */
/* Implements REQ_FADEX_OS_SRD-T4-0030 */
/* Implements REQ_FADEX_OS_SRD-T4-0050 */
/* T4 periodic function acquisition and CBIT */
void t4_periodic(const boolean_t channel_is_a)
{
   ts_temp4 * shmem_t4;         /* pointer to shmem of actual channel   */

   float32_t tcj_in_mv;         /* Final TCJ value in mv (after interpolation) */

   float32_t t4_ref_voltage_avg; /* Average of the 8 T4 reference voltage acquisition */
   float32_t t4_gnd_voltage_avg; /* Average of the 8 T4 ground voltage acquisition */

   float32_t t4_compensated_deg_value; /* Final T4 voltage after TCJ compensation */

   uint32_t i; /* Increment for loop */

   /* variable init */
   t4_sig_voltage_avg = (float32_t)0.0;
   t4_ref_voltage_avg = (float32_t)0.0;
   t4_gnd_voltage_avg = (float32_t)0.0;
   t4_compensated_deg_value = (float32_t)0.0;
   t4_tcj = (float32_t)0.0;
   tcj_in_mv = (float32_t)0.0;

   /* if channel is A */
   if(channel_is_a)
   {
      shmem_t4 = &(shmem.s_t4a); /* actual channel is A */
   }
   /* if channel B */
   else
   {
      shmem_t4 = &(shmem.s_t4b); /* actual channel is B */
   }

   shmem_t4->s_fault_word.u_word = (uint32_t)0;

   /* Acquisition of TCJ via I2C (one measure) value between 0 and 65 535 */
   t4_tcj_get(&t4_tcj, shmem_t4);

   /* The acquisition of 12 Samples of signal / ref and gnd T4 is done with SPI/ADC3 */
   /* Averaging of samples */
   for ( i = N_SAMPLES_IGNORED; i < (TOTAL_NB_SAMPLES - M_SAMPLES_IGNORED); i ++)
   {
      t4_sig_voltage_avg += t4_sig[i]; /* Sum of signal sample */
      t4_ref_voltage_avg += t4_ref[i]; /* Sum of reference sample */
      t4_gnd_voltage_avg += t4_gnd[i]; /* Sum of Ground sample */
   }

   t4_sig_voltage_avg = t4_sig_voltage_avg / ((float32_t)NB_SAMPLES_TO_AVG) ; /* Averaging of signal sample */
   t4_ref_voltage_avg = t4_ref_voltage_avg / ((float32_t)NB_SAMPLES_TO_AVG) ; /* Averaging of reference sample */
   t4_gnd_voltage_avg = t4_gnd_voltage_avg / ((float32_t)NB_SAMPLES_TO_AVG) ; /* Averaging of ground sample */


   /* If T4 signal avg voltage out of range */
   if (t4_sig_voltage_avg < SIG_AVG_MIN || t4_sig_voltage_avg > SIG_AVG_MAX)
   {
      /* Indicate open circuit fault to CSS */
      shmem_t4->s_fault_word.u_bit.s_meas1_oc_fault = (uint32_t)1;
   }
   /* If T4 ref avg voltage out of range */
   if (t4_ref_voltage_avg < REF_AVG_MIN || t4_ref_voltage_avg > REF_AVG_MAX)
   {
      /* Indicate internal failure fault to CSS */
      shmem_t4->s_fault_word.u_bit.s_internal_failure = (uint32_t)1;
   }
   /* If T4 ground avg voltage out of range */
   if (t4_gnd_voltage_avg < GND_AVG_MIN || t4_gnd_voltage_avg > GND_AVG_MAX)
   {
      /* Indicate internal failure fault to CSS */
      shmem_t4->s_fault_word.u_bit.s_internal_failure = (uint32_t)1;
   }

   /* Computation of t4 volatage value */
   t4_voltage_cmp_value =
   ( ((t4_sig_voltage_avg * T4_SIG_GAIN) - (t4_gnd_voltage_avg * T4_GND_GAIN)) /
     ((t4_ref_voltage_avg * T4_REF_GAIN) - (t4_gnd_voltage_avg * T4_GND_GAIN))  ) * T4_REF_VOLT;

   /* Conversion T4 in mV */
   t4_voltage_cmp_value = t4_voltage_cmp_value * CONV_VOLT_MV;

   /* Interpolation of tcj (degree) into mV */
   t4_interp(t4_tcj, &tcj_in_mv, e_interp_degree_to_volt);

   t4_voltage_cmp_value = t4_voltage_cmp_value + tcj_in_mv;

   /* Interpolation of t4 computed voltage into t4 interp table to convert in degree */
   t4_interp(t4_voltage_cmp_value, &t4_compensated_deg_value, e_interp_volt_to_degree);

   /* Perform final range check on compensated T4 */
   /* If T4 Final measure out of range open circuit */
   if (t4_compensated_deg_value < T4_MEAS_OC_MIN || t4_compensated_deg_value > T4_MEAS_OC_MAX)
   {
      /* Indicate open circuit failure fault to CSS */
      shmem_t4->s_fault_word.u_bit.s_meas1_oc_fault = (uint32_t)1;
   }
   /* Else if T4 Final measure out of range */
   else if (t4_compensated_deg_value < T4_MEAS_OFR_MIN || t4_compensated_deg_value > T4_MEAS_OFR_MAX)
   {
      /* Indicate out of range final measure fault to CSS */
      shmem_t4->s_fault_word.u_bit.s_out_of_range = (uint32_t)1;
   }

   /* Check on invalid error and update T4 Status */
   if (shmem_t4->s_fault_word.u_word != (uint32_t)0 )
   {
      /* Indicate that the status is invalid */
      shmem_t4->s_fault_word.u_bit.s_invalid = (uint32_t)1;
   }
   /* Store the T4 measure in SHMEM valid or not */
   shmem_t4->s_measure = t4_compensated_deg_value;


   /* This part is moved to CCDL functionality
   If CCDL unavailable or not
   if (is_ccdl_unavailable == TRUE)
   {
      Set only the unavailable bit of opp ch status word and store
      shmem_t4_opp_ch->s_fault_word.u_word = (uint32_t)0x2;
   }
   Else CCDL available
   else
   {
      TBD TO REMOVE when CCDL driver available acquire t4_compensated_opp_ch and store it
      shmem_t4_opp_ch->s_measure = t4_compensated_deg_value;
   }*/
}

/* ---------- internal operations: ------------------------------------------ */
