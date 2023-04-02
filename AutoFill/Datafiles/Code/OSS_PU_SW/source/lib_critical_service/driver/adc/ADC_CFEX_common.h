/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef ADC_CFEX_COMMON_H
#define ADC_CFEX_COMMON_H

/* ---------- include required interface: ----------------------------------- */
#include "type/common_type.h"

/* ---------- provided define constants: ------------------------------------ */
/* ADC SYSTEM LIMIT */
/* Supported maximum number of ADC IPs */
/* MPC5577M has 12 SARADCs and 10 SDADCs */
#define ADC_CFEX_LINE_ID_00     0
#define ADC_CFEX_LINE_MAX_NB    3
#define ADC_CFEX_CTR_RES_SHIFT  (31)
#define ADC_CFEX_CTR_RES_MASK   (1<<ADC_CFEX_CTR_RES_SHIFT)

#define ADC_CFEX_CTR_ELT_NB   4

/* XR voltage monitoring */
#define ADC_CFEX_AN45   (45)
#define ADC_CFEX_AN46   (46)

/* LVDT voltage monitoring */
#define ADC_CFEX_AN44   (44)
#define ADC_CFEX_AN25   (25)
#define ADC_CFEX_AN24   (24)
#define ADC_CFEX_AN17   (17)

/* tmot : voltage monitoring */
#define ADC_CFEX_AN47   (47)

/* tmot : current monitoring */
#define ADC_CFEX_AN50   (50)

/* smot : current monitoring */
#define ADC_CFEX_AN64   (64)

/* smot : voltage monitoring */
#define ADC_CFEX_AN65   (65)

/* SG: P3 EXC Monitoring */
#define ADC_CFEX_AN66   (66)

/* SG: SG1/SG3-SG4 EXC Monitoring */
#define ADC_CFEX_AN67   (67)

/* Powersup: 28V voltage monitoring */
#define ADC_CFEX_AN69   (69)

/* HP/LP: MPC_HP4_CURRENT_MON */
#define ADC_CFEX_AN70   (70)

/* HP/LP: MPC_HP4_VOLTAGE_MON */
#define ADC_CFEX_AN71   (71)

/* SG: SG2/SG5g EXC Monitoring */
#define ADC_CFEX_AN74   (74)

/* Pot: Pot_1 or Pot_2 Low-side EXC Monitoring */
#define ADC_CFEX_AN78   (78)

/* Pot: Pot_3 Low-side EXC Monitoring */
#define ADC_CFEX_AN79   (79)

/* Discrete: communication EMAN and SVOI monitoring */
#define ADC_CFEX_AN16   (16)

/* TECU */
#define ADC_CFEX_AN120   (120)

/* TECU */
#define ADC_CFEX_AN121   (121)

/* REF_2V5 */
#define ADC_CFEX_AN8     (8)


#define ADC_INT_NB_MEAS  (4)

/* ADC gain conversion */
#define ADC_CONVERT_VALUE (float32_t)(5.0/4096.0)

/* ---------- provided types: ----------------------------------------------- */

/*  ADC IDs */
typedef enum
{
   e_CFEX_ADC_INT_AN8 = 0u,
   e_CFEX_ADC_INT_AN16,
   e_CFEX_ADC_INT_AN17,
   e_CFEX_ADC_INT_AN24,
   e_CFEX_ADC_INT_AN25,
   e_CFEX_ADC_INT_AN44,
   e_CFEX_ADC_INT_AN45,
   e_CFEX_ADC_INT_AN46,
   e_CFEX_ADC_INT_AN47,
   e_CFEX_ADC_INT_AN50,
   e_CFEX_ADC_INT_AN64,
   e_CFEX_ADC_INT_AN65,
   e_CFEX_ADC_INT_AN66,
   e_CFEX_ADC_INT_AN67,
   e_CFEX_ADC_INT_AN69,
   e_CFEX_ADC_INT_AN70,
   e_CFEX_ADC_INT_AN71,
   e_CFEX_ADC_INT_AN74,
   e_CFEX_ADC_INT_AN78,
   e_CFEX_ADC_INT_AN79,
   e_CFEX_ADC_INT_AN120,
   e_CFEX_ADC_INT_AN121,
   e_CFEX_ADC_INT_ANx_NB
}
te_CFEX_ADC_INT_ANx_CONF_ID;

