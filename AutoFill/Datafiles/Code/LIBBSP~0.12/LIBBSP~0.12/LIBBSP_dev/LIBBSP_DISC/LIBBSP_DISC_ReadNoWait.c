/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_DISC_ReadNoWait.h"

/*==== Definitions =====================================================================*/


/*==== Variables ===========================================================================*/

/*==== SERVICES ========================================================================*/

void LIBBSP_DISC_ReadNoWait(const TE_LIBBSP_DISC_Expander expanderID, const TE_LIBBSP_I2C_CurrentStep v_step_in, TE_LIBBSP_I2C_CurrentStep* const v_step_out, TE_LIBBSP_I2C_ErrorCode * const v_ret)
{
	uint8_t v_buf;
	uint8_t v_slave_address;

	*v_step_out = v_step_in;

	if(expanderID >= E_LIBBSP_DISC_NB_EXPANDER)
	{
	   *v_ret = E_LIBBSP_I2C_COMMAND_ERROR;
	}
	else if (V_DISC_Max7312State[expanderID] != E_LIBBSP_DISC_MAX7312_OPEN)
	{
		*v_ret = E_LIBBSP_I2C_COMMAND_NOT_TAKEN;
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

		*v_ret = LIBBSP_I2C_WriteNoWait(C_DISC_MAX7312_USED_BUS, v_slave_address, 1ul, &v_buf, v_step_out);

		V_DISC_Cmd[expanderID] = E_LIBBSP_DISC_CMD_READ;
	}
}
