/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_TMP_GetTimeMs.h"

/*==== Definitions =====================================================================*/


/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

void LIBBSP_TMP_GetTimeMs(uint32_t * const v_Time)
{
   uint32_t v_current_tmp;
   uint64_t v_dif;
   float64_t V_LIBBSP_TMP_tmp_cnt_float;
   float64_t v_Time_float;
   
   /* recup�ration du cnt courant*/
   v_current_tmp = V_TMPRegs->reg_tmp_cnt;
   
   /* ajout de la diff�rence*/
   if ( v_current_tmp >= V_LIBBSP_TMP_last_tmp_cnt )
   {
      v_dif = (uint64_t)v_current_tmp - (uint64_t)V_LIBBSP_TMP_last_tmp_cnt;
   }
   else
   {
      /* C_TMP_ROLL_OVER = ((max uint32_t) + 1) and V_last_tmp_cnt is an uint32_t so the difference is always positive */
      v_dif = (uint64_t)C_TMP_ROLL_OVER;
      v_dif -= (uint64_t)V_LIBBSP_TMP_last_tmp_cnt;
      v_dif += (uint64_t)v_current_tmp;
   }
   
   V_LIBBSP_TMP_last_tmp_cnt = v_current_tmp;
   
   V_LIBBSP_TMP_tmp_cnt += v_dif;
   
   V_LIBBSP_TMP_tmp_cnt_float = LIBBSP_MATH_ConvertUInt64ToFloat64(V_LIBBSP_TMP_tmp_cnt);
   v_Time_float = V_LIBBSP_TMP_tmp_cnt_float * (float64_t)C_TMP_RESOLUTION;
   *v_Time = (uint32_t) v_Time_float; /* %RELAX<SYNCHRONe_C_Code_10.7> This loss of precision is wanted, to get the time in ms */
}

/*==== END =============================================================================*/
