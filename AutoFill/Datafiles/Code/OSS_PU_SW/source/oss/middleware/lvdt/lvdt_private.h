/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef LVDT_PRIVATE_H
#define LVDT_PRIVATE_H

/* ---------- include required interface: ----------------------------------- */
#include "type/common_type.h"
#include "driver/adc_over_spi/adc_over_spi_public.h"
#include "memory/shared_memory_public.h"

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */

/* Number of samples to acquire */
#define LVDT_SPI_NB_OF_ADC_SAMPLES_RAW        ((uint32_t) 88)
#define LVDT_SPI_NB_OF_ADC_SAMPLES_MON        ((uint32_t) 12)

/* Number of samples to ignore */
#define LVDT_NB_OF_IGNORED_RAW_SAMPLES_AVG_N  ((uint32_t)2)
#define LVDT_NB_OF_IGNORED_RAW_SAMPLES_AVG_M  ((uint32_t)2)
#define LVDT_NB_OF_IGNORED_MON_SAMPLES_AVG    ((uint32_t)2)

/* Table for predefined sinus / cosinus */
#define REF_TABLE_SIZE                        (LVDT_SPI_NB_OF_ADC_SAMPLES_RAW       - \
                                               LVDT_NB_OF_IGNORED_RAW_SAMPLES_AVG_N - \
                                               LVDT_NB_OF_IGNORED_RAW_SAMPLES_AVG_M)

/* ---------- provided types: ----------------------------------------------- */

/* Thresholds for LVDTs fault word */
typedef struct
{
   float32_t t1;
   float32_t t2;
   float32_t t3;
   float32_t t4;
   float32_t t5;
   float32_t t6;
   float32_t t7;
   float32_t t8;
   float32_t t11;
   float32_t t12;
   float32_t t13;
   float32_t t14;
   float32_t t15;
   float32_t t16;
   float32_t t17;
   float32_t t18;
   float32_t t19;
   float32_t t20;
   float32_t t21;
   float32_t t22;
   float32_t t23;
   float32_t t24;
   float32_t t100;
   float32_t t101;
   float32_t t102;
   float32_t t103;
}
ts_lvdt_fault_word_thresholds;

/* ---------- provided constants: ------------------------------------------- */

#define LVDT_SENSOR_ID_A                      0
#define LVDT_SENSOR_ID_B                      1
#define LVDT_SENSOR_ID_C                      2

/* ---------- provided data: ------------------------------------------------ */
/* LVDT computed values */
extern float32_t lvdt_s1;
extern float32_t lvdt_s2;

/* Average values for s1/s2 GND and REF */
extern float32_t lvdt_s1_ref_avg;
extern float32_t lvdt_s1_gnd_avg;
extern float32_t lvdt_s2_ref_avg;
extern float32_t lvdt_s2_gnd_avg;

/* Thresholds used for fault word computation */
extern ts_lvdt_fault_word_thresholds * lvdt_fault_word_thresholds_lvdtx[3];

/*  Fault words LVDT */
extern tu_lvdt_fault_word lvdt_fault_word;

/* ---------- provided operations: ------------------------------------------ */

/* Init fault word thresholds according to oss conf */
extern void lvdt_init_fault_word_thresholds(void);

/* Initialize sinus generators on SPI */
extern void lvdt_init_configure_exc_frequency(const boolean_t channel_is_a);

/* Compute lvdt values from raw data */
extern void lvdt_compute_values(const boolean_t use_data_from_lvdt_a_or_lvdt_b,
                                float32_t * const lvdt_exc);

/* Compute fault word */
extern void lvdt_compute_fault_word(const boolean_t   use_data_from_lvdt_a_or_lvdt_b,
                                    float32_t * const voltage_lvdt_dc_raw_s1        ,
                                    float32_t * const voltage_lvdt_dc_raw_s2        ,
                                    float32_t         lvdt_exc                      ,
                           const ts_lvdt_fault_word_thresholds * const thresholds);

#endif /* LVDT_PRIVATE_H */
