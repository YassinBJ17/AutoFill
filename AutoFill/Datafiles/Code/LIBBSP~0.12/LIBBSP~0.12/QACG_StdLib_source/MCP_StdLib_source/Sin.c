/*-------------------------------------------------------------------------------------------------------------------*/
/* PROJECT : Unified Standard Library                                                                                */
/*-------------------------------------------------------------------------------------------------------------------*/
/* COMPANY : SAGEM                                                                                                   */
/*-------------------------------------------------------------------------------------------------------------------*/
/* CSU NAME : Sin                                                                                                    */
/* FILENAME : Sin.c                                                                                                  */
/*-------------------------------------------------------------------------------------------------------------------*/

#include "Sin.h"
#include "LibTrig.h"
#include "LibIEEE.h"

/*------------------------------------------------------------------------------------------------------------------*/
/* Function:   Sin                                                                                                   */
/*-------------------------------------------------------------------------------------------------------------------*/
/* Description: This function computes the sine of the input X                                                       */
/*    Special case: if X = INF or Nan, the function returns NaN                                                      */
/* Pre-condition: ABS(X) shall be less than or equal to 1.0e+04 (32 bits) or 1.0e+05 (64 bits)                       */
/*                                                                                                                   */
/* Input: X : parameter for which the sine is computed                                                               */
/* Output: none                                                                                                      */
/* Return: sinX : result of sine                                                                                     */
/*-------------------------------------------------------------------------------------------------------------------*/

t_float Sin(const t_float /* IN */ X)
{
   /* Declarations */
   t_float redX;
   t_float sinX;
   t_int_32 quadrant;
   t_boolean IsNanOrInfX;
   t_float AbsX;
   
   /* Initializations */
   IsNanOrInfX = IsNanOrInf(X);
   redX = C_ZERO_FLOAT;
   sinX = C_ZERO_FLOAT;
   AbsX = Abs(X);

   /* if X equals INF or NaN or outside the range defined by the precondition */
   if (IsNanOrInfX != FALSE || AbsX > C_MAX_INPUT)
   {
      /* Return the NaN value */
      sinX = M_D_NAN;
   }
   else
   {
      /* Reduce range to [-Pi/4..Pi/4] */
      quadrant = SinCosRangeReduc(X, &redX);

      /* Compute the Sine of the reduced value */
      /* Use symmetry properties of Sine/Cosine according to the quadrant */
      if (quadrant == C_QUADRANT_0)
      {
         sinX = ReducedSin(redX);
      }
      else if (quadrant == C_QUADRANT_1)
      {
         sinX = ReducedCos(redX);
      }
      else if (quadrant == C_QUADRANT_2)
      {
         sinX = -ReducedSin(redX);
      }
      else /* C_QUADRANT_3 */
      {
         sinX = -ReducedCos(redX);
      }

      /* Restore sign symmetry. It was lost during reduction */
      if (X < C_ZERO_FLOAT)
      {
         sinX = -sinX;
      }
   }
   
   return (sinX);
}

