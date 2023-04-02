/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/

#ifndef LIBBSP_PQRFS_WRITE_H
#define LIBBSP_PQRFS_WRITE_H

#include "LIBBSP_PQRFS_Globals.h"
#include "LIBBSP_PQRFS_Defines.h"
#include "LIBBSP_PQRFS_Anchor.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

TE_LIBBSP_PQRFS_Error LIBBSP_PQRFS_WriteUserLabels(  const uint32_t* const p_buffer, const uint32_t v_buffer_size, const uint32_t v_buffer_size_1_or_3, const TE_LIBBSP_PQRFS_1ST_OR_3RD_CYCLE v_1st_5ms, const uint32_t v_failure);

#endif

/*==== END =============================================================================*/
