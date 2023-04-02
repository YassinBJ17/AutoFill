/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2017                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_FNOR_PREPARE_COMMAND_H_
#define LIBBSP_FNOR_PREPARE_COMMAND_H_

#include "LIBBSP_FNOR_Globals.h"


/*==== Definitions =====================================================================*/
/* #define C_FNOR_SPI_FIFO_SIZE 32ul */

/* Enable Write */
/*#define LIBBSP_FNOR_EnableWrite(devID) \
		LIBBSP_SPI_Exchange(devID, 0, NULL, sizeof(C_FNOR_WREN), &C_FNOR_WREN, E_LIBBSP_SPI_NORMAL_MODE)*/

/* Enter 4 bytes addressing mode */
/*#define LIBBSP_FNOR_Enter4B(devID) \
		LIBBSP_SPI_Exchange(devID, 0, NULL, sizeof(C_FNOR_ENTER4B), &C_FNOR_ENTER4B, E_LIBBSP_SPI_NORMAL_MODE)*/

/* Exit 4 bytes addressing mode */
/*#define LIBBSP_FNOR_Exit4B(devID) \
		LIBBSP_SPI_Exchange(devID, 0, 0, sizeof(C_FNOR_ENTER4B), &C_FNOR_ENTER4B, E_LIBBSP_SPI_NORMAL_MODE)*/

/* Clear Flag Status Register  */
/*#define LIBBSP_FNOR_ClearFlagStatusReg(devID) \
		LIBBSP_SPI_Exchange(devID, 0, NULL, sizeof(C_FNOR_CFSR), &C_FNOR_CFSR, E_LIBBSP_SPI_NORMAL_MODE)*/




void LIBBSP_FNOR_PrepareCommand(const uint8_t command, const uint32_t flashAddress);

#endif LIBBSP_FNOR_PREPARE_COMMAND_H_
