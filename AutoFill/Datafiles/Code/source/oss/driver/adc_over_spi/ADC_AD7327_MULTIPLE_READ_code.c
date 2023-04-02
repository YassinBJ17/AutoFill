/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : <short description of the operations of the .c file>
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "driver/adc_over_spi/ADC_AD7327_CFEX_common.h"

/* ---------- include required interface: ----------------------------------- */
#include "driver/adc_over_spi/ADC_AD7327_HAL_common.h"
#include "driver/spi/SPI_HAL_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */

/* Used to received data */
void ADC_AD7327_MULTIPLE_READ ( const uint32_t              adc_conf_id,
                                const CMN_SYSTEM_ADDR_t     buff_addr,
                                const uint32_t              buff_size,
                                uint32_t *                  read_size_pt)
{
   /* Read SPI Line */
   SPI_DMA_READ_DATA (ADC_AD7327_CFEX_descriptor_tab[adc_conf_id].spi_conf_id,
                      buff_addr,
                      buff_size,
                      read_size_pt);
}

/* ---------- internal operation bodies: ------------------------------------ */
