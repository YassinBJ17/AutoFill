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
/* DrvFTM_Acquire_Raw_Data : To acquire the NGOS1, NGOS2, NTLOS1 and NTLOS2 periods values
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void DrvFTM_Acquire_RawData (uint32_t p_freq_id)
{
   volatile uint32_t v_Overflow;
   volatile uint32_t v_LastPeriod_Index;

   if (DRVFTM_CNSC_CHF_MASK ==
       ((*(V_DrvFTM_Acq_Raw_Freq_Data[p_freq_id].S_Freq_CnSC) & DRVFTM_CNSC_CHF_MASK)))
   {
      if (DRVFTM_FREQUENCIES_PERIODS_NB <=
          V_DrvFTM_Acq_Raw_Freq_Data[p_freq_id].S_LastPeriod_Index)
      {
         V_DrvFTM_Acq_Raw_Freq_Data[p_freq_id].S_LastPeriod_Index = 0UL;
      }
      else
      {
         V_DrvFTM_Acq_Raw_Freq_Data[p_freq_id].S_LastPeriod_Index++;
      }

      if ((OVSP_SW_LONG_MAX - 1UL) <=
          V_DrvFTM_Acq_Raw_Freq_Data[p_freq_id].S_NbPeriods_Acquired)
      {
         V_DrvFTM_Acq_Raw_Freq_Data[p_freq_id].S_NbPeriods_Acquired = 0UL;
      }
      else
      {
         V_DrvFTM_Acq_Raw_Freq_Data[p_freq_id].S_NbPeriods_Acquired++;
      }

      if (((*(V_DrvFTM_Acq_Raw_Freq_Data[p_freq_id].S_Freq_CnV) <
            V_DrvFTM_Acq_Raw_Freq_Data[p_freq_id].S_PeriodCnt_Prev)) &&
           (V_DrvFTM_Acq_Raw_Freq_Data[p_freq_id].S_OFlow_Cpt_Prev ==
            V_DrvFTM_Acq_Raw_Freq_Data[p_freq_id].S_OFlow_Cpt))
      {
         v_Overflow = V_DrvFTM_Acq_Raw_Freq_Data[p_freq_id].S_OFlow_Cpt + 1UL;
      }
      else
      {
         v_Overflow = V_DrvFTM_Acq_Raw_Freq_Data[p_freq_id].S_OFlow_Cpt;
      }

      v_LastPeriod_Index = V_DrvFTM_Acq_Raw_Freq_Data[p_freq_id].S_LastPeriod_Index;

      V_DrvFTM_Acq_Raw_Freq_Data[p_freq_id].S_Freq_Cnt [v_LastPeriod_Index] =
         (*(V_DrvFTM_Acq_Raw_Freq_Data[p_freq_id].S_Freq_CnV) +
           (v_Overflow * DRVFTM_TIMER_NB_MAX_VALUES));

      V_DrvFTM_Acq_Raw_Freq_Data[p_freq_id].S_PeriodCnt_Prev =
         *(V_DrvFTM_Acq_Raw_Freq_Data[p_freq_id].S_Freq_CnV);

      V_DrvFTM_Acq_Raw_Freq_Data[p_freq_id].S_OFlow_Cpt_Prev =
         V_DrvFTM_Acq_Raw_Freq_Data[p_freq_id].S_OFlow_Cpt;

      /* DRVFTM_CNSC_CHF_MASK = 0x80, clear CHF flag */
      *(V_DrvFTM_Acq_Raw_Freq_Data[p_freq_id].S_Freq_CnSC) &= ~DRVFTM_CNSC_CHF_MASK;
   }
   else
   { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
      /* TODO : Définir un CBIT pour les erreurs liées a une levée d'IRQ non mappée pour le Channel Flag */
   }
}
