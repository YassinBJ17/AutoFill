/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef ADC_OVER_SPI_PRIVATE_H
#define ADC_OVER_SPI_PRIVATE_H

/* ---------- include required interface: ----------------------------------- */
#include "type/common_type.h"

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */

#define AD7327_CONF_1 0
#define AD7327_CONF_2 8
#define AD7327_CONF_3 16

/* ---------- provided types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- provided operations: ------------------------------------------ */

extern void adc_over_spi_configure(const boolean_t channel_is_a);

#endif /* ADC_OVER_SPI_PRIVATE_H */
