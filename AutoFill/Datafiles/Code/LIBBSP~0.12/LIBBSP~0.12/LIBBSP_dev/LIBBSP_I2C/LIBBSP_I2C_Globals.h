/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_I2C_GLOBALS_H
#define LIBBSP_I2C_GLOBALS_H

#include "LIBBSP_I2C.h"
#include "LIBBSP_CCSR.h"
#include "LIBBSP_CMN.h"

/*==== Definitions =====================================================================*/
extern volatile TS_LIBBSP_I2C_RegisterSet* const P_I2C_RegAddress;
/*==== Variables =======================================================================*/

extern TE_LIBBSP_I2C_DeviceState V_I2C_State[E_LIBBSP_I2C_NB_I2C_BUS];
extern uint8_t V_I2C_BuffWrite[E_LIBBSP_I2C_NB_I2C_BUS][C_I2C_NB_BYTE_MAX];
extern uint8_t V_I2C_BuffRead[E_LIBBSP_I2C_NB_I2C_BUS][C_I2C_NB_BYTE_MAX];
extern uint32_t V_I2C_WriteSize[E_LIBBSP_I2C_NB_I2C_BUS];
extern uint32_t V_I2C_ReadSize[E_LIBBSP_I2C_NB_I2C_BUS];
extern uint32_t V_I2C_WriteIndex[E_LIBBSP_I2C_NB_I2C_BUS];
extern uint32_t V_I2C_ReadIndex[E_LIBBSP_I2C_NB_I2C_BUS];
/*==== Services ========================================================================*/

/*==== END =============================================================================*/
#endif
