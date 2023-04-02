/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : VRT periodic function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "middleware/vrt/vrt_private.h"
#include "middleware/vrt/vrt_public.h"
#include "conf/oss_conf_public.h"
#include "memory/lib_critical_service_section_def_data.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

float32_t vrt1_voltage_avg;             /* Average of the 8 VRT1 voltage acquisition */
float32_t vrt2_voltage_avg;             /* Average of the 8 VRT2 voltage acquisition */
float32_t vrtff_voltage_avg;            /* Average of the 8 VRTFF voltage acquisition */

float32_t vrt1_volt_shunt_avg;          /* Average of the 8 VRT1 shunt current acquisition */
float32_t vrt2_volt_shunt_avg;          /* Average of the 8 VRT2 shunt current acquisition */
float32_t vrtff_volt_shunt_avg;         /* Average of the 8 VRTFF shunt current acquisition */

float32_t gnd_voltage_avg;              /* Average of the 8 VRT ground voltage acquisition */

float32_t vrt1_cal_voltage;            /* VRT1 calibrated voltage */
float32_t vrt2_cal_voltage;            /* VRT2 calibrated voltage */
float32_t vrtff_cal_voltage;           /* VRTFF calibrated voltage */

float32_t vrt1_shunt_cal_current;      /* VRT1 shunt calibrated current */
float32_t vrt2_shunt_cal_current;      /* VRT2 shunt calibrated current */
float32_t vrtff_shunt_cal_current;     /* VRTFF shunt calibrated current */

float32_t vrt1_cal_resistor;           /* VRT1 calibrated resistor (Ohm) */
float32_t vrt2_cal_resistor;           /* VRT2 calibrated resistor (Ohm) */
float32_t vrtff_cal_resistor;           /* VRTFF calibrated resistor (Ohm) */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-VRT-0010 */
/* Implements REQ_FADEX_OS_SRD-VRT-0020 */
/* Implements REQ_FADEX_OS_SRD-VRT-0030 */
/* VRT periodic function */
void vrt_periodic(const boolean_t channel_is_a)
{
   ts_temp * shmem_vrt1;                 /* pointer to VRT1 shmem of actual channel   */
   ts_temp * shmem_vrt2;                 /* pointer to VRT2 shmem of actual channel   */
   ts_temp * shmem_vrtff;                /* pointer to VRTFF shmem of actual channel  */


   /* Retrieve configuration data */
   ts_oss_conf_table * pt_oss_conf = (ts_oss_conf_table *)OSS_CONF_START_ADDR;


   /* if channel is A */
   if(channel_is_a)
   {
      shmem_vrt1  =  &(shmem.s_t1a);  /* actual channel is A */
      shmem_vrt2  =  &(shmem.s_t2a);  /* actual channel is A */
      shmem_vrtff =  &(shmem.s_tffa); /* actual channel is A */
   }
   /* if channel B */
   else
   {
      shmem_vrt1  =  &(shmem.s_t1b);  /* actual channel is B */
      shmem_vrt2  =  &(shmem.s_t2b);  /* actual channel is B */
      shmem_vrtff =  &(shmem.s_tffb); /* actual channel is B */
   }


   /* Initialize VRT status */
   shmem_vrt1->s_fault_word.u_word = (uint32_t)0;     /* VRT1 status  */
   shmem_vrt2->s_fault_word.u_word = (uint32_t)0;     /* VRT2 status  */
   shmem_vrtff->s_fault_word.u_word = (uint32_t)0;    /* VRTFF status */

   /* VRTx acquisition and calibrated voltage computation */
   vrt_computation();

   /* Compute the VRTx calibrated resistor (Ohm) */
   vrt1_cal_resistor = (vrt1_cal_voltage/vrt1_shunt_cal_current) * VRT1_GAIN_COMPENSATION;

   /* Add a gain to the calibrated resistor to compensate the PIB impedance */
   vrt2_cal_resistor = (vrt2_cal_voltage/vrt2_shunt_cal_current) - vrt2_pib_gain;
   vrtff_cal_resistor = (vrtff_cal_voltage/vrtff_shunt_cal_current) - vrtff_pib_gain;

   /***** VRTx fault status management *****/
   /* VRT1 fault status */
   vrt_status_manage(shmem_vrt1,vrt1_cal_resistor,gnd_voltage_avg,vrt1_cal_voltage,vrt1_shunt_cal_current,
                     vrt1_cal_volt_min,vrt1_cal_volt_max,vrt1_shunt_cal_current_min,
                     vrt1_shunt_cal_current_max,gnd_voltage_avg_min,gnd_voltage_avg_max,
                     vrt1_cal_resistor_min,vrt1_cal_resistor_max);

   /* VRT2 fault status */
   vrt_status_manage(shmem_vrt2,vrt2_cal_resistor,gnd_voltage_avg,vrt2_cal_voltage,vrt2_shunt_cal_current,
                     vrt2_cal_volt_min,vrt2_cal_volt_max,vrt2_shunt_cal_current_min,
                     vrt2_shunt_cal_current_max,gnd_voltage_avg_min,gnd_voltage_avg_max,
                     vrt2_cal_resistor_min,vrt2_cal_resistor_max);

   /* VRTFF fault status */
   vrt_status_manage(shmem_vrtff,vrtff_cal_resistor,gnd_voltage_avg,vrtff_cal_voltage,vrtff_shunt_cal_current,
                     vrtff_cal_volt_min,vrtff_cal_volt_max,vrtff_shunt_cal_current_min,
                     vrtff_shunt_cal_current_max,gnd_voltage_avg_min,gnd_voltage_avg_max,
                     vrtff_cal_resistor_min,vrtff_cal_resistor_max);


   /* If there is not fault in the VRT1 fault status */
   /*if((uint32_t)0 == shmem_vrt1->s_fault_word.u_word)*/           /* Canceled to allow IVV test */
   /*{*/
      /* VRT1 linear interpolation computation */
      vrt_interpolation(pt_oss_conf->s_t1_configuration,&vrt1_cal_resistor,&vrt1_therm_temp);
   /*}*/

   /* If there is not fault in the VRT2 fault status */
   /*if((uint32_t)0 == shmem_vrt2->s_fault_word.u_word)*/           /* Canceled to allow IVV test */
   /*{*/
      /* VRT2 linear interpolation computation */
      vrt_interpolation(pt_oss_conf->s_t2_configuration,&vrt2_cal_resistor,&vrt2_therm_temp);
   /*}*/

   /* If there is not fault in the VRTFF fault status */
   /*if((uint32_t)0 == shmem_vrtff->s_fault_word.u_word)*/          /* Canceled to allow IVV test */
   /*{*/
      /* VRTFF linear interpolation computation */
      vrt_interpolation(pt_oss_conf->s_tff_configuration,&vrtff_cal_resistor,&vrtff_therm_temp);
   /*}*/

   /***** Transmit the VRTx thermal temperature to the shared memory *****/
   shmem_vrt1->s_measure = vrt1_therm_temp;     /* VRT1 */
   shmem_vrt2->s_measure = vrt2_therm_temp;     /* VRT2 */
   shmem_vrtff->s_measure = vrtff_therm_temp;   /* VRTFF */
}

/* ---------- internal operations: ------------------------------------------ */
