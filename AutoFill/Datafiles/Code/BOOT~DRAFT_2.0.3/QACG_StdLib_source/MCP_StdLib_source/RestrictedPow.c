/*-------------------------------------------------------------------------------------------------------------------*/
/* PROJECT : Unified Standard Library                                                                                */
/*-------------------------------------------------------------------------------------------------------------------*/
/* COMPANY : SAGEM                                                                                                   */
/*-------------------------------------------------------------------------------------------------------------------*/
/* CSU NAME : RestrictedPow                                                                                          */
/* FILENAME : RestrictedPow.c                                                                                        */
/*-------------------------------------------------------------------------------------------------------------------*/

#include "LibIEEE.h"
#include "RestrictedPow.h"
#include "Log2.h"
#include "Expo.h"

/*-------------------------------------------------------------------------------------------------------------------*/
/* Function:   RestrictedPow                                                                                         */
/*-------------------------------------------------------------------------------------------------------------------*/
/* Description: This function computes X to the Y power: X^Y                                                         */
/*   if Y equals NaN, +/-Inf, then RestrictedPow returns NaN                                             */
/*   if Y is a valid number and X equals NaN, +/-Inf or X < 0.0, then RestrictedPow returns NaN                      */
/*   if X and Y are valid numbers and Abs of Y*Log2(X) >= 1024 (64bits) OR 128(32 bits), then                        */
/*   RestrictedPow returns NaN                                                                                       */
/*                                                                                                                   */
/*     Y valid number means different from NaN or Inf                                                     */
/*     X valid number means X >= 0 and different from NaN or Inf                                                     */
/*                                                                                                                   */
/* Pre-condition:                                                                                                    */
/*     X >= 0                                                                                                        */
/*     If X <> 0 => ABS(Y*Log2(X)) < 126.0 for 32 bits implementation                                                */
/*     If X <> 0 => ABS(Y*Log2(X)) < 1022.0 for 64 bits implementation                                               */
/*                                                                                                                   */
/*-------------------------------------------------------------------------------------------------------------------*/
/* Input: X : parameter from which the power is computed                                                             */
/* Input: Y : parameter which is the power of input parameter X                                                      */
/* Output: none                                                                                                      */
/* Return: result of the computation X^Y                                                                     */
/*-------------------------------------------------------------------------------------------------------------------*/

t_float RestrictedPow(const t_float X, const t_float Y)
{
   /* Constant Neperian/Natural logarithm of 2 */
   const t_float LN2 = 6.93147180559945309417e-01;

   /* Declarations */
   t_boolean IsNanOrInfY;
   t_boolean IsNanOrInfX;
   t_float XpowY;
   t_float Y_ln_X;
   t_float Y_log2_X;

   #if defined (FLOAT_64)
   const t_float C_PRECONDITION = 1022.0;
   #elif defined (FLOAT_32)
   const t_float C_PRECONDITION = 126.0;
   #endif 


   /* Initialization */
   IsNanOrInfX = IsNanOrInf(X);
   IsNanOrInfY = IsNanOrInf(Y);

   /* Statements */

   /* If Y equals NaN, Inf or X equals NaN, +/-Inf or X < 0.0 then RestrictedPow returns NaN */
   if ((IsNanOrInfY != FALSE) || (IsNanOrInfX != FALSE) || (X < C_ZERO_FLOAT))
   {
      /* Return the NaN value */
      XpowY = M_D_NAN;
   }
   else
   {
      /* If X = 0.0, then RestrictedPow returns 0.0 */
      if (X == C_ZERO_FLOAT)
      {
         /* Y = 0.0 returns 1.0 */
         if (Y == C_ZERO_FLOAT)
         {
            XpowY = C_ONE_FLOAT;
         }
         else
         {
            /* else returns 0.0 */
            XpowY = C_ZERO_FLOAT;
         }
      }
      else
      {
         /* X^Y = e^Ln(X^Y)= e^(Y*Ln(X))=e^(Y*log2(X)*Ln(2))  */
         /* Compute log2(X) using existing Log2 function      */

         Y_log2_X = Log2(X);
         /* calculate the Abs(Y)*Log2(X)*/
         Y_log2_X = Y_log2_X * Abs(Y);
         /* check the precondition */
         if (Y_log2_X >= C_PRECONDITION)
         {
            if (Y < C_ZERO_FLOAT)
            {
               /* Out of the lower range -> 0.0 */
               XpowY = C_ZERO_FLOAT;
            }
            else
            {
               /* Out of the upper range -> NaN */
               XpowY = M_D_NAN;
            }
         }
         else
         {
            /* calculate Y_ln_X = y times logarithm  natural of x */
            /* multiplying by Ln(2)                               */
            Y_ln_X = LN2 * Y_log2_X;

            /* Compute e^(Y_ln_X) using existing Expo function */
            XpowY = Expo(Y_ln_X);

            if (Y < C_ZERO_FLOAT)
            {
               /* recompute the output value for negative values of Y, as X**Y for negative Y is 1 / X**Abs(Y) */
               XpowY = C_ONE_FLOAT / XpowY ;
            }
         }
      }
   }

   return (XpowY);
}
