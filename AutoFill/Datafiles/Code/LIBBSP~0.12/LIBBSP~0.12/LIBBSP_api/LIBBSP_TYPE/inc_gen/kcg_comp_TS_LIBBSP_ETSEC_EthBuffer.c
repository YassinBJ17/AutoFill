#include "kcg_types.h"

 kcg_bool kcg_comp_TS_LIBBSP_ETSEC_EthBuffer(   TS_LIBBSP_ETSEC_EthBuffer *kcg_c1,   TS_LIBBSP_ETSEC_EthBuffer *kcg_c2) {   kcg_bool kcg_equ;   kcg_size kcg_ci;   kcg_equ = kcg_true;   for (kcg_ci = 0; kcg_ci < 1518; kcg_ci++) {     kcg_equ = kcg_equ & ((*kcg_c1)[kcg_ci] == (*kcg_c2)[kcg_ci]);   }   return kcg_equ; }
