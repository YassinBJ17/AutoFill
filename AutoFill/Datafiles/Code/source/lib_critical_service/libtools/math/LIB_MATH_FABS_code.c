/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : <short description of the operations of the .c file>
 * -------------------------------------------------------------------------- */

#include "type/common_type.h"
#include "libtools/math/LIB_MATH_public.h"

/*----------------------------------------------------------------------------*/
/* Function:   LIB_MATH_FABS                                                  */
/*----------------------------------------------------------------------------*/
/* Description: Returns the absolute value of the argument                    */
/*                                                                            */
/* Pre-condition:  none                                                       */
/*                                                                            */
/* Input: x : input value from which the absolute value is computed           */
/* Output: none                                                               */
/* Return: result : the absolute value of the argument                        */
/*----------------------------------------------------------------------------*/

float32_t LIB_MATH_FABS(const float32_t p_input)
{
   /* Declarations */
   tu_CMN_BITFIELD v_input;
   float32_t       v_abs_value;

   /* Initializations */
   v_input.u_word = p_input;

   /* Statements */
   /* >RELAX<SYNCHRONe_C_Code_10.7> No loss of precision, C_MASK_BITS is on 16 bits  */
   v_input.u_word_bitfield.s_HIGH_FIELD = (uint16_t)v_input.u_word_bitfield.s_HIGH_FIELD & ((reg16_t) C_MASK_BITS);

   v_abs_value = v_input.u_word;
   return (v_abs_value);
}
