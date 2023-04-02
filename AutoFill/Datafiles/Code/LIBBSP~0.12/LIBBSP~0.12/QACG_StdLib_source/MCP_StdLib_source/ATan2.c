/*-------------------------------------------------------------------------------------------------------------------*/
/* PROJECT : Unified Standard Library                                                                                */
/*-------------------------------------------------------------------------------------------------------------------*/
/* COMPANY : SAGEM                                                                                                   */
/*-------------------------------------------------------------------------------------------------------------------*/
/* CSU NAME : ATan2                                                                                                  */
/* FILENAME : ATan2.c                                                                                                */
/*-------------------------------------------------------------------------------------------------------------------*/

#include "ATan2.h"
#include "LibTrig.h"
#include "CopySign.h"
#include "LibIEEE.h"
#include "IsInf.h"
#include "IsNan.h"

/*-------------------------------------------------------------------------------------------------------------------*/
/* Function:   ATan2                                                                                                 */
/*-------------------------------------------------------------------------------------------------------------------*/
/* Description: This function computes the arc tangent of the ratio Y/X.                                             */
/*   if Y=NaN or X=NaN, then Atan2 X,Y returns NaN                                                                   */
/*   if Y=INF and X=INF, then Atan2 Y,X returns NaN                                                                  */
/*   if Y=0.0 and X>=0, then Atan2 returns exactly 0.0                                                               */
/*   if Y=0.0 and X<0, then Atan2 returns exactly PI                                                                 */
/* Pre-condition: none                                                                                               */
/*                                                                                                                   */
/* Input: X : the cosine of the angle                                                                                */
/* Input: Y : the sine of the angle                                                                                  */
/* Output: none                                                                                                      */
/* Return: atan2YX : result of the arc tangent of the ratio Y/X.                                                     */
/*-------------------------------------------------------------------------------------------------------------------*/

t_float ATan2(const t_float Y, const t_float X)
{
   /* Declarations */
   t_float atan2YX;
   t_float YX;
   t_float AbsYX;
   t_boolean IsNanX;
   t_boolean IsNanY;
   t_boolean IsInfX;
   t_boolean IsInfY;
   t_float PositiveAtanAbsYX;
   
   IsNanX = IsNan(X);
   IsNanY = IsNan(Y);
   IsInfX = IsInf(X);
   IsInfY = IsInf(Y);

   /* Statements */
   /* if X or Y equal NaN, or if X and Y equal Inf then Atan2 returns NaN */
   if (((IsNanY != FALSE) || (IsNanX != FALSE)) || ((IsInfY != FALSE) && (IsInfX != FALSE)))
   {
      /* Return the NaN value */
      atan2YX = M_D_NAN;
   }
   else
   {
      /* Also compatible with Y/INF and INF/X ratios */
      if (Y == C_ZERO_FLOAT)
      {
         /* If Y=0, the return exactly 0.0 or PI without further calculation */
         if (X >= C_ZERO_FLOAT)
         {
            atan2YX = C_ZERO_FLOAT;
         }
         else
         {
            atan2YX = M_D_PI + M_D_PI_LOW;
         }
      }
      else
      {
         if (X > C_ZERO_FLOAT)
         {
            YX = Y / X;
            AbsYX = Abs(YX);
            atan2YX = PositiveAtan(AbsYX);
         }
         else
         { 
            if (X < C_ZERO_FLOAT)
            {
               YX = Y / X;
               AbsYX = Abs(YX);
               PositiveAtanAbsYX = PositiveAtan(AbsYX);
               atan2YX = (M_D_PI - PositiveAtanAbsYX) + M_D_PI_LOW;
            }
            else
            {
               atan2YX = M_D_PI_2 + M_D_PI_2_LOW;
            }
         }
      }

      /* Also applied when Y is 0.0 for continuity near zero */
      /* with negative and positive zeros */
      atan2YX = CopySign(atan2YX, Y);
   }

   return (atan2YX);
}
