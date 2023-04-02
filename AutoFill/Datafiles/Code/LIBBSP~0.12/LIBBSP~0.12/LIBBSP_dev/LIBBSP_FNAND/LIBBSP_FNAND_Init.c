/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2021                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_FNAND_Init.h"

/*==== Definitions =====================================================================*/


/*==== Variables =======================================================================*/
extern TU_LIBBSP_FNAND_STATUSCARD  V_LIBBSP_FNAND_StatusCard;
extern TU_LIBBSP_FNAND_STATUSCARD* P_LIBBSP_FNAND_StatusCard;

extern TS_LIBBSP_FNAND_OP  V_LIBBSP_FNAND_Op;
//extern TS_LIBBSP_FNAND_OP* P_LIBBSP_FNAND_Op;

extern TS_LIBBSP_FNAND_STATUS  V_LIBBSP_FNAND_Status;
//extern TS_LIBBSP_FNAND_STATUS* P_LIBBSP_FNAND_Status;

/*==== Services ========================================================================*/

/* Public function
 * Initialization of the addresses for the eSDHC controller.
 * Parameters : v_Address -> CCSR eSDHC address
 * Return : TE_LIBBSP_FNAND_INIT
 */
void LIBBSP_FNAND_Init(void)
{
   /* {{RELAX<SYNCHRONe_C_Code_10.7> No precision lost: same type */
   P_LIBBSP_FNAND_StatusCard = &V_LIBBSP_FNAND_StatusCard;
   P_LIBBSP_FNAND_Op = &V_LIBBSP_FNAND_Op;
   P_LIBBSP_FNAND_Status = &V_LIBBSP_FNAND_Status;
   /* }} RELAX<SYNCHRONe_C_Code_10.7> */
}

/*==== END =============================================================================*/
