/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_TMP_GLOBALS_H
#define LIBBSP_TMP_GLOBALS_H

#include "LIBBSP_TMP.h"
#include "LIBBSP_MEGREG.h"
#include "LIBBSP_MATH.h"


/*==== Definitions =====================================================================*/
/* the duration is computed in ms */
#define C_TMP_RESOLUTION (25.0e-3)

/* 0x100000000LL = 2^32 = 4294967296 */
#define C_TMP_ROLL_OVER (4294967296)
/*==== Variables =======================================================================*/

extern uint32_t V_LIBBSP_TMP_tmp1;
extern uint32_t V_LIBBSP_TMP_tmp2;
extern uint32_t V_LIBBSP_TMP_tmp3;

extern uint64_t V_LIBBSP_TMP_tmp_cnt;
extern uint32_t V_LIBBSP_TMP_last_tmp_cnt;


/*==== Services ========================================================================*/

/*==== END =============================================================================*/
#endif
