/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_TMP_GetTMP.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

void LIBBSP_TMP_GetTMP( const TE_LIBBSP_TMP_Number v_tmp, boolean_t * const pa_new, uint32_t * const pa_value)
{
   uint32_t v_cnt;
   *pa_new = FALSE;
   
   /* verification que l'argument du n� de TMP est correct */
   switch ( v_tmp )
   {
      case E_LIBBSP_TMP_TMP1:
         /* cas tmp 1 */
         /* recuperation du tmp */
         v_cnt = V_TMPRegs->reg_tmp_1;
         /* verification si le compteur de tmp a chang� depuis le dernier appel */
         if ( v_cnt != V_LIBBSP_TMP_tmp1 )
         {
            /* nouveau tmp re�u */
            *pa_new = TRUE;
         }
         /* recup�ration de la valeur du tmp */
         *pa_value = v_cnt;
         /* m�morisation pour le prochain coup */
         V_LIBBSP_TMP_tmp1 = v_cnt;
         break;
      case E_LIBBSP_TMP_TMP2:
         /* idem tmp 2 */
         v_cnt = V_TMPRegs->reg_tmp_2;
         if ( v_cnt != V_LIBBSP_TMP_tmp2 )
         {
            *pa_new = TRUE;
         }
         *pa_value = v_cnt;
         V_LIBBSP_TMP_tmp2 = v_cnt;
         break;
      case E_LIBBSP_TMP_TMP3:
         /* idem tmp 3 */
         v_cnt = V_TMPRegs->reg_tmp_3;
         if ( v_cnt != V_LIBBSP_TMP_tmp3 )
         {
            *pa_new = TRUE;
         }
         *pa_value = v_cnt;
         V_LIBBSP_TMP_tmp3 = v_cnt;
         break;
      default:
         *pa_value = 0ul;
         break;
   }
}

/*==== END =============================================================================*/
