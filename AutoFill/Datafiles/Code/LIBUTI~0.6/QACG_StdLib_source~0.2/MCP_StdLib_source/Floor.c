/*-------------------------------------------------------------------------------------------------------------------*/
/* PROJECT : Unified Standard Library                                                                                */
/*-------------------------------------------------------------------------------------------------------------------*/
/* COMPANY : SAGEM                                                                                                   */
/*-------------------------------------------------------------------------------------------------------------------*/
/* CSU NAME : Floor                                                                                                  */
/* FILENAME : Floor.c                                                                                                */
/*-------------------------------------------------------------------------------------------------------------------*/

#include "Floor.h"
#include "IsNan.h"
#include "LibIEEE.h"


/*-------------------------------------------------------------------------------------------------------------------*/
/* Function:   Floor                                                                                                 */
/*-------------------------------------------------------------------------------------------------------------------*/
/* Description: This function returns the greatest integer value smaller or equal to the input value                 */
/*                                                                                                                   */
/* Pre-condition:  none                                                                                              */
/*                                                                                                                   */
/* Input: X : input value for the computation                                                                        */
/* Output: none                                                                                                      */
/* Return: v_result : the greatest integer value smaller or equal to the input value X.                              */
/*-------------------------------------------------------------------------------------------------------------------*/

/* Value where the Unit in the last place (ULP) is one, so all values above it can be handled as integer */
#if defined (FLOAT_64)
/* same value as 0x1.000000p+52 */
const t_float C_Float_offset_for_Integer =  4503599627370496.0;
#elif defined (FLOAT_32)
/* same value as 0x1.000000p+23f */
const t_float C_Float_offset_for_Integer =  8388608.0f;         
#endif


const t_float float_zero        =  0.0;
const t_float float_one         =  1.0;
const t_float float_minus_one   = -1.0;

t_float Floor (const t_float X)
{
   t_float v_result;
   volatile t_float temp;

   /* if X IS equal NaN then Floor returns NaN */
   if (IsNan(X) != FALSE)
   {
      /* Return the NaN value */
      v_result = M_D_NAN;
   }
   else
   {
      if (X >= float_zero)
      {
         /* X is positive */
         /* All positiv subnormal values shall be set to zero. */
         if (X < float_one)
         {
            v_result = float_zero;
         }
         else if (X >= C_Float_offset_for_Integer)
         {
            /* Above 2^(k-1) all floating point numbers are integers, */
            /* k = the amount of mantissa bits plus one (24 in FLOAT_32 ; 53 in FLOAT_64) */
            v_result = X;
         }
         else
         {
            /* Rounding to the nearest algorithm for positive X */
            temp = X + C_Float_offset_for_Integer;
            v_result = temp - C_Float_offset_for_Integer;
            /* Make from the round to nearest a Floor functionality by eventually substract one */
            if ( X < v_result )
            {
               v_result = v_result - float_one;
            }
         }
      }
      else
      {
         /* X is negative */
         /* All negativ subnormal values shall be set to minus one. */
         if (X >= float_minus_one)
         {
            v_result = float_minus_one;
         }
         else if (X <= -C_Float_offset_for_Integer)
         {
            /* Below -2^(k-1) all floating point numbers are integers */
            v_result = X;
         }
         else
         {
            /* Rounding to the nearest algorithm for negative X */
            temp = X - C_Float_offset_for_Integer;
            v_result = temp + C_Float_offset_for_Integer;
            /* Make from the round to nearest a Floor functionality by eventually substract one */
            if ( X < v_result )
            {
               v_result = v_result - float_one;
            }
         }
      }
   }

   return (v_result);
}
