/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the DrvFTM CSC Utilities functions
 * -------------------------------------------------------------------------- */

/* ---------- include predefined types: ------------------------------------- */
#include "DrvFTM_Private.h"
#include "DrvFTM_Public.h"

#include "Boot_Public.h"
#include "MCP_Types.h"

/* ---------- include provided interface: ----------------------------------- */

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
/* DrvFTM_Start : To start the DrvFTM Timer
 *   Inputs:
 *      - p_ftm_id : the identifier of the timer
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void DrvFTM_Start(uint32_t p_ftm_id)
{
   TS_DrvFTM_Registers * pt_ftm_reg;

   if (p_ftm_id < DRVFTM_FTM_NUMBER)
   {
      pt_ftm_reg = C_DrvFTM_Controller[p_ftm_id];

      /* Start counter by setting clock source to FTM (75 MHz clock source from SPLL_CLK) */
      pt_ftm_reg->S_SC |= ((1UL << DRVFTM_SC_CLKS_SHIFT) & DRVFTM_SC_CLKS_MASK);
   }
}


/* DrvFTM_Stop : To stop the DrvFTM Timer
 *   Inputs:
 *      - p_ftm_id : the identifier of the timer
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void DrvFTM_Stop(uint32_t p_ftm_id)
{
   TS_DrvFTM_Registers * pt_ftm_reg;

   if (p_ftm_id < DRVFTM_FTM_NUMBER)
   {
      pt_ftm_reg = C_DrvFTM_Controller[p_ftm_id];

      /* Stop counter by setting clock source to NONE */
      pt_ftm_reg->S_SC &= ~DRVFTM_SC_CLKS_MASK;
   }
}



/* DrvFTM_Start_TSpeed_HS : To start the TSpeed HS signal
 *   Inputs:
 *      - p_mod : The modulo calculated to generate the requested TSpeed frequency
 *   Outputs:
 *      - p_pt_TSpeed_Status : The status of the activation of TSpeed
 *   Function return: None
 *   Pre-condition: None
*/
void DrvFTM_Start_TSpeed_HS (uint16_t p_mod)
{
   if (p_mod > (uint16_t) 0)
   {
      p_mod = p_mod - 1;
   }
   else
   { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
       /* Nothing to do */
   }

   /* (chan Edge or Level Select)= 0b01, toggle output on match */
   C_DrvFTM_Controller[DRVFTM_TIMER_1]->S_CONTROLS[DRVFTM_CHAN_1].S_CnSC = 0x0;

   C_DrvFTM_Controller[DRVFTM_TIMER_1]->S_CONTROLS[DRVFTM_CHAN_1].S_CnSC |=
      ((1UL << DRVFTM_CNSC_ELSA_SHIFT) & DRVFTM_CNSC_ELSA_MASK);

   C_DrvFTM_Controller[DRVFTM_TIMER_1]->S_CONTROLS[DRVFTM_CHAN_1].S_CnSC |=
      ((0UL << DRVFTM_CNSC_ELSB_SHIFT) & DRVFTM_CNSC_ELSB_MASK);

   C_DrvFTM_Controller[DRVFTM_TIMER_1]->S_CONTROLS[DRVFTM_CHAN_1].S_CnSC |=
      ((1UL << DRVFTM_CNSC_MSA_SHIFT) & DRVFTM_CNSC_MSA_MASK);

   C_DrvFTM_Controller[DRVFTM_TIMER_1]->S_CONTROLS[DRVFTM_CHAN_1].S_CnSC |=
      ((0UL << DRVFTM_CNSC_MSB_SHIFT) & DRVFTM_CNSC_MSB_MASK);

   C_DrvFTM_Controller[DRVFTM_TIMER_1]->S_CONTROLS[DRVFTM_CHAN_1].S_CnV = p_mod; /* The signal frequency of HS_PWM emitted to LS OVSP_SW is divided by two, thus S_MOD is multiplied by two */

   C_DrvFTM_Controller[DRVFTM_TIMER_1]->S_MOD = p_mod; /* The signal frequency of HS_PWM emitted to LS OVSP_SW is divided by two, thus S_MOD is multiplied by two */

   C_DrvFTM_Controller[DRVFTM_TIMER_1]->S_SC = 0;

   C_DrvFTM_Controller[DRVFTM_TIMER_1]->S_SC |=
      ((1UL << DRVFTM_SC_CLKS_SHIFT) & DRVFTM_SC_CLKS_MASK);

   C_DrvFTM_Controller[DRVFTM_TIMER_1]->S_SC |=
      ((1UL << DRVFTM_SC_PWMEN1_SHIFT) & DRVFTM_SC_PWMEN1_MASK);

   C_DrvFTM_Controller[DRVFTM_TIMER_0]->S_SC |=
      ((1UL << DRVFTM_SC_TOIE_SHIFT) & DRVFTM_SC_TOIE_MASK);

   /* (chan Edge or Level Select)= 0b01, Falling Edges detection, TriggTest acquisition channel  */
   C_DrvFTM_Controller[DRVFTM_TIMER_0]->S_CONTROLS[DRVFTM_CHAN_1].S_CnSC &= ~
      ((0UL << DRVFTM_CNSC_ELSA_SHIFT) & DRVFTM_CNSC_ELSA_MASK);

   C_DrvFTM_Controller[DRVFTM_TIMER_0]->S_CONTROLS[DRVFTM_CHAN_1].S_CnSC |=
      ((1UL << DRVFTM_CNSC_ELSB_SHIFT) & DRVFTM_CNSC_ELSB_MASK);

   C_DrvFTM_Controller[DRVFTM_TIMER_0]->S_CONTROLS[DRVFTM_CHAN_1].S_CnSC |=
      ((1UL << DRVFTM_CNSC_CHIE_SHIFT) & DRVFTM_CNSC_CHIE_MASK);

   DrvFTM_Start (0);
   DrvFTM_Start (1);
}


