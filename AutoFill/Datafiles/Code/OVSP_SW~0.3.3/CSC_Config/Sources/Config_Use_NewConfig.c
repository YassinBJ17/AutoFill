/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the function allowing to use
 *               the new OVSP Config table
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "Config_Public.h"
#include "Config_Private.h"


/* ---------- include required interface: ----------------------------------- */
/* None */


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
/* Config_Use_NewConfig : To use the new OVSP Config table
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void Config_Use_NewConfig (void)
{
   Config_Copy_Cfg_With_Swap (&V_Config_OVSP_Cfg_Buffer, &V_Config_OVSP_Cfg_Used);
}
