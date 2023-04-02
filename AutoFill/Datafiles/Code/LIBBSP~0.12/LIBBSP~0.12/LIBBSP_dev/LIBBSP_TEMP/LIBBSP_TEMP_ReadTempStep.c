/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_TEMP_ReadTempStep.h"

/*==== Definitions =====================================================================*/

/*==== Types ===========================================================================*/

/*==== SERVICES ========================================================================*/


void LIBBSP_TEMP_ReadTempStep(TE_LIBBSP_I2C_CurrentStep const v_step_in, TE_LIBBSP_I2C_CurrentStep* const v_step_out, TE_LIBBSP_I2C_ErrorCode * const v_ret)
{

	*v_step_out = v_step_in;

	*v_ret = LIBBSP_I2C_Step(C_TEMP_TMP451_USED_BUS,v_step_out);

	if ((*v_ret == E_LIBBSP_I2C_COMMAND_TAKEN) && (V_TEMP_Cmd == E_LIBBSP_TEMP_CMD_READ) && (*v_step_out == E_LIBBSP_I2C_IDLE))
	{
		*v_ret = LIBBSP_I2C_ReadNoWait(C_TEMP_TMP451_USED_BUS, C_TEMP_TMP451_ADDRESS, 1ul, v_step_out);
		V_TEMP_Cmd = E_LIBBSP_TEMP_CMD_IDLE;
	}

}

