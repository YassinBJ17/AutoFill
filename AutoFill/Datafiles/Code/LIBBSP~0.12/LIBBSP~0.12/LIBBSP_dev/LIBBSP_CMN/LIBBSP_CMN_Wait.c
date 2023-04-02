/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_CMN_Wait.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

void LIBBSP_CMN_Wait(const uint32_t timeout)
{
	uint32_t v_count;
	/*(void)LIBBSP_CMN_waitForTrueCondition(alwaysFalse, timeout);*/

	v_count = timeout;
	/* {{RELAX<SYNCHRONe_C_Code_14.2> waiting timeout */
	while ( LIBBSP_CMN_isElapsed(&v_count) == (uint32_t)0)
	{
		
	}/* }} RELAX<SYNCHRONe_C_Code_14.2> */
	/* If v_ret = 0 => Time is reached*/
}

/*==== END =============================================================================*/
