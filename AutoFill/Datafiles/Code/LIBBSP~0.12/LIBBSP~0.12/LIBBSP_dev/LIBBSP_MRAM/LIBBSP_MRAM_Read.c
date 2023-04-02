/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_MRAM_Read.h"

/*==== Definitions =====================================================================*/


/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

void LIBBSP_MRAM_Read(const uint32_t mramAddress, const uint32_t size, uint8_t * const buffer, TE_LIBBSP_MRAM_ErrorCode * const v_ret) /* %RELAX<SYNCHRONe_C_Code_8.18> Output used only as parameter in subfunction */
{
   TE_LIBBSP_SPI_ErrorCode v_rc;
   uint32_t v_currentMramAddress;
   uint32_t v_sizeRemaining;
   uint32_t v_numberOfBlocks;
   uint32_t v_blockIndex;
   uint8_t v_MramWriteBuffer[C_MRAM_TX_BUFFER_SIZE];
   const uint8_t * const c_nullDataBuffer = { 0 };
   
   if (mramAddress < C_MRAM_ADDRESS_MIN && mramAddress+size > C_MRAM_ADDRESS_MAX)
   {
      *v_ret = E_LIBBSP_MRAM_EXCHANGE_ESPI_ERROR;
      return;
   }

   /* Process according page segmentation */
   v_sizeRemaining = size;
   v_currentMramAddress = mramAddress;
   v_blockIndex = 0ul;
   
   /* Process beginning blocks */
   if (v_sizeRemaining > (uint32_t)C_MRAM_SPI_TRANSMISSION_MAXSIZE)
   {
      v_numberOfBlocks = v_sizeRemaining / (uint32_t)C_MRAM_SPI_TRANSMISSION_MAXSIZE;
      v_sizeRemaining = v_sizeRemaining % (uint32_t)C_MRAM_SPI_TRANSMISSION_MAXSIZE;
      for (v_blockIndex=0ul; v_blockIndex < v_numberOfBlocks; v_blockIndex++)
      {
         /* Prepare block read command */
		 /*{{RELAX<SYNCHRONe_C_Code_10.7>*/
		 /*Loss of precision because v_currentMramAddress is split in uint8_t*/
         v_MramWriteBuffer[0] = (uint8_t)LIBBSP_MRAM_READ;
         v_MramWriteBuffer[1] = (uint8_t)((v_currentMramAddress&C_MRAM_SECOND_LSB_BYTE) >> C_MRAM_SHIFT_16_BITS);
         v_MramWriteBuffer[2] = (uint8_t)((v_currentMramAddress&C_MRAM_SECOND_MSB_BYTE) >> C_MRAM_SHIFT_8_BITS);
         v_MramWriteBuffer[3] = (uint8_t)(v_currentMramAddress&C_MRAM_FIRST_MSB_BYTE);
         /*}}RELAX<SYNCHRONe_C_Code_10.7> */
         /* Send program command.  Size is whole size  : command + address + payload) */
         v_rc = LIBBSP_SPI_Exchange(E_LIBBSP_SPI_MRAM, (uint32_t)C_MRAM_SPI_TRANSMISSION_MAXSIZE,
                                    &buffer[v_blockIndex*(uint32_t)C_MRAM_SPI_TRANSMISSION_MAXSIZE],/*%RELAX<SYNCHRONe_C_Code_17.4> Array indexing used because LIBBSP_SPI_Exchange can't guess teh size of buffer needed*/
                                    C_MRAM_TX_BUFFER_SIZE, v_MramWriteBuffer,
                                    0ul, c_nullDataBuffer, E_LIBBSP_SPI_NORMAL_MODE);
         
         if (v_rc != E_LIBBSP_SPI_OK)
         {
            *v_ret=E_LIBBSP_MRAM_EXCHANGE_ESPI_ERROR;
            return;
         }
         
         v_currentMramAddress = v_currentMramAddress + (uint32_t)C_MRAM_SPI_TRANSMISSION_MAXSIZE;
      }
   }
   
   /* Process last block */
   if (v_sizeRemaining > 0ul)
   {
      /* Prepare block read command */
	  /*{{RELAX<SYNCHRONe_C_Code_10.7>*/
	  /*Loss of precision because v_currentMramAddress is split in uint8_t*/
      v_MramWriteBuffer[0] = (uint8_t)LIBBSP_MRAM_READ;
      v_MramWriteBuffer[1] = (uint8_t)((v_currentMramAddress&C_MRAM_SECOND_LSB_BYTE) >> C_MRAM_SHIFT_16_BITS);
      v_MramWriteBuffer[2] = (uint8_t)((v_currentMramAddress&C_MRAM_SECOND_MSB_BYTE) >> C_MRAM_SHIFT_8_BITS);
      v_MramWriteBuffer[3] = (uint8_t)(v_currentMramAddress&C_MRAM_FIRST_MSB_BYTE);
      /*}}RELAX<SYNCHRONe_C_Code_10.7> */
      /* Send program command. Tx Size is 4 (1 byte command + 3 bytes address). Rx size is "v_sizeRemaining" */
      v_rc = LIBBSP_SPI_Exchange(E_LIBBSP_SPI_MRAM, v_sizeRemaining,
                                 &buffer[v_blockIndex*(uint32_t)C_MRAM_SPI_TRANSMISSION_MAXSIZE],/*%RELAX<SYNCHRONe_C_Code_17.4> Array indexing used because LIBBSP_SPI_Exchange can't guess teh size of buffer needed*/
                                 C_MRAM_TX_BUFFER_SIZE, v_MramWriteBuffer,
                                 0ul, c_nullDataBuffer, E_LIBBSP_SPI_NORMAL_MODE);
      if (v_rc != E_LIBBSP_SPI_OK)
      {
         *v_ret=E_LIBBSP_MRAM_EXCHANGE_ESPI_ERROR;
         return;
      }
   }

   *v_ret=E_LIBBSP_MRAM_OK;
   return;
}
/*==== END =============================================================================*/
