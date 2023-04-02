/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the TRIGGERED_TEST Command frame decoding function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "CAN_Private.h"


/* ---------- include required interface: ----------------------------------- */
#include "DrvCAN_Public.h"
#include "Modes_Public.h"
#include "OVSP_Public.h"

#include "OVSP_SW_Public.h"


/* ---------- internal define constants: ------------------------------------ */
#define CAN_TEST_SPEED_MIN     0.0f
#define CAN_TEST_SPEED_MAX   200.0f


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
/* CAN_Decode_TRIGGERED_TEST_Frame : To decode the TRIGGERED_TEST Command frame
 *   Inputs:
 *     - p_pt_RxFrame: Buffer of the received frame
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void CAN_Decode_TRIGGERED_TEST_Frame (const TS_DrvCAN_RxFrame * const p_pt_RxFrame)
{
   TE_Modes_SW_Mode       v_SW_Mode;
   TE_OVSP_SW_Speed_Level v_Engine_SpeedLevel;

   v_SW_Mode = Modes_Get_SW_Mode ();
   v_Engine_SpeedLevel = OVSP_Get_Engine_SpeedLevel ();

   switch (p_pt_RxFrame->S_RxData [OVSP_SW_LONG_0])
   {
      case CAN_TRIG_TEST_ON:
      {
         if (((E_Modes_Operational == v_SW_Mode) && (E_OVSP_SW_Low_Speed == v_Engine_SpeedLevel)) ||
             (E_Modes_TriggeredTest == v_SW_Mode))
         {
            V_CAN_TriggTest_cmd = E_CAN_TriggTest_On;
            V_CAN_Test_Speed.U_Value_32BitUint = p_pt_RxFrame->S_RxData [OVSP_SW_LONG_1];

            if (CAN_TEST_SPEED_MAX < V_CAN_Test_Speed.U_Value_32BitFloat)
            {
               V_CAN_Test_Speed.U_Value_32BitFloat = CAN_TEST_SPEED_MAX;
            }
            else
            {
               if (CAN_TEST_SPEED_MIN > V_CAN_Test_Speed.U_Value_32BitFloat)
               {
                  V_CAN_Test_Speed.U_Value_32BitFloat = CAN_TEST_SPEED_MIN;
               }
               else
               { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
                  /* Nothing to do */
               }
            }
         }
      }
      break;

      case CAN_TRIG_TEST_OFF:
      {
         V_CAN_TriggTest_cmd = E_CAN_TriggTest_Off;
      }
      break;

      default:
      {
         V_CAN_TriggTest_cmd = E_CAN_TriggTest_Invalid;
      }
      break;

   }
}
