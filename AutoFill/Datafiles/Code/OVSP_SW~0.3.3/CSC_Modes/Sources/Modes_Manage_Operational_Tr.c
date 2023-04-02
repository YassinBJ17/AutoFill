/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the function to manage the SW Mode
 *               transition in Operational mode
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "Modes_Public.h"
#include "Modes_Private.h"


/* ---------- include required interface: ----------------------------------- */
#include "CAN_Public.h"
#include "CBIT_Public.h"
#include "Config_Public.h"
#include "DrvFTM_Public.h"
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
/* Modes_Manage_Operational_Tr : To manage the SW Mode transition in Operational mode
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void Modes_Manage_Operational_Tr (void)
{
   TE_CBIT_Test_Result v_CBIT_Result;
   TE_Config_Integrity_Status v_OVSP_Config_Validity;
   TE_CAN_TriggTest_Cmd v_TriggTest_Cmd;
   float32_t v_TriggTest_Speed;
   TE_OVSP_SW_Speed_Level v_Engine_SpeedLevel;

   v_CBIT_Result = CBIT_Get_Test_Result ();

   if (E_CBIT_Fatal_Error == v_CBIT_Result)
   {
      V_Modes_SW_Mode = E_Modes_Fail;
   }
   else
   {
      v_OVSP_Config_Validity = Config_Get_Integrity_Status ();

      if (E_Config_Integrity_KO == v_OVSP_Config_Validity)
      {
         V_Modes_SW_Mode = E_Modes_Degraded;

         DrvFTM_Stop (DRVFTM_TIMER_0);
         DrvFTM_Stop (DRVFTM_TIMER_2);
         DrvFTM_Stop (DRVFTM_TIMER_3);
      }
      else
      {
         v_TriggTest_Cmd = CAN_Get_TriggTest_Cmd ();
         v_Engine_SpeedLevel = OVSP_Get_Engine_SpeedLevel ();

         if ((E_CAN_TriggTest_On == v_TriggTest_Cmd) && (E_OVSP_SW_Low_Speed == v_Engine_SpeedLevel))
         {
            V_Modes_SW_Mode = E_Modes_TriggeredTest;

            v_TriggTest_Speed = CAN_Get_Test_Speed ();

            DrvFTM_Stop_Freqs_Acq ();
            DrvFTM_Prepare_TSpeed_Signal (v_TriggTest_Speed);
            DrvFTM_Manage_TSpeed_Signal ();
         }
         else
         { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
            /* Nothing to do */
         }
      }
   }
}
