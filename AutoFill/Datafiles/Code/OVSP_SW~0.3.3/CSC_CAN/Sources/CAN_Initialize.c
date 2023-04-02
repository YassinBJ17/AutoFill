/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the CAN CSC initialization function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "CAN_Private.h"


/* ---------- include required interface: ----------------------------------- */
#include "OVSP_SW_Public.h"
#include "MCP_Types.h"


/* ---------- internal define constants: ------------------------------------ */
/* None */


/* ---------- internal types: ----------------------------------------------- */
/* None */


/* ---------- provided constants: ------------------------------------------- */
/* None */


/* ---------- provided data: ------------------------------------------------ */
/* None */


/* ---------- internal constants: ------------------------------------------- */
/* None */


/* ---------- internal data: ------------------------------------------------ */
/* None */


/* ---------- internal operations: ------------------------------------------ */
/* None */


/* ---------- provided operation bodies: ------------------------------------ */
/* CAN_Initialize : To initialize the CAN CSC
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void CAN_Initialize (void)
{
   V_CAN_Compatibility_Status = TRUE;

   CAN_Init_SET_PARAM_Data ();

   V_CAN_OVSP_Config_16BitCRC_Recv = OVSP_SW_WORD_MIN;

   CAN_Init_SET_PARAM_Frames_States ();

   V_CAN_OVSP_Config_Recv_Status = E_CAN_Frame_Cmd_Recv_KO;

   V_CAN_TriggTest_cmd = E_CAN_TriggTest_Off;
   V_CAN_Test_Speed.U_Value_32BitFloat = 0.0f;

   V_CAN_TestDiscrete_Cmd = E_OVSP_SW_Cmd_Off;

   V_CAN_CAM_Cmd_1 = E_OVSP_SW_Cmd_Off;
   V_CAN_CAM_Cmd_2 = E_OVSP_SW_Cmd_Off;
   V_CAN_CAM_Timing = CAN_CAM_CMD_TIMEOUT;

   V_CAN_OSARM_Rqst = E_OVSP_SW_NotRequested;
   V_CAN_REARM_Rqst = E_OVSP_SW_NotRequested;
   V_CAN_REARM_Timing = CAN_REARM_RQST_TIMEOUT;

   V_CAN_GET_DATA_Received = FALSE;
   V_CAN_GET_DATA_FC = 0UL;

   CAN_Init_DATA_Frames ();

   V_CAN_DATA_FrameToSend = CAN_DATA_FRAME01_INDEX;

   V_CAN_NG_Status  = (uint8_t) 0;
   V_CAN_NTL_Status = (uint8_t) 0;

   V_CAN_NG_Status_Prev = (uint8_t) 0;
   V_CAN_NTL_Status_Prev = (uint8_t) 0;

   V_CAN_NG_NTL_Statuses_Sent = FALSE;

   V_CAN_NTL_OneSensor_CSSAuth = E_OVSP_SW_NotAuthorized;
   V_CAN_NG_OneSensor_CSSAuth = E_OVSP_SW_NotAuthorized;
}
