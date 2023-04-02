/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef ADC_REG_COMMON_H
#define ADC_REG_COMMON_H

/* ---------- include required interface: ----------------------------------- */
#include "type/common_type.h"
#include "driver/adc/ADC_CFEX_common.h"

/* ---------- provided define constants: ------------------------------------ */
/* Enable */
typedef enum
{
   e_ADC_ENABLE  = 0,
   e_ADC_DISABLE = 1
}
te_ADC_ENABLE_TYPE;

/* fault */
typedef enum
{
   e_ADC_NO_FAULT = 0,
   e_ADC_BUS_BUSY,
   e_ADC_TIMEOUT
}
te_ADC_FAULT_TYPE;

#define ADC_LAST_ADC_NORMAL_CHANNEL (95UL)
#define ADC_LAST_ADC_TEST_CHANNEL   (127UL)
#define ADC_WORD_SIZE                   (32UL)

/* SARADC_B address */
#define SARADC_B_LINE_BA_ADDR (CMN_SYSTEM_ADDR_t *) 0xFFE3C000


/* ============================================================================
   =============================== Module: SARADC =============================
   ============================================================================ */

/* {{RELAX<SYNCHRONe_C_Code_6.6,SYNCHRONe_C_Code_7.2> Following structures and unions are used for the mapping of the MPC registers. */

