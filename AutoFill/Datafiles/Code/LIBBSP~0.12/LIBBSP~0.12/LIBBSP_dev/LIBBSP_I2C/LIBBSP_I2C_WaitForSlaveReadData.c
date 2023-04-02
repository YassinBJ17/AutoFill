/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_I2C_WaitForSlaveReadData.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

/* {{RELAX<SYNCHRONe_C_Code_17.4> Use of pointer array indexing :can't guess the size of the memory */

void LIBBSP_I2C_WaitForSlaveReadData(const TE_LIBBSP_I2C_Bus v_devID, TE_LIBBSP_I2C_CurrentStep* const v_step, TE_LIBBSP_I2C_ErrorCode* const v_errorCode)
{

	volatile TS_LIBBSP_I2C_Register v_reg;

	if (V_I2C_ReadIndex[v_devID] < (V_I2C_ReadSize[v_devID]-1ul))
	{
		if ( P_I2C_RegAddress[v_devID].i2csr.I2CSR.MIF == (uint8_t)1)
		{
			P_I2C_RegAddress[v_devID].i2csr.I2CSR.MIF = (uint8_t)0;

			if (V_I2C_ReadIndex[v_devID] == (V_I2C_ReadSize[v_devID]-2ul))
			{
				/* lecture du 1 er mot */
				v_reg.R = P_I2C_RegAddress[v_devID].i2ccr.R;     /* Get actual value */
				v_reg.I2CCR.MSTA = (uint8_t)1;                 /* Set master mode to take the bus */
				/*reg.I2CCR.MTX  = 1;*/
				v_reg.I2CCR.TXAK = (uint8_t)1;
				P_I2C_RegAddress[v_devID].i2ccr.R = v_reg.R;
			}

			V_I2C_BuffRead[v_devID][V_I2C_ReadIndex[v_devID]] = P_I2C_RegAddress[v_devID].i2cdr.I2CDR.DATA;

			if (V_I2C_ReadIndex[v_devID] == (V_I2C_ReadSize[v_devID]-2ul))
			{
				*v_step = E_LIBBSP_I2C_DATA_READ;
			}
			else
			{
				V_I2C_ReadIndex[v_devID]++;
			}

		}
		else
		{
			*v_errorCode = E_LIBBSP_I2C_COMMAND_ERROR;
		}
	}
	else if (V_I2C_ReadIndex[v_devID] == (V_I2C_ReadSize[v_devID]-1ul))
	{
		*v_step = E_LIBBSP_I2C_DATA_READ;
	}
	else
	{
		*v_errorCode = E_LIBBSP_I2C_COMMAND_ERROR;
	}


}
/* }} RELAX<SYNCHRONe_C_Code_17.4> */
/*==== END =============================================================================*/
