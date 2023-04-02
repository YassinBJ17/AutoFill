/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_DISC_Step.h"

/*==== Definitions =====================================================================*/


/*==== Variables ===========================================================================*/

/*==== SERVICES ========================================================================*/

void LIBBSP_DISC_Step(const TE_LIBBSP_DISC_Expander expanderID, const TE_LIBBSP_I2C_CurrentStep v_step_in, TE_LIBBSP_I2C_CurrentStep* const v_step_out, TE_LIBBSP_I2C_ErrorCode * const v_ret)
{
	uint8_t v_slave_address;


	*v_step_out = v_step_in;

	if (expanderID >= E_LIBBSP_DISC_NB_EXPANDER)
	{
		*v_ret = E_LIBBSP_I2C_COMMAND_NOT_TAKEN;
	}
	else
	{
		*v_ret = LIBBSP_I2C_Step(C_DISC_MAX7312_USED_BUS,v_step_out);

		if ((*v_ret == E_LIBBSP_I2C_COMMAND_TAKEN) && (V_DISC_Cmd[expanderID] == E_LIBBSP_DISC_CMD_READ) && (*v_step_out == E_LIBBSP_I2C_IDLE))
		{

			if (expanderID == E_LIBBSP_DISC_EXPANDER_1)
			{
				v_slave_address = C_DISC_MAX7312_IO_EXP1_ADDR;
			}
			else
			{
				v_slave_address = C_DISC_MAX7312_IO_EXP2_ADDR;
			}

			*v_ret = LIBBSP_I2C_ReadNoWait(C_DISC_MAX7312_USED_BUS, v_slave_address, C_DISC_NB_BUFF, v_step_out);

			V_DISC_Cmd[expanderID] = E_LIBBSP_DISC_CMD_IDLE;
		}
	}

}
