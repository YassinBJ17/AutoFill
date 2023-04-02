/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef DRVADC_PRIVATE_H
#define DRVADC_PRIVATE_H

/* ---------- include required interface: ----------------------------------- */
#include "MCP_Types.h"


/* ---------- Linker command file symbol: ----------------------------------- */
/* None */


/* ---------- provided define constants: ------------------------------------ */
#define DRVADC_MAX_CTRL_NB           2UL

#define DRVADC_ADC0_ID               0UL
#define DRVADC_ADC1_ID               1UL

#define DRVADC_ADC0_ADDRESS          0x4003B000UL
#define DRVADC_ADC1_ADDRESS          0x40027000UL


#define DRVADC_ADC0_CFG1_CONFIG      0x00000044UL
#define DRVADC_ADC0_CFG2_CONFIG      0x000000FFUL
#define DRVADC_ADC0_SC2_CONFIG       0x00000000UL

#define DRVADC_ADC1_CFG1_CONFIG      0x00000044UL
#define DRVADC_ADC1_CFG2_CONFIG      0x0000000AUL
#define DRVADC_ADC1_SC2_CONFIG       0x00000000UL


#define DRVADC_SC1_NB                16UL
#define DRVADC_R_NB                  16UL
#define DRVADC_CV_NB                  2UL


#define DRVADC_SC1A_ID               0UL

#define DRVADC_SC1A_CAM_HS_CURRENT   4UL
#define DRVADC_SC1A_CAM_LS_CURRENT   5UL
#define DRVADC_SC1A_CAM_VLOAD        6UL
#define DRVADC_SC1A_TEMPERATURE      4UL


#define DRVADC_ANALOG_MAX_NB         4UL

#define DRVADC_CAM_HS_CURRENT_GAIN   0.001141167f
#define DRVADC_CAM_LS_CURRENT_GAIN   0.000893197f
#define DRVADC_CAM_VLOAD_GAIN        0.016784668f
#define DRVADC_TEMPERATURE_GAIN      0.0579614f
#define DRVADC_TEMPERATURE_OFFSET    57.0144f

#define DRVADC_SC1_ADCH_MASK         0x0000001FUL


/* ---------- provided types: ----------------------------------------------- */
typedef struct
{
   uint32_t S_SC1 [DRVADC_SC1_NB];
   uint32_t S_CFG1;
   uint32_t S_CFG2;
   uint32_t S_R [DRVADC_R_NB];
   uint32_t S_CV [DRVADC_CV_NB];
   uint32_t S_SC2;
   uint32_t S_SC3;
   uint32_t S_BASE_OFS;
   uint32_t S_OFS;
   uint32_t S_USR_OFS;
   uint32_t S_XOFS;
   uint32_t S_YOFS;
   uint32_t S_G;
   uint32_t S_UG;
   uint32_t S_CLPS;
   uint32_t S_CLP3;
   uint32_t S_CLP2;
   uint32_t S_CLP1;
   uint32_t S_CLP0;
   uint32_t S_CLPX;
   uint32_t S_CLP9;
   uint32_t S_CLPS_OFS;
   uint32_t S_CLP3_OFS;
   uint32_t S_CLP2_OFS;
   uint32_t S_CLP1_OFS;
   uint32_t S_CLP0_OFS;
   uint32_t S_CLPX_OFS;
   uint32_t S_CLP9_OFS;
} TS_DrvADC_Registers;

typedef struct
{
   uint32_t  S_Controller_Id;
   uint32_t  S_SC1A_Value;
   float32_t S_ADC_Gain;
   float32_t S_ADC_Offset;
} TS_DrvADC_Port_Definition;


/* ---------- provided constants: ------------------------------------------- */
extern TS_DrvADC_Registers * const C_DrvADC_Registers [DRVADC_MAX_CTRL_NB];

extern const TS_DrvADC_Port_Definition C_DrvADC_Port_Def [DRVADC_ANALOG_MAX_NB];


/* ---------- provided data: ------------------------------------------------ */
/* None */


/* ---------- provided operations: ------------------------------------------ */
/* None */


#endif /* DRVADC_PRIVATE_H */
