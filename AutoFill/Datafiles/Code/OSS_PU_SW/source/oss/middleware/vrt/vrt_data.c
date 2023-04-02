/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : VRT global data
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "middleware/vrt/vrt_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* VRT1 thermal temperature (degC) */
float32_t vrt1_therm_temp;
/* VRT2 thermal temperature (degC) */
float32_t vrt2_therm_temp;
/* VRTFF thermal temperature (degC) */
float32_t vrtff_therm_temp;

float32_t vrt1_cal_volt_min;           /* VRT1 calibrated voltage minimum value */
float32_t vrt1_cal_volt_max;           /* VRT1 calibrated voltage minimum value */
float32_t vrt1_shunt_cal_current_min;  /* VRT1 shunt calibrated current minimum value */
float32_t vrt1_shunt_cal_current_max;  /* VRT1 shunt calibrated current maximum value */

float32_t vrt2_cal_volt_min;           /* VRT2 calibrated voltage minimum value */
float32_t vrt2_cal_volt_max;           /* VRT2 calibrated voltage minimum value */
float32_t vrt2_shunt_cal_current_min;  /* VRT2 shunt calibrated current minimum value */
float32_t vrt2_shunt_cal_current_max;  /* VRT2 shunt calibrated current maximum value */

float32_t vrtff_cal_volt_min;           /* VRTFF calibrated voltage minimum value */
float32_t vrtff_cal_volt_max;           /* VRTFF calibrated voltage minimum value */
float32_t vrtff_shunt_cal_current_min;  /* VRTFF shunt calibrated current minimum value */
float32_t vrtff_shunt_cal_current_max;  /* VRTFF shunt calibrated current maximum value */


float32_t gnd_voltage_avg_min;          /* VRT ground voltage average minimum value */
float32_t gnd_voltage_avg_max;          /* VRT ground voltage average maximum value */

float32_t vrt1_cal_resistor_min;        /* VRT1 calibrated resistor minimum value */
float32_t vrt1_cal_resistor_max;        /* VRT1 calibrated resistor maximum value */

float32_t vrt2_cal_resistor_min;        /* VRT2 calibrated resistor minimum value */
float32_t vrt2_cal_resistor_max;        /* VRT2 calibrated resistor maximum value */

float32_t vrtff_cal_resistor_min;        /* VRTFF calibrated resistor minimum value */
float32_t vrtff_cal_resistor_max;        /* VRTFF calibrated resistor maximum value */

float32_t vrt2_pib_gain;                 /* VRT2 PIB gain compensation */
float32_t vrtff_pib_gain;                /* VRTFF PIB gain compensation */


/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */
