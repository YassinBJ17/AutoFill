/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : <short description of the operations of the .c file>
 * -------------------------------------------------------------------------- */

#include "type/common_type.h"
#include "libtools/math/LIB_MATH_public.h"

#define C_ATAN_POLY_ORDER (4)


/*Float constants used in various computation representable in IEEE754 Single and Double precision */
const float32_t C_ONE_FLOAT = 1.0;


const float32_t C_SMALL_v_input = 1.0e-10;


/*-----------------------------------------------------------------------------------------------*/
/* Function:   LIB_MATH_POSITIVE_ATAN                                                            */
/*-----------------------------------------------------------------------------------------------*/
/* Description: Returns the arc tangent of a positive value with an accuracy is less than 2E-16. */
/*     Special: if X=INF, then PositiveAtan returns Pi/2                                         */
/*                                                                                               */
/* Pre-condition:  none                                                                          */
/*                                                                                               */
/* Input: x : input value for the computation                                                    */
/* Output: none                                                                                  */
/* Return: result : the arc tangent of the input value.                                          */
/*-----------------------------------------------------------------------------------------------*/

float32_t LIB_MATH_POSITIVE_ATAN( const float32_t p_input )
{
   /* Declarations constants for continued fraction */
   const float32_t c_frac_tab[C_ATAN_POLY_ORDER] = {
      (91.0 / 51.0),
      (249.0 / 455.0),
      (1289.0 / 7553.0),
      (16384.0 / 638055.0)
   };
   const float32_t c_d_tab[C_ATAN_POLY_ORDER] = {
      (36.0 / 17.0),
      (7.0 / 10.0),
      (10.0 / 39.0),
      (3.0 / 44.0)
   };



   /* Threshold above which the effective result and the asymptotic */
   /* value cannot be distinguished on a 64bit FP data */
   const float32_t c_LIBMATH_X_HIGHLIMIT = 1.0e+20;

   /* Declarations */
   float32_t            v_atan_value;
   float32_t            v_input;
   float32_t            v_input_square;
   float32_t            v_n;
   float32_t            v_d;
   te_CMN_FLAG_VALIDITY v_comp;
   te_CMN_FLAG_VALIDITY v_hi_seg;
   te_CMN_FLAG_VALIDITY v_is_inf;

   tu_CMN_BITFIELD v_PI_2;
   tu_CMN_BITFIELD v_PI_2_LOW;
   tu_CMN_BITFIELD v_PI_6;
   tu_CMN_BITFIELD v_PI_6_LOW;
   tu_CMN_BITFIELD v_TAN_PI_12;
   tu_CMN_BITFIELD v_TAN_PI_12_LOW;
   tu_CMN_BITFIELD v_TAN_PI_6;
   tu_CMN_BITFIELD v_TAN_PI_6_LOW;

   /* Initializations */
   v_input  = p_input;
   v_comp   = e_CMN_FLAG_NOT_VALID;
   v_hi_seg = e_CMN_FLAG_NOT_VALID;
   v_is_inf = LIB_MATH_IS_INF(v_input);


   /* {{RELAX<SYNCHRONe_C_Code_10.2,SYNCHRONe_C_Code_10.7> cast is safe, element is consistent with parameter and pointer type. No loss of precision : constants are defined on 16 bits  */
   v_PI_2.u_word_bitfield.s_LOW_FIELD = C_PI_2_LF;
   v_PI_2.u_word_bitfield.s_HIGH_FIELD = C_PI_2_HF;
   v_PI_2_LOW.u_word_bitfield.s_LOW_FIELD = C_PI_2_LOW_LF;
   v_PI_2_LOW.u_word_bitfield.s_HIGH_FIELD = C_PI_2_LOW_HF;
   v_PI_6.u_word_bitfield.s_LOW_FIELD = C_PI_6_LF;
   v_PI_6.u_word_bitfield.s_HIGH_FIELD = C_PI_6_HF;
   v_PI_6_LOW.u_word_bitfield.s_LOW_FIELD = C_PI_6_LOW_LF;
   v_PI_6_LOW.u_word_bitfield.s_HIGH_FIELD = C_PI_6_LOW_HF;
   v_TAN_PI_12.u_word_bitfield.s_LOW_FIELD = C_TAN_PI_12_LF;
   v_TAN_PI_12.u_word_bitfield.s_HIGH_FIELD = C_TAN_PI_12_HF;
   v_TAN_PI_12_LOW.u_word_bitfield.s_LOW_FIELD = C_TAN_PI_12_LOW_LF;
   v_TAN_PI_12_LOW.u_word_bitfield.s_HIGH_FIELD = C_TAN_PI_12_LOW_HF;
   v_TAN_PI_6.u_word_bitfield.s_LOW_FIELD = C_TAN_PI_6_LF;
   v_TAN_PI_6.u_word_bitfield.s_HIGH_FIELD = C_TAN_PI_6_HF;
   v_TAN_PI_6_LOW.u_word_bitfield.s_LOW_FIELD = C_TAN_PI_6_LOW_LF;
   v_TAN_PI_6_LOW.u_word_bitfield.s_HIGH_FIELD = C_TAN_PI_6_LOW_HF;
   /*}}<SYNCHRONe_C_Code_10.2,SYNCHRONe_C_Code_10.7> */

   /* Statements */
   /* PositiveAtan INF returns Pi/2 */
   if (v_is_inf != e_CMN_FLAG_NOT_VALID)
   {
      v_atan_value = v_PI_2.u_word + v_PI_2_LOW.u_word;
   }
   else
   {
      /* When v_input<C_SMALL_v_input, the relative error between atan x  and x is */
      /* below FP relative precision capabilities. Thus atan v_input  and v_input */
      /* cannot be distinguished */
      if (v_input < C_SMALL_v_input)
      {
         v_atan_value = v_input;
      }
      else
      {
         /* When X>c_LIBMATH_X_HIGHLIMIT, the relative error between atan x and the */
         /* asymptotic value is below FP relative precision */
         /* capabilities. Thus atan X and Pi/2 cannot be distinguished */
         if (v_input > c_LIBMATH_X_HIGHLIMIT)
         {
            v_atan_value = v_PI_2.u_word + v_PI_2_LOW.u_word;
         }
         else
         {
            /* Limit argument to [0..1] */
            if (v_input > C_ONE_FLOAT)
            {
               v_comp = e_CMN_FLAG_VALID;
               v_input = C_ONE_FLOAT / v_input;
            }
            /* Range reduction */
            /* Determine segmentation */
            if (v_input > (v_TAN_PI_12.u_word + v_TAN_PI_12_LOW.u_word))
            {
               v_hi_seg = e_CMN_FLAG_VALID;
               v_input = ((v_input - v_TAN_PI_6.u_word) - v_TAN_PI_6_LOW.u_word) / (C_ONE_FLOAT + ((v_TAN_PI_6.u_word + v_TAN_PI_6_LOW.u_word) * v_input));
            }
            /* Argument is now < tan Pi/12 */
            v_input_square = v_input * v_input;
            /* {{RELAX<SYNCHRONe_C_Code_7.2> no loop can be applied on the function, tables are declared is the function.  */
            v_n = C_ONE_FLOAT + (c_frac_tab[0] * (v_input_square * (C_ONE_FLOAT + (c_frac_tab[1] * (v_input_square * (C_ONE_FLOAT + (c_frac_tab[2] * (v_input_square * (C_ONE_FLOAT + (c_frac_tab[3] * v_input_square))))))))));
            v_d = C_ONE_FLOAT + (c_d_tab[0] * (v_input_square * (C_ONE_FLOAT + (c_d_tab[1] * (v_input_square * (C_ONE_FLOAT + (c_d_tab[2] * (v_input_square * (C_ONE_FLOAT + (c_d_tab[3] * v_input_square))))))))));
            /* }}<SYNCHRONe_C_Code_7.2> */
            v_atan_value = v_input * (v_n / v_d);
            /* Now restore offset if needed */
            if (v_hi_seg != e_CMN_FLAG_NOT_VALID)
            {
               v_atan_value = (v_atan_value + v_PI_6.u_word) + v_PI_6_LOW.u_word;
            }
            /* Restore complement if needed */
            if (v_comp != e_CMN_FLAG_NOT_VALID)
            {
               v_atan_value = (v_PI_2.u_word - v_atan_value) + v_PI_2_LOW.u_word;
            }
         }
      }
   }

   return (v_atan_value);
}
