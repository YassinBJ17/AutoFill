/*-------------------------------------------------------------------------------------------------------------------*/
/* PROJECT : Unified Standard Library                                                                                */
/*-------------------------------------------------------------------------------------------------------------------*/
/* COMPANY : SAGEM                                                                                                   */
/*-------------------------------------------------------------------------------------------------------------------*/
/* CSU NAME : Log2                                                                                                   */
/* FILENAME : Log2.c                                                                                                 */
/*-------------------------------------------------------------------------------------------------------------------*/

#include "LibIEEE.h"
#include "Log2.h"

/*-------------------------------------------------------------------------------------------------------------------*/
/* Function:   Log2                                                                                                  */
/*-------------------------------------------------------------------------------------------------------------------*/
/* Description: This function computes Logarithm in base 2 of input X                                                */
/*   if X is Nan, +/-Inf or X <= 0.0 then Log2 returns is NaN                                                        */
/*   if X is 1, then Log2 returns is exactly 0.0                                                                     */
/*                                                                                                                   */
/* Pre-condition: none                                                                                               */
/*                                                                                                                   */
/* Input: X : parameter for Logarithm in base 2 is computed                                                          */
/* Output: none                                                                                                      */
/* Return: Log2X : result of Logarithm in base 2                                                                     */
/*-------------------------------------------------------------------------------------------------------------------*/
t_float Log2(const t_float X)
{
   /* Constants for continued fraction */
   const t_float C_N[2] =
   {
      (7.0 / 9.0),
      (64.0 / 735.0)
   };

   const t_float C_D[2] =
   {
      (10.0 / 9.0),
      (3.0 / 14.0)
   };

   /* Constants for segmentation */
   const t_float C_LIMIT[3] =
   {
      0.55204475683690601, /* 0.5^6/7 */
      0.67295009631617808, /* 0.5^4/7 */
      0.82033535600763807  /* 0.5^2/7 */
   };

   const t_float C_K[3] =
   {
      1.6406707120152761, /* 2^5/7 */
      1.3459001926323562, /* 2^3/7 */
      1.104089513673812   /* 2^1/7 */
   };

   /* Constant for scaling */
   const t_float C_2_LN2 = 2.8853900817779268;
   const t_float C_FOUR_FLOAT = 4.0;
   const t_float C_SIX_FLOAT = 6.0;
   const t_float C_SEVEN_FLOAT = 7.0;

   /* Declarations */
   t_float Log2X;
   t_float fr;
   t_float redX;
   t_float z;
   t_float z2;
   t_float offset;
   t_float n_z;
   t_float d_z;
   t_int_32 ex;
   t_boolean IsNanOrInfX;

   /* Initializations */
   ex = 0L;
   IsNanOrInfX = IsNanOrInf(X);

   /* Statements */
   /* if X is Nan, +/-Inf or X <= 0.0 then Log2 returns is NaN */
   if ((X <= C_ZERO_FLOAT) || (IsNanOrInfX != FALSE))
   {
      /* Return the NaN value */
      Log2X = M_D_NAN;
   }
   else
   {
      /* If X = 1, then return exactly 0.0 without further calculation */
      if (X == C_ONE_FLOAT)
      {
         Log2X = C_ZERO_FLOAT;
      }
      else
      {      
         /* Range reduction: */
         /*  First separate mantissa and exponent */
         /*  with 0.5 <= mantissa < 1 */
         fr = FrExp(X, &ex);
         /* Now reduce the interval into 4 segments:        */
         if (fr < C_LIMIT[0])
         {
            /* In S1, k = 2 and offset = log2 of 2/k = 0 */
            redX = fr * C_TWO_FLOAT;
            offset = C_ZERO_FLOAT;
         }
         else
         {
            if (fr < C_LIMIT[1])
            {
               /* In S2, k = 2^5/7 and offset = log2 of 2/k = 2/7 */
               redX = fr * C_K[0];
               offset = C_TWO_FLOAT / C_SEVEN_FLOAT;
            }
            else
            {
               if (fr < C_LIMIT[2])
               {
                  /* In S3, k = 2^ 3/7  and offset = log2 ok 2/k = 4/7 */
                  redX = fr * C_K[1];
                  offset = C_FOUR_FLOAT / C_SEVEN_FLOAT;
               }
               else
               {
                  /* In S3, k = 2^ 1/7 and offset = log2 of 2/k = 6/7 */
                  redX = fr * C_K[2];
                  offset = C_SIX_FLOAT / C_SEVEN_FLOAT;
               }
            }
         }
         /* Now 0.5^1/7 <= redX <= 2^1/7         */
         /* Evaluate the continued fraction terms  */
         z = (redX - C_ONE_FLOAT) / (redX + C_ONE_FLOAT);
         z2 = z * z;
         n_z = C_ONE_FLOAT - (C_N[0] * (z2 * (C_ONE_FLOAT - (C_N[1] * z2))));
         d_z = C_ONE_FLOAT - (C_D[0] * (z2 * (C_ONE_FLOAT - (C_D[1] * z2))));

         /* And build the final result:               */
         /* log2 x  = 2/ln of 2*z*n_z/d_z + offset+ex-1 */
         Log2X = (C_2_LN2 * (z * (n_z / d_z))) + (offset + ((t_float)ex - C_ONE_FLOAT));
      }
   }

   return (Log2X);
}
