/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : <short description of the operations of the .c file>
 * -------------------------------------------------------------------------- */

#include "type/common_type.h"
#include "libtools/math/LIB_MATH_public.h"

/*-----------------------------------------------------------------------------*/
/* Function:   LIB_MATH_IS_NAN_OR_INF                                          */
/*-----------------------------------------------------------------------------*/
/* Description: Indicates if X is equal to +Inf, -Inf or NaN                   */
/*                                                                             */
/* Pre-condition:  none                                                        */
/*                                                                             */
/* Input: X : input value to be analyzed                                       */
/* Output: none                                                                */
/* Return: v_is_Nan_or_inf : e_CMN_FLAG_VALID if argument is +Inf, -Inf or NaN,*/
/*                           e_CMN_FLAG_NOT_VALID otherwize                    */
/*-----------------------------------------------------------------------------*/

te_CMN_FLAG_VALIDITY LIB_MATH_IS_NAN_OR_INF( const float32_t p_input )
{
   /* Declarations */
   tu_CMN_BITFIELD      v_input;
   te_CMN_FLAG_VALIDITY v_is_Nan_or_inf;

   /* Initializations */
   v_input.u_word = p_input;
   v_is_Nan_or_inf = e_CMN_FLAG_NOT_VALID;

   /* Statements */
   /* >RELAX<SYNCHRONe_C_Code_10.7> No loss of precision, C_MASK_BITS and C_NAN_FORMAT are on 16 bits  */
   if ( ( v_input.u_word_bitfield.s_HIGH_FIELD & ((reg16_t)C_MASK_BITS) ) >= (uint16_t)C_NAN_FORMAT )
   {
      v_is_Nan_or_inf = e_CMN_FLAG_VALID;
   }

   return ( v_is_Nan_or_inf );
}
