/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_TEMP_Close.h"

/*==== Definitions =====================================================================*/

/*==== Types ===========================================================================*/

/*==== SERVICES ========================================================================*/

TE_LIBBSP_I2C_Code LIBBSP_TEMP_Close(void)
{
   TE_LIBBSP_I2C_Code v_rc;

   v_rc = E_LIBBSP_I2C_CLOSED;

   if (V_TEMP_TMP451_State == E_TMP451_OPEN)
   {
      V_TEMP_TMP451_State = E_TMP451_CLOSED;
      v_rc = LIBBSP_I2C_Close(C_TEMP_TMP451_USED_BUS);
   }

   return (v_rc); /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
}
