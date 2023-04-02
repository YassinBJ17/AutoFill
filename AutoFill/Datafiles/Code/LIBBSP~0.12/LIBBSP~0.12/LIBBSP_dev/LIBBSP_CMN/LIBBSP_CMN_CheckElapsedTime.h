/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2022                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_CMN_CHECK_ELAPSED_TIME_H
#define LIBBSP_CMN_CHECK_ELAPSED_TIME_H

#include "LIBBSP_CMN_Globals.h"

/*==== Definitions =====================================================================*/

extern const uint32_t C_CMN_MAX_TIME;

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
uint32_t LIBBSP_CMN_CheckElapsedTime( uint32_t v_currentTime, uint32_t v_previousTime );

/*==== END =============================================================================*/
#endif
