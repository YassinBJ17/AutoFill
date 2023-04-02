/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the CAN CSC Utilities functions
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "CAN_Public.h"
#include "CAN_Private.h"


/* ---------- include required interface: ----------------------------------- */
#include "Config_Public.h"
#include "IO_Public.h"
#include "Modes_Public.h"
#include "OVSP_Public.h"

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
/* CAN_Init_SET_PARAM_Data : To initialize the SET_PARAM data
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void CAN_Init_SET_PARAM_Data (void)
{
   uint32_t v_Iter_32BitWord;

   for (v_Iter_32BitWord = 0UL; v_Iter_32BitWord < CAN_SET_PARAM_32BIT_NB; v_Iter_32BitWord++)
   {
      V_CAN_SET_PARAM_Frames.U_Array_32BitUint [v_Iter_32BitWord] = OVSP_SW_LONG_MIN;
   }
}


/* CAN_Init_SET_PARAM_Frames_States : To initialize the SET_PARAM frames states
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void CAN_Init_SET_PARAM_Frames_States (void)
{
   uint32_t v_Iter_SET_PARAM;

   for (v_Iter_SET_PARAM = 0UL; v_Iter_SET_PARAM < (CAN_SET_PARAM_FRAMES_NB + 1UL) ; v_Iter_SET_PARAM++)
   {
      V_CAN_SET_PARAM_Frames_States [v_Iter_SET_PARAM] = E_CAN_Frame_Cmd_Idle;
   }
}


/* CAN_Init_DATA_Frames : To initialize the DATA frames
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void CAN_Init_DATA_Frames (void)
{
   uint32_t v_Iter_DATA;

   for (v_Iter_DATA = 0UL; v_Iter_DATA < CAN_DATA_FRAME_NB; v_Iter_DATA++)
   {
      V_CAN_DATA_Frames [v_Iter_DATA].S_TxId = OVSP_SW_LONG_MAX;
      V_CAN_DATA_Frames [v_Iter_DATA].S_TxData [OVSP_SW_LONG_0] = OVSP_SW_LONG_MAX;
      V_CAN_DATA_Frames [v_Iter_DATA].S_TxData [OVSP_SW_LONG_1] = OVSP_SW_LONG_MAX;
   }
}


/* CAN_Get_TriggTest_Cmd : To provide the CAN Triggered Test command
 *   Inputs: None
 *   Outputs: None
 *   Function return: CAN Triggered Test command
 *   Pre-condition: None
*/
TE_CAN_TriggTest_Cmd CAN_Get_TriggTest_Cmd (void)
{
   /* >RELAX<SYNCHRONe_C_Code_16.12> Waiting for SYNCHONe analyze, it seems to be a false violation. */
   /* The returned data is of the function return type. */
   return (V_CAN_TriggTest_cmd);
}


/* CAN_Get_Test_Speed : To provide the CAN Triggered Test speed
 *   Inputs: None
 *   Outputs: None
 *   Function return: CAN Triggered Test speed
 *   Pre-condition: None
*/
float32_t CAN_Get_Test_Speed (void)
{
   return (V_CAN_Test_Speed.U_Value_32BitFloat);
}


/* CAN_Get_TestDiscrete_Cmd : To provide the CAN Discrete Test command
 *   Inputs: None
 *   Outputs: None
 *   Function return: CAN Discrete Test command
 *   Pre-condition: None
*/
TE_OVSP_SW_Cmd CAN_Get_TestDiscrete_Cmd (void)
{
   /* >RELAX<SYNCHRONe_C_Code_16.12> Waiting for SYNCHONe analyze, it seems to be a false violation. */
   /* The returned data is of the function return type. */
   return (V_CAN_TestDiscrete_Cmd);
}


/* CAN_Get_CAM_Cmd_1 : To provide the CAN CAM command 1
 *   Inputs: None
 *   Outputs: None
 *   Function return: CAN CAM command 1
 *   Pre-condition: None
*/
TE_OVSP_SW_Cmd CAN_Get_CAM_Cmd_1 (void)
{
   /* >RELAX<SYNCHRONe_C_Code_16.12> Waiting for SYNCHONe analyze, it seems to be a false violation. */
   /* The returned data is of the function return type. */
   return (V_CAN_CAM_Cmd_1);
}


