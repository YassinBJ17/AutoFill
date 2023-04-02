/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** Command: kcg66.exe -config P:/OVSP_SW/CSC_OVSP/.SCADE/KCG/config.txt
** Generation date: 2022-11-16T17:38:35
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "ToDetectOverspeed.h"

/* ToDetectOverspeed/ */
void ToDetectOverspeed(inC_ToDetectOverspeed *inC, outC_ToDetectOverspeed *outC)
{
  /* IfBlock1:else:_L35/, IfBlock1:else:_L59/, _V_NTLOS2_Measure/ */
  kcg_float32 _L35_else_IfBlock1;
  /* IfBlock1:else:_L41/, IfBlock1:else:_L57/, _V_NTLOS1_Measure/ */
  kcg_float32 _L41_else_IfBlock1;
  /* _L451/, _L528/, _L98/, _NTL_Overspeed_Detected/, _isStatusSent/ */
  kcg_bool _L98;
  /* _L452/, _L99/, _NG_Overspeed_Detected/ */
  kcg_bool _L99;
  /* IfBlock1:,
     _L473/,
     _L491/,
     _L493/,
     _L494/,
     _L529/,
     _isTriggeredTestEnabled/ */
  kcg_bool _L473;

  _L473 = inC->V_OVSP_SW_Mode == E_Mode_TriggTest;
  _L98 = inC->V_NG_NTL_Statuses_Sent == E_Yes;
  /* IfBlock1: */
  if (_L473) {
    /* IfBlock1:then:_L24=,
       IfBlock1:then:_L28=,
       IfBlock1:then:_L29=,
       IfBlock1:then:_L32=,
       IfBlock1:then:_L33=,
       IfBlock1:then:_L36=,
       IfBlock1:then:_L38=,
       IfBlock1:then:_L40=,
       IfBlock1:then:_L43=,
       IfBlock1:then:_L44=,
       IfBlock1:then:_L48=,
       IfBlock1:then:_L51=,
       IfBlock1:then:_L52=,
       IfBlock1:then:_L53=,
       IfBlock1:then:_L61=,
       IfBlock1:then:_L66= */
    if (outC->init) {
      outC->_V_Engine_SpeedLevel_partial = E_NCD_Speed;
      outC->_V_NGOS1_OutOfTime_partial = E_No;
      outC->_V_NTLOS2_OutOfTime_partial = E_No;
      outC->_V_NTLOS2_OutOfHigh_partial = E_No;
      outC->_V_NTLOS2_Updated_partial = E_No;
      outC->_V_NTLOS2_Measure_partial = kcg_lit_float32(0.0);
      outC->_V_NTLOS1_OutOfHigh_partial = E_No;
      outC->_V_NTLOS1_OutOfTime_partial = E_No;
      outC->_V_NTLOS1_Updated_partial = E_No;
      outC->_V_NTLOS1_Measure_partial = kcg_lit_float32(0.0);
      outC->_V_NGOS2_Measure_partial = kcg_lit_float32(0.0);
      outC->_V_NGOS2_Updated_partial = E_No;
      outC->_V_NGOS2_OutOfHigh_partial = E_No;
      outC->_V_NGOS2_OutOfTime_partial = E_No;
      outC->_V_NGOS1_Updated_partial = E_No;
      outC->_V_NGOS1_OutOfHigh_partial = E_No;
    }
    /* IfBlock1:then:_L3=(ToComputeSpeed#Test_Speed)/ */
    ToComputeSpeed(
      inC->V_Test_NbPeriods_Acquired,
      inC->V_Test_LastPeriod_Index,
      &inC->V_Test_Periods_Ar,
      inC->V_NGOS1_NbPeriods,
      inC->V_NGOS1_Timeout,
      _L98,
      &outC->Context_ToComputeSpeed_Test_Speed);
    outC->V_NTLOS1_Measure = outC->_V_NTLOS1_Measure_partial;
    outC->V_NTLOS2_Measure = outC->_V_NTLOS2_Measure_partial;
    outC->V_NGOS1_Measure =
      outC->Context_ToComputeSpeed_Test_Speed.NTLOS_NGOS_Measure;
    outC->V_NGOS2_Measure = outC->_V_NGOS2_Measure_partial;
    outC->V_NTLOS1_OutOfTime = outC->_V_NTLOS1_OutOfTime_partial;
    outC->V_NTLOS2_OutOfTime = outC->_V_NTLOS2_OutOfTime_partial;
    outC->V_NGOS2_OutOfTime = outC->_V_NGOS2_OutOfTime_partial;
    outC->V_NGOS1_OutOfTime = outC->_V_NGOS1_OutOfTime_partial;
    outC->V_NGOS2_OutOfHigh = outC->_V_NGOS2_OutOfHigh_partial;
    outC->V_NGOS1_OutOfHigh = outC->_V_NGOS1_OutOfHigh_partial;
    outC->V_NTLOS2_OutOfHigh = outC->_V_NTLOS2_OutOfHigh_partial;
    outC->V_NTLOS1_OutOfHigh = outC->_V_NTLOS1_OutOfHigh_partial;
    outC->V_NGOS1_Updated = outC->_V_NGOS1_Updated_partial;
    outC->V_NGOS2_Updated = outC->_V_NGOS2_Updated_partial;
    outC->V_NTLOS1_Updated = outC->_V_NTLOS1_Updated_partial;
    outC->V_NTLOS2_Updated = outC->_V_NTLOS2_Updated_partial;
    outC->V_Test_Speed_Measure =
      outC->Context_ToComputeSpeed_Test_Speed.NTLOS_NGOS_Measure;
  }
  else {
    /* IfBlock1:else:_L51= */
    if (outC->init1) {
      outC->_V_Test_Speed_Measure_partial = kcg_lit_float32(0.0);
    }
    /* IfBlock1:else:_L41=(ToComputeSpeed#NTLOS1)/ */
    ToComputeSpeed(
      inC->V_NTLOS1_NbPeriods_Acquired,
      inC->V_NTLOS1_LastPeriod_Index,
      &inC->V_NTLOS1_Periods_Ar,
      inC->V_NTLOS1_NbPeriods,
      inC->V_NTLOS1_Timeout,
      _L98,
      &outC->Context_ToComputeSpeed_NTLOS1);
    _L41_else_IfBlock1 = outC->Context_ToComputeSpeed_NTLOS1.NTLOS_NGOS_Measure;
    /* IfBlock1:else:_L35=(ToComputeSpeed#NTLOS2)/ */
    ToComputeSpeed(
      inC->V_NTLOS2_NbPeriods_Acquired,
      inC->V_NTLOS2_LastPeriod_Index,
      &inC->V_NTLOS2_Periods_Ar,
      inC->V_NTLOS2_NbPeriods,
      inC->V_NTLOS2_Timeout,
      _L98,
      &outC->Context_ToComputeSpeed_NTLOS2);
    _L35_else_IfBlock1 = outC->Context_ToComputeSpeed_NTLOS2.NTLOS_NGOS_Measure;
    /* IfBlock1:else:_L26=(ToComputeSpeed#NGOS2)/ */
    ToComputeSpeed(
      inC->V_NGOS2_NbPeriods_Acquired,
      inC->V_NGOS2_LastPeriod_Index,
      &inC->V_NGOS2_Periods_Ar,
      inC->V_NGOS2_NbPeriods,
      inC->V_NGOS2_Timeout,
      _L98,
      &outC->Context_ToComputeSpeed_NGOS2);
    /* IfBlock1:else:_L12=(ToComputeSpeed#NGOS1)/ */
    ToComputeSpeed(
      inC->V_NGOS1_NbPeriods_Acquired,
      inC->V_NGOS1_LastPeriod_Index,
      &inC->V_NGOS1_Periods_Ar,
      inC->V_NGOS1_NbPeriods,
      inC->V_NGOS1_Timeout,
      _L98,
      &outC->Context_ToComputeSpeed_NGOS1);
    outC->V_NTLOS1_Measure = _L41_else_IfBlock1;
    outC->V_NTLOS2_Measure = _L35_else_IfBlock1;
    outC->V_NGOS1_Measure = outC->Context_ToComputeSpeed_NGOS1.NTLOS_NGOS_Measure;
    outC->V_NGOS2_Measure = outC->Context_ToComputeSpeed_NGOS2.NTLOS_NGOS_Measure;
    outC->V_NTLOS1_OutOfTime = outC->Context_ToComputeSpeed_NTLOS1.OutOfTime;
    outC->V_NTLOS2_OutOfTime = outC->Context_ToComputeSpeed_NTLOS2.OutOfTime;
    outC->V_NGOS2_OutOfTime = outC->Context_ToComputeSpeed_NGOS2.OutOfTime;
    outC->V_NGOS1_OutOfTime = outC->Context_ToComputeSpeed_NGOS1.OutOfTime;
    outC->V_NGOS2_OutOfHigh = outC->Context_ToComputeSpeed_NGOS2.OutOfHigh;
    outC->V_NGOS1_OutOfHigh = outC->Context_ToComputeSpeed_NGOS1.OutOfHigh;
    outC->V_NTLOS2_OutOfHigh = outC->Context_ToComputeSpeed_NTLOS2.OutOfHigh;
    outC->V_NTLOS1_OutOfHigh = outC->Context_ToComputeSpeed_NTLOS1.OutOfHigh;
    outC->V_NGOS1_Updated = outC->Context_ToComputeSpeed_NGOS1.Updated;
    outC->V_NGOS2_Updated = outC->Context_ToComputeSpeed_NGOS2.Updated;
    outC->V_NTLOS1_Updated = outC->Context_ToComputeSpeed_NTLOS1.Updated;
    outC->V_NTLOS2_Updated = outC->Context_ToComputeSpeed_NTLOS2.Updated;
    outC->V_Test_Speed_Measure = outC->_V_Test_Speed_Measure_partial;
  }
  /* _L423=(ToSelectNTLThreshold#NTLOS1)/ */
  ToSelectNTLThreshold(
    &inC->V_NG_OVSTHRESD_Threshold_Ar,
    &inC->V_NTL_OVSVARIABLE_Threshold_Ar,
    inC->V_NTL_OVS_FUNCTION,
    inC->V_NTL_OVSTHRESD_Threshold,
    outC->V_NGOS1_Measure,
    outC->V_NGOS1_Updated,
    outC->V_NGOS1_OutOfTime,
    inC->V_NTL_OVSVARIABLE_Threshold_Ar[5],
    inC->V_NGOS1_100,
    &outC->_2_Context_ToSelectNTLThreshold_NTLOS1);
  outC->V_NTLOS1_Threshold_Used =
    outC->_2_Context_ToSelectNTLThreshold_NTLOS1.threshold;
  /* _L426=(ToSelectNTLThreshold#NTLOS2)/ */
  ToSelectNTLThreshold(
    &inC->V_NG_OVSTHRESD_Threshold_Ar,
    &inC->V_NTL_OVSVARIABLE_Threshold_Ar,
    inC->V_NTL_OVS_FUNCTION,
    inC->V_NTL_OVSTHRESD_Threshold,
    outC->V_NGOS2_Measure,
    outC->V_NGOS2_Updated,
    outC->V_NGOS2_OutOfTime,
    inC->V_NTL_OVSVARIABLE_Threshold_Ar[5],
    inC->V_NGOS2_100,
    &outC->Context_ToSelectNTLThreshold_NTLOS2);
  outC->V_NTLOS2_Threshold_Used =
    outC->Context_ToSelectNTLThreshold_NTLOS2.threshold;
  /* _L98=(ToDetectNxOverspeed#NTL)/ */
  ToDetectNxOverspeed(
    outC->V_NTLOS1_Measure,
    outC->V_NTLOS2_Measure,
    inC->V_NTL_OVSTHRESD_N,
    outC->V_NTLOS1_Threshold_Used,
    outC->V_NTLOS2_Threshold_Used,
    inC->V_NTL_OVSTHRESD_Window,
    inC->V_OVS_OneSensorNTLInhib,
    inC->V_NTL_OneSensor_CSSauthorization,
    inC->V_NTLOS1_100,
    inC->V_NTLOS2_100,
    &outC->Context_ToDetectNxOverspeed_NTL);
  _L98 = outC->Context_ToDetectNxOverspeed_NTL.NTL_NG_OVERSPEED;
  outC->V_NTLOS1_OVS_Conditions_Met =
    outC->Context_ToDetectNxOverspeed_NTL.V_NxxOS1_OVS_Conditions_Met;
  outC->V_NTLOS2_OVS_Conditions_Met =
    outC->Context_ToDetectNxOverspeed_NTL.V_NxxOS2_OVS_Conditions_Met;
  /* _L99=(ToDetectNxOverspeed#NG)/ */
  ToDetectNxOverspeed(
    outC->V_NGOS1_Measure,
    outC->V_NGOS2_Measure,
    inC->V_NG_OVSTHRESD_N,
    inC->V_NG_OVSTHRESD_Threshold,
    inC->V_NG_OVSTHRESD_Threshold,
    inC->V_NG_OVSTHRESD_Window,
    inC->V_OVS_OneSensorNGInhib,
    inC->V_NG_OneSensor_CSSauthorization,
    inC->V_NGOS1_100,
    inC->V_NGOS2_100,
    &outC->Context_ToDetectNxOverspeed_NG);
  _L99 = outC->Context_ToDetectNxOverspeed_NG.NTL_NG_OVERSPEED;
  outC->V_NGOS1_OVS_Conditions_Met =
    outC->Context_ToDetectNxOverspeed_NG.V_NxxOS1_OVS_Conditions_Met;
  outC->V_NGOS2_OVS_Conditions_Met =
    outC->Context_ToDetectNxOverspeed_NG.V_NxxOS2_OVS_Conditions_Met;
  /* IfBlock1: */
  if (_L473) {
    outC->V_Engine_SpeedLevel = outC->_V_Engine_SpeedLevel_partial;
    outC->init = kcg_false;
  }
  else {
    outC->V_Engine_SpeedLevel =
      /* IfBlock1:else:_L58=(ToComputeSpeedLevel#2)/ */
      ToComputeSpeedLevel(
        _L41_else_IfBlock1,
        _L35_else_IfBlock1,
        inC->V_NTLOS1_100,
        inC->V_NTLOS2_100,
        _L98,
        _L99);
    outC->init1 = kcg_false;
  }
  /* _L358=(ToComputeOSREARM#1)/ */
  ToComputeOSREARM(
    inC->V_OSREARM,
    inC->V_CAN_REARM_Request,
    _L473,
    outC->V_Engine_SpeedLevel,
    &outC->Context_ToComputeOSREARM_1);
  outC->V_REARM_Cmd = outC->Context_ToComputeOSREARM_1.V_REARM_Cmd;
  outC->V_OSARM_Cmd = /* _L354=(ToComputeOSARM#1)/ */
    ToComputeOSARM(
      inC->V_CAN_OSARM_Request,
      inC->V_CBIT_Result,
      inC->V_OVSP_Side_Id,
      inC->V_CAM_HS_Current,
      inC->V_CAM_LS_Current,
      outC->V_Engine_SpeedLevel,
      _L473);
  /* _L349=(ToComputeCamCmdx#1)/ */
  ToComputeCamCmdx(
    inC->V_CAN_CAM_Cmd1,
    inC->V_CAN_CAM_Cmd2,
    _L98,
    _L99,
    inC->V_DININHIB,
    inC->V_OVS_CSSInhib,
    inC->V_OVS_NGInhib,
    inC->V_OVS_NTLThresholdInhib,
    _L473,
    outC->V_NGOS1_OVS_Conditions_Met,
    &outC->V_CAM_Cmd1,
    &outC->V_CAM_Cmd2);
  /* _L345=(ToComputeDOUTINHIB#1)/ */
  ToComputeDOUTINHIB(
    outC->V_Engine_SpeedLevel,
    inC->V_CAN_CAM_Cmd1,
    inC->V_CAN_CAM_Cmd2,
    inC->V_OVS_CSSInhib,
    inC->V_Interlock_Inhib,
    outC->V_REARM_Cmd,
    _L473,
    outC->V_NGOS1_OVS_Conditions_Met,
    inC->V_DININHIB,
    &outC->Context_ToComputeDOUTINHIB_1);
  outC->V_DOUTINHIB = outC->Context_ToComputeDOUTINHIB_1.DOUTINHIB;
  /* _L306= */
  if (_L99) {
    outC->V_NG_Overspeed_Detected = E_Yes;
  }
  else {
    outC->V_NG_Overspeed_Detected = E_No;
  }
  /* _L302= */
  if (_L98) {
    outC->V_NTL_Overspeed_Detected = E_Yes;
  }
  else {
    outC->V_NTL_Overspeed_Detected = E_No;
  }
  outC->V_TriggTest_Overspeed_Detected = outC->V_NGOS1_OVS_Conditions_Met;
}

