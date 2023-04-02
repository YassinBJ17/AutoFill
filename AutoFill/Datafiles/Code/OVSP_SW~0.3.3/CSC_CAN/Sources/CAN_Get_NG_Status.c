#include "CAN_Public.h"
#include "CAN_Private.h"
#include "Config_Public.h"
#include "IO_Public.h"
#include "Modes_Public.h"
#include "OVSP_Public.h"
#include "OVSP_SW_Public.h"
#include "MCP_Types.h"

 uint8_t CAN_Get_NG_Status (void) {    TU_CAN_NG_Status v_NG_Status;    v_NG_Status.U_Fields.S_NGOS1_OutOfTime = (uint8_t) OVSP_Get_NGOS1_OutOfTime ();    v_NG_Status.U_Fields.S_NGOS2_OutOfTime = (uint8_t) OVSP_Get_NGOS2_OutOfTime ();    v_NG_Status.U_Fields.S_NGOS1_Updated = (uint8_t) OVSP_Get_NGOS1_Updated ();    v_NG_Status.U_Fields.S_NGOS2_Updated = (uint8_t) OVSP_Get_NGOS2_Updated ();    v_NG_Status.U_Fields.S_NGOS1_OutOfRangeHigh = (uint8_t) OVSP_Get_NGOS1_OutOfHigh ();    v_NG_Status.U_Fields.S_NGOS2_OutOfRangeHigh = (uint8_t) OVSP_Get_NGOS2_OutOfHigh ();    v_NG_Status.U_Fields.S_NG_Status_Unused = CAN_UNUSED_BYTE_DATA;    return (v_NG_Status.U_Value); }
