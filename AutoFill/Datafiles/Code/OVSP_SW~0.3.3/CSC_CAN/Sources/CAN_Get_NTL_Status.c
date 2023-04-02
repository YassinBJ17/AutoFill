#include "CAN_Public.h"
#include "CAN_Private.h"
#include "Config_Public.h"
#include "IO_Public.h"
#include "Modes_Public.h"
#include "OVSP_Public.h"
#include "OVSP_SW_Public.h"
#include "MCP_Types.h"

 uint8_t CAN_Get_NTL_Status (void) {    TU_CAN_NTL_Status v_NTL_Status;    v_NTL_Status.U_Fields.S_NTLOS1_OutOfTime = (uint8_t) OVSP_Get_NTLOS1_OutOfTime ();    v_NTL_Status.U_Fields.S_NTLOS2_OutOfTime = (uint8_t) OVSP_Get_NTLOS2_OutOfTime ();    v_NTL_Status.U_Fields.S_NTLOS1_Updated = (uint8_t) OVSP_Get_NTLOS1_Updated ();    v_NTL_Status.U_Fields.S_NTLOS2_Updated = (uint8_t) OVSP_Get_NTLOS2_Updated ();    v_NTL_Status.U_Fields.S_NTLOS1_OutOfRangeHigh = (uint8_t) OVSP_Get_NTLOS1_OutOfHigh ();    v_NTL_Status.U_Fields.S_NTLOS2_OutOfRangeHigh = (uint8_t) OVSP_Get_NTLOS2_OutOfHigh ();    v_NTL_Status.U_Fields.S_NTL_Status_Unused = CAN_UNUSED_BYTE_DATA;    return (v_NTL_Status.U_Value); }
