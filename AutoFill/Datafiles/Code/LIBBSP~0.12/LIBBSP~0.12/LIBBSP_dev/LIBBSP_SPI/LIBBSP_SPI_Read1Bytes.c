/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_SPI_Read1Bytes.h"
/*==== Definitions =====================================================================*/
/* configure eSPI block to send 1 char (and skip it) and receive 1 */

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
void LIBBSP_SPI_Read1Bytes(const TE_LIBBSP_SPI_Device SpiDevice, uint8_t * const Buffer, TE_LIBBSP_SPI_ErrorCode * const v_SpiErr)
{
   uint32_t v_timeout ;
   
   *v_SpiErr = E_LIBBSP_SPI_OK;
   
   /* Clear All eSPI events */
   V_SPI_Regs->spie.R = C_SPI_CLEAR_GLOBAL_REG_MASK;
   
   /* Configure the SPI bus to send 2 Word and receive 1 on Chip select 1 */
   V_SPI_Regs->spitf.u8 = Buffer[0]; /*%RELAX<SYNCHRONe_C_Code_17.4> Array indexing used on poiter because its a buffer*/
   
   switch (SpiDevice)
   {
      case E_LIBBSP_SPI_FLASH_PROGRAM:
         V_SPI_Regs->spcom.R = (uint32_t)C_SPI_RX_FLASH_PROGRAM_1CHAR;
         break;
      case E_LIBBSP_SPI_MRAM:
         V_SPI_Regs->spcom.R = (uint32_t)C_SPI_RX_MRAM_1CHAR;
         break;
      case E_LIBBSP_SPI_FLASH_BITE:
         V_SPI_Regs->spcom.R = (uint32_t)C_SPI_RX_FLASH_BITE_1CHAR;
         break;
      default:
         V_SPI_Regs->spcom.R = (uint32_t)C_SPI_RX_DEFAULT_1CHAR;
         break;
   }
   
   v_timeout = C_SPI_TIMEOUT_US; /* 10�s */
   /* Attendre que le dernier caract�re soit sortit du serializer */
   while(V_SPI_Regs->spie.B.DON == 0ul) 
   {
      if ((LIBBSP_CMN_isElapsed(&v_timeout) == 1ul))
      {
        *v_SpiErr = E_LIBBSP_SPI_TIMEOUT_DON;
        break;
      }
   }
   
   /* Attente fin de l'�mission*/
   
   while (V_SPI_Regs->spie.B.RXCNT == 0ul)
   {
      if ((LIBBSP_CMN_isElapsed(&v_timeout) == 1ul))
      {
   	   *v_SpiErr = E_LIBBSP_SPI_TIMEOUT_RXCNT;
         break;
      }
   }
   
   if (*v_SpiErr == E_LIBBSP_SPI_OK)
   {
      /* Place the read data in the end of buffer */
      Buffer[0] = V_SPI_Regs->spirf.u8; /*%RELAX<SYNCHRONe_C_Code_17.4> Array indexing used on poiter because its a buffer*/
   }
}
/*==== END =============================================================================*/