#ifndef KCG_USER_DEFINED_INIT
void ToDetectOverspeed_init(outC_ToDetectOverspeed *outC)
{
  outC->init = kcg_true;
  outC->init1 = kcg_true;
  outC->V_TriggTest_Overspeed_Detected = E_No;
  outC->V_NG_Overspeed_Detected = E_No;
  outC->V_NTL_Overspeed_Detected = E_No;
  outC->V_NTLOS2_Threshold_Used = kcg_lit_float32(0.0);
  outC->V_NTLOS1_Threshold_Used = kcg_lit_float32(0.0);
  outC->V_NTLOS2_OVS_Conditions_Met = E_No;
  outC->V_NTLOS1_OVS_Conditions_Met = E_No;
  outC->V_NGOS2_OVS_Conditions_Met = E_No;
  outC->V_NGOS1_OVS_Conditions_Met = E_No;
  outC->_V_Test_Speed_Measure_partial = kcg_lit_float32(0.0);
  outC->_V_Engine_SpeedLevel_partial = E_NCD_Speed;
  outC->_V_NTLOS2_Updated_partial = E_No;
  outC->_V_NTLOS1_Updated_partial = E_No;
  outC->_V_NGOS2_Updated_partial = E_No;
  outC->_V_NGOS1_Updated_partial = E_No;
  outC->_V_NTLOS1_OutOfHigh_partial = E_No;
  outC->_V_NTLOS2_OutOfHigh_partial = E_No;
  outC->_V_NGOS1_OutOfHigh_partial = E_No;
  outC->_V_NGOS2_OutOfHigh_partial = E_No;
  outC->_V_NGOS1_OutOfTime_partial = E_No;
  outC->_V_NGOS2_OutOfTime_partial = E_No;
  outC->_V_NTLOS2_OutOfTime_partial = E_No;
  outC->_V_NTLOS1_OutOfTime_partial = E_No;
  outC->_V_NGOS2_Measure_partial = kcg_lit_float32(0.0);
  outC->_V_NTLOS2_Measure_partial = kcg_lit_float32(0.0);
  outC->_V_NTLOS1_Measure_partial = kcg_lit_float32(0.0);
  outC->V_Test_Speed_Measure = kcg_lit_float32(0.0);
  outC->V_REARM_Cmd = E_Cmd_Off;
  outC->V_Engine_SpeedLevel = E_NCD_Speed;
  outC->V_NTLOS2_Updated = E_No;
  outC->V_NTLOS1_Updated = E_No;
  outC->V_NGOS2_Updated = E_No;
  outC->V_NGOS1_Updated = E_No;
  outC->V_NTLOS2_OutOfHigh = E_No;
  outC->V_NTLOS1_OutOfHigh = E_No;
  outC->V_NGOS2_OutOfHigh = E_No;
  outC->V_NGOS1_OutOfHigh = E_No;
  outC->V_NTLOS2_OutOfTime = E_No;
  outC->V_NTLOS1_OutOfTime = E_No;
  outC->V_NGOS2_OutOfTime = E_No;
  outC->V_NGOS1_OutOfTime = E_No;
  outC->V_NTLOS2_Measure = kcg_lit_float32(0.0);
  outC->V_NTLOS1_Measure = kcg_lit_float32(0.0);
  outC->V_NGOS2_Measure = kcg_lit_float32(0.0);
  outC->V_NGOS1_Measure = kcg_lit_float32(0.0);
  outC->V_OSARM_Cmd = E_Cmd_Off;
  outC->V_DOUTINHIB = E_Cmd_Off;
  outC->V_CAM_Cmd2 = E_Cmd_Off;
  outC->V_CAM_Cmd1 = E_Cmd_Off;
  /* _L345=(ToComputeDOUTINHIB#1)/ */
  ToComputeDOUTINHIB_init(&outC->Context_ToComputeDOUTINHIB_1);
  /* _L358=(ToComputeOSREARM#1)/ */
  ToComputeOSREARM_init(&outC->Context_ToComputeOSREARM_1);
  /* _L99=(ToDetectNxOverspeed#NG)/ */
  ToDetectNxOverspeed_init(&outC->Context_ToDetectNxOverspeed_NG);
  /* _L98=(ToDetectNxOverspeed#NTL)/ */
  ToDetectNxOverspeed_init(&outC->Context_ToDetectNxOverspeed_NTL);
  /* _L426=(ToSelectNTLThreshold#NTLOS2)/ */
  ToSelectNTLThreshold_init(&outC->Context_ToSelectNTLThreshold_NTLOS2);
  /* _L423=(ToSelectNTLThreshold#NTLOS1)/ */
  ToSelectNTLThreshold_init(&outC->_2_Context_ToSelectNTLThreshold_NTLOS1);
  /* IfBlock1:then:_L3=(ToComputeSpeed#Test_Speed)/ */
  ToComputeSpeed_init(&outC->Context_ToComputeSpeed_Test_Speed);
  /* IfBlock1:else:_L12=(ToComputeSpeed#NGOS1)/ */
  ToComputeSpeed_init(&outC->Context_ToComputeSpeed_NGOS1);
  /* IfBlock1:else:_L26=(ToComputeSpeed#NGOS2)/ */
  ToComputeSpeed_init(&outC->Context_ToComputeSpeed_NGOS2);
  /* IfBlock1:else:_L35=(ToComputeSpeed#NTLOS2)/ */
  ToComputeSpeed_init(&outC->Context_ToComputeSpeed_NTLOS2);
  /* IfBlock1:else:_L41=(ToComputeSpeed#NTLOS1)/ */
  ToComputeSpeed_init(&outC->Context_ToComputeSpeed_NTLOS1);
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void ToDetectOverspeed_reset(outC_ToDetectOverspeed *outC)
{
  outC->init = kcg_true;
  outC->init1 = kcg_true;
  /* _L345=(ToComputeDOUTINHIB#1)/ */
  ToComputeDOUTINHIB_reset(&outC->Context_ToComputeDOUTINHIB_1);
  /* _L358=(ToComputeOSREARM#1)/ */
  ToComputeOSREARM_reset(&outC->Context_ToComputeOSREARM_1);
  /* _L99=(ToDetectNxOverspeed#NG)/ */
  ToDetectNxOverspeed_reset(&outC->Context_ToDetectNxOverspeed_NG);
  /* _L98=(ToDetectNxOverspeed#NTL)/ */
  ToDetectNxOverspeed_reset(&outC->Context_ToDetectNxOverspeed_NTL);
  /* _L426=(ToSelectNTLThreshold#NTLOS2)/ */
  ToSelectNTLThreshold_reset(&outC->Context_ToSelectNTLThreshold_NTLOS2);
  /* _L423=(ToSelectNTLThreshold#NTLOS1)/ */
  ToSelectNTLThreshold_reset(&outC->_2_Context_ToSelectNTLThreshold_NTLOS1);
  /* IfBlock1:then:_L3=(ToComputeSpeed#Test_Speed)/ */
  ToComputeSpeed_reset(&outC->Context_ToComputeSpeed_Test_Speed);
  /* IfBlock1:else:_L12=(ToComputeSpeed#NGOS1)/ */
  ToComputeSpeed_reset(&outC->Context_ToComputeSpeed_NGOS1);
  /* IfBlock1:else:_L26=(ToComputeSpeed#NGOS2)/ */
  ToComputeSpeed_reset(&outC->Context_ToComputeSpeed_NGOS2);
  /* IfBlock1:else:_L35=(ToComputeSpeed#NTLOS2)/ */
  ToComputeSpeed_reset(&outC->Context_ToComputeSpeed_NTLOS2);
  /* IfBlock1:else:_L41=(ToComputeSpeed#NTLOS1)/ */
  ToComputeSpeed_reset(&outC->Context_ToComputeSpeed_NTLOS1);
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */



/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** ToDetectOverspeed.c
** Generation date: 2022-11-16T17:38:35
*************************************************************$ */

