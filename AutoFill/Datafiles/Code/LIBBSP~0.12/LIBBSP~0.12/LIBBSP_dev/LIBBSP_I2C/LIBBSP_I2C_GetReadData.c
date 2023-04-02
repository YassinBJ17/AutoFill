/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_I2C_GetReadData.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

TE_LIBBSP_I2C_ErrorCode LIBBSP_I2C_GetReadData(	const TE_LIBBSP_I2C_Bus v_devID,
					const uint32_t v_size,
					uint8_t * const pa_buffer)
{
	TE_LIBBSP_I2C_ErrorCode v_errorCode = E_LIBBSP_I2C_COMMAND_TAKEN;
	uint32_t v_i;


	if ( v_devID >= E_LIBBSP_I2C_NB_I2C_BUS )
	{
		v_errorCode = E_LIBBSP_I2C_COMMAND_NOT_TAKEN;
	}
	else if(v_size > C_I2C_NB_BYTE_MAX)
	{
		v_errorCode = E_LIBBSP_I2C_READ_OVERSIZED;
	}
	else
	{
		for (v_i = 0ul; v_i<v_size; v_i++)
		{
			pa_buffer[v_i] = V_I2C_BuffRead[v_devID][v_i];/* %RELAX<SYNCHRONe_C_Code_17.4> Use of pointer array indexing :can't guess the size of the memory */

		}
	}

    return v_errorCode; /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
}

/*==== END =============================================================================*/
