/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_ETR_ReadInfos.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
void LIBBSP_ETR_ReadInfos(TS_LIBBSP_ETR_ReadInfos * const v_ReadValue, TE_LIBBSP_I2C_Code * const v_ret)
{
	uint8_t v_buf_cmd;
	uint8_t v_buf[C_ETR_BUFF_READ];

	v_ReadValue->v_AlarmRegdata = 0ul;
	v_ReadValue->v_ETregdata = 0ul;
	v_ReadValue->v_EventCountdata = (uint16_t)0;

	/* verify if the device is opened */
	if (V_ETR_DS1682_State == E_LIBBSP_ETR_DS1682_OPEN)
	{

		/*Read Alarm Register*/

		/* write the data */
		v_buf_cmd = (uint8_t)E_LIBBSP_ETR_DS1682_ALMREG_LL; /* %RELAX<SYNCHRONe_C_Code_10.7> enum field on 8 bits , no loss of precision */

		*v_ret =  LIBBSP_I2C_Write(	C_ETR_DS1682_USED_BUS,
							C_ETR_DS1682_ADDRESS,
							C_ETR_BUFF_WRITE,
							&v_buf_cmd);

		if (*v_ret == E_LIBBSP_I2C_OK)
		{
			/* read the data */
			*v_ret =  LIBBSP_I2C_Read(	C_ETR_DS1682_USED_BUS,
								C_ETR_DS1682_ADDRESS,
								C_ETR_BUFF_READ_ALARM,
								&v_buf[0]);

			if ( *v_ret == E_LIBBSP_I2C_OK )
			{
				v_ReadValue->v_AlarmRegdata = (uint32_t)(v_buf[0])
				          + (uint32_t)(((uint32_t)(v_buf[1])) << C_ETR_SHIFT_8_BITS)
						  + (uint32_t)(((uint32_t)(v_buf[2])) << C_ETR_SHIFT_16_BITS)
						  + (uint32_t)(((uint32_t)(v_buf[3])) << C_ETR_SHIFT_24_BITS);
			}
			else
			{
				/* DO NOTHING*/
			}
		}
		else
		{
			/* DO NOTHING*/
		}


		/*Read Elapsed Time Register*/

		/* write the data */
		v_buf_cmd = (uint8_t)E_LIBBSP_ETR_DS1682_ETCREG_LL; /* %RELAX<SYNCHRONe_C_Code_10.7> enum field on 8 bits , no loss of precision */

		*v_ret =  LIBBSP_I2C_Write(	C_ETR_DS1682_USED_BUS,
							C_ETR_DS1682_ADDRESS,
							C_ETR_BUFF_WRITE,
							&v_buf_cmd);

		if (*v_ret == E_LIBBSP_I2C_OK)
		{
			/* read the data */
			*v_ret =  LIBBSP_I2C_Read(	C_ETR_DS1682_USED_BUS,
								C_ETR_DS1682_ADDRESS,
								C_ETR_BUFF_READ_ALARM,
								&v_buf[0]);

			if ( *v_ret == E_LIBBSP_I2C_OK )
			{
				v_ReadValue->v_ETregdata = (uint32_t)(v_buf[0])
						  + (uint32_t)(((uint32_t)(v_buf[1])) << C_ETR_SHIFT_8_BITS)
						  + (uint32_t)(((uint32_t)(v_buf[2])) << C_ETR_SHIFT_16_BITS)
						  + (uint32_t)(((uint32_t)(v_buf[3])) << C_ETR_SHIFT_24_BITS);
			}
			else
			{
				/* DO NOTHING*/
			}
		}
		else
		{
			/* DO NOTHING*/
		}

		/*Read Event Counter*/

		/* write the data */
		v_buf_cmd = (uint8_t)E_LIBBSP_ETR_DS1682_ECREG_L; /* %RELAX<SYNCHRONe_C_Code_10.7> enum field on 8 bits , no loss of precision */

		*v_ret =  LIBBSP_I2C_Write(	C_ETR_DS1682_USED_BUS,
							C_ETR_DS1682_ADDRESS,
							C_ETR_BUFF_WRITE,
							&v_buf_cmd);

		if (*v_ret == E_LIBBSP_I2C_OK)
		{
			/* read the data */
			*v_ret =  LIBBSP_I2C_Read(	C_ETR_DS1682_USED_BUS,
								C_ETR_DS1682_ADDRESS,
								C_ETR_BUFF_READ_ALARM,
								&v_buf[0]);

			if ( *v_ret == E_LIBBSP_I2C_OK )
			{
				v_ReadValue->v_EventCountdata = (uint16_t)(v_buf[0])
						  + (uint16_t)(((uint16_t)(v_buf[1])) << C_ETR_SHIFT_8_BITS);
			}
			else
			{
				/* DO NOTHING*/
			}
		}
		else
		{
			/* DO NOTHING*/
		}



	}
	else
	{
		*v_ret = E_LIBBSP_I2C_CLOSED;
	}
}
/*==== END =============================================================================*/
