/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_I2C_WaitEndOfTransmission.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

TE_LIBBSP_I2C_Code LIBBSP_I2C_WaitEndOfTransmission(const uint32_t v_timeout,
								 volatile TS_LIBBSP_I2C_Register * const p_reg)
{
    uint32_t v_timer;
    TE_LIBBSP_I2C_Code v_ret;

	v_ret = E_LIBBSP_I2C_OK;

    v_timer = v_timeout;

	while (	((p_reg->I2CSR.MIF)  == (uint8_t)0) &&
			(v_ret == E_LIBBSP_I2C_OK) )
	{
        	if ( LIBBSP_CMN_isElapsed(&v_timer) != 0ul)
			{
				v_ret = E_LIBBSP_I2C_TIMEOUT;
			}
			else
			{
				/* NOTHING TO DO */
			}

    }
	if (v_ret == E_LIBBSP_I2C_OK)
	{
		p_reg->I2CSR.MIF = (uint8_t)0;
	}
	else
	{
		/* NOTHING TO DO */
	}
    return v_ret; /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
}

/*==== END =============================================================================*/
