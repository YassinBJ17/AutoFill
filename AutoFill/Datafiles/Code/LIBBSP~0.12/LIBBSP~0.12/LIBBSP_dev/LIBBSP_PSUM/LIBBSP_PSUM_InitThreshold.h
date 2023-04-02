/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_PSUM_INIT_THRESHOLD_H
#define LIBBSP_PSUM_INIT_THRESHOLD_H

#include "LIBBSP_PSUM_Globals.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
void LIBBSP_PSUM_InitThreshold(const TS_LIBBSP_PSUM_Conf * const p_conf,
                               const uint32_t                    v_nb_initilisation_couple);

/*==== END =============================================================================*/
#endif
