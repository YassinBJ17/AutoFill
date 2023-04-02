/* ---------- include provided interface: ----------------------------------- */
#include "LIB_MATH_public.h"

/* ---------- include required interface: ----------------------------------- */
/* LPOS Common Interface */
#include "CMN_TYPES_common.h"

/* ---------- internal operation bodies: ------------------------------------ */


/*                                                                            */
/* FUNCTION: fls                                                              */
/*                                                                            */
/* BRIEF: Get the most significant bit of a 32 bits data                      */
/*                                                                            */
/* DESCRIPTION: This function returns the index of the most-significant bit   */
/*              of 32 bits data by successive comparisons and shifts.         */
/*                                                                            */
/* RETURNED TYPE: int32_t                                                     */
/*                                                                            */
/* PARAMETERS: p_data of type uint32_t                                        */
/*                                                                            */
/* GLOBALS Inputs: None                                                       */
/*                                                                            */
/* GLOBALS Outputs: None                                                      */
/*                                                                            */
/* CALLS: None                                                                */
/*                                                                            */
/* EXTERNAL CALLS: None                                                       */
/*                                                                            */
/* PRECONDITIONS: None                                                        */
/*                                                                            */
uint32_t LIB_MATH_UDIV64_FLS(uint32_t const p_data)
{
   uint32_t v_result ;
   uint32_t v_data ;

   v_result = C_32_MSB_UL ;

   /* Check Data is null, ie. equal to 0 */
   if ( p_data == 0ul )
   {
      v_result = 0ul ;
   }
   else
   {
      v_data = p_data ;

      /* Check if data has bit raised in 16 most significant bits */
      if ( ( v_data & C_MASK_16_MSB_ON_32 ) == 0ul )
      {
         v_data = v_data << C_16_MSB_UL ;
         v_result = v_result - C_16_MSB_UL ;
      }
      else 
      /* >RELAX<SYNCHRONe_C_Code_14.2> : the input is at least coded on 17 bits. so no modification of the higher index MSB value. */
      {
         /* do nothing */
      }

      /* Check if data has bit raised in 8 most significant bits */
      if ( ( v_data & C_MASK_8_MSB_ON_32 ) == 0ul )
      {
         v_data = v_data << C_8_MSB_UL ;
         v_result = v_result - C_8_MSB_UL ;
      }
      else 
      /* >RELAX<SYNCHRONe_C_Code_14.2> : the input is at least coded on 25 bits. so no modification of the higher index MSB value. */
      {
         /* do nothing */
      }

      /* Check if data has bit raised in 4 most significant bits */
      if ( ( v_data & C_MASK_4_MSB_ON_32 ) == 0ul )
      {
         v_data = v_data << C_4_MSB_UL ;
         v_result = v_result - C_4_MSB_UL ;
      }
      else 
      /* >RELAX<SYNCHRONe_C_Code_14.2> : the input is at least coded on 29 bits. so no modification of the higher index MSB value. */
      {
         /* do nothing */
      }

      /* Check if data has bit raised in 4 most significant bits */
      if ( ( v_data & C_MASK_2_MSB_ON_32 ) == 0ul )
      {
         v_data = v_data << C_2_MSB_UL ;
         v_result = v_result - C_2_MSB_UL ;
      }
      else 
      /* >RELAX<SYNCHRONe_C_Code_14.2> : the input is at least coded on 31 bits. so no modification of the higher index MSB value. */
      {
         /* do nothing */
      }

      /* Check if data has its most significant bit raised*/
      if ( ( v_data & C_MASK_MSB_ON_32 ) == 0ul )
      {
         v_result = v_result - C_MSB_UL ;
      }
      else 
      /* >RELAX<SYNCHRONe_C_Code_14.2> : the input is coded on 32 bits. so no modification of the higher index MSB value. */
      {
         /* do nothing */
      }

   }
   return v_result ;
}