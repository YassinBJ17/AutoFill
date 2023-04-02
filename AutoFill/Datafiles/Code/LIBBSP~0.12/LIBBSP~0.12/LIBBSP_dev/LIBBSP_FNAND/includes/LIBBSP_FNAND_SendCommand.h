/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2021                                                                  */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_FNAND_SENDCOMMAND_H
#define LIBBSP_FNAND_SENDCOMMAND_H

#include "LIBBSP_FNAND_Globals.h"
#include "LIBBSP_FNAND_GetResponse.h"
#include "LIBBSP_FNAND_IsElapsed.h"

/*==== Definitions =====================================================================*/


/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
TE_LIBBSP_FNAND_ERROR_OP SendCommand(const TS_LIBBSP_FNAND_CMD *v_Cmd, const TE_LIBBSP_FNAND_RSP_TYPE v_RspType, const uint32_t v_Timeout);

/*==== END =============================================================================*/
#endif /* LIBBSP_FNAND_SENDCOMMAND_H */
