/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_SPI_Read2Bytes.h"

/*==== Definitions =====================================================================*/
/* configure eSPI block to send 4 char (and skip them) and receive 2 */

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
void LIBBSP_SPI_Read2Bytes(const TE_LIBBSP_SPI_Device      SpiDevice,
                           uint8_t *                 const Buffer,
                           TE_LIBBSP_SPI_ErrorCode * const v_SpiErr)
{
   uint32_t v_timeout ;
   
   *v_SpiErr = E_LIBBSP_SPI_OK;
   
   /* Clear All eSPI events */
   V_SPI_Regs->spie.R = C_SPI_CLEAR_GLOBAL_REG_MASK;
   
   /* load the buffer */
   /*{{RELAX<SYNCHRONe_C_Code_17.4>*/
   /*Array indexing used on poiter because its a buffer*/
   V_SPI_Regs->spitf.u8 = Buffer[0];
   V_SPI_Regs->spitf.u8 = Buffer[1];
   V_SPI_Regs->spitf.u8 = Buffer[2];
   V_SPI_Regs->spitf.u8 = Buffer[3];
   /*}}RELAX<SYNCHRONe_C_Code_17.4> */
   /* Configure the SPI bus to send 4 char  and receive 2 on Chip select 1 */
   switch (SpiDevice)
   {
      case E_LIBBSP_SPI_FLASH_PROGRAM:
         V_SPI_Regs->spcom.R = (uint32_t)C_SPI_RX_FLASH_PROGRAM_2CHAR;
         break;
      case E_LIBBSP_SPI_MRAM:
         V_SPI_Regs->spcom.R = (uint32_t)C_SPI_RX_MRAM_2CHAR;
         break;
      case E_LIBBSP_SPI_FLASH_BITE:
         V_SPI_Regs->spcom.R = (uint32_t)C_SPI_RX_FLASH_BITE_2CHAR;
         break;
      default:
         V_SPI_Regs->spcom.R = (uint32_t)C_SPI_RX_DEFAULT_2CHAR;
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
   /* Attente fin de l'�mission de 32 octets @ 27MHz*/
   
   while (V_SPI_Regs->spie.B.RXCNT == 0ul)
   {
      if ((LIBBSP_CMN_isElapsed(&v_timeout) == 1ul))
      {
         /* return E_LIBBSP_SPI_TIMEOUT_RXCNT; */
         *v_SpiErr = E_LIBBSP_SPI_TIMEOUT_RXCNT;
         break;
      }
   }
   
   if (*v_SpiErr == E_LIBBSP_SPI_OK)
   {
      /* Place the read data in the end of buffer */
	  /*{{RELAX<SYNCHRONe_C_Code_17.4>*/
      /*Array indexing used on poiter because its a buffer*/
      Buffer[0] = V_SPI_Regs->spirf.u8;
      Buffer[1] = V_SPI_Regs->spirf.u8;
	  /*}}RELAX<SYNCHRONe_C_Code_17.4> */
   }
}
/*==== END =============================================================================*/
