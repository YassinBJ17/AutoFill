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
#include "DrvCPU_Public.h"
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
/* DrvMCM_Initialize : To initialize the DrvMCM CSC
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void DrvMCM_Initialize (void)
{
   C_DrvMCM_Registers->S_ISCR = DRVMCM_ISCR_CONFIG;

   V_DrvMCM_PBIT_FPU_FIOC_Cnt    = 0UL;
   V_DrvMCM_PBIT_FPU_FIOC_status = OVSP_SW_RESULT_FAILED;
   V_DrvMCM_PBIT_FPU_FDZC_status = OVSP_SW_RESULT_FAILED;
   V_DrvMCM_PBIT_FPU_FOFC_status = OVSP_SW_RESULT_FAILED;
   V_DrvMCM_PBIT_FPU_FUFC_status = OVSP_SW_RESULT_FAILED;
   V_DrvMCM_PBIT_FPU_FIXC_status = OVSP_SW_RESULT_FAILED;
   V_DrvMCM_PBIT_FPU_FIDC_status = OVSP_SW_RESULT_FAILED;

   V_DrvMCM_CBIT_FPU_FIOC_status = OVSP_SW_RESULT_OK;
   V_DrvMCM_CBIT_FPU_FDZC_status = OVSP_SW_RESULT_OK;
   V_DrvMCM_CBIT_FPU_FOFC_status = OVSP_SW_RESULT_OK;
   V_DrvMCM_CBIT_FPU_FUFC_status = OVSP_SW_RESULT_OK;
   V_DrvMCM_CBIT_FPU_FIDC_status = OVSP_SW_RESULT_OK;
}
