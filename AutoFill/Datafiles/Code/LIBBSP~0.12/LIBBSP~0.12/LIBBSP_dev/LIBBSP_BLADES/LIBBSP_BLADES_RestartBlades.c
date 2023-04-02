/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/

#include "LIBBSP_BLADES_RestartBlades.h"

boolean_t LIBBSP_BLADES_RestartBlades( void )
{
    return LIBBSP_BLADES_WriteBlades(C_LIBBSP_BLADES_START_BLADES, C_LIBBSP_BLADES_STARTED_VALUE);
}