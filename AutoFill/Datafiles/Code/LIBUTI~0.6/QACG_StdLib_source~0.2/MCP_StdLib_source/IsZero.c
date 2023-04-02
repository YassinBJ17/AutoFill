/*-------------------------------------------------------------------------------------------------------------------*/
/* PROJECT : Unified Standard Library                                                                                */
/*-------------------------------------------------------------------------------------------------------------------*/
/* COMPANY : SAGEM                                                                                                   */
/*-------------------------------------------------------------------------------------------------------------------*/
/* CSU NAME : IsZero                                                                                                */
/* FILENAME : IsZero.c                                                                                              */
/*-------------------------------------------------------------------------------------------------------------------*/

#include "BaseType.h"
#include "LibIEEE.h"
#include "IsZero.h"

/* Least or most significant part of the floating-point number is 0 */
#if defined (FLOAT_64)
#define C_NULL ((t_uint_32)0x00000000ul)
#elif defined (FLOAT_32)
#define C_NULL ((t_uint_16)0x0000u)
#endif

/*-------------------------------------------------------------------------------------------------------------------*/
/* Function: IsZero                                                                                                   */
/*-------------------------------------------------------------------------------------------------------------------*/
/* Description: Indicates if the argument is equal to +Inf or -Inf.                                                  */
/*                                                                                                                   */
/* Pre-condition:  none                                                                                              */
/*                                                                                                                   */
/* Input: x : input value to evaluate                                                                                */
/* Output: none                                                                                                      */
/* Return: result : TRUE if X=+/-Inf, FALSE otherwize.                                                               */
/*-------------------------------------------------------------------------------------------------------------------*/

t_boolean IsZero(const t_float x)
{

   /* Declarations */
   TU_LIB_MATH_IEEE md;
   t_boolean result;

   /* Initializations */
   md.d = x;
   result = FALSE;

   /* Statements */

   if ((md.i.low == C_NULL) && ((md.i.high & C_SIGN_MASK_HIGH) == C_NULL))
   {

      result = TRUE;
   }

   return (result);
}
