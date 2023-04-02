/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2021                                                                  */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_FNAND_WRITESINGLENODMA_H_
#define LIBBSP_FNAND_WRITESINGLENODMA_H_

#include "LIBBSP_FNAND_Globals.h"
#include "LIBBSP_FNAND_SetBlockSize.h"
#include "LIBBSP_FNAND_StopTransmission.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
TE_LIBBSP_FNAND_ERROR_OP Write_Singleblock_NoDMA(const uint32_t v_SectorAddr, const uint32_t* const p_Data);

/*==== END =============================================================================*/

#endif /* LIBBSP_FNAND_WRITESINGLENODMA_H_ */
