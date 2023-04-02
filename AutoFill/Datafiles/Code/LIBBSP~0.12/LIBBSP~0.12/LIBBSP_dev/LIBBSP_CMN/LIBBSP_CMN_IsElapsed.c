/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_CMN_IsElapsed.h"
#include "LIBBSP_CMN_CheckElapsedTime.h"

/*==== Definitions =====================================================================*/
#define TIME_10_MICRO_S /*0x0168*/(0x1a0ul)

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
uint32_t LIBBSP_CMN_isElapsed(uint32_t * const Count) 
{
	uint32_t v_previousTime;
	uint32_t v_currentTime;
	uint32_t v_elapsedTime;
	uint32_t v_ret;


	if (*Count == 0ul)
	{
		v_ret = 1ul;
	}
	else
	{
		*Count -= 1ul;
		v_previousTime = LIBBSP_CMN_GetTicks();
		v_elapsedTime = 0;

		do
		{
			v_currentTime = LIBBSP_CMN_GetTicks();
			v_elapsedTime += LIBBSP_CMN_CheckElapsedTime(v_currentTime, v_previousTime);
			v_previousTime = v_currentTime;
		}
		while (v_elapsedTime < TIME_10_MICRO_S);

		v_ret = 0ul;
	}
    return v_ret;
};

/*==== END =============================================================================*/
