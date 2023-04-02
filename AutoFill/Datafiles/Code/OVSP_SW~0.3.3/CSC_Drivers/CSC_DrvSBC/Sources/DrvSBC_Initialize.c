/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 *    DESCRIPTION : This file contains the initialization of the DrvSBC CSC
 * -------------------------------------------------------------------------- */

/* ---------- include predefined types: ------------------------------------- */
#include "DrvSBC_Public.h"
#include "DrvSBC_Private.h"

/* ---------- include provided interface: ----------------------------------- */
/* None */


/* ---------- internal define constants: ------------------------------------ */
/* None */

/* ---------- internal types: ----------------------------------------------- */
/* None */

/* ---------- internal operations: ------------------------------------------ */
/* None */

/* ---------- internal constants: ------------------------------------------- */
/* None */

/* ---------- internal data: ------------------------------------------------ */
/* None */

/* ---------- provided operation bodies: ------------------------------------ */
/* DrvSBC_Initialize : To initialize the DrvSBC CSC
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/

void DrvSBC_Initialize (void)
{
   TE_DrvSBC_CAN_Status v_CAN_Status;
   TE_DrvSBC_States v_SBC_State;
   TE_DrvSBC_Init_Status v_SBC_init_status;

   v_CAN_Status = E_DrvSBC_CAN_KO;
   v_SBC_init_status = E_DrvSBC_Init_KO;

   v_SBC_State = DrvSBC_Get_Current_Mode ();

   if (v_SBC_State == E_DrvSBC_Mode_Init)
   {
      DrvSBC_Cmd_Init_WDOG ();
      DrvSBC_Cmd_Init_Reg ();
      DrvSBC_Cmd_Init_LIN_IO ();
      DrvSBC_Cmd_Init_Misc ();
   }

   while (v_SBC_State != E_DrvSBC_Mode_Normal)
   {
      DrvSBC_Cmd_WDOG_Refresh ();
      v_SBC_State = DrvSBC_Get_Current_Mode ();
   }

   if (v_SBC_State == E_DrvSBC_Mode_Normal)
   {
      DrvSBC_Cmd_Timer_A ();
      DrvSBC_Cmd_Timer_B ();
      DrvSBC_Cmd_Timer_C ();
      DrvSBC_Cmd_Reg ();
      DrvSBC_Cmd_CAN_Reg ();

      v_CAN_Status = DrvSBC_CAN_RT_Status ();

      while (v_CAN_Status != E_DrvSBC_CAN_OK)
      {
         DrvSBC_Cmd_CAN_Reg ();
      }

      if (v_CAN_Status == E_DrvSBC_CAN_OK)
      {
         DrvSBC_Cmd_IO ();
         DrvSBC_Cmd_Int ();
         DrvSBC_Cmd_LIN1 ();
         DrvSBC_Cmd_LIN2 ();
         DrvSBC_Cmd_Mux_Out ();

         v_SBC_init_status = E_DrvSBC_Init_OK;
      }
      else
      {
         v_SBC_init_status = E_DrvSBC_Init_KO;
      }
   }
   else
   {
      v_SBC_init_status = E_DrvSBC_Init_KO;
   }

   if (v_SBC_init_status == E_DrvSBC_Init_KO)
   { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
      /* Error on SBC, go to Fail-Safe Mode */
   }
}
