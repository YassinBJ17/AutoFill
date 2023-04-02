/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Buffers for ADC7327 acquisition
 * -------------------------------------------------------------------------- */

#include "type/common_type.h"
#include "driver/adc_over_spi/adc_over_spi_public.h"

/* DSPI 1 */
float32_t sg1_sg3_sai1_sai3_sig       [ADC_OVER_SPI_COUNT];
float32_t sg1_sg3_sg4_sai1_sai3_gnd   [ADC_OVER_SPI_COUNT];
float32_t sg1_sg3_sg4_sai1_sai3_exc   [ADC_OVER_SPI_COUNT];
float32_t sg4_sig                     [ADC_OVER_SPI_COUNT];

/* DSPI2 */
float32_t sg2_sai2_sig                [ADC_OVER_SPI_COUNT];
float32_t sg2_sg5b_sai2_sai4_gnd      [ADC_OVER_SPI_COUNT];
float32_t sg2_sg5b_sai2_sai4_exc      [ADC_OVER_SPI_COUNT];
float32_t sg5_sai4_sig                [ADC_OVER_SPI_COUNT];

/* DSPI3 */
float32_t p3_sig                      [ADC_OVER_SPI_COUNT];
float32_t p3_gnd                      [ADC_OVER_SPI_COUNT];
float32_t p3_exc                      [ADC_OVER_SPI_COUNT];

/* DSPI1 */
float32_t xr_vsin_raw                 [ADC_OVER_SPI_XR_RAW_COUNT];
float32_t xr_vsin_ref                 [ADC_OVER_SPI_XR_REF_COUNT];
float32_t xr_vsin_gnd                 [ADC_OVER_SPI_XR_GND_COUNT];

float32_t lvdt_a_b_s1_raw             [ADC_OVER_SPI_LVDT_COUNT];
float32_t lvdt_c_s1_raw               [ADC_OVER_SPI_LVDT_COUNT];

/* DSPI2 */
float32_t xr_vcos_raw                 [ADC_OVER_SPI_XR_RAW_COUNT];
float32_t xr_vcos_ref                 [ADC_OVER_SPI_XR_REF_COUNT];
float32_t xr_vcos_gnd                 [ADC_OVER_SPI_XR_GND_COUNT];

float32_t lvdt_a_b_s2_raw             [ADC_OVER_SPI_LVDT_COUNT];
float32_t lvdt_c_s2_raw               [ADC_OVER_SPI_LVDT_COUNT];

/* DSPI3 */
float32_t xr_exc_raw                  [ADC_OVER_SPI_XR_RAW_COUNT];

float32_t lvdt_a_b_exc_raw            [ADC_OVER_SPI_LVDT_COUNT];
float32_t lvdt_c_exc_raw              [ADC_OVER_SPI_LVDT_COUNT];

/* DSPI3 */
float32_t t4_sig                      [ADC_OVER_SPI_COUNT];
float32_t t4_gnd                      [ADC_OVER_SPI_COUNT];
float32_t t4_ref                      [ADC_OVER_SPI_COUNT];

/* DSPI3 */
float32_t vrt1_voltage_raw            [ADC_OVER_SPI_VRT_COUNT];
float32_t vrt1_shunt_curr_raw         [ADC_OVER_SPI_VRT_COUNT];

/* DSPI3 */
float32_t vrt2_voltage_raw            [ADC_OVER_SPI_VRT_COUNT];
float32_t vrt2_shunt_curr_raw         [ADC_OVER_SPI_VRT_COUNT];

/* DSPI3 */
float32_t vrtff_voltage_raw           [ADC_OVER_SPI_VRT_COUNT];
float32_t vrtff_shunt_curr_raw        [ADC_OVER_SPI_VRT_COUNT];

/* DSPI3 */
float32_t gnd_voltage_raw             [ADC_OVER_SPI_VRT_COUNT];

/* DSPI3 */
float32_t pot_signal_1_2_raw          [ADC_OVER_SPI_COUNT];
float32_t pot_exc_1_2_raw             [ADC_OVER_SPI_COUNT];
float32_t pot_gnd_raw                 [ADC_OVER_SPI_COUNT];
float32_t pot_ref_raw                 [ADC_OVER_SPI_COUNT];
float32_t pot_signal_3_raw            [ADC_OVER_SPI_COUNT];
float32_t pot_exc_3_raw               [ADC_OVER_SPI_COUNT];

/* DSPI1 */
float32_t calres_signal_2_4_raw       [ADC_OVER_SPI_CALRES_COUNT];
float32_t calres_ref_2_4_raw          [ADC_OVER_SPI_CALRES_COUNT];
float32_t calres_gnd_2_4_raw          [ADC_OVER_SPI_CALRES_COUNT];

/* DSPI2 */
float32_t calres_signal_1_3_raw       [ADC_OVER_SPI_CALRES_COUNT];
float32_t calres_ref_1_3_raw          [ADC_OVER_SPI_CALRES_COUNT];
float32_t calres_gnd_1_3_raw          [ADC_OVER_SPI_CALRES_COUNT];
