#include "Config_Private.h"
#include "OVSP_SW_Public.h"
#include "MCP_Types.h"

    for (v_Iter_Area = 0UL; v_Iter_Area < p_Length ; v_Iter_Area++)    {       v_Table_Index =          (((uint8_t) (v_16BitCRC_Result >> OVSP_SW_DEC_1BYTE)) ^ (p_pt_StartAddr [v_Iter_Area])) & OVSP_SW_BYTE_MAX;       v_16BitCRC_Result = v_16BitCRC_Result << OVSP_SW_DEC_1BYTE;       v_16BitCRC_Result = v_16BitCRC_Result ^ c_Config_16BitCRC_Table [v_Table_Index];    }
