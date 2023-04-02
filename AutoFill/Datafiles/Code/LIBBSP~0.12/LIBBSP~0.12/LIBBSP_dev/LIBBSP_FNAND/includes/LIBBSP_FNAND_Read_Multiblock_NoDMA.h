/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2021                                                                  */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_FNAND_READMULTINODMA_H_
#define LIBBSP_FNAND_READMULTINODMA_H_

#include "LIBBSP_FNAND_Globals.h"
#include "LIBBSP_FNAND_IsElapsed.h"
#include "LIBBSP_FNAND_SetBlockSize.h"
#include "LIBBSP_FNAND_SendCommand.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
TE_LIBBSP_FNAND_ERROR_OP Read_Multiblock_NoDMA(const uint32_t v_SectorAddr, uint32_t* const p_Data, const uint32_t v_NbrBlocks);

/*==== END =============================================================================*/

#endif /* LIBBSP_FNAND_READMULTINODMA_H_ */
