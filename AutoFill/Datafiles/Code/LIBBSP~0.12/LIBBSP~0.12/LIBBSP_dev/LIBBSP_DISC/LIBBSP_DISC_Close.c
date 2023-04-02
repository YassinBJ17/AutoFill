/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_DISC_Close.h"

/*==== Definitions =====================================================================*/


/*==== Variables ===========================================================================*/


/*==== SERVICES ========================================================================*/

TE_LIBBSP_I2C_Code LIBBSP_DISC_Close(void)
{
	TE_LIBBSP_I2C_Code v_rc;
	uint32_t v_i;

	v_rc = E_LIBBSP_I2C_CLOSED;

	for (v_i = 0ul; v_i < E_LIBBSP_DISC_NB_EXPANDER; ++v_i)
	{
		if ( V_DISC_Max7312State[v_i] == E_LIBBSP_DISC_MAX7312_OPEN )
		{
			V_DISC_Max7312State[v_i] = E_LIBBSP_DISC_MAX7312_CLOSED;
			v_rc = E_LIBBSP_I2C_OK;
		}
	}

	if ( v_rc == E_LIBBSP_I2C_OK )
	{
		v_rc = LIBBSP_I2C_Close(C_DISC_MAX7312_USED_BUS);
	}

	return (v_rc); /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
}
