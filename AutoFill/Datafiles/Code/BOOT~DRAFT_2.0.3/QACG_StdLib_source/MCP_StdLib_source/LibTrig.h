#ifndef LIBTRIG_H
#define LIBTRIG_H

/*-------------------------------------------------------------------------------------------------------------------*/
/* PROJECT : Unified Standard Library                                                                                */
/*-------------------------------------------------------------------------------------------------------------------*/
/* COMPANY : SAGEM                                                                                                   */
/*-------------------------------------------------------------------------------------------------------------------*/
/* CSU NAME : LibTrig                                                                                                */
/* FILENAME : LibTrig.h                                                                                              */
/*-------------------------------------------------------------------------------------------------------------------*/

#include "BaseType.h"

#define C_QUADRANT_0 0L
#define C_QUADRANT_1 1L
#define C_QUADRANT_2 2L
#define C_QUADRANT_3 3L

#define M_D_PI            C_D_PI.d
#define M_D_PI_LOW        C_D_PI_LOW.d
#define M_D_PI_2          C_D_PI_2.d
#define M_D_PI_2_LOW      C_D_PI_2_LOW.d
#define M_D_PI_4          C_D_PI_4.d
#define M_D_PI_4_LOW      C_D_PI_4_LOW.d
#define M_D_PI_6          C_D_PI_6.d
#define M_D_PI_6_LOW      C_D_PI_6_LOW.d

#define M_D_TAN_PI_6      C_D_TAN_PI_6.d
#define M_D_TAN_PI_6_LOW  C_D_TAN_PI_6_LOW.d
#define M_D_TAN_PI_12     C_D_TAN_PI_12.d
#define M_D_TAN_PI_12_LOW C_D_TAN_PI_12_LOW.d

/* Maximum input value for Trigonometric Functions */
#if defined (FLOAT_64)
#define C_MAX_INPUT    ((t_float)(1.0E+5))
#elif defined (FLOAT_32)
#define C_MAX_INPUT    ((t_float)(1.0E+4))
#endif


extern t_float ReducedSin(const t_float X);
extern t_float ReducedCos(const t_float X);
extern t_float PositiveAtan(const t_float X);
extern t_int_32 SinCosRangeReduc(const t_float X, t_float * const pa_RedX);

extern const TU_LIB_MATH_IEEE C_D_PI;
extern const TU_LIB_MATH_IEEE C_D_PI_LOW;
extern const TU_LIB_MATH_IEEE C_D_PI_2;
extern const TU_LIB_MATH_IEEE C_D_PI_2_LOW;
extern const TU_LIB_MATH_IEEE C_D_PI_4;
extern const TU_LIB_MATH_IEEE C_D_PI_4_LOW;
extern const TU_LIB_MATH_IEEE C_D_PI_6;
extern const TU_LIB_MATH_IEEE C_D_PI_6_LOW;
extern const TU_LIB_MATH_IEEE C_D_TAN_PI_6_LOW;
extern const TU_LIB_MATH_IEEE C_D_TAN_PI_12;
extern const TU_LIB_MATH_IEEE C_D_TAN_PI_12_LOW;

#endif /* LIBTRIG_H */
