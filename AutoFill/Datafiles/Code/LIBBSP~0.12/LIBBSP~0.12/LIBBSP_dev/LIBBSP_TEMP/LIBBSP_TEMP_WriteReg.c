/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_TEMP_WriteReg.h"

/*==== Definitions =====================================================================*/
/*==== Variables ===========================================================================*/

/*==== SERVICES ========================================================================*/

TE_LIBBSP_I2C_Code LIBBSP_TEMP_WriteReg(const TE_LIBBSP_TEMP_WriteRegAddr RegAddr, const uint8_t v_val)
{
   TE_LIBBSP_I2C_Code v_ret;
   uint8_t v_buf[C_TEMP_NB_BUFF];
   
   v_buf[0] = (uint8_t)RegAddr; /* %RELAX<SYNCHRONe_C_Code_10.7> There is no loss of precision because TE_LIBBSP_TEMP_WriteRegAddr is on 8bit*/
   v_buf[1] = v_val;
   
   v_ret = LIBBSP_I2C_Write(C_TEMP_TMP451_USED_BUS,
                            C_TEMP_TMP451_ADDRESS,
                            C_TEMP_NB_BUFF,
                            &v_buf[0]);
   
   return (v_ret); /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
}
