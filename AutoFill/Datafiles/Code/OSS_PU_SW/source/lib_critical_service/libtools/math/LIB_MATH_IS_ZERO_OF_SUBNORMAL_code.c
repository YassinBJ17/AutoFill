/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : <short description of the operations of the .c file>
 * -------------------------------------------------------------------------- */

#include "type/common_type.h"
#include "libtools/math/LIB_MATH_public.h"

/*-------------------------------------------------------------------------------------------------------------------*/
/* Function: LIB_MATH_IS_ZERO_OR_SUBNORMAL                                                                           */
/*-------------------------------------------------------------------------------------------------------------------*/
/* Description: Indicates if the argument is 0.0 or Subnormal, that is to say exponent equals to 1                   */
/*                                                                                                                   */
/* Pre-condition:  none                                                                                              */
/*                                                                                                                   */
/* Input: p_input : input value to evaluate                                                                          */
/* Output: none                                                                                                      */
/* Return: v_is_zero_or_subnormal : e_CMN_FLAG_VALID if argument is 0.0 or Subnormal, e_CMN_FLAG_NOT_VALID otherwise.*/
/*-------------------------------------------------------------------------------------------------------------------*/
te_CMN_FLAG_VALIDITY LIB_MATH_IS_ZERO_OR_SUBNORMAL(const float32_t p_input)
{
   /* Declarations */
   tu_CMN_BITFIELD      v_input;
   te_CMN_FLAG_VALIDITY v_is_zero_or_subnormal;

   /* Initializations */
   v_input.u_word = p_input;
   v_is_zero_or_subnormal = e_CMN_FLAG_NOT_VALID;

   /* Statements */
   /* >RELAX<SYNCHRONe_C_Code_10.7> No loss of precision, C_MASK_BITS and C_EXPON_VAL_FOR_SUBNORMAL_NUM are on 16 bits*/
   if ( ( v_input.u_word_bitfield.s_HIGH_FIELD & ((reg16_t)C_MASK_BITS) ) < ( (uint16_t)C_EXPON_VAL_FOR_SUBNORMAL_NUM ) )
   {
      v_is_zero_or_subnormal = e_CMN_FLAG_VALID;
   }
   return ( v_is_zero_or_subnormal );
}
