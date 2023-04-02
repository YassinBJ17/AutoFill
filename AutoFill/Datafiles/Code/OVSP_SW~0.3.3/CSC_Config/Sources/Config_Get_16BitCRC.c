#include "Config_Public.h"
#include "Config_Private.h"
#include "DrvFTFC_Public.h"
#include "OVSP_SW_Public.h"
#include "MCP_Types.h"

 void Config_Get_16BitCRC (uint8_t * const p_pt_16BitCRC_MSB, uint8_t * const p_pt_16BitCRC_LSB) {    *p_pt_16BitCRC_MSB = V_Config_OVSP_Cfg_Used.U_Fields.S_16BitCRC_MSB;    *p_pt_16BitCRC_LSB = V_Config_OVSP_Cfg_Used.U_Fields.S_16BitCRC_LSB; }
