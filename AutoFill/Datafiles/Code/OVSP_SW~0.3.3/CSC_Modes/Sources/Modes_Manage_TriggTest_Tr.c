/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the function to manage the SW Mode
 *               transition in TriggeredTest mode
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "Modes_Public.h"
#include "Modes_Private.h"


/* ---------- include required interface: ----------------------------------- */
#include "Boot_Public.h"
#include "CAN_Public.h"
#include "CBIT_Public.h"
#include "DrvFTM_Public.h"
#include "DrvGPIO_Public.h"

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
/* Modes_Manage_TriggTest_Tr : To manage the SW Mode transition in TriggeredTest mode
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void Modes_Manage_TriggTest_Tr (void)
{
   TE_CBIT_Test_Result v_CBIT_Result;
   TE_CAN_TriggTest_Cmd v_TriggTest_Cmd;
   float32_t v_TriggTest_Speed;
   uint8_t v_OVSP_Side_Id;

   v_CBIT_Result = CBIT_Get_Test_Result ();

   if (E_CBIT_Fatal_Error == v_CBIT_Result)
   {
      V_Modes_SW_Mode = E_Modes_Fail;
   }
   else
   {
      v_TriggTest_Cmd = CAN_Get_TriggTest_Cmd ();

      if (E_CAN_TriggTest_Off == v_TriggTest_Cmd)
      {
         V_Modes_SW_Mode = E_Modes_Operational;

         v_OVSP_Side_Id = Boot_Get_Side_Id ();

         if (BOOT_SIDE_ID_HS == v_OVSP_Side_Id)
         {
            DrvFTM_Stop_CAM_Generation ();
            DrvFTM_Stop_TSpeed_HS ();
         }
         else
         {
            DrvGPIO_Write (DRVGPIO_OUT_CAM_CMD1, E_OVSP_SW_Cmd_Off);
            DrvFTM_Stop_TSpeed_LS ();
         }

         DrvFTM_Initialize_TSpeed_Data ();
         DrvFTM_Start_Freqs_Acq ();

         DrvGPIO_Write (DRVGPIO_OUT_CAM_CMD2,  E_OVSP_SW_Cmd_Off);
         DrvGPIO_Write (DRVGPIO_OUT_DOUTINHIB, E_OVSP_SW_Cmd_Off);
         DrvGPIO_Write (DRVGPIO_OUT_OSARM_CMD, E_OVSP_SW_Cmd_Off);

         CAN_Reset_TestDiscrete_Cmd ();
      }
      else
      {
         v_TriggTest_Speed = CAN_Get_Test_Speed ();

         DrvFTM_Prepare_TSpeed_Signal (v_TriggTest_Speed);
         DrvFTM_Manage_TSpeed_Signal ();
      }
   }
}
