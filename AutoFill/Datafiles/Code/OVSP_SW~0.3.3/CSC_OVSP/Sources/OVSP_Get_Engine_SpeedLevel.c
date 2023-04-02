#include "OVSP_Public.h"
#include "OVSP_Private.h"
#include "OVSP_SW_Public.h"
#include "MCP_Types.h"

 TE_OVSP_SW_Speed_Level OVSP_Get_Engine_SpeedLevel (void) {    return ((TE_OVSP_SW_Speed_Level) V_OVSP_Context_Out.V_Engine_SpeedLevel); }
