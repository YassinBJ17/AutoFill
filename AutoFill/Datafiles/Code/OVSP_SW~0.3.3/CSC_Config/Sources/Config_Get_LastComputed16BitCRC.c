#include "Config_Public.h"
#include "Config_Private.h"
#include "DrvFTFC_Public.h"
#include "OVSP_SW_Public.h"
#include "MCP_Types.h"

 void Config_Get_LastComputed16BitCRC (uint8_t * const p_pt_16BitCRC_MSB, uint8_t * const p_pt_16BitCRC_LSB) {    *p_pt_16BitCRC_MSB = V_Last_Computed_16BitCRC.U_Array_8BitUint [OVSP_SW_BYTE_0];    *p_pt_16BitCRC_LSB = V_Last_Computed_16BitCRC.U_Array_8BitUint [OVSP_SW_BYTE_1]; }
