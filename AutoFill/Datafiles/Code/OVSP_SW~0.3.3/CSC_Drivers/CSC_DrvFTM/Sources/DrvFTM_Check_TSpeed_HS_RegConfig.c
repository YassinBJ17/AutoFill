/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the DrvFTM CSC function to test the
 *               DrvFTM registers configuration for High Side TSpeed
 *               PWM generation and acquisition
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "DrvFTM_Public.h"
#include "DrvFTM_Private.h"


/* ---------- include required interface: ----------------------------------- */
#include "OVSP_SW_Public.h"
#include "CAN_Public.h"
#include "Config_Public.h"


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
/* DrvFTM_Check_TSpeed_HS_RegConfig : To test the DrvFTM registers configuration for
 * High Side TSpeed PWM generation and acquisition
 *   Inputs: None
 *   Outputs:
 *     - p_pt_Check_Result: Result of the check
 *   Function return: None
 *   Pre-condition: None
*/
void DrvFTM_Check_TSpeed_HS_RegConfig (uint32_t * const p_pt_Check_Result)
{
   uint32_t v_FTM1_reg_SC;
   uint32_t v_FTM1_reg_MOD;
   uint32_t v_FTM1_CH1_reg_CnSC;
   uint32_t v_FTM1_CH1_reg_CnV;

   uint32_t v_FTM0_reg_SC;
   uint32_t v_FTM0_reg_MOD;
   uint32_t v_FTM0_CH1_reg_CnSC;

   uint32_t v_modulo;

   float32_t v_min_trig_speed;
   float32_t v_NGOS1_100;

   uint32_t v_trigtest_emit;
   uint32_t v_trigtest_recv;

   v_FTM1_reg_SC = C_DrvFTM_Controller[DRVFTM_TIMER_1]->S_SC;
   v_FTM1_reg_MOD = C_DrvFTM_Controller[DRVFTM_TIMER_1]->S_MOD;
   v_FTM1_CH1_reg_CnSC = C_DrvFTM_Controller[DRVFTM_TIMER_1]->S_CONTROLS[DRVFTM_CHAN_1].S_CnSC;
   v_FTM1_CH1_reg_CnV = C_DrvFTM_Controller[DRVFTM_TIMER_1]->S_CONTROLS[DRVFTM_CHAN_1].S_CnV;

   v_FTM0_reg_SC = C_DrvFTM_Controller[DRVFTM_TIMER_0]->S_SC;
   v_FTM0_reg_MOD = C_DrvFTM_Controller[DRVFTM_TIMER_0]->S_MOD;
   v_FTM0_CH1_reg_CnSC = C_DrvFTM_Controller[DRVFTM_TIMER_0]->S_CONTROLS[DRVFTM_CHAN_1].S_CnSC;

   v_NGOS1_100 = Config_Get_NGOS1_100 ();

   v_min_trig_speed = (uint16_t) ((DRVFTM_FREQ_CLK_HZ / ((OVSP_SW_WORD_MAX * v_NGOS1_100) / 100.0f)) + 1.0f);

   if ((V_DrvFTM_TSpeed_Applied_Speed > 0.0f))
   {
      if (V_DrvFTM_TSpeed_Applied_Speed >= v_min_trig_speed)
      {
         /* V_DrvFTM_TSpeed_Applied_Speed is a rate of v_NGOS1_100 in percent */
         v_modulo = (uint16_t) (DRVFTM_FREQ_CLK_HZ / ((V_DrvFTM_TSpeed_Applied_Speed * v_NGOS1_100) / 100.0f));
      }
      else
      {
         /* v_min_trig_speed is a rate of v_NGOS1_100 in percent */
         v_modulo = (uint16_t) (DRVFTM_FREQ_CLK_HZ / ((v_min_trig_speed * v_NGOS1_100) / 100.0f));
      }
   }
   else
   {
      v_modulo = 0U;
   }

   if (v_modulo > 0U)
   {
      v_modulo = v_modulo - 1U;
   }
   else
   { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
      /* Nothing to do */
   }

   /* HS_PWM emission verification */

   if ((v_FTM1_reg_MOD == v_modulo) && (v_FTM1_CH1_reg_CnV == v_modulo))
   {
      if ((((v_FTM1_reg_SC & DRVFTM_SC_PWMEN1_MASK) >> DRVFTM_SC_PWMEN1_SHIFT) == 1UL) &&
         (((v_FTM1_reg_SC & DRVFTM_SC_CPWMS_MASK) >> DRVFTM_SC_CPWMS_SHIFT) == 0UL) &&
         (((v_FTM1_reg_SC & DRVFTM_SC_CLKS_MASK) >> DRVFTM_SC_CLKS_SHIFT) == 1UL) &&
         (((v_FTM1_reg_SC & DRVFTM_SC_PS_MASK) >> DRVFTM_SC_PS_SHIFT) == 0UL) &&
         (((v_FTM1_reg_SC & DRVFTM_SC_TOIE_MASK) >> DRVFTM_SC_TOIE_SHIFT)) == 0UL)
      {
         if ((((v_FTM1_CH1_reg_CnSC & DRVFTM_CNSC_ELSA_MASK) >> DRVFTM_CNSC_ELSA_SHIFT)
            == 1)
             && (((v_FTM1_CH1_reg_CnSC & DRVFTM_CNSC_ELSB_MASK) >> DRVFTM_CNSC_ELSB_SHIFT)
                == 0)
             && (((v_FTM1_CH1_reg_CnSC & DRVFTM_CNSC_MSA_MASK) >> DRVFTM_CNSC_MSA_SHIFT)
                == 1)
             && (((v_FTM1_CH1_reg_CnSC & DRVFTM_CNSC_MSB_MASK) >> DRVFTM_CNSC_MSB_SHIFT)
                == 0)
             && (((v_FTM1_CH1_reg_CnSC & DRVFTM_CNSC_CHIE_MASK) >> DRVFTM_CNSC_CHIE_SHIFT)) == 0)
         {
            v_trigtest_emit = OVSP_SW_RESULT_OK;
         }
         else
         {
            v_trigtest_emit = OVSP_SW_RESULT_FAILED;
         }
      }
      else
      {
         v_trigtest_emit = OVSP_SW_RESULT_FAILED;
      }
   }
   else
   {
      v_trigtest_emit = OVSP_SW_RESULT_FAILED;
   }

   /* HS acquisition of LS_PWM verification */
   if (v_FTM0_reg_MOD == 0)
   {
      if ((((v_FTM0_reg_SC & DRVFTM_SC_CPWMS_MASK) >> DRVFTM_SC_CPWMS_SHIFT) == 0) &&
          (((v_FTM0_reg_SC & DRVFTM_SC_CLKS_MASK) >> DRVFTM_SC_CLKS_SHIFT) == 1) &&
          (((v_FTM0_reg_SC & DRVFTM_SC_PS_MASK) >> DRVFTM_SC_PS_SHIFT) == 0) &&
          (((v_FTM0_reg_SC & DRVFTM_SC_TOIE_MASK) >> DRVFTM_SC_TOIE_SHIFT)) == 1)
      {
         if ((((v_FTM0_CH1_reg_CnSC & DRVFTM_CNSC_ELSA_MASK) >> DRVFTM_CNSC_ELSA_SHIFT)
            == 0) &&
             (((v_FTM0_CH1_reg_CnSC & DRVFTM_CNSC_ELSB_MASK) >> DRVFTM_CNSC_ELSB_SHIFT)
                == 1) &&
             (((v_FTM0_CH1_reg_CnSC & DRVFTM_CNSC_MSA_MASK) >> DRVFTM_CNSC_MSA_SHIFT)
                == 0) &&
             (((v_FTM0_CH1_reg_CnSC & DRVFTM_CNSC_MSB_MASK) >> DRVFTM_CNSC_MSB_SHIFT)
                == 0) &&
             (((v_FTM0_CH1_reg_CnSC & DRVFTM_CNSC_CHIE_MASK) >> DRVFTM_CNSC_CHIE_SHIFT)) == 1)
         {
            v_trigtest_recv = OVSP_SW_RESULT_OK;
         }
         else
         {
            v_trigtest_recv = OVSP_SW_RESULT_FAILED;
         }
      }
      else
      {
         v_trigtest_recv = OVSP_SW_RESULT_FAILED;
      }
   }
   else
   {
      v_trigtest_recv = OVSP_SW_RESULT_FAILED;
   }

   *p_pt_Check_Result =
      (uint32_t) ((uint8_t) v_trigtest_emit | (uint8_t) v_trigtest_recv);
}
