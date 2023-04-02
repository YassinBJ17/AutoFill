/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the Seq CSC Utilities functions
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "Seq_Public.h"
#include "Seq_Private.h"


/* ---------- include required interface: ----------------------------------- */
#include "DrvLPIT_Public.h"
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
/* Seq_Set_NewConfig_Status : To set the flag indicating there is a new configuration to manage
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void Seq_Set_NewConfig_Status (void)
{
   V_Seq_NewConfig_To_Manage = TRUE;
}


/* Seq_Set_NewConfig_toUse : To set the flag indicating there is a new OVSP Config table to use
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void Seq_Set_NewConfig_toUse (void)
{
   V_Seq_NewConfig_To_Use = TRUE;
}


/* Seq_Start_Sequencer : To start the sequencer
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void Seq_Start_Sequencer (void)
{
   DrvLPIT_Start (DRVLPIT_IDENT_0, DRVLPIT_500_US);

   DrvNVIC_Initialize (DRVNVIC_SEQ_IRQ_SELECTION);
}
