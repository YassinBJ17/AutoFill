/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_DISC_WriteNoWait.h"

/*==== Definitions =====================================================================*/


/*==== Variables ===========================================================================*/

/*==== SERVICES ========================================================================*/

void LIBBSP_DISC_WriteNoWait(const TE_LIBBSP_DISC_Expander expanderID, const uint16_t v_reg, const TE_LIBBSP_I2C_CurrentStep v_step_in, TE_LIBBSP_I2C_CurrentStep* const v_step_out, TE_LIBBSP_I2C_ErrorCode * const v_ret)
{
	uint8_t v_buf[C_DISC_NB_WRITE];
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
		/* {{RELAX<SYNCHRONe_C_Code_10.7> No precision lost: partitioning of value into a table */
		v_buf[0] = (uint8_t)E_LIBBSP_DISC_MAX732_OUTPUT_PORT_1;
		v_buf[1] = (uint8_t)(v_reg & C_DISC_MASK_FIRST_BYTE);
		v_buf[2] = (uint8_t)((v_reg>>C_DISC_SHIFT_8_BITS) & C_DISC_MASK_FIRST_BYTE);
		/* }} RELAX<SYNCHRONe_C_Code_10.7> */
		*v_ret = LIBBSP_I2C_WriteNoWait(C_DISC_MAX7312_USED_BUS,
										  v_slave_address,
										  C_DISC_NB_WRITE,
										  &v_buf[0],
										  v_step_out);

		V_DISC_Cmd[expanderID] = E_LIBBSP_DISC_CMD_WRITE;
	}
}


