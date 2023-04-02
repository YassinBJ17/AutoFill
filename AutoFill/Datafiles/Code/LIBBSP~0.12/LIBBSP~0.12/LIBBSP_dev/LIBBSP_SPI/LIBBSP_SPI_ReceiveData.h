/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_SPI_RECEIVE_DATA_H
#define LIBBSP_SPI_RECEIVE_DATA_H

#include "LIBBSP_SPI_Globals.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
TE_LIBBSP_SPI_ErrorCode LIBBSP_SPI_ReceiveData(const uint32_t           inSize,
                                               uint8_t *          const inBuffer,
                                               const TE_LIBBSP_SPI_Mode mode);
/*==== END =============================================================================*/
#endif
