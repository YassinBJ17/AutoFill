/*-------------------------------------------------------------------------------------------------------------------*/
/* PROJECT : Unified Standard Library                                                                                */
/*-------------------------------------------------------------------------------------------------------------------*/
/* COMPANY : SAGEM                                                                                                   */
/*-------------------------------------------------------------------------------------------------------------------*/
/* CSU NAME : ASin                                                                                                   */
/* FILENAME : ASin.c                                                                                                 */
/*-------------------------------------------------------------------------------------------------------------------*/

#include "LibIEEE.h"
#include "ATan2.h"
#include "Sqrt.h"
#include "ASin.h"

/*-------------------------------------------------------------------------------------------------------------------*/
/* Function:   ASin                                                                                                  */
/*-------------------------------------------------------------------------------------------------------------------*/
/* Description: This function computes the Arc Sine of the input X                                                   */
/*   if X = NaN, X = +/-Inf or Abs X > 1, then ASin returns NaN                                                      */
/*   if X = 0.0 then ASin returns exactly 0.0 without further calculation                                            */
/*                                                                                                                   */
/* Pre-condition: none                                                                                               */
/*                                                                                                                   */
/* Input: X : parameter for which the Arc Sine is computed                                                           */
/* Output: none                                                                                                      */
/* Return: AsinX : result of Arc Sine                                                                                */
/*-------------------------------------------------------------------------------------------------------------------*/

t_float ASin(const t_float X)
{
   t_float AsinX;
   t_float AbsX;
   t_float Y;
   t_float Z;
   t_boolean IsNanOrInfX;
   t_boolean IsZeroOrSubnormalX;

   /* Initialization */
   IsNanOrInfX = IsNanOrInf(X);
   IsZeroOrSubnormalX = IsZeroOrSubnormal(X);
   AbsX = Abs(X);

   /* Statements */
   /* if X=NaN, X=+/-Inf or Abs X > 1, then ACos returns NaN */
   if ((IsNanOrInfX != FALSE) || (AbsX > C_ONE_FLOAT))
   {
      /* Return the NaN value */
      AsinX = M_D_NAN;
   }
   else
   {
      /* If X = 0 (or subnormal), then return exactly 0.0 without further calculation */
      if (IsZeroOrSubnormalX != FALSE)
      {
         AsinX = C_ZERO_FLOAT;
      }
      else
      {
         Y = C_ONE_FLOAT - (X * X);
         Z = Sqrt(Y);
         Z = C_ONE_FLOAT + Z;
         Z = ATan2(X, Z);
         AsinX = C_TWO_FLOAT * Z;
      }
   }

   return (AsinX);
}
