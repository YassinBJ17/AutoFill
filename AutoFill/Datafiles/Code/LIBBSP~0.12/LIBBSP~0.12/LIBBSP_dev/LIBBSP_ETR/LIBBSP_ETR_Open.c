/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_ETR_Open.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/
/*==== Services ========================================================================*/

TE_LIBBSP_I2C_Code LIBBSP_ETR_Open(void)
{
	TE_LIBBSP_I2C_Code v_rc;

	V_ETR_DS1682_State = E_LIBBSP_ETR_DS1682_CLOSED;

	/* open the link */
	v_rc =  LIBBSP_I2C_Open(C_ETR_DS1682_USED_BUS,
			C_ETR_DS1682_DIGITAL_FILTER,
			C_ETR_DS1682_DIVISOR_VALUE );

	if ( v_rc == E_LIBBSP_I2C_OK )
	{
		V_ETR_DS1682_State = E_LIBBSP_ETR_DS1682_OPEN;
	}

	return (v_rc); /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
}

/*==== END =============================================================================*/
