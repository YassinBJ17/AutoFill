/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the received CAN Command frames management function
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
/* CAN_Manage_Command_Frames : To manage the received CAN Command frames
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void CAN_Manage_Command_Frames (void)
{
   TS_DrvCAN_RxFrame v_CAN_RxFrame;
   TS_DrvCAN_TxFrame v_CAN_TxFrame;

   DrvCAN_Get_RxFrame_FromQueue (&v_CAN_RxFrame, DRVCAN_RXQUEUE0_ID);

   switch (v_CAN_RxFrame.S_RxId)
   {
      case CAN_GET_SW_INFO_ID:
      {
         CAN_Decode_GET_SW_INFO_Frame (&v_CAN_RxFrame);

         CAN_Encode_SW_INFO_Frame (&v_CAN_TxFrame);

         DrvCAN_Write (DRVCAN_TX_SW_INFO_MB_ID, &v_CAN_TxFrame);
      }
      break;

      case CAN_TRIGGERED_TEST_ID:
      {
         CAN_Decode_TRIGGERED_TEST_Frame (&v_CAN_RxFrame);
      }
      break;

      case CAN_TEST_DISCRETE_ID:
      {
         CAN_Decode_TEST_DISCRETE_Frame (&v_CAN_RxFrame);
      }
      break;

      case CAN_CAM_CMD_ID:
      {
         if (CAN_CAM_CMD_TIMEOUT > V_CAN_CAM_Timing)
         { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
            /* Nothing to do */
         }
         else
         {
            CAN_Decode_CAM_CMD_Frame (&v_CAN_RxFrame);
         }
      }
      break;

      case CAN_OSARM_CMD_ID:
      {
         CAN_Decode_OSARM_CMD_Frame (&v_CAN_RxFrame);
      }
      break;

      case CAN_REARM_CMD_ID:
      {
         CAN_Decode_REARM_CMD_Frame (&v_CAN_RxFrame);
      }
      break;

      case CAN_GET_DATA_FC0_ID:
      case CAN_GET_DATA_FC1_ID:
      case CAN_GET_DATA_FC2_ID:
      case CAN_GET_DATA_FC3_ID:
      {
         V_CAN_GET_DATA_Received = TRUE;

         V_CAN_GET_DATA_FC = v_CAN_RxFrame.S_RxId & CAN_GET_DATA_FC_MASK;

         CAN_Encode_DATA_Frame1 ();
         CAN_Encode_DATA_Frame2 ();
         CAN_Encode_DATA_Frame3 ();
         CAN_Encode_DATA_Frame4 ();
         CAN_Encode_DATA_Frame5 ();
         CAN_Encode_DATA_Frame6 ();

         V_CAN_DATA_FrameToSend = CAN_DATA_FRAME01_INDEX;
      }
      break;

      case CAN_ONE_SENSOR_CMD_ID:
      {
         CAN_Decode_ONE_SENSOR_CMD_Frame (&v_CAN_RxFrame);
      }
      break;

      default:
      { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
         /* Nothing to do */
      }
      break;

   }
}