typedef struct
{
   /* Main Configuration Register */
   union
   {
      reg32_t u_R;
      struct
      {
         reg32_t s_OWREN:1;
         reg32_t s_WLSIDE:1;
         reg32_t s_MODE:1;
         reg32_t  :1;
         reg32_t s_NSTART:1;
         reg32_t s_NTRGEN:1;
         reg32_t s_NEDGESEL:2;
         reg32_t s_JSTART:1;
         reg32_t s_JTRGEN:1;
         reg32_t s_JEDGESEL:2;
         reg32_t s_JTRGSEQ:1;
         reg32_t  :1;
         reg32_t  :2;
         reg32_t s_WTRIGOUT:1;
         reg32_t  :3;
         reg32_t s_JTRGSEL:4;
         reg32_t s_ABORTCHAIN:1;
         reg32_t s_ABORT:1;
         reg32_t  :1;
         reg32_t s_FRZ:1;
         reg32_t  :2;
         reg32_t s_EDCSELF:1;
         reg32_t s_PWDN:1;
      } u_B;
   } s_MCR;

   /* Main Status Register */
   PACKED_U32 union
   {
      reg32_t u_R;
      PACKED_U32 struct
      {
         reg32_t  :4;
         reg32_t s_NSTART:1;
         reg32_t  :3;
         reg32_t s_JSTART:1;
         reg32_t  :4;
         reg32_t s_JABORTCHAIN:1;
         reg32_t  :1;
         reg32_t  :1;
         reg32_t s_CHADDR:8;
         reg32_t  :5;
         reg32_t s_ADCSTATUS:3;
      } u_B;
   } s_MSR;

   /* reserved area */
   uint8_t s_reserved0[8];

   /* Interrupt Status Register */
   union
   {
      reg32_t u_R;
      struct
      {
         reg32_t  :27;
         reg32_t  :1;
         reg32_t s_JEOC:1;
         reg32_t s_JECH:1;
         reg32_t s_NEOC:1;
         reg32_t s_NECH:1;
      } u_B;
   } s_ISR;

   /* Internal channel Interrupt Pending Register */
   union
   {
      reg32_t u_R;
      struct
      {
         reg32_t s_EOC_CHx:32;
      } u_B;
   } s_ICIPR[3];

   /* Interrupt Mask Register */
   union
   {
      reg32_t u_R;
      struct
      {
         reg32_t  :27;
         reg32_t  :1;
         reg32_t s_MSKJEOC:1;
         reg32_t s_MSKJECH:1;
         reg32_t s_MSKNEOC:1;
         reg32_t s_MSKNECH:1;
      } u_B;
   } s_IMR;

   /* Internal Channel Interrupt Mask Register */
   union
   {
      reg32_t u_R;
      struct
      {
         reg32_t s_IM_CHx:32;
      } u_B;
   } s_ICIMR[3];

   /* Watchdog Threshold Interrupt Status Register */
   union
   {
      reg32_t u_R;
      struct
      {
         reg32_t s_WDG15H:1;
         reg32_t s_WDG15L:1;
         reg32_t s_WDG14H:1;
         reg32_t s_WDG14L:1;
         reg32_t s_WDG13H:1;
         reg32_t s_WDG13L:1;
         reg32_t s_WDG12H:1;
         reg32_t s_WDG12L:1;
         reg32_t s_WDG11H:1;
         reg32_t s_WDG11L:1;
         reg32_t s_WDG10H:1;
         reg32_t s_WDG10L:1;
         reg32_t s_WDG9H:1;
         reg32_t s_WDG9L:1;
         reg32_t s_WDG8H:1;
         reg32_t s_WDG8L:1;
         reg32_t s_WDG7H:1;
         reg32_t s_WDG7L:1;
         reg32_t s_WDG6H:1;
         reg32_t s_WDG6L:1;
         reg32_t s_WDG5H:1;
         reg32_t s_WDG5L:1;
         reg32_t s_WDG4H:1;
         reg32_t s_WDG4L:1;
         reg32_t s_WDG3H:1;
         reg32_t s_WDG3L:1;
         reg32_t s_WDG2H:1;
         reg32_t s_WDG2L:1;
         reg32_t s_WDG1H:1;
         reg32_t s_WDG1L:1;
         reg32_t s_WDG0H:1;
         reg32_t s_WDG0L:1;
      } u_B;
   } s_WTISR;

   /* Watchdog Threshold Interrupt Mask Register */
   union
   {
      reg32_t u_R;
      struct
      {
         reg32_t s_MSKWDG15H:1;
         reg32_t s_MSKWDG15L:1;
         reg32_t s_MSKWDG14H:1;
         reg32_t s_MSKWDG14L:1;
         reg32_t s_MSKWDG13H:1;
         reg32_t s_MSKWDG13L:1;
         reg32_t s_MSKWDG12H:1;
         reg32_t s_MSKWDG12L:1;
         reg32_t s_MSKWDG11H:1;
         reg32_t s_MSKWDG11L:1;
         reg32_t s_MSKWDG10H:1;
         reg32_t s_MSKWDG10L:1;
         reg32_t s_MSKWDG9H:1;
         reg32_t s_MSKWDG9L:1;
         reg32_t s_MSKWDG8H:1;
         reg32_t s_MSKWDG8L:1;
         reg32_t s_MSKWDG7H:1;
         reg32_t s_MSKWDG7L:1;
         reg32_t s_MSKWDG6H:1;
         reg32_t s_MSKWDG6L:1;
         reg32_t s_MSKWDG5H:1;
         reg32_t s_MSKWDG5L:1;
         reg32_t s_MSKWDG4H:1;
         reg32_t s_MSKWDG4L:1;
         reg32_t s_MSKWDG3H:1;
         reg32_t s_MSKWDG3L:1;
         reg32_t s_MSKWDG2H:1;
         reg32_t s_MSKWDG2L:1;
         reg32_t s_MSKWDG1H:1;
         reg32_t s_MSKWDG1L:1;
         reg32_t s_MSKWDG0H:1;
         reg32_t s_MSKWDG0L:1;
      } u_B;
   } s_WTIMR;

   /* reserved area */
   uint8_t s_reserved1[8];

   /* DMA Enable Register */
   union
   {
      reg32_t u_R;
      struct
      {
         reg32_t  :30;
         reg32_t s_DCLR:1;
         reg32_t s_DMAEN:1;
      } u_B;
   } s_DMAE;

   /* Internal Channel DMA Select Register */
   union
   {
      reg32_t u_R;
      struct
      {
         reg32_t s_DS_CHx:32;
      } u_B;
   } s_ICDSR[3];

   /* reserved area */
   uint8_t s_reserved2[16];

   /* Watchdog Threshold Register */
   union
   {
      reg32_t u_R;
      struct
      {
         reg32_t  :4;
         reg32_t s_THRH:12;
         reg32_t  :4;
         reg32_t s_THRL:12;
      } u_B;
   } s_WTHRHLR[4];

   /* reserved area */
   uint8_t s_reserved3[36];

   /* Conversion Timing Register */
   union
   {
      reg32_t u_R;
      struct
      {
         reg32_t s_CRES:1;
         reg32_t  :19;
         reg32_t s_PRECHG:4;
         reg32_t s_INPSAMP:8;
      } u_B;
   } s_CTR[4];

   /* Internal Channel Normal Conversion Mask Register */
   union
   {
      reg32_t u_R;
      struct
      {
         reg32_t s_NCE_CHx:32;
      } u_B;
   } s_ICNCMR[3];

   /* reserved area */
   uint8_t s_reserved4[4];

   /* Internal Channel Injected Conversion Mask Register */
   union
   {
      reg32_t u_R;
      struct
      {
         reg32_t s_JCE_CH:32;
      } u_B;
   } s_ICJCMR[3];

   /* reserved area */
   uint8_t s_reserved5[8];

   /* Power Down Exit Delay Register */
   union
   {
      reg32_t u_R;
      struct
      {
         reg32_t  :24;
         reg32_t s_PDED:8;
      } u_B;
   } s_PDEDR;

   /* reserved area */
   uint8_t s_reserved6[52];

   /* Internal Channel Data Register */
   PACKED_U32 union
   {
      reg32_t u_R;
      PACKED_U32 struct
      {
         reg32_t  :1;
         reg32_t s_REFSEL:1;
         reg32_t  :2;
         reg32_t s_PCE:1;
         reg32_t  :1;
         reg32_t s_CTSEL:2;
         reg32_t  :4;
         reg32_t s_VALID:1;
         reg32_t s_OVERW:1;
         reg32_t s_RESULT:2;
         reg32_t s_CDATA:16;
      } u_B;
   } s_ICDR[96];

   /* reserved area */
   uint8_t s_reserved7[48];

   /* Internal Channel Watchdog Selection Register */
   union
   {
      reg32_t u_R;
      struct
      {
         reg32_t s_WSEL_CH7:4;
         reg32_t s_WSEL_CH6:4;
         reg32_t s_WSEL_CH5:4;
         reg32_t s_WSEL_CH4:4;
         reg32_t s_WSEL_CH3:4;
         reg32_t s_WSEL_CH2:4;
         reg32_t s_WSEL_CH1:4;
         reg32_t s_WSEL_CH0:4;
      } u_B;
   } s_ICWSELR[12];

   /* Internal Channel Watchdog Enable Register */
   union
   {
      reg32_t u_R;
      struct
      {
         reg32_t s_WEN_CHx:32;
      } u_B;
   } s_ICWENR[3];

   /* reserved area */
   uint8_t s_reserved8[4];

   /* Internal Channel Analog Watchdog Out of Range register */
   union
   {
      reg32_t u_R;
      struct
      {
         reg32_t s_AWOR_CHx:32;
      } u_B;
   } s_ICAWORR[3];

   /* reserved area */
   uint8_t s_reserved9[260];

   /* Test Channel Interrupt Pending Register */
   union
   {
      reg32_t u_R;
      struct
      {
         reg32_t s_EOC_CHx:32;
      } u_B;
   } s_TCIPR;

   /* Test Channel Interrupt Mask Register */
   union
   {
      reg32_t u_R;
      struct
      {
         reg32_t s_IM_CHx:32;
      } u_B;
   } s_TCIMR;

   /* Test Channel DMA Select Register */
   union
   {
      reg32_t u_R;
      struct
      {
         reg32_t s_DS_CHx:32;
      } u_B;
   } s_TCDSR;

   /* Test Channel Normal Conversion Mask Register */
   union
   {
      reg32_t u_R;
      struct
      {
         reg32_t s_NCE_CHx:32;
      } u_B;
   } s_TCNCMR;

   /* Test Channel Injected Conversion Mask Register */
   union
   {
      reg32_t u_R;
      struct
      {
         reg32_t s_JCE_CHx:32;
      } u_B;
   } s_TCJCMR;

   /* Test Channel Watchdog Selection Register */
   union
   {
      reg32_t u_R;
      struct
      {
         reg32_t s_WSEL_CHa:4;
         reg32_t s_WSEL_CHb:4;
         reg32_t s_WSEL_CHc:4;
         reg32_t s_WSEL_CHd:4;
         reg32_t s_WSEL_CHe:4;
         reg32_t s_WSEL_CHf:4;
         reg32_t s_WSEL_CHg:4;
         reg32_t s_WSEL_CHh:4;
      } u_B;
   } s_TCWSELR[4];

   /* Test Channel Watchdog Enable Register */
   union
   {
      reg32_t u_R;
      struct
      {
         reg32_t s_WEN_CHx:32;
      } u_B;
   } s_TCWENR;

   /* Test Channel Analog Watchdog Out of Range Register */
   union
   {
      reg32_t u_R;
      struct
      {
         reg32_t s_AWOR_CHx:32;
      } u_B;
   } s_TCAWORR;

   /* reserved area */
   uint8_t s_reserved10[4];

   /* Test Channel Connection with Analog Pin Register */
   union
   {
      reg32_t u_R;
      struct
      {
         reg32_t s_ESIC_TCH3:1;
         reg32_t s_ICSEL_TCH3:7;
         reg32_t s_ESIC_TCH2:1;
         reg32_t s_ICSEL_TCH2:7;
         reg32_t s_ESIC_TCH1:1;
         reg32_t s_ICSEL_TCH1:7;
         reg32_t s_ESIC_TCH0:1;
         reg32_t s_ICSEL_TCH0:7;
      } u_B;
   } s_TCCAPR[8];

   /* Test Channel Data Register */
   union
   {
      reg32_t u_R;
      struct
      {
         reg32_t  :1;
         reg32_t s_REFSEL:1;
         reg32_t  :2;
         reg32_t s_PCE:1;
         reg32_t  :1;
         reg32_t s_CTSEL:2;
         reg32_t  :4;
         reg32_t s_VALID:1;
         reg32_t s_OVERW:1;
         reg32_t s_RESULT:2;
         reg32_t s_CDATA:16;
      } u_B;
   } s_TCDR[32];

   /* reserved area */
   uint8_t s_reserved11[48];

   /* External Channel Decode Signals Delay Register */
   union
   {
      reg32_t u_R;
      struct
      {
         reg32_t  :20;
         reg32_t s_DSD:12;
      } u_B;
   } s_ECDSDR;

   /* reserved area */
   uint8_t s_reserved12[12];

   /* External Channel Interrupt Pending Register */
   union
   {
      reg32_t u_R;
      struct
      {
         reg32_t s_EOC_CHx:32;
      } u_B;
   } s_ECIPR[4];

   /* External Channel Interrupt Mask Register */
   union
   {
      reg32_t u_R;
      struct
      {
         reg32_t s_IM_CHx:32;
      } u_B;
   } s_ECIMR[4];

   /* External Channel DMA Select Register */
   union
   {
      reg32_t u_R;
      struct
      {
         reg32_t s_DS_CHx:32;
      } u_B;
   } s_ECDSR[4];

   /* External Channel Normal Conversion Mask Register */
   union
   {
      reg32_t u_R;
      struct
      {
         reg32_t s_NCE_CHx:32;
      } u_B;
   } s_ECNCMR[4];

   /* External Channel Injected Conversion Mask Register */
   union
   {
      reg32_t u_R;
      struct
      {
         reg32_t s_JCE_CHx:32;
      } u_B;
   } s_ECJCMR[4];

   /* External Channel Watchdog Selection Register */
   PACKED_U32 union
   {
      reg32_t u_R;
      PACKED_U32 struct
      {
         reg32_t s_WSEL_CHa:4;
         reg32_t s_WSEL_CHb:4;
         reg32_t s_WSEL_CHc:4;
         reg32_t s_WSEL_CHd:4;
         reg32_t s_WSEL_CHe:4;
         reg32_t s_WSEL_CHf:4;
         reg32_t s_WSEL_CHg:4;
         reg32_t s_WSEL_CHh:4;
      } u_B;
   } s_ECWSELR[16];

   /* External Channel Watchdog Enable Register */
   union
   {
      reg32_t u_R;
      struct
      {
         reg32_t s_WEN_CHx:32;
      } u_B;
   } s_ECWENR[4];

   /* External Channel Analog Watchdog Out of Range register */
   union
   {
      reg32_t u_R;
      struct
      {
         reg32_t s_AWOR_CHx:32;
      } u_B;
   } s_ECAWORR[4];

   /* External Channel Mapping to Internal Channel Register */
   union
   {
      reg32_t u_R;
      struct
      {
         reg32_t  :1;
         reg32_t s_ICSEL_ECH152_159:7;
         reg32_t  :1;
         reg32_t s_ICSEL_ECH144_151:7;
         reg32_t  :1;
         reg32_t s_ICSEL_ECH136_143:7;
         reg32_t  :1;
         reg32_t s_ICSEL_ECH128_135:7;
      } u_B;
   } s_ECMICR[4];

   /* External Channel Data Register */
   union
   {
      reg32_t u_R;
      struct
      {
         reg32_t  :1;
         reg32_t s_REFSEL:1;
         reg32_t  :2;
         reg32_t s_PCE:1;
         reg32_t  :1;
         reg32_t s_CTSEL:2;
         reg32_t  :4;
         reg32_t s_VALID:1;
         reg32_t s_OVERW:1;
         reg32_t s_RESULT:2;
         reg32_t s_CDATA:16;
      } u_B;
   } s_ECDR[128];
}
ts_ADC_CTRL_TYPE;

/* }}RELAX<SYNCHRONe_C_Code_6.6,SYNCHRONe_C_Code_7.2> */

/* ---------- provided types: ----------------------------------------------- */

/* ADC data */
typedef struct
{
   /* HW descriptor */
   ts_ADC_CTRL_TYPE * s_adc_reg_descr_pt;
}
ts_ADC_DESCR_TYPE;

/* ---------- provided constants: ------------------------------------------- */
/* */
/* Table for ADC controler registers */
extern ts_ADC_CTRL_TYPE *  const c_ADC_ctrler_pt[ADC_CFEX_LINE_MAX_NB];

/* ---------- provided data: ------------------------------------------------ */

/* ---------- provided operations: ------------------------------------------ */

#endif /* ADC_REG_COMMON_H */
