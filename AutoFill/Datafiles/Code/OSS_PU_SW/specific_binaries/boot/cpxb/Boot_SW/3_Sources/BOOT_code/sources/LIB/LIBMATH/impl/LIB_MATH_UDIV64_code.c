/* --------------------------------------------------------------------------
 *                           Sagem Defense Securite
 *                               SAFRAN Group
 * --------------------------------------------------------------------------
 * PROJECT : CHRONOS_MOCKUP
 * CSU name :
 * %name: LIB_MATH_UDIV64_code.c %
 * %full_name: fadex#3/csrc/LIB_MATH_UDIV64_code.c/1 %
 * DESCRIPTION : short description of the operations of the .c file
 *
 * Creation information:
 *   Created by: F073297
 *   Date : Thu Jan 31 18:12:19 CET 2019
 *
 * Modification information:
 *   %derived_by: F605763 %
 *   %date_created:Thu May 12 18:19:03 CEST 2022 %
 * --------------------------------------------------------------------------
 * SAGEM Defense Securite document. Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "LIB_MATH_public.h"

/* ---------- include required interface: ----------------------------------- */
/* LPOS Common Interface */
#include "CMN_TYPES_common.h"

/* LPOS Public Interface */
/* none */

/* LPOS Private Interface */
/* none */

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */
/* none */

/* ---------- internal operations: ------------------------------------------ */
/* none */

/* ---------- internal constants: ------------------------------------------- */
/* none */

/* ---------- internal data: ------------------------------------------------ */
/* none */

/* ---------- provided operation bodies: ------------------------------------ */


/*                                                                            */
/* FUNCTION:    LIB_MATH_UDIV64                                               */
/*                                                                            */
/* BRIEF: Computation of the division for two unsigned integer defined on     */
/*        64 bits                                                             */
/* DESCRIPTION: This function computes the division for two unsigned integer  */
/*              defined on 64 bits.                                           */
/*              The first action is to check is divisor v_high part is not      */
/*              equal to 0, in that case the division is simplified because   */
/*              division can be computed with a divisor defined on 32 bits.   */
/*              If v_high part of divisor is not Null, the divisor and the      */
/*              dividend will be simplified by dividing them by               */
/*              2^(most significant bit of divisor) and then compute the      */
/*              division ith a divisor defined on 32 bits.                    */
/*              At last, if ratio is not null, it shall be decremented in     */
/*              order to check if computed remainder isn't greater than the   */
/*              divisor. In this last case, ratio shall be incremented by one */
/*              to have the correct value.                                    */
/*                                                                            */
/* RETURNED TYPE: uint64_t                                           */
/*                                                                            */
/* PARAMETERS: p_dividend of type uint64_t                           */
/*             p_divisor of type uint64_t                            */
/*                                                                            */
/* GLOBALS Inputs: None                                                       */
/*                                                                            */
/* GLOBALS Outputs: None                                                      */
/*                                                                            */
/* CALLS: div_u64                                                             */
/*        fls                                                                 */
/*                                                                            */
/* EXTERNAL CALLS: None                                                       */
/*                                                                            */
/* PRECONDITIONS: None                                                        */
/*                                                                            */
uint64_t LIB_MATH_UDIV64( uint64_t const p_dividend,
                          uint64_t const p_divisor)
{
   /* */
   uint32_t v_high ;
   uint64_t v_quot ;
   uint32_t v_shift ;
   uint64_t v_valueResult ;
   uint32_t v_paramDivisor ;
   uint64_t v_paramDividend ;

   /* Get the v_high part of the divisor */
   /* >RELAX<SYNCHRONe_C_Code_10.7> the result is coded on 32 bits. */
   v_high = (uint32_t) ( p_divisor >> C_32_MSB_ULL ) ;

   /* Check if divisor v_high part is equal to 0 */
   if ( v_high == 0ul )
   {
      /* then the division is simplified, dividing only by a 32bits integer */
      /* >RELAX<SYNCHRONe_C_Code_10.7> the p_divisor value is coded on 32 bits (tested before). The cast is secure. */
      v_quot = LIB_MATH_UDIV64_DIV_U64 ( p_dividend , (uint32_t) p_divisor ) ;
   }
   else
   {
      /* get the last most-significant bit */
      v_shift = (uint32_t) ( LIB_MATH_UDIV64_FLS ( v_high ) ) ;
      v_shift = 1ul + v_shift ;

      /* Compute reduced dividend and reduced divisor */
      v_paramDividend = LIB_MATH_UDIV64_LSR64 ( p_dividend ,
                                                  v_shift ) ;
      /* >RELAX<SYNCHRONe_C_Code_10.7> The result is coded on 32 bits, as the parameter given in the function is
       *  the value and its corresponding last most-significant bit. */
      v_paramDivisor = (uint32_t) ( LIB_MATH_UDIV64_LSR64 ( p_divisor , v_shift ) ) ;

      /* do the division with reduced parameters */
      v_quot = LIB_MATH_UDIV64_DIV_U64 ( v_paramDividend ,
                                         v_paramDivisor ) ;

      /* Check if v_result of division isn't NULL */
      if ( v_quot != 0ull )
      {
         /* decrement the v_result by one */
         v_quot-- ;
      }
      else
      /* >RELAX<SYNCHRONe_C_Code_14.2> : the value v_l_quot is equal to 0, the smallest value possible.  */
      {
         /* do nothing */
      }

      /* Compute the remainder */
      v_valueResult = ( p_dividend - ( v_quot * p_divisor ) ) ;

      /* Check if remainder is greater or equal than the divisor */
      if ( v_valueResult >= p_divisor )
      {
         /* increment the v_result by one */
         v_quot++ ;
      }
      else
      /* >RELAX<SYNCHRONe_C_Code_14.2> : the result of the division is less than the divisor, so the quotient is correct. */
      {
         /* do nothing */
      }
   }

   return v_quot ;
}
