/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the DrvFTM CSC functions to
 *               manage the DrvFTM registers configuration for TSpeed signal
 *               for acquisition and generation according to the OVSP side
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "DrvFTM_Public.h"
#include "DrvFTM_Private.h"


/* ---------- include required interface: ----------------------------------- */
#include "Boot_Public.h"
#include "Seq_Public.h"
#include "OVSP_SW_Public.h"
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
/* DrvFTM_Stop_Freqs_Acq : To reconfigure FTMs to deactivate frequencies
 *                         acquisition according to the OVSP side
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void DrvFTM_Stop_Freqs_Acq (void)
{
   DrvFTM_Stop_NGOS1_Acquisition ();
   DrvFTM_Stop_NGOS2_Acquisition ();
   DrvFTM_Stop_NTLOS1_Acquisition ();
   DrvFTM_Stop_NTLOS2_Acquisition ();
   DrvFTM_Stop (DRVFTM_TIMER_0);
   DrvFTM_Stop (DRVFTM_TIMER_1);
   DrvFTM_Stop (DRVFTM_TIMER_3);
}

