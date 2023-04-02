/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_ETR_Close.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

TE_LIBBSP_I2C_Code LIBBSP_ETR_Close(void)
{
	TE_LIBBSP_I2C_Code v_rc;

	v_rc = E_LIBBSP_I2C_CLOSED;

	if (V_ETR_DS1682_State == E_LIBBSP_ETR_DS1682_OPEN)
	{
		v_rc = LIBBSP_I2C_Close(C_ETR_DS1682_USED_BUS);
		V_ETR_DS1682_State = E_LIBBSP_ETR_DS1682_CLOSED;
	}

	return (v_rc); /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
}

/*==== END =============================================================================*/
