/*-------------------------------------------------------------------------------------------------------------------*/
/* PROJECT : Unified Standard Library                                                                                */
/*-------------------------------------------------------------------------------------------------------------------*/
/* COMPANY : SAGEM                                                                                                   */
/*-------------------------------------------------------------------------------------------------------------------*/
/* CSU NAME : CubeRoot                                                                                               */
/* FILENAME : CubeRoot.c                                                                                             */
/*-------------------------------------------------------------------------------------------------------------------*/

#include "LibIEEE.h"
#include "CopySign.h"
#include "CubeRoot.h"

/*-------------------------------------------------------------------------------------------------------------------*/
/* Function:   CubeRoot                                                                                              */
/*-------------------------------------------------------------------------------------------------------------------*/
/* Description: This function computes the cube root of the input X                                                  */
/*   if X is Nan or +/-Inf then CubeRoot returns NaN                                                                 */ 
/*   if X = 0.0 or X is a Subnormal numbers then CubeRoot returns 0.0                                                */
/*                                                                                                                   */
/* Pre-condition: none                                                                                               */
/*                                                                                                                   */
/* Input: X : parameter from which the cube root is computed                                                         */
/* Output: none                                                                                                      */
/* Return: CbrtX : result of cube root                                                                               */
/*-------------------------------------------------------------------------------------------------------------------*/
t_float CubeRoot(const t_float X)
{
   /* Constants for second degree approximation over 1/2 and 1 */
   const t_float C_C[2] = {
      0.4153379914158275,
      0.59130052135085043
   };

   /* Constants for scaling */
   const t_float C_1_CBRT2 = 0.79370052598409968;

   /* 1/CubeRoot of 2 */
   const t_float C_1_CBRT4 = 0.62996052494743671;

   const t_int_32 C_TWO_INT32 = 2;
   const t_int_32 C_THREE_INT32 = 3;
   
   /* Declarations */
   t_float fr;
   t_float AbsX;
   t_float fr1;
   t_float CbrtX;
   t_int_32 ex;
   t_int_32 ex1;
   t_int_32 ex2;
   t_boolean IsNanOrInfX;
   t_boolean IsZeroOrSubnormalX;

   /* Initializations */
   ex = 0L;
   IsNanOrInfX = IsNanOrInf(X);
   IsZeroOrSubnormalX = IsZeroOrSubnormal(X);

   /* Statements */
   /* if X equals +/-Inf or NaN, then the input is propagated to CbrtX */
   if (IsNanOrInfX != FALSE)
   {
      /* Return the NaN value */
      CbrtX = M_D_NAN;
   }
   else
   {
      /* if X is 0.0 or Subnormal then CubeRoot returns 0.0 */
      if (IsZeroOrSubnormalX != FALSE)
      {
         CbrtX = C_ZERO_FLOAT;
      }
      else
      {
         /* Range reduction: */
         /* Separate into fraction and exponent */
         /* as 0.5 <= fraction < 1           */
         /* Forget the sign for now          */
         AbsX = Abs(X);
         fr = FrExp(AbsX, &ex);

         /* Separate the exponent so that ex = 3*ex1 + ex2 */
         /* with ex2 equals -2, -1 or 0               */
         /* ex1 is the exponent of the cube root of X     */
         ex2 = ex % C_THREE_INT32;
         if (ex2 > 0L)
         {
            ex2 = ex2 - C_THREE_INT32;
         }
         ex1 = (ex - ex2) / C_THREE_INT32;

         /* At this point, CubeRootX = CubeRoot of fr * CubeRoot of 2^ex2 * 2^ex1 */
         /* with ex2 being 0, -1 or -2                            */

         /* Use a linear approximation of cube root over when 1/2 <= X < 1 */
         /* to compute a first guess of the cube root of fr. */
         /* with 6 accurate bits */
         fr1 = (C_C[0] * fr) + C_C[1];

         /* Then perform several Newton-Raphson iterations to */
         /* quadratically improve the precision of the mantissa        */
         /* 12 accurate bits                     */
         fr1 = (C_ONE_FLOAT / C_THREE_FLOAT) * ((C_TWO_FLOAT * fr1) + (fr / (fr1 * fr1)));
         /* 24 accurate bits - accurate enough for single precision */
         fr1 = (C_ONE_FLOAT / C_THREE_FLOAT) * ((C_TWO_FLOAT * fr1) + (fr / (fr1 * fr1)));
         /* 48 accurate bits                     */
         fr1 = (C_ONE_FLOAT / C_THREE_FLOAT) * ((C_TWO_FLOAT * fr1) + (fr / (fr1 * fr1)));
         /* 96 accurate bits - accurate enough for double precision */
         fr1 = (C_ONE_FLOAT / C_THREE_FLOAT) * ((C_TWO_FLOAT * fr1) + (fr / (fr1 * fr1)));

         /* Integrate CubeRoot of 2^ex2 factor if ex2 = -1 or -2 */
         if (ex2 == (-1L))
         {
            fr1 = fr1 * C_1_CBRT2;
         }
         else
         {
            if (ex2 == (-C_TWO_INT32))
            {
               fr1 = fr1 * C_1_CBRT4;
            }
         }

         /* Finally recompose fr1, ex1, and the sign of X */
         CbrtX = LdExp(fr1, ex1);
         CbrtX = CopySign(CbrtX, X);
      }
   }

   return (CbrtX);
}
