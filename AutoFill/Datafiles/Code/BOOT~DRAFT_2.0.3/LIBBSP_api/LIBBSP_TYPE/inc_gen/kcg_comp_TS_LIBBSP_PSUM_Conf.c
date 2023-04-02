#include "kcg_types.h"

 kcg_bool kcg_comp_TS_LIBBSP_PSUM_Conf(   TS_LIBBSP_PSUM_Conf *kcg_c1,   TS_LIBBSP_PSUM_Conf *kcg_c2) {   kcg_bool kcg_equ;   kcg_equ = kcg_true;   kcg_equ = kcg_equ & (kcg_c1->v_data == kcg_c2->v_data);   kcg_equ = kcg_equ & (kcg_c1->v_address == kcg_c2->v_address);   return kcg_equ; }
