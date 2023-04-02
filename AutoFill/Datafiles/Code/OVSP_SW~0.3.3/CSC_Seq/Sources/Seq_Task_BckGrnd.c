/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the function to sequence the treatments
 *               in the background task
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "Seq_Public.h"
#include "Seq_Private.h"


/* ---------- include required interface: ----------------------------------- */
#include "CBIT_Public.h"
#include "Config_Public.h"
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
/* Seq_Task_BckGrnd : To sequence the treatments in the background task
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void Seq_Task_BckGrnd (void)
{
   while (TRUE)
   {
      if (V_Seq_NewConfig_To_Manage)
      {
         Config_Manage_NewConfig_BckGrnd ();

         V_Seq_NewConfig_To_Manage = FALSE;
      }
      else
      {
         Config_Treatments ();

         CBIT_Treatments_BckGrnd ();

         Logbook_Write_In_FlexNVM ();
      }
   }
}