/* DrvFTM_Start_TSpeed_LS : To start the TSpeed LS signal
 *   Inputs:
 *      - p_mod : The modulo calculated to generate the requested TSpeed frequency
 *   Outputs:
 *      - p_pt_TSpeed_Status : The status of the activation of TSpeed
 *   Function return: None
 *   Pre-condition: None
*/
void DrvFTM_Start_TSpeed_LS (uint16_t p_mod)
{
   if (p_mod > (uint16_t) 0)
   {
      p_mod = p_mod - 1;
   }
   else
   { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
       /* Nothing to do */
   }

   C_DrvFTM_Controller[DRVFTM_TIMER_0]->S_MOD = (uint16_t) (0.5f * p_mod);

   /* (chan Edge or Level Select)= 0b01, toggle output on match */
   C_DrvFTM_Controller[DRVFTM_TIMER_0]->S_CONTROLS[DRVFTM_CHAN_3].S_CnSC |= ((1UL << DRVFTM_CNSC_ELSA_SHIFT)
                                                                            & DRVFTM_CNSC_ELSA_MASK);
   C_DrvFTM_Controller[DRVFTM_TIMER_0]->S_CONTROLS[DRVFTM_CHAN_3].S_CnSC |=
      ((1UL << DRVFTM_CNSC_MSA_SHIFT) & DRVFTM_CNSC_MSA_MASK);
   C_DrvFTM_Controller[DRVFTM_TIMER_0]->S_CONTROLS[DRVFTM_CHAN_3].S_CnV = (uint16_t) (0.5f * p_mod);

   C_DrvFTM_Controller[DRVFTM_TIMER_0]->S_SC = 0;
   C_DrvFTM_Controller[DRVFTM_TIMER_0]->S_SC |=
      ((1UL << DRVFTM_SC_CLKS_SHIFT) & DRVFTM_SC_CLKS_MASK);
   C_DrvFTM_Controller[DRVFTM_TIMER_0]->S_SC |=
      ((1UL << DRVFTM_SC_PWMEN3_SHIFT) & DRVFTM_SC_PWMEN3_MASK);
   C_DrvFTM_Controller[DRVFTM_TIMER_1]->S_SC |=
      ((1UL << DRVFTM_SC_TOIE_SHIFT) & DRVFTM_SC_TOIE_MASK);

   DrvFTM_Start (1);

   /* (chan Edge or Level Select)= 0b10, Both Edges detection, TriggTest acquisition channel */
   C_DrvFTM_Controller[DRVFTM_TIMER_1]->S_CONTROLS[DRVFTM_CHAN_5].S_CnSC |=
      ((1UL << DRVFTM_CNSC_ELSA_SHIFT) & DRVFTM_CNSC_ELSA_MASK);
   C_DrvFTM_Controller[DRVFTM_TIMER_1]->S_CONTROLS[DRVFTM_CHAN_5].S_CnSC |=
      ((1UL << DRVFTM_CNSC_ELSB_SHIFT) & DRVFTM_CNSC_ELSB_MASK);

   C_DrvFTM_Controller[DRVFTM_TIMER_1]->S_CONTROLS[DRVFTM_CHAN_5].S_CnSC |=
      ((1UL << DRVFTM_CNSC_CHIE_SHIFT) & DRVFTM_CNSC_CHIE_MASK);
}


