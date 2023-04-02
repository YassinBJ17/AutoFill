/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_PQRFS_Deactivate_Line_H
#define LIBBSP_PQRFS_Deactivate_Line_H

#include "LIBBSP_PQRFS_Globals.h"
#include "LIBBSP_PQRFS_Defines.h"
#include "LIBBSP_PQRFS_Anchor.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

TE_LIBBSP_PQRFS_Error LIBBSP_PQRFS_Deactivate_Line( const TE_LIBBSP_PQRFS_Line v_line, const boolean_t v_stop);

/*==== END =============================================================================*/
#endif
