#include "kcg_types.h"

 kcg_bool kcg_comp_TS_LIBBSP_PQRFS_Status_data(   TS_LIBBSP_PQRFS_Status_data *kcg_c1,   TS_LIBBSP_PQRFS_Status_data *kcg_c2) {   kcg_bool kcg_equ;   kcg_equ = kcg_true;   kcg_equ = kcg_equ & (kcg_c1->label_err_1 == kcg_c2->label_err_1);   kcg_equ = kcg_equ & (kcg_c1->label_err_2 == kcg_c2->label_err_2);   kcg_equ = kcg_equ & (kcg_c1->label_err_3 == kcg_c2->label_err_3);   kcg_equ = kcg_equ & (kcg_c1->label_err_4 == kcg_c2->label_err_4);   kcg_equ = kcg_equ & (kcg_c1->label_err_5 == kcg_c2->label_err_5);   kcg_equ = kcg_equ & (kcg_c1->label_err_6 == kcg_c2->label_err_6);   kcg_equ = kcg_equ & (kcg_c1->label_err_7 == kcg_c2->label_err_7);   kcg_equ = kcg_equ & (kcg_c1->label_err_8 == kcg_c2->label_err_8);   kcg_equ = kcg_equ & (kcg_c1->label_err_9 == kcg_c2->label_err_9);   kcg_equ = kcg_equ & (kcg_c1->label_err_10 == kcg_c2->label_err_10);   kcg_equ = kcg_equ & (kcg_c1->label_err_11 == kcg_c2->label_err_11);   kcg_equ = kcg_equ & (kcg_c1->label_err_12 == kcg_c2->label_err_12);   kcg_equ = kcg_equ & (kcg_c1->label_err_13 == kcg_c2->label_err_13);   return kcg_equ; }
