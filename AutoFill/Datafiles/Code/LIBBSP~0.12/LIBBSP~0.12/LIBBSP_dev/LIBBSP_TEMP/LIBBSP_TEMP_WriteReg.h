/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
#ifndef LIBBSP_TEMP_WRITE_REG_H
#define LIBBSP_TEMP_WRITE_REG_H

#include "LIBBSP_TEMP_Globals.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
TE_LIBBSP_I2C_Code LIBBSP_TEMP_WriteReg(const TE_LIBBSP_TEMP_WriteRegAddr RegAddr, const uint8_t v_val);
/*==== END =============================================================================*/
#endif
