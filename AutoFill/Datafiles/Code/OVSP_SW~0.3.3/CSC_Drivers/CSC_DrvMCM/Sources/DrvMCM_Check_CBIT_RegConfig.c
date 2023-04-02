#include "DrvMCM_Public.h"
#include "DrvMCM_Private.h"
#include "MCP_Types.h"
#include "OVSP_SW_Public.h"

 void DrvMCM_Check_CBIT_RegConfig (uint32_t * p_pt_Check_Result) {    uint32_t v_FPU_int_flags;    v_FPU_int_flags = C_DrvMCM_Registers->S_ISCR;    if ((DRVMCM_CBIT_VALID_CONFIG_1 == v_FPU_int_flags) ||         (DRVMCM_CBIT_VALID_CONFIG_2 == v_FPU_int_flags))    {       *p_pt_Check_Result = OVSP_SW_RESULT_OK;    }    else    {       *p_pt_Check_Result = OVSP_SW_RESULT_FAILED;    } }
