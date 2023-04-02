#include "CAN_Public.h"
#include "CAN_Private.h"
#include "Config_Public.h"
#include "IO_Public.h"
#include "Modes_Public.h"
#include "OVSP_Public.h"
#include "OVSP_SW_Public.h"
#include "MCP_Types.h"

 void CAN_Init_SET_PARAM_Data (void) {    uint32_t v_Iter_32BitWord;    for (v_Iter_32BitWord = 0UL; v_Iter_32BitWord < CAN_SET_PARAM_32BIT_NB; v_Iter_32BitWord++)    {       V_CAN_SET_PARAM_Frames.U_Array_32BitUint [v_Iter_32BitWord] = OVSP_SW_LONG_MIN;    } }
