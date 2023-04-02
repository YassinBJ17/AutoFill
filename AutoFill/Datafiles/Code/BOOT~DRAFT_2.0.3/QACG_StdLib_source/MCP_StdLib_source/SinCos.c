/*-------------------------------------------------------------------------------------------------------------------*/
/* PROJECT : Unified Standard Library                                                                                */
/*-------------------------------------------------------------------------------------------------------------------*/
/* COMPANY : SAGEM                                                                                                   */
/*-------------------------------------------------------------------------------------------------------------------*/
/* CSU NAME : SinCos                                                                                                 */
/* FILENAME : SinCos.c                                                                                               */
/*-------------------------------------------------------------------------------------------------------------------*/

#include "SinCos.h"
#include "LibTrig.h"
#include "LibIEEE.h"

/*-------------------------------------------------------------------------------------------------------------------*/
/* Function:   SinCos                                                                                                */
/*-------------------------------------------------------------------------------------------------------------------*/
/* Description: This function computes the sine and the cosine of the input parameter X.                             */
/*    If X = INF or Nan, the sine and cosine of X equal NaN                                                          */
/*                                                                                                                   */
/* Pre-condition: ABS(X) shall be less than or equal to 1.0e+04 (32 bits) or 1.0e+05 (64 bits)                       */
/*                                                                                                                   */
/* Input: X : parameter for which the sine and the cosine are computed.                                              */
/* Output: none                                                                                                      */
/* Return: SinX: sine of X                                                                                           */
/*         CosX: cosine of X                                                                                         */
/*-------------------------------------------------------------------------------------------------------------------*/

void SinCos(const t_float X, t_float * const SinX, t_float * const CosX)
{
   /* Declarations */
   t_float redX;
   t_int_32 quadrant;
   t_boolean IsNanOrInfX;
   t_float AbsX;

   /* Initializations */
   redX = C_ZERO_FLOAT;
   *SinX = C_ZERO_FLOAT;
   *CosX = C_ZERO_FLOAT;
   IsNanOrInfX = IsNanOrInf(X);
   AbsX = Abs(X);

   /* Statements */
   /* if X equals INF or NaN or outside the range defined by the precondition */
   if (IsNanOrInfX != FALSE || AbsX > C_MAX_INPUT)
   {
      /* Return the NaN value */
      *SinX = M_D_NAN;
      *CosX = M_D_NAN;
   }
   else
   {
      /* Reduce range to [-Pi/4..Pi/4] */
      quadrant = SinCosRangeReduc(X, &redX);

      /* Compute the Sine and Cosine of the reduced value */
      /* Use symmetry properties of Sine/Cosine according to the quadrant */
      if (quadrant == C_QUADRANT_0)
      {
         *SinX = ReducedSin(redX);
         *CosX = ReducedCos(redX);
      }
      else if (quadrant == C_QUADRANT_1)
      {
         *SinX = ReducedCos(redX);
         *CosX = -ReducedSin(redX);
      }
      else if (quadrant == C_QUADRANT_2)
      {
         *SinX = -ReducedSin(redX);
         *CosX = -ReducedCos(redX);
      }
      else /* C_QUADRANT_3 */
      {
         *SinX = -ReducedCos(redX);
         *CosX = ReducedSin(redX);
      }

      /* Restore sign symmetry of sine, lost during reduction */
      if (X < C_ZERO_FLOAT)
      {
         *SinX = - (*SinX);
      }
   }
}

