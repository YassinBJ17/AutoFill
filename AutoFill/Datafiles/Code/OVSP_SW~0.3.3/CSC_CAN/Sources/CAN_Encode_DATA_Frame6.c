#include "CAN_Private.h"
#include "Config_Public.h"
#include "DrvCAN_Public.h"
#include "IO_Public.h"
#include "OVSP_Public.h"
#include "OVSP_SW_Public.h"

 void CAN_Encode_DATA_Frame6 (void) {    TU_OVSP_SW_Uint32_Float32 v_Test_Speed_Measure;    v_Test_Speed_Measure.U_Value_32BitFloat = OVSP_Get_Test_Speed_Measure ();    V_CAN_DATA_Frames [CAN_DATA_FRAME06_INDEX].S_TxId = CAN_DATA_FRAME06_ID | V_CAN_GET_DATA_FC;    V_CAN_DATA_Frames [CAN_DATA_FRAME06_INDEX].S_TxData [OVSP_SW_LONG_0] = v_Test_Speed_Measure.U_Value_32BitUint;    V_CAN_DATA_Frames [CAN_DATA_FRAME06_INDEX].S_TxData [OVSP_SW_LONG_1] = CAN_UNUSED_LONG_DATA; }
