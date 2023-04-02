#include "kcg_types.h"

 kcg_bool kcg_comp_TA_LIBBSP_UART_RxBuffer(   TA_LIBBSP_UART_RxBuffer *kcg_c1,   TA_LIBBSP_UART_RxBuffer *kcg_c2) {   kcg_bool kcg_equ;   kcg_size kcg_ci;   kcg_equ = kcg_true;   for (kcg_ci = 0; kcg_ci < 2048; kcg_ci++) {     kcg_equ = kcg_equ & ((*kcg_c1)[kcg_ci] == (*kcg_c2)[kcg_ci]);   }   return kcg_equ; }
