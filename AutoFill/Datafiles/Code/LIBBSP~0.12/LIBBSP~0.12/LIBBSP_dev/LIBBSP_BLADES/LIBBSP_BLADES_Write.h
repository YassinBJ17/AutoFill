/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_BLADES_WRITE_H
#define LIBBSP_BLADES_WRITE_H
#include "LIBBSP_BLADES_Globals.h"
#include "LIBBSP_BLADES_Anchor.h"
#include "LIBBSP_BLADES_Defines.h"
#include "LIBBSP_CMN.h"

/*==== Service =========================================================================*/

boolean_t LIBBSP_BLADES_WriteBlades( uint32_t const v_write_value, uint32_t const v_expected_value );
#endif
