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
#include "Boot_Public.h"
#include "OVSP_SW_Public.h"
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
/* DrvFTM_Check_CAM_RegConfig : To test the DrvFTM registers configuration for
 * CAM PWM generation
 *   Inputs: None
 *   Outputs:
 *     - p_pt_Check_Result: Result of the check
 *   Function return: None
 *   Pre-condition: None
*/
void DrvFTM_Check_CAM_RegConfig (uint32_t * const p_pt_Check_Result)
{
   uint8_t v_OVSP_Side_Id;

   uint32_t v_FTM2_reg_SC;
   uint32_t v_FTM2_reg_MOD;
   uint32_t v_FTM2_reg_POL;
   uint32_t v_FTM2_reg_CNTIN;
   uint32_t v_FTM2_reg_COMBINE;
   uint32_t v_FTM2_CH4_reg_CnSC;
   uint32_t v_FTM2_CH4_reg_CnV;

   TE_OVSP_SW_Cmd v_CAM_Cmd1;

   v_OVSP_Side_Id = Boot_Get_Side_Id ();

   v_FTM2_reg_SC = C_DrvFTM_Controller[DRVFTM_TIMER_2]->S_SC;
   v_FTM2_reg_MOD = C_DrvFTM_Controller[DRVFTM_TIMER_2]->S_MOD;
   v_FTM2_reg_POL = C_DrvFTM_Controller[DRVFTM_TIMER_2]->S_POL;
   v_FTM2_reg_CNTIN = C_DrvFTM_Controller[DRVFTM_TIMER_2]->S_CNTIN;
   v_FTM2_reg_COMBINE = C_DrvFTM_Controller[DRVFTM_TIMER_2]->S_COMBINE;
   v_FTM2_CH4_reg_CnSC = C_DrvFTM_Controller[DRVFTM_TIMER_2]->S_CONTROLS[DRVFTM_CHAN_4].S_CnSC;
   v_FTM2_CH4_reg_CnV = C_DrvFTM_Controller[DRVFTM_TIMER_2]->S_CONTROLS[DRVFTM_CHAN_4].S_CnV;

   v_CAM_Cmd1 = OVSP_Get_CAM_Cmd1 ();

   if (v_OVSP_Side_Id == BOOT_SIDE_ID_HS)
   {
      /* FTM2CH4, generates HS_CAM_CMD1_PWM for CAM Activation */
      if (E_OVSP_SW_Cmd_On == v_CAM_Cmd1)
      {
         if ((v_FTM2_reg_MOD == DRVFTM_CAM_MOD_CONFIG_HS) &&
             (v_FTM2_reg_POL == DRVFTM_CAM_POL_CONFIG_HS) &&
             (v_FTM2_reg_CNTIN == DRVFTM_CNTIN_CONFIG) &&
             (v_FTM2_reg_COMBINE == DRVFTM_COMBINE_CONFIG) &&
             (v_FTM2_CH4_reg_CnV == DRVFTM_CAM_CNV_CONFIG_HS))
         {

            if ((((v_FTM2_reg_SC & DRVFTM_SC_PWMEN4_MASK) >> DRVFTM_SC_PWMEN4_SHIFT) == 1)
               && (((v_FTM2_reg_SC & DRVFTM_SC_CPWMS_MASK) >> DRVFTM_SC_CPWMS_SHIFT) == 0)
               && (((v_FTM2_reg_SC & DRVFTM_SC_CLKS_MASK) >> DRVFTM_SC_CLKS_SHIFT) == 1)
               && (((v_FTM2_reg_SC & DRVFTM_SC_PS_MASK) >> DRVFTM_SC_PS_SHIFT) == 0)
               && (((v_FTM2_reg_SC & DRVFTM_SC_TOIE_MASK) >> DRVFTM_SC_TOIE_SHIFT)) == 1)
            {
               if ((((v_FTM2_CH4_reg_CnSC & DRVFTM_CNSC_ELSA_MASK)
                     >> DRVFTM_CNSC_ELSA_SHIFT) == 1) &&
                   (((v_FTM2_CH4_reg_CnSC & DRVFTM_CNSC_ELSB_MASK)
                     >> DRVFTM_CNSC_ELSB_SHIFT) == 0) &&
                   (((v_FTM2_CH4_reg_CnSC & DRVFTM_CNSC_MSA_MASK)
                     >> DRVFTM_CNSC_MSA_SHIFT) == 1) &&
                   (((v_FTM2_CH4_reg_CnSC & DRVFTM_CNSC_MSB_MASK)
                     >> DRVFTM_CNSC_MSB_SHIFT) == 0) &&
                   (((v_FTM2_CH4_reg_CnSC & DRVFTM_CNSC_CHIE_MASK)
                     >> DRVFTM_CNSC_CHIE_SHIFT)) == 1)
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
               *p_pt_Check_Result = OVSP_SW_RESULT_FAILED;
            }
         }
         else
         {
            *p_pt_Check_Result = OVSP_SW_RESULT_FAILED;
         }
      }
      else
      {
         if ((v_FTM2_reg_MOD == DRVFTM_CAM_MOD_CONFIG_HS) &&
             (v_FTM2_reg_POL == DRVFTM_CAM_POL_CONFIG_HS) &&
              (v_FTM2_reg_CNTIN == DRVFTM_CNTIN_CONFIG) &&
              (v_FTM2_reg_COMBINE == DRVFTM_COMBINE_CONFIG) &&
              (v_FTM2_CH4_reg_CnV == DRVFTM_CAM_CNV_CONFIG_HS))
         {

            if ((((v_FTM2_reg_SC & DRVFTM_SC_PWMEN4_MASK)
                  >> DRVFTM_SC_PWMEN4_SHIFT) == 1) &&
               (((v_FTM2_reg_SC & DRVFTM_SC_CPWMS_MASK)
                  >> DRVFTM_SC_CPWMS_SHIFT) == 0) &&
               (((v_FTM2_reg_SC & DRVFTM_SC_CLKS_MASK)
                  >> DRVFTM_SC_CLKS_SHIFT) == 1) &&
               (((v_FTM2_reg_SC & DRVFTM_SC_PS_MASK)
                  >> DRVFTM_SC_PS_SHIFT) == 0) &&
               (((v_FTM2_reg_SC & DRVFTM_SC_TOIE_MASK)
                  >> DRVFTM_SC_TOIE_SHIFT)) == 1)
            {
               if ((((v_FTM2_CH4_reg_CnSC & DRVFTM_CNSC_ELSA_MASK)
                     >> DRVFTM_CNSC_ELSA_SHIFT) == 0) &&
                  (((v_FTM2_CH4_reg_CnSC & DRVFTM_CNSC_ELSB_MASK)
                     >> DRVFTM_CNSC_ELSB_SHIFT) == 0) &&
                  (((v_FTM2_CH4_reg_CnSC & DRVFTM_CNSC_MSA_MASK)
                     >> DRVFTM_CNSC_MSA_SHIFT) == 1) &&
                  (((v_FTM2_CH4_reg_CnSC & DRVFTM_CNSC_MSB_MASK)
                     >> DRVFTM_CNSC_MSB_SHIFT) == 0) &&
                  (((v_FTM2_CH4_reg_CnSC & DRVFTM_CNSC_CHIE_MASK)
                     >> DRVFTM_CNSC_CHIE_SHIFT)) == 1)
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
               *p_pt_Check_Result = OVSP_SW_RESULT_FAILED;
            }
         }
         else
         {
            *p_pt_Check_Result = OVSP_SW_RESULT_FAILED;
         }
      }
   }
   else
   { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
      /* Tested in GPIO */
   }
}
