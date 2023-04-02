/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef T4_PRIVATE_H
#define T4_PRIVATE_H

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "memory/shared_memory_public.h"

/* ---------- provided define constants: ------------------------------------ */
/* TCJ Resolution used for convertion */
#define TCJ_CONV_RESOLUTION (float32_t)(0.0078125)
/* TCJ offset used of negative TCJ value, float32_t is used because result is float32_t type */
#define TCJ_NEG_OFFSET (float32_t)(512)
/* TCJ limit value betweent positiv and neg values */
/* uint16_t is used because raw_tcj is uint16_t type */
#define RAW_TCJ_LIMIT_VAL (uint16_t)(32768)
/* TCJ filter value for a filter of order 1 with cutoff frequency of 1Hz */
#define TCJ_FILTER_VALUE (float32_t)(0.9391)
/* first n samples ignored for averages */
#define N_SAMPLES_IGNORED (uint32_t)2
/* last m samples ignored for averages */
#define M_SAMPLES_IGNORED (uint32_t)2
/* Total number of sample to acquire */
#define TOTAL_NB_SAMPLES (uint32_t)12
/* Total number of sample to average */
#define NB_SAMPLES_TO_AVG (TOTAL_NB_SAMPLES - N_SAMPLES_IGNORED - M_SAMPLES_IGNORED)
/* SiZE of interpolation table */
#define INTERP_TABLE_SIZE (uint32_t)1643
/* t4 deg value min */
#define T4_DEG_VAL_MIN -270
/* t4 deg value max */
#define T4_DEG_VAL_MAX 1372
/* t4 voltage interp value min */
#define T4_VOLT_VAL_MIN (float32_t)(-6.458)
/* t4 voltage interp value max */
#define T4_VOLT_VAL_MAX (float32_t)(54.886)
/* t4 signal gain */
#define T4_SIG_GAIN (float32_t)(1/142.54)
/* t4 reference gain */
#define T4_REF_GAIN (float32_t)(1/142.54)
/* t4 ground gain */
#define T4_GND_GAIN (float32_t)(1/142.54)
/* t4 Reference voltage */
#define T4_REF_VOLT (float32_t)(0.0675675675)
/* Raw TCJ minimum value deg*/
#define RAW_TCJ_MIN (float32_t)(-50.0)
/* Raw TCJ maximum value deg*/
#define RAW_TCJ_MAX (float32_t)(130.0)
/* T4 signal average minimum value V*/
#define SIG_AVG_MIN (float32_t)(-7.12)
/* T4 signal average maximum value V*/
#define SIG_AVG_MAX (float32_t)(10.0)

/* T4 signal average maximum value mV*/
#define CONV_VOLT_MV (float32_t)(1000.0)

/* T4 signal ADC Gain */
#define T4_ADC_GAIN (float32_t)(142.54)

/* T4 reference average minimum value V*/
#define REF_AVG_MIN (float32_t)(-7.12)
/* T4 reference average maximum value V*/
#define REF_AVG_MAX (float32_t)(10.0)
/* T4 ground average minimum value V*/
#define GND_AVG_MIN (float32_t)(-7.12)
/* T4 ground average maximum value V*/
#define GND_AVG_MAX (float32_t)(10.0)

/* T4 compensated out of range minimum value deg */
#define T4_MEAS_OFR_MIN (float32_t)(-66.0)
/* T4 compensated out of range maximum value deg */
#define T4_MEAS_OFR_MAX (float32_t)(1156.0)

/* T4 compensated open circuit minimum value deg */
#define T4_MEAS_OC_MIN (float32_t)(-80.0)
/* T4 compensated open circuit maximum value deg */
#define T4_MEAS_OC_MAX (float32_t)(1232.0)

#define I2C1_BAUD (uint8_t)0x5B
#define I2C1_IBDR_00 (uint8_t)0x90 /* 10010010 */
#define I2C1_IBDR_01 (uint8_t)0x10010011

/* T4 Mask to only keep error in the status register */
#define TCJ_STATUS_MASK (uint16_t)0xD000
/* ---------- provided types: ----------------------------------------------- */

typedef enum
{
   /* Interpolation with input value in Volt and output value in Degree (T4) */
   e_interp_volt_to_degree = 0,
   /* Interpolation with input value in Degree and output value in Volt (TCJ) */
   e_interp_degree_to_volt = 1        /* Done */
}
te_t4_interp_type;

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* Retain the previous TCJ value */
extern float32_t previous_tcj_value;


/* ---------- provided operations: ------------------------------------------ */
/* T4 interpolation to convert t4 from mV to deg */
void t4_interp(float32_t const t4_volt_value, float32_t * t4_deg_value, te_t4_interp_type type);
/* TCJ and TCJ status acquisition through I2C */
void t4_tcj_get(float32_t * const tcj, ts_temp4 * const shmem_t4);

#endif /* T4_PRIVATE_H */
