#include "driver/adc_over_spi/ADC_AD7327_CFEX_common.h"
#include "driver/adc_over_spi/ADC_AD7327_HAL_common.h"
#include "driver/spi/SPI_HAL_public.h"

 void ADC_AD7327_MULTIPLE_WRITE_FRAME_START (const uint32_t adc_conf_id) {    SPI_DMA_WRITE_CMD_DATA_START(ADC_AD7327_CFEX_descriptor_tab[adc_conf_id].spi_conf_id); }
