/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_MRAM_H
#define LIBBSP_MRAM_H

#include "LIBBSP_SPI.h"
#include "LIBMCP_Types.h"
#include "kcg_types.h"

/*==== Definitions =====================================================================*/

#define C_MRAM_SPI_TRANSMISSION_MAXSIZE 0xFFF0

#define C_MRAM_CLEAR_BPX 0x0

#define C_MRAM_TX_BUFFER_SIZE 4ul

/*==== Types ===========================================================================*/
typedef enum {
   LIBBSP_MRAM_WRSR               = 0x01,     /* Write status register */
   LIBBSP_MRAM_WRITE              = 0x02,     /* Write command (page program) */
   LIBBSP_MRAM_READ               = 0x03,     /* Read command */
   LIBBSP_MRAM_WRDI               = 0x04,     /* Write Disable */
   LIBBSP_MRAM_RDSR               = 0x05,     /* Read status register */
   LIBBSP_MRAM_WREN               = 0x06,     /* Write enable */
   LIBBSP_MRAM_SLEEP              = 0xB9,     /* Enter Sleep Mode */
   LIBBSP_MRAM_WAKE               = 0xAB      /* Exit Sleep Mode */
} TE_LIBBSP_MRAM_Command;

/* Return codes of MRAM layer */

/*typedef enum {
    E_LIBBSP_MRAM_OK                  = 0,
    E_LIBBSP_MRAM_OPEN_ESPI_ERROR       = 1,
    E_LIBBSP_MRAM_CLOSE_ESPI_ERROR      = 2,
    E_LIBBSP_MRAM_WRITE_ERROR          = 3,
    E_LIBBSP_MRAM_READ_ERROR           = 4,
    E_LIBBSP_MRAM_EXCHANGE_ESPI_ERROR    = 5
} TE_LIBBSP_MRAM_ErrorCode;
*/
/* defined in kcg_types.h */

/*==== Variables ========================================================================*/

// extern const uint32_t C_MRAM_FIRST_MSB_BYTE;
// extern const uint32_t C_MRAM_SECOND_MSB_BYTE;
// extern const uint32_t C_MRAM_SECOND_LSB_BYTE;
// extern const uint32_t C_MRAM_SHIFT_16_BITS;
// extern const uint32_t C_MRAM_SHIFT_8_BITS;

/*==== Services ========================================================================*/

extern TE_LIBBSP_MRAM_ErrorCode LIBBSP_MRAM_Close(void);
extern TE_LIBBSP_MRAM_ErrorCode LIBBSP_MRAM_Open(void);
extern void LIBBSP_MRAM_Read(const uint32_t mramAddress, const uint32_t size, uint8_t * const buffer, TE_LIBBSP_MRAM_ErrorCode * const v_ret);
extern void LIBBSP_MRAM_Write(const uint32_t mramAddress, const uint32_t size, uint8_t * const buffer, TE_LIBBSP_MRAM_ErrorCode * const v_ret);

#endif /* LIBBSP_MRAM_H */
