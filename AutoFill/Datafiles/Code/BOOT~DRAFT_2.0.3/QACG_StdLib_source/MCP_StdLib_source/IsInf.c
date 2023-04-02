/*-------------------------------------------------------------------------------------------------------------------*/
/* PROJECT : Unified Standard Library                                                                                */
/*-------------------------------------------------------------------------------------------------------------------*/
/* COMPANY : SAGEM                                                                                                   */
/*-------------------------------------------------------------------------------------------------------------------*/
/* CSU NAME : LibIEEE                                                                                                */
/* FILENAME : LibIEEE.c                                                                                              */
/*-------------------------------------------------------------------------------------------------------------------*/

#include "BaseType.h"
#include "LibIEEE.h"
#include "IsInf.h"

/* Least significant part of the floating-point number is 0 */
#if defined (FLOAT_64)
#define C_NULL_LOW ((t_uint_32)0ul)
#elif defined (FLOAT_32)
#define C_NULL_LOW ((t_uint_16)0u)
#endif


/*-------------------------------------------------------------------------------------------------------------------*/
/* Function: IsInf                                                                                                   */
/*-------------------------------------------------------------------------------------------------------------------*/
/* Description: Indicates if the argument is equal to +Inf or -Inf.                                                  */
/*                                                                                                                   */
/* Pre-condition:  none                                                                                              */
/*                                                                                                                   */
/* Input: x : input value to evaluate                                                                                */
/* Output: none                                                                                                      */
/* Return: result : TRUE if X=+/-Inf, FALSE otherwize.                                                               */
/*-------------------------------------------------------------------------------------------------------------------*/

t_boolean IsInf(const t_float x)
{
   /* Declarations */
   TU_LIB_MATH_IEEE md;
   t_boolean result;

   /* Initializations */
   md.d = x;
   result = FALSE;

   /* Statements */
   if (((md.i.high & C_SIGN_MASK_HIGH) == C_INF_NAN_FORMAT_HIGH) && (md.i.low == C_NULL_LOW))
   {
      result = TRUE;
   }
   return (result);
}
