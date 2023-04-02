/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef VRT_PRIVATE_H
#define VRT_PRIVATE_H

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "memory/shared_memory_public.h"


/* ---------- provided define constants: ------------------------------------ */
/******* VRTx ground voltage treshold *******/

/* VRT ground voltage average maximum value (Volt) */
#define GND_AVG_MAX (float32_t)0.05
/* VRT ground voltage average minimum value (Volt) */
#define GND_AVG_MIN (float32_t)-0.05

/******* VRTx calibrated voltage treshold *******/

/* VRT1 calibrated voltage minimum value in PT100 configuration (Volt) */
#define PT100_VRT1_CAL_VOLT_MIN (float32_t)0.150
/* VRT1 calibrated voltage maximum value in PT100 configuration (Volt) */
#define PT100_VRT1_CAL_VOLT_MAX (float32_t)0.500
/* VRT1 calibrated voltage minimum value in PT1000 configuration (Volt) */
#define PT1000_VRT1_CAL_VOLT_MIN (float32_t)0.800
/* VRT1 calibrated voltage maximum value in PT1000 configuration (Volt) */
#define PT1000_VRT1_CAL_VOLT_MAX (float32_t)2.0


/* VRT2 calibrated voltage minimum value in PT100 configuration (Volt) */
#define PT100_VRT2_CAL_VOLT_MIN (float32_t)0.150
/* VRT2 calibrated voltage maximum value in PT100 configuration (Volt) */
#define PT100_VRT2_CAL_VOLT_MAX (float32_t)0.500
/* VRT2 calibrated voltage minimum value in PT1000 configuration (Volt) */
#define PT1000_VRT2_CAL_VOLT_MIN (float32_t)0.800
/* VRT2 calibrated voltage maximum value in PT1000 configuration (Volt) */
#define PT1000_VRT2_CAL_VOLT_MAX (float32_t)2.0


/* VRTFF calibrated voltage minimum value in PT100 configuration (Volt) */
#define PT100_VRTFF_CAL_VOLT_MIN (float32_t)0.150
/* VRTFF calibrated voltage maximum value in PT100 configuration (Volt) */
#define PT100_VRTFF_CAL_VOLT_MAX (float32_t)0.500
/* VRTFF calibrated voltage minimum value in PT1000 configuration (Volt) */
#define PT1000_VRTFF_CAL_VOLT_MIN (float32_t)0.800
/* VRTFF calibrated voltage maximum value in PT1000 configuration (Volt) */
#define PT1000_VRTFF_CAL_VOLT_MAX (float32_t)2.0


/******* VRTx shunt calibrated current treshold *******/

/* VRT1 shunt calibrated current minimum value in PT100 configuration (A) */
#define PT100_VRT1_SHUNT_CAL_CURR_MIN (float32_t)0.0020
/* VRT1 shunt calibrated current maximum value in PT100 configuration (A) */
#define PT100_VRT1_SHUNT_CAL_CURR_MAX (float32_t)0.0031
/* VRT1 shunt calibrated current minimum value in PT1000 configuration (A) */
#define PT1000_VRT1_SHUNT_CAL_CURR_MIN (float32_t)0.0009
/* VRT1 shunt calibrated current maximum value in PT1000 configuration (A) */
#define PT1000_VRT1_SHUNT_CAL_CURR_MAX (float32_t)0.00135


/* VRT2 shunt calibrated current minimum value in PT100 configuration (A) */
#define PT100_VRT2_SHUNT_CAL_CURR_MIN (float32_t)0.0020
/* VRT2 shunt calibrated current maximum value in PT100 configuration (A) */
#define PT100_VRT2_SHUNT_CAL_CURR_MAX (float32_t)0.0031
/* VRT2 shunt calibrated current minimum value in PT1000 configuration (A) */
#define PT1000_VRT2_SHUNT_CAL_CURR_MIN (float32_t)0.0009
/* VRT2 shunt calibrated current maximum value in PT1000 configuration (A) */
#define PT1000_VRT2_SHUNT_CAL_CURR_MAX (float32_t)0.00135


/* VRTFF shunt calibrated current minimum value in PT100 configuration (A) */
#define PT100_VRTFF_SHUNT_CAL_CURR_MIN (float32_t)0.0020
/* VRTFF shunt calibrated current maximum value in PT100 configuration (A) */
#define PT100_VRTFF_SHUNT_CAL_CURR_MAX (float32_t)0.0031
/* VRTFF shunt calibrated current minimum value in PT1000 configuration (A) */
#define PT1000_VRTFF_SHUNT_CAL_CURR_MIN (float32_t)0.0009
/* VRTFF shunt calibrated current maximum value in PT1000 configuration (A) */
#define PT1000_VRTFF_SHUNT_CAL_CURR_MAX (float32_t)0.00135


