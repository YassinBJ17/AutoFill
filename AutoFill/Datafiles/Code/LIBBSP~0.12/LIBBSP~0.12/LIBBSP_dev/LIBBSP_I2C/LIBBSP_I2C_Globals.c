/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_I2C_Globals.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

volatile TS_LIBBSP_I2C_RegisterSet* const P_I2C_RegAddress = (volatile TS_LIBBSP_I2C_RegisterSet* const) C_LIBBSP_CCSR_I2C; /* %RELAX<SYNCHRONe_C_Code_10.7> No precision lost: adress */


TE_LIBBSP_I2C_DeviceState V_I2C_State[E_LIBBSP_I2C_NB_I2C_BUS];
uint8_t V_I2C_BuffWrite[E_LIBBSP_I2C_NB_I2C_BUS][C_I2C_NB_BYTE_MAX];
uint8_t V_I2C_BuffRead[E_LIBBSP_I2C_NB_I2C_BUS][C_I2C_NB_BYTE_MAX];
uint32_t V_I2C_WriteSize[E_LIBBSP_I2C_NB_I2C_BUS];
uint32_t V_I2C_ReadSize[E_LIBBSP_I2C_NB_I2C_BUS];
uint32_t V_I2C_WriteIndex[E_LIBBSP_I2C_NB_I2C_BUS];
uint32_t V_I2C_ReadIndex[E_LIBBSP_I2C_NB_I2C_BUS];

/*==== Services ========================================================================*/

/*==== END =============================================================================*/
