/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : <short description of the operations of the .c file>
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "driver/adc_over_spi/ADC_AD7327_CFEX_common.h"
#include "driver/adc_over_spi/ADC_AD7327_HAL_common.h"
#include "libtools/memory/LIB_MEM_public.h"
#include "conf/oss_conf_public.h"
#include "memory/memory_address_public.h"
#include "middleware/vrt/vrt_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* */

void adc_over_spi_configure(const boolean_t channel_is_a)
{
   /* Retrieve configuration data */
   ts_oss_conf_table * pt_oss_conf = (ts_oss_conf_table *)OSS_CONF_START_ADDR;

   LIB_MEM_CPY((int8_t*) applied_adc_over_spi_settings_adc1,
               (int8_t*) (channel_is_a ? ADC_AD7327_CFEX_ADC1_st_cpmb : ADC_AD7327_CFEX_ADC1_st),
               (uint32_t)ADC_AD7327_CFEX_ADC1_SAMPLES_TO_SEND_NB);

   LIB_MEM_CPY((int8_t*) applied_adc_over_spi_settings_adc2,
               (int8_t*) (channel_is_a ? ADC_AD7327_CFEX_ADC2_st_cpmb : ADC_AD7327_CFEX_ADC2_st),
               (uint32_t)ADC_AD7327_CFEX_ADC2_SAMPLES_TO_SEND_NB );

   LIB_MEM_CPY((int8_t*) applied_adc_over_spi_settings_adc3,
               (int8_t*) (channel_is_a ? ADC_AD7327_CFEX_ADC3_st_cpmb : ADC_AD7327_CFEX_ADC3_st),
               (uint32_t)ADC_AD7327_CFEX_ADC3_SAMPLES_TO_SEND_NB );

   /* If the OSS_CONF indicates PT100 configuration mode for the VRT1 */
   if((uint32_t)0 == pt_oss_conf->s_t1_configuration)
   {
      /* Set 0/10V ADC configuration for VRT1_shunt_current_raw acquisition */
      applied_adc_over_spi_settings_adc3[286] = 0x0005D800;

      /* Set -2.5/2.5V ADC configuration for VRT1_voltage_raw acquisition */
      applied_adc_over_spi_settings_adc3[317] = 0x0005D000;
   }

   /* If the OSS_CONF indicates PT100 configuration mode for the VRT2 */
   if((uint32_t)0 == pt_oss_conf->s_t2_configuration)
   {
      /* Set 0/10V ADC configuration for VRT2_shunt_current_raw acquisition */
      applied_adc_over_spi_settings_adc3[371] = 0x0003D800;

      /* Set -2.5/2.5V ADC configuration for VRT2_voltage_raw acquisition */
      applied_adc_over_spi_settings_adc3[402] = 0x0003D000;
   }

   /* If the OSS_CONF indicates PT100 configuration mode for the VRTFF */
   if((uint32_t)0 == pt_oss_conf->s_tff_configuration)
   {
      /* Set -2.5/2.5V ADC configuration for VRTFF_voltage_raw acquisition */
      applied_adc_over_spi_settings_adc3[433] = 0x0003D000;

      /* Set 0/10V ADC configuration for VRTFF_shunt_current_raw acquisition */
      applied_adc_over_spi_settings_adc3[464] = 0x0003D800;
   }
}

/* ---------- internal operation bodies: ------------------------------------ */
