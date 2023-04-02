/* ---------- include provided interface: ----------------------------------- */
#include "LIB_MATH_public.h"

/* ---------- include required interface: ----------------------------------- */
/* LPOS Common Interface */
#include "CMN_TYPES_common.h"
/*                                                                            */
/* FUNCTION: div64_32                                                         */
/*                                                                            */
/* BRIEF: Compute the real division of a 64 bits unsigned integer by a        */
/*        32 bits unsigned integer                                            */
/*                                                                            */
/* DESCRIPTION: This function computes the division of a 64 bits unsigned     */
/*              integer by a 32 bits unsigned integer by successive additions */
/*              and substractions.                                            */
/*                                                                            */
/* RETURNED TYPE: uint32_t                                                */
/*                                                                            */
/* PARAMETERS: p_pa_n of type uint64_t                                 */
/*             p_base of type uint32_t                                    */
/*                                                                            */
/* GLOBALS Inputs: None                                                       */
/*                                                                            */
/* GLOBALS Outputs: None                                                      */
/*                                                                            */
/* CALLS: None                                                                */
/*                                                                            */
/* EXTERNAL CALLS: None                                                       */
/*                                                                            */
/* PRECONDITIONS: p_base is no equal to 0                                     */
/*                                                                            */
uint32_t LIB_MATH_UDIV64_DIV64_32( uint64_t * const p_pa_n,
                                   uint32_t const p_base)
{
   uint64_t v_remainder ;
   uint64_t v_base ;
   uint64_t v_result ;
   uint64_t v_d ;
   uint32_t v_high ;

   v_remainder = *p_pa_n ;
   v_base = (uint64_t) ( p_base ) ;
   v_d = 1ull ;
   /* >RELAX<SYNCHRONe_C_Code_10.7> the result is coded on 32 bits. */
   v_high = (uint32_t) ( v_remainder >> C_32_MSB_ULL ) ;

   v_result = 0ull ;

   /* Check if v_high part of dividend is greater or equal than the dividend */
   if ( v_high >= p_base )
   {
      /* Reduce the v_high part */
      v_high = v_high / p_base ;
      /* Compute v_high part of the v_result */
      v_result = ( (uint64_t) v_high ) << C_32_MSB_ULL ;

      /* Compute the remainder */
      v_remainder = v_remainder - ( ( ( (uint64_t) v_high ) * ( (uint64_t) p_base ) ) << C_32_MSB_ULL ) ;
   }
   else
   /* >RELAX<SYNCHRONe_C_Code_14.2> : the v_high is ready to be used. */
   {
      /* do nothing */
   }

   /* while the base is positive and is less than the remainder */
   /* >RELAX<SYNCHRONe_C_Code_10.7> the cast in signed is wanted in order to identify if the MSB bit is set. */
   while ( ( (int64_t) v_base > 0ll ) && ( v_base < v_remainder ) )
   {
      /* Increment the base and divisor */
      v_base = v_base + v_base ;
      v_d = v_d + v_d ;
   }

   do
   {
      /* Check if remainder is greater or equal than the base */
      if ( v_remainder >= v_base )
      {
         /* Substract the base to the remainder */
         v_remainder = v_remainder - v_base ;

         /* increment the v_result with the divisor */
         v_result = v_result + v_d ;
      }
      else 
      /* >RELAX<SYNCHRONe_C_Code_14.2> : the v_remainder is ready to be used. */
      {
         /* do nothing */
      }

      /* Divide the base and the divisor by 2 */
      v_base = v_base >> 1ull ;
      v_d = v_d >> 1ull ;
   }
   /* while divisor is not null */
   while ( v_d != 0ull ) ;

   *p_pa_n = v_result ;

   /* >RELAX<SYNCHRONe_C_Code_10.7> : the remainder is less than the dividend with is a uint32_t. */
   return (uint32_t) v_remainder ;
}
