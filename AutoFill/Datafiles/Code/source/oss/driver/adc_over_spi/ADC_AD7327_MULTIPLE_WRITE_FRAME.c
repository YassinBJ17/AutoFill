#include "driver/adc_over_spi/ADC_AD7327_CFEX_common.h"
#include "driver/adc_over_spi/ADC_AD7327_HAL_common.h"
#include "driver/spi/SPI_HAL_public.h"

 void ADC_AD7327_MULTIPLE_WRITE_FRAME ( const uint32_t            adc_conf_id,                                        const CMN_SYSTEM_ADDR_t   buff_addr,                                        const uint32_t   buff_size,                                        uint32_t * written_size_pt) {    SPI_DMA_WRITE_CMD_DATA(ADC_AD7327_CFEX_descriptor_tab[adc_conf_id].spi_conf_id,                           buff_addr,                           buff_size,                           written_size_pt); }
