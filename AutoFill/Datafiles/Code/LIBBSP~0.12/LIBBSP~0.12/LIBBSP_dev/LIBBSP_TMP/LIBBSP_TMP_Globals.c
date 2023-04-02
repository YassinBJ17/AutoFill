/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_TMP_Globals.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/
volatile TS_LIBBSP_TMP_Registers * const V_TMPRegs = (volatile TS_LIBBSP_TMP_Registers * const) C_LIBBSP_MEGREG_TMP; /* %RELAX<SYNCHRONe_C_Code_10.7> No precision lost: adress */


uint32_t V_LIBBSP_TMP_tmp1;
uint32_t V_LIBBSP_TMP_tmp2;
uint32_t V_LIBBSP_TMP_tmp3;

uint64_t V_LIBBSP_TMP_tmp_cnt;
uint32_t V_LIBBSP_TMP_last_tmp_cnt;

/*==== END =============================================================================*/
