/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : <short description of the operations of the .c file>
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "driver/adc_over_spi/ADC_AD7327_CFEX_common.h"

/* ---------- include required interface: ----------------------------------- */

/* ---------- internal define constants: ------------------------------------ */

/* ADC AD7327 configuration table size */
#define  ADC_AD7327_CFEX_TAB_SIZE 24

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ADC AD7327 configuration table size */
const uint16_t ADC_AD7327_CFEX_CONFIGURATION_SIZE = ADC_AD7327_CFEX_TAB_SIZE;

/* */
/*ADC AD7327 configuration table */
const ADC_AD7327_CFEX_ELT_TYPE ADC_AD7327_CFEX_CONFIGURATION_tab[ADC_AD7327_CFEX_TAB_SIZE] =
{
   /* ADC1 */
   /* 00 : ADC1 line 0 - SPI_1 */
   {
      ADC_AD7327_CFEX_LINE_0,                /* [0..7]                         */
      ADC_AD7327_CFEX_MODE_8_SINGLE_ENDED,
      ADC_AD7327_CFEX_CODING_BIN,
      ADC_AD7327_CFEX_REF_EXT,                /* Reference internal or external */
      ADC_AD7327_CFEX_CFG_N10_P10,
      ADC_AD7327_CFEX_SPI_CONF_0,            /* SPI conf                       */
   },
   /* 01 : ADC1 line 1 - SPI_1 */
   {
      ADC_AD7327_CFEX_LINE_1,                /* [0..7]                         */
      ADC_AD7327_CFEX_MODE_8_SINGLE_ENDED,
      ADC_AD7327_CFEX_CODING_BIN,
      ADC_AD7327_CFEX_REF_EXT,                /* Reference internal or external */
      ADC_AD7327_CFEX_CFG_N10_P10,
      ADC_AD7327_CFEX_SPI_CONF_0,            /* SPI conf                       */
   },
   /* 02 : ADC1 line 2 - SPI_1 */
   {
      ADC_AD7327_CFEX_LINE_2,                /* [0..7]                         */
      ADC_AD7327_CFEX_MODE_8_SINGLE_ENDED,
      ADC_AD7327_CFEX_CODING_BIN,
      ADC_AD7327_CFEX_REF_EXT,                /* Reference internal or external */
      ADC_AD7327_CFEX_CFG_N10_P10,
      ADC_AD7327_CFEX_SPI_CONF_0,            /* SPI conf                       */
   },
   /* 03 : ADC1 line 3 - SPI_1 */
   {
      ADC_AD7327_CFEX_LINE_3,                /* [0..7]                         */
      ADC_AD7327_CFEX_MODE_8_SINGLE_ENDED,
      ADC_AD7327_CFEX_CODING_BIN,
      ADC_AD7327_CFEX_REF_EXT,                /* Reference internal or external */
      ADC_AD7327_CFEX_CFG_N10_P10,
      ADC_AD7327_CFEX_SPI_CONF_0,            /* SPI conf                       */
   },
   /* 04 : ADC1 line 4 - SPI_1 */
   {
      ADC_AD7327_CFEX_LINE_4,                /* [0..7]                         */
      ADC_AD7327_CFEX_MODE_8_SINGLE_ENDED,
      ADC_AD7327_CFEX_CODING_BIN,
      ADC_AD7327_CFEX_REF_EXT,                /* Reference internal or external */
      ADC_AD7327_CFEX_CFG_N00_P10,
      ADC_AD7327_CFEX_SPI_CONF_0,            /* SPI conf                       */
   },
   /* 05 : ADC1 line 5 - SPI_1 */
   {
      ADC_AD7327_CFEX_LINE_5,                /* [0..7]                         */
      ADC_AD7327_CFEX_MODE_8_SINGLE_ENDED,
      ADC_AD7327_CFEX_CODING_BIN,
      ADC_AD7327_CFEX_REF_EXT,                /* Reference internal or external */
      ADC_AD7327_CFEX_CFG_N00_P10,
      ADC_AD7327_CFEX_SPI_CONF_0,            /* SPI conf                       */
   },
   /* 06 : ADC1 line 6 - SPI_1 */
   {
      ADC_AD7327_CFEX_LINE_6,                /* [0..7]                         */
      ADC_AD7327_CFEX_MODE_8_SINGLE_ENDED,
      ADC_AD7327_CFEX_CODING_BIN,
      ADC_AD7327_CFEX_REF_EXT,                /* Reference internal or external */
      ADC_AD7327_CFEX_CFG_N00_P10,
      ADC_AD7327_CFEX_SPI_CONF_0,            /* SPI conf                       */
   },
   /* 07 : ADC1 line 7 - SPI_1 */
   {
      ADC_AD7327_CFEX_LINE_7,                /* [0..7]                         */
      ADC_AD7327_CFEX_MODE_8_SINGLE_ENDED,
      ADC_AD7327_CFEX_CODING_BIN,
      ADC_AD7327_CFEX_REF_EXT,                /* Reference internal or external */
      ADC_AD7327_CFEX_CFG_N25_P25,
      ADC_AD7327_CFEX_SPI_CONF_0,            /* SPI conf                       */
   },
   /* ADC2 */
   /* 08 : ADC2 line 0 - SPI_2 */
   {
      ADC_AD7327_CFEX_LINE_0,                /* [0..7]                         */
      ADC_AD7327_CFEX_MODE_8_SINGLE_ENDED,
      ADC_AD7327_CFEX_CODING_BIN,
      ADC_AD7327_CFEX_REF_EXT,                /* Reference internal or external */
      ADC_AD7327_CFEX_CFG_N10_P10,
      ADC_AD7327_CFEX_SPI_CONF_1,            /* SPI conf                       */
   },
   /* 09 : ADC2 line 1 - SPI_2 */
   {
      ADC_AD7327_CFEX_LINE_1,                /* [0..7]                         */
      ADC_AD7327_CFEX_MODE_8_SINGLE_ENDED,
      ADC_AD7327_CFEX_CODING_BIN,
      ADC_AD7327_CFEX_REF_EXT,                /* Reference internal or external */
      ADC_AD7327_CFEX_CFG_N10_P10,
      ADC_AD7327_CFEX_SPI_CONF_1,            /* SPI conf                       */
   },
   /* 10 : ADC2 line 2 - SPI_2 */
   {
      ADC_AD7327_CFEX_LINE_2,                /* [0..7]                         */
      ADC_AD7327_CFEX_MODE_8_SINGLE_ENDED,
      ADC_AD7327_CFEX_CODING_BIN,
      ADC_AD7327_CFEX_REF_EXT,                /* Reference internal or external */
      ADC_AD7327_CFEX_CFG_N10_P10,
      ADC_AD7327_CFEX_SPI_CONF_1,            /* SPI conf                       */
   },
   /* 11 : ADC2 line 3 - SPI_2 */
   {
      ADC_AD7327_CFEX_LINE_3,                /* [0..7]                         */
      ADC_AD7327_CFEX_MODE_8_SINGLE_ENDED,
      ADC_AD7327_CFEX_CODING_BIN,
      ADC_AD7327_CFEX_REF_EXT,                /* Reference internal or external */
      ADC_AD7327_CFEX_CFG_N10_P10,
      ADC_AD7327_CFEX_SPI_CONF_1,            /* SPI conf                       */
   },
   /* 12 : ADC2 line 4 - SPI_2 */
   {
      ADC_AD7327_CFEX_LINE_4,                /* [0..7]                         */
      ADC_AD7327_CFEX_MODE_8_SINGLE_ENDED,
      ADC_AD7327_CFEX_CODING_BIN,
      ADC_AD7327_CFEX_REF_EXT,                /* Reference internal or external */
      ADC_AD7327_CFEX_CFG_N00_P10,
      ADC_AD7327_CFEX_SPI_CONF_1,            /* SPI conf                       */
   },
   /* 13 : ADC2 line 5 - SPI_2 */
   {
      ADC_AD7327_CFEX_LINE_5,                /* [0..7]                         */
      ADC_AD7327_CFEX_MODE_8_SINGLE_ENDED,
      ADC_AD7327_CFEX_CODING_BIN,
      ADC_AD7327_CFEX_REF_EXT,                /* Reference internal or external */
      ADC_AD7327_CFEX_CFG_N00_P10,
      ADC_AD7327_CFEX_SPI_CONF_1,            /* SPI conf                       */
   },
   /* 14 : ADC2 line 6 - SPI_2 */
   {
      ADC_AD7327_CFEX_LINE_6,                /* [0..7]                         */
      ADC_AD7327_CFEX_MODE_8_SINGLE_ENDED,
      ADC_AD7327_CFEX_CODING_BIN,
      ADC_AD7327_CFEX_REF_EXT,                /* Reference internal or external */
      ADC_AD7327_CFEX_CFG_N00_P10,
      ADC_AD7327_CFEX_SPI_CONF_1,            /* SPI conf                       */
   },
   /* 15 : ADC2 line 7 - SPI_2 */
   {
      ADC_AD7327_CFEX_LINE_7,                /* [0..7]                         */
      ADC_AD7327_CFEX_MODE_8_SINGLE_ENDED,
      ADC_AD7327_CFEX_CODING_BIN,
      ADC_AD7327_CFEX_REF_EXT,                /* Reference internal or external */
      ADC_AD7327_CFEX_CFG_N25_P25,
      ADC_AD7327_CFEX_SPI_CONF_1,            /* SPI conf                       */
   },
   /* ADC3 */
   /* 16 : ADC3 line 0 - SPI_3 */
   {
      ADC_AD7327_CFEX_LINE_0,                /* [0..7]                         */
      ADC_AD7327_CFEX_MODE_8_SINGLE_ENDED,
      ADC_AD7327_CFEX_CODING_BIN,
      ADC_AD7327_CFEX_REF_EXT,                /* Reference internal or external */
      ADC_AD7327_CFEX_CFG_N10_P10,
      ADC_AD7327_CFEX_SPI_CONF_2,            /* SPI conf                       */
   },
   /* 17 : ADC3 line 1 - SPI_3 */
   {
      ADC_AD7327_CFEX_LINE_1,                /* [0..7]                         */
      ADC_AD7327_CFEX_MODE_8_SINGLE_ENDED,
      ADC_AD7327_CFEX_CODING_BIN,
      ADC_AD7327_CFEX_REF_EXT,                /* Reference internal or external */
      ADC_AD7327_CFEX_CFG_N10_P10,
      ADC_AD7327_CFEX_SPI_CONF_2,            /* SPI conf                       */
   },
   /* 18 : ADC3 line 2 - SPI_3 */
   {
      ADC_AD7327_CFEX_LINE_2,                /* [0..7]                         */
      ADC_AD7327_CFEX_MODE_8_SINGLE_ENDED,
      ADC_AD7327_CFEX_CODING_BIN,
      ADC_AD7327_CFEX_REF_EXT,                /* Reference internal or external */
      ADC_AD7327_CFEX_CFG_N10_P10,
      ADC_AD7327_CFEX_SPI_CONF_2,            /* SPI conf                       */
   },
   /* 19 : ADC3 line 3 - SPI_3 */
   {
      ADC_AD7327_CFEX_LINE_3,                /* [0..7]                         */
      ADC_AD7327_CFEX_MODE_8_SINGLE_ENDED,
      ADC_AD7327_CFEX_CODING_BIN,
      ADC_AD7327_CFEX_REF_EXT,                /* Reference internal or external */
      ADC_AD7327_CFEX_CFG_N00_P10,
      ADC_AD7327_CFEX_SPI_CONF_2,            /* SPI conf                       */
   },
   /* 20 : ADC3 line 4 - SPI_3 */
   {
      ADC_AD7327_CFEX_LINE_4,                /* [0..7]                         */
      ADC_AD7327_CFEX_MODE_8_SINGLE_ENDED,
      ADC_AD7327_CFEX_CODING_BIN,
      ADC_AD7327_CFEX_REF_EXT,                /* Reference internal or external */
      ADC_AD7327_CFEX_CFG_N00_P10,
      ADC_AD7327_CFEX_SPI_CONF_2,            /* SPI conf                       */
   },
   /* 21 : ADC3 line 5 - SPI_3 */
   {
      ADC_AD7327_CFEX_LINE_5,                /* [0..7]                         */
      ADC_AD7327_CFEX_MODE_8_SINGLE_ENDED,
      ADC_AD7327_CFEX_CODING_BIN,
      ADC_AD7327_CFEX_REF_EXT,                /* Reference internal or external */
      ADC_AD7327_CFEX_CFG_N10_P10,
      ADC_AD7327_CFEX_SPI_CONF_2,            /* SPI conf                       */
   },
   /* 22 : ADC3 line 6 - SPI_3 */
   {
      ADC_AD7327_CFEX_LINE_6,                /* [0..7]                         */
      ADC_AD7327_CFEX_MODE_8_SINGLE_ENDED,
      ADC_AD7327_CFEX_CODING_BIN,
      ADC_AD7327_CFEX_REF_EXT,                /* Reference internal or external */
      ADC_AD7327_CFEX_CFG_N00_P10,
      ADC_AD7327_CFEX_SPI_CONF_2,            /* SPI conf                       */
   },
   /* 23 : ADC3 line 7 - SPI_3 */
   {
      ADC_AD7327_CFEX_LINE_7,                /* [0..7]                         */
      ADC_AD7327_CFEX_MODE_8_SINGLE_ENDED,
      ADC_AD7327_CFEX_CODING_BIN,
      ADC_AD7327_CFEX_REF_EXT,                /* Reference internal or external */
      ADC_AD7327_CFEX_CFG_N25_P25,
      ADC_AD7327_CFEX_SPI_CONF_2,            /* SPI conf                       */
   }
};

/* ---------- internal data: ------------------------------------------------ */
/* ADC AD7327 descriptor declaration */
ADC_AD7327_CONFIG_DESC_TYPE ADC_AD7327_CFEX_descriptor_tab[ADC_AD7327_CFEX_TAB_SIZE];

/* ---------- provided operation bodies: ------------------------------------ */

/* ---------- internal operation bodies: ------------------------------------ */
