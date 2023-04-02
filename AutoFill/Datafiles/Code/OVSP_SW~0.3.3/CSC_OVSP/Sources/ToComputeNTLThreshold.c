/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** Command: kcg66.exe -config P:/OVSP_SW/CSC_OVSP/.SCADE/KCG/config.txt
** Generation date: 2022-11-16T17:38:35
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "ToComputeNTLThreshold.h"

/* ToComputeNTLThreshold/ */
kcg_float32 ToComputeNTLThreshold(
  /* NG_OVSTHRESD_Threshold/, _L4/ */
  array_float32_6 *NG_OVSTHRESD_Threshold,
  /* NTL_OVSVARIABLE_Threshold/, _L6/ */
  array_float32_6 *NTL_OVSVARIABLE_Threshold,
  /* NGx/, _L1/, _x/ */
  kcg_float32 NGx)
{
  /* IfBlock1:then:IfBlock2:, IfBlock1:then:_L1/, IfBlock1:then:sel1/ */
  kcg_bool _L1_then_IfBlock1;
  /* IfBlock1:then:IfBlock2:else:IfBlock3:else:IfBlock4:,
     IfBlock1:then:IfBlock2:else:IfBlock3:else:_L3/,
     IfBlock1:then:IfBlock2:else:IfBlock3:else:sel3/ */
  kcg_bool IfBlock4_clock_else_IfBlock3_else_IfBlock2_then_IfBlock1;
  /* IfBlock1:then:IfBlock2:else:IfBlock3:else:IfBlock4:else:IfBlock5:else:IfBlock6:,
     IfBlock1:then:IfBlock2:else:IfBlock3:else:IfBlock4:else:IfBlock5:else:_L1/,
     IfBlock1:then:IfBlock2:else:IfBlock3:else:IfBlock4:else:IfBlock5:else:sel5/ */
  kcg_bool IfBlock6_clock_else_IfBlock5_else_IfBlock4_else_IfBlock3_else_IfBlock2_then_IfBlock1;
  /* IfBlock1:then:IfBlock2:else:IfBlock3:else:IfBlock4:else:IfBlock5:,
     IfBlock1:then:IfBlock2:else:IfBlock3:else:IfBlock4:else:_L1/,
     IfBlock1:then:IfBlock2:else:IfBlock3:else:IfBlock4:else:sel4/ */
  kcg_bool _L1_else_IfBlock4_else_IfBlock3_else_IfBlock2_then_IfBlock1;
  /* IfBlock1:then:IfBlock2:else:IfBlock3:,
     IfBlock1:then:IfBlock2:else:_L1/,
     IfBlock1:then:IfBlock2:else:sel2/ */
  kcg_bool _L1_else_IfBlock2_then_IfBlock1;
  /* IfBlock1: */
  kcg_bool IfBlock1_clock;
  /* threshold/ */
  kcg_float32 threshold;

  IfBlock1_clock = NGx >= (*NG_OVSTHRESD_Threshold)[0];
  /* IfBlock1: */
  if (IfBlock1_clock) {
    _L1_then_IfBlock1 = /* IfBlock1:then:_L1=(ToSelectInterpolation#6)/ */
      ToSelectInterpolation(
        (*NG_OVSTHRESD_Threshold)[0],
        (*NG_OVSTHRESD_Threshold)[1],
        NGx);
    /* IfBlock1:then:IfBlock2: */
    if (_L1_then_IfBlock1) {
      threshold = /* IfBlock1:then:IfBlock2:then:_L6=(ToInterpolate#3)/ */
        ToInterpolate(
          (*NG_OVSTHRESD_Threshold)[0],
          (*NG_OVSTHRESD_Threshold)[1],
          (*NTL_OVSVARIABLE_Threshold)[0],
          (*NTL_OVSVARIABLE_Threshold)[1],
          NGx);
    }
    else {
      _L1_else_IfBlock2_then_IfBlock1 =
        /* IfBlock1:then:IfBlock2:else:_L1=(ToSelectInterpolation#9)/ */
        ToSelectInterpolation(
          (*NG_OVSTHRESD_Threshold)[1],
          (*NG_OVSTHRESD_Threshold)[2],
          NGx);
      /* IfBlock1:then:IfBlock2:else:IfBlock3: */
      if (_L1_else_IfBlock2_then_IfBlock1) {
        threshold =
          /* IfBlock1:then:IfBlock2:else:IfBlock3:then:_L1=(ToInterpolate#6)/ */
          ToInterpolate(
            (*NG_OVSTHRESD_Threshold)[1],
            (*NG_OVSTHRESD_Threshold)[2],
            (*NTL_OVSVARIABLE_Threshold)[1],
            (*NTL_OVSVARIABLE_Threshold)[2],
            NGx);
      }
      else {
        IfBlock4_clock_else_IfBlock3_else_IfBlock2_then_IfBlock1 =
          /* IfBlock1:then:IfBlock2:else:IfBlock3:else:_L3=(ToSelectInterpolation#11)/ */
          ToSelectInterpolation(
            (*NG_OVSTHRESD_Threshold)[2],
            (*NG_OVSTHRESD_Threshold)[3],
            NGx);
        /* IfBlock1:then:IfBlock2:else:IfBlock3:else:IfBlock4: */
        if (IfBlock4_clock_else_IfBlock3_else_IfBlock2_then_IfBlock1) {
          threshold =
            /* IfBlock1:then:IfBlock2:else:IfBlock3:else:IfBlock4:then:_L1=(ToInterpolate#8)/ */
            ToInterpolate(
              (*NG_OVSTHRESD_Threshold)[2],
              (*NG_OVSTHRESD_Threshold)[3],
              (*NTL_OVSVARIABLE_Threshold)[2],
              (*NTL_OVSVARIABLE_Threshold)[3],
              NGx);
        }
        else {
          _L1_else_IfBlock4_else_IfBlock3_else_IfBlock2_then_IfBlock1 =
            /* IfBlock1:then:IfBlock2:else:IfBlock3:else:IfBlock4:else:_L1=(ToSelectInterpolation#13)/ */
            ToSelectInterpolation(
              (*NG_OVSTHRESD_Threshold)[3],
              (*NG_OVSTHRESD_Threshold)[4],
              NGx);
          /* IfBlock1:then:IfBlock2:else:IfBlock3:else:IfBlock4:else:IfBlock5: */
          if (_L1_else_IfBlock4_else_IfBlock3_else_IfBlock2_then_IfBlock1) {
            threshold =
              /* IfBlock1:then:IfBlock2:else:IfBlock3:else:IfBlock4:else:IfBlock5:then:_L6=(ToInterpolate#10)/ */
              ToInterpolate(
                (*NG_OVSTHRESD_Threshold)[3],
                (*NG_OVSTHRESD_Threshold)[4],
                (*NTL_OVSVARIABLE_Threshold)[3],
                (*NTL_OVSVARIABLE_Threshold)[4],
                NGx);
          }
          else {
            IfBlock6_clock_else_IfBlock5_else_IfBlock4_else_IfBlock3_else_IfBlock2_then_IfBlock1 =
              /* IfBlock1:then:IfBlock2:else:IfBlock3:else:IfBlock4:else:IfBlock5:else:_L1=(ToSelectInterpolation#14)/ */
              ToSelectInterpolation(
                (*NG_OVSTHRESD_Threshold)[4],
                (*NG_OVSTHRESD_Threshold)[5],
                NGx);
            /* IfBlock1:then:IfBlock2:else:IfBlock3:else:IfBlock4:else:IfBlock5:else:IfBlock6: */
            if (IfBlock6_clock_else_IfBlock5_else_IfBlock4_else_IfBlock3_else_IfBlock2_then_IfBlock1) {
              threshold =
                /* IfBlock1:then:IfBlock2:else:IfBlock3:else:IfBlock4:else:IfBlock5:else:IfBlock6:then:_L1=(ToInterpolate#11)/ */
                ToInterpolate(
                  (*NG_OVSTHRESD_Threshold)[4],
                  (*NG_OVSTHRESD_Threshold)[5],
                  (*NTL_OVSVARIABLE_Threshold)[4],
                  (*NTL_OVSVARIABLE_Threshold)[5],
                  NGx);
            }
            else {
              threshold = (*NTL_OVSVARIABLE_Threshold)[5];
            }
          }
        }
      }
    }
  }
  else {
    threshold = (*NTL_OVSVARIABLE_Threshold)[0];
  }
  return threshold;
}



/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** ToComputeNTLThreshold.c
** Generation date: 2022-11-16T17:38:35
*************************************************************$ */

