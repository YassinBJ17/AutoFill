#include "CAN_Private.h"
#include "Config_Public.h"
#include "DrvCAN_Public.h"
#include "IO_Public.h"
#include "OVSP_Public.h"
#include "OVSP_SW_Public.h"

 void CAN_Encode_DATA_Frame1 (void) {    TU_OVSP_SW_Uint32_Uint8 v_Frame_Data_0;    TU_OVSP_SW_Uint32_Uint8 v_Frame_Data_1;    v_Frame_Data_0.U_Array_8BitUint [OVSP_SW_BYTE_0] = CAN_Get_DIN_Status ();    v_Frame_Data_0.U_Array_8BitUint [OVSP_SW_BYTE_1] = V_CAN_NTL_Status;    v_Frame_Data_0.U_Array_8BitUint [OVSP_SW_BYTE_2] = V_CAN_NG_Status;    v_Frame_Data_0.U_Array_8BitUint [OVSP_SW_BYTE_3] = CAN_Get_OVS_Status ();    Config_Get_LastComputed16BitCRC (&(v_Frame_Data_1.U_Array_8BitUint [OVSP_SW_BYTE_0]),                                     &(v_Frame_Data_1.U_Array_8BitUint [OVSP_SW_BYTE_1]));    v_Frame_Data_1.U_Array_8BitUint [OVSP_SW_BYTE_2] = CAN_UNUSED_BYTE_DATA;    v_Frame_Data_1.U_Array_8BitUint [OVSP_SW_BYTE_3] = CAN_Get_DOUT_Status ();    V_CAN_DATA_Frames [CAN_DATA_FRAME01_INDEX].S_TxId = CAN_DATA_FRAME01_ID | V_CAN_GET_DATA_FC;    V_CAN_DATA_Frames [CAN_DATA_FRAME01_INDEX].S_TxData [OVSP_SW_LONG_0] = v_Frame_Data_0.U_Value_32BitUint;    V_CAN_DATA_Frames [CAN_DATA_FRAME01_INDEX].S_TxData [OVSP_SW_LONG_1] = v_Frame_Data_1.U_Value_32BitUint; }
