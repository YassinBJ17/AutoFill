/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : VRT averaging and calibrating computation function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "middleware/vrt/vrt_public.h"
#include "middleware/vrt/vrt_private.h"
#include "memory/lib_critical_service_section_def_data.h"
#include "driver/adc_over_spi/adc_over_spi_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */
/* GPDO address */
#define SIUL2_GPDO_64_ADDR        (uint32_t *)0xFFFC01340    /* VRT_T1_PT100_PT1000_N */
#define SIUL2_GPDO_68_ADDR        (uint32_t *)0xFFFC01344    /* VRT_T2_PT100_PT1000_N */
#define SIUL2_GPDO_75_ADDR        (uint32_t *)0xFFFC0134B    /* VRT_TFF_PT100_PT1000_N */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-VRT-0010 */
/* VRTx averaging and calibrating computation function */
void vrt_computation(void)
{

   float32_t vrt1_voltage_raw_sum;        /* Sum of the 12 VRT1 voltage raw samples */
   float32_t vrt1_voltage_shunt_raw_sum;  /* Sum of the 12 VRT1 voltage shunt raw samples */

   float32_t vrt2_voltage_raw_sum;        /* Sum of the 12 VRT2 voltage raw samples */
   float32_t vrt2_voltage_shunt_raw_sum;  /* Sum of the 12 VRT1 voltage shunt raw samples */

   float32_t vrtff_voltage_raw_sum;        /* Sum of the 12 VRTFF voltage raw samples */
   float32_t vrtff_voltage_shunt_raw_sum;  /* Sum of the 12 VRT1 voltage shunt raw samples */

   float32_t gnd_voltage_sum;              /* Sum of the 12 ground voltage acquisition */


   /* iterator for loop */
   uint32_t i;


   /* Initialize the local variables */
   vrt1_voltage_raw_sum = 0;
   vrt2_voltage_raw_sum = 0;
   vrtff_voltage_raw_sum = 0;
   vrt1_voltage_shunt_raw_sum = 0;
   vrt2_voltage_shunt_raw_sum = 0;
   vrtff_voltage_shunt_raw_sum = 0;
   gnd_voltage_sum = 0;

   /* The acquisition of 12 raw samples (voltage/shunt/gnd) VRT is done with SPI3/ADC3 */
   /* Averaging of samples */
   for ( i = N_SAMPLES_IGNORED; i < (TOTAL_NB_SAMPLES - M_SAMPLES_IGNORED); i ++)
   {
      vrt1_voltage_raw_sum += vrt1_voltage_raw[i];            /* Sum of VRT1 voltage raw samples */
      vrt1_voltage_shunt_raw_sum += vrt1_shunt_curr_raw[i];   /* Sum of VRT1 shunt current raw samples */

      vrt2_voltage_raw_sum += vrt2_voltage_raw[i];            /* Sum of VRT2 voltage raw samples */
      vrt2_voltage_shunt_raw_sum += vrt2_shunt_curr_raw[i];   /* Sum of VRT2 shunt current raw samples */

      vrtff_voltage_raw_sum += vrtff_voltage_raw[i];          /* Sum of VRTFF voltage raw samples */
      vrtff_voltage_shunt_raw_sum += vrtff_shunt_curr_raw[i]; /* Sum of VRTFF shunt current raw samples */

      gnd_voltage_sum += gnd_voltage_raw[i];                  /* Sum of ground voltage raw samples */

   }

   /* VRTx voltage average computation */
   vrt1_voltage_avg = (vrt1_voltage_raw_sum / ((float32_t)NB_SAMPLES_TO_AVG)) * VRTX_AOP_GAIN;    /* VRT1 */
   vrt2_voltage_avg = (vrt2_voltage_raw_sum / ((float32_t)NB_SAMPLES_TO_AVG)) * VRTX_AOP_GAIN;    /* VRT2 */
   vrtff_voltage_avg = (vrtff_voltage_raw_sum / ((float32_t)NB_SAMPLES_TO_AVG)) * VRTX_AOP_GAIN; /* VRTFF */

   /* VRTx shunt current average computation */
   /* vrt1_volt_shunt_avg = (vrt1_shunt_curr_avg / ((float32_t)NB_SAMPLES_TO_AVG)) * vrtx_avg_gain; */
   vrt1_volt_shunt_avg = (vrt1_voltage_shunt_raw_sum / ((float32_t)NB_SAMPLES_TO_AVG)) * VRTX_AOP_GAIN; /* T1 */
   vrt2_volt_shunt_avg = (vrt2_voltage_shunt_raw_sum / ((float32_t)NB_SAMPLES_TO_AVG)) * VRTX_AOP_GAIN; /* T2 */
   vrtff_volt_shunt_avg = (vrtff_voltage_shunt_raw_sum / ((float32_t)NB_SAMPLES_TO_AVG)) * VRTX_AOP_GAIN; /* TFF */

   /* VRTx ground voltage average computation */
   gnd_voltage_avg = (gnd_voltage_sum / ((float32_t)NB_SAMPLES_TO_AVG)) * VRTX_AOP_GAIN;

   /**** VRTx calibrated voltage computation ****/
   vrt1_cal_voltage = vrt1_voltage_avg - gnd_voltage_avg;    /* VRT1 */
   vrt2_cal_voltage = vrt2_voltage_avg - gnd_voltage_avg;    /* VRT2 */
   vrtff_cal_voltage = vrtff_voltage_avg - gnd_voltage_avg;   /* VRTFF */

   /**** VRTx shunt calibrated current computation ****/
   vrt1_shunt_cal_current = (vrt1_volt_shunt_avg - gnd_voltage_avg)/VRTX_SHUNT_RESISTOR;      /* VRT1 */
   vrt2_shunt_cal_current = (vrt2_volt_shunt_avg - gnd_voltage_avg)/VRTX_SHUNT_RESISTOR;      /* VRT2 */
   vrtff_shunt_cal_current = (vrtff_volt_shunt_avg - gnd_voltage_avg)/VRTX_SHUNT_RESISTOR;   /* VRTFF */

}

/* ---------- internal operations: ------------------------------------------ */
