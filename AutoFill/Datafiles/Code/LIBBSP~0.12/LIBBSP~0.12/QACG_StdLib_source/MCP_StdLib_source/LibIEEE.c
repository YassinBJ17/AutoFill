/*-------------------------------------------------------------------------------------------------------------------*/
/* PROJECT : Unified Standard Library                                                                                */
/*-------------------------------------------------------------------------------------------------------------------*/
/* COMPANY : SAGEM                                                                                                   */
/*-------------------------------------------------------------------------------------------------------------------*/
/* CSU NAME : LibIEEE                                                                                                */
/* FILENAME : LibIEEE.c                                                                                              */
/*-------------------------------------------------------------------------------------------------------------------*/

#include "LibIEEE.h"
#include "CopySign.h"


/* Max value for the exponent  */
#if defined (FLOAT_64)
/* 2^11 - 1 */
#define C_EXPON_BITS_MAX_VAL   (2047)
#elif defined (FLOAT_32)
/* 2^8 - 1 */
#define C_EXPON_BITS_MAX_VAL   (255)
#endif

#if defined (FLOAT_64)
#define C_MASK_EXPONENT    ((t_uint_32) 0x800ffffful)
#elif defined (FLOAT_32)
#define C_MASK_EXPONENT    ((t_uint_16) 0x807fu)
#endif

/*Float constants used in various computation representable in IEEE754 Single and Double precision */ 
const t_float C_ZERO_FLOAT = 0.0;
const t_float C_ONE_FLOAT = 1.0;
const t_float C_TWO_FLOAT = 2.0;
const t_float C_THREE_FLOAT = 3.0;

/* NaN and positive and negative Infinity IEEE 754 representations */
#if defined (FLOAT_64)
const TU_LIB_MATH_IEEE C_D_NAN    = {0x7FFFFFFFul, 0xFFFFFFFFul};
const TU_LIB_MATH_IEEE C_D_PINF   = {0x7FF00000ul, 0x00000000ul};
const TU_LIB_MATH_IEEE C_D_MINF   = {0xFFF00000ul, 0x00000000ul};
#elif defined (FLOAT_32)
const TU_LIB_MATH_IEEE C_D_NAN    = {0x7FFFu, 0xFFFFu}; 
const TU_LIB_MATH_IEEE C_D_PINF   = {0x7F80u, 0x0000u};
const TU_LIB_MATH_IEEE C_D_MINF   = {0xFF80u, 0x0000u};
#endif


/*-------------------------------------------------------------------------------------------------------------------*/
/* Function:   IsNanOrInf                                                                                            */
/*-------------------------------------------------------------------------------------------------------------------*/
/* Description: Indicates if X is equal to +Inf, -Inf or NaN                                                         */
/*                                                                                                                   */
/* Pre-condition:  none                                                                                              */
/*                                                                                                                   */
/* Input: X : input value to be analyzed                                                                             */
/* Output: none                                                                                                      */
/* Return: result : TRUE if argument is +Inf, -Inf or NaN, FALSE otherwize                                           */
/*-------------------------------------------------------------------------------------------------------------------*/

t_boolean IsNanOrInf(const t_float x)
{
   /* Declarations */
   TU_LIB_MATH_IEEE md;
   t_boolean result;

   /* Initializations */
   md.d = x;
   result = FALSE;

   /* Statements */
   if ((md.i.high & C_SIGN_MASK_HIGH) >= C_INF_NAN_FORMAT_HIGH)
   {
      result = TRUE;
   }

   return (result);
}


/*-------------------------------------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------------------------------*/
/* Function: IsZeroOrSubnormal                                                                                       */
/*-------------------------------------------------------------------------------------------------------------------*/
/* Description: Indicates if the argument is 0.0 or Subnormal, that is to say exponent equals to 1                   */
/*                                                                                                                   */
/* Pre-condition:  none                                                                                              */
/*                                                                                                                   */
/* Input: x : input value to evaluate                                                                                */
/* Output: none                                                                                                      */
/* Return: result : TRUE if argument is 0.0 or Subnormal, FALSE otherwise.                                           */
/*-------------------------------------------------------------------------------------------------------------------*/
t_boolean IsZeroOrSubnormal(const t_float x)
{
   /* Declarations */
   TU_LIB_MATH_IEEE md;
   t_boolean result;

   /* Initializations */
   md.d = x;
   result = FALSE;

   /* Statements */
   if ((md.i.high & C_SIGN_MASK_HIGH) < C_EXPON_VAL_FOR_SUBNORMAL_NUM)
   {
      result = TRUE;
   }
   return (result);
} 


/*-------------------------------------------------------------------------------------------------------------------*/
/* Function:   Abs                                                                                                   */
/*-------------------------------------------------------------------------------------------------------------------*/
/* Description: Returns the absolute value of the argument                                                           */
/*                                                                                                                   */
/* Pre-condition:  none                                                                                              */
/*                                                                                                                   */
/* Input: x : input value from which the absolute value is computed                                                  */
/* Output: none                                                                                                      */
/* Return: result : the absolute value of the argument                                                               */
/*-------------------------------------------------------------------------------------------------------------------*/

t_float Abs(const t_float x)
{
   /* Declarations */
   TU_LIB_MATH_IEEE md;
   t_float result;

   /* Initializations */
   md.d = x;

   /* Statements */
   md.i.high = md.i.high & C_SIGN_MASK_HIGH;

   result = md.d;
   return (result);
}


