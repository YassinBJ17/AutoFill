#include "DrvMCM_Public.h"
#include "DrvMCM_Private.h"
#include "MCP_Types.h"
#include "DrvCPU_Public.h"
#include "OVSP_SW_Public.h"

 void DrvMCM_Check_CBIT_FPU_FIDC (uint32_t * p_pt_Check_Result) {       if (V_DrvMCM_CBIT_FPU_FIDC_status == OVSP_SW_RESULT_OK)    {       *p_pt_Check_Result = OVSP_SW_RESULT_OK;    }    else    {       *p_pt_Check_Result = OVSP_SW_RESULT_FAILED;      } }
