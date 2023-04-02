/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
/* Conditional compilation                                                              */
/* Part number of flash component determines the available services                     */
/* FLASHPART1 is the 1st component used on the Ganav hardware: N25Q512ABG12             */
/* FLASHPART2 is the 2nd component used on the Ganav hardware: MT25QL512ABB8E12-0AAT    */
/****************************************************************************************/

#ifndef LIBBSP_FNOR_H_
#define LIBBSP_FNOR_H_


#include "LIBBSP_SPI.h"
#include "LIBMCP_Types.h"

/*==== Definitions =====================================================================*/

/* eSpi Payload is the fifo even size, minus the write command (1 byte) and address size (4 bytes) */
/* (Used for write operation */
#define C_FNOR_SPI_WRITE_PAYLOAD    26ul

#define C_FNOR_SPI_TRANSMISSION_MAXSIZE        0xFFF0

#define C_FNOR_EXCHANGE_SIZE_OUT    5ul

/*==== Types ===========================================================================*/

/* Erase commands */
typedef enum {
    E_LIBBSP_FNOR_BULK_ERASE       = 21,
	E_LIBBSP_FNOR_SECTOR_ERASE     = 22,
	E_LIBBSP_FNOR_SUB_SECTOR_ERASE = 23
} TE_LIBBSP_FNOR_EraseCommand;

typedef enum {
    E_LIBBSP_FNOR_FLASH_PROGRAM       = 0,
	E_LIBBSP_FNOR_FLASH_BITE          = 2
} TE_LIBBSP_FNOR_Device;

/* Return codes of Flash layer */
typedef enum {
    E_LIBBSP_FNOR_OK                 		= 0,
    E_LIBBSP_FNOR_INVALID_ID           	    = 1,
    E_LIBBSP_FNOR_OPEN_ESPI_ERROR           = 2,
    E_LIBBSP_FNOR_INVALID_ERASE             = 3,
    E_LIBBSP_FNOR_ERASE_ERROR               = 4,
    E_LIBBSP_FNOR_WRITE_ERROR               = 5,
    E_LIBBSP_FNOR_PROTECTION_ERROR          = 6,
    E_LIBBSP_FNOR_TIMEOUT_ERROR             = 7,
	E_LIBBSP_FNOR_NOT_AVAILABLE_FOR_READ    = 8,
	E_LIBBSP_FNOR_NOT_AVAILABLE_FOR_WRITE   = 9,
    E_LIBBSP_FNOR_XCHANGE_ESPI_ERROR        = 0x100
} TE_LIBBSP_FNOR_ErrorCode;

extern const uint32_t C_FNOR_MASK_FIRST_MSB_BYTE;
/*==== Services ========================================================================*/

extern TE_LIBBSP_FNOR_ErrorCode LIBBSP_FNOR_Open(const TE_LIBBSP_SPI_Device devID);
extern TE_LIBBSP_FNOR_ErrorCode LIBBSP_FNOR_Erase(const TE_LIBBSP_SPI_Device devID, const TE_LIBBSP_FNOR_EraseCommand command, const uint32_t flashAddress);
extern TE_LIBBSP_FNOR_ErrorCode LIBBSP_FNOR_CloseErase( const TE_LIBBSP_SPI_Device devID);
extern TE_LIBBSP_FNOR_ErrorCode LIBBSP_FNOR_Write(const TE_LIBBSP_SPI_Device devID, const uint32_t flashAddress, const uint32_t size, const uint8_t * const buffer);
extern TE_LIBBSP_FNOR_ErrorCode LIBBSP_FNOR_Read(const TE_LIBBSP_SPI_Device devID, const uint32_t flashAddress, const uint32_t size, uint8_t * const buffer);
extern TE_LIBBSP_FNOR_ErrorCode LIBBSP_FNOR_FastRead(const TE_LIBBSP_SPI_Device devID, const uint32_t flashAddress, const uint32_t size, uint8_t * const buffer);
extern TE_LIBBSP_FNOR_ErrorCode LIBBSP_FNOR_GetAvailability(const TE_LIBBSP_SPI_Device devID, boolean_t * const CmdStatus);
extern void LIBBSP_FNOR_Close(void);


#endif LIBBSP_FNOR_H_
/*==== END =============================================================================*/
