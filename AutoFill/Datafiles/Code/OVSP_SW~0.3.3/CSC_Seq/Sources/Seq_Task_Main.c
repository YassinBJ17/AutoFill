/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the function to sequence the treatments
 *               in the main task
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "Seq_Public.h"
#include "Seq_Private.h"


/* ---------- include required interface: ----------------------------------- */
#include "CAN_Public.h"
#include "CBIT_Public.h"
#include "Config_Public.h"
#include "DrvLPIT_Public.h"
#include "IO_Public.h"
#include "Modes_Public.h"
#include "OVSP_Public.h"

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
/* Seq_Task_Main : To sequence the treatments in the main task
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void Seq_Task_Main (void)
{
   TE_Modes_SW_Mode v_SW_Mode;

   if (V_Seq_NewConfig_To_Use)
   {
      Config_Use_NewConfig ();

      V_Seq_NewConfig_To_Use = FALSE;
   }
   else
   { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
      /* Nothing to do */
   }

   v_SW_Mode = Modes_Get_SW_Mode ();

   switch (v_SW_Mode)
   {
      case E_Modes_Operational:
      case E_Modes_TriggeredTest:
      {
         IO_Acquire_Discretes ();
         IO_Acquire_Analogs ();
      }
      break;

      default:
      { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
         /* Nothing to do */
      }
      break;

   }

   CAN_Treatments ();

   OVSP_Treatments ();

   switch (v_SW_Mode)
   {
      case E_Modes_Operational:
      case E_Modes_TriggeredTest:
      {
         IO_Generate_Discretes ();
      }
      break;

      default:
      { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
         /* Nothing to do */
      }
      break;

   }

   CBIT_Treatments_RTC ();

   Modes_Treatments ();

   DrvLPIT_Reset ();
}
