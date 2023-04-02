#include "CAN_Public.h"
#include "CAN_Private.h"
#include "Config_Public.h"
#include "IO_Public.h"
#include "Modes_Public.h"
#include "OVSP_Public.h"
#include "OVSP_SW_Public.h"
#include "MCP_Types.h"

 uint8_t CAN_Get_DIN_Status (void) {    TU_CAN_DIN_Status v_DIN_Status;    v_DIN_Status.U_Fields.S_DININHIB  = (uint8_t) IO_Get_DININHIB_Cmd ();    v_DIN_Status.U_Fields.S_OSREARM   = (uint8_t) IO_Get_OSREARM_Cmd ();    v_DIN_Status.U_Fields.S_NTLOSTEST = (uint8_t) IO_Get_NTLOSTEST_Cmd ();    v_DIN_Status.U_Fields.S_DIN_Status_Unused = CAN_UNUSED_BYTE_DATA;    return (v_DIN_Status.U_Value); }
