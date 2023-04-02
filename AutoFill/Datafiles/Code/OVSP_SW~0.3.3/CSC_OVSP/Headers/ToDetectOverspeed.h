/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** Command: kcg66.exe -config P:/OVSP_SW/CSC_OVSP/.SCADE/KCG/config.txt
** Generation date: 2022-11-16T17:38:35
*************************************************************$ */
#ifndef _ToDetectOverspeed_H_
#define _ToDetectOverspeed_H_

#include "kcg_types.h"
#include "ToComputeSpeedLevel.h"
#include "ToComputeOSARM.h"
#include "ToComputeCamCmdx.h"
#include "ToComputeSpeed.h"
#include "ToSelectNTLThreshold.h"
#include "ToComputeOSREARM.h"
#include "ToComputeDOUTINHIB.h"
#include "ToDetectNxOverspeed.h"

/* ========================  input structure  ====================== */
typedef struct {
  kcg_float32 /* V_NTL_OVSTHRESD_Threshold/,
     _L422/ */ V_NTL_OVSTHRESD_Threshold;
  kcg_float32 /* V_NTL_OVSTHRESD_Window/, _L2/ */ V_NTL_OVSTHRESD_Window;
  kcg_uint32 /* V_NTL_OVSTHRESD_N/, _L58/ */ V_NTL_OVSTHRESD_N;
  kcg_float32 /* V_NG_OVSTHRESD_Threshold/, _L56/ */ V_NG_OVSTHRESD_Threshold;
  array_float32_6 /* V_NG_OVSTHRESD_Threshold_Ar/,
     _L418/ */ V_NG_OVSTHRESD_Threshold_Ar;
  kcg_float32 /* V_NG_OVSTHRESD_Window/, _L55/ */ V_NG_OVSTHRESD_Window;
  kcg_uint32 /* V_NG_OVSTHRESD_N/, _L59/ */ V_NG_OVSTHRESD_N;
  array_float32_6 /* V_NTL_OVSVARIABLE_Threshold_Ar/,
     _L419/,
     _L443/ */ V_NTL_OVSVARIABLE_Threshold_Ar;
  TE_Inhibition /* V_OVS_NTLThresholdInhib/, _L104/ */ V_OVS_NTLThresholdInhib;
  kcg_uint32 /* V_NTLOS1_NbPeriods/ */ V_NTLOS1_NbPeriods;
  kcg_uint32 /* V_NTLOS2_NbPeriods/ */ V_NTLOS2_NbPeriods;
  kcg_uint32 /* V_NGOS1_NbPeriods/ */ V_NGOS1_NbPeriods;
  kcg_uint32 /* V_NGOS2_NbPeriods/ */ V_NGOS2_NbPeriods;
  TE_Inhibition /* V_OVS_OneSensorNGInhib/, _L13/ */ V_OVS_OneSensorNGInhib;
  TE_Inhibition /* V_OVS_OneSensorNTLInhib/, _L14/ */ V_OVS_OneSensorNTLInhib;
  kcg_float32 /* V_NTLOS1_Timeout/ */ V_NTLOS1_Timeout;
  kcg_float32 /* V_NTLOS2_Timeout/ */ V_NTLOS2_Timeout;
  kcg_float32 /* V_NGOS1_Timeout/ */ V_NGOS1_Timeout;
  kcg_float32 /* V_NGOS2_Timeout/ */ V_NGOS2_Timeout;
  TE_Inhibition /* V_OVS_NGInhib/, _L107/ */ V_OVS_NGInhib;
  TE_Inhibition /* V_OVS_CSSInhib/, _L236/, _L352/ */ V_OVS_CSSInhib;
  TE_NTL_Threshold_Type /* V_NTL_OVS_FUNCTION/, _L420/ */ V_NTL_OVS_FUNCTION;
  kcg_uint32 /* V_NTLOS1_LastPeriod_Index/ */ V_NTLOS1_LastPeriod_Index;
  kcg_uint32 /* V_NTLOS2_LastPeriod_Index/ */ V_NTLOS2_LastPeriod_Index;
  kcg_uint32 /* V_NGOS1_LastPeriod_Index/ */ V_NGOS1_LastPeriod_Index;
  kcg_uint32 /* V_NGOS2_LastPeriod_Index/ */ V_NGOS2_LastPeriod_Index;
  kcg_uint32 /* V_Test_LastPeriod_Index/ */ V_Test_LastPeriod_Index;
  array_uint32_101 /* V_NTLOS1_Periods_Ar/ */ V_NTLOS1_Periods_Ar;
  array_uint32_101 /* V_NTLOS2_Periods_Ar/ */ V_NTLOS2_Periods_Ar;
  array_uint32_101 /* V_NGOS1_Periods_Ar/ */ V_NGOS1_Periods_Ar;
  array_uint32_101 /* V_NGOS2_Periods_Ar/ */ V_NGOS2_Periods_Ar;
  array_uint32_101 /* V_Test_Periods_Ar/ */ V_Test_Periods_Ar;
  TE_Cmd_Status /* V_DININHIB/, _L121/ */ V_DININHIB;
  TE_Cmd_Status /* V_OSREARM/, _L122/ */ V_OSREARM;
  TE_Test_Result /* V_CBIT_Result/, _L356/ */ V_CBIT_Result;
  kcg_float32 /* V_CAM_HS_Current/, _L182/ */ V_CAM_HS_Current;
  kcg_float32 /* V_CAM_LS_Current/, _L183/ */ V_CAM_LS_Current;
  TE_Request /* V_CAN_OSARM_Request/, _L357/ */ V_CAN_OSARM_Request;
  TE_OneSensor_Authorization /* V_NTL_OneSensor_CSSauthorization/,
     _L221/ */ V_NTL_OneSensor_CSSauthorization;
  TE_OneSensor_Authorization /* V_NG_OneSensor_CSSauthorization/,
     _L220/ */ V_NG_OneSensor_CSSauthorization;
  TE_Cmd_Status /* V_CAN_CAM_Cmd1/, _L234/, _L346/ */ V_CAN_CAM_Cmd1;
  TE_Cmd_Status /* V_CAN_CAM_Cmd2/, _L235/, _L347/ */ V_CAN_CAM_Cmd2;
  kcg_uint32 /* V_NGOS1_NbPeriods_Acquired/ */ V_NGOS1_NbPeriods_Acquired;
  kcg_uint32 /* V_NGOS2_NbPeriods_Acquired/ */ V_NGOS2_NbPeriods_Acquired;
  kcg_uint32 /* V_NTLOS1_NbPeriods_Acquired/ */ V_NTLOS1_NbPeriods_Acquired;
  kcg_uint32 /* V_NTLOS2_NbPeriods_Acquired/ */ V_NTLOS2_NbPeriods_Acquired;
  kcg_uint32 /* V_Test_NbPeriods_Acquired/ */ V_Test_NbPeriods_Acquired;
  TE_Answer /* V_NG_NTL_Statuses_Sent/, _L527/ */ V_NG_NTL_Statuses_Sent;
  kcg_float32 /* V_NGOS1_100/, _L299/, _L465/, _V_NGOS1_100/ */ V_NGOS1_100;
  kcg_float32 /* V_NGOS2_100/, _L300/, _L466/, _V_NGOS2_100/ */ V_NGOS2_100;
  kcg_float32 /* V_NTLOS1_100/, _L297/, _V_NTLOS1_100/ */ V_NTLOS1_100;
  kcg_float32 /* V_NTLOS2_100/, _L298/, _V_NTLOS2_100/ */ V_NTLOS2_100;
  TE_Inhibition /* V_Interlock_Inhib/, _L348/ */ V_Interlock_Inhib;
  TE_OVSP_Side /* V_OVSP_Side_Id/, _L355/ */ V_OVSP_Side_Id;
  TE_Request /* V_CAN_REARM_Request/, _L359/ */ V_CAN_REARM_Request;
  TE_OVSP_Mode /* V_OVSP_SW_Mode/, _L524/ */ V_OVSP_SW_Mode;
} inC_ToDetectOverspeed;

