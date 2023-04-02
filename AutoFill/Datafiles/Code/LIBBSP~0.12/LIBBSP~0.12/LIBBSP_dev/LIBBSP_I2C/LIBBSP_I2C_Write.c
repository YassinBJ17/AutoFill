/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_I2C_Write.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

/* {{RELAX<SYNCHRONe_C_Code_17.4> Use of pointer array indexing :can't guess the size of the memory */

TE_LIBBSP_I2C_Code LIBBSP_I2C_Write(	const TE_LIBBSP_I2C_Bus v_devID,
					const uint8_t v_slave_adress,
					const uint32_t v_size,
					const uint8_t * const p_buffer )
{

    volatile TS_LIBBSP_I2C_Register v_reg;
    TE_LIBBSP_I2C_Code v_errorCode;



	if ( v_devID >= E_LIBBSP_I2C_NB_I2C_BUS )
	{
		v_errorCode = E_LIBBSP_I2C_INVALID_ID;
	}
	else if ( V_I2C_State[v_devID] != E_LIBBSP_I2C_BUS_OPEN )
	{
		v_errorCode = E_LIBBSP_I2C_CLOSED;
	}
	else
	{

		/* Enable device */
		P_I2C_RegAddress[v_devID].i2ccr.I2CCR.MEN = (uint8_t)1;
		/* Prepare control register value */
		v_reg.R = P_I2C_RegAddress[v_devID].i2ccr.R;     /* Get actual value */
		v_reg.I2CCR.MSTA = (uint8_t)1;                 /* Set master mode to take the bus */
		v_reg.I2CCR.MTX  = (uint8_t)1;                 /* Transmit mode */
		v_reg.I2CCR.TXAK = (uint8_t)0;                 /* Aknowledge received byte */

		if (P_I2C_RegAddress[v_devID].i2csr.I2CSR.MBB == (uint8_t)0)
		{
			/* I2C bus is free */
			P_I2C_RegAddress[v_devID].i2ccr.I2CREG.u8 = v_reg.I2CREG.u8;  /* Take I2C bus (master mode) to transmit START */
			P_I2C_RegAddress[v_devID].i2cdr.I2CDR.DATA = ((uint8_t)(v_slave_adress << 1) | (uint8_t)0);   /* Device address + write */
			/* Wait EOT */
			v_errorCode = LIBBSP_I2C_WaitEndOfTransmission(C_I2C_150_MICRO_S, &(P_I2C_RegAddress[v_devID].i2csr)); /* %RELAX<SYNCHRONe_C_Code_10.7> No precision lost  */
			if (v_errorCode == E_LIBBSP_I2C_OK)
			{
				LIBBSP_I2C_TransmissionWrite(v_devID, p_buffer, v_size, &v_errorCode);
			}
			else
			{
				/* Free I2C bus STOP */
				P_I2C_RegAddress[v_devID].i2ccr.I2CCR.MSTA = (uint8_t)0;
				/* Reset/disable device */
				P_I2C_RegAddress[v_devID].i2ccr.I2CCR.MEN = (uint8_t)0; /* v�rifier si cela est bien utile*/

			}
		}
		else
		{
			/* The bus is not free */
			v_errorCode = E_LIBBSP_I2C_BUS_BUSY;
		}

		/* Reset/disable device */
		P_I2C_RegAddress[v_devID].i2ccr.I2CCR.MEN = (uint8_t)1;

		if (v_errorCode == E_LIBBSP_I2C_OK) /*(v_wait == E_I2C_WAIT) &&*/
		{
			v_errorCode = LIBBSP_I2C_WaitEndOfBusy(C_I2C_150_MICRO_S, &(P_I2C_RegAddress[v_devID].i2csr)); /* %RELAX<SYNCHRONe_C_Code_10.7> No precision lost  */
			if (v_errorCode != E_LIBBSP_I2C_OK)
			{
				/* Free I2C bus STOP */
				P_I2C_RegAddress[v_devID].i2ccr.I2CCR.MSTA = (uint8_t)0;
				/* Reset/disable device */
				P_I2C_RegAddress[v_devID].i2ccr.I2CCR.MEN = (uint8_t)0; /* v�rifier si cela est bien utile*/
			}
			else
			{
				/* NOTHING TO DO */
			}
		}
		else
		{
			/* NOTHING TO DO */
		}
	}

    return v_errorCode; /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
}
/* }} RELAX<SYNCHRONe_C_Code_17.4> */
/*==== END =============================================================================*/
