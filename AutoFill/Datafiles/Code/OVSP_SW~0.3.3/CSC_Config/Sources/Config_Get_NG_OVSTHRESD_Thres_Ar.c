#include "Config_Public.h"
#include "Config_Private.h"
#include "DrvFTFC_Public.h"
#include "OVSP_SW_Public.h"
#include "MCP_Types.h"

 uint8_t Config_Get_NG_OVSTHRESD_Thres_Ar (const uint32_t p_Index) {    uint8_t v_Return_Value;    if (CONFIG_NTL_VAR_THRES_NB > p_Index)    {       v_Return_Value = V_Config_OVSP_Cfg_Used.U_Fields.S_NG_OVSTHRESD_Threshold_Ar [p_Index];    }    else    {       v_Return_Value = (uint8_t) 0;    }    return (v_Return_Value); }
