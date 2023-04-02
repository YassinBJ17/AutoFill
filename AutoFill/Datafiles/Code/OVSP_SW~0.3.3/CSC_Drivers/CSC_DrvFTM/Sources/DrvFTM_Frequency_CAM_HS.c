/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the NGOS1 frequency input acquisition functions
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "DrvFTM_Public.h"
#include "DrvFTM_Private.h"


/* ---------- include required interface: ----------------------------------- */
#include "Boot_Public.h"
#include "OVSP_Public.h"

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
/* DrvFTM_Start_CAM_Generation : To start the CAM HS Square signal generation
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void DrvFTM_Start_CAM_Generation (void)
{
   volatile TS_DrvFTM_Registers * pt_FLEXTIMER2 =
      C_DrvFTM_Controller [DRVFTM_TIMER_2];

   pt_FLEXTIMER2->S_CONTROLS [DRVFTM_CHAN_4].S_CnSC |= DRVFTM_CNSC_ELSA_MASK;
}

/* DrvFTM_Stop_CAM_Generation : To stop the CAM HS Square signal generation
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void DrvFTM_Stop_CAM_Generation (void)
{
   volatile TS_DrvFTM_Registers * pt_FLEXTIMER2 =
      C_DrvFTM_Controller [DRVFTM_TIMER_2];

   pt_FLEXTIMER2->S_CONTROLS [DRVFTM_CHAN_4].S_CnSC &= ~DRVFTM_CNSC_ELSA_MASK;
   pt_FLEXTIMER2->S_CONTROLS [DRVFTM_CHAN_4].S_CnSC &= ~DRVFTM_CNSC_ELSA_MASK;
}
