/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_TEMP_ReadTemp.h"

/*==== Definitions =====================================================================*/

/*==== Types ===========================================================================*/

/*==== SERVICES ========================================================================*/

void LIBBSP_TEMP_ReadTemp(const TE_LIBBSP_TEMP_ReadRegAddr v_reg ,TE_LIBBSP_I2C_CurrentStep const v_step_in, TE_LIBBSP_I2C_CurrentStep* const v_step_out, TE_LIBBSP_I2C_ErrorCode * const v_ret)
{
   uint8_t v_buf;
   
   *v_step_out = v_step_in;
   
   if ( V_TEMP_TMP451_State != E_TMP451_OPEN )
   {
      *v_ret = E_LIBBSP_I2C_COMMAND_NOT_TAKEN;
   }
   else
   {
      /* prog the address */
      v_buf = (uint8_t)v_reg; /* %RELAX<SYNCHRONe_C_Code_10.7> There is no loss of precision because TE_LIBBSP_TEMP_ReadRegAddr is on 8bit*/
      *v_ret = LIBBSP_I2C_WriteNoWait(C_TEMP_TMP451_USED_BUS, C_TEMP_TMP451_ADDRESS, 1ul, &v_buf, v_step_out);
      V_TEMP_Cmd = E_LIBBSP_TEMP_CMD_READ;
   }
}


