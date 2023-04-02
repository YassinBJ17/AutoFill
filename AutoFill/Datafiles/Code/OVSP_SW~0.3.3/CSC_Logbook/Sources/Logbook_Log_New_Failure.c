/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the function to log a new Failure
 *               in the Logbook
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "Logbook_Public.h"
#include "Logbook_Private.h"


/* ---------- include required interface: ----------------------------------- */
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
/* Logbook_Log_New_Failure : To log a new Failure in the Logbook
 *   Inputs:
 *     - p_Failure_Type: Type of the Failure to log
 *     - p_Failure_Code: Code of the Failure to log
 *     - p_Failure_Detail: Detail of the Failure to log
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void Logbook_Log_New_Failure (const uint32_t p_Failure_Type,
                              const uint32_t p_Failure_Code,
                              const uint32_t p_Failure_Detail)
{
   uint32_t v_Failure_Index;
   boolean_t v_Failure_To_Record;

   v_Failure_To_Record = FALSE;

   switch (p_Failure_Type)
   {
      case LOGBOOK_PBIT_FAILURE_ID:
      {
         if ((p_Failure_Code != V_Logbook_Previous_PBIT_Failure.S_Failure_Code) ||
             (p_Failure_Detail != V_Logbook_Previous_PBIT_Failure.S_Failure_Detail))
         {
            v_Failure_To_Record = TRUE;

            V_Logbook_Previous_PBIT_Failure.S_Failure_Code = p_Failure_Code;
            V_Logbook_Previous_PBIT_Failure.S_Failure_Detail = p_Failure_Detail;
         }
         else
         { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
            /* Nothing to do */
         }
      }
      break;

      case LOGBOOK_CBIT_FAILURE_ID:
      {
         if ((p_Failure_Code != V_Logbook_Previous_CBIT_Failure.S_Failure_Code) ||
             (p_Failure_Detail != V_Logbook_Previous_CBIT_Failure.S_Failure_Detail))
         {
            v_Failure_To_Record = TRUE;

            V_Logbook_Previous_CBIT_Failure.S_Failure_Code = p_Failure_Code;
            V_Logbook_Previous_CBIT_Failure.S_Failure_Detail = p_Failure_Detail;
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

   if (v_Failure_To_Record)
   {
      v_Failure_Index = V_Logbook.U_Fields.S_Next_Failure_Index;

      V_Logbook.U_Fields.S_Failures [v_Failure_Index].S_Failure_Code = p_Failure_Code;
      V_Logbook.U_Fields.S_Failures [v_Failure_Index].S_Failure_Detail = p_Failure_Detail;

      V_Logbook.U_Fields.S_Nb_Failures_Logged++;

      V_Logbook.U_Fields.S_Next_Failure_Index = (v_Failure_Index + 1UL) % LOGBOOK_FAILURES_NB;

      V_Logbook_Failure_to_Write = TRUE;
   }
   else
   { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
      /* Nothing to do */
   }
}
