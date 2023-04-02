/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/

#ifndef LIBBSP_PQRFS_STATUS_H
#define LIBBSP_PQRFS_STATUS_H

#include "LIBBSP_PQRFS_Globals.h"
#include "LIBBSP_PQRFS_Defines.h"
#include "LIBBSP_PQRFS_Anchor.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

TE_LIBBSP_PQRFS_Error LIBBSP_PQRFS_GetStatus( TS_LIBBSP_PQRFS_Status * const p_status_1_or_3,TS_LIBBSP_PQRFS_Status * const p_status_2_or_4 , const boolean_t v_1st_5ms );

#endif

/*==== END =============================================================================*/
