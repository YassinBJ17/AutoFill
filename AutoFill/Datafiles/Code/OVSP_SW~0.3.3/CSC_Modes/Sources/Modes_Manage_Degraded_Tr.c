/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the function to manage the SW Mode
 *               transition in Degraded mode
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "Modes_Public.h"
#include "Modes_Private.h"


/* ---------- include required interface: ----------------------------------- */
#include "CBIT_Public.h"
#include "Config_Public.h"
#include "DrvFTM_Public.h"


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
/* Modes_Manage_Degraded_Tr : To manage the SW Mode transition in Degraded mode
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void Modes_Manage_Degraded_Tr (void)
{
   TE_CBIT_Test_Result v_CBIT_Result;
   TE_Config_Integrity_Status v_OVSP_Config_Validity;

   v_CBIT_Result = CBIT_Get_Test_Result ();

   if (E_CBIT_Fatal_Error == v_CBIT_Result)
   {
      V_Modes_SW_Mode = E_Modes_Fail;
   }
   else
   {
      v_OVSP_Config_Validity = Config_Get_Integrity_Status ();

      if (E_Config_Integrity_OK == v_OVSP_Config_Validity)
      {
         V_Modes_SW_Mode = E_Modes_Operational;

         DrvFTM_Start (DRVFTM_TIMER_0);
         DrvFTM_Start (DRVFTM_TIMER_2);
         DrvFTM_Start (DRVFTM_TIMER_3);
      }
      else
      { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
         /* Nothing to do */
      }
   }
}
