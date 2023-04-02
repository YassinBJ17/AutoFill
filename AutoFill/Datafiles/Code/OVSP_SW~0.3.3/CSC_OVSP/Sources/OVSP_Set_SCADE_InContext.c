/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the function to set the Input Context
 *               for the SCADE treatments
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "OVSP_Private.h"


/* ---------- include required interface: ----------------------------------- */
#include "Boot_Public.h"
#include "DrvCPU_Public.h"
#include "DrvFTM_Public.h"
#include "CAN_Public.h"
#include "CBIT_Public.h"
#include "Config_Public.h"
#include "IO_Public.h"
#include "Modes_Public.h"
#include "ToDetectOverspeed.h"

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
/* OVSP_Set_SCADE_InContext : To set the Input Context for the SCADE treatments
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void OVSP_Set_SCADE_InContext (void)
{
   uint32_t v_Iter_Array;

   uint8_t v_OVSP_Side_Id;
   uint32_t v_NGOS1_NbPeriods;
   uint32_t v_NGOS2_NbPeriods;
   uint32_t v_NTLOS1_NbPeriods;
   uint32_t v_NTLOS2_NbPeriods;
   uint32_t v_TSpeed_NbPeriods;

   V_OVSP_Context_In.V_NTL_OVSTHRESD_Threshold = (kcg_float32) Config_Get_NTL_OVSTHRESD_Threshold ();
   V_OVSP_Context_In.V_NTL_OVSTHRESD_Window = (kcg_float32) Config_Get_NTL_OVSTHRESD_Window ();

   V_OVSP_Context_In.V_NTL_OVSTHRESD_N = (kcg_uint32) Config_Get_NTL_OVSTHRESD_N ();

   V_OVSP_Context_In.V_NG_OVSTHRESD_Threshold = (kcg_float32) Config_Get_NG_OVSTHRESD_Threshold ();

   for (v_Iter_Array = 0UL; v_Iter_Array < OVSP_NTL_VAR_THRES_NB ; v_Iter_Array++)
   {
      /* {{RELAX<SYNCHRONe_C_Code_10.7> There is no loss of precision */
      /* as it is a 8-bit Unsigned Integer converted to a 32-bit float. */
      V_OVSP_Context_In.V_NG_OVSTHRESD_Threshold_Ar [v_Iter_Array] =
         (kcg_float32) Config_Get_NG_OVSTHRESD_Thres_Ar (v_Iter_Array);

      V_OVSP_Context_In.V_NTL_OVSVARIABLE_Threshold_Ar [v_Iter_Array] =
         (kcg_float32) Config_Get_NTL_OVSVARIA_Thres_Ar (v_Iter_Array);
      /* }} RELAX<SYNCHRONe_C_Code_10.7> */
   }

   V_OVSP_Context_In.V_NG_OVSTHRESD_Window = (kcg_float32) Config_Get_NG_OVSTHRESD_Window ();
   V_OVSP_Context_In.V_NG_OVSTHRESD_N = (kcg_uint32) Config_Get_NG_OVSTHRESD_N ();

   /* >RELAX<SYNCHRONe_C_Code_12.14> The function return fits in the enum type. */
   V_OVSP_Context_In.V_OVS_NTLThresholdInhib = (TE_Inhibition) Config_Get_OVS_NTLThresholdInhib ();

   v_OVSP_Side_Id = Boot_Get_Side_Id ();

   if (BOOT_SIDE_ID_LS == v_OVSP_Side_Id)
   {
      V_OVSP_Context_In.V_NTLOS1_NbPeriods = (kcg_uint32) Config_Get_NTLOS1_NL ();
      V_OVSP_Context_In.V_NTLOS2_NbPeriods = (kcg_uint32) Config_Get_NTLOS2_NL ();
      V_OVSP_Context_In.V_NGOS1_NbPeriods = (kcg_uint32) Config_Get_NGOS1_NL ();
      V_OVSP_Context_In.V_NGOS2_NbPeriods = (kcg_uint32) Config_Get_NGOS2_NL ();

      V_OVSP_Context_In.V_OVSP_Side_Id = E_OVSP_LS;
   }
   else
   {
      V_OVSP_Context_In.V_NTLOS1_NbPeriods = (kcg_uint32) Config_Get_NTLOS1_NH ();
      V_OVSP_Context_In.V_NTLOS2_NbPeriods = (kcg_uint32) Config_Get_NTLOS2_NH ();
      V_OVSP_Context_In.V_NGOS1_NbPeriods = (kcg_uint32) Config_Get_NGOS1_NH ();
      V_OVSP_Context_In.V_NGOS2_NbPeriods = (kcg_uint32) Config_Get_NGOS2_NH ();

      V_OVSP_Context_In.V_OVSP_Side_Id = E_OVSP_HS;
   }

   /* {{RELAX<SYNCHRONe_C_Code_12.14> The function return fits in the enum type. */
   V_OVSP_Context_In.V_OVS_OneSensorNGInhib = (TE_Inhibition) Config_Get_OVS_OneSensorNGInhib ();
   V_OVSP_Context_In.V_OVS_OneSensorNTLInhib = (TE_Inhibition) Config_Get_OVS_OneSensorNTLInhib ();
   /* }} RELAX<SYNCHRONe_C_Code_12.14> */

   V_OVSP_Context_In.V_NTLOS1_Timeout = (kcg_float32) Config_Get_NTLOS1_Timeout ();
   V_OVSP_Context_In.V_NTLOS2_Timeout = (kcg_float32) Config_Get_NTLOS2_Timeout ();
   V_OVSP_Context_In.V_NGOS1_Timeout = (kcg_float32) Config_Get_NGOS1_Timeout ();
   V_OVSP_Context_In.V_NGOS2_Timeout = (kcg_float32) Config_Get_NGOS2_Timeout ();

   /* {{RELAX<SYNCHRONe_C_Code_12.14> The function return fits in the enum type. */
   V_OVSP_Context_In.V_OVS_NGInhib = (TE_Inhibition) Config_Get_OVS_NGInhib ();
   V_OVSP_Context_In.V_OVS_CSSInhib = (TE_Inhibition) Config_Get_OVS_CSSInhib ();
   /* }} RELAX<SYNCHRONe_C_Code_12.14> */

   /* >RELAX<SYNCHRONe_C_Code_12.14> The function return minus 1 fits in the enum type. */
   /* >RELAX<SYNCHRONe_C_Code_10.3> The function return minus 1 fits in the enum type. */
   V_OVSP_Context_In.V_NTL_OVS_FUNCTION = (TE_NTL_Threshold_Type) (Config_Get_NTL_OVS_FUNCTION () - (uint8_t) 1);


   /* Masking of the ITs for this critical section to avoid corruption of the acquired data by new acquisitions */
   DrvCPU_Enter_Crit_Sect ();

   V_OVSP_Context_In.V_NTLOS1_LastPeriod_Index = (kcg_uint32) DrvFTM_Get_LastPeriod_Index (DRVFTM_NTLOS1_DATA_ID);
   V_OVSP_Context_In.V_NTLOS2_LastPeriod_Index = (kcg_uint32) DrvFTM_Get_LastPeriod_Index (DRVFTM_NTLOS2_DATA_ID);
   V_OVSP_Context_In.V_NGOS1_LastPeriod_Index = (kcg_uint32) DrvFTM_Get_LastPeriod_Index (DRVFTM_NGOS1_DATA_ID);
   V_OVSP_Context_In.V_NGOS2_LastPeriod_Index = (kcg_uint32) DrvFTM_Get_LastPeriod_Index (DRVFTM_NGOS2_DATA_ID);
   V_OVSP_Context_In.V_Test_LastPeriod_Index = (kcg_uint32) DrvFTM_Get_LastPeriod_Index (DRVFTM_TSPEED_DATA_ID);

   /* End of the critical section, ITs unmasking */
   DrvCPU_Exit_Crit_Sect ();


   /* Fields V_NTLOS1_Periods_Ar [], V_NTLOS2_Periods_Ar [], V_NGOS1_Periods_Ar [], V_NGOS2_Periods_Ar [] and  */
   /* V_Test_Periods_Ar [] of V_OVSP_Context_In data are directly set in the "Acquire" functions of the IO CSC */

   /* {{RELAX<SYNCHRONe_C_Code_12.14> The enum types are similar then compatible. */
   V_OVSP_Context_In.V_DININHIB = (TE_Cmd_Status) IO_Get_DININHIB_Cmd ();
   V_OVSP_Context_In.V_OSREARM = (TE_Cmd_Status) IO_Get_OSREARM_Cmd ();

   V_OVSP_Context_In.V_CBIT_Result = (TE_Test_Result) CBIT_Get_Test_Result ();
   /* }} RELAX<SYNCHRONe_C_Code_12.14> */

   V_OVSP_Context_In.V_CAM_HS_Current = (kcg_float32) IO_Get_CAM_HS_Current ();
   V_OVSP_Context_In.V_CAM_LS_Current = (kcg_float32) IO_Get_CAM_LS_Current ();

   /* {{RELAX<SYNCHRONe_C_Code_12.14> The enum types are similar then compatible. */
   V_OVSP_Context_In.V_CAN_OSARM_Request = (TE_Request) CAN_Get_OSARM_Rqst ();

   V_OVSP_Context_In.V_NTL_OneSensor_CSSauthorization = (TE_OneSensor_Authorization) CAN_Get_NTL_OneSensor_CSSAuth ();
   V_OVSP_Context_In.V_NG_OneSensor_CSSauthorization = (TE_OneSensor_Authorization) CAN_Get_NG_OneSensor_CSSAuth ();

   V_OVSP_Context_In.V_CAN_CAM_Cmd1 = (TE_Cmd_Status) CAN_Get_CAM_Cmd_1 ();
   V_OVSP_Context_In.V_CAN_CAM_Cmd2 = (TE_Cmd_Status) CAN_Get_CAM_Cmd_2 ();
   /* }} RELAX<SYNCHRONe_C_Code_12.14> */


   /* Masking of the ITs for this critical section to avoid corruption of the acquired data by new acquisitions */
   DrvCPU_Enter_Crit_Sect ();

   v_NGOS1_NbPeriods = DrvFTM_Get_NbPeriods_Acquired (DRVFTM_NGOS1_DATA_ID);
   V_OVSP_Context_In.V_NGOS1_NbPeriods_Acquired = (kcg_uint32) (v_NGOS1_NbPeriods - V_OVSP_NGOS1_NbPeriods_Prev);
   V_OVSP_NGOS1_NbPeriods_Prev = v_NGOS1_NbPeriods;

   v_NGOS2_NbPeriods = DrvFTM_Get_NbPeriods_Acquired (DRVFTM_NGOS2_DATA_ID);
   V_OVSP_Context_In.V_NGOS2_NbPeriods_Acquired = (kcg_uint32) (v_NGOS2_NbPeriods - V_OVSP_NGOS2_NbPeriods_Prev);
   V_OVSP_NGOS2_NbPeriods_Prev = v_NGOS2_NbPeriods;

   v_NTLOS1_NbPeriods = DrvFTM_Get_NbPeriods_Acquired (DRVFTM_NTLOS1_DATA_ID);
   V_OVSP_Context_In.V_NTLOS1_NbPeriods_Acquired = (kcg_uint32) (v_NTLOS1_NbPeriods - V_OVSP_NTLOS1_NbPeriods_Prev);
   V_OVSP_NTLOS1_NbPeriods_Prev = v_NTLOS1_NbPeriods;

   v_NTLOS2_NbPeriods = DrvFTM_Get_NbPeriods_Acquired (DRVFTM_NTLOS2_DATA_ID);
   V_OVSP_Context_In.V_NTLOS2_NbPeriods_Acquired = (kcg_uint32) (v_NTLOS2_NbPeriods - V_OVSP_NTLOS2_NbPeriods_Prev);
   V_OVSP_NTLOS2_NbPeriods_Prev = v_NTLOS2_NbPeriods;

   v_TSpeed_NbPeriods = DrvFTM_Get_NbPeriods_Acquired (DRVFTM_TSPEED_DATA_ID);
   V_OVSP_Context_In.V_Test_NbPeriods_Acquired = (kcg_uint32) (v_TSpeed_NbPeriods - V_OVSP_TSpeed_NbPeriods_Prev);
   V_OVSP_TSpeed_NbPeriods_Prev = v_TSpeed_NbPeriods;

   /* End of the critical section, ITs unmasking */
   DrvCPU_Exit_Crit_Sect ();


   /* >RELAX<SYNCHRONe_C_Code_12.14> The enum types are similar then compatible. */
   V_OVSP_Context_In.V_NG_NTL_Statuses_Sent = (TE_Answer) CAN_Get_NG_NTL_Statuses_Sent ();

   V_OVSP_Context_In.V_NGOS1_100 = (kcg_float32) Config_Get_NGOS1_100 ();
   V_OVSP_Context_In.V_NGOS2_100 = (kcg_float32) Config_Get_NGOS2_100 ();
   V_OVSP_Context_In.V_NTLOS1_100 = (kcg_float32) Config_Get_NTLOS1_100 ();
   V_OVSP_Context_In.V_NTLOS2_100 = (kcg_float32) Config_Get_NTLOS1_100 ();

   /* {{RELAX<SYNCHRONe_C_Code_12.14> The enum types are similar then compatible. */
   V_OVSP_Context_In.V_Interlock_Inhib = (TE_Inhibition) Config_Get_Interlock_Inhib ();

   V_OVSP_Context_In.V_CAN_REARM_Request = (TE_Request) CAN_Get_REARM_Rqst ();

   V_OVSP_Context_In.V_OVSP_SW_Mode = (TE_OVSP_Mode) Modes_Get_SW_Mode ();
   /* }} RELAX<SYNCHRONe_C_Code_12.14> */
}
