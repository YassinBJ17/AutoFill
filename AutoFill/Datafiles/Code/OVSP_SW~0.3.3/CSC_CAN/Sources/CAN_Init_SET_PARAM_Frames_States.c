#include "CAN_Public.h"
#include "CAN_Private.h"
#include "Config_Public.h"
#include "IO_Public.h"
#include "Modes_Public.h"
#include "OVSP_Public.h"
#include "OVSP_SW_Public.h"
#include "MCP_Types.h"

 void CAN_Init_SET_PARAM_Frames_States (void) {    uint32_t v_Iter_SET_PARAM;    for (v_Iter_SET_PARAM = 0UL; v_Iter_SET_PARAM < (CAN_SET_PARAM_FRAMES_NB + 1UL) ; v_Iter_SET_PARAM++)    {       V_CAN_SET_PARAM_Frames_States [v_Iter_SET_PARAM] = E_CAN_Frame_Cmd_Idle;    } }
