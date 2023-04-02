#include "CAN_Private.h"
#include "Config_Public.h"
#include "DrvCAN_Public.h"
#include "IO_Public.h"
#include "OVSP_Public.h"
#include "OVSP_SW_Public.h"

 void CAN_Encode_DATA_Frame4 (void) {    TU_OVSP_SW_Uint32_Float32 v_CAM_VLoad;    TU_OVSP_SW_Uint32_Float32 v_CAM_HS_Current;    v_CAM_VLoad.U_Value_32BitFloat = IO_Get_CAM_Vload ();    v_CAM_HS_Current.U_Value_32BitFloat = IO_Get_CAM_HS_Current ();    V_CAN_DATA_Frames [CAN_DATA_FRAME04_INDEX].S_TxId = CAN_DATA_FRAME04_ID | V_CAN_GET_DATA_FC;    V_CAN_DATA_Frames [CAN_DATA_FRAME04_INDEX].S_TxData [OVSP_SW_LONG_0] = v_CAM_VLoad.U_Value_32BitUint;    V_CAN_DATA_Frames [CAN_DATA_FRAME04_INDEX].S_TxData [OVSP_SW_LONG_1] = v_CAM_HS_Current.U_Value_32BitUint; }
