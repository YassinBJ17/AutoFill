#include "kcg_types.h"

 kcg_bool kcg_comp_TS_LIBBSP_ETSEC_ConfHostMac(   TS_LIBBSP_ETSEC_ConfHostMac *kcg_c1,   TS_LIBBSP_ETSEC_ConfHostMac *kcg_c2) {   kcg_bool kcg_equ;   kcg_equ = kcg_true;   kcg_equ = kcg_equ & kcg_comp_TS_LIBBSP_ETSEC_MacAddr(       &kcg_c1->mac_addr,       &kcg_c2->mac_addr);   return kcg_equ; }
