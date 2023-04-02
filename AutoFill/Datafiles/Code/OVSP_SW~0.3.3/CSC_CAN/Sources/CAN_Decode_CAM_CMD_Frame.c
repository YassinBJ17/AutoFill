/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the CAM_CMD Command frame decoding function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "CAN_Private.h"


/* ---------- include required interface: ----------------------------------- */
#include "DrvCAN_Public.h"

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
/* CAN_Decode_CAM_CMD_Frame : To decode the CAM_CMD Command frame
 *   Inputs:
 *     - p_pt_RxFrame: Buffer of the received frame
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void CAN_Decode_CAM_CMD_Frame (const TS_DrvCAN_RxFrame * const p_pt_RxFrame)
{
   uint32_t v_CAM_Cmd_AS_Key;

   v_CAM_Cmd_AS_Key = p_pt_RxFrame->S_RxData [OVSP_SW_LONG_1];

   switch (p_pt_RxFrame->S_RxData [OVSP_SW_LONG_0])
   {
      case CAN_CAM_OS_KEY_CMD1_OFF:
      {
         if (CAN_CAM_AS_KEY_CMD1_OFF == v_CAM_Cmd_AS_Key)
         {
            V_CAN_CAM_Cmd_1 = E_OVSP_SW_Cmd_Off;
            V_CAN_CAM_Timing = 0UL;
         }
         else
         { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
            /* Nothing to do */
         }
      }
      break;

      case CAN_CAM_OS_KEY_CMD1_ON:
      {
         if (CAN_CAM_AS_KEY_CMD1_ON == v_CAM_Cmd_AS_Key)
         {
            V_CAN_CAM_Cmd_1 = E_OVSP_SW_Cmd_On;
            V_CAN_CAM_Timing = 0UL;
         }
         else
         { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
            /* Nothing to do */
         }
      }
      break;

      case CAN_CAM_OS_KEY_CMD2_OFF:
      {
         if (CAN_CAM_AS_KEY_CMD2_OFF == v_CAM_Cmd_AS_Key)
         {
            V_CAN_CAM_Cmd_2 = E_OVSP_SW_Cmd_Off;
            V_CAN_CAM_Timing = 0UL;
         }
         else
         { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
            /* Nothing to do */
         }
      }
      break;

      case CAN_CAM_OS_KEY_CMD2_ON:
      {
         if (CAN_CAM_AS_KEY_CMD2_ON == v_CAM_Cmd_AS_Key)
         {
            V_CAN_CAM_Cmd_2 = E_OVSP_SW_Cmd_On;
            V_CAN_CAM_Timing = 0UL;
         }
         else
         { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
            /* Nothing to do */
         }
      }
      break;

      default:
      { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
         /* Nothing to do */
      }
      break;

   }
}
