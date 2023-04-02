/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_CMN_CheckElapsedTime.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
uint32_t LIBBSP_CMN_CheckElapsedTime( uint32_t v_currentTime, uint32_t v_previousTime ) /* %RELAX<SYNCHRONe_C_Code_16.12> assembler command to access a register */
{
	uint32_t v_elapsed;

    if ( v_currentTime >= v_previousTime )
    {
        v_elapsed = (v_currentTime - v_previousTime);				
    }
    else
    {
        v_previousTime = C_CMN_MAX_TIME - v_previousTime;
        v_elapsed = (v_currentTime + v_previousTime);
    }

    return v_elapsed;
}

/*==== END =============================================================================*/