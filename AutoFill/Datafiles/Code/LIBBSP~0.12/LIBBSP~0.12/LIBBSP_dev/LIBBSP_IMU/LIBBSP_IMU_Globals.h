/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_IMU_GLOBALS_H
#define LIBBSP_IMU_GLOBALS_H

#include "LIBBSP_IMU.h"
#include "LIBBSP_MEGREG.h"
#include "LIBBSP_IMU_RAMTIC.h"
#define C_IMU_DATA_TO_READ_MAX 64

/*==== Definitions =====================================================================*/
typedef enum {
	E_LIBBSP_IMU_INDEX_0,
	E_LIBBSP_IMU_INDEX_1,
	E_LIBBSP_IMU_INDEX_2,
	E_LIBBSP_IMU_INDEX_3,
	E_LIBBSP_IMU_INDEX_4,
	E_LIBBSP_IMU_INDEX_5,
	E_LIBBSP_IMU_INDEX_6,
	E_LIBBSP_IMU_INDEX_7,
	E_LIBBSP_IMU_INDEX_8,
	E_LIBBSP_IMU_INDEX_9,
	E_LIBBSP_IMU_INDEX_10,
	E_LIBBSP_IMU_INDEX_11,
	E_LIBBSP_IMU_INDEX_12,
	E_LIBBSP_IMU_INDEX_13,
	E_LIBBSP_IMU_INDEX_14,
	E_LIBBSP_IMU_INDEX_15,
	E_LIBBSP_IMU_INDEX_16,
	E_LIBBSP_IMU_INDEX_17,
	E_LIBBSP_IMU_INDEX_18,
	E_LIBBSP_IMU_INDEX_19,
	E_LIBBSP_IMU_INDEX_20,
	E_LIBBSP_IMU_INDEX_21,
	E_LIBBSP_IMU_INDEX_22,
	E_LIBBSP_IMU_INDEX_23,
	E_LIBBSP_IMU_INDEX_24,
	E_LIBBSP_IMU_INDEX_25,
	E_LIBBSP_IMU_INDEX_26,
	E_LIBBSP_IMU_INDEX_27,
	E_LIBBSP_IMU_INDEX_28,
	E_LIBBSP_IMU_INDEX_29,
	E_LIBBSP_IMU_INDEX_30,
	E_LIBBSP_IMU_INDEX_31,
	E_LIBBSP_IMU_INDEX_32,
	E_LIBBSP_IMU_INDEX_33,
	E_LIBBSP_IMU_INDEX_34,
	E_LIBBSP_IMU_INDEX_35,
	E_LIBBSP_IMU_INDEX_36,
	E_LIBBSP_IMU_INDEX_37,
	E_LIBBSP_IMU_INDEX_38,
	E_LIBBSP_IMU_INDEX_39,
	E_LIBBSP_IMU_INDEX_40,
	E_LIBBSP_IMU_INDEX_41,
	E_LIBBSP_IMU_INDEX_42,
	E_LIBBSP_IMU_INDEX_43,
	E_LIBBSP_IMU_INDEX_44,
	E_LIBBSP_IMU_INDEX_45,
	E_LIBBSP_IMU_INDEX_46,
	E_LIBBSP_IMU_INDEX_47,
	E_LIBBSP_IMU_INDEX_48,
	E_LIBBSP_IMU_INDEX_49,
	E_LIBBSP_IMU_INDEX_50,
	E_LIBBSP_IMU_INDEX_51,
	E_LIBBSP_IMU_INDEX_52,
	E_LIBBSP_IMU_INDEX_53,
	E_LIBBSP_IMU_INDEX_54,
	E_LIBBSP_IMU_INDEX_55,
	E_LIBBSP_IMU_INDEX_56,
	E_LIBBSP_IMU_INDEX_57,
	E_LIBBSP_IMU_INDEX_58,
	E_LIBBSP_IMU_INDEX_59,
	E_LIBBSP_IMU_INDEX_60,
	E_LIBBSP_IMU_INDEX_61,
	E_LIBBSP_IMU_INDEX_62,
	E_LIBBSP_IMU_INDEX_63
} TE_LIBBSP_IMU_DataIndex;

extern const uint32_t C_IMU_MASK_23_MSB_BITS;
extern const uint32_t C_IMU_SHIFT_8_BITS;
extern const uint32_t C_IMU_MASK_BIT_31;
extern const uint32_t C_IMU_MASK_31_MSB_BITS;
extern const uint32_t C_IMU_SHIFT_11_BITS;
extern const uint32_t C_IMU_MASK_11_MSB_BITS;
extern const uint32_t C_IMU_SHIFT_21_BITS;
extern const uint32_t C_IMU_EXPONENT_BIAS_SINGLE_PRECISION;
extern const uint32_t C_IMU_EXPONENT_BIAS_DOUBLE_PRECISION;
extern const uint32_t C_IMU_EXPONENT_VALUE_MAX_SINGLE_PRECISION;
extern const uint32_t C_IMU_EXPONENT_VALUE_MAX_DOUBLE_PRECISION;
extern const uint32_t C_IMU_MASK_BIT_23;
extern const uint32_t C_IMU_MASK_BIT_20;
extern const uint32_t C_IMU_SHIFT_3_BITS;
extern const uint32_t C_IMU_MASK_3_MSB_BITS;
extern const uint32_t C_IMU_SHIFT_29_BITS;

extern const uint32_t C_IMU_SW2HW_EN_CONSISTENT_DATA;

extern const uint32_t C_IMU_BLADE_TIC_NB_DATA_READ_MAX;

extern const uint32_t C_IMU_BLADE_TIC_NB_DATA_WRITE_MAX;

extern const uint32_t C_IMU_INERTIAL_DATA_TO_READ[C_IMU_NB_INERTIAL_DATA_TO_READ];

extern const uint32_t C_IMU_SW2HW_NB_REGISTERS;

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

/*==== END =============================================================================*/
#endif
