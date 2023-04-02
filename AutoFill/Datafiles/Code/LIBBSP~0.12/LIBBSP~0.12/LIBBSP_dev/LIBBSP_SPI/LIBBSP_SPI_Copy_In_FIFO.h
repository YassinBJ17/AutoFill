/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_SPI_COPY_IN_FIFO_H
#define LIBBSP_SPI_COPY_IN_FIFO_H

#include "LIBBSP_SPI_Globals.h"
#include "LIBBSP_SPI_WaitEndOfCom.h"
#include "LIBBSP_SPI_ReceiveData.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
TE_LIBBSP_SPI_ErrorCode LIBBSP_SPI_Copy_In_FIFO(const uint32_t Size, const uint8_t * const Buffer);

/*==== END =============================================================================*/
#endif
