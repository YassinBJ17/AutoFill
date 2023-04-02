/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_GPIO_Write.h"

/*==== Definitions =====================================================================*/
/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

TE_LIBBSP_GPIO_Status LIBBSP_GPIO_Write( const TE_LIBBSP_GPIO_DiscName GPIO, const boolean_t State)
{
   TE_LIBBSP_GPIO_Status v_ret;
   uint16_t v_mask;

   /* check if the GPIO given in argument is configured as an output*/
   if ((V_GPIOReg->GPDIR & (uint16_t)GPIO) !=  (uint16_t)0) /* %RELAX<SYNCHRONe_C_Code_10.7> No precision lost: Enum maximum value is 32768 (uint16 max is 65535) */
   {
      /* Set the GPIO according to the given State */
      if (State != FALSE)
      {
         V_GPIOReg->GPDAT = V_GPIOReg->GPDAT | (uint16_t)GPIO; /* %RELAX<SYNCHRONe_C_Code_10.7> No precision lost: Enum maximum value is 32768 (uint16 max is 65535) */
      }
      else
      {
         /* The operand "~GPIO" give a result on 32 bits instead of 16.*/
         /* For correct operation : keep the usefull part and cast the result in 16 bits */
         v_mask = (uint16_t)(~GPIO) & C_GPIO_MASK; /* %RELAX<SYNCHRONe_C_Code_10.7> No precision lost: Enum whose maximum value is 32768 (uint16 max is 65535) */
         V_GPIOReg->GPDAT = V_GPIOReg->GPDAT & v_mask ;
      }

      v_ret = E_LIBBSP_GPIO_SUCCEEDED;
   }
   else
   {

	   v_ret = E_LIBBSP_GPIO_FAILED;
   }
   return v_ret; /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
}
/*==== END =============================================================================*/
