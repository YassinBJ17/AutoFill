/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_DISC_GetReadDisc.h"

/*==== Definitions =====================================================================*/
const uint32_t C_DISC_SHIFT_8_BITS = 8;

/*==== Variables ===========================================================================*/

/*==== SERVICES ========================================================================*/

uint16_t LIBBSP_DISC_GetReadDisc(void)
{
	TE_LIBBSP_I2C_ErrorCode v_ret;
	uint16_t v_read_disc;
	uint8_t v_buf_data[C_DISC_NB_BUFF];

	v_read_disc = (uint16_t)0;

	v_ret = LIBBSP_I2C_GetReadData(C_DISC_MAX7312_USED_BUS,C_DISC_NB_BUFF,&v_buf_data[0]);

	if (v_ret == E_LIBBSP_I2C_COMMAND_TAKEN)
	{
		v_read_disc = (uint16_t)(v_buf_data[0]) + (uint16_t)(((uint16_t)(v_buf_data[1])) << C_DISC_SHIFT_8_BITS);

	}

	return v_read_disc;

}
