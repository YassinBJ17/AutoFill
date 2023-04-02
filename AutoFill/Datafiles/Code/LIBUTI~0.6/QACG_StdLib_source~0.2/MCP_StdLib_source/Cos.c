/*-------------------------------------------------------------------------------------------------------------------*/
/* PROJECT : Unified Standard Library                                                                                */
/*-------------------------------------------------------------------------------------------------------------------*/
/* COMPANY : SAGEM                                                                                                   */
/*-------------------------------------------------------------------------------------------------------------------*/
/* CSU NAME : Cos                                                                                                    */
/* FILENAME : Cos.c                                                                                                  */
/*-------------------------------------------------------------------------------------------------------------------*/

#include "Cos.h"
#include "LibTrig.h"
#include "LibIEEE.h"

/*-------------------------------------------------------------------------------------------------------------------*/
/* Function:   Cos                                                                                                   */
/*-------------------------------------------------------------------------------------------------------------------*/
/* Description: This function computes the cosine of the input X                                                     */
/*    Special case: if X = INF or Nan, the function returns NaN                                                      */
/* Pre-condition: ABS(X) shall be less than or equal to 1.0e+04 (32 bits) or 1.0e+05 (64 bits)                       */
/*                                                                                                                   */
/* Input: X : parameter for which the cosine is computed                                                             */
/* Output: none                                                                                                      */
/* Return: cosX : result of cosine                                                                                   */
/*-------------------------------------------------------------------------------------------------------------------*/

t_float Cos(const t_float /* IN */ X)
{
   /* Declarations */
   t_float redX;
   t_float cosX;
   t_int_32 quadrant;
   t_boolean IsNanOrInfX;
   t_float AbsX;
   
   /* Initializations */
   redX = C_ZERO_FLOAT;
   cosX = C_ZERO_FLOAT;
   IsNanOrInfX = IsNanOrInf(X);
   AbsX = Abs(X);

   /* If X equals INF or NaN or outside the range defined by the precondition */
   if (IsNanOrInfX != FALSE || AbsX > C_MAX_INPUT)
   {
      /* Return the NaN value */
      cosX = M_D_NAN;
   }
   else
   {
      /* Reduce range to [-Pi/4..Pi/4] */
      quadrant = SinCosRangeReduc(X, &redX);

      /* Compute the Cosine of the reduced value                          */
      /* Use symmetry properties of Sine/Cosine according to the quadrant */
      if (quadrant == C_QUADRANT_0)
      {
         cosX = ReducedCos(redX);
      }
      else if (quadrant == C_QUADRANT_1)
      {
         cosX = -ReducedSin(redX);
      }
      else if (quadrant == C_QUADRANT_2)
      {
         cosX = -ReducedCos(redX);
      }
      else /* C_QUADRANT_3 */
      {
         cosX = ReducedSin(redX);
      }
   }

   return (cosX);
}

