/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the DrvADC registers configuration
 *               check function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "DrvADC_Public.h"
#include "DrvADC_Private.h"


/* ---------- include required interface: ----------------------------------- */
#include "OVSP_SW_Public.h"
#include "MCP_Types.h"


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
/* DrvADC_Check_RegConfig : To test the DrvADC registers configuration
 *   Inputs: None
 *   Outputs:
 *     - p_pt_Check_Result: Result of the check
 *   Function return: None
 *   Pre-condition: None
*/
void DrvADC_Check_RegConfig (uint32_t * const p_pt_Check_Result)
{
   if ((DRVADC_ADC0_CFG1_CONFIG != C_DrvADC_Registers [DRVADC_ADC0_ID]->S_CFG1) ||
       (DRVADC_ADC0_CFG2_CONFIG != C_DrvADC_Registers [DRVADC_ADC0_ID]->S_CFG2) ||
       (DRVADC_ADC0_SC2_CONFIG != C_DrvADC_Registers [DRVADC_ADC0_ID]->S_SC2))
   {
      *p_pt_Check_Result = OVSP_SW_RESULT_FAILED;
   }
   else
   {
      if ((DRVADC_ADC1_CFG1_CONFIG != C_DrvADC_Registers [DRVADC_ADC1_ID]->S_CFG1) ||
          (DRVADC_ADC1_CFG2_CONFIG != C_DrvADC_Registers [DRVADC_ADC1_ID]->S_CFG2) ||
          (DRVADC_ADC1_SC2_CONFIG != C_DrvADC_Registers [DRVADC_ADC1_ID]->S_SC2))
      {
         *p_pt_Check_Result = OVSP_SW_RESULT_FAILED;
      }
      else
      {
         *p_pt_Check_Result = OVSP_SW_RESULT_OK;
      }
   }
}
