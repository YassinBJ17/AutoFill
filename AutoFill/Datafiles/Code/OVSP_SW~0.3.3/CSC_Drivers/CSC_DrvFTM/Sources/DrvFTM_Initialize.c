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
#include "OVSP_SW_Public.h"
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
/* DrvFTM_Initialize : To initialize the DrvFTM CSC
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void DrvFTM_Initialize (void)
{
   TS_DrvFTM_Registers * pt_ftm_reg;
   uint8_t v_OVSP_Side_Id;
   uint32_t v_FTM_Side_Id;
   uint32_t v_Channel_id;
   uint32_t v_Timer_id;
   uint32_t v_Iter_Freqs;

   pt_ftm_reg = OVSP_SW_NULL_POINTER;

   v_OVSP_Side_Id = Boot_Get_Side_Id();

   if (BOOT_SIDE_ID_LS == v_OVSP_Side_Id)
   {
      v_FTM_Side_Id = DRVFTM_OVSP_LS_ID;
   }
   else
   {
      v_FTM_Side_Id = DRVFTM_OVSP_HS_ID;
   }

   for (v_Iter_Freqs = 0UL; v_Iter_Freqs < DRVFTM_FREQ_PORTS_NB; v_Iter_Freqs++)
   {
      v_Timer_id =
         C_DrvFTM_Freq_Port_Config [v_FTM_Side_Id] [v_Iter_Freqs].S_Timer_Id;

      pt_ftm_reg =
         C_DrvFTM_Controller [v_Timer_id];

      pt_ftm_reg->S_SC = DRVFTM_SC_DEFAULT;

      v_Channel_id =
         C_DrvFTM_Freq_Port_Config [v_FTM_Side_Id] [v_Iter_Freqs].S_Channel_Id;

      pt_ftm_reg->S_CONTROLS [v_Channel_id].S_CnSC =
         C_DrvFTM_Freq_Port_Config [v_FTM_Side_Id] [v_Iter_Freqs].S_CnSC_Config;

      pt_ftm_reg->S_SC =
         C_DrvFTM_Freq_Port_Config [v_FTM_Side_Id] [v_Iter_Freqs].S_SC_Config;
   }

   if (v_OVSP_Side_Id == BOOT_SIDE_ID_HS)
   {
      pt_ftm_reg =
         C_DrvFTM_Controller [C_DrvFTM_CAM_Port_Config.S_Timer_Id];

      pt_ftm_reg->S_SC = DRVFTM_SC_DEFAULT;

      pt_ftm_reg->S_MOD =
         C_DrvFTM_CAM_Port_Config.S_MOD_Config;

      v_Channel_id =
         C_DrvFTM_CAM_Port_Config.S_Channel_Id;

      pt_ftm_reg->S_CONTROLS [v_Channel_id].S_CnSC =
         C_DrvFTM_CAM_Port_Config.S_CnSC_Config;

      pt_ftm_reg->S_CONTROLS [v_Channel_id].S_CnV =
         C_DrvFTM_CAM_Port_Config.S_CnV_Config;

      pt_ftm_reg->S_SC =
         C_DrvFTM_CAM_Port_Config.S_SC_Config;
   }
   else
   { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
      /* Nothing to do */
   }

   /* Initialize the NGOS1, NGOS2, NTLOS1, NTLOS2 and TSpeed data */
   DrvFTM_Initialize_Freq_Acq_Data ();
   DrvFTM_Initialize_TSpeed_Data ();
}

