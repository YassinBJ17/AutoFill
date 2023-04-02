/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the new OVSP Config table management
 *               function for Background
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "Config_Public.h"
#include "Config_Private.h"


/* ---------- include required interface: ----------------------------------- */
#include "Seq_Public.h"


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
/* Config_Manage_NewConfig_BckGrnd : To manage a new OVSP Config table in Background
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void Config_Manage_NewConfig_BckGrnd (void)
{
   TE_Config_Integrity_Status v_Cfg_Integrity;

   Config_Check_OVSP_Cfg (E_Config_OVSP_Cfg_New, &v_Cfg_Integrity);

   if (E_Config_Integrity_OK == v_Cfg_Integrity)
   {
      Seq_Set_NewConfig_toUse ();

      Config_Write_In_FlexNVM ();
   }
   else
   { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
      /* Nothing to do */
   }
}
