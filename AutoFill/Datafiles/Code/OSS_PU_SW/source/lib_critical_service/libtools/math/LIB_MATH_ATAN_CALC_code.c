/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : <short description of the operations of the .c file>
 * -------------------------------------------------------------------------- */

#include "libtools/math/LIB_MATH_public.h"


/*-------------------------------------------------------------------------------------------------------------------*/
/* Function:   ATan                                                                                                  */
/*-------------------------------------------------------------------------------------------------------------------*/
/* Description: This function computes the Arc Tangent of the input X                                                */
/*   if X is NaN or +/-Inf then ATan returns NaN                                                                     */
/*                                                                                                                   */
/* Pre-condition: none                                                                                               */
/*                                                                                                                   */
/* Input: X : parameter for which the Arc Tangent is computed                                                        */
/* Output: none                                                                                                      */
/* Return: v_atan_value : result of Arc Tangent                                                                      */
/*-------------------------------------------------------------------------------------------------------------------*/

/*Float constants used in various computation representable in IEEE754 Single and Double precision */
const float32_t C_ZERO_FLOAT = 0.0;




float32_t LIB_MATH_ATAN_CALC(const float32_t p_input)
{
   /* Declarations */
   float32_t            v_atan_value;
   te_CMN_FLAG_VALIDITY v_isNanOrInf;
   te_CMN_FLAG_VALIDITY v_isZeroOrSubnormal;

   /* Initialization */
   v_isNanOrInf = LIB_MATH_IS_NAN_OR_INF(p_input);
   v_isZeroOrSubnormal = LIB_MATH_IS_ZERO_OR_SUBNORMAL(p_input);

   /* Statements */
   /* if X is NaN or +/-Inf then ATan returns NaN */
   if (v_isNanOrInf != e_CMN_FLAG_NOT_VALID)
   {
     /* >RELAX<SYNCHRONe_C_Code_10.7> No loss, v_atan_value is float32_t */
      v_atan_value = C_NAN_FLOAT32;
   }
   else
   {
      /* If X = 0 (or subnormal), then return exactly 0.0 without further calculation */
      if (v_isZeroOrSubnormal != e_CMN_FLAG_NOT_VALID)
      {
         v_atan_value = C_ZERO_FLOAT;
      }
      else
      {
         /* Also compatible with X = Inf */
         v_atan_value = LIB_MATH_FABS(p_input);
         v_atan_value = LIB_MATH_POSITIVE_ATAN(v_atan_value);
         /* Also applied when X is 0.0 for continuity near zero */
         /* Negative and positive zeros */
         v_atan_value = LIB_MATH_COPYSIGN(v_atan_value, p_input);
      }
   }

   return (v_atan_value);
}

