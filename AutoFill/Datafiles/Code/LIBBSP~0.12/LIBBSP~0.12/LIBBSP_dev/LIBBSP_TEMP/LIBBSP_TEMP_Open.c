/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_TEMP_Open.h"

/*==== Definitions =====================================================================*/

/*==== Types ===========================================================================*/


/*==== SERVICES ========================================================================*/


TE_LIBBSP_I2C_Code LIBBSP_TEMP_Open(void)
{
   TE_LIBBSP_I2C_Code v_rc;

   V_TEMP_TMP451_State = E_TMP451_CLOSED;
   V_TEMP_Cmd = E_LIBBSP_TEMP_CMD_IDLE;
  
   /* open the link */
   v_rc = LIBBSP_I2C_Open(C_TEMP_TMP451_USED_BUS,
                          C_TEMP_TMP451_DIGITAL_FILTER,
                          C_TEMP_TMP451_DIVISOR_VALUE );
   
   if ( v_rc == E_LIBBSP_I2C_OK )
   {
      V_TEMP_TMP451_State = E_TMP451_OPEN;
   }
   
   return (v_rc); /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
}
