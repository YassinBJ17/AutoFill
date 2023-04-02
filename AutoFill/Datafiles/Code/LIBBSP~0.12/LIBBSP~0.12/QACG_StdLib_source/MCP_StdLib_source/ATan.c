/*-------------------------------------------------------------------------------------------------------------------*/
/* PROJECT : Unified Standard Library                                                                                */
/*-------------------------------------------------------------------------------------------------------------------*/
/* COMPANY : SAGEM                                                                                                   */
/*-------------------------------------------------------------------------------------------------------------------*/
/* CSU NAME : ATan                                                                                                   */
/* FILENAME : ATan.c                                                                                                 */
/*-------------------------------------------------------------------------------------------------------------------*/

#include "LibIEEE.h"
#include "LibTrig.h"
#include "CopySign.h"
#include "ATan.h"

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
/* Return: AtanX : result of Arc Tangent                                                                             */
/*-------------------------------------------------------------------------------------------------------------------*/

t_float ATan(const t_float X)
{
   /* Declarations */
   t_float AtanX;
   t_boolean IsNanOrInfX;
   t_boolean IsZeroOrSubnormalX;

   /* Initialization */
   IsNanOrInfX = IsNanOrInf(X);
   IsZeroOrSubnormalX = IsZeroOrSubnormal(X);
   /* Statements */
   /* if X is NaN or +/-Inf then ATan returns NaN */
   if (IsNanOrInfX != FALSE)
   {
      /* Return the NaN value */
      AtanX = M_D_NAN;
   }
   else
   {
      /* If X = 0 (or subnormal), then return exactly 0.0 without further calculation */
      if (IsZeroOrSubnormalX != FALSE)
      {
         AtanX = C_ZERO_FLOAT;
      }
      else
      {
         /* Also compatible with X = Inf */
         AtanX = Abs(X);
         AtanX = PositiveAtan(AtanX);
         /* Also applied when X is 0.0 for continuity near zero */
         /* Negative and positive zeros */
         AtanX = CopySign(AtanX, X);
      }
   }

   return (AtanX);
}

