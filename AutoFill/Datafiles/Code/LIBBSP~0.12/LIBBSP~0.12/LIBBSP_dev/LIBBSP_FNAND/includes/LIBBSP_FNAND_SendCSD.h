/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2021                                                                  */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_FNAND_SENDCSD_H_
#define LIBBSP_FNAND_SENDCSD_H_

#include "LIBBSP_FNAND_Globals.h"
#include "LIBBSP_FNAND_SendCommand.h"
/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
TE_LIBBSP_FNAND_ERROR_OP SendCSD(uint32_t p_CSD[C_FNAND_CSD_BUFFER_SIZE]);

/*==== END =============================================================================*/

#endif /* LIBBSP_FNAND_SENDCSD_H_ */
