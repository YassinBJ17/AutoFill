/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2021                                                                  */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_FNAND_SETBUSCONF_H
#define LIBBSP_FNAND_SETBUSCONF_H

#include "LIBBSP_FNAND_Globals.h"
#include "LIBBSP_FNAND_IsElapsed.h"
#include "LIBBSP_FNAND_SelectCard.h"
#include "LIBBSP_FNAND_SendCSD.h"
#include "LIBBSP_FNAND_Wait.h"
/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
TE_LIBBSP_FNAND_INIT_CARD SetBusConf(void);

/*==== END =============================================================================*/
#endif /* LIBBSP_FNAND_SETBUSCONF_H */
