/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the DrvPCC registers configuration
 *               check function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "DrvPCC_Public.h"
#include "DrvPCC_Private.h"


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
/* DrvPCC_Check_RegConfig : To test the DrvPCC registers configuration
 *   Inputs: None
 *   Outputs:
 *     - p_pt_Check_Result: Result of the check
 *   Function return: None
 *   Pre-condition: None
*/
void DrvPCC_Check_RegConfig (uint32_t * const p_pt_Check_Result)
{
   uint32_t v_Iter_PCC;
   uint32_t v_Expected_Result;

   *p_pt_Check_Result = OVSP_SW_RESULT_OK;

   for (v_Iter_PCC = 0UL; v_Iter_PCC < DRVPCC_PCC_USED_NB ; v_Iter_PCC++)
   {
      if (DRVPCC_PCS_CLOCK_NONE != C_DrvPCC_PCS_Config [v_Iter_PCC].S_PCS_Value)
      {
         v_Expected_Result = C_DrvPCC_PCS_Config [v_Iter_PCC].S_PCS_Value | DRVPCC_CGC_ENABLE_MASK;
      }
      else
      {
         v_Expected_Result = DRVPCC_CGC_ENABLE_MASK;
      }

      if (C_DrvPCC_Registers->S_PCC [C_DrvPCC_PCS_Config [v_Iter_PCC].S_Index] == v_Expected_Result)
      {
         *p_pt_Check_Result = OVSP_SW_RESULT_FAILED;
      }
   }
}