/* VRTx AOP gain */
#define VRTX_AOP_GAIN (float32_t)(1./3.12)


/* VRTX shunt resistor value (Ohm) */
#define VRTX_SHUNT_RESISTOR (float32_t)450


/* first n samples ignored for averages */
#define N_SAMPLES_IGNORED (uint32_t)2
/* last m samples ignored for averages */
#define M_SAMPLES_IGNORED (uint32_t)2
/* Total number of sample to acquire */
#define TOTAL_NB_SAMPLES (uint32_t)12
/* Total number of sample to average */
#define NB_SAMPLES_TO_AVG (TOTAL_NB_SAMPLES - N_SAMPLES_IGNORED - M_SAMPLES_IGNORED)

/* The size of the interpolation table of PT1000 */
#define INTERP_TABLE_SIZE_PT1000 231.00

/* The size of the interpolation table of PT100 */
#define INTERP_TABLE_SIZE_PT100 250.00

/* The minimum thermal temperature in PT1000 (deg) */
#define THERM_TEMP_MIN_PT1000  -65.00

/* The minimum thermal temperature in PT100 (deg) */
#define THERM_TEMP_MIN_PT100  -84.00

/* No thermal temperature threshold (deg) */
#define THERM_TEMP_NULL 0.00

/* The minimum calibrated resistor value for PT100 configuration */
#define VRT_PT100_RESISTOR_MIN (float32_t)66.30
/* The maximum calibrated resistor value for PT100 configuration */
#define VRT_PT100_RESISTOR_MAX (float32_t)162.8945611

/* The minimum calibrated resistor value for PT1000 configuration */
#define VRT_PT1000_RESISTOR_MIN (float32_t)743.2
/* The maximum calibrated resistor value for PT1000 configuration */
#define VRT_PT1000_RESISTOR_MAX (float32_t)1628.945611

/* The minimum calibrated resistor expected for PT1000 configuration */
#define VRT_PT1000_RESISTOR_MIN_EXPECTED (float32_t)763.2
/* The maximum calibrated resistor expected for PT1000 configuration */
#define VRT_PT1000_RESISTOR_MAX_EXPECTED (float32_t)1610.395489

/* The minimum calibrated resistor expected for PT1000 configuration VRT_T1 */
#define VRT1_PT1000_RESISTOR_MIN_EXPECTED (float32_t)763.2
/* The maximum calibrated resistor expected for PT1000 configuration VRT_T1 */
#define VRT1_PT1000_RESISTOR_MAX_EXPECTED (float32_t)1573.1

/* The minimum calibrated resistor expected for PT100 configuration */
#define VRT_PT100_RESISTOR_MIN_EXPECTED (float32_t)76.32
/* The maximum calibrated resistor expected for PT100 configuration */
#define VRT_PT100_RESISTOR_MAX_EXPECTED (float32_t)161.0395489

/* The minimum calibrated resistor expected for PT100 configuration VRT_T1 */
#define VRT1_PT100_RESISTOR_MIN_EXPECTED (float32_t)67.91
/* The maximum calibrated resistor expected for PT100 configuration VRT_T1 */
#define VRT1_PT100_RESISTOR_MAX_EXPECTED (float32_t)157.31


/* Step between the resistor value of the interpolation table for PT100 configuration */
#define VRT_PT100_STEP (float32_t)((VRT_PT100_RESISTOR_MAX - VRT_PT100_RESISTOR_MIN)/INTERP_TABLE_SIZE_PT100)
/* Step between the resistor value of the interpolation table for PT1000 configuration */
#define VRT_PT1000_STEP (float32_t)((VRT_PT1000_RESISTOR_MAX - VRT_PT1000_RESISTOR_MIN)/INTERP_TABLE_SIZE_PT1000)


#define VRT2A_PIB_GAIN (float32_t)2.61   /* The value of the PIB compensation for VRT2 on channel A (Ohm) */
#define VRT2B_PIB_GAIN (float32_t)2.71   /* The value of the PIB compensation for VRT2 on channel B (Ohm) */
#define VRTFFA_PIB_GAIN (float32_t)2.78   /* The value of the PIB compensation for VRTFF on channel A (Ohm) */
#define VRTFFB_PIB_GAIN (float32_t)1.72   /* The value of the PIB compensation for VRTFF on channel B (Ohm) */

/* The value that should be applicated to VRT1 to correct HW design */
#define VRT1_GAIN_COMPENSATION (float32_t)0.99422396

/* ---------- provided types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

extern float32_t vrt1_voltage_avg;             /* Average of the 8 VRT1 voltage acquisition */
extern float32_t vrt2_voltage_avg;             /* Average of the 8 VRT2 voltage acquisition */
extern float32_t vrtff_voltage_avg;            /* Average of the 8 VRTFF voltage acquisition */

