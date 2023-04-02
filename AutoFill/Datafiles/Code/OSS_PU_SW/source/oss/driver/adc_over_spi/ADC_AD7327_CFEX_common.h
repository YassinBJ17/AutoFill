/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef ADC_AD7327_CFEX_COMMON_H
#define ADC_AD7327_CFEX_COMMON_H

/* ---------- include required interface: ----------------------------------- */
#include "driver/adc_over_spi/ADC_AD7327_HAL_common.h"

/* ---------- provided define constants: ------------------------------------ */

#define ADC_AD7327_CFEX_CMD_WRITE      0x8000

/* Shift data in command word */
#define ADC_AD7327_CFEX_LINE_SHIFT     10
#define ADC_AD7327_CFEX_MODE_SHIFT     8
#define ADC_AD7327_CFEX_CODING_SHIFT   5
#define ADC_AD7327_CFEX_REF_SHIFT      4
/* Number of samples */
#define ADC_AD7327_CFEX_ADC1_SAMPLES_NB  (112+174+205+54+81+81+180+118)
/* Number of samples to send */
#define ADC_AD7327_CFEX_ADC1_SAMPLES_TO_SEND_NB  (ADC_AD7327_CFEX_ADC1_SAMPLES_NB*sizeof(uint32_t))
/* Number of samples to receive */
#define ADC_AD7327_CFEX_ADC1_SAMPLES_TO_RCV_NB  (ADC_AD7327_CFEX_ADC1_SAMPLES_NB*sizeof(uint16_t))
/* Number of samples to receive */
#define ADC_AD7327_CFEX_ADC1_SAMPLES_TO_RCV_BUFF  ((ADC_AD7327_CFEX_ADC1_SAMPLES_TO_RCV_NB*4) + (10*sizeof(uint16_t)) )
/* Number of sensors acquired */
#define ADC_AD7327_CFEX_ADC1_SENSORS_NB  (5+9+11+3+3+3+2+3)
/* Number of samples */
#define ADC_AD7327_CFEX_ADC2_SAMPLES_NB  (112+174+205+54+81+81+180+118)
/* Number of samples to send */
#define ADC_AD7327_CFEX_ADC2_SAMPLES_TO_SEND_NB  (ADC_AD7327_CFEX_ADC2_SAMPLES_NB*sizeof(uint32_t))
/* Number of samples to receive */
#define ADC_AD7327_CFEX_ADC2_SAMPLES_TO_RCV_NB  (ADC_AD7327_CFEX_ADC2_SAMPLES_NB*sizeof(uint16_t))
/* Number of samples to receive */
#define ADC_AD7327_CFEX_ADC2_SAMPLES_TO_RCV_BUFF  ((ADC_AD7327_CFEX_ADC2_SAMPLES_TO_RCV_NB*4) + (10*sizeof(uint16_t)) )
/* Number of sensors acquired */
#define ADC_AD7327_CFEX_ADC2_SENSORS_NB  (5+9+11+3+3+3+2+3)
/* Number of samples */
#define ADC_AD7327_CFEX_ADC3_SAMPLES_NB  (112+174+205+54+81+81+180+118)
/* Number of samples to send */
#define ADC_AD7327_CFEX_ADC3_SAMPLES_TO_SEND_NB  (ADC_AD7327_CFEX_ADC3_SAMPLES_NB*sizeof(uint32_t))
/* Number of samples to receive */
#define ADC_AD7327_CFEX_ADC3_SAMPLES_TO_RCV_NB  (ADC_AD7327_CFEX_ADC3_SAMPLES_NB*sizeof(uint16_t))
/* Number of samples to receive */
#define ADC_AD7327_CFEX_ADC3_SAMPLES_TO_RCV_BUFF  ((ADC_AD7327_CFEX_ADC3_SAMPLES_TO_RCV_NB*4) + (10*sizeof(uint16_t)) )
/* Number of sensors acquired */
#define ADC_AD7327_CFEX_ADC3_SENSORS_NB  (5+9+11+3+3+3+2+3)
/* */
/* Supported maximum number of ADC */
#define ADC_AD7327_CFEX_LINE_NB_MAX    8
/* */
/* 8 line SPI max = 8 conf SPI max */
#define ADC_AD7327_CFEX_SPI_CONF_MAX   8

/* XR Position */
#define ADC_AD7327_CFEX_SPI_CONF_MAX   8

/* ---------- provided types: ----------------------------------------------- */

/* */
typedef enum
{
   /* */
   ADC_AD7327_CFEX_LINE_0  = 0,
   /* */
   ADC_AD7327_CFEX_LINE_1  = 1,
   /* */
   ADC_AD7327_CFEX_LINE_2  = 2,
   /* */
   ADC_AD7327_CFEX_LINE_3  = 3,
   /* */
   ADC_AD7327_CFEX_LINE_4  = 4,
   /* */
   ADC_AD7327_CFEX_LINE_5  = 5,
   /* */
   ADC_AD7327_CFEX_LINE_6  = 6,
   /* */
   ADC_AD7327_CFEX_LINE_7  = 7
}
ADC_AD7327_CFEX_LINE_NB_TYPE;

/* */
typedef enum
{
   /* */
   ADC_AD7327_CFEX_MODE_8_SINGLE_ENDED = 0,
   /* */
   ADC_AD7327_CFEX_MODE_4_PSEUDO_DIFF  = 1,
   /* */
   ADC_AD7327_CFEX_MODE_4_FULLY_DIFF   = 2,
   /* */
   ADC_AD7327_CFEX_MODE_7_PSEUDO_DIFF  = 3
}
ADC_AD7327_CFEX_MODE_TYPE;