/* CAN_Get_CAM_Cmd_2 : To provide the CAN CAM command 2
 *   Inputs: None
 *   Outputs: None
 *   Function return: CAN MesCAM command 2
 *   Pre-condition: None
*/
TE_OVSP_SW_Cmd CAN_Get_CAM_Cmd_2 (void)
{
   /* >RELAX<SYNCHRONe_C_Code_16.12> Waiting for SYNCHONe analyze, it seems to be a false violation. */
   /* The returned data is of the function return type. */
   return (V_CAN_CAM_Cmd_2);
}


/* CAN_Get_OSARM_Rqst : To provide the CAN OSARM request
 *   Inputs: None
 *   Outputs: None
 *   Function return: CAN OSARM request
 *   Pre-condition: None
*/
TE_OVSP_SW_Request CAN_Get_OSARM_Rqst (void)
{
   /* >RELAX<SYNCHRONe_C_Code_16.12> Waiting for SYNCHONe analyze, it seems to be a false violation. */
   /* The returned data is of the function return type. */
   return (V_CAN_OSARM_Rqst);
}


/* CAN_Get_REARM_Rqst : To provide the CAN REARM request
 *   Inputs: None
 *   Outputs: None
 *   Function return: CAN REARM request
 *   Pre-condition: None
*/
TE_OVSP_SW_Request CAN_Get_REARM_Rqst (void)
{
   /* >RELAX<SYNCHRONe_C_Code_16.12> Waiting for SYNCHONe analyze, it seems to be a false violation. */
   /* The returned data is of the function return type. */
   return (V_CAN_REARM_Rqst);
}


/* CAN_Get_OVS_Status : To provide the OVS Status by collecting the required data
 *   Inputs: None
 *   Outputs: None
 *   Function return: OVS Status
 *   Pre-condition: None
*/
uint8_t CAN_Get_OVS_Status (void)
{
   TU_CAN_OVS_Status v_OVS_Status;
   TE_Modes_SW_Mode v_SW_Mode;

   /* >RELAX<SYNCHRONe_C_Code_10.7> There is no loss of precision. The returned enum type fits in a bit. */
   v_OVS_Status.U_Fields.S_CMD1_Status = (uint8_t) OVSP_Get_CAM_Cmd1 ();

   /* >RELAX<SYNCHRONe_C_Code_10.7> There is no loss of precision. The returned enum type fits in a bit. */
   v_OVS_Status.U_Fields.S_CMD2_Status = (uint8_t) OVSP_Get_CAM_Cmd2 ();

   v_SW_Mode = Modes_Get_SW_Mode ();

   if (E_Modes_TriggeredTest == v_SW_Mode)
   {
      v_OVS_Status.U_Fields.S_Mode = (uint8_t) 1;
   }
   else
   {
      v_OVS_Status.U_Fields.S_Mode = (uint8_t) 0;
   }

   if (E_CAN_Frame_Cmd_Recv_OK == V_CAN_OVSP_Config_Recv_Status)
   {
      v_OVS_Status.U_Fields.S_OVSP_Config_Reception = (uint8_t) 0;
   }
   else
   {
      v_OVS_Status.U_Fields.S_OVSP_Config_Reception = (uint8_t) 1;
   }

   /* >RELAX<SYNCHRONe_C_Code_10.7> There is no loss of precision. The returned enum type fits in a bit. */
   v_OVS_Status.U_Fields.S_OVSP_Config_Integrity = (uint8_t) Config_Get_Integrity_Status ();

   v_OVS_Status.U_Fields.S_OVS_Status_Unused = CAN_UNUSED_BYTE_DATA;

   return (v_OVS_Status.U_Value);
}