/* Mode type */
typedef enum
{
   e_ADC_CFEX_RES_12BITS = 0, /* 12-bits resolution */
   e_ADC_CFEX_RES_10BITS = 1  /* 10-bits resolution */
}
te_ADC_CFEX_RES_TYPE;

/* Mode type */
typedef enum
{
   e_ADC_CFEX_ONE_SHOT = 0, /* one-shot mode */
   e_ADC_CFEX_SCAN     = 1  /* scan mode */

}
te_ADC_CFEX_MODE_TYPE;

/* channel conversion type */
typedef enum
{
   e_ADC_CFEX_NORM_CH_CONV   = 0, /* normal channel conversion */
   e_ADC_CFEX_INJ_CH_CONV = 1  /* injected channel conversion */
}
te_ADC_CFEX_CH_CONV_TYPE;

/* IRQ enable */
typedef enum
{
   e_ADC_CFEX_IRQ_DISABLE = 0, /* do not manage IRQ */
   e_ADC_CFEX_IRQ_ENABLE  = 1  /* manage IRQ */
}
te_ADC_CFEX_IRQ_TYPE;

/* DMA enable */
typedef enum
{
   e_ADC_CFEX_DMA_DISABLE = 0, /* do not manage DMA */
   e_ADC_CFEX_DMA_ENABLE  = 1  /* manage DMA */
}
te_ADC_CFEX_DMA_TYPE;


/* generic parameters for all ADC lines */
typedef struct
{
   /* ADC instance line */
   uint32_t                     s_adc_line;
   /* DMA transfer enable */
   te_ADC_CFEX_DMA_TYPE         s_dma_enable;
   /* IRQ enable */
   te_ADC_CFEX_IRQ_TYPE         s_irq_enable;
   /* Scan or one-shot mode */
   te_ADC_CFEX_MODE_TYPE        s_mode;
   /* Conversion type */
   te_ADC_CFEX_CH_CONV_TYPE     s_conversion;
   /* CTR configuration */
   uint32_t                     s_ctr[ADC_CFEX_CTR_ELT_NB];
   /* All ADC to read from beginning */
   te_CMN_FLAG_ACTIVATION       s_all;
}
ts_ADC_CFEX_GEN_CONF_TYPE;

/* Lines description by ADC */
typedef struct
{
   /* ADC input pins to access */
   uint32_t                      s_adc_number;
   /* CTR choice */
   uint32_t                      s_ctr_index;
   /* DMA transfer enable */
   te_ADC_CFEX_DMA_TYPE          s_dma_enable;
   /* DMA line number */
   uint32_t                      s_dma_conf_nb;
}
ts_ADC_CFEX_ELT_TYPE;


/* ADC configuration table */
typedef struct
{
   /* Number of elements */
   uint32_t                           s_adc_nb;
   /* Common configuration */
   ts_ADC_CFEX_GEN_CONF_TYPE const *  s_adc_gen_conf_pt;
   /* Table of elements */
   ts_ADC_CFEX_ELT_TYPE               s_adc_elt_tab[e_CFEX_ADC_INT_ANx_NB];
}
ts_ADC_CFEX_TAB_TYPE;


/* ---------- provided constants: ------------------------------------------- */
/* */
extern const ts_ADC_CFEX_TAB_TYPE  ADC_CFEX_st;



/* ---------- provided operations: ------------------------------------------ */

#endif /* ADC_CFEX_COMMON_H */
