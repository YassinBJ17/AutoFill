/*-------------------------------------------------------------------------------------------------------------------*/
/* PROJECT : Unified Standard Library                                                            */
/*-------------------------------------------------------------------------------------------------------------------*/
/* COMPANY : SAGEM                                                                           */
/*-------------------------------------------------------------------------------------------------------------------*/
/* CSU NAME : CopySign                                                                        */
/* FILENAME : CopySign.c                                                                      */
/*-------------------------------------------------------------------------------------------------------------------*/

#include "LibIEEE.h"
#include "IsNan.h"
#include "CopySign.h"
/*-------------------------------------------------------------------------------------------------------------------*/
/* Function:   CopySign                                                                       */
/*-------------------------------------------------------------------------------------------------------------------*/
/* Description: Returns x with the sign of y                                                       */
/*                                                                                       */
/* Pre-condition:  none                                                                       */
/*                                                                                       */
/* Input: x : number from which the mantissa and the exponent is taken                                    */
/*      ex : number from which the sign is taken                                                   */
/* Output: none                                                                             */
/* Return: result : Returns x with the sign of y                                                    */
/*-------------------------------------------------------------------------------------------------------------------*/


t_float CopySign(const t_float x, const t_float y)
{
   /* Declarations */
   TU_LIB_MATH_IEEE mdx;
   TU_LIB_MATH_IEEE mdy;
   #if defined (FLOAT_64)
   t_uint_32    valx;
   t_uint_32    valy;
   #elif defined (FLOAT_32)
   t_uint_16    valx;
   t_uint_16    valy;
   #endif

   t_float result;
   const t_boolean IsNanX = IsNan(x);
   const t_boolean IsNanY = IsNan(y);

   /* If X or Y are equals NaN*/
   if (IsNanX != FALSE || IsNanY != FALSE)
   {
      /* Return the NaN value */
      result = M_D_NAN;
   }
   else
   {
      /* Initializations */
      mdx.d = x;
      mdy.d = y;

      /* Forget the sign of x */
      valx = mdx.i.high;

      valx = valx & C_SIGN_MASK_HIGH;

      /* And set the sign of y */

      valy = mdy.i.high;

      valy = valy & C_UINT_THRESHOLD;

      /* Statements */
      /* Reconstitute mdx.i.high */
      mdx.i.high = valx | valy;
      result = mdx.d;
   }
   return (result);
}