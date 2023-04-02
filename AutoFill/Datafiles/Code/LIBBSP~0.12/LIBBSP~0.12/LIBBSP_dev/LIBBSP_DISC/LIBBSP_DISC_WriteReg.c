/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_DISC_WriteReg.h"

/*==== Definitions =====================================================================*/

/*==== Variables ===========================================================================*/

/*==== SERVICES ========================================================================*/

TE_LIBBSP_I2C_Code LIBBSP_DISC_WriteReg(const uint8_t v_slave_address, const TE_LIBBSP_DISC_Max7312RegAddr RegAddr, const uint8_t v_val)
{
	TE_LIBBSP_I2C_Code v_ret;
	uint8_t v_buf[C_DISC_NB_BUFF];

   v_buf[0] = (uint8_t)RegAddr; /* %RELAX<SYNCHRONe_C_Code_10.7> No precision lost: Enum max value is 8, uint8 max is 255 */
   v_buf[1] = v_val;

   v_ret = LIBBSP_I2C_Write(C_DISC_MAX7312_USED_BUS,
                           v_slave_address,
                           C_DISC_NB_BUFF,
                           &v_buf[0]);


	return (v_ret); /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
}
