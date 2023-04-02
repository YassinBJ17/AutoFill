/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the function indicating there is a Failure
 *               to write in FlexNVM
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
/* Logbook_Is_Failure_to_Write : To provide the flag indicating there is a Failure to write in FlexNVM
 *   Inputs: None
 *   Outputs: None
 *   Function return: Answer to the question "Is there a Failure to write in FlexNVM ?"
 *   Pre-condition: None
*/
boolean_t Logbook_Is_Failure_to_Write (void)
{
   return (V_Logbook_Failure_to_Write);
}
