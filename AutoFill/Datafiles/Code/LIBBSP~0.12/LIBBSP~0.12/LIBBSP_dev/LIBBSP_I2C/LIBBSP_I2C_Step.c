/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_I2C_Step.h"


/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
TE_LIBBSP_I2C_ErrorCode LIBBSP_I2C_Step(	const TE_LIBBSP_I2C_Bus v_devID,
											TE_LIBBSP_I2C_CurrentStep* const v_step)
{

   TE_LIBBSP_I2C_ErrorCode v_errorCode = E_LIBBSP_I2C_COMMAND_TAKEN;


	if ((v_devID >= E_LIBBSP_I2C_NB_I2C_BUS) || (V_I2C_State[v_devID] != E_LIBBSP_I2C_BUS_OPEN))
	{
		v_errorCode = E_LIBBSP_I2C_COMMAND_NOT_TAKEN;
	}
	else
	{
		switch(*v_step)
			{
				/*WRITE*/
				case E_LIBBSP_I2C_WAIT_FOR_SLV_CMD_W_ACK:

					LIBBSP_I2C_WaitForSlaveWriteCmd(v_devID, v_step, &v_errorCode);

					break;

				case E_LIBBSP_I2C_WAIT_FOR_SLV_W_ACK:

					LIBBSP_I2C_WaitForSlaveWriteAck(v_devID, v_step, &v_errorCode);
					break;

				case E_LIBBSP_I2C_DATA_WRITTEN:

					*v_step = E_LIBBSP_I2C_IDLE;

					break;

				/*READ*/
				case E_LIBBSP_I2C_WAIT_FOR_SLV_CMD_R_ACK:

					LIBBSP_I2C_WaitForSlaveReadCmd(v_devID, v_step, &v_errorCode);

					break;

				case E_LIBBSP_I2C_WAIT_FOR_SLV_R_DATA:

					LIBBSP_I2C_WaitForSlaveReadData(v_devID, v_step, &v_errorCode);

					break;

				case E_LIBBSP_I2C_DATA_READ:

					LIBBSP_I2C_DataRead(v_devID, v_step, &v_errorCode);

					break;

				default:

					break;
			}
	}

	return (v_errorCode); /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
}
/*==== END =============================================================================*/
