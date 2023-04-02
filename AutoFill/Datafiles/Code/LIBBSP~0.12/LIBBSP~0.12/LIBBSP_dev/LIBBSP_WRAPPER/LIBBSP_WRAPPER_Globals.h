/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_WRAPPER_GLOBALS_H
#define LIBBSP_WRAPPER_GLOBALS_H

#include "LIBBSP_WRAPPER.h"
#include "LIBBSP_IMU_RAMTIC.h"

/*==== Definitions =====================================================================*/
#define C_NB_MAX_ADDITIONAL_DATA  13
#define C_IMU_ADDITIONAL_NB_DATA_TO_READ 5
/*IMU defines*/
#define C_FIRST_INDEX 2
#define C_SIZE 19
/*WRAPPER DEFINES*/
#define C_UINT8_SIZE 8

extern const uint32_t C_IMU_ADDITIONAL_DATA_TO_READ_0[C_IMU_ADDITIONAL_NB_DATA_TO_READ];
extern const uint32_t C_IMU_ADDITIONAL_DATA_TO_READ_1[C_IMU_ADDITIONAL_NB_DATA_TO_READ];
extern const uint32_t C_IMU_ADDITIONAL_DATA_TO_READ_2[C_IMU_ADDITIONAL_NB_DATA_TO_READ];
extern const uint32_t C_IMU_ADDITIONAL_DATA_TO_READ_3[C_IMU_ADDITIONAL_NB_DATA_TO_READ];
extern const uint32_t C_IMU_ADDITIONAL_DATA_TO_READ_4[C_IMU_ADDITIONAL_NB_DATA_TO_READ];
extern const uint32_t C_IMU_ADDITIONAL_DATA_TO_READ_5[C_IMU_ADDITIONAL_NB_DATA_TO_READ];
extern const uint32_t C_IMU_ADDITIONAL_DATA_TO_READ_6[C_IMU_ADDITIONAL_NB_DATA_TO_READ];
extern const uint32_t C_IMU_ADDITIONAL_DATA_TO_READ_7[C_IMU_ADDITIONAL_NB_DATA_TO_READ];
extern const uint32_t C_IMU_ADDITIONAL_DATA_TO_READ_8[C_IMU_ADDITIONAL_NB_DATA_TO_READ];
extern const uint32_t C_IMU_ADDITIONAL_DATA_TO_READ_9[C_IMU_ADDITIONAL_NB_DATA_TO_READ];
extern const uint32_t C_IMU_ADDITIONAL_DATA_TO_READ_10[C_IMU_ADDITIONAL_NB_DATA_TO_READ];
extern const uint32_t C_IMU_ADDITIONAL_DATA_TO_READ_11[C_IMU_ADDITIONAL_NB_DATA_TO_READ];
extern const uint32_t C_IMU_ADDITIONAL_DATA_TO_READ_12[C_IMU_ADDITIONAL_NB_DATA_TO_READ];
extern const uint32_t C_IMU_ADDITIONAL_DATA_TO_READ_13[C_IMU_ADDITIONAL_NB_DATA_TO_READ];
extern const uint32_t C_IMU_ADDITIONAL_DATA_TO_READ_14[C_IMU_ADDITIONAL_NB_DATA_TO_READ];
extern const uint32_t C_IMU_ADDITIONAL_DATA_TO_READ_15[C_IMU_ADDITIONAL_NB_DATA_TO_READ];
extern const uint32_t C_IMU_ADDITIONAL_DATA_TO_READ_16[C_IMU_ADDITIONAL_NB_DATA_TO_READ];
extern const uint32_t * const C_LINK_CYCLE_DATA[C_SIZE];
extern const uint8_t C_MASK_AND[C_UINT8_SIZE];

extern const uint8_t C_MASK_OR[C_UINT8_SIZE];


/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

/*==== END =============================================================================*/
#endif
