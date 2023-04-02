/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2021                                                                  */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_FNAND_SENDCID_H_
#define LIBBSP_FNAND_SENDCID_H_

#include "LIBBSP_FNAND_Globals.h"
#include "LIBBSP_FNAND_Configure.h"
#include "LIBBSP_FNAND_SendCommand.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
TE_LIBBSP_FNAND_ERROR_OP SendCID(uint32_t p_CID[C_FNAND_CID_BUFFER_SIZE]);

/*==== END =============================================================================*/

#endif /* LIBBSP_FNAND_SENDCID_H_ */
