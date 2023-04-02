#include "Config_Public.h"
#include "Config_Private.h"
#include "DrvFTFC_Public.h"
#include "OVSP_SW_Public.h"
#include "MCP_Types.h"

 void Config_Retrieve_From_FlexNVM (TU_Config_OVSP_Cfg * const p_pt_Config) {    uint32_t v_Iter_32BitWord;    TU_Config_OVSP_Cfg * pt_FlexNVM_Cfg;    pt_FlexNVM_Cfg = (TU_Config_OVSP_Cfg *) DRVFTFC_CONFIG_START_ADDR;    for (v_Iter_32BitWord = 0UL; v_Iter_32BitWord < DRVFTFC_CONFIG_32BIT_NB ; v_Iter_32BitWord++)    {       p_pt_Config->U_Array_32BitUint [v_Iter_32BitWord] = pt_FlexNVM_Cfg->U_Array_32BitUint [v_Iter_32BitWord];    } }
