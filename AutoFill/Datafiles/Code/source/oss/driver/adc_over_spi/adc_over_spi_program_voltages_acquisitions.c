/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : <short description of the operations of the .c file>
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "driver/adc_over_spi/adc_over_spi_private.h"
#include "driver/adc_over_spi/ADC_AD7327_HAL_common.h"
#include "driver/adc_over_spi/ADC_AD7327_CFEX_common.h"
#include "driver/spi/SPI_HAL_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */

extern uint16_t adc_over_spi_rx_buffer_adc_1[ADC_AD7327_CFEX_ADC1_SAMPLES_NB];
extern uint16_t adc_over_spi_rx_buffer_adc_2[ADC_AD7327_CFEX_ADC2_SAMPLES_NB];
extern uint16_t adc_over_spi_rx_buffer_adc_3[ADC_AD7327_CFEX_ADC3_SAMPLES_NB];

void adc_over_spi_program_voltages_acquisitions(void)
{
   uint32_t written_size;
   uint32_t read_size;

   /* Read SPI Line */
   SPI_DMA_READ_DATA(ADC_AD7327_CFEX_descriptor_tab[AD7327_CONF_3].spi_conf_id,
                     (CMN_SYSTEM_ADDR_t) adc_over_spi_rx_buffer_adc_3,
                     ADC_AD7327_CFEX_ADC3_SAMPLES_TO_RCV_BUFF,
                     &read_size);

   /* Read SPI Line */
   SPI_DMA_READ_DATA(ADC_AD7327_CFEX_descriptor_tab[AD7327_CONF_2].spi_conf_id,
                     (CMN_SYSTEM_ADDR_t) adc_over_spi_rx_buffer_adc_2,
                     ADC_AD7327_CFEX_ADC2_SAMPLES_TO_RCV_BUFF,
                     &read_size);

   /* Read SPI Line */
   SPI_DMA_READ_DATA(ADC_AD7327_CFEX_descriptor_tab[AD7327_CONF_1].spi_conf_id,
                     (CMN_SYSTEM_ADDR_t) adc_over_spi_rx_buffer_adc_1,
                     ADC_AD7327_CFEX_ADC1_SAMPLES_TO_RCV_BUFF,
                     &read_size);

   /* Start new acquisition */
   ADC_AD7327_MULTIPLE_WRITE_FRAME_HOLD ( AD7327_CONF_3,
                                          (CMN_SYSTEM_ADDR_t) applied_adc_over_spi_settings_adc3,
                                          ADC_AD7327_CFEX_ADC3_SAMPLES_TO_SEND_NB,
                                          &written_size);

   ADC_AD7327_MULTIPLE_WRITE_FRAME_HOLD ( AD7327_CONF_2,
                                          (CMN_SYSTEM_ADDR_t) applied_adc_over_spi_settings_adc2,
                                          ADC_AD7327_CFEX_ADC2_SAMPLES_TO_SEND_NB,
                                          &written_size);

   ADC_AD7327_MULTIPLE_WRITE_FRAME_HOLD ( AD7327_CONF_1,
                                          (CMN_SYSTEM_ADDR_t) applied_adc_over_spi_settings_adc1,
                                          ADC_AD7327_CFEX_ADC1_SAMPLES_TO_SEND_NB,
                                          &written_size);

   ADC_AD7327_MULTIPLE_WRITE_FRAME_START ( AD7327_CONF_3);
   ADC_AD7327_MULTIPLE_WRITE_FRAME_START ( AD7327_CONF_2);
   ADC_AD7327_MULTIPLE_WRITE_FRAME_START ( AD7327_CONF_1);
}

/* ---------- internal operation bodies: ------------------------------------ */
