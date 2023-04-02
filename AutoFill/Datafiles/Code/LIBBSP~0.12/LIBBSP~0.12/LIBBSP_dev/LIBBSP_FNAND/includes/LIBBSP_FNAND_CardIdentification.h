/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2021                                                                  */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_FNAND_CARDIDENT_H
#define LIBBSP_FNAND_CARDIDENT_H

#include "LIBBSP_FNAND_Globals.h"
#include "LIBBSP_FNAND_Configure.h"
#include "LIBBSP_FNAND_SendCommand.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
TE_LIBBSP_FNAND_INIT_CARD CardIdentification(void);

/*==== END =============================================================================*/
#endif /* LIBBSP_FNAND_CARDIDENT_H */
