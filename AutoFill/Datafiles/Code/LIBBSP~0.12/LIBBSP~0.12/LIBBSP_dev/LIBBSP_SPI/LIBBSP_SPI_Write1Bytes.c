/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_SPI_Write1Bytes.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
void LIBBSP_SPI_Write1Bytes(const TE_LIBBSP_SPI_Device      SpiDevice,
                            const uint8_t *           const Buffer,
                            TE_LIBBSP_SPI_ErrorCode * const v_SpiErr)
{
   uint32_t v_Timeout;
   
   *v_SpiErr = E_LIBBSP_SPI_OK;
   /* Clear All previous eSPI events */
   V_SPI_Regs->spie.R = C_SPI_CLEAR_GLOBAL_REG_MASK;
   
   /* Load the Tx FIFO */
   V_SPI_Regs->spitf.u8 = Buffer[0]; /*%RELAX<SYNCHRONe_C_Code_17.4> Array indexing used on poiter because its a buffer*/
   
   /* Configure the SPI bus to send 1 chars on Chip select 1 */
   switch (SpiDevice)
   {
      case E_LIBBSP_SPI_FLASH_PROGRAM:
         V_SPI_Regs->spcom.R = (uint32_t)C_SPI_BUS_FLASH_PROGRAM_1CHAR;
         break;
      case E_LIBBSP_SPI_MRAM:
         V_SPI_Regs->spcom.R = (uint32_t)C_SPI_BUS_MRAM_1CHAR;
         break;
      case E_LIBBSP_SPI_FLASH_BITE:
         V_SPI_Regs->spcom.R = (uint32_t)C_SPI_BUS_FLASH_BITE_1CHAR;
         break;
      default:
         V_SPI_Regs->spcom.R = (uint32_t)C_SPI_BUS_DEFAULT_1CHAR;
         break;
   }
   
   v_Timeout = C_SPI_TIMEOUT_US;
   /* Attendre que le dernier caract�re soit sortit du serializer */
   while(V_SPI_Regs->spie.B.DON == 0ul) 
   {
      if ((LIBBSP_CMN_isElapsed(&v_Timeout) == 1ul))
      {
         *v_SpiErr = E_LIBBSP_SPI_TIMEOUT_DON;
         break;
      }
   }
}
/*==== END =============================================================================*/