extern float32_t vrt1_volt_shunt_avg;          /* Average of the 8 VRT1 shunt current acquisition */
extern float32_t vrt2_volt_shunt_avg;          /* Average of the 8 VRT2 shunt current acquisition */
extern float32_t vrtff_volt_shunt_avg;         /* Average of the 8 VRTFF shunt current acquisition */

extern float32_t gnd_voltage_avg;              /* Average of the 8 VRT ground voltage acquisition */

extern float32_t vrt1_cal_resistor;           /* VRT1 calibrated resistor (Ohm) */
extern float32_t vrt2_cal_resistor;           /* VRT2 calibrated resistor (Ohm) */
extern float32_t vrtff_cal_resistor;           /* VRTFF calibrated resistor (Ohm) */

extern float32_t vrt1_cal_volt_min;           /* VRT1 calibrated voltage minimum value */
extern float32_t vrt1_cal_volt_max;           /* VRT1 calibrated voltage minimum value */
extern float32_t vrt1_shunt_cal_current_min;  /* VRT1 shunt calibrated current minimum value */
extern float32_t vrt1_shunt_cal_current_max;  /* VRT1 shunt calibrated current maximum value */

extern float32_t vrt2_cal_volt_min;           /* VRT2 calibrated voltage minimum value */
extern float32_t vrt2_cal_volt_max;           /* VRT2 calibrated voltage minimum value */
extern float32_t vrt2_shunt_cal_current_min;  /* VRT2 shunt calibrated current minimum value */
extern float32_t vrt2_shunt_cal_current_max;  /* VRT2 shunt calibrated current maximum value */

extern float32_t vrtff_cal_volt_min;           /* VRTFF calibrated voltage minimum value */
extern float32_t vrtff_cal_volt_max;           /* VRTFF calibrated voltage minimum value */
extern float32_t vrtff_shunt_cal_current_min;  /* VRTFF shunt calibrated current minimum value */
extern float32_t vrtff_shunt_cal_current_max;  /* VRTFF shunt calibrated current maximum value */


extern float32_t gnd_voltage_avg_min;          /* VRT ground voltage average minimum value */
extern float32_t gnd_voltage_avg_max;          /* VRT ground voltage average maximum value */

extern float32_t vrt1_cal_resistor_min;        /* VRT1 calibrated resistor minimum value */
extern float32_t vrt1_cal_resistor_max;        /* VRT1 calibrated resistor maximum value */

extern float32_t vrt2_cal_resistor_min;        /* VRT2 calibrated resistor minimum value */
extern float32_t vrt2_cal_resistor_max;        /* VRT2 calibrated resistor maximum value */

extern float32_t vrtff_cal_resistor_min;        /* VRTFF calibrated resistor minimum value */
extern float32_t vrtff_cal_resistor_max;        /* VRTFF calibrated resistor maximum value */


/* ---------- provided operations: ------------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-VRT-0010 */
/* VRTx acquisition and calibrated voltage computation */
extern void vrt_computation(void);

/* Implements REQ_FADEX_OS_SRD-VRT-0010 */
/* Implements REQ_FADEX_OS_SRD-VRT-0020 */
/* VRTx status management function */
extern void vrt_status_manage(ts_temp* shmem,                                        /* out */
                              float32_t  const  p_vrtx_cal_resistor,                 /* out */
                              float32_t  const  p_gnd_voltage_avg,                   /* in */
                              float32_t  const  p_vrtx_cal_voltage,                  /* in */
                              float32_t  const  p_vrtx_shunt_cal_current,            /* in */
                              float32_t  const  p_vrtx_cal_voltage_min,              /* in */
                              float32_t  const  p_vrtx_cal_voltage_max,              /* in */
                              float32_t  const  p_vrtx_shunt_cal_current_min,        /* in */
                              float32_t  const  p_vrtx_shunt_cal_current_max,        /* in */
                              float32_t  const  p_gnd_voltage_min,                   /* in */
                              float32_t  const  p_gnd_voltage_max,                   /* in */
                              float32_t  const  p_vrtx_cal_resistor_min,             /* in */
                              float32_t  const  p_vrtx_cal_resistor_max);            /* in */

/* Implements REQ_FADEX_OS_SRD-VRT-0020 */
/* VRTx interpolation function (conversion from Ohm to Degree) */
extern void vrt_interpolation(uint32_t  const p_vrtx_oss_config,                     /* in */
                              float32_t *     p_vrtx_cal_resistor,                   /* in */
                              float32_t *     p_vrtx_deg_thermal_temp);              /* out */

#endif /* VRT_PRIVATE_H */
