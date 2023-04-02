/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_DISC_Read.h"

/*==== Definitions =====================================================================*/


/*==== Variables ===========================================================================*/

/*==== SERVICES ========================================================================*/

void LIBBSP_DISC_Read(const TE_LIBBSP_DISC_Expander expanderID, uint16_t* const v_reg, TE_LIBBSP_I2C_Code * const v_ret)
{
	uint8_t v_buf;
	uint8_t v_buff_read[C_DISC_NB_BUFF];
	uint8_t v_slave_address;

	if (expanderID >= E_LIBBSP_DISC_NB_EXPANDER)
	{
	   *v_ret = E_LIBBSP_I2C_INVALID_ID;
	}
	else if (V_DISC_Max7312State[expanderID] != E_LIBBSP_DISC_MAX7312_OPEN)
   {
      *v_ret = E_LIBBSP_I2C_CLOSED;
   }
	else
	{
		if (expanderID == E_LIBBSP_DISC_EXPANDER_1)
		{
			v_slave_address = C_DISC_MAX7312_IO_EXP1_ADDR;
		}
		else
		{
			v_slave_address = C_DISC_MAX7312_IO_EXP2_ADDR;
		}

		/* prog the address */
		v_buf = (uint8_t)E_LIBBSP_DISC_MAX732_INPUT_PORT_1; /* %RELAX<SYNCHRONe_C_Code_10.7> Cast specific enum to generic data */

		*v_ret = LIBBSP_I2C_Write(C_DISC_MAX7312_USED_BUS,
								v_slave_address,
								1ul,
								&v_buf);



		if (*v_ret == E_LIBBSP_I2C_OK)
		{
			*v_ret = LIBBSP_I2C_Read(C_DISC_MAX7312_USED_BUS,
									v_slave_address,
									C_DISC_NB_BUFF,
									&v_buff_read[0]);
			if (*v_ret == E_LIBBSP_I2C_OK)
			{
				*v_reg = (uint16_t)(v_buff_read[0]) + (uint16_t)(((uint16_t)(v_buff_read[1])) << C_DISC_SHIFT_8_BITS);

			}

		}

	}
}
