/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_I2C_ReadNoWait.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

/* {{RELAX<SYNCHRONe_C_Code_17.4> Use of pointer array indexing :can't guess the size of the memory */

TE_LIBBSP_I2C_ErrorCode LIBBSP_I2C_ReadNoWait(	const TE_LIBBSP_I2C_Bus v_devID,
					const uint8_t v_slave_adress,
					const uint32_t v_size,
				    TE_LIBBSP_I2C_CurrentStep* const v_step)
{

	volatile TS_LIBBSP_I2C_Register v_reg;
	uint32_t v_i;
	TE_LIBBSP_I2C_ErrorCode v_errorCode;

	v_errorCode = E_LIBBSP_I2C_COMMAND_TAKEN;

	if ((v_devID >= E_LIBBSP_I2C_NB_I2C_BUS) || (V_I2C_State[v_devID] != E_LIBBSP_I2C_BUS_OPEN))
	{
		v_errorCode = E_LIBBSP_I2C_COMMAND_NOT_TAKEN;
	}
	else if(v_size > C_I2C_NB_BYTE_MAX)
	{
		v_errorCode = E_LIBBSP_I2C_READ_OVERSIZED;
	}
	else
	{
		if (*v_step == E_LIBBSP_I2C_IDLE)
		{
			/* Init global */
			for (v_i = 0ul; v_i<v_size; v_i++)
			{
				V_I2C_BuffRead[v_devID][v_i] = (uint8_t)0;
			}

			V_I2C_ReadSize[v_devID] = v_size;
			V_I2C_ReadIndex[v_devID] = 0ul;


			/* Enable device */
			P_I2C_RegAddress[v_devID].i2ccr.I2CCR.MEN = (uint8_t)1;

			/* Prepare control register value */
			v_reg.R = P_I2C_RegAddress[v_devID].i2ccr.R;     /* Get actual value */
			v_reg.I2CCR.MSTA = (uint8_t)1;                 /* Set master mode to take the bus */
			v_reg.I2CCR.MTX  = (uint8_t)1;                 /* Transmit mode */
			v_reg.I2CCR.TXAK = (uint8_t)0;                 /* Aknowledge received byte */
			/*busy2 = P_I2C_RegAddress[v_devID].i2csr.I2CSR.MBB;*/
			if (P_I2C_RegAddress[v_devID].i2csr.I2CSR.MBB/* busy2 */ == (uint8_t)0)
			{
				/* I2C bus is free */
				P_I2C_RegAddress[v_devID].i2ccr.I2CREG.u8 = v_reg.I2CREG.u8;


				/* Take I2C bus (master mode) to transmit START */
				/* {{RELAX<SYNCHRONe_C_Code_10.7, SYNCHRONe_C_Code_11.1> No precision lost: affect value to just a part of the variable (see the structure to better understand) */
				*(volatile uint8_t *)&(P_I2C_RegAddress[v_devID].i2cdr.R) = ((uint8_t)(v_slave_adress << (uint8_t)1) | (uint8_t)1); /* Device address read */
				/* }} RELAX<SYNCHRONe_C_Code_10.7, SYNCHRONe_C_Code_11.1> */

				*v_step = E_LIBBSP_I2C_WAIT_FOR_SLV_CMD_R_ACK;

			}
			else
			{
				v_errorCode = E_LIBBSP_I2C_COMMAND_ERROR;
			}
		}
		else
		{
			v_errorCode = E_LIBBSP_I2C_COMMAND_NOT_TAKEN;
		}
	}


    return v_errorCode; /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
}
/* }} RELAX<SYNCHRONe_C_Code_17.4> */
/*==== END =============================================================================*/
