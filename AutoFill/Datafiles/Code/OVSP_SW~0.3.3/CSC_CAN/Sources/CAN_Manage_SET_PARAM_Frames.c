/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the CAN frames reception management function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "CAN_Private.h"


/* ---------- include required interface: ----------------------------------- */
#include "Config_Public.h"
#include "DrvCAN_Public.h"
#include "Modes_Public.h"
#include "OVSP_Public.h"

#include "OVSP_SW_Public.h"


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
/* CAN_Manage_SET_PARAM_Frames : To manage the CAN received SET_PARAM frames
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
/* >RELAX<SYNCHRONe_C_Code_22.4> It is clearer to manage the SET_PARAM frames reception in a single function. */
/* This is mainly caused by "switch...case" that is not so complex in terms of independent ways than "if...else". */
void CAN_Manage_SET_PARAM_Frames (void)
{
   TS_DrvCAN_RxFrame        v_CAN_RxFrame;
   TE_OVSP_SW_Speed_Level   v_Engine_SpeedLevel;
   TE_Modes_SW_Mode         v_SW_Mode;
   TU_OVSP_SW_Uint32_Uint16 v_Frame_Data;

   DrvCAN_Get_RxFrame_FromQueue (&v_CAN_RxFrame, DRVCAN_RXQUEUE1_ID);

   switch (v_CAN_RxFrame.S_RxId)
   {
      case CAN_SET_PARAM_FRAME00_ID:
      {
         v_Engine_SpeedLevel = OVSP_Get_Engine_SpeedLevel ();

         v_SW_Mode = Modes_Get_SW_Mode ();

         if ((E_OVSP_SW_Low_Speed == v_Engine_SpeedLevel) || (E_Modes_Degraded == v_SW_Mode))
         {
            CAN_Init_SET_PARAM_Frames_States ();

            if (CAN_SET_PARAM_KEY == v_CAN_RxFrame.S_RxData [OVSP_SW_LONG_0])
            {
               V_CAN_SET_PARAM_Frames_States [0] = E_CAN_Frame_Cmd_Start;

               v_Frame_Data.U_Value_32BitUint = v_CAN_RxFrame.S_RxData [OVSP_SW_LONG_1];
               V_CAN_OVSP_Config_16BitCRC_Recv = v_Frame_Data.U_Array_16BitUint [OVSP_SW_WORD_1];
            }
            else
            {
               V_CAN_SET_PARAM_Frames_States [0] = E_CAN_Frame_Cmd_Recv_KO;
            }
         }
         else
         { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
            /* Nothing to do */
         }
      }
      break;

      case CAN_SET_PARAM_FRAME01_ID:
      {
         CAN_Decode_SET_PARAM_Frame (&v_CAN_RxFrame, CAN_SET_PARAM_FRAME01_INDEX);
      }
      break;

      case CAN_SET_PARAM_FRAME02_ID:
      {
         CAN_Decode_SET_PARAM_Frame (&v_CAN_RxFrame, CAN_SET_PARAM_FRAME02_INDEX);
      }
      break;

      case CAN_SET_PARAM_FRAME03_ID:
      {
         CAN_Decode_SET_PARAM_Frame (&v_CAN_RxFrame, CAN_SET_PARAM_FRAME03_INDEX);
      }
      break;

      case CAN_SET_PARAM_FRAME04_ID:
      {
         CAN_Decode_SET_PARAM_Frame (&v_CAN_RxFrame, CAN_SET_PARAM_FRAME04_INDEX);
      }
      break;

      case CAN_SET_PARAM_FRAME05_ID:
      {
         CAN_Decode_SET_PARAM_Frame (&v_CAN_RxFrame, CAN_SET_PARAM_FRAME05_INDEX);
      }
      break;

      case CAN_SET_PARAM_FRAME06_ID:
      {
         CAN_Decode_SET_PARAM_Frame (&v_CAN_RxFrame, CAN_SET_PARAM_FRAME06_INDEX);
      }
      break;

      case CAN_SET_PARAM_FRAME07_ID:
      {
         CAN_Decode_SET_PARAM_Frame (&v_CAN_RxFrame, CAN_SET_PARAM_FRAME07_INDEX);
      }
      break;

      case CAN_SET_PARAM_FRAME08_ID:
      {
         CAN_Decode_SET_PARAM_Frame (&v_CAN_RxFrame, CAN_SET_PARAM_FRAME08_INDEX);
      }
      break;

      case CAN_SET_PARAM_FRAME09_ID:
      {
         CAN_Decode_SET_PARAM_Frame (&v_CAN_RxFrame, CAN_SET_PARAM_FRAME09_INDEX);
      }
      break;

      case CAN_SET_PARAM_FRAME10_ID:
      {
         CAN_Decode_SET_PARAM_Frame (&v_CAN_RxFrame, CAN_SET_PARAM_FRAME10_INDEX);
      }
      break;

      case CAN_SET_PARAM_FRAME11_ID:
      {
         CAN_Decode_SET_PARAM_Frame (&v_CAN_RxFrame, CAN_SET_PARAM_FRAME11_INDEX);

         if (E_CAN_Frame_Cmd_Recv_OK == V_CAN_SET_PARAM_Frames_States [CAN_SET_PARAM_FRAME11_INDEX + 1UL])
         {
            Config_Manage_NewConfig_HTR (&V_CAN_SET_PARAM_Frames, V_CAN_OVSP_Config_16BitCRC_Recv);
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
