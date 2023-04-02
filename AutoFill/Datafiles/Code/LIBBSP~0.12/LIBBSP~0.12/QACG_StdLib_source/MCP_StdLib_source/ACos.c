/*-------------------------------------------------------------------------------------------------------------------*/
/* PROJECT : Unified Standard Library                                                                                */
/*-------------------------------------------------------------------------------------------------------------------*/
/* COMPANY : SAGEM                                                                                                   */
/*-------------------------------------------------------------------------------------------------------------------*/
/* CSU NAME : ACos                                                                                                   */
/* FILENAME : ACos.c                                                                                                 */
/*-------------------------------------------------------------------------------------------------------------------*/

#include "LibIEEE.h"
#include "LibTrig.h"
#include "ATan2.h"
#include "Sqrt.h"
#include "ACos.h"

/*-------------------------------------------------------------------------------------------------------------------*/
/* Function:   ACos                                                                                                  */
/*-------------------------------------------------------------------------------------------------------------------*/
/* Description: This function computes the Arc Cosine of the input X                                                 */
/*   if X = NaN, X = +/-Inf or Abs X > 1, then ACos returns NaN                                                      */
/*   if X = 1, then ACos returns exactly 0.0 (ensured in by the ATAN2 function)                                      */
/*                                                                                                                   */
/* Pre-condition: none                                                                                               */
/*                                                                                                                   */
/* Input: X : parameter for which the Arc Cosine is computed                                                         */
/* Output: none                                                                                                      */
/* Return: AcosX : result of Arc Cosine X                                                                            */
/*-------------------------------------------------------------------------------------------------------------------*/

t_float ACos(const t_float X)
{
   /* Declarations */
   t_float AcosX;
   t_float Y;
   t_float Z;
   t_float AbsX;
   t_boolean IsNanOrInfX;

   /* Initialization */
   AbsX = Abs(X);
   IsNanOrInfX = IsNanOrInf(X);

   /* Statements */
   /* if X=NaN, X=+/-Inf or Abs X > 1, then ACos returns NaN */
   if ((IsNanOrInfX != FALSE) || (AbsX > C_ONE_FLOAT))
   {
      /* Return the NaN value */
      AcosX = M_D_NAN;
   }
   else
   {
      /* If X = -1.0, then ACos returns Pi */
      if (X == (-C_ONE_FLOAT))
      {
         AcosX = M_D_PI + M_D_PI_LOW;
      }
      else
      {
         Z = C_ONE_FLOAT + X;
         Y = (C_ONE_FLOAT - X) * Z;
         Y = Sqrt(Y);
         /* logic to output exactly 0.0 if X = 1 into the function Atan2 */
         Y = ATan2(Y, Z);
         AcosX = C_TWO_FLOAT * Y;
      }
   }

   return (AcosX);
}

