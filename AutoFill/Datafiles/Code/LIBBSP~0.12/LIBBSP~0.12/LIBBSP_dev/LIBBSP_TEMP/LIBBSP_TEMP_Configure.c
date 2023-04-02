/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_TEMP_Configure.h"

/*==== Definitions =====================================================================*/


/*==== Types ===========================================================================*/

/*==== SERVICES ========================================================================*/

TE_LIBBSP_I2C_Code LIBBSP_TEMP_Configure(void)
{
   TE_LIBBSP_I2C_Code v_ret;
   uint32_t v_index;
   
   if ( V_TEMP_TMP451_State != E_TMP451_OPEN )
   {
      v_ret = E_LIBBSP_I2C_CLOSED;
   }
   else
   {
      v_ret = E_LIBBSP_I2C_OK;
      v_index = (uint32_t)0;
      
      while ( (v_index < (uint32_t)C_TEMP_NB_TMP451_CONF) && (v_ret == E_LIBBSP_I2C_OK ))
      {
         v_ret = LIBBSP_TEMP_WriteReg(C_TEMP_TMP451_CONF[v_index].v_reg, C_TEMP_TMP451_CONF[v_index].v_data);
         v_index += (uint32_t)1 ;
      }
   }
   
   return v_ret;
}


