/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** Command: kcg66.exe -config P:/OVSP_SW/CSC_OVSP/.SCADE/KCG/config.txt
** Generation date: 2022-11-16T17:38:35
*************************************************************$ */

#include "kcg_types.h"

#ifdef kcg_use_array_float32_6
kcg_bool kcg_comp_array_float32_6(
  array_float32_6 *kcg_c1,
  array_float32_6 *kcg_c2)
{
  kcg_bool kcg_equ;
  kcg_size kcg_ci;

  kcg_equ = kcg_true;
  for (kcg_ci = 0; kcg_ci < 6; kcg_ci++) {
    kcg_equ = kcg_equ & ((*kcg_c1)[kcg_ci] == (*kcg_c2)[kcg_ci]);
  }
  return kcg_equ;
}
#endif /* kcg_use_array_float32_6 */

#ifdef kcg_use_array_uint32_101
kcg_bool kcg_comp_array_uint32_101(
  array_uint32_101 *kcg_c1,
  array_uint32_101 *kcg_c2)
{
  kcg_bool kcg_equ;
  kcg_size kcg_ci;

  kcg_equ = kcg_true;
  for (kcg_ci = 0; kcg_ci < 101; kcg_ci++) {
    kcg_equ = kcg_equ & ((*kcg_c1)[kcg_ci] == (*kcg_c2)[kcg_ci]);
  }
  return kcg_equ;
}
#endif /* kcg_use_array_uint32_101 */

/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** kcg_types.c
** Generation date: 2022-11-16T17:38:35
*************************************************************$ */

