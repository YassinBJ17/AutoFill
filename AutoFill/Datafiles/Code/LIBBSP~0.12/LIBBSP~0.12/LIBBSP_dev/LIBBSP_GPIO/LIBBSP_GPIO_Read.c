/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_GPIO_Read.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

boolean_t LIBBSP_GPIO_Read( const TE_LIBBSP_GPIO_DiscName GPIO)
{

   boolean_t v_State;

   if ((V_GPIOReg->GPDAT & (uint16_t)GPIO) !=  (uint16_t)0) /* %RELAX<SYNCHRONe_C_Code_10.7> No precision lost: Enum maximum value is 32768 (uint16 max is 65535) */
   {
      v_State = TRUE;
   }
   else
   {
      v_State = FALSE;
   }

   return v_State;
}



/*==== END =============================================================================*/
