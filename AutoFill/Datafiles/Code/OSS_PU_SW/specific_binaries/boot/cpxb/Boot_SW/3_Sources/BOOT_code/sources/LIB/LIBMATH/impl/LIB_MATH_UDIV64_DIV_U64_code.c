/* ---------- include provided interface: ----------------------------------- */
#include "LIB_MATH_public.h"

/* ---------- include required interface: ----------------------------------- */
/* LPOS Common Interface */
#include "CMN_TYPES_common.h"

/*                                                                            */
/* FUNCTION: div_u64                                                          */
/*                                                                            */
/* BRIEF: Call the division of 64 bits data by 32 bits data                   */
/*                                                                            */
/* DESCRIPTION: This function call the division of 64 bits unsigned integer   */
/*              by a 32 bits unsigned integer.                                */
/*                                                                            */
/* RETURNED TYPE: uint64_t                                           */
/*                                                                            */
/* PARAMETERS: p_dividend of type uint64_t                           */
/*             p_divisor of type uint32_t                                 */
/*                                                                            */
/* GLOBALS Inputs: None                                                       */
/*                                                                            */
/* GLOBALS Outputs: None                                                      */
/*                                                                            */
/* CALLS: div_u64_rem                                                         */
/*                                                                            */
/* EXTERNAL CALLS: None                                                       */
/*                                                                            */
/* PRECONDITIONS: None                                                        */
/*                                                                            */
uint64_t LIB_MATH_UDIV64_DIV_U64( uint64_t const p_dividend,
                                  uint32_t const p_divisor )
{
   uint32_t v_l_remainder ;
   uint64_t v_l_result ;

   /* Compute the division with remainder */
   v_l_result = LIB_MATH_UDIV64_DIV_U64_REM ( p_dividend ,
                                                p_divisor ,
                                                &v_l_remainder ) ;
   return v_l_result ;
}


