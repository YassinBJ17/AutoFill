/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
#ifndef LIBBSP_DISC_WRITE_REG_H
#define LIBBSP_DISC_WRITE_REG_H

#include "LIBBSP_DISC_Globals.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
TE_LIBBSP_I2C_Code LIBBSP_DISC_WriteReg(const uint8_t v_slave_address, const TE_LIBBSP_DISC_Max7312RegAddr RegAddr, const uint8_t v_val);
/*==== END =============================================================================*/
#endif
