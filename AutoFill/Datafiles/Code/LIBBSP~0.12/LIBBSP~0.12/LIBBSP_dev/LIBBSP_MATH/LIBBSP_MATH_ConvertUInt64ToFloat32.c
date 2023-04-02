#include "LIBBSP_MATH_Casts.h"

 void LIBBSP_MATH_ConvertUInt64ToFloat32  ( const uint64_t           v_Value_UInt64,                                            float32_t * const        pa_Value_Float32) {    uint32_t  v_MSBUInt32;    uint32_t  v_LSBUInt32;    uint64_t  v_MSBUInt64;    uint64_t  v_LSBUInt64;    float32_t v_MSBFloat32;    v_MSBUInt64 = v_Value_UInt64 & C_LIBMATH_CONST_32_BITS_MSB_MASK;    v_MSBUInt64 = v_MSBUInt64 >> C_LIBMATH_CONST_NB_BIT_WORD32;    v_MSBUInt32 = (uint32_t)v_MSBUInt64;    v_MSBFloat32 = (float32_t)v_MSBUInt32;    v_MSBFloat32 = v_MSBFloat32 * C_LIBMATH_CONST_FL32_2EXP32;    v_LSBUInt64 = v_Value_UInt64 & C_LIBMATH_CONST_32_BITS_LSB_MASK;    v_LSBUInt32 = (uint32_t)v_LSBUInt64;    *pa_Value_Float32 = v_MSBFloat32 + ((float32_t)v_LSBUInt32); }
