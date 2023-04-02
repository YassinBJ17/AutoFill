/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_I2C_WaitForSlaveWriteAck.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

/* {{RELAX<SYNCHRONe_C_Code_17.4> Use of pointer array indexing :can't guess the size of the memory */
void LIBBSP_I2C_WaitForSlaveWriteAck(const TE_LIBBSP_I2C_Bus v_devID, TE_LIBBSP_I2C_CurrentStep* const v_step, TE_LIBBSP_I2C_ErrorCode* const v_errorCode)
{
	if ( P_I2C_RegAddress[v_devID].i2csr.I2CSR.MIF == (uint8_t)1)
	{
		P_I2C_RegAddress[v_devID].i2csr.I2CSR.MIF = (uint8_t)0;

		P_I2C_RegAddress[v_devID].i2ccr.I2CCR.MSTA = (uint8_t)0;
		P_I2C_RegAddress[v_devID].i2ccr.I2CCR.MEN = (uint8_t)1;

		*v_step = E_LIBBSP_I2C_DATA_WRITTEN;
	}
	else
	{
		*v_errorCode = E_LIBBSP_I2C_COMMAND_ERROR;
	}
}
/* }} RELAX<SYNCHRONe_C_Code_17.4> */
/*==== END =============================================================================*/
