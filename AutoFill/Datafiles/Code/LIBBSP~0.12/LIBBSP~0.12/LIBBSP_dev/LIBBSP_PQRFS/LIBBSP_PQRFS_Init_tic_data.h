/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/

#ifndef LIBBSP_PQRFS_INIT_LABEL_H
#define LIBBSP_PQRFS_INIT_LABEL_H

#include "LIBBSP_PQRFS_Globals.h"
#include "LIBBSP_PQRFS_Defines.h"
#include "LIBBSP_PQRFS_Anchor.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

TE_LIBBSP_PQRFS_Error LIBBSP_PQRFS_Init_tic_data(const uint32_t * const p_buffer, const uint32_t v_size);

#endif

/*==== END =============================================================================*/
