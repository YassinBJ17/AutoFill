/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_I2C_TRANSMISSION_WRITE_H
#define LIBBSP_I2C_TRANSMISSION_WRITE_H

#include "LIBBSP_I2C_Globals.h"
#include "LIBBSP_I2C_WaitEndOfTransmission.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
void LIBBSP_I2C_TransmissionWrite(const TE_LIBBSP_I2C_Bus v_devID, const uint8_t * const p_buffer ,const uint32_t v_size, TE_LIBBSP_I2C_Code* const v_errorCode);
/*==== END =============================================================================*/
#endif
