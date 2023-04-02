/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_DISC_Open.h"

/*==== Definitions =====================================================================*/


/*==== Variables ===========================================================================*/
TE_LIBBSP_DISC_Max7312State V_DISC_Max7312State[E_LIBBSP_DISC_NB_EXPANDER];
TE_LIBBSP_DISC_Cmd V_DISC_Cmd[E_LIBBSP_DISC_NB_EXPANDER];

/*==== SERVICES ========================================================================*/

TE_LIBBSP_I2C_Code LIBBSP_DISC_Open(const TE_LIBBSP_DISC_Expander expanderID)
{
	TE_LIBBSP_I2C_Code v_ret;

    V_DISC_Max7312State[expanderID] = E_LIBBSP_DISC_MAX7312_CLOSED;
    V_DISC_Cmd[expanderID] = E_LIBBSP_DISC_CMD_IDLE;

	if (expanderID >= E_LIBBSP_DISC_NB_EXPANDER)
	{
		v_ret = E_LIBBSP_I2C_INVALID_ID;
	}
	else
	{
		/* open the link */
		v_ret =  LIBBSP_I2C_Open(C_DISC_MAX7312_USED_BUS,
				C_DISC_MAX7312_DIGITAL_FILTER,
				C_DISC_MAX7312_DIVISOR_VALUE );

		if ( v_ret == E_LIBBSP_I2C_OK )
		{
			V_DISC_Max7312State[expanderID] = E_LIBBSP_DISC_MAX7312_OPEN;
		}
	}

    return v_ret; /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
}
