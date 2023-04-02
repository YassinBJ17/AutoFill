/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the DrvADC CSC initialization function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "DrvADC_Public.h"
#include "DrvADC_Private.h"


/* ---------- include required interface: ----------------------------------- */
/* None */


/* ---------- internal define constants: ------------------------------------ */
/* None */


/* ---------- internal types: ----------------------------------------------- */
/* None */


/* ---------- provided constants: ------------------------------------------- */
/* None */


/* ---------- provided data: ------------------------------------------------ */
/* None */


/* ---------- internal constants: ------------------------------------------- */
/* None */


/* ---------- internal data: ------------------------------------------------ */
/* None */


/* ---------- internal operations: ------------------------------------------ */
/* None */


/* ---------- provided operation bodies: ------------------------------------ */
/* DrvADC_Initialize : To initialize the DrvADC CSC
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void DrvADC_Initialize (void)
{
   /* ADC0 initialization */
   C_DrvADC_Registers [DRVADC_ADC0_ID]->S_SC1 [DRVADC_SC1A_ID] = DRVADC_SC1A_CAM_HS_CURRENT;

   C_DrvADC_Registers [DRVADC_ADC0_ID]->S_CFG1 = DRVADC_ADC0_CFG1_CONFIG;
   C_DrvADC_Registers [DRVADC_ADC0_ID]->S_CFG2 = DRVADC_ADC0_CFG2_CONFIG;

   C_DrvADC_Registers [DRVADC_ADC0_ID]->S_SC2 = DRVADC_ADC0_SC2_CONFIG;

   /* ADC1 initialization */
   C_DrvADC_Registers [DRVADC_ADC1_ID]->S_SC1 [DRVADC_SC1A_ID] = DRVADC_SC1A_TEMPERATURE;

   C_DrvADC_Registers [DRVADC_ADC1_ID]->S_CFG1 = DRVADC_ADC1_CFG1_CONFIG;
   C_DrvADC_Registers [DRVADC_ADC1_ID]->S_CFG2 = DRVADC_ADC1_CFG2_CONFIG;

   C_DrvADC_Registers [DRVADC_ADC1_ID]->S_SC2 = DRVADC_ADC1_SC2_CONFIG;
}
