/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2022                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_RMM_H
#define LIBBSP_RMM_H

#include "LIBBSP_I2C.h"

/*==== Definitions =====================================================================*/

#define C_RMM_PAGE_SIZE 128

/*==== Types ===========================================================================*/
typedef enum {
    E_LIBBSP_RMM_CLOSED                  = 0,
    E_LIBBSP_RMM_OPEN                    = 1
} TE_LIBBSP_RMM_State;

/*==== Variables ========================================================================*/
extern TE_LIBBSP_RMM_State V_RMM_State;

extern const uint8_t C_RMM_24FC1025_B0_ADDR;
extern const uint8_t C_RMM_24FC1025_B1_ADDR;
extern const TE_LIBBSP_I2C_Bus C_RMM_USED_BUS;
extern const TE_LIBBSP_I2C_FreqDiv C_RMM_DIVISOR_VALUE;
extern const uint8_t C_RMM_DIGITAL_FILTER;

/*==== Services ========================================================================*/

extern TE_LIBBSP_I2C_Code LIBBSP_RMM_Close(void);
extern TE_LIBBSP_I2C_Code LIBBSP_RMM_Open(void);
extern void LIBBSP_RMM_Read(const uint32_t rmmAddress, const uint32_t size, uint8_t * const buffer, TE_LIBBSP_I2C_Code * const v_ret);
extern void LIBBSP_RMM_Write(const uint32_t rmmAddress, const uint32_t size, uint8_t * const buffer, TE_LIBBSP_I2C_Code * const v_ret);

#endif /* LIBBSP_RMM_H */
