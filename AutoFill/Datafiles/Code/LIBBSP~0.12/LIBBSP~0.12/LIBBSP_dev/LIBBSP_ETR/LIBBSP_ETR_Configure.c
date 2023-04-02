/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_ETR_Configure.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/



/*==== Services ========================================================================*/

TE_LIBBSP_I2C_Code LIBBSP_ETR_Configure(void)
{
	TE_LIBBSP_I2C_Code v_ret;
	uint8_t v_buf[C_ETR_BUFF_CONF];


	/* verify if the device is opened */
	if (V_ETR_DS1682_State == E_LIBBSP_ETR_DS1682_OPEN)
	{

		/* write the data */
		v_buf[0] = (uint8_t)E_LIBBSP_ETR_DS1682_CONFREG; /* %RELAX<SYNCHRONe_C_Code_10.7> No precision lost: Enum value within range of uint8 */
		v_buf[1] = (uint8_t)C_ETR_CONF_VALUE;
		v_ret =  LIBBSP_I2C_Write(	C_ETR_DS1682_USED_BUS,
							C_ETR_DS1682_ADDRESS,
							C_ETR_BUFF_CONF,
							&v_buf[0] );

	}
	else
	{
		v_ret = E_LIBBSP_I2C_CLOSED;
	}
	return v_ret;
}

/*==== END =============================================================================*/
