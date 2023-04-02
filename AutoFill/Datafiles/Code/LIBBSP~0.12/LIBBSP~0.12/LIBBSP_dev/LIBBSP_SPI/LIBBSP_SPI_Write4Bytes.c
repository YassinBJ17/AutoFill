/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_SPI_Write4Bytes.h"
/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
void LIBBSP_SPI_Write4Bytes(const TE_LIBBSP_SPI_Device      SpiDevice,
                            const uint8_t *           const Buffer,
                            TE_LIBBSP_SPI_ErrorCode * const v_SpiErr)
{
   uint32_t v_Timeout;
   *v_SpiErr = E_LIBBSP_SPI_OK;
   /* Clear All previous eSPI events */
   V_SPI_Regs->spie.R = C_SPI_CLEAR_GLOBAL_REG_MASK;
   
   /* Load the Tx FIFO */
   /*{{RELAX<SYNCHRONe_C_Code_17.4>*/
   /*Array indexing used on poiter because its a buffer*/
   V_SPI_Regs->spitf.u8 = Buffer[0];
   V_SPI_Regs->spitf.u8 = Buffer[1];
   V_SPI_Regs->spitf.u8 = Buffer[2];
   V_SPI_Regs->spitf.u8 = Buffer[3];
   /*}}RELAX<SYNCHRONe_C_Code_17.4> */
   /* Configure the SPI bus to send 6 chars on Chip select 1 */
   switch (SpiDevice)
   {
      case E_LIBBSP_SPI_FLASH_PROGRAM:
         V_SPI_Regs->spcom.R = (uint32_t)C_SPI_BUS_FLASH_PROGRAM_4CHAR;
         break;
      case E_LIBBSP_SPI_MRAM:
         V_SPI_Regs->spcom.R = (uint32_t)C_SPI_BUS_MRAM_4CHAR;
         break;
      case E_LIBBSP_SPI_FLASH_BITE:
         V_SPI_Regs->spcom.R = (uint32_t)C_SPI_BUS_FLASH_BITE_4CHAR;
         break;
      default:
         V_SPI_Regs->spcom.R = (uint32_t)C_SPI_BUS_DEFAULT_4CHAR;
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
