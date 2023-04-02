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

#include "OVSP_SW_Public.h"


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
/* DrvFTM_Count_Overflow : To count the FlexTimer 0, 1 and 3 overflows
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void DrvFTM_Count_Overflow (uint32_t p_freq_id, uint32_t p_timer_id)
{
   volatile boolean_t v_vond_1;
   volatile boolean_t v_vond_2;
   volatile boolean_t v_vond_3;
   volatile boolean_t v_vond_synth;


   if (DRVFTM_SC_TOF_MASK == (*(V_DrvFTM_Acq_Raw_Freq_Data[p_freq_id].S_Freq_SC) & DRVFTM_SC_TOF_MASK ))
   {
      /* Overflow Detected on FTM1, increment the overflow counter on this channel */
      if ((OVSP_SW_LONG_MAX - 1UL) <= V_DrvFTM_Acq_Raw_Freq_Data[p_freq_id].S_OFlow_Cpt)
      {
         V_DrvFTM_Acq_Raw_Freq_Data[p_freq_id].S_OFlow_Cpt = 0UL;
      }
      else
      {
         V_DrvFTM_Acq_Raw_Freq_Data[p_freq_id].S_OFlow_Cpt++;
      }
   }

   v_vond_1 = ((p_freq_id == DRVFTM_NTLOS1_DATA_ID) &&
               (p_timer_id == DRVFTM_TIMER_0) &&
               (V_DrvFTM_Acq_Raw_Freq_Data[p_freq_id].S_Timer_Side == DRVFTM_OVSP_LS_ID)) ||
              ((p_freq_id == DRVFTM_TSPEED_DATA_ID) &&
               (p_timer_id == DRVFTM_TIMER_0) &&
               (V_DrvFTM_Acq_Raw_Freq_Data[p_freq_id].S_Timer_Side == DRVFTM_OVSP_HS_ID));

   v_vond_2 = ((p_freq_id == DRVFTM_TSPEED_DATA_ID) &&
               (p_timer_id == DRVFTM_TIMER_1) &&
               (V_DrvFTM_Acq_Raw_Freq_Data[p_freq_id].S_Timer_Side == DRVFTM_OVSP_LS_ID));

   v_vond_3 =  (((p_freq_id == DRVFTM_NTLOS2_DATA_ID)) &&
                 (p_timer_id == DRVFTM_TIMER_3));

   v_vond_synth = v_vond_1 || v_vond_2 || v_vond_3;

   if (v_vond_synth)
   {
      *(V_DrvFTM_Acq_Raw_Freq_Data[p_freq_id].S_Freq_SC) &= ~DRVFTM_SC_TOF_MASK;
   }
   else
   { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
      /* Nothing to do */
   }
}
