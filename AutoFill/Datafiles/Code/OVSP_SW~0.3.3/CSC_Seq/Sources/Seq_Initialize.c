/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the Seq CSC initialization function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "Seq_Public.h"
#include "Seq_Private.h"


/* ---------- include required interface: ----------------------------------- */
#include "DrvCPU_Public.h"
#include "DrvNVIC_Public.h"

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
/* Seq_Initialize : To initialize the Seq CSC
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void Seq_Initialize (void)
{
   V_Seq_NewConfig_To_Manage = FALSE;
   V_Seq_NewConfig_To_Use = FALSE;

   DrvCPU_Enter_Crit_Sect ();

   DrvNVIC_Init_VTOR_InSRAM ();

   Seq_Start_Sequencer ();

   DrvCPU_Exit_Crit_Sect ();
}
