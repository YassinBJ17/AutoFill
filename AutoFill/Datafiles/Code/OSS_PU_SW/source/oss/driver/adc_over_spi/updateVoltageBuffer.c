#include "type/common_type.h"
#include "driver/adc_over_spi/adc_over_spi_private.h"
#include "driver/adc_over_spi/ADC_AD7327_HAL_common.h"
#include "driver/adc_over_spi/ADC_AD7327_CFEX_common.h"
#include "driver/adc_over_spi/adc_over_spi_public.h"
#include "driver/spi/SPI_HAL_public.h"
#include "driver/spi/SPI_CFEX_public.h"
#include "middleware/uod_bypass/uod_bypass_public.h"
#include "conf/oss_conf_public.h"
#include "memory/memory_address_public.h"

 void updateVoltageBuffer(float32_t offset,                    float32_t     maxValue,                    uint32_t      indexStart,                    uint32_t      indexStop,                    uint16_t *    rx,                    float32_t *   rx_voltage,                    uint8_t       incrementInBuffer,                    uint16_t      uod_bypass_value) {    uint32_t rx_voltage_index = 0;    uint32_t iter;    uint16_t val;    if(uod_bypass.enable_bypass_adcOverSpi)    {       for(iter = indexStart ; iter <= indexStop ; iter = iter + incrementInBuffer)       {          val = uod_bypass_value & 0b0001111111111111;          if(val & 0b0001000000000000)          {             rx_voltage[rx_voltage_index] = -((~(val - 1)) & 0b0001111111111111);          }          else          {             rx_voltage[rx_voltage_index] = val;          }          rx_voltage[rx_voltage_index] = offset + rx_voltage[rx_voltage_index] * maxValue / 4096.;          rx_voltage_index++;       }    }    else     {       for(iter = indexStart ; iter <= indexStop ; iter = iter + incrementInBuffer)       {          val = rx[iter] & 0b0001111111111111;          if(val & 0b0001000000000000)          {             rx_voltage[rx_voltage_index] = -((~(val - 1)) & 0b0001111111111111);          }          else          {             rx_voltage[rx_voltage_index] = val;          }          rx_voltage[rx_voltage_index] = offset + rx_voltage[rx_voltage_index] * maxValue / 4096.;          rx_voltage_index++;       }    } }
