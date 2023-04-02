/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the OVSP CSC initialization function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "OVSP_Public.h"
#include "OVSP_Private.h"


/* ---------- include required interface: ----------------------------------- */
#include "kcg_types.h"
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
/* OVSP_Initialize : To initialize the OVSP CSC
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void OVSP_Initialize (void)
{
   uint32_t v_Iter_Array;

   V_OVSP_NGOS1_NbPeriods_Prev = 0UL;
   V_OVSP_NGOS2_NbPeriods_Prev = 0UL;
   V_OVSP_NTLOS1_NbPeriods_Prev = 0UL;
   V_OVSP_NTLOS2_NbPeriods_Prev = 0UL;

   V_OVSP_TSpeed_NbPeriods_Prev = 0UL;

   V_OVSP_Context_In.V_NTL_OVSTHRESD_Threshold = 0.0f;
   V_OVSP_Context_In.V_NTL_OVSTHRESD_Window = 0.0f;

   V_OVSP_Context_In.V_NTL_OVSTHRESD_N = 0UL;

   V_OVSP_Context_In.V_NG_OVSTHRESD_Threshold = 0.0f;

   for (v_Iter_Array = 0UL; v_Iter_Array < OVSP_NTL_VAR_THRES_NB ; v_Iter_Array++)
   {
      V_OVSP_Context_In.V_NG_OVSTHRESD_Threshold_Ar [v_Iter_Array] = 0.0f;
      V_OVSP_Context_In.V_NTL_OVSVARIABLE_Threshold_Ar [v_Iter_Array] = 0.0f;
   }

   V_OVSP_Context_In.V_NG_OVSTHRESD_Window = 0.0f;

   V_OVSP_Context_In.V_NG_OVSTHRESD_N = 0UL;

   V_OVSP_Context_In.V_OVS_NTLThresholdInhib = E_Not_Inhibited;

   V_OVSP_Context_In.V_NTLOS1_NbPeriods = 0UL;
   V_OVSP_Context_In.V_NTLOS2_NbPeriods = 0UL;
   V_OVSP_Context_In.V_NGOS1_NbPeriods = 0UL;
   V_OVSP_Context_In.V_NGOS2_NbPeriods = 0UL;

   V_OVSP_Context_In.V_OVS_OneSensorNGInhib = E_Not_Inhibited;
   V_OVSP_Context_In.V_OVS_OneSensorNTLInhib = E_Not_Inhibited;

   V_OVSP_Context_In.V_NTLOS1_Timeout = 0.0f;
   V_OVSP_Context_In.V_NTLOS2_Timeout = 0.0f;
   V_OVSP_Context_In.V_NGOS1_Timeout = 0.0f;
   V_OVSP_Context_In.V_NGOS2_Timeout = 0.0f;

   V_OVSP_Context_In.V_OVS_NGInhib = E_Not_Inhibited;
   V_OVSP_Context_In.V_OVS_CSSInhib = E_Not_Inhibited;

   V_OVSP_Context_In.V_NTL_OVS_FUNCTION = E_NTL_Fixed_Thres;

   V_OVSP_Context_In.V_NTLOS1_LastPeriod_Index = 0UL;
   V_OVSP_Context_In.V_NTLOS2_LastPeriod_Index = 0UL;
   V_OVSP_Context_In.V_NGOS1_LastPeriod_Index = 0UL;
   V_OVSP_Context_In.V_NGOS2_LastPeriod_Index = 0UL;
   V_OVSP_Context_In.V_Test_LastPeriod_Index = 0UL;

   for (v_Iter_Array = 0UL; v_Iter_Array <= OVSP_FREQ_PERIODS_NB ; v_Iter_Array++)
   {
      V_OVSP_Context_In.V_NTLOS1_Periods_Ar [v_Iter_Array] = 0UL;
      V_OVSP_Context_In.V_NTLOS2_Periods_Ar [v_Iter_Array] = 0UL;

      V_OVSP_Context_In.V_NGOS1_Periods_Ar [v_Iter_Array] = 0UL;
      V_OVSP_Context_In.V_NGOS2_Periods_Ar [v_Iter_Array] = 0UL;

      V_OVSP_Context_In.V_Test_Periods_Ar [v_Iter_Array] = 0UL;
   }

   V_OVSP_Context_In.V_DININHIB = E_Cmd_Off;
   V_OVSP_Context_In.V_OSREARM = E_Cmd_Off;

   V_OVSP_Context_In.V_CBIT_Result = E_Test_Passed;

   V_OVSP_Context_In.V_CAM_HS_Current = 0.0f;
   V_OVSP_Context_In.V_CAM_LS_Current = 0.0f;

   V_OVSP_Context_In.V_CAN_OSARM_Request = E_NotRequested;

   V_OVSP_Context_In.V_NTL_OneSensor_CSSauthorization = E_NotAuthorized;
   V_OVSP_Context_In.V_NG_OneSensor_CSSauthorization = E_NotAuthorized;

   V_OVSP_Context_In.V_CAN_CAM_Cmd1 = E_Cmd_Off;
   V_OVSP_Context_In.V_CAN_CAM_Cmd2 = E_Cmd_Off;

   V_OVSP_Context_In.V_NGOS1_NbPeriods_Acquired = 0UL;
   V_OVSP_Context_In.V_NGOS2_NbPeriods_Acquired = 0UL;
   V_OVSP_Context_In.V_NTLOS1_NbPeriods_Acquired = 0UL;
   V_OVSP_Context_In.V_NTLOS2_NbPeriods_Acquired = 0UL;
   V_OVSP_Context_In.V_Test_NbPeriods_Acquired = 0UL;

   V_OVSP_Context_In.V_NG_NTL_Statuses_Sent = E_No;

   V_OVSP_Context_In.V_NGOS1_100 = 0.0f;
   V_OVSP_Context_In.V_NGOS2_100 = 0.0f;
   V_OVSP_Context_In.V_NTLOS1_100 = 0.0f;
   V_OVSP_Context_In.V_NTLOS2_100 = 0.0f;

   V_OVSP_Context_In.V_Interlock_Inhib = E_Not_Inhibited;

   V_OVSP_Context_In.V_OVSP_Side_Id = E_OVSP_HS;

   V_OVSP_Context_In.V_CAN_REARM_Request = E_NotRequested;

   V_OVSP_Context_In.V_OVSP_SW_Mode = E_Mode_Init;

   ToDetectOverspeed_init (&V_OVSP_Context_Out);
}
