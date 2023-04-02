/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_I2C_WAIT_FOR_SLAVE_WRITE_ACK_H
#define LIBBSP_I2C_WAIT_FOR_SLAVE_WRITE_ACK_H

#include "LIBBSP_I2C_Globals.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
void LIBBSP_I2C_WaitForSlaveWriteAck(const TE_LIBBSP_I2C_Bus v_devID, TE_LIBBSP_I2C_CurrentStep* const v_step, TE_LIBBSP_I2C_ErrorCode* const v_errorCode);
/*==== END =============================================================================*/
#endif
