#include "Config_Public.h"
#include "Config_Private.h"
#include "DrvFTFC_Public.h"
#include "OVSP_SW_Public.h"
#include "MCP_Types.h"

 void Config_Reset_OVSP_Cfg (TU_Config_OVSP_Cfg * const p_pt_Config) {    uint32_t v_Iter_32BitWord;    for (v_Iter_32BitWord = 0UL; v_Iter_32BitWord < CONFIG_FIRST_RESERVED_INDEX ; v_Iter_32BitWord++)    {       p_pt_Config->U_Array_32BitUint [v_Iter_32BitWord] = OVSP_SW_LONG_MIN;    }    for (v_Iter_32BitWord = CONFIG_FIRST_RESERVED_INDEX; v_Iter_32BitWord < DRVFTFC_CONFIG_32BIT_NB ; v_Iter_32BitWord++)    {       p_pt_Config->U_Array_32BitUint [v_Iter_32BitWord] = OVSP_SW_LONG_MAX;    } }
