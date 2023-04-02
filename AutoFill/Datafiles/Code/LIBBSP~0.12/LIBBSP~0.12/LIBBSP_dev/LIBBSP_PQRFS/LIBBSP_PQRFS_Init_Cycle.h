/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/

#ifndef LIBBSP_PQRFS_INIT_CYCLE_H
#define LIBBSP_PQRFS_INIT_CYCLE_H

#include "LIBBSP_PQRFS_Globals.h"
#include "LIBBSP_PQRFS_Defines.h"
#include "LIBBSP_PQRFS_Anchor.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

TE_LIBBSP_PQRFS_Error LIBBSP_PQRFS_Init_Cycle( const uint32_t* const pa_cycle, const uint32_t v_nb_labels_cycle, const TE_LIBBSP_PQRFS_Cycle v_cycle );

#endif

/*==== END =============================================================================*/