/* CAN_Get_NG_Status : To provide the NG Status by collecting the required data
 *   Inputs: None
 *   Outputs: None
 *   Function return: NG Status
 *   Pre-condition: None
*/
uint8_t CAN_Get_NG_Status (void)
{
   TU_CAN_NG_Status v_NG_Status;

   /* >RELAX<SYNCHRONe_C_Code_10.7> There is no loss of precision. The returned boolean values fit in a bit. */
   v_NG_Status.U_Fields.S_NGOS1_OutOfTime = (uint8_t) OVSP_Get_NGOS1_OutOfTime ();

   /* >RELAX<SYNCHRONe_C_Code_10.7> There is no loss of precision. The returned boolean values fit in a bit. */
   v_NG_Status.U_Fields.S_NGOS2_OutOfTime = (uint8_t) OVSP_Get_NGOS2_OutOfTime ();

   /* >RELAX<SYNCHRONe_C_Code_10.7> There is no loss of precision. The returned boolean values fit in a bit. */
   v_NG_Status.U_Fields.S_NGOS1_Updated = (uint8_t) OVSP_Get_NGOS1_Updated ();

   /* >RELAX<SYNCHRONe_C_Code_10.7> There is no loss of precision. The returned boolean values fit in a bit. */
   v_NG_Status.U_Fields.S_NGOS2_Updated = (uint8_t) OVSP_Get_NGOS2_Updated ();

   /* >RELAX<SYNCHRONe_C_Code_10.7> There is no loss of precision. The returned boolean values fit in a bit. */
   v_NG_Status.U_Fields.S_NGOS1_OutOfRangeHigh = (uint8_t) OVSP_Get_NGOS1_OutOfHigh ();

   /* >RELAX<SYNCHRONe_C_Code_10.7> There is no loss of precision. The returned boolean values fit in a bit. */
   v_NG_Status.U_Fields.S_NGOS2_OutOfRangeHigh = (uint8_t) OVSP_Get_NGOS2_OutOfHigh ();

   v_NG_Status.U_Fields.S_NG_Status_Unused = CAN_UNUSED_BYTE_DATA;

   return (v_NG_Status.U_Value);
}


/* CAN_Get_NTL_Status : To provide the NTL Status by collecting the required data
 *   Inputs: None
 *   Outputs: None
 *   Function return: NTL Status
 *   Pre-condition: None
*/
uint8_t CAN_Get_NTL_Status (void)
{
   TU_CAN_NTL_Status v_NTL_Status;

   /* >RELAX<SYNCHRONe_C_Code_10.7> There is no loss of precision. The returned boolean values fit in a bit. */
   v_NTL_Status.U_Fields.S_NTLOS1_OutOfTime = (uint8_t) OVSP_Get_NTLOS1_OutOfTime ();

   /* >RELAX<SYNCHRONe_C_Code_10.7> There is no loss of precision. The returned boolean values fit in a bit. */
   v_NTL_Status.U_Fields.S_NTLOS2_OutOfTime = (uint8_t) OVSP_Get_NTLOS2_OutOfTime ();

   /* >RELAX<SYNCHRONe_C_Code_10.7> There is no loss of precision. The returned boolean values fit in a bit. */
   v_NTL_Status.U_Fields.S_NTLOS1_Updated = (uint8_t) OVSP_Get_NTLOS1_Updated ();

   /* >RELAX<SYNCHRONe_C_Code_10.7> There is no loss of precision. The returned boolean values fit in a bit. */
   v_NTL_Status.U_Fields.S_NTLOS2_Updated = (uint8_t) OVSP_Get_NTLOS2_Updated ();

   /* >RELAX<SYNCHRONe_C_Code_10.7> There is no loss of precision. The returned boolean values fit in a bit. */
   v_NTL_Status.U_Fields.S_NTLOS1_OutOfRangeHigh = (uint8_t) OVSP_Get_NTLOS1_OutOfHigh ();

   /* >RELAX<SYNCHRONe_C_Code_10.7> There is no loss of precision. The returned boolean values fit in a bit. */
   v_NTL_Status.U_Fields.S_NTLOS2_OutOfRangeHigh = (uint8_t) OVSP_Get_NTLOS2_OutOfHigh ();

   v_NTL_Status.U_Fields.S_NTL_Status_Unused = CAN_UNUSED_BYTE_DATA;

   return (v_NTL_Status.U_Value);
}


