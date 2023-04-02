/* ---------- include provided interface: ----------------------------------- */
#include "LIB_MATH_public.h"

/* ---------- include required interface: ----------------------------------- */
/* LPOS Common Interface */
#include "CMN_TYPES_common.h"


/*                                                                            */
/* FUNCTION: div_u64_rem                                                      */
/*                                                                            */
/* BRIEF: Simplify computation the division of 64 bits data by 32 bits data   */
/*                                                                            */
/* DESCRIPTION: This function simplifies the computation of the division,     */
/*              by first checking is dividend v_high part is null.              */
/*              In that case the division is only a 32 bits data division.    */
/*              If v_high part of dividend is not null,then call the function   */
/*              div64_32 in order to really compute the division.             */
/*                                                                            */
/* RETURNED TYPE: uint64_t                                           */
/*                                                                            */
/* PARAMETERS: p_dividend of type uint64_t                           */
/*             p_divisor of type  uint32_t                                */
/*             p_pa_remainder of type  uint32_t                             */
/*                                                                            */
/* GLOBALS Inputs: None                                                       */
/*                                                                            */
/* GLOBALS Outputs: None                                                      */
/*                                                                            */
/* CALLS: div64_32                                                            */
/*                                                                            */
/* EXTERNAL CALLS: None                                                       */
/*                                                                            */
/* PRECONDITIONS: p_divisor is no equal to 0                                  */
/*                                                                            */
uint64_t LIB_MATH_UDIV64_DIV_U64_REM(uint64_t const p_dividend,
                                     uint32_t const p_divisor,
                                     uint32_t * const p_pa_remainder)
{
   uint32_t v_rem ;
   uint64_t v_dividendInternal ;

   v_dividendInternal = p_dividend ;

   /* Check if v_high part of dividend is full of 0 */
   /* >RELAX<SYNCHRONe_C_Code_10.7> the result of the extract of the 32 MSB bits is coded on 32 bits.  */
   if ( (uint32_t) ( v_dividendInternal >> C_32_MSB_ULL ) == 0ul )
   {
      /* compute remainder and division with only 32 bits integer */
      /* {{RELAX<SYNCHRONe_C_Code_10.7> the value v_l_dividendInternal is coded on 32 bits (has been tested previously).  */
      v_rem = (uint32_t) ( v_dividendInternal ) % p_divisor ;
      /* >RELAX<SYNCHRONe_C_Code_10.3> the value v_l_dividendInternal is coded on 32 bits (has been tested previously). */
      v_dividendInternal = (uint64_t) ( (uint32_t) ( v_dividendInternal ) / p_divisor ) ;
      /* }}<SYNCHRONe_C_Code_10.7> */
   }
   else
   {
      /* do the division with call to LIB_MATH_UDIV64_L_div64_32 */
      v_rem = LIB_MATH_UDIV64_DIV64_32 ( & ( v_dividendInternal ) ,
                                             p_divisor ) ;
   }

   *p_pa_remainder = v_rem ;
   return v_dividendInternal ;
}