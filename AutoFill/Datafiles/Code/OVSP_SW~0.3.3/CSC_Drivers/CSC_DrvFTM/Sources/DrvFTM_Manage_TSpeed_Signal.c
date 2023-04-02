/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the DrvFTM CSC functions to
 *               manage the DrvFTM registers configuration for TSpeed signal
 *               for acquisition and generation according to the OVSP side
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "DrvFTM_Public.h"
#include "DrvFTM_Private.h"


/* ---------- include required interface: ----------------------------------- */
#include "Boot_Public.h"
#include "DrvCPU_Public.h"
#include "Seq_Public.h"

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
/* DrvFTM_Manage_TSpeed_Signal : To Manage the TSpeed signal for acquisition
 * and generation according to the OVSP side
 *   Inputs:
 *       - p_TSpeed_Activation, the Activation/Deactivation command
 *       - p_modulo, The Modulo applied to the timer to generate the TSpeed
 *   Outputs:
 *     - p_pt_TSpeed_Status: Result of
 *   Function return: None
 *   Pre-condition: None
*/
void DrvFTM_Manage_TSpeed_Signal (void)
{
   uint8_t v_OVSP_Side_Id;

   v_OVSP_Side_Id = Boot_Get_Side_Id ();

   if (V_DrvFTM_New_Test_Speed_Recv == DRVFTM_TSPEED_SIGNAL_ON) /* PWM activated */
   {
      DrvCPU_Enter_Crit_Sect ();

      if (v_OVSP_Side_Id == BOOT_SIDE_ID_HS)
      {
         DrvFTM_Stop_TSpeed_HS ();
         DrvFTM_Start_TSpeed_HS (V_DrvFTM_TSpeed_Signal_Mod);
      }
      else
      {
         if (v_OVSP_Side_Id == BOOT_SIDE_ID_LS)
         {
            DrvFTM_Stop_TSpeed_LS ();
            DrvFTM_Start_TSpeed_LS (V_DrvFTM_TSpeed_Signal_Mod);
         }
      }

      DrvCPU_Exit_Crit_Sect ();
   }
   else
   { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
      /* Nothing to do */
   }
}

