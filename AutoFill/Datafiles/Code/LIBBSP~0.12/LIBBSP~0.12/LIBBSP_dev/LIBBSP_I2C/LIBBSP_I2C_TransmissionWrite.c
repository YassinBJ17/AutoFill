/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_I2C_TransmissionWrite.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

/* {{RELAX<SYNCHRONe_C_Code_17.4> Use of pointer array indexing :can't guess the size of the memory */

void LIBBSP_I2C_TransmissionWrite(const TE_LIBBSP_I2C_Bus v_devID, const uint8_t * const p_buffer ,const uint32_t v_size, TE_LIBBSP_I2C_Code * const v_errorCode)
{
	uint32_t v_index;

	if (P_I2C_RegAddress[v_devID].i2csr.I2CSR.RXAK == (uint8_t)0)
	{
		v_index = 0ul;
		/* A slave has responded  => Write data to slave (*/
		while ( (v_index < v_size) && (*v_errorCode == E_LIBBSP_I2C_OK) )
		{
			P_I2C_RegAddress[v_devID].i2cdr.I2CDR.DATA = p_buffer[v_index];    /* Write value */

			/* Wait EOT */
			*v_errorCode = LIBBSP_I2C_WaitEndOfTransmission(C_I2C_150_MICRO_S, &(P_I2C_RegAddress[v_devID].i2csr)); /* %RELAX<SYNCHRONe_C_Code_10.7> No precision lost  */

			v_index  = v_index + 1ul;
		};
		if ( *v_errorCode == E_LIBBSP_I2C_OK )
		{
			if (P_I2C_RegAddress[v_devID].i2csr.I2CSR.MAL == (uint8_t)1)
			{
				/* Arbitration lost */
				*v_errorCode = E_LIBBSP_I2C_ARBITRATION_LOST;
			}
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
		/* No slave answer */
		*v_errorCode = E_LIBBSP_I2C_NO_ACK;
	}
	/* Free I2C bus STOP */
	P_I2C_RegAddress[v_devID].i2ccr.I2CCR.MSTA = (uint8_t)0;


}

/* }} RELAX<SYNCHRONe_C_Code_17.4> */
/*==== END =============================================================================*/