/* DrvFTM_Stop_TSpeed_HS : To stop the TSpeed HS signal
 *   Inputs: None
 *   Outputs:
 *      - p_pt_TSpeed_Status : The status of the activation of TSpeed
 *   Function return: None
 *   Pre-condition: None
*/
void DrvFTM_Stop_TSpeed_HS (void)
{
   /* (chan Edge or Level Select)= 0b00, Not Used */
   C_DrvFTM_Controller[DRVFTM_TIMER_1]->S_CONTROLS[DRVFTM_CHAN_1].S_CnSC &= ~DRVFTM_CNSC_ELSA_MASK;
   C_DrvFTM_Controller[DRVFTM_TIMER_1]->S_CONTROLS[DRVFTM_CHAN_1].S_CnSC &= ~DRVFTM_CNSC_ELSB_MASK;

   C_DrvFTM_Controller[DRVFTM_TIMER_1]->S_CONTROLS[DRVFTM_CHAN_1].S_CnV = 0x0;
   C_DrvFTM_Controller[DRVFTM_TIMER_1]->S_MOD = 0x0;

   C_DrvFTM_Controller[DRVFTM_TIMER_1]->S_SC &=~DRVFTM_SC_CLKS_MASK;

   /* (chan Edge or Level Select)= 0b01, Falling Edges detection, TriggTest acquisition channel  */
   C_DrvFTM_Controller[DRVFTM_TIMER_0]->S_CONTROLS[DRVFTM_CHAN_1].S_CnSC = 0;

   DrvFTM_Stop (1);
}


/* DrvFTM_Stop_TSpeed_LS : To stop the TSpeed LS signal
 *   Inputs: None
 *   Outputs:
 *      - p_pt_TSpeed_Status : The status of the activation of TSpeed
 *   Function return: None
 *   Pre-condition: None
*/
void DrvFTM_Stop_TSpeed_LS (void)
{

   DrvFTM_Stop (0);

   /* (chan Edge or Level Select)= 0b00, Not Used */
   C_DrvFTM_Controller[DRVFTM_TIMER_0]->S_CONTROLS[DRVFTM_CHAN_3].S_CnSC &= ~DRVFTM_CNSC_ELSA_MASK;
   C_DrvFTM_Controller[DRVFTM_TIMER_0]->S_CONTROLS[DRVFTM_CHAN_3].S_CnSC &= ~DRVFTM_CNSC_ELSB_MASK;

   C_DrvFTM_Controller[DRVFTM_TIMER_0]->S_CONTROLS[DRVFTM_CHAN_3].S_CnV = 0x0;

   while (C_DrvFTM_Controller[DRVFTM_TIMER_0]->S_MOD != 0x0)
   {
      C_DrvFTM_Controller[DRVFTM_TIMER_0]->S_MOD = 0x0;
   }

   C_DrvFTM_Controller[DRVFTM_TIMER_0]->S_SC &= ~DRVFTM_SC_CLKS_MASK;

   C_DrvFTM_Controller[DRVFTM_TIMER_0]->S_SC |= ((1UL << DRVFTM_SC_TOIE_SHIFT) & DRVFTM_SC_TOIE_MASK);

   DrvFTM_Stop (1);
}



/* DrvFTM_Get_NbPeriods_Acquired : To provide the number of NGOS1, NGOS2, NTLOS1 or NTLOS2 acquired periods
 *   Inputs:
 *       - p_freq_id, Id of the frequency to check
 *   Outputs: None
 *   Function return:
 *     - Number of the requested frequency acquired periods
 *   Pre-condition: None
*/
uint32_t DrvFTM_Get_NbPeriods_Acquired (uint32_t p_freq_id)
{
   uint32_t v_return;

   if (p_freq_id < DRVFTM_FREQS_NB)
   {
      v_return = V_DrvFTM_Acq_Raw_Freq_Data[p_freq_id].S_NbPeriods_Acquired;
   }

   return v_return;
}

/* DrvFTM_Get_LastPeriod_Index : To provide the index of NGOS1, NGOS2, NTLOS1 or NTLOS2 last period
 *   Inputs:
 *       - p_freq_id, Id of the frequency to check
 *   Outputs: None
 *   Function return:
 *     - Index of requested frequency last period
 *   Pre-condition: None
*/
uint32_t DrvFTM_Get_LastPeriod_Index (uint32_t p_freq_id)
{
   uint32_t v_return;

   if (p_freq_id < DRVFTM_FREQS_NB)
   {
      v_return = V_DrvFTM_Acq_Raw_Freq_Data[p_freq_id].S_LastPeriod_Index;
   }

   return v_return;
}

