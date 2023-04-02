/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/

#include "LIBBSP_BLADES_StopBlades.h"

boolean_t LIBBSP_BLADES_StopBlades( void )
{
    /* Set the mode to HRG calibration mode to access the blades and PQR RAM */
    return LIBBSP_BLADES_WriteBlades(C_LIBBSP_BLADES_STOP_BLADES, C_LIBBSP_BLADES_STOPPED_VALUE);
}