/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the SET_PARAM Command frames decoding function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "CAN_Private.h"


/* ---------- include required interface: ----------------------------------- */
#include "DrvCAN_Public.h"

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
/* CAN_Decode_SET_PARAM_Frame : To decode the SET_PARAM Command specified frame
 *   Inputs:
 *     - p_pt_RxFrame: Buffer of the received frame
 *     - p_Index: Frame index
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void CAN_Decode_SET_PARAM_Frame (const TS_DrvCAN_RxFrame * const p_pt_RxFrame, const uint32_t p_Index)
{
   TE_CAN_Frame_Cmd_State v_ExpectedStatus;

   if (0UL == p_Index)
   {
      v_ExpectedStatus = E_CAN_Frame_Cmd_Start;
   }
   else
   {
      v_ExpectedStatus = E_CAN_Frame_Cmd_Recv_OK;
   }

   if (V_CAN_SET_PARAM_Frames_States [p_Index] == v_ExpectedStatus)
   {
      V_CAN_SET_PARAM_Frames.U_Array_32BitUint
         [DRVCAN_FRAME_32BIT_NB * (p_Index)] = p_pt_RxFrame->S_RxData [OVSP_SW_LONG_0];

      V_CAN_SET_PARAM_Frames.U_Array_32BitUint
         [(DRVCAN_FRAME_32BIT_NB * (p_Index)) + 1UL] = p_pt_RxFrame->S_RxData [OVSP_SW_LONG_1];

      V_CAN_SET_PARAM_Frames_States [p_Index + 1UL] = E_CAN_Frame_Cmd_Recv_OK;

      if (CAN_SET_PARAM_FRAMES_NB == p_Index)
      {
         V_CAN_OVSP_Config_Recv_Status = E_CAN_Frame_Cmd_Recv_OK;
      }
      else
      { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
         /* Nothing to do */
      }
   }
   else
   {
      V_CAN_SET_PARAM_Frames_States [p_Index] = E_CAN_Frame_Cmd_Recv_KO;
      V_CAN_OVSP_Config_Recv_Status = E_CAN_Frame_Cmd_Recv_KO;
   }
}
