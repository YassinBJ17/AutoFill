/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2021                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_FNAND_Globals.h"

/*==== Definitions =====================================================================*/

TU_LIBBSP_FNAND_STATUSCARD  V_LIBBSP_FNAND_StatusCard;
TU_LIBBSP_FNAND_STATUSCARD* P_LIBBSP_FNAND_StatusCard;

TS_LIBBSP_FNAND_OP  V_LIBBSP_FNAND_Op;
TS_LIBBSP_FNAND_OP* P_LIBBSP_FNAND_Op;

TS_LIBBSP_FNAND_STATUS  V_LIBBSP_FNAND_Status;
TS_LIBBSP_FNAND_STATUS* P_LIBBSP_FNAND_Status;

const uint32_t C_FNAND_MAX_TIME = 0xFFFFFFFFul;

volatile TS_LIBBSP_FNAND_HOST* const P_LIBBSP_FNAND_Host = (volatile TS_LIBBSP_FNAND_HOST*)(C_LIBBSP_CCSR_FNAND);
volatile TU_LIBBSP_FNAND_DCR* const P_LIBBSP_FNAND_FNAND_DCRReg = (volatile TU_LIBBSP_FNAND_DCR*)(C_LIBBSP_CCSR_FNAND + C_LIBBSP_FNAND_DCR_OFFSET);
volatile TS_LIBBSP_FNAND_GUTS_PMUXCR* const P_LIBBSP_FNAND_PMUXCRReg = (volatile TS_LIBBSP_FNAND_GUTS_PMUXCR*)(C_LIBBSP_CCSR_FNAND + C_LIBBSP_FNAND_GUTS_PMUXCR_OFFSET);


/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

/*==== END =============================================================================*/
