/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_I2C_Open.h"

/*==== Definitions =====================================================================*/


/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

/* {{RELAX<SYNCHRONe_C_Code_17.4> Use of pointer array indexing :can't guess the size of the memory */
TE_LIBBSP_I2C_Code LIBBSP_I2C_Open(const TE_LIBBSP_I2C_Bus v_devID,
				const uint8_t v_digital_filter,
				const TE_LIBBSP_I2C_FreqDiv v_divider )
{

   volatile TS_LIBBSP_I2C_Register v_reg;
	uint32_t v_i;

	/* var used for the erreor return */
    TE_LIBBSP_I2C_Code v_ret;

	/* initialization of the return */
	v_ret = E_LIBBSP_I2C_OK;

    if (v_devID >= E_LIBBSP_I2C_NB_I2C_BUS)
	{
        v_ret = E_LIBBSP_I2C_INVALID_ID;
	}
	else if(V_I2C_State[v_devID] == E_LIBBSP_I2C_BUS_CLOSED)
	{
		/*initialization of global*/
		for (v_i = 0ul; v_i<C_I2C_NB_BYTE_MAX; v_i++)
		{
			V_I2C_BuffWrite[v_devID][v_i] = (uint8_t)0;
			V_I2C_BuffRead[v_devID][v_i] = (uint8_t)0;
		}

		V_I2C_WriteSize[v_devID] = 0ul;
		V_I2C_WriteIndex[v_devID] = 0ul;

		V_I2C_ReadSize[v_devID] = 0ul;
		V_I2C_ReadIndex[v_devID] = 0ul;

		/* change the state of the bus */
		V_I2C_State[v_devID] = E_LIBBSP_I2C_BUS_OPEN;

		/* intialisation of the registers */

		P_I2C_RegAddress[v_devID].i2ccr.I2CCR.MEN = (uint8_t)0; /*reinit*/
		P_I2C_RegAddress[v_devID].i2cdfsrr.I2CDFSRR.DFSR = v_digital_filter; /*0x10;  digital filter*/
		P_I2C_RegAddress[v_devID].i2cfdr.I2CFDR.FDR = (uint8_t)v_divider; /*E_I2C_DIV_1024; Set frequency divider */ /* %RELAX<SYNCHRONe_C_Code_10.7> No precision lost: type of the value is an enum with a max value of 63 (uint8 -> 255 max) */
		P_I2C_RegAddress[v_devID].i2cadr.I2CADR.ADDR = (uint8_t)0;


		/* Control register to default value */
		v_reg.R = P_I2C_RegAddress[v_devID].i2ccr.R;
		v_reg.I2CCR.MEN  = (uint8_t)1;   /* Enable device */
		v_reg.I2CCR.MSTA = (uint8_t)0;   /* Slave mode while not transmitting */
		v_reg.I2CCR.MIEN = (uint8_t)0;   /* No interrupt */
		v_reg.I2CCR.MTX  = (uint8_t)0;   /* Receive mode by default */
		v_reg.I2CCR.TXAK = (uint8_t)0;   /* Send an acknowledge after receiving one byte of data */
		v_reg.I2CCR.BCST = (uint8_t)0;

		/* Write control register value */
		P_I2C_RegAddress[v_devID].i2ccr.I2CREG.u8 = v_reg.I2CREG.u8;

	}
	else
	{
		v_ret = E_LIBBSP_I2C_BUS_BUSY;
	}
   return v_ret; /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
}
/* }} RELAX<SYNCHRONe_C_Code_17.4> */
/*==== END =============================================================================*/
