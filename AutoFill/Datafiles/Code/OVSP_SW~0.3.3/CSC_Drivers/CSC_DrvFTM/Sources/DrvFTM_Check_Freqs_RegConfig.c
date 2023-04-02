/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the DrvFTM CSC Utilities functions
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "DrvFTM_Public.h"
#include "DrvFTM_Private.h"


/* ---------- include required interface: ----------------------------------- */
#include "OVSP_SW_Public.h"
#include "Boot_Public.h"
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
/* DrvFTM_Check_Freqs_RegConfig : To test the DrvFTM registers configuration for
 *                                frequencies acquisition
 *   Inputs: None
 *   Outputs:
 *     - p_pt_Check_Result: Result of the check
 *   Function return: None
 *   Pre-condition: None
*/
void DrvFTM_Check_Freqs_RegConfig (uint32_t * const p_pt_Check_Result)
{
   uint8_t v_OVSP_Side_Id;

   uint32_t v_FTM0_reg_SC;
   uint32_t v_FTM3_reg_SC;
   uint32_t v_FTM0_reg_CNTIN;
   uint32_t v_FTM3_reg_CNTIN;
   uint32_t v_FTM0_reg_COMBINE;
   uint32_t v_FTM3_reg_COMBINE;
   uint32_t v_FTM0_CH2_reg_CnSC;
   uint32_t v_FTM0_CH4_reg_CnSC;
   uint32_t v_FTM3_CH0_reg_CnSC;
   uint32_t v_FTM3_CH4_reg_CnSC;

   boolean_t v_Cond1;
   boolean_t v_Cond2;
   boolean_t v_Cond3;
   boolean_t v_Cond4;
   boolean_t v_Cond_part_synth;

   v_OVSP_Side_Id = Boot_Get_Side_Id ();

   v_FTM0_reg_SC = C_DrvFTM_Controller[DRVFTM_TIMER_0]->S_SC;
   v_FTM3_reg_SC = C_DrvFTM_Controller[DRVFTM_TIMER_3]->S_SC;
   v_FTM0_reg_CNTIN = C_DrvFTM_Controller[DRVFTM_TIMER_0]->S_CNTIN;
   v_FTM3_reg_CNTIN = C_DrvFTM_Controller[DRVFTM_TIMER_3]->S_CNTIN;
   v_FTM0_reg_COMBINE =  C_DrvFTM_Controller[DRVFTM_TIMER_0]->S_COMBINE;
   v_FTM3_reg_COMBINE = C_DrvFTM_Controller[DRVFTM_TIMER_3]->S_COMBINE;

   v_FTM0_CH2_reg_CnSC =
      C_DrvFTM_Controller[DRVFTM_TIMER_0]->S_CONTROLS[DRVFTM_CHAN_2].S_CnSC;

   v_FTM0_CH4_reg_CnSC =
      C_DrvFTM_Controller[DRVFTM_TIMER_0]->S_CONTROLS[DRVFTM_CHAN_4].S_CnSC;

   v_FTM3_CH0_reg_CnSC =
      C_DrvFTM_Controller[DRVFTM_TIMER_3]->S_CONTROLS[DRVFTM_CHAN_0].S_CnSC;

   v_FTM3_CH4_reg_CnSC =
      C_DrvFTM_Controller[DRVFTM_TIMER_3]->S_CONTROLS[DRVFTM_CHAN_4].S_CnSC;


   v_Cond1 = (((v_FTM0_reg_SC & DRVFTM_SC_CLKS_MASK) >> DRVFTM_SC_CLKS_SHIFT) == 1UL) &&
             (((v_FTM0_reg_SC & DRVFTM_SC_PS_MASK) >> DRVFTM_SC_PS_SHIFT) == 0UL) &&
             (((v_FTM0_reg_SC & DRVFTM_SC_TOIE_MASK) >> DRVFTM_SC_TOIE_SHIFT) == 1UL);

   v_Cond2 = (((v_FTM3_reg_SC & DRVFTM_SC_CLKS_MASK) >> DRVFTM_SC_CLKS_SHIFT) == 1UL) &&
             (((v_FTM3_reg_SC & DRVFTM_SC_PS_MASK) >> DRVFTM_SC_PS_SHIFT) == 0UL) &&
             (((v_FTM3_reg_SC & DRVFTM_SC_TOIE_MASK) >> DRVFTM_SC_TOIE_SHIFT) == 1UL);

   v_Cond3 = ((v_FTM0_reg_CNTIN == DRVFTM_CNTIN_CONFIG) &&
              (v_FTM3_reg_CNTIN == DRVFTM_CNTIN_CONFIG));

   v_Cond4 = ((v_FTM0_reg_COMBINE == DRVFTM_COMBINE_CONFIG) &&
              (v_FTM3_reg_COMBINE == DRVFTM_COMBINE_CONFIG));

   v_Cond_part_synth = v_Cond1 && v_Cond2 &&
                       v_Cond3 && v_Cond4;

   if (v_Cond_part_synth)
   {
      if (v_OVSP_Side_Id == BOOT_SIDE_ID_HS)
      {
         if (((v_FTM0_CH2_reg_CnSC & DRVFTM_NXOSY_RUNNING_CNSC_MASK) ==
               DRVFTM_NGOS1_ON_CNSC_CONFIG_HS)
            && ((v_FTM0_CH4_reg_CnSC & DRVFTM_NXOSY_RUNNING_CNSC_MASK) ==
                  DRVFTM_NTLOS1_ON_CNSC_CONFIG_HS)
            && ((v_FTM3_CH0_reg_CnSC & DRVFTM_NXOSY_RUNNING_CNSC_MASK) ==
                  DRVFTM_NGOS2_ON_CNSC_CONFIG_HS)
            && ((v_FTM3_CH4_reg_CnSC & DRVFTM_NXOSY_RUNNING_CNSC_MASK) ==
                  DRVFTM_NTLOS2_ON_CNSC_CONFIG_HS))
         {
            *p_pt_Check_Result = OVSP_SW_RESULT_OK;
         }
         else
         {
            *p_pt_Check_Result = OVSP_SW_RESULT_FAILED;
         }
      }
      else
      {
         if (v_OVSP_Side_Id == BOOT_SIDE_ID_LS)
         {
            if (((v_FTM0_CH2_reg_CnSC & DRVFTM_NXOSY_RUNNING_CNSC_MASK) ==
                  DRVFTM_NGOS1_ON_CNSC_CONFIG_LS)
               && ((v_FTM0_CH4_reg_CnSC & DRVFTM_NXOSY_RUNNING_CNSC_MASK) ==
                     DRVFTM_NTLOS1_ON_CNSC_CONFIG_LS)
               && ((v_FTM3_CH0_reg_CnSC & DRVFTM_NXOSY_RUNNING_CNSC_MASK) ==
                     DRVFTM_NGOS2_ON_CNSC_CONFIG_LS)
               && ((v_FTM3_CH4_reg_CnSC & DRVFTM_NXOSY_RUNNING_CNSC_MASK) ==
                     DRVFTM_NTLOS2_ON_CNSC_CONFIG_LS))
            {
               *p_pt_Check_Result = OVSP_SW_RESULT_OK;
            }
            else
            {
               *p_pt_Check_Result = OVSP_SW_RESULT_FAILED;
            }
         }
      }
   }
   else
   {
      *p_pt_Check_Result = OVSP_SW_RESULT_FAILED;
   }
}
