/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2021                                                                  */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_FNAND_WRITEMULTI_H_
#define LIBBSP_FNAND_WRITEMULTI_H_

#include "LIBBSP_FNAND_Globals.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
TE_LIBBSP_FNAND_ERROR_OP Write_Multiblock(const uint32_t v_SectorAddr, const uint32_t* const p_Data, const uint32_t v_NbrBlocks);

/*==== END =============================================================================*/

#endif /* LIBBSP_FNAND_WRITEMULTI_H_ */