/* */
typedef enum
{
   /* */
   ADC_AD7327_CFEX_CODING_2COMP  = 0,
   /* */
   ADC_AD7327_CFEX_CODING_BIN    = 1
}
ADC_AD7327_CFEX_CODING_TYPE;

/* */
typedef enum
{
   /* */
   ADC_AD7327_CFEX_REF_EXT  = 0,
   /* */
   ADC_AD7327_CFEX_REF_IN   = 1
}
ADC_AD7327_CFEX_REF_TYPE;

/* */
typedef enum
{
   /* */
   ADC_AD7327_CFEX_CFG_N10_P10 = 0,
   /* */
   ADC_AD7327_CFEX_CFG_N50_P50 = 1,
   /* */
   ADC_AD7327_CFEX_CFG_N25_P25 = 2,
   /* */
   ADC_AD7327_CFEX_CFG_N00_P10 = 3
}
ADC_AD7327_CFEX_CFG_TYPE;

/* */
typedef enum
{
   /* */
   ADC_AD7327_CFEX_SPI_CONF_0  = 0,
   /* */
   ADC_AD7327_CFEX_SPI_CONF_1  = 1,
   /* */
   ADC_AD7327_CFEX_SPI_CONF_2  = 2,
   /* */
   ADC_AD7327_CFEX_SPI_CONF_3  = 3,
   /* */
   ADC_AD7327_CFEX_SPI_CONF_4  = 4,
   /* */
   ADC_AD7327_CFEX_SPI_CONF_5  = 5,
   /* */
   ADC_AD7327_CFEX_SPI_CONF_6  = 6,
   /* */
   ADC_AD7327_CFEX_SPI_CONF_7  = 7
}
ADC_AD7327_CFEX_SPI_CONF_NB_TYPE;


/* */
/* Physical description of one ADC */
typedef struct
{
   /* ADC line number */
   ADC_AD7327_CFEX_LINE_NB_TYPE      adc_line_nb;   /* [0..7] */
   /* ADC mode acquisition */
   ADC_AD7327_CFEX_MODE_TYPE         adc_mode;
   /* ADC coding acquisition */
   ADC_AD7327_CFEX_CODING_TYPE       adc_coding;
   /* ADC reference */
   ADC_AD7327_CFEX_REF_TYPE          adc_ref;      /* Reference internal or external */
   /* ADC configuration acquisition */
   ADC_AD7327_CFEX_CFG_TYPE          adc_cfg;
   /* SPI conf number */
   ADC_AD7327_CFEX_SPI_CONF_NB_TYPE  spi_conf_nb;
}
ADC_AD7327_CFEX_ELT_TYPE;


/* */
typedef struct
{
   /* ADC command */
   uint16_t        adc_command;
   /* SPI conf number */
   CMN_IOSP_ID_t   spi_conf_id;
}
ADC_AD7327_CONFIG_DESC_TYPE;

/* */
typedef struct
{
   /* ADC offset */
   uint16_t   adc_offset;
   /* ADC sample  number */
   uint16_t   adc_sample_nb;
}
ADC_AD7327_CFEX_TAB_OFF_TYPE;


/* ---------- provided constants: ------------------------------------------- */
extern const uint16_t                 ADC_AD7327_CFEX_CONFIGURATION_SIZE;
extern const ADC_AD7327_CFEX_ELT_TYPE ADC_AD7327_CFEX_CONFIGURATION_tab[];
extern ADC_AD7327_CONFIG_DESC_TYPE    ADC_AD7327_CFEX_descriptor_tab[];

extern const uint32_t                 ADC_AD7327_CFEX_ADC1_st[ADC_AD7327_CFEX_ADC1_SAMPLES_NB];
extern const uint32_t                 ADC_AD7327_CFEX_ADC1_st_cpmb[ADC_AD7327_CFEX_ADC1_SAMPLES_NB];
extern const                          ADC_AD7327_CFEX_TAB_OFF_TYPE ADC_AD7327_CFEX_ADC1_OFF_TAB[ADC_AD7327_CFEX_ADC1_SENSORS_NB];
extern uint32_t                       applied_adc_over_spi_settings_adc1[ADC_AD7327_CFEX_ADC1_SAMPLES_NB];

extern const uint32_t                 ADC_AD7327_CFEX_ADC2_st[ADC_AD7327_CFEX_ADC2_SAMPLES_NB];
extern const uint32_t                 ADC_AD7327_CFEX_ADC2_st_cpmb[ADC_AD7327_CFEX_ADC2_SAMPLES_NB];
extern const                          ADC_AD7327_CFEX_TAB_OFF_TYPE ADC_AD7327_CFEX_ADC2_OFF_TAB[ADC_AD7327_CFEX_ADC2_SENSORS_NB];
extern uint32_t                       applied_adc_over_spi_settings_adc2[ADC_AD7327_CFEX_ADC2_SAMPLES_NB];

extern const uint32_t                 ADC_AD7327_CFEX_ADC3_st[ADC_AD7327_CFEX_ADC3_SAMPLES_NB];
extern const uint32_t                 ADC_AD7327_CFEX_ADC3_st_cpmb[ADC_AD7327_CFEX_ADC3_SAMPLES_NB];
extern const                          ADC_AD7327_CFEX_TAB_OFF_TYPE ADC_AD7327_CFEX_ADC3_OFF_TAB[ADC_AD7327_CFEX_ADC3_SENSORS_NB];
extern uint32_t                       applied_adc_over_spi_settings_adc3[ADC_AD7327_CFEX_ADC3_SAMPLES_NB];

/* ---------- provided data: ----------------------------------------------- */

/* ---------- provided operations: ------------------------------------------ */

#endif /* ADC_AD7327_CFEX_COMMON_H */
