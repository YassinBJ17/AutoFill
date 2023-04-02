#include "kcg_types.h"

 kcg_bool kcg_comp_TS_LIBBSP_ETR_ReadInfos(   TS_LIBBSP_ETR_ReadInfos *kcg_c1,   TS_LIBBSP_ETR_ReadInfos *kcg_c2) {   kcg_bool kcg_equ;   kcg_equ = kcg_true;   kcg_equ = kcg_equ & (kcg_c1->v_EventCountdata == kcg_c2->v_EventCountdata);   kcg_equ = kcg_equ & (kcg_c1->v_ETregdata == kcg_c2->v_ETregdata);   kcg_equ = kcg_equ & (kcg_c1->v_AlarmRegdata == kcg_c2->v_AlarmRegdata);   return kcg_equ; }
