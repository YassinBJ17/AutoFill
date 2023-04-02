/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_I2C_RECEIVE_MODE_H
#define LIBBSP_I2C_RECEIVE_MODE_H

#include "LIBBSP_I2C_Globals.h"
#include "LIBBSP_I2C_WaitEndOfTransmission.h"
/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
void LIBBSP_I2C_ReceiveMode(const TE_LIBBSP_I2C_Bus v_devID, const uint32_t v_size, uint8_t * const pa_buffer, TE_LIBBSP_I2C_Code* const v_errorCode);

/*==== END =============================================================================*/
#endif
