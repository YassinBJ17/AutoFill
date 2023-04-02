/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef RESOLVER_PRIVATE_H
#define RESOLVER_PRIVATE_H

/* ---------- include required interface: ----------------------------------- */
#include "type/common_type.h"
#include "driver/adc_over_spi/adc_over_spi_public.h"
#include "memory/shared_memory_public.h"

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */
/* xrb vs calres indicator */
#define XRB_IS_ENABLED 1

/* Number of samples to acquire */
#define RESOLVER_SPI_NB_OF_ADC_SAMPLES_RAW        ((uint32_t) 88)
#define RESOLVER_SPI_NB_OF_ADC_SAMPLES_MON        ((uint32_t) 12)

/* Number of samples to ignore */
#define RESOLVER_NB_OF_IGNORED_RAW_SAMPLES_AVG_N  ((uint32_t)2)
#define RESOLVER_NB_OF_IGNORED_RAW_SAMPLES_AVG_M  ((uint32_t)2)
#define RESOLVER_NB_OF_IGNORED_MON_SAMPLES_AVG    ((uint32_t)2)

/* Table for predefined sinus / cosinus */
#define REF_TABLE_SIZE                            (RESOLVER_SPI_NB_OF_ADC_SAMPLES_RAW       - \
                                                   RESOLVER_NB_OF_IGNORED_RAW_SAMPLES_AVG_N - \
                                                   RESOLVER_NB_OF_IGNORED_RAW_SAMPLES_AVG_M)

/* ---------- provided types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */


/* ---------- provided data: ------------------------------------------------ */
/* XR computed values */
extern float32_t xr_vcos;
extern float32_t xr_vsin;
extern float32_t xr_measure;
extern float32_t xr_vcos_measure;
extern float32_t xr_vsin_measure;

/* Average values for vcos/vsin GND and REF */
extern float32_t xr_vcos_ref_avg;
extern float32_t xr_vcos_gnd_avg;
extern float32_t xr_vsin_ref_avg;
extern float32_t xr_vsin_gnd_avg;

/*  Fault word XR */
extern tu_xr_fault_word xr_fault_word;

/* ---------- provided operations: ------------------------------------------ */

/* Compute resolver values from raw data */
extern void resolver_compute_values(float32_t * const xr_exc);

/* Compute fault word */
extern void resolver_compute_fault_word(const boolean_t channel_is_a     ,
                                        float32_t * const voltage_dc_raw ,
                                        float32_t xr_xrb_exc);

#endif /* RESOLVER_PRIVATE_H */
