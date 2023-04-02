#ifndef LIBIEEE_H
#define LIBIEEE_H

/*-------------------------------------------------------------------------------------------------------------------*/
/* PROJECT : Unified Standard Library                                                                                */
/*-------------------------------------------------------------------------------------------------------------------*/
/* COMPANY : SAGEM                                                                                                   */
/*-------------------------------------------------------------------------------------------------------------------*/
/* CSU NAME : LibIEEE                                                                                                */
/* FILENAME : LibIEEE.h                                                                                              */
/*-------------------------------------------------------------------------------------------------------------------*/

#include "BaseType.h"


/* NaN, positive and negative Infinity values */
#define M_D_NAN   C_D_NAN.d
#define M_D_PINF  C_D_PINF.d
#define M_D_MINF  C_D_MINF.d

/* Can be used to retreive the sign of a float */
/* Value of 2^32 */
#if defined (FLOAT_64)
#define C_UINT_THRESHOLD   ((t_uint_32)0x80000000ul)
#elif defined (FLOAT_32)
#define C_UINT_THRESHOLD   ((t_uint_16)0x8000u)
#endif

/* Floating-point mask to remove the sign of a float, number higher half */
#if defined (FLOAT_64)
#define C_SIGN_MASK_HIGH ((t_uint_32)0x7ffffffful)
#elif defined (FLOAT_32)
#define C_SIGN_MASK_HIGH ((t_uint_16)0x7fffu)
#endif

/* Shift value for access to exponent */
#if defined (FLOAT_64)
#define C_SHIFT_EXPONENT   (20)
#elif defined (FLOAT_32)
#define C_SHIFT_EXPONENT   (7)
#endif

/* Symbolic constant for Bias factor */
#if defined (FLOAT_64)
#define C_M_EX_BIAS    (1023)
#elif defined (FLOAT_32)
#define C_M_EX_BIAS    (127)
#endif

/* Floating-point comparison value for INF and NaN, number higher half */
#if defined (FLOAT_64)
#define C_INF_NAN_FORMAT_HIGH ((t_uint_32)0x7ff00000ul)
#elif defined (FLOAT_32)
#define C_INF_NAN_FORMAT_HIGH ((t_uint_16)0x7f80u)
#endif

/* Subnormal numbers have their exponent is equal to 1 */
#if defined (FLOAT_64)
#define C_EXPON_VAL_FOR_SUBNORMAL_NUM   ((t_uint_32)0x00100000ul)
#elif defined (FLOAT_32)
#define C_EXPON_VAL_FOR_SUBNORMAL_NUM   ((t_uint_16)0x0080u)
#endif

/* Floating-point mask for the fraction part on the number higher half */
#if defined (FLOAT_64)
#define C_FRAC_MASK_HIGH   ((t_uint_32)0x000ffffful)
#elif defined (FLOAT_32)
#define C_FRAC_MASK_HIGH   ((t_uint_16)0x007fu)
#endif


extern t_boolean IsNanOrInf(const t_float x);
extern t_boolean IsZeroOrSubnormal(const t_float x);
extern t_float Abs(const t_float x);
extern t_float LdExp(const t_float x, const t_int_32 ex);
extern t_float FrExp(const t_float x, t_int_32 * const pEx);

extern const t_float C_ZERO_FLOAT;
extern const t_float C_ONE_FLOAT;
extern const t_float C_TWO_FLOAT;
extern const t_float C_THREE_FLOAT;

extern const TU_LIB_MATH_IEEE C_D_NAN;
extern const TU_LIB_MATH_IEEE C_D_PINF;
extern const TU_LIB_MATH_IEEE C_D_MINF;

#endif /* LIBIEEE_H */