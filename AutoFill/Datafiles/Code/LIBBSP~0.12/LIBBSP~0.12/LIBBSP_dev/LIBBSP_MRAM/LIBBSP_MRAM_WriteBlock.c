/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_MRAM_WriteBlock.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

TE_LIBBSP_MRAM_ErrorCode LIBBSP_MRAM_WriteBlock(const uint32_t        mramAddress,
                                                const uint32_t        size,
                                                const uint8_t * const buffer)
{
   TE_LIBBSP_SPI_ErrorCode v_rc;
   uint8_t v_MramWriteBuffer[C_MRAM_TX_BUFFER_SIZE];
   
   /* Prepare block program command */
   /*{{RELAX<SYNCHRONe_C_Code_10.7>*/
   /*Loss of precision because mramAddress is split in uint8_t*/
   v_MramWriteBuffer[0] = (uint8_t)LIBBSP_MRAM_WRITE;
   v_MramWriteBuffer[1] = (uint8_t)((mramAddress&C_MRAM_SECOND_LSB_BYTE) >> C_MRAM_SHIFT_16_BITS);
   v_MramWriteBuffer[2] = (uint8_t)((mramAddress&C_MRAM_SECOND_MSB_BYTE) >> C_MRAM_SHIFT_8_BITS);
   v_MramWriteBuffer[3] = (uint8_t)(mramAddress&C_MRAM_FIRST_MSB_BYTE);
   /*}}RELAX<SYNCHRONe_C_Code_10.7> */
   /* Send program command.  Size is whole size  : command + address + payload) */
   v_rc = LIBBSP_SPI_Exchange(E_LIBBSP_SPI_MRAM, 0ul, (uint8_t *)0, C_MRAM_TX_BUFFER_SIZE,
                              v_MramWriteBuffer, size, buffer, E_LIBBSP_SPI_NORMAL_MODE);
   
   if (v_rc != E_LIBBSP_SPI_OK)
   {
      return (E_LIBBSP_MRAM_EXCHANGE_ESPI_ERROR); /* %RELAX<SYNCHRONe_C_Code_16.12> returned value is part of the Enum type */
   }
   else
   {
      return (E_LIBBSP_MRAM_OK); /* %RELAX<SYNCHRONe_C_Code_16.12> returned value is part of the Enum type */
   }
}

/*==== END =============================================================================*/
