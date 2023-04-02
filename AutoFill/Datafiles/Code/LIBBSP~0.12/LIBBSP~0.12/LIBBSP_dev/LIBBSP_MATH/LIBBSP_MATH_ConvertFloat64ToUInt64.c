#include "LIBBSP_MATH_Casts.h"

 void LIBBSP_MATH_ConvertFloat64ToUInt64  (const float64_t     v_Value_Float64,                                           uint64_t  * const   pa_Value_UInt64) {    float64_t v_MSB;    float64_t v_LSB;    uint32_t v_MSBUint;    v_MSB = v_Value_Float64 / C_LIBMATH_CONST_FL64_2EXP32;    v_LSB = v_Value_Float64 - (((float64_t)((uint32_t)v_MSB)) * C_LIBMATH_CONST_FL64_2EXP32);    v_MSBUint = (uint32_t)v_MSB;    *pa_Value_UInt64 =(uint64_t)((uint64_t)v_MSBUint << C_LIBMATH_CONST_NB_BIT_WORD32) + (uint64_t)((uint32_t)v_LSB); }
