/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_I2C_Close.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

TE_LIBBSP_I2C_Code LIBBSP_I2C_Close(const TE_LIBBSP_I2C_Bus v_devID)
{
	/* var used for the erreor return */
	TE_LIBBSP_I2C_Code v_ret;

	/* initialization of the return */
	v_ret = E_LIBBSP_I2C_OK;

    /* Verify the device */
    if (v_devID >= E_LIBBSP_I2C_NB_I2C_BUS)
	{
        v_ret = E_LIBBSP_I2C_INVALID_ID;
	}
	else
	{
		/* change the state of the bus */
		V_I2C_State[v_devID] = E_LIBBSP_I2C_BUS_CLOSED;
	}

    return v_ret;
}

/*==== END =============================================================================*/
