/*-------------------------------------------------------------------------------------------------------------------*/
/* PROJECT : Unified Standard Library                                                                                */
/*-------------------------------------------------------------------------------------------------------------------*/
/* COMPANY : SAGEM                                                                                                   */
/*-------------------------------------------------------------------------------------------------------------------*/
/* CSU NAME : Sqrt                                                                                                   */
/* FILENAME : Sqrt.c                                                                                                 */
/*-------------------------------------------------------------------------------------------------------------------*/

#include "LibIEEE.h"
#include "Sqrt.h"

/*-------------------------------------------------------------------------------------------------------------------*/
/* Function:   Sqrt                                                                                                  */
/*-------------------------------------------------------------------------------------------------------------------*/
/* Description: This function computes the square root of input X                                                    */
/*   if X is Nan, +/-Inf or X < 0, then Sqrt returns NaN                                                             */ 
/*                                                                                                                   */
/* Pre-condition: none                                                                                               */
/*                                                                                                                   */
/* Input: X : parameter for which the square root is computed                                                        */
/* Output: none                                                                                                      */
/* Return: SqrtX : result of arc cosine                                                                              */
/*-------------------------------------------------------------------------------------------------------------------*/

t_float Sqrt(const t_float X)
{

   /* Constants for second degree approximation over [1/2..1[ */
   const t_float C_C[2] =
   {
      0.59016206709064445,
      0.41730759963886499
   };
   /* Constant for scaling */
   const t_float C_1_SQRT2 = 0.70710678118654746;
   
   const t_float C_ZERO_DOT_FIVE_FLOAT = 0.5;
   const t_int_32 C_TWO_INT32 = 2;

   /* Declarations */
   t_float fr;
   t_float fr1;
   t_float SqrtX;
   t_int_32 ex;
   t_int_32 ex1;
   t_int_32 ex2;
   t_boolean IsZeroOrSubnormalX;
   t_boolean IsNanOrInfX;

   /* Initializations */
   ex = 0L;
   IsZeroOrSubnormalX = IsZeroOrSubnormal(X);
   IsNanOrInfX = IsNanOrInf(X);

   /* Statements */
   /* if X is NaN, +/-Inf or X < 0 then Sqrt returns NaN */
   if ((X < C_ZERO_FLOAT) || (IsNanOrInfX != FALSE))
   {
      /* Return the NaN value */
      SqrtX = M_D_NAN;
   }
   else if (IsZeroOrSubnormalX != FALSE)
   {
      /* if X is 0.0 or Subnormal then Sqrt returns 0.0 */
      SqrtX = C_ZERO_FLOAT;
   }
   else
   {
      /* Range reduction */
      /* Separate into fraction and exponent */
      /* with 0.5 <= fraction < 1        */
      fr = FrExp(X, &ex);

      /* Separate the exponent so that ex = 2*ex1 + ex2, */
      /* with ex2 equals -1 or 0 */
      /* ex1 is the exponent of the square root of X */
      ex2 = ex % C_TWO_INT32;
      if (ex2 > 0L)
      {
         ex2 = ex2 - C_TWO_INT32;
      }
      ex1 = (ex - ex2) / C_TWO_INT32;

      /* At this point, SqrtX equals sqrt of fr * sqrt of 2^ex2 * 2^ex1 */
      /* with ex2 being 0 or -1 */

      /* Use a linear approximation of square root when 0.5 <= X < 1 */
      /* to compute a first guess of the square root of fr */
      /* with 6 accurate bits */
      fr1 = (C_C[0] * fr) + C_C[1];

      /* Then perform several Newton-Raphson iterations to   */
      /* quadratically improve the precision of the mantissa */
      /* 12 accurate bits */
      fr1 = C_ZERO_DOT_FIVE_FLOAT * (fr1 + (fr / fr1));
      /* 24 accurate bits - accurate enough for single precision */
      fr1 = C_ZERO_DOT_FIVE_FLOAT * (fr1 + (fr / fr1));
      /* 48 accurate bits */
      fr1 = C_ZERO_DOT_FIVE_FLOAT * (fr1 + (fr / fr1));
      /* 96 accurate bits - accurate enough for double precision */
      fr1 = C_ZERO_DOT_FIVE_FLOAT * (fr1 + (fr / fr1));

      /* Integrate sqrt of 2^ex2 factor if ex2 = -1 */
      if (ex2 != 0L)
      {
         fr1 = fr1 * C_1_SQRT2;
      }

      /* Finally recompose fr1 and ex1 */
      SqrtX = LdExp(fr1, ex1);
   }

   return (SqrtX);
}
