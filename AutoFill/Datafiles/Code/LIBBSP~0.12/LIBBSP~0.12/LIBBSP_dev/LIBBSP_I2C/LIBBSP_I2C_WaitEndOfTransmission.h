/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_I2C_WAIT_END_OF_TRANSMISSION_H
#define LIBBSP_I2C_WAIT_END_OF_TRANSMISSION_H

#include "LIBBSP_I2C_Globals.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

TE_LIBBSP_I2C_Code LIBBSP_I2C_WaitEndOfTransmission(const uint32_t v_timeout,
								 volatile TS_LIBBSP_I2C_Register * const p_reg);
/*==== END =============================================================================*/
#endif
