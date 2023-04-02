/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the DrvMCM CSC Utilities functions
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "DrvMCM_Public.h"
#include "DrvMCM_Private.h"


/* ---------- include required interface: ----------------------------------- */
#include "MCP_Types.h"
#include "OVSP_SW_Public.h"


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
/* DrvMCM_Check_RegConfig : To test the DrvMCM registers configuration during CBIT
 *   Inputs: None
 *   Outputs:
 *     - p_pt_Check_Result: Result of the check
 *   Function return: None
 *   Pre-condition: None
*/
void DrvMCM_Check_CBIT_RegConfig (uint32_t * p_pt_Check_Result)
{
   uint32_t v_FPU_int_flags;

   v_FPU_int_flags = C_DrvMCM_Registers->S_ISCR;

   if ((DRVMCM_CBIT_VALID_CONFIG_1 == v_FPU_int_flags) || 
       (DRVMCM_CBIT_VALID_CONFIG_2 == v_FPU_int_flags))
   {
      *p_pt_Check_Result = OVSP_SW_RESULT_OK;
   }
   else
   {
      *p_pt_Check_Result = OVSP_SW_RESULT_FAILED;
   }
}

/* DrvMCM_Check_PBIT_RegConfig : To test the DrvMCM registers configuration during PBIT
 *   Inputs: None
 *   Outputs:
 *     - p_pt_Check_Result: Result of the check
 *   Function return: None
 *   Pre-condition: None
*/
void DrvMCM_Check_PBIT_RegConfig (uint32_t * p_pt_Check_Result)
{
   uint32_t v_FPU_int_flags;

   v_FPU_int_flags = C_DrvMCM_Registers->S_ISCR;

   if ((DRVMCM_PBIT_VALID_CONFIG_1 == v_FPU_int_flags) || 
       (DRVMCM_PBIT_VALID_CONFIG_2 == v_FPU_int_flags))
   {
      *p_pt_Check_Result = OVSP_SW_RESULT_OK;
   }
   else
   {
      *p_pt_Check_Result = OVSP_SW_RESULT_FAILED;
   }
}
