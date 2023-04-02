/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_I2C_ReceiveMode.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

/* {{RELAX<SYNCHRONe_C_Code_17.4> Use of pointer array indexing :can't guess the size of the memory */

void LIBBSP_I2C_ReceiveMode(const TE_LIBBSP_I2C_Bus v_devID, const uint32_t v_size, uint8_t * const pa_buffer, TE_LIBBSP_I2C_Code* const v_errorCode)
{
	volatile TS_LIBBSP_I2C_Register v_reg;
	uint32_t v_index;

	P_I2C_RegAddress[v_devID].i2ccr.I2CCR.MTX = (uint8_t)0; /* une fois l'adresse envoy�e, on part en lecture*/

	if (P_I2C_RegAddress[v_devID].i2csr.I2CSR.RXAK == (uint8_t)0)
	{
		if (v_size == 1ul)
		{
			v_reg.R = P_I2C_RegAddress[v_devID].i2ccr.R;     /* Get actual value */

			v_reg.I2CCR.MSTA = (uint8_t)1;                 /* Set master mode to take the bus */
			/*reg.I2CCR.MTX  = 1;*/
			v_reg.I2CCR.TXAK = (uint8_t)1;
			P_I2C_RegAddress[v_devID].i2ccr.R = v_reg.R;
		}
		else
		{
			v_reg.R = P_I2C_RegAddress[v_devID].i2ccr.R;     /* Get actual value */

			v_reg.I2CCR.MSTA = (uint8_t)1;                 /* Set master mode to take the bus */
			/*reg.I2CCR.MTX  = 1;*/
			v_reg.I2CCR.TXAK = (uint8_t)0;
			P_I2C_RegAddress[v_devID].i2ccr.R = v_reg.R;

		}

		/* A slave has responded  => Read data from slave */
		v_reg.R = (uint32_t)P_I2C_RegAddress[v_devID].i2cdr.I2CDR.DATA;            /* Start first read */ /* dummy read */

		/* Wait EOT */
		*v_errorCode = LIBBSP_I2C_WaitEndOfTransmission(C_I2C_150_MICRO_S, &(P_I2C_RegAddress[v_devID].i2csr)); /* %RELAX<SYNCHRONe_C_Code_10.7> no precision lost */

		if (*v_errorCode == E_LIBBSP_I2C_OK)
		{
			v_index = 0ul;
			while ( (v_index < (v_size-1ul)) && (*v_errorCode == E_LIBBSP_I2C_OK))
			{
				if (  v_index == (v_size-2ul) )
				{
					v_reg.R = P_I2C_RegAddress[v_devID].i2ccr.R;     /* Get actual value */
					v_reg.I2CCR.MSTA = (uint8_t)1;                 /* Set master mode to take the bus */
					/*reg.I2CCR.MTX  = 1;*/
					v_reg.I2CCR.TXAK = (uint8_t)1;
					P_I2C_RegAddress[v_devID].i2ccr.R = v_reg.R;
				}
				pa_buffer[v_index] = P_I2C_RegAddress[v_devID].i2cdr.I2CDR.DATA;    /* Read value ans start receiving next data */

				/* Wait EOT */
				*v_errorCode = LIBBSP_I2C_WaitEndOfTransmission(C_I2C_150_MICRO_S, &(P_I2C_RegAddress[v_devID].i2csr)); /* %RELAX<SYNCHRONe_C_Code_10.7> no precision lost */
				if (*v_errorCode != E_LIBBSP_I2C_OK)
				{
					    /* Free I2C bus STOP */
						P_I2C_RegAddress[v_devID].i2ccr.I2CCR.MSTA = (uint8_t)0;

						/* Reset/disable device */
						P_I2C_RegAddress[v_devID].i2ccr.I2CCR.MEN = (uint8_t)0;
				}
				v_index = v_index + 1ul;
			}
		}
		else
		{
			/* Free I2C bus STOP */
			P_I2C_RegAddress[v_devID].i2ccr.I2CCR.MSTA = (uint8_t)0;

			/* Reset/disable device */
			P_I2C_RegAddress[v_devID].i2ccr.I2CCR.MEN = (uint8_t)0;
		}
		if (*v_errorCode == E_LIBBSP_I2C_OK)
		{
			v_reg.R = P_I2C_RegAddress[v_devID].i2ccr.R;     /* Get actual value */

			v_reg.I2CCR.MSTA = (uint8_t)1;                 /* Set master mode to take the bus */
			v_reg.I2CCR.MTX  = (uint8_t)1;
			/*reg.I2CCR.TXAK = 1;*/
			/*reg.I2CCR.MTX = 1;*/
			P_I2C_RegAddress[v_devID].i2ccr.R = v_reg.R;


			pa_buffer[v_size-1ul] = P_I2C_RegAddress[v_devID].i2cdr.I2CDR.DATA;       /* Read last byte of data */

			/* Wait EOT */
			if (P_I2C_RegAddress[v_devID].i2csr.I2CSR.MAL == (uint8_t)1)
			{
				/* Arbitration lost */
				*v_errorCode = E_LIBBSP_I2C_ARBITRATION_LOST;
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
	else
	{
		 *v_errorCode = E_LIBBSP_I2C_NO_ACK;
	}
	/* Free I2C bus STOP */
	P_I2C_RegAddress[v_devID].i2ccr.I2CCR.MSTA = (uint8_t)0;


}
/* }} RELAX<SYNCHRONe_C_Code_17.4> */
/*==== END =============================================================================*/
