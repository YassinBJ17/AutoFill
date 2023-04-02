/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2021                                                                  */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_FNAND_SETBLOCKSIZE_H_
#define LIBBSP_FNAND_SETBLOCKSIZE_H_

#include "LIBBSP_FNAND_Globals.h"
#include "LIBBSP_FNAND_SendCommand.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
TE_LIBBSP_FNAND_ERROR_OP SetBlockSize(const uint32_t v_BlockSize);

/*==== END =============================================================================*/

#endif /* LIBBSP_FNAND_SETBLOCKSIZE_H_ */
