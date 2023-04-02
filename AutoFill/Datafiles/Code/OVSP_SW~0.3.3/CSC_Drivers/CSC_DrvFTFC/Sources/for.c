#include "DrvFTFC_Private.h"
#include "OVSP_SW_Public.h"
#include "MCP_Types.h"

    for (v_Iter_Area = 0UL; v_Iter_Area < p_Length ; v_Iter_Area++)    {       v_Table_Index =          (((uint8_t) (v_32BitCRC_Result >> OVSP_SW_DEC_3BYTES)) ^ (p_pt_StartAddr [v_Iter_Area])) & OVSP_SW_BYTE_MAX;       v_32BitCRC_Result = v_32BitCRC_Result << OVSP_SW_DEC_1BYTE;       v_32BitCRC_Result = v_32BitCRC_Result ^ c_DrvFTFC_32BitCRC_Table [v_Table_Index];    }
