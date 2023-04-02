/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef ADC_OVER_SPI_PUBLIC_H
#define ADC_OVER_SPI_PUBLIC_H

/* ---------- include required interface: ----------------------------------- */
#include "type/common_type.h"

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */

/* Number of raw samples DSPIx */
#define ADC_OVER_SPI_COUNT          12
#define ADC_OVER_SPI_XR_RAW_COUNT   88
#define ADC_OVER_SPI_XR_REF_COUNT   12
#define ADC_OVER_SPI_XR_GND_COUNT   12
#define ADC_OVER_SPI_LVDT_COUNT     88
#define ADC_OVER_SPI_VRT_COUNT      12
#define ADC_OVER_SPI_T4_COUNT       12
#define ADC_OVER_SPI_CALRES_COUNT   16

/* ---------- provided types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* DSPI 1 */
extern float32_t sg1_sg3_sai1_sai3_sig     [ADC_OVER_SPI_COUNT];
extern float32_t sg1_sg3_sg4_sai1_sai3_gnd [ADC_OVER_SPI_COUNT];
extern float32_t sg1_sg3_sg4_sai1_sai3_exc [ADC_OVER_SPI_COUNT];
extern float32_t sg4_sig                   [ADC_OVER_SPI_COUNT];
extern float32_t lvdt_a_b_s1_raw           [ADC_OVER_SPI_LVDT_COUNT];
extern float32_t lvdt_c_s1_raw             [ADC_OVER_SPI_LVDT_COUNT];

/* DSPI2 */
extern float32_t sg2_sai2_sig              [ADC_OVER_SPI_COUNT];
extern float32_t sg2_sg5b_sai2_sai4_gnd    [ADC_OVER_SPI_COUNT];
extern float32_t sg2_sg5b_sai2_sai4_exc    [ADC_OVER_SPI_COUNT];
extern float32_t sg5_sai4_sig              [ADC_OVER_SPI_COUNT];
extern float32_t lvdt_a_b_s2_raw           [ADC_OVER_SPI_LVDT_COUNT];
extern float32_t lvdt_c_s2_raw             [ADC_OVER_SPI_LVDT_COUNT];

/* DSPI3 */
extern float32_t p3_sig                    [ADC_OVER_SPI_COUNT];
extern float32_t p3_gnd                    [ADC_OVER_SPI_COUNT];
extern float32_t p3_exc                    [ADC_OVER_SPI_COUNT];

extern float32_t xr_vsin_raw               [ADC_OVER_SPI_XR_RAW_COUNT];
extern float32_t xr_vsin_ref               [ADC_OVER_SPI_XR_REF_COUNT];
extern float32_t xr_vsin_gnd               [ADC_OVER_SPI_XR_GND_COUNT];

extern float32_t xr_vcos_raw               [ADC_OVER_SPI_XR_RAW_COUNT];
extern float32_t xr_vcos_ref               [ADC_OVER_SPI_XR_REF_COUNT];
extern float32_t xr_vcos_gnd               [ADC_OVER_SPI_XR_GND_COUNT];

extern float32_t xr_exc_raw                [ADC_OVER_SPI_XR_RAW_COUNT];

extern float32_t lvdt_a_b_exc_raw          [ADC_OVER_SPI_LVDT_COUNT];
extern float32_t lvdt_c_exc_raw            [ADC_OVER_SPI_LVDT_COUNT];

extern float32_t t4_sig                    [ADC_OVER_SPI_T4_COUNT];
extern float32_t t4_gnd                    [ADC_OVER_SPI_T4_COUNT];
extern float32_t t4_ref                    [ADC_OVER_SPI_T4_COUNT];

extern float32_t vrt1_voltage_raw          [ADC_OVER_SPI_VRT_COUNT];
extern float32_t vrt1_shunt_curr_raw       [ADC_OVER_SPI_VRT_COUNT];

extern float32_t vrt2_voltage_raw          [ADC_OVER_SPI_VRT_COUNT];
extern float32_t vrt2_shunt_curr_raw       [ADC_OVER_SPI_VRT_COUNT];

extern float32_t vrtff_voltage_raw         [ADC_OVER_SPI_VRT_COUNT];
extern float32_t vrtff_shunt_curr_raw      [ADC_OVER_SPI_VRT_COUNT];

extern float32_t gnd_voltage_raw           [ADC_OVER_SPI_VRT_COUNT];

extern float32_t pot_signal_1_2_raw        [ADC_OVER_SPI_COUNT];
extern float32_t pot_exc_1_2_raw           [ADC_OVER_SPI_COUNT];
extern float32_t pot_gnd_raw               [ADC_OVER_SPI_COUNT];
extern float32_t pot_ref_raw               [ADC_OVER_SPI_COUNT];
extern float32_t pot_signal_3_raw          [ADC_OVER_SPI_COUNT];
extern float32_t pot_exc_3_raw             [ADC_OVER_SPI_COUNT];

extern float32_t calres_signal_2_4_raw     [ADC_OVER_SPI_CALRES_COUNT];
extern float32_t calres_ref_2_4_raw        [ADC_OVER_SPI_CALRES_COUNT];
extern float32_t calres_gnd_2_4_raw        [ADC_OVER_SPI_CALRES_COUNT];
extern float32_t calres_signal_1_3_raw     [ADC_OVER_SPI_CALRES_COUNT];
extern float32_t calres_ref_1_3_raw        [ADC_OVER_SPI_CALRES_COUNT];
extern float32_t calres_gnd_1_3_raw        [ADC_OVER_SPI_CALRES_COUNT];

/* ---------- provided operations: ------------------------------------------ */
extern void adc_over_spi_init_acquisitions(const boolean_t channel_is_a);

extern void adc_over_spi_init_ad7327(void);

extern void adc_over_spi_retrieve_acquired_voltages(void);

extern void adc_over_spi_program_voltages_acquisitions(void);

#endif /* ADC_OVER_SPI_PUBLIC_H */
