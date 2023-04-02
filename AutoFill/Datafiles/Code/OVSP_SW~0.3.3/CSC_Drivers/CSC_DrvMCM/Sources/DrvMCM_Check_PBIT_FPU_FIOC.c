#include "DrvMCM_Public.h"
#include "DrvMCM_Private.h"
#include "MCP_Types.h"
#include "DrvCPU_Public.h"
#include "OVSP_SW_Public.h"

 void DrvMCM_Check_PBIT_FPU_FIOC (uint32_t * p_pt_Check_Result, uint32_t p_generated_errors) {    if ((V_DrvMCM_PBIT_FPU_FIOC_status == OVSP_SW_RESULT_OK) &&        (DRVMCM_FPU_FIOC_ERROR_NB == V_DrvMCM_PBIT_FPU_FIOC_Cnt) ||        (DRVMCM_FPU_FIOC_ERROR_NB == p_generated_errors))    {       *p_pt_Check_Result = OVSP_SW_RESULT_OK;    }    else    {       *p_pt_Check_Result = OVSP_SW_RESULT_FAILED;      } }