/* CAN_Get_DIN_Status : To provide the Discrete Inputs Status by collecting the required data
 *   Inputs: None
 *   Outputs: None
 *   Function return: Discrete Inputs Status
 *   Pre-condition: None
*/
uint8_t CAN_Get_DIN_Status (void)
{
   TU_CAN_DIN_Status v_DIN_Status;

   /* >RELAX<SYNCHRONe_C_Code_10.7> There is no loss of precision. The returned enum type fits in a bit. */
   v_DIN_Status.U_Fields.S_DININHIB  = (uint8_t) IO_Get_DININHIB_Cmd ();

   /* >RELAX<SYNCHRONe_C_Code_10.7> There is no loss of precision. The returned enum type fits in a bit. */
   v_DIN_Status.U_Fields.S_OSREARM   = (uint8_t) IO_Get_OSREARM_Cmd ();

   /* >RELAX<SYNCHRONe_C_Code_10.7> There is no loss of precision. The returned enum type fits in a bit. */
   v_DIN_Status.U_Fields.S_NTLOSTEST = (uint8_t) IO_Get_NTLOSTEST_Cmd ();

   v_DIN_Status.U_Fields.S_DIN_Status_Unused = CAN_UNUSED_BYTE_DATA;

   return (v_DIN_Status.U_Value);
}


/* CAN_Get_DOUT_Status : To provide the Discrete Outputs Status by collecting the required data
 *   Inputs: None
 *   Outputs: None
 *   Function return: Discrete Outputs Status
 *   Pre-condition: None
*/
uint8_t CAN_Get_DOUT_Status (void)
{
   TU_CAN_DOUT_Status v_DOUT_Status;

   /* >RELAX<SYNCHRONe_C_Code_10.7> There is no loss of precision. The returned enum type fits in a bit. */
   v_DOUT_Status.U_Fields.S_DOUTINHIB_FB = (uint8_t) IO_Get_DOUTINHIB_FB ();

   /* >RELAX<SYNCHRONe_C_Code_10.7> There is no loss of precision. The returned enum type fits in a bit. */
   v_DOUT_Status.U_Fields.S_CAMLOW2_FB   = (uint8_t) IO_Get_CAMLOW2_FB ();

   /* >RELAX<SYNCHRONe_C_Code_10.7> There is no loss of precision. The returned enum type fits in a bit. */
   v_DOUT_Status.U_Fields.S_OSARM_FB     = (uint8_t) IO_Get_OSARM_FB ();

   v_DOUT_Status.U_Fields.S_DOUT_Status_Unused = CAN_UNUSED_BYTE_DATA;

   return (v_DOUT_Status.U_Value);
}


/* CAN_Get_NG_NTL_Statuses_Sent : To provide the sending state of NG and NTL statuses
 *   Inputs: None
 *   Outputs: None
 *   Function return: NG and NTL statuses sending state
 *   Pre-condition: None
*/
boolean_t CAN_Get_NG_NTL_Statuses_Sent (void)
{
   return (V_CAN_NG_NTL_Statuses_Sent);
}


/* CAN_Get_NTL_OneSensor_CSSAuth : To provide the NTL one sensor CSS authorization
 *   Inputs: None
 *   Outputs: None
 *   Function return: NTL one sensor CSS authorization
 *   Pre-condition: None
*/
TE_OVSP_SW_OneSensor_Auth CAN_Get_NTL_OneSensor_CSSAuth (void)
{
   /* >RELAX<SYNCHRONe_C_Code_16.12> Waiting for SYNCHONe analyze, it seems to be a false violation. */
   /* The returned data is of the function return type. */
   return (V_CAN_NTL_OneSensor_CSSAuth);
}


/* CAN_Get_NG_OneSensor_CSSAuth : To provide the NG one sensor CSS authorization
 *   Inputs: None
 *   Outputs: None
 *   Function return: NG one sensor CSS authorization
 *   Pre-condition: None
*/
TE_OVSP_SW_OneSensor_Auth CAN_Get_NG_OneSensor_CSSAuth (void)
{
   /* >RELAX<SYNCHRONe_C_Code_16.12> Waiting for SYNCHONe analyze, it seems to be a false violation. */
   /* The returned data is of the function return type. */
   return (V_CAN_NG_OneSensor_CSSAuth);
}


/* CAN_Reset_TestDiscrete_Cmd : To reset the Test Discrete command
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void CAN_Reset_TestDiscrete_Cmd (void)
{
   V_CAN_TestDiscrete_Cmd = E_OVSP_SW_Cmd_Off;
}
