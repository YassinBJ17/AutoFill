/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2021                                                                  */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_FNAND_INITCARD_H
#define LIBBSP_FNAND_INITCARD_H

#include "LIBBSP_FNAND_Globals.h"
#include "LIBBSP_FNAND_CardIdentification.h"
#include "LIBBSP_FNAND_IsElapsed.h"
#include "LIBBSP_FNAND_ResetCard.h"
#include "LIBBSP_FNAND_SetBusConf.h"
#include "LIBBSP_FNAND_VoltageValidation.h"
#include "LIBBSP_FNAND_Wait.h"


/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
TE_LIBBSP_FNAND_INIT_CARD InitCard(void);

/*==== END =============================================================================*/
#endif /* LIBBSP_FNAND_INITCARD_H */
