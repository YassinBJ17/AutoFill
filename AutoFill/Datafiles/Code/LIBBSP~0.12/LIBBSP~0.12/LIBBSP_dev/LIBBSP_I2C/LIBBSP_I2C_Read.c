/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_I2C_Read.h"


/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

/* {{RELAX<SYNCHRONe_C_Code_17.4> Use of pointer array indexing :can't guess the size of the memory */

TE_LIBBSP_I2C_Code LIBBSP_I2C_Read(const TE_LIBBSP_I2C_Bus v_devID,
									const uint8_t v_slave_adress,
									const uint32_t v_size,
									uint8_t * const pa_buffer) /* %RELAX<SYNCHRONe_C_Code_8.18> Output only used as paramter in subfunction  */
{
    volatile TS_LIBBSP_I2C_Register v_reg;
    TE_LIBBSP_I2C_Code v_errorCode;

    /* Verify v_devID */

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
		/*busy2 = P_I2C_RegAddress[v_devID].i2csr.I2CSR.MBB;*/
		if (P_I2C_RegAddress[v_devID].i2csr.I2CSR.MBB/* busy2 */ == (uint8_t)0)
		{
			/* I2C bus is free */
			P_I2C_RegAddress[v_devID].i2ccr.I2CREG.u8 = v_reg.I2CREG.u8;


			/* Take I2C bus (master mode) to transmit START */
			/* {{RELAX<SYNCHRONe_C_Code_10.7, SYNCHRONe_C_Code_11.1> No precision lost: affect value to just a part of the variable (see the structure to better understand) */
			*(volatile uint8_t *)&(P_I2C_RegAddress[v_devID].i2cdr.R) = ((uint8_t)(v_slave_adress << (uint8_t)1) | (uint8_t)1);   /* Device address read */
			/* }} RELAX<SYNCHRONe_C_Code_10.7, SYNCHRONe_C_Code_11.1> */

			/* Wait EOT */
			v_errorCode = LIBBSP_I2C_WaitEndOfTransmission(C_I2C_150_MICRO_S, &(P_I2C_RegAddress[v_devID].i2csr)); /* %RELAX<SYNCHRONe_C_Code_10.7> No precision lost */

			if (v_errorCode == E_LIBBSP_I2C_OK)
			/* Set receive mode */
			{
				LIBBSP_I2C_ReceiveMode(v_devID, v_size, pa_buffer, &v_errorCode);
			}
			else
			{
				/* Free I2C bus STOP */
				P_I2C_RegAddress[v_devID].i2ccr.I2CCR.MSTA = (uint8_t)0;
				/* Reset/disable device */
				P_I2C_RegAddress[v_devID].i2ccr.I2CCR.MEN = (uint8_t)0;
			}
		}
		else
		{
			/* The bus is not free */
			v_errorCode = E_LIBBSP_I2C_BUS_BUSY;
		}

    }

    /* Reset/disable device */
    P_I2C_RegAddress[v_devID].i2ccr.I2CCR.MEN = (uint8_t)0;


    return v_errorCode; /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
}
/* }} RELAX<SYNCHRONe_C_Code_17.4> */
/*==== END =============================================================================*/
