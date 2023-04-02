/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : <short description of the operations of the .c file>
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "type/common_type.h"
#include "driver/adc_over_spi/adc_over_spi_private.h"
#include "driver/adc_over_spi/ADC_AD7327_CFEX_common.h"
#include "driver/spi/SPI_HAL_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */

uint16_t adc_over_spi_rx_buffer_adc_1[ADC_AD7327_CFEX_ADC1_SAMPLES_NB];
uint16_t adc_over_spi_rx_buffer_adc_2[ADC_AD7327_CFEX_ADC2_SAMPLES_NB];
uint16_t adc_over_spi_rx_buffer_adc_3[ADC_AD7327_CFEX_ADC3_SAMPLES_NB];

void adc_over_spi_init_acquisitions(const boolean_t channel_is_a)
{
   uint16_t read_data[2];
   uint32_t read_size;

   /* Select DMA buffers according to channel and conf table  */
   adc_over_spi_configure(channel_is_a);

   /* Read SPI Line */
   SPI_DMA_READ_DATA(ADC_AD7327_CFEX_descriptor_tab[AD7327_CONF_1].spi_conf_id,
                     (CMN_SYSTEM_ADDR_t) &(read_data[0]),
                     4,
                     &read_size);

   /* Read SPI Line */
   SPI_DMA_READ_DATA(ADC_AD7327_CFEX_descriptor_tab[AD7327_CONF_2].spi_conf_id,
                     (CMN_SYSTEM_ADDR_t) &(read_data[0]),
                     4,
                     &read_size);

   /* Read SPI Line */
   SPI_DMA_READ_DATA(ADC_AD7327_CFEX_descriptor_tab[AD7327_CONF_3].spi_conf_id,
                     (CMN_SYSTEM_ADDR_t) &(read_data[0]),
                     4,
                     &read_size);
}

/* ---------- internal operation bodies: ------------------------------------ */
