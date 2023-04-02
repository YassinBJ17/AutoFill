/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : <short description of the operations of the .c file>
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "driver/adc_over_spi/ADC_AD7327_CFEX_common.h"

/* ---------- include required interface: ----------------------------------- */
#include "driver/spi/SPI_HAL_public.h"

/* ---------- internal define constants: ------------------------------------ */
#define ADC_AD7327_SPI_CONF_NOT_USED   0x00
#define ADC_AD7327_SPI_CONF_USED       0x01

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */

void adc_over_spi_init_ad7327(void)
{

   /* Local variable declaration */
   uint16_t adc_line_conf;
   uint16_t adc_cfg;
   uint16_t adc_spi_conf;
   uint16_t adc_spi_used[ADC_AD7327_CFEX_SPI_CONF_MAX];
   uint16_t adc_spi_cfg[ADC_AD7327_CFEX_SPI_CONF_MAX][ADC_AD7327_CFEX_LINE_NB_MAX];
   uint16_t adc_spi_cfg_word;
   uint32_t adc_cfg_ret_size_out;

   /* Initialize the ADC-SPI  table*/
   for ( adc_spi_conf = 0; adc_spi_conf < ADC_AD7327_CFEX_SPI_CONF_MAX; adc_spi_conf++ )
   {
      /* */
      adc_spi_used[adc_spi_conf] = ADC_AD7327_SPI_CONF_NOT_USED;
      /* */
      for( adc_cfg= 0; adc_cfg<ADC_AD7327_CFEX_LINE_NB_MAX ; adc_cfg++ )
      {
         /* */
         adc_spi_cfg[adc_spi_conf][adc_cfg] = 0;
      }
   }

   /* Initialize the ADC descriptor table and configuration table */
   for ( adc_line_conf = 0 ; adc_line_conf < ADC_AD7327_CFEX_CONFIGURATION_SIZE ; adc_line_conf++ )
   {
      /* */
      adc_spi_conf = (uint16_t)ADC_AD7327_CFEX_CONFIGURATION_tab[adc_line_conf].spi_conf_nb;
      /* */
      adc_spi_used[adc_spi_conf] = ADC_AD7327_SPI_CONF_USED;
      /* */
      adc_spi_cfg[adc_spi_conf][ADC_AD7327_CFEX_CONFIGURATION_tab[adc_line_conf].adc_line_nb] =
           (uint16_t)ADC_AD7327_CFEX_CONFIGURATION_tab[adc_line_conf].adc_cfg;

      /* ADC Descriptor init       */
      /* ADC command */
      ADC_AD7327_CFEX_descriptor_tab[adc_line_conf].adc_command =
            (uint16_t)ADC_AD7327_HAL_CMD_WRITE
          | (uint16_t)(ADC_AD7327_CFEX_CONFIGURATION_tab[adc_line_conf].adc_line_nb << ADC_AD7327_CFEX_LINE_SHIFT   )
          | (uint16_t)(ADC_AD7327_CFEX_CONFIGURATION_tab[adc_line_conf].adc_mode    << ADC_AD7327_CFEX_MODE_SHIFT   )
          | (uint16_t)(ADC_AD7327_CFEX_CONFIGURATION_tab[adc_line_conf].adc_coding  << ADC_AD7327_CFEX_CODING_SHIFT )
          | (uint16_t)(ADC_AD7327_CFEX_CONFIGURATION_tab[adc_line_conf].adc_ref     << ADC_AD7327_CFEX_REF_SHIFT    );
      /* SPI conf number */
      ADC_AD7327_CFEX_descriptor_tab[adc_line_conf].spi_conf_id = adc_spi_conf;
   }

   /* Initialize the ADC component with two configuration word */
   for ( adc_spi_conf = 0; adc_spi_conf < ADC_AD7327_CFEX_SPI_CONF_MAX; adc_spi_conf++ )
   {
      /* */
      if ( adc_spi_used[adc_spi_conf] == ADC_AD7327_SPI_CONF_USED )
      {
         /* */
         adc_spi_cfg_word = (uint16_t)0xA000
                     | (uint16_t)((adc_spi_cfg[adc_spi_conf][0] & 0x0003)<<11)
                     | (uint16_t)((adc_spi_cfg[adc_spi_conf][1] & 0x0003)<<9)
                     | (uint16_t)((adc_spi_cfg[adc_spi_conf][2] & 0x0003)<<7)
                     | (uint16_t)((adc_spi_cfg[adc_spi_conf][3] & 0x0003)<<5);

         /* Write SPI Line */
         SPI_ONE_WRITE_DATA( adc_spi_conf,
                                    (CMN_SYSTEM_ADDR_t*)&adc_spi_cfg_word,
                                    sizeof(adc_spi_cfg_word),
                                    &adc_cfg_ret_size_out);
         /* */
         adc_spi_cfg_word = (uint16_t)0xC000
                     | (uint16_t)((adc_spi_cfg[adc_spi_conf][4] & 0x0003)<<11)
                     | (uint16_t)((adc_spi_cfg[adc_spi_conf][5] & 0x0003)<<9)
                     | (uint16_t)((adc_spi_cfg[adc_spi_conf][6] & 0x0003)<<7)
                     | (uint16_t)((adc_spi_cfg[adc_spi_conf][7] & 0x0003)<<5);

         /* Write SPI Line */
         SPI_ONE_WRITE_DATA( adc_spi_conf,
                                    (CMN_SYSTEM_ADDR_t*)&adc_spi_cfg_word,
                                    sizeof(adc_spi_cfg_word),
                                    &adc_cfg_ret_size_out);
      }
   }
}

/* ---------- internal operation bodies: ------------------------------------ */
