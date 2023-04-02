/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2021                                                                  */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_FNAND_WRITESINGLE_H_
#define LIBBSP_FNAND_WRITESINGLE_H_

#include "LIBBSP_FNAND_Globals.h"
#include "LIBBSP_FNAND_Configure.h"
#include "LIBBSP_FNAND_SendCommand.h"
#include "LIBBSP_FNAND_SetBlockSize.h"


/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
TE_LIBBSP_FNAND_ERROR_OP Write_Singleblock(const uint32_t v_SectorAddr, const uint32_t* const p_Data);

/*==== END =============================================================================*/

#endif /* LIBBSP_FNAND_WRITE_H_ */
