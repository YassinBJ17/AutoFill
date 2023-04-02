/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef VRT_PUBLIC_H
#define VRT_PUBLIC_H

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "type/mcp_types.h"
#include "driver/adc_over_spi/ADC_AD7327_CFEX_common.h"

/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* VRT1 thermal temperature (deg) */
extern float32_t vrt1_therm_temp;
/* VRT2 thermal temperature (deg) */
extern float32_t vrt2_therm_temp;
/* VRTFF thermal temperature (deg) */
extern float32_t vrtff_therm_temp;

extern float32_t vrt1_cal_voltage;            /* VRT1 calibrated voltage */
extern float32_t vrt2_cal_voltage;            /* VRT2 calibrated voltage */
extern float32_t vrtff_cal_voltage;           /* VRTFF calibrated voltage */

extern float32_t vrt1_shunt_cal_current;      /* VRT1 shunt calibrated current */
extern float32_t vrt2_shunt_cal_current;      /* VRT2 shunt calibrated current */
extern float32_t vrtff_shunt_cal_current;     /* VRTFF shunt calibrated current */

extern float32_t vrt2_pib_gain;           /* VRT2 PIB gain compensation */
extern float32_t vrtff_pib_gain;          /* VRTFF PIB gain compensation */

/* ---------- provided operations: ------------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-VRT-0020 */
/* Implements REQ_FADEX_OS_SRD-VRT-0030 */
/* VRT intialization function */
void vrt_init(const boolean_t channel_is_a);

/* Implements REQ_FADEX_OS_SRD-VRT-0010 */
/* Implements REQ_FADEX_OS_SRD-VRT-0020 */
/* Implements REQ_FADEX_OS_SRD-VRT-0030 */
/* VRT periodic function */
void vrt_periodic(const boolean_t channel_is_a);

#endif /* VRT_PUBLIC_H */
