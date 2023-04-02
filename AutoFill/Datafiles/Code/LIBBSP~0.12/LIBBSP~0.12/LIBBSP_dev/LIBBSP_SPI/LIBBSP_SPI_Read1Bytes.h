/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_SPI_READ_1_BYTES_H
#define LIBBSP_SPI_READ_1_BYTES_H

#include "LIBBSP_SPI_Globals.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
void LIBBSP_SPI_Read1Bytes(const TE_LIBBSP_SPI_Device      SpiDevice,
                           uint8_t *                 const Buffer,
                           TE_LIBBSP_SPI_ErrorCode * const v_SpiErr);
/*==== END =============================================================================*/
#endif
