/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : <short description of the operations of the .c file>
 * -------------------------------------------------------------------------- */

#include "type/common_type.h"
#include "libtools/math/LIB_MATH_public.h"

/*--------------------------------------------------------------------------- */
/* Function: LIB_MATH_IS_INF                                                  */
/*--------------------------------------------------------------------------- */
/* Description: Indicates if the argument is equal to +Inf or -Inf.           */
/*                                                                            */
/* Pre-condition:  none                                                       */
/*                                                                            */
/* Input: p_input : input value to evaluate                                   */
/* Output: none                                                               */
/* Return: v_is_inf : true if p_input=+/-Inf, false otherwize.                */
/*--------------------------------------------------------------------------- */

te_CMN_FLAG_VALIDITY LIB_MATH_IS_INF( const float32_t p_input )
{
   /* Declarations */
   tu_CMN_BITFIELD      v_input;
   te_CMN_FLAG_VALIDITY v_is_inf;

   /* Initializations */
   v_input.u_word = p_input;
   v_is_inf = e_CMN_FLAG_NOT_VALID;

   /* Statements */
   /* >RELAX<SYNCHRONe_C_Code_10.7> No loss of precision, all field are on 16 bits  */
   if ( ( ( v_input.u_word_bitfield.s_HIGH_FIELD & ((reg16_t)C_MASK_BITS) ) == ((uint16_t)C_NAN_FORMAT) )
     && ( (uint16_t)v_input.u_word_bitfield.s_LOW_FIELD == (uint16_t)C_LSB_MANTISSA_CLEARED ) )
   {
      v_is_inf = e_CMN_FLAG_VALID;
   }
   return ( v_is_inf);
}
