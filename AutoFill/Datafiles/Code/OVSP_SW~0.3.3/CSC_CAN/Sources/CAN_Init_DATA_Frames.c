#include "CAN_Public.h"
#include "CAN_Private.h"
#include "Config_Public.h"
#include "IO_Public.h"
#include "Modes_Public.h"
#include "OVSP_Public.h"
#include "OVSP_SW_Public.h"
#include "MCP_Types.h"

 void CAN_Init_DATA_Frames (void) {    uint32_t v_Iter_DATA;    for (v_Iter_DATA = 0UL; v_Iter_DATA < CAN_DATA_FRAME_NB; v_Iter_DATA++)    {       V_CAN_DATA_Frames [v_Iter_DATA].S_TxId = OVSP_SW_LONG_MAX;       V_CAN_DATA_Frames [v_Iter_DATA].S_TxData [OVSP_SW_LONG_0] = OVSP_SW_LONG_MAX;       V_CAN_DATA_Frames [v_Iter_DATA].S_TxData [OVSP_SW_LONG_1] = OVSP_SW_LONG_MAX;    } }
