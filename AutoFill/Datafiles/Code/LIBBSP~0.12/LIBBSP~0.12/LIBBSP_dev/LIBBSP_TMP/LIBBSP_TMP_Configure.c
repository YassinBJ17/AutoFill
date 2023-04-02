/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_TMP_Configure.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/


/*==== Services ========================================================================*/

TE_LIBBSP_TMP_AddrStatus LIBBSP_TMP_Configure( void )
{
   /* initialisation du compteur pour avoir une fonction donnant le temps depuis le démarrage de la centrale */
   V_LIBBSP_TMP_tmp_cnt = (uint64_t)(V_TMPRegs->reg_tmp_cnt);
   V_LIBBSP_TMP_last_tmp_cnt = V_TMPRegs->reg_tmp_cnt;
   
   V_LIBBSP_TMP_tmp1 = V_TMPRegs->reg_tmp_1;
   V_LIBBSP_TMP_tmp2 = V_TMPRegs->reg_tmp_2;
   V_LIBBSP_TMP_tmp3 = V_TMPRegs->reg_tmp_3;

   return (E_LIBBSP_TMP_VALID_ADDR); /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
}

/*==== END =============================================================================*/
