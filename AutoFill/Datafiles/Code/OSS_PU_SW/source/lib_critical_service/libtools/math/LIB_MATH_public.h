/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef LIB_MATH_PUBLIC_H
#define LIB_MATH_PUBLIC_H

/* ---------- include required interface: ----------------------------------- */
#include "type/common_type.h"


/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* Remove sign of a float */
/* Words are split and stored in 32 bites */
#define C_MASK_BITS (0x7fffUL)

/* Mask to get 32 LSBits on 64 bits word */
#define C_MASK_32_LSB_ON_64    (0x00000000FFFFFFFFULL)

/* Mask to get 16 MSBits on 32 bits word */
#define C_MASK_16_MSB_ON_32    (0xFFFF0000UL)

/* Mask to get 8 MSBits on 32 bits word */
#define C_MASK_8_MSB_ON_32    (0xFF000000UL)

/* Mask to get 4 MSBits on 32 bits word */
#define C_MASK_4_MSB_ON_32    (0xF0000000UL)

/* Mask to get 2 MSBits on 32 bits word */
#define C_MASK_2_MSB_ON_32    (0xC0000000UL)

/* Mask to get the MSB on 32 bits word */
#define C_MASK_MSB_ON_32    (0x80000000UL)

/* IEEE 754: Not A Number */
#define C_NAN_FORMAT (0x7f80UL)

/* IEEE 754: Not A Number float format */
#define C_NAN_FLOAT32  ((float32_t)(0x7f800000))

/* Subnormal numbers have their exponent is equal to 1 */
#define C_EXPON_VAL_FOR_SUBNORMAL_NUM   (0x0080UL)

/* Can be used to retreive the sign of a float */
/* Value of 2^32 */
#define C_UINT_THRESHOLD   (0x8000UL)

/* Less Significant bit of the IEEE 754 mantissa is 0 */
#define C_LSB_MANTISSA_CLEARED   (0UL)

/* Define to retrieve the first MSBit on 64 bits data */
#define C_63_VALUE_ON_64_BITS   (63LL)

/* Define to retrieve the 32 MSBit */
#define C_32_MSB_ULL         (32ULL)

/* Define to retrieve the 32 MSBit */
#define C_32_MSB_UL           (32UL)

/* Define to retrieve the 16 MSBit */
#define C_16_MSB_UL            (16UL)

/* Define to retrieve the 8 MSBit */
#define C_8_MSB_UL            (8UL)

/* Define to retrieve the 4 MSBit */
#define C_4_MSB_UL            (4UL)

/* Define to retrieve the 2 MSBit */
#define C_2_MSB_UL            (2UL)

/* Define to retrieve the MSBit */
#define C_MSB_UL            (1UL)

/**** PI VALUES ****/
/* Pi/2 */

/* Pi/2 32 bits value                    =   1.5707963267948966192313216916397514420985846996876   */
/* v_PI_2 = 0x3fc90fdb                   =   1.57079637050628662109375E0                           */
#define C_PI_2_HF          0x3FC9uL
#define C_PI_2_LF           0x0FDBuL
/* v_PI_2_LOW   0xB33BBD2F               =   -4.3711391839451607665978372097E-8                    */
#define C_PI_2_LOW_HF      0xB33BuL
#define C_PI_2_LOW_LF      0xBD2FuL

   /* PI/6 */

/* Pi/6 32 bits value                     = 0.52359877559829887307710723054658381403286156656252 */
/* v_PI_6 =  0x3F060A92                   = 0.52359879016876220703125                            */
#define C_PI_6_HF         0x3F06uL
#define C_PI_6_LF         0x0A92uL
/* v_PI_6_LOW = 0xb27a5194               = -1.4570463946483869221992790699E-8                   */
#define C_PI_6_LOW_HF      0xB27AuL
#define C_PI_6_LOW_LF      0x5194uL

/* Tan Pi/12 */

/* Tan Pi/12 32 bits value               = 0.267949192431122751312244645305327139794826507568359375*/
/* v_TAN_PI_12  = 0x3E8930A3              = 0.2679491937160491943359375                            */
#define C_TAN_PI_12_HF      0x3E89uL
#define C_TAN_PI_12_LF      0x30A3uL
/* v_TAN_PI_12_LOW =  0xB0B09955          = -1.28492649853484408595249988139E-9                      */
#define C_TAN_PI_12_LOW_HF   0xB0B0uL
#define C_TAN_PI_12_LOW_LF   0x9955uL

/* Tan Pi/6 */

/* Tan Pi/6 32 bits value                 = 0.57735026918962584208117050366126932203769683837890625 */
/* v_TAN_PI_6   = 0x3F13CD3A              = 0.57735025882720947265625                            */
#define C_TAN_PI_6_HF      0x3F13uL
#define C_TAN_PI_6_LF      0xCD3AuL
/* v_TAN_PI_6_LOW = 0x32320664            = 1.03624167024918278912082314491E-8                 */
#define C_TAN_PI_6_LOW_HF   0x3232uL
#define C_TAN_PI_6_LOW_LF   0x0664uL



/* ---------- provided data: ------------------------------------------------ */

/* ---------- provided operations: ------------------------------------------ */

extern float32_t LIB_MATH_ATAN_CALC(const float32_t p_input);

extern float32_t LIB_MATH_COPYSIGN(const float32_t p_input_x, const float32_t p_input_y);


/* */
extern int64_t LIB_MATH_DIV64 ( int64_t const v_dividend ,
                                int64_t const v_divisor ) ;

extern float32_t LIB_MATH_FABS(const float32_t p_input);

extern te_CMN_FLAG_VALIDITY LIB_MATH_IS_INF(const float32_t p_input);

extern te_CMN_FLAG_VALIDITY LIB_MATH_IS_NAN_OR_INF(const float32_t p_input);

extern te_CMN_FLAG_VALIDITY LIB_MATH_IS_ZERO_OR_SUBNORMAL(const float32_t p_input);

extern float32_t LIB_MATH_POSITIVE_ATAN(const float32_t p_input);

extern float32_t sqrt(const float32_t p_input);

extern uint64_t LIB_MATH_UDIV64( uint64_t const p_dividend,
                                 uint64_t const p_divisor);

extern uint64_t LIB_MATH_UDIV64_DIV_U64( uint64_t const p_dividend,
                                         uint32_t const p_divisor );

extern uint64_t LIB_MATH_UDIV64_DIV_U64_REM(uint64_t const p_dividend,
                                            uint32_t const p_divisor,
                                            uint32_t * const p_pa_remainder);

extern uint32_t LIB_MATH_UDIV64_DIV64_32(uint64_t * const p_pa_n,
                                         uint32_t const p_base);

extern uint32_t LIB_MATH_UDIV64_FLS(uint32_t const p_data);

extern uint64_t LIB_MATH_UDIV64_LSR64( uint64_t const p_ulong,
                                       uint32_t const p_shift);


extern uint64_t LIB_MATH_UREM64(uint64_t const p_dividend,
                                uint64_t const p_divisor);

extern uint64_t lib_math_umul64( uint64_t const p_op1,
                                 uint64_t const p_op2 );

#endif /* LIBUTILS_LIB_MATH_PUBLIC_H */
