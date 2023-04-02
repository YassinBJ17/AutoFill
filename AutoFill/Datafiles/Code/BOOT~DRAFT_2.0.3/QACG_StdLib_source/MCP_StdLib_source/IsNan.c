/*-------------------------------------------------------------------------------------------------------------------*/
/* PROJECT : Unified Standard Library                                                                                */
/*-------------------------------------------------------------------------------------------------------------------*/
/* COMPANY : SAGEM                                                                                                   */
/*-------------------------------------------------------------------------------------------------------------------*/
/* CSU NAME : IsNan                                                                                                */
/* FILENAME : IsNan.c                                                                                              */
/*-------------------------------------------------------------------------------------------------------------------*/
#include "BaseType.h"
#include "LibIEEE.h"
#include "IsNan.h"

/* Least significant part of the floating-point number is 0 */
#if defined (FLOAT_64)
#define C_NULL_LOW ((t_uint_32)0ul)
#elif defined (FLOAT_32)
#define C_NULL_LOW ((t_uint_16)0u)
#endif


/*-------------------------------------------------------------------------------------------------------------------*/
/* Function: IsNan                                                                                                   */
/*-------------------------------------------------------------------------------------------------------------------*/
/* Description: Indicates if the argument is equal to NaN.                                                           */
/*                                                                                                                   */
/* Pre-condition:  none                                                                                              */
/*                                                                                                                   */
/* Input: x : input value to evaluate                                                                                */
/* Output: none                                                                                                      */
/* Return: result : TRUE if argument is NaN, FALSE otherwise.                                                        */
/*-------------------------------------------------------------------------------------------------------------------*/

t_boolean IsNan(const t_float x)
{
   /* Declarations */
   TU_LIB_MATH_IEEE md;
   #if defined (FLOAT_64)
   t_uint_32 high;
   #elif defined (FLOAT_32)
   t_uint_16 high;
   #endif  
   t_boolean result;

   /* Initializations */
   md.d = x;
   high = md.i.high;
   high = high & C_SIGN_MASK_HIGH;
   result = FALSE;

   /* Statements */
   if ((high > C_INF_NAN_FORMAT_HIGH) || ((high == C_INF_NAN_FORMAT_HIGH) && (md.i.low > C_NULL_LOW)))
   {
      result = TRUE;
   }
   return (result);
}
