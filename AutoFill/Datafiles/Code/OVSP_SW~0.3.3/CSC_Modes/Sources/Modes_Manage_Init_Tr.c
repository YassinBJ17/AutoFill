/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the function to manage the SW Mode
 *               transition in Init mode
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "Modes_Public.h"
#include "Modes_Private.h"


/* ---------- include required interface: ----------------------------------- */
#include "Boot_Public.h"
#include "Config_Public.h"
#include "DrvFTM_Public.h"
#include "PBIT_Public.h"

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
/* Modes_Manage_Init_Tr : To manage the SW Mode transition in Init mode
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void Modes_Manage_Init_Tr (void)
{
   uint8_t v_OVSP_Side_Id;
   TE_PBIT_Test_Result v_PBIT_Result;
   TE_Config_Integrity_Status v_OVSP_Config_Validity;

   v_OVSP_Side_Id = Boot_Get_Side_Id ();
   v_PBIT_Result = PBIT_Get_Test_Result ();

   if ((BOOT_SIDE_ID_INVALID == v_OVSP_Side_Id) || (E_PBIT_Failed == v_PBIT_Result))
   {
      V_Modes_SW_Mode = E_Modes_Fail;
   }
   else
   {
      v_OVSP_Config_Validity = Config_Get_Integrity_Status ();

      if (E_Config_Integrity_KO == v_OVSP_Config_Validity)
      {
         V_Modes_SW_Mode = E_Modes_Degraded;
      }
      else
      {
         V_Modes_SW_Mode = E_Modes_Operational;

         DrvFTM_Start (DRVFTM_TIMER_0);
         DrvFTM_Start (DRVFTM_TIMER_2);
         DrvFTM_Start (DRVFTM_TIMER_3);
      }
   }
}
