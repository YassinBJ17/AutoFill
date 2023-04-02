/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the DrvFTM CSC initialization function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "DrvFTM_Private.h"
#include "DrvFTM_Public.h"

/* ---------- include required interface: ----------------------------------- */
#include "Boot_Public.h"
#include "OVSP_Public.h"
#include "MCP_Types.h"

/* ---------- internal define constants: ------------------------------------ */
/* None */

/* ---------- internal types: ----------------------------------------------- */
/* None */

/* ---------- internal operations: ------------------------------------------ */
/* None */

/* ---------- internal constants: ------------------------------------------- */
/* None */

/* ---------- internal data: ------------------------------------------------ */
/* None */

/* ---------- provided operation bodies: ------------------------------------ */
/* DrvFTM_Initialize_Freq_Acq_Data : To initialize the NGOS1, NGOS2, NTLOS1 and NTLOS2 data
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void DrvFTM_Initialize_Freq_Acq_Data (void)
{
   uint8_t v_OVSP_Side_Id;
   uint32_t v_Timer_id;
   uint32_t v_Channel_id;
   uint32_t v_FTM_Side_Id;
   uint32_t v_Iter_Freqs;


   v_OVSP_Side_Id = Boot_Get_Side_Id();

   if (BOOT_SIDE_ID_LS == v_OVSP_Side_Id)
   {
      v_FTM_Side_Id = DRVFTM_OVSP_LS_ID;
   }
   else
   {
      v_FTM_Side_Id = DRVFTM_OVSP_HS_ID;
   }

   for (v_Iter_Freqs = 0; v_Iter_Freqs < DRVFTM_FREQS_NB; v_Iter_Freqs++)
   {
      v_Timer_id = C_DrvFTM_Freq_Port_Config [v_FTM_Side_Id][v_Iter_Freqs].S_Timer_Id;
      v_Channel_id = C_DrvFTM_Freq_Port_Config [v_FTM_Side_Id][v_Iter_Freqs].S_Channel_Id;

      V_DrvFTM_Acq_Raw_Freq_Data[v_Iter_Freqs].S_Timer_Id = v_Timer_id;
      V_DrvFTM_Acq_Raw_Freq_Data[v_Iter_Freqs].S_Timer_Side = v_FTM_Side_Id;

      V_DrvFTM_Acq_Raw_Freq_Data[v_Iter_Freqs].S_Freq_CnV =
         &(C_DrvFTM_Controller [v_Timer_id]->S_CONTROLS [v_Channel_id].S_CnV);

      V_DrvFTM_Acq_Raw_Freq_Data[v_Iter_Freqs].S_Freq_CnSC =
         &(C_DrvFTM_Controller [v_Timer_id]->S_CONTROLS [v_Channel_id].S_CnSC);

      V_DrvFTM_Acq_Raw_Freq_Data[v_Iter_Freqs].S_Freq_SC =
         &(C_DrvFTM_Controller [v_Timer_id]->S_SC);

      V_DrvFTM_Acq_Raw_Freq_Data[v_Iter_Freqs].S_LastPeriod_Index = 0UL;
      V_DrvFTM_Acq_Raw_Freq_Data[v_Iter_Freqs].S_NbPeriods_Acquired = 0UL;
      V_DrvFTM_Acq_Raw_Freq_Data[v_Iter_Freqs].S_PeriodCnt_Prev = 0UL;
      V_DrvFTM_Acq_Raw_Freq_Data[v_Iter_Freqs].S_OFlow_Cpt = 0UL;
      V_DrvFTM_Acq_Raw_Freq_Data[v_Iter_Freqs].S_OFlow_Cpt_Prev = 0UL;
   }

   V_DrvFTM_Acq_Raw_Freq_Data [DRVFTM_NGOS1_DATA_ID].S_Freq_Cnt = OVSP_Get_Periods_Array (OVSP_NGOS1_ID);
   V_DrvFTM_Acq_Raw_Freq_Data [DRVFTM_NGOS2_DATA_ID].S_Freq_Cnt = OVSP_Get_Periods_Array (OVSP_NGOS2_ID);

   V_DrvFTM_Acq_Raw_Freq_Data [DRVFTM_NTLOS1_DATA_ID].S_Freq_Cnt = OVSP_Get_Periods_Array (OVSP_NTLOS1_ID);
   V_DrvFTM_Acq_Raw_Freq_Data [DRVFTM_NTLOS2_DATA_ID].S_Freq_Cnt = OVSP_Get_Periods_Array (OVSP_NTLOS2_ID);

   V_DrvFTM_Acq_Raw_Freq_Data [DRVFTM_TSPEED_DATA_ID].S_Freq_Cnt = OVSP_Get_Periods_Array (OVSP_TSPEED_ID);
}