/* =====================  no output structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  TE_Cmd_Status /* V_CAM_Cmd1/, _L349/ */ V_CAM_Cmd1;
  TE_Cmd_Status /* V_CAM_Cmd2/, _L350/ */ V_CAM_Cmd2;
  TE_Cmd_Status /* V_DOUTINHIB/, _L345/ */ V_DOUTINHIB;
  TE_Cmd_Status /* V_OSARM_Cmd/, _L354/ */ V_OSARM_Cmd;
  kcg_float32 /* V_NGOS1_Measure/,
     _L404/,
     _L421/,
     _L499/,
     _V_NGOS1_Measure/ */ V_NGOS1_Measure;
  kcg_float32 /* V_NGOS2_Measure/,
     _L405/,
     _L427/,
     _L496/,
     _V_NGOS2_Measure/ */ V_NGOS2_Measure;
  kcg_float32 /* V_NTLOS1_Measure/,
     _L402/,
     _L497/,
     _V_NTLOS1_Measure/ */ V_NTLOS1_Measure;
  kcg_float32 /* V_NTLOS2_Measure/,
     _L403/,
     _L498/,
     _V_NTLOS2_Measure/ */ V_NTLOS2_Measure;
  TE_Answer /* V_NGOS1_OutOfTime/,
     _L449/,
     _L504/,
     _V_NGOS1_OutOfTime/ */ V_NGOS1_OutOfTime;
  TE_Answer /* V_NGOS2_OutOfTime/,
     _L448/,
     _L505/,
     _V_NGOS2_OutOfTime/ */ V_NGOS2_OutOfTime;
  TE_Answer /* V_NTLOS1_OutOfTime/,
     _L502/,
     _V_NTLOS1_OutOfTime/ */ V_NTLOS1_OutOfTime;
  TE_Answer /* V_NTLOS2_OutOfTime/,
     _L503/,
     _V_NTLOS2_OutOfTime/ */ V_NTLOS2_OutOfTime;
  TE_Answer /* V_NGOS1_OutOfHigh/,
     _L506/,
     _V_NGOS1_OutOfHigh/ */ V_NGOS1_OutOfHigh;
  TE_Answer /* V_NGOS2_OutOfHigh/,
     _L507/,
     _V_NGOS2_OutOfHigh/ */ V_NGOS2_OutOfHigh;
  TE_Answer /* V_NTLOS1_OutOfHigh/,
     _L508/,
     _V_NTLOS1_OutOfHigh/ */ V_NTLOS1_OutOfHigh;
  TE_Answer /* V_NTLOS2_OutOfHigh/,
     _L509/,
     _V_NTLOS2_OutOfHigh/ */ V_NTLOS2_OutOfHigh;
  TE_Answer /* V_NGOS1_Updated/,
     _L440/,
     _L515/,
     _V_NGOS1_Updated/ */ V_NGOS1_Updated;
  TE_Answer /* V_NGOS2_Updated/,
     _L441/,
     _L516/,
     _V_NGOS2_Updated/ */ V_NGOS2_Updated;
  TE_Answer /* V_NTLOS1_Updated/,
     _L517/,
     _V_NTLOS1_Updated/ */ V_NTLOS1_Updated;
  TE_Answer /* V_NTLOS2_Updated/,
     _L518/,
     _V_NTLOS2_Updated/ */ V_NTLOS2_Updated;
  TE_Speed_Level /* V_Engine_SpeedLevel/,
     _L520/,
     _L521/,
     _L522/,
     _L523/,
     _V_Engine_SpeedLevel/ */ V_Engine_SpeedLevel;
  TE_Cmd_Status /* V_REARM_Cmd/, _L358/, _L435/, _V_REARM_Cmd/ */ V_REARM_Cmd;
  kcg_float32 /* V_Test_Speed_Measure/,
     _L519/,
     _V_Test_Speed_Measure/ */ V_Test_Speed_Measure;
  /* -----------------------   local probes  ------------------------- */
  TE_Answer /* V_NGOS1_OVS_Conditions_Met/,
     _L223/,
     _L468/,
     _L490/,
     _V_TriggTest_Overspeed_Detected/ */ V_NGOS1_OVS_Conditions_Met;
  TE_Answer /* V_NGOS2_OVS_Conditions_Met/,
     _L225/ */ V_NGOS2_OVS_Conditions_Met;
  TE_Answer /* V_NTLOS1_OVS_Conditions_Met/,
     _L224/ */ V_NTLOS1_OVS_Conditions_Met;
  TE_Answer /* V_NTLOS2_OVS_Conditions_Met/,
     _L226/ */ V_NTLOS2_OVS_Conditions_Met;
  kcg_float32 /* V_NTLOS1_Threshold_Used/,
     _L423/,
     _L430/,
     _V_NTLOS1_Threshold_Used/ */ V_NTLOS1_Threshold_Used;
  kcg_float32 /* V_NTLOS2_Threshold_Used/,
     _L426/,
     _L431/,
     _V_NTLOS2_Threshold_Used/ */ V_NTLOS2_Threshold_Used;
  TE_Answer /* V_NTL_Overspeed_Detected/, _L302/ */ V_NTL_Overspeed_Detected;
  TE_Answer /* V_NG_Overspeed_Detected/, _L306/ */ V_NG_Overspeed_Detected;
  TE_Answer /* V_TriggTest_Overspeed_Detected/ */ V_TriggTest_Overspeed_Detected;
  /* ----------------------- local memories  ------------------------- */
  kcg_bool init;
  kcg_bool init1;
  kcg_float32 /* IfBlock1:then:_L38/,
     _V_NTLOS1_Measure/ */ _V_NTLOS1_Measure_partial;
  kcg_float32 /* IfBlock1:then:_L48/,
     _V_NTLOS2_Measure/ */ _V_NTLOS2_Measure_partial;
  kcg_float32 /* IfBlock1:then:_L36/,
     _V_NGOS2_Measure/ */ _V_NGOS2_Measure_partial;
  TE_Answer /* IfBlock1:then:_L43/,
     _V_NTLOS1_OutOfTime/ */ _V_NTLOS1_OutOfTime_partial;
  TE_Answer /* IfBlock1:then:_L53/,
     _V_NTLOS2_OutOfTime/ */ _V_NTLOS2_OutOfTime_partial;
  TE_Answer /* IfBlock1:then:_L29/,
     _V_NGOS2_OutOfTime/ */ _V_NGOS2_OutOfTime_partial;
  TE_Answer /* IfBlock1:then:_L61/,
     _V_NGOS1_OutOfTime/ */ _V_NGOS1_OutOfTime_partial;
  TE_Answer /* IfBlock1:then:_L32/,
     _V_NGOS2_OutOfHigh/ */ _V_NGOS2_OutOfHigh_partial;
  TE_Answer /* IfBlock1:then:_L24/,
     _V_NGOS1_OutOfHigh/ */ _V_NGOS1_OutOfHigh_partial;
  TE_Answer /* IfBlock1:then:_L52/,
     _V_NTLOS2_OutOfHigh/ */ _V_NTLOS2_OutOfHigh_partial;
  TE_Answer /* IfBlock1:then:_L44/,
     _V_NTLOS1_OutOfHigh/ */ _V_NTLOS1_OutOfHigh_partial;
  TE_Answer /* IfBlock1:then:_L28/,
     _V_NGOS1_Updated/ */ _V_NGOS1_Updated_partial;
  TE_Answer /* IfBlock1:then:_L33/,
     _V_NGOS2_Updated/ */ _V_NGOS2_Updated_partial;
  TE_Answer /* IfBlock1:then:_L40/,
     _V_NTLOS1_Updated/ */ _V_NTLOS1_Updated_partial;
  TE_Answer /* IfBlock1:then:_L51/,
     _V_NTLOS2_Updated/ */ _V_NTLOS2_Updated_partial;
  TE_Speed_Level /* IfBlock1:then:_L66/,
     _V_Engine_SpeedLevel/ */ _V_Engine_SpeedLevel_partial;
  kcg_float32 /* IfBlock1:else:_L51/,
     _V_Test_Speed_Measure/ */ _V_Test_Speed_Measure_partial;
  /* ---------------------  sub nodes' contexts  --------------------- */
  outC_ToComputeDOUTINHIB /* _L345=(ToComputeDOUTINHIB#1)/ */ Context_ToComputeDOUTINHIB_1;
  outC_ToComputeOSREARM /* _L358=(ToComputeOSREARM#1)/ */ Context_ToComputeOSREARM_1;
  outC_ToDetectNxOverspeed /* _L99=(ToDetectNxOverspeed#NG)/ */ Context_ToDetectNxOverspeed_NG;
  outC_ToDetectNxOverspeed /* _L98=(ToDetectNxOverspeed#NTL)/ */ Context_ToDetectNxOverspeed_NTL;
  outC_ToSelectNTLThreshold /* _L426=(ToSelectNTLThreshold#NTLOS2)/ */ Context_ToSelectNTLThreshold_NTLOS2;
  outC_ToSelectNTLThreshold /* _L423=(ToSelectNTLThreshold#NTLOS1)/ */ _2_Context_ToSelectNTLThreshold_NTLOS1;
  outC_ToComputeSpeed /* IfBlock1:then:_L3=(ToComputeSpeed#Test_Speed)/ */ Context_ToComputeSpeed_Test_Speed;
  outC_ToComputeSpeed /* IfBlock1:else:_L12=(ToComputeSpeed#NGOS1)/ */ Context_ToComputeSpeed_NGOS1;
  outC_ToComputeSpeed /* IfBlock1:else:_L26=(ToComputeSpeed#NGOS2)/ */ Context_ToComputeSpeed_NGOS2;
  outC_ToComputeSpeed /* IfBlock1:else:_L35=(ToComputeSpeed#NTLOS2)/ */ Context_ToComputeSpeed_NTLOS2;
  outC_ToComputeSpeed /* IfBlock1:else:_L41=(ToComputeSpeed#NTLOS1)/ */ Context_ToComputeSpeed_NTLOS1;
  /* ----------------- no clocks of observable data ------------------ */
} outC_ToDetectOverspeed;

/* ===========  node initialization and cycle functions  =========== */
/* ToDetectOverspeed/ */
extern void ToDetectOverspeed(
  inC_ToDetectOverspeed *inC,
  outC_ToDetectOverspeed *outC);

#ifndef KCG_NO_EXTERN_CALL_TO_RESET
extern void ToDetectOverspeed_reset(outC_ToDetectOverspeed *outC);
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

#ifndef KCG_USER_DEFINED_INIT
extern void ToDetectOverspeed_init(outC_ToDetectOverspeed *outC);
#endif /* KCG_USER_DEFINED_INIT */



#endif /* _ToDetectOverspeed_H_ */
/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** ToDetectOverspeed.h
** Generation date: 2022-11-16T17:38:35
*************************************************************$ */