/*-------------------------------------------------------------------------------------------------------------------*/
/* Function:   LdExp                                                                                                 */
/*-------------------------------------------------------------------------------------------------------------------*/
/* Description: Computes x*2^ex                                                                                      */
/*                                                                                                                   */
/* Pre-condition:  none                                                                                              */
/*                                                                                                                   */
/* Input: X : mantissa used for the computation                                                                      */
/*        ex : exponent for the computation                                                                          */
/* Output: none                                                                                                      */
/* Return: result : return the computation x*2^ex                                                                    */
/*-------------------------------------------------------------------------------------------------------------------*/

t_float LdExp(const t_float x, const t_int_32 ex)
{
   /* Declarations */
   TU_LIB_MATH_IEEE md;
   t_float result;
   t_int_32 exx;
   #if defined (FLOAT_64)
   t_uint_32 ix;
   t_uint_32 hx;
   t_uint_32 exp;
   #elif defined (FLOAT_32)
   t_uint_16 ix;
   t_uint_16 hx;
   t_uint_16 exp;
   #endif
    
   /* Initializations */
   md.d = x;
   result = C_ZERO_FLOAT;

   /* Statements */
   hx = md.i.high;
   ix = hx & C_SIGN_MASK_HIGH;
   
   /* If x is Inf or NaN, return the same */
   if (IsNanOrInf(x) != FALSE)
   {
      result = x;
   }
   /* If x is 0 or Subnormal, return zero */
   else if (IsZeroOrSubnormal(x) != FALSE)
   {
      result = C_ZERO_FLOAT;
   }
   /* Handle normal numbers */
   else
   {
      /* Extract exponent of x */
      exx = ((t_int_32) ix >> C_SHIFT_EXPONENT);
      /* Detect exponent overflow: value of 0x7FF is 2047 */
      if (ex >= ((t_int_32)C_EXPON_BITS_MAX_VAL - exx))
      {
         /* Result is Inf  */
         result = M_D_PINF;
         result = CopySign(result, x);
      }
      /* Detect exponent underflow or subnormal result */
      else
      {
         if (ex <= (-exx))
         {
            /* Result is 0.0 */
            result = C_ZERO_FLOAT;
            result = CopySign(result, x);
         }
         /* Handle normal results */
         else
         {
            /* Forget original exponent */
            hx = hx & C_MASK_EXPONENT;
            /* Set exponent to exx+ex,  0 < exx+ex < 0x7FF  */
            #if defined (FLOAT_64)
            exp = (((t_uint_32)exx + (t_uint_32)ex) << C_SHIFT_EXPONENT);
            #elif defined (FLOAT_32)
            exp = (((t_uint_16)exx + (t_uint_16)ex) << C_SHIFT_EXPONENT);

            #endif

            /* Reconstitute md.i.high */
            md.i.high = hx | exp;
            result = md.d;
         }
      }
   }
   return (result);
}


/*-------------------------------------------------------------------------------------------------------------------*/
/* Function:   FrExp                                                                                                 */
/*-------------------------------------------------------------------------------------------------------------------*/
/* Description: Decompose the argument x into a fraction fr and an exponent ex such as x=fr*2^ex and 0.5<=|fr|<1     */
/* If x equals 0.0, INF or NaN then fr equals x and ex equals 0.                                                     */
/*                                                                                                                   */
/* Pre-condition:  none                                                                                              */
/*                                                                                                                   */
/* Input: x : Input from which the decomposition is performed                                                        */
/* Output: pEx : exponent of input x                                                                                 */
/* Return: result : fraction of input x such as 0.5 <= |fr| < 1                                                      */
/*-------------------------------------------------------------------------------------------------------------------*/

t_float FrExp(const t_float x, t_int_32 * const pEx)
{
   /* Declarations */
   TU_LIB_MATH_IEEE md;
   #if defined (FLOAT_64)
   t_uint_32 hx;
   t_uint_32 ix;
   t_uint_32 ex;
   #elif defined (FLOAT_32)
   t_uint_16 hx;
   t_uint_16 ix;
   t_uint_16 ex;
   #endif

   t_float result;

   /* Initializations */
   md.d = x;
   result = C_ZERO_FLOAT;
   *pEx = 0L;

   /* Statements */
   hx = md.i.high;
   ix = hx & C_SIGN_MASK_HIGH;

   /* If x is Inf or NaN, return the same */
   if (IsNanOrInf(x) != FALSE)
   {
      result = x;
   }
   /* If x is 0 or Subnormal, return zero */
   else if (IsZeroOrSubnormal(x) != FALSE)
   {
      result = C_ZERO_FLOAT;
   }
   else
   {
      /* Get the exponent value */
      *pEx = (((t_int_32)ix >> C_SHIFT_EXPONENT) - (t_int_32)(C_M_EX_BIAS - 1));
      /* Forget original exponent */
      hx = (hx & C_MASK_EXPONENT);
      /* Set exponent to 0 */
      #if defined (FLOAT_64)
      ex = ((t_uint_32) (C_M_EX_BIAS - 1) << C_SHIFT_EXPONENT);
      #elif defined (FLOAT_32)
      ex = ((t_uint_16) (C_M_EX_BIAS - 1) << C_SHIFT_EXPONENT);
      #endif
      /* And the fraction fr so that 0.5 <= |fr| < 1 */
      md.i.high = (hx | ex);
      result = md.d;
   }
   return (result);
}


