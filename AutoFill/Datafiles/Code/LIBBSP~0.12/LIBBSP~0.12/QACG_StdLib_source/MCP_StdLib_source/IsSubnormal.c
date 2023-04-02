/*-------------------------------------------------------------------------------------------------------------------*/
/* PROJECT : Unified Standard Library                                                                                */
/*-------------------------------------------------------------------------------------------------------------------*/
/* COMPANY : SAGEM                                                                                                   */
/*-------------------------------------------------------------------------------------------------------------------*/
/* CSU NAME : IsSubnormal                                                                                            */
/* FILENAME : IsSubnormal.h                                                                                          */
/*-------------------------------------------------------------------------------------------------------------------*/

#include "BaseType.h"
#include "LibIEEE.h"
#include "IsSubnormal.h"

/* Least or most significant part of the floating-point number is 0 */
#if defined (FLOAT_64)
#define C_NULL ((t_uint_32)0x00000000ul)
#elif defined (FLOAT_32)
#define C_NULL ((t_uint_16)0x0000u)
#endif

t_boolean IsSubnormal(const t_float x)
{

   /* Declarations */
   TU_LIB_MATH_IEEE md;
   t_boolean result;

   /* Initializations */
   md.d = x;
   result = FALSE;

   /* Statements */
   if ((md.i.high & C_INF_NAN_FORMAT_HIGH) == C_NULL)
   {
      if ((md.i.low != C_NULL) || ((md.i.high & C_FRAC_MASK_HIGH) != C_NULL))
      {
         result = TRUE;
      }
   }
   
   return (result);
}
