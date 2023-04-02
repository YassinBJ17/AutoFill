#include "kcg_types.h"

 kcg_bool kcg_comp_TS_LIBBSP_PQRFS_Status(   TS_LIBBSP_PQRFS_Status *kcg_c1,   TS_LIBBSP_PQRFS_Status *kcg_c2) {   kcg_bool kcg_equ;   kcg_equ = kcg_true;   kcg_equ = kcg_equ & (kcg_c1->status == kcg_c2->status);   kcg_equ = kcg_equ & kcg_comp_TS_LIBBSP_PQRFS_Status_data(       &kcg_c1->data,       &kcg_c2->data);   return kcg_equ; }
