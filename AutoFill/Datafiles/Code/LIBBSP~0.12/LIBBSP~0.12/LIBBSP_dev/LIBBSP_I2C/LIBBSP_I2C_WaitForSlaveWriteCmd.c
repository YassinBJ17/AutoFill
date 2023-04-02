/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_I2C_WaitForSlaveWriteCmd.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

/* {{RELAX<SYNCHRONe_C_Code_17.4> Use of pointer array indexing :can't guess the size of the memory */

void LIBBSP_I2C_WaitForSlaveWriteCmd(const TE_LIBBSP_I2C_Bus v_devID, TE_LIBBSP_I2C_CurrentStep* const v_step, TE_LIBBSP_I2C_ErrorCode* const v_errorCode)
{

	if(V_I2C_WriteIndex[v_devID] < V_I2C_WriteSize[v_devID])
	{
		if ( P_I2C_RegAddress[v_devID].i2csr.I2CSR.MIF == (uint8_t)1)
		{
			P_I2C_RegAddress[v_devID].i2csr.I2CSR.MIF = (uint8_t)0;

			if (P_I2C_RegAddress[v_devID].i2csr.I2CSR.RXAK == (uint8_t)0)
			{

				P_I2C_RegAddress[v_devID].i2cdr.I2CDR.DATA = V_I2C_BuffWrite[v_devID][V_I2C_WriteIndex[v_devID]];

				if(V_I2C_WriteIndex[v_devID] == (V_I2C_WriteSize[v_devID]-1ul))
				{
					*v_step = E_LIBBSP_I2C_WAIT_FOR_SLV_W_ACK;
				}
				else
				{
					V_I2C_WriteIndex[v_devID]++;
				}


			}
			else
			{
				*v_errorCode = E_LIBBSP_I2C_COMMAND_ERROR;
			}
		}
		else
		{
			*v_errorCode = E_LIBBSP_I2C_COMMAND_ERROR;
		}

	}
	else
	{
		*v_errorCode = E_LIBBSP_I2C_COMMAND_ERROR;
	}

}

/* }} RELAX<SYNCHRONe_C_Code_17.4> */
/*==== END =============================================================================*/
