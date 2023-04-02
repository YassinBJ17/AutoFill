/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2021                                                                  */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_FNAND_WRITEMULTINODMA_H_
#define LIBBSP_FNAND_WRITEMULTINODMA_H_

#include "LIBBSP_FNAND_Globals.h"
#include "LIBBSP_FNAND_Configure.h"
#include "LIBBSP_FNAND_SendCommand.h"
#include "LIBBSP_FNAND_SetBlockCount.h"
#include "LIBBSP_FNAND_StopTransmission.h"
#include "LIBBSP_FNAND_Wait.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
TE_LIBBSP_FNAND_ERROR_OP Write_Multiblock_NoDMA(const uint32_t v_SectorAddr, const uint32_t* const p_Data, const uint32_t v_NbrBlocks);

/*==== END =============================================================================*/

#endif /* LIBBSP_FNAND_WRITEMULTINODMA_H_ */
