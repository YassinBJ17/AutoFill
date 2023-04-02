/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_I2C_Reset.h"


/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

/* {{RELAX<SYNCHRONe_C_Code_17.4> Use of pointer array indexing :can't guess the size of the memory */

TE_LIBBSP_I2C_Code LIBBSP_I2C_Reset(const TE_LIBBSP_I2C_Bus v_devID)
{
	/* var used for the erreor return */
    TE_LIBBSP_I2C_Code v_ret;

	/* initialization of the return */
	v_ret = E_LIBBSP_I2C_OK;

    if (v_devID >= E_LIBBSP_I2C_NB_I2C_BUS)
	{
        v_ret = E_LIBBSP_I2C_INVALID_ID;
	}
	else
	{
	   P_I2C_RegAddress[v_devID].i2ccr.I2CCR.MSTA = (uint8_t)1;

	   v_ret = LIBBSP_I2C_WaitEndOfTransmission(C_I2C_150_MICRO_S, &(P_I2C_RegAddress[v_devID].i2csr)); /* %RELAX<SYNCHRONe_C_Code_10.7> No precision lost */

	   P_I2C_RegAddress[v_devID].i2ccr.I2CCR.MSTA = (uint8_t)0;

	   v_ret = LIBBSP_I2C_WaitEndOfTransmission(C_I2C_150_MICRO_S, &(P_I2C_RegAddress[v_devID].i2csr)); /* %RELAX<SYNCHRONe_C_Code_10.7> No precision lost */
	}
    return v_ret; /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
}
/* }} RELAX<SYNCHRONe_C_Code_17.4> */
/*==== END =============================================================================*/
