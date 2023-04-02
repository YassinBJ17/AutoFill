/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_I2C_DataRead.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

/* {{RELAX<SYNCHRONe_C_Code_17.4> Use of pointer array indexing :can't guess the size of the memory */

void LIBBSP_I2C_DataRead(const TE_LIBBSP_I2C_Bus v_devID, TE_LIBBSP_I2C_CurrentStep* const v_step, TE_LIBBSP_I2C_ErrorCode* const v_errorCode)
{

	volatile TS_LIBBSP_I2C_Register v_reg;

	if ( P_I2C_RegAddress[v_devID].i2csr.I2CSR.MIF == (uint8_t)1)
	{
		P_I2C_RegAddress[v_devID].i2csr.I2CSR.MIF = (uint8_t)0;

		v_reg.R = P_I2C_RegAddress[v_devID].i2ccr.R;     /* Get actual value */

		v_reg.I2CCR.MSTA = (uint8_t)1;                 /* Set master mode to take the bus */
		v_reg.I2CCR.MTX  = (uint8_t)1;
		/*reg.I2CCR.TXAK = 1;*/
		/*reg.I2CCR.MTX = 1;*/
		P_I2C_RegAddress[v_devID].i2ccr.R = v_reg.R;

		V_I2C_BuffRead[v_devID][V_I2C_ReadSize[v_devID]-1ul] = P_I2C_RegAddress[v_devID].i2cdr.I2CDR.DATA;       /* Read last byte of data */

		/* Free I2C bus STOP */
		P_I2C_RegAddress[v_devID].i2ccr.I2CCR.MSTA = (uint8_t)0;
		/* Reset/disable device */
		P_I2C_RegAddress[v_devID].i2ccr.I2CCR.MEN = (uint8_t)0;

		*v_step = E_LIBBSP_I2C_IDLE;
	}
	else
	{
		*v_errorCode = E_LIBBSP_I2C_COMMAND_ERROR;
	}


}
/* }} RELAX<SYNCHRONe_C_Code_17.4> */

/*==== END =============================================================================*/
