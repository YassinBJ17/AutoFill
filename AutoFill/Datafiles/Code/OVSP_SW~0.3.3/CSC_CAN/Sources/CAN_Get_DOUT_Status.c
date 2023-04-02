#include "CAN_Public.h"
#include "CAN_Private.h"
#include "Config_Public.h"
#include "IO_Public.h"
#include "Modes_Public.h"
#include "OVSP_Public.h"
#include "OVSP_SW_Public.h"
#include "MCP_Types.h"

 uint8_t CAN_Get_DOUT_Status (void) {    TU_CAN_DOUT_Status v_DOUT_Status;    v_DOUT_Status.U_Fields.S_DOUTINHIB_FB = (uint8_t) IO_Get_DOUTINHIB_FB ();    v_DOUT_Status.U_Fields.S_CAMLOW2_FB   = (uint8_t) IO_Get_CAMLOW2_FB ();    v_DOUT_Status.U_Fields.S_OSARM_FB     = (uint8_t) IO_Get_OSARM_FB ();    v_DOUT_Status.U_Fields.S_DOUT_Status_Unused = CAN_UNUSED_BYTE_DATA;    return (v_DOUT_Status.U_Value); }
