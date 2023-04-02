/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the timers overflows counting functions
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "DrvFTM_Public.h"
#include "DrvFTM_Private.h"


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
/* DrvFTM_Count_FTM1_Overflow : To count the FlexTimer 1 overflow (TSpeed)
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void DrvFTM_Count_FTM0_Overflow (void)
{
   DrvFTM_Count_Overflow (DRVFTM_NGOS1_DATA_ID, DRVFTM_TIMER_0);
   DrvFTM_Count_Overflow (DRVFTM_NTLOS1_DATA_ID, DRVFTM_TIMER_0);

   if (DRVFTM_OVSP_HS_ID == V_DrvFTM_Acq_Raw_Freq_Data[DRVFTM_TSPEED_DATA_ID].S_Timer_Side)
   {
      DrvFTM_Count_Overflow (DRVFTM_TSPEED_DATA_ID, DRVFTM_TIMER_0);
   }
   else
   { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
      /* Nothing to do */
   }
}
