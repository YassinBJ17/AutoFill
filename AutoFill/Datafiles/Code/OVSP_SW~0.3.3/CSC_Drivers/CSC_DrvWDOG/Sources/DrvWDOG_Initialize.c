/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the DrvWDOG CSC initialization function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "DrvWDOG_Public.h"
#include "DrvWDOG_Private.h"


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
/* DrvWDOG_Initialize : To initialize the DrvWDOG CSC
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void DrvWDOG_Initialize (void)
{
   C_DrvWDOG_Registers->S_CNT = DRVWDOG_UNLOCK_WATCHDOG;

   C_DrvWDOG_Registers->S_CS = DRVWDOG_DISABLE_WATCHDOG;

   C_DrvWDOG_Registers->S_TOVAL = DRVWDOG_INITIALIZE_TIMEOUT;
}
