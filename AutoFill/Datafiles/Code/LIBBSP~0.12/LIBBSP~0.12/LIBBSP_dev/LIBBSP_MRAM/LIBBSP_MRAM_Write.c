/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_MRAM_Write.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

void LIBBSP_MRAM_Write(const uint32_t                   mramAddress,
                       const uint32_t                   size,
                       uint8_t *                  const buffer, /* %RELAX<SYNCHRONe_C_Code_8.18> Output only used as parameter in subfunction */
                       TE_LIBBSP_MRAM_ErrorCode * const v_ret)
{
   TE_LIBBSP_MRAM_ErrorCode v_rc;
   uint32_t v_currentMramAddress;
   uint32_t v_sizeRemaining;
   uint32_t v_numberOfBlocks;
   uint32_t v_blockIndex;

   /* Process according page segmentation */
   v_sizeRemaining = size;
   v_currentMramAddress = mramAddress;
   v_blockIndex = 0ul;

   if(mramAddress < C_MRAM_ADDRESS_MIN && mramAddress + size > C_MRAM_ADDRESS_MAX)
   {
      *v_ret = E_LIBBSP_MRAM_EXCHANGE_ESPI_ERROR;
      return ;
   }

   /* The entire memory of this MRAM can be read in a single command  (until next rise of the chip select).  */
   /* As we want a deterministic Software, software musn't use interruption to fill/get the entire data. So, */
   /* data are cut into memory blocks of maximum "C_MRAM_SPI_TRANSMISSION_MAXSIZE" size.                             */
   if (v_sizeRemaining > (uint32_t)C_MRAM_SPI_TRANSMISSION_MAXSIZE )
   {
      /* Each espi write command cannot exceed  MRAM_SPI_FIFO_SIZE - 4 in bytes */
      v_numberOfBlocks = v_sizeRemaining / ((uint32_t)C_MRAM_SPI_TRANSMISSION_MAXSIZE);
      v_sizeRemaining = v_sizeRemaining % ((uint32_t)C_MRAM_SPI_TRANSMISSION_MAXSIZE);
      for (v_blockIndex=0ul; v_blockIndex < v_numberOfBlocks; v_blockIndex++)
      {
         v_rc = LIBBSP_MRAM_WriteBlock(v_currentMramAddress, (uint32_t)C_MRAM_SPI_TRANSMISSION_MAXSIZE,
                                       &buffer[v_blockIndex*(uint32_t)C_MRAM_SPI_TRANSMISSION_MAXSIZE]);/*%RELAX<SYNCHRONe_C_Code_17.4> Array indexing used because LIBBSP_SPI_Exchange can't guess teh size of buffer needed*/
         if (v_rc != E_LIBBSP_MRAM_OK)
         {
            *v_ret = E_LIBBSP_MRAM_EXCHANGE_ESPI_ERROR;
            return;
         }
         v_currentMramAddress += (uint32_t)C_MRAM_SPI_TRANSMISSION_MAXSIZE;
      }
   }

   /* Process last block */
   if (v_sizeRemaining > 0ul)
   {
      v_rc = LIBBSP_MRAM_WriteBlock(v_currentMramAddress, v_sizeRemaining,
                                    &buffer[v_blockIndex*(uint32_t)C_MRAM_SPI_TRANSMISSION_MAXSIZE]);/*%RELAX<SYNCHRONe_C_Code_17.4> Array indexing used because LIBBSP_SPI_Exchange can't guess teh size of buffer needed*/
      if (v_rc != E_LIBBSP_MRAM_OK)
      {
         *v_ret=E_LIBBSP_MRAM_EXCHANGE_ESPI_ERROR;
         return;
      }
   }

   *v_ret=E_LIBBSP_MRAM_OK;
   return;
}

/*==== END =============================================================================*/
