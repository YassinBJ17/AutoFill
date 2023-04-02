/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : <short description of the operations of the .c file>
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "type/common_type.h"
#include "driver/adc/ADC_CFEX_common.h"
#include "driver/adc/ADC_REG_common.h"

/* Generic configuration for all ADCs */
const ts_ADC_CFEX_GEN_CONF_TYPE GEN_CONF_pt =
{
   /* ADC instance identifier */
   ADC_CFEX_LINE_ID_00,
   /* DMA transfer enable */
   e_ADC_CFEX_DMA_ENABLE,
   /* IRQ enable */
   e_ADC_CFEX_IRQ_DISABLE,
   /* Scan or one-shot mode */
   e_ADC_CFEX_SCAN,
   /* ADC configuration */
   e_ADC_CFEX_NORM_CH_CONV,
   /* CTR configuration */
   {
      /* CTR[0]: CRES=12-bits resolution, PRECH=0xF, INPSAMP=0xFF */
      0x00000FFF,
      /* CTR[1] */
      0x00000000,
      /* CTR[2] */
      0x00000000,
      /* CTR[3] */
      0x00000000
   },
   e_CMN_FLAG_ACTIVATE
};

const ts_ADC_CFEX_TAB_TYPE ADC_CFEX_st =
{
   /* Number of elements */
   e_CFEX_ADC_INT_ANx_NB,
   /* Common configuration */
   &GEN_CONF_pt,
   /* Table of elements */
   {
       {
         /* ADC to read */
         ADC_CFEX_AN8,
         /* CTR choice */
         0,
         e_ADC_CFEX_DMA_DISABLE,
         /* DMA line number */
         0
      },
      {
         /* ADC to read */
         ADC_CFEX_AN16,
         /* CTR choice */
         0,
         e_ADC_CFEX_DMA_DISABLE,
         /* DMA line number */
         0
      },
     {
         /* ADC to read */
         ADC_CFEX_AN17,
         /* CTR choice */
         0,
         e_ADC_CFEX_DMA_DISABLE,
         /* DMA line number */
         0
      },
      {
         /* ADC to read */
         ADC_CFEX_AN24,
         /* CTR choice */
         0,
         e_ADC_CFEX_DMA_DISABLE,
         /* DMA line number */
         0
      },
      {
         /* ADC to read */
         ADC_CFEX_AN25,
         /* CTR choice */
         0,
         e_ADC_CFEX_DMA_DISABLE,
         /* DMA line number */
         0
      },
      {
         /* ADC to read */
         ADC_CFEX_AN44,
         /* CTR choice */
         0,
         e_ADC_CFEX_DMA_DISABLE,
         /* DMA line number */
         0
      },
      {
         /* ADC to read */
         ADC_CFEX_AN45,
         /* CTR choice */
         0,
         e_ADC_CFEX_DMA_DISABLE,
         /* DMA line number */
         0
      },
      {
         /* ADC to read */
         ADC_CFEX_AN46,
         /* CTR choice */
         0,
         e_ADC_CFEX_DMA_DISABLE,
         /* DMA line number */
         0
      },
      {
         /* ADC to read */
         ADC_CFEX_AN47,
         /* CTR choice */
         0,
         e_ADC_CFEX_DMA_DISABLE,
         /* DMA line number */
         0
      },
      {
         /* ADC to read */
         ADC_CFEX_AN50,
         /* CTR choice */
         0,
         e_ADC_CFEX_DMA_DISABLE,
         /* DMA line number */
         0
      },
      {
        /* ADC to read */
        ADC_CFEX_AN64,
        /* CTR choice */
        0,
        e_ADC_CFEX_DMA_DISABLE,
        /* DMA line number */
        0
      },
      {
        /* ADC to read */
        ADC_CFEX_AN65,
        /* CTR choice */
        0,
        e_ADC_CFEX_DMA_DISABLE,
        /* DMA line number */
        0
      },
      {
         /* ADC to read */
         ADC_CFEX_AN66,
         /* CTR choice */
         0,
         e_ADC_CFEX_DMA_DISABLE,
         /* DMA line number */
         0
      },
      {
         /* ADC to read */
         ADC_CFEX_AN67,
         /* CTR choice */
         0,
         e_ADC_CFEX_DMA_DISABLE,
         /* DMA line number */
         0
      },
      {
         /* ADC to read */
         ADC_CFEX_AN69,
         /* CTR choice */
         0,
         e_ADC_CFEX_DMA_DISABLE,
         /* DMA line number */
         0
      },
      {
         /* ADC to read */
         ADC_CFEX_AN70,
         /* CTR choice */
         0,
         e_ADC_CFEX_DMA_DISABLE,
         /* DMA line number */
         0
      },
      {
         /* ADC to read */
         ADC_CFEX_AN71,
         /* CTR choice */
         0,
         e_ADC_CFEX_DMA_DISABLE,
         /* DMA line number */
         0
      },
      {
         /* ADC to read */
         ADC_CFEX_AN74,
         /* CTR choice */
         0,
         e_ADC_CFEX_DMA_DISABLE,
         /* DMA line number */
         0
      },
      {
         /* ADC to read */
         ADC_CFEX_AN78,
         /* CTR choice */
         0,
         e_ADC_CFEX_DMA_DISABLE,
         /* DMA line number */
         0
      },
      {
         /* ADC to read */
         ADC_CFEX_AN79,
         /* CTR choice */
         0,
         e_ADC_CFEX_DMA_DISABLE,
         /* DMA line number */
         0
      },
      {
         /* ADC to read */
         ADC_CFEX_AN120,
         /* CTR choice */
         0,
         e_ADC_CFEX_DMA_DISABLE,
         /* DMA line number */
         0
      },
      {
         /* ADC to read */
         ADC_CFEX_AN121,
         /* CTR choice */
         0,
         e_ADC_CFEX_DMA_DISABLE,
         /* DMA line number */
         0
      }
   }
};

/* Table for ADC controler registers */
ts_ADC_CTRL_TYPE * const c_ADC_ctrler_pt[ADC_CFEX_LINE_MAX_NB] =
{
   /* >RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> cast is safe, address is mapped to a structure */
   (ts_ADC_CTRL_TYPE *) SARADC_B_LINE_BA_ADDR
};

/* Table for SARADC_B values get from DMA */
uint32_t v_adc_int_buffer[e_CFEX_ADC_INT_ANx_NB][ADC_INT_NB_MEAS];
