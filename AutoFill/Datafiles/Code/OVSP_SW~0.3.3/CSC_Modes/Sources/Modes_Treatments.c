/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the Modes Treatments function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "Modes_Public.h"
#include "Modes_Private.h"


/* ---------- include required interface: ----------------------------------- */
#include "Logbook_Public.h"

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
/* Modes_Treatments : To perform the Modes management treatments
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void Modes_Treatments (void)
{
   boolean_t v_Log_to_Write;

   switch (V_Modes_SW_Mode)
   {
      case E_Modes_Init:
      {
         Modes_Manage_Init_Tr ();
      }
      break;

      case E_Modes_Operational:
      {
         Modes_Manage_Operational_Tr ();
      }
      break;

      case E_Modes_Degraded:
      {
         Modes_Manage_Degraded_Tr ();
      }
      break;

      case E_Modes_TriggeredTest:
      {
         Modes_Manage_TriggTest_Tr ();
      }
      break;

      default:
      {
         V_Modes_SW_Mode = E_Modes_Fail;
      }
      break;

   }

   if (E_Modes_Fail == V_Modes_SW_Mode)
   {
      v_Log_to_Write = Logbook_Is_Failure_to_Write ();

      if (FALSE == v_Log_to_Write)
      {
         while (TRUE)
         {
            /* Halt the microcontroller */
         }
      }
      else
      { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
         /* Nothing to do */
      }
   }
   else
   { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
      /* Nothing to do */
   }
}
