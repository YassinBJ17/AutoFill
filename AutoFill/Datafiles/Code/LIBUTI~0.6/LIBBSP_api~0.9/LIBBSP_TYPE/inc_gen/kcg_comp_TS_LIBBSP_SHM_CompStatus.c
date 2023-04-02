#include "kcg_types.h"

 kcg_bool kcg_comp_TS_LIBBSP_SHM_CompStatus(   TS_LIBBSP_SHM_CompStatus *kcg_c1,   TS_LIBBSP_SHM_CompStatus *kcg_c2) {   kcg_bool kcg_equ;   kcg_equ = kcg_true;   kcg_equ = kcg_equ & (kcg_c1->critical_uvd_cnt == kcg_c2->critical_uvd_cnt);   kcg_equ = kcg_equ & (kcg_c1->hw_reset_request_cnt ==       kcg_c2->hw_reset_request_cnt);   kcg_equ = kcg_equ & (kcg_c1->sw_reset_request_cnt ==       kcg_c2->sw_reset_request_cnt);   kcg_equ = kcg_equ & (kcg_c1->wd_failure_cnt == kcg_c2->wd_failure_cnt);   return kcg_equ; }
