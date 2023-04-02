/*-------------------------------------------------------------------------------------------------------------------*/
/* PROJECT : Unified Standard Library                                                                                */
/*-------------------------------------------------------------------------------------------------------------------*/
/* COMPANY : SAGEM                                                                                                   */
/*-------------------------------------------------------------------------------------------------------------------*/
/* CSU NAME : Tan                                                                                                    */
/* FILENAME : Tan.c                                                                                                  */
/*-------------------------------------------------------------------------------------------------------------------*/

#include "Tan.h"
#include "LibTrig.h"
#include "LibIEEE.h"

/*-------------------------------------------------------------------------------------------------------------------*/
/* Function:   Tan                                                                                                   */
/*-------------------------------------------------------------------------------------------------------------------*/
/* Description: This function computes the tangent of the input X                                                    */
/*    Special case: if X = INF or Nan, the function returns NaN                                                      */
/*    Special case: if X = 0.0, the function returns exactly 0.0                                                     */
/* Pre-condition: X != Pi mod Pi/2                                                                                   */
/*                ABS(X) shall be less than or equal to 1.0e+04 (32 bits) or 1.0e+05 (64 bits)                       */
/* Input: X : parameter for which the tangent is computed                                                            */
/* Output: none                                                                                                      */
/* Return: tanX : result of tangent                                                                                  */
/*-------------------------------------------------------------------------------------------------------------------*/

t_float Tan(const t_float /* IN */ X)
{
   
   /* constants for continued fraction */
   const t_float C_N[4] =
   {
      (7.0 / 51.0),
      (1.0 / 35.0),
      (2.0 / 273.0),
      (1.0 / 990.0)
   };
   const t_float C_D[4] =
   {
      (8.0 / 17.0),
      (7.0 / 120.0),
      (4.0 / 273.0),
      (1.0 / 308.0)
   };

   /* Declarations */
   t_float redX;
   t_int_32 quadrant;
   t_float tanX;
   t_float x2;
   t_float n_x;
   t_float d_x;
   t_boolean IsNanOrInfX;
   t_boolean IsZeroOrSubnormalX;
   t_float AbsX;

   /* Initializations */
   redX = C_ZERO_FLOAT;
   IsNanOrInfX = IsNanOrInf(X);
   IsZeroOrSubnormalX = IsZeroOrSubnormal(X);
   AbsX = Abs(X);
   
   /* if X equals INF or NaN or outside the range defined by the precondition */
   if (IsNanOrInfX != FALSE || AbsX > C_MAX_INPUT)
   {
      /* Return the NaN value */
      tanX = M_D_NAN;
   }
   else
   {    
      /* If X = 0 (or subnormal), then return exactly 0.0 without further calculation */
      if (IsZeroOrSubnormalX != FALSE)
      {
         tanX = C_ZERO_FLOAT;
      }
      else
      {
         /* Reduce range to [-Pi/4..Pi/4] */
         quadrant = SinCosRangeReduc(X, &redX);

         /* Compute the tangent of the reduced argument */
         x2 = redX * redX;

         n_x = C_ONE_FLOAT - (C_N[3] * x2);
         n_x = C_ONE_FLOAT - (C_N[2] * (x2 * n_x));
         n_x = C_ONE_FLOAT - (C_N[1] * (x2 * n_x));
         n_x = C_ONE_FLOAT - (C_N[0] * (x2 * n_x));

         d_x = C_ONE_FLOAT - (C_D[3] * x2);
         d_x = C_ONE_FLOAT - (C_D[2] * (x2 * d_x));
         d_x = C_ONE_FLOAT - (C_D[1] * (x2 * d_x));
         d_x = C_ONE_FLOAT - (C_D[0] * (x2 * d_x));

         tanX = redX * (n_x / d_x);

         /* Correct the result depending of the quadrants, symmetry */
         if ((quadrant == C_QUADRANT_1) || (quadrant == C_QUADRANT_3))
         {
            tanX = -(C_ONE_FLOAT / tanX);
         }

         /* Restore sign symmetry, was lost during reduction */
         if (X < C_ZERO_FLOAT)
         {
            tanX = -tanX;
         }
      }
   }

   /* Return data is set in any condition case */
   return (tanX);
}

