/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2021                                                                  */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_FNAND_RESETCARD_H
#define LIBBSP_FNAND_RESETCARD_H

#include "LIBBSP_FNAND_Globals.h"
#include "LIBBSP_FNAND_Wait.h"
#include "LIBBSP_FNAND_SendCommand.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
TE_LIBBSP_FNAND_INIT_CARD ResetCard(void);

/*==== END =============================================================================*/
#endif /* LIBBSP_FNAND_RESETCARD_H */
