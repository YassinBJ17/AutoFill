#include "Config_Public.h"
#include "Config_Private.h"
#include "DrvFTFC_Public.h"
#include "OVSP_SW_Public.h"
#include "MCP_Types.h"

 uint8_t Config_Get_OVS_OneSensorNGInhib (void) {    return (V_Config_OVSP_Cfg_Used.U_Fields.S_OVS_OneSensorNGInhib); }
