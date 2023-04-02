#include "CAN_Public.h"
#include "CAN_Private.h"
#include "Config_Public.h"
#include "IO_Public.h"
#include "Modes_Public.h"
#include "OVSP_Public.h"
#include "OVSP_SW_Public.h"
#include "MCP_Types.h"

 uint8_t CAN_Get_OVS_Status (void) {    TU_CAN_OVS_Status v_OVS_Status;    TE_Modes_SW_Mode v_SW_Mode;    v_OVS_Status.U_Fields.S_CMD1_Status = (uint8_t) OVSP_Get_CAM_Cmd1 ();    v_OVS_Status.U_Fields.S_CMD2_Status = (uint8_t) OVSP_Get_CAM_Cmd2 ();    v_SW_Mode = Modes_Get_SW_Mode ();    if (E_Modes_TriggeredTest == v_SW_Mode)    {       v_OVS_Status.U_Fields.S_Mode = (uint8_t) 1;    }    else    {       v_OVS_Status.U_Fields.S_Mode = (uint8_t) 0;    }    if (E_CAN_Frame_Cmd_Recv_OK == V_CAN_OVSP_Config_Recv_Status)    {       v_OVS_Status.U_Fields.S_OVSP_Config_Reception = (uint8_t) 0;    }    else    {       v_OVS_Status.U_Fields.S_OVSP_Config_Reception = (uint8_t) 1;    }    v_OVS_Status.U_Fields.S_OVSP_Config_Integrity = (uint8_t) Config_Get_Integrity_Status ();    v_OVS_Status.U_Fields.S_OVS_Status_Unused = CAN_UNUSED_BYTE_DATA;    return (v_OVS_Status.U_Value); }
