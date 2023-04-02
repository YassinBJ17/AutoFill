/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the Discretes outputs generation function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "DrvFTM_Public.h"
#include "DrvFTM_Private.h"

/* ---------- include required interface: ----------------------------------- */
#include "Config_Public.h"

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
/* DrvFTM_Prepare_TSpeed_Signal : To generate the TSpeed output signal
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: The running mode is E_Modes_TriggeredTest
*/
void DrvFTM_Prepare_TSpeed_Signal (float32_t p_trig_speed)
{
   float32_t v_Delta_trig_speed;
   float32_t v_NGOS1_100;
   uint16_t v_min_trig_speed;

   v_NGOS1_100 = Config_Get_NGOS1_100 ();

   v_min_trig_speed = (uint16_t) ((DRVFTM_FREQ_CLK_HZ / ((OVSP_SW_WORD_MAX * v_NGOS1_100) / 100.0f)) + 1.0f);

   v_Delta_trig_speed = p_trig_speed - V_DrvFTM_TSpeed_Test_Speed_Prev;

   if (v_Delta_trig_speed < 0.0f)
   {
      v_Delta_trig_speed = 0.0f - v_Delta_trig_speed;
   }

   if ((p_trig_speed >= 0.0f) &&
       ((p_trig_speed < (V_DrvFTM_TSpeed_Applied_Speed - 0.5f)) ||
       (p_trig_speed > (V_DrvFTM_TSpeed_Applied_Speed + 0.5f))) &&
       (v_Delta_trig_speed > OVSP_SW_FLOAT_EPS))
   {
      if (p_trig_speed >= v_min_trig_speed)
      {
         /* p_trig_speed is a rate of v_NGOS1_100 in percent */
         V_DrvFTM_TSpeed_Signal_Mod = (uint16_t) (DRVFTM_FREQ_CLK_HZ / ((p_trig_speed * v_NGOS1_100) / 100.0f));
         V_DrvFTM_TSpeed_Applied_Speed = p_trig_speed;
      }
      else
      {
         /* v_min_trig_speed is a rate of v_NGOS1_100 in percent */
         V_DrvFTM_TSpeed_Signal_Mod = (uint16_t) (DRVFTM_FREQ_CLK_HZ / ((v_min_trig_speed * v_NGOS1_100) / 100.0f));
         V_DrvFTM_TSpeed_Applied_Speed = v_min_trig_speed;
      }

      V_DrvFTM_New_Test_Speed_Recv = TRUE;
   }
   else
   {
      V_DrvFTM_New_Test_Speed_Recv = FALSE;
   }

   V_DrvFTM_TSpeed_Test_Speed_Prev = p_trig_speed;
}
