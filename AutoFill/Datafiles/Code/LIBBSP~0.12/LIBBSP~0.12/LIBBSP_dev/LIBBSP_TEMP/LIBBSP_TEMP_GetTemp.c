/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_TEMP_GetTemp.h"

/*==== Definitions =====================================================================*/
/*==== Types ===========================================================================*/

/*==== SERVICES ========================================================================*/

float64_t LIBBSP_TEMP_GetTemp( void )
{
   float64_t v_ReadTemp;
   TE_LIBBSP_I2C_ErrorCode v_ret;
   uint8_t v_buf_data[C_TEMP_NB_BUFF_GET_TEMP];
   int32_t v_temperature;
   
   v_ReadTemp = (float64_t)0.0;
   
   v_ret = LIBBSP_I2C_GetReadData(C_TEMP_TMP451_USED_BUS,C_TEMP_NB_BUFF_GET_TEMP,&v_buf_data[0]);
   
   if (v_ret == E_LIBBSP_I2C_COMMAND_TAKEN)
   {
      v_temperature = ((int32_t)(v_buf_data[0])) + C_DELTA;
      v_ReadTemp = (float64_t)(v_temperature); /* %RELAX<SYNCHRONe_C_Code_10.7> No precision lost */
   }
   return v_ReadTemp;
}
