/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_SPI_Copy_In_FIFO.h"


/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
TE_LIBBSP_SPI_ErrorCode LIBBSP_SPI_Exchange(const TE_LIBBSP_SPI_Device SpiID,
                                            const uint32_t inSize, uint8_t * const inBuffer, /* %RELAX<SYNCHRONe_C_Code_8.18> Output used only as parameter for subfunction */
                                            const uint32_t cmdSize, const uint8_t * const cmdBuffer,
                                            const uint32_t dataSize, const uint8_t * const dataBuffer,
                                            const TE_LIBBSP_SPI_Mode mode)
{
  /* TE_LIBBSP_SPI_ErrorCode v_EndOfCom_errorCode;*/
  /* TE_LIBBSP_SPI_ErrorCode v_ReceiveData_errorCode;*/
   TE_LIBBSP_SPI_ErrorCode v_ReturnErrorCode;

   volatile TU_LIBBSP_SPI_Spcom v_Reg_spcom;

   if ((uint64_t)SpiID < (uint64_t)C_SPI_DEVICES_COUNT) /*%RELAX<SYNCHRONe_C_Code_10.7> No loss of precision on the conversion from TE_LIBBSP_SPI_Device to uint64_t*/
   {
      /* Clear All previous eSPI events. This action is mandatory at the beginning of  */
      /* an eSpi transaction.  See "eSPI programming examples" page 1463 of P1020 User */
      /* Manuel reference.    */
      V_SPI_Regs->spie.R = 0xFFFFFFFFul;
      /* Prepare command send */
      v_Reg_spcom.R = 0ul;                                      /* Initialize register */
      v_Reg_spcom.B.CS            = (uint32_t)SpiID;                     /* Address device */ /*%RELAX<SYNCHRONe_C_Code_10.7> No loss of precision on the conversion from TE_LIBBSP_SPI_Device to uint32_t*/
      v_Reg_spcom.B.TRANLEN       = (cmdSize+dataSize+inSize)-1ul;          /* Length of transaction */
      if (mode == E_LIBBSP_SPI_DUAL_MODE)
      {
         v_Reg_spcom.B.DO       = 1ul;                          /* Dual output read */
         v_Reg_spcom.B.TRANLEN += 2ul;                            /* 2 bytes for dummy cycles */
      }
      else
      {
         v_Reg_spcom.B.DO       = 0ul;                          /* Normal eSPI operation */
      }
      
      if (inSize == 0ul)
      {
         v_Reg_spcom.B.TO        = 1ul;                           /* Mode Transmit only */
      }
      else
      {
         v_Reg_spcom.B.RxSKIP    = /*(uint8_t)*/ cmdSize+dataSize;     /* Force Half Duplex */
      }
      /* Copy all cmd in transmit FIFO */

      v_ReturnErrorCode = LIBBSP_SPI_Copy_In_FIFO(cmdSize, cmdBuffer);
	  
	  if (v_ReturnErrorCode == E_LIBBSP_SPI_TIMEOUT_TNF)
	  {
		return v_ReturnErrorCode; /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
	  }

      /* Configure frame, char size for transmission. This action is mandatory and must take place*/
      /* after writting data into fifo.  See "eSPI programming examples" page 1463 of P1020 User  */
      /* Manuel reference. */
      V_SPI_Regs->spcom.R = v_Reg_spcom.R;                                   /* Effective access */

      /* Copy all data in transmit FIFO */

	  v_ReturnErrorCode = LIBBSP_SPI_Copy_In_FIFO(dataSize, dataBuffer);
	  
	  if (v_ReturnErrorCode == E_LIBBSP_SPI_TIMEOUT_TNF)
	  {
		return v_ReturnErrorCode; /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
	  }
      
      /* Wait for end of communication */
      if (inSize == 0ul)
      {
         v_ReturnErrorCode = LIBBSP_SPI_WaitEndOfCom();
      }
      else
      {
         v_ReturnErrorCode = LIBBSP_SPI_ReceiveData(inSize, inBuffer, mode);
      }
   }
   else
   {
	  v_ReturnErrorCode = E_LIBBSP_SPI_INVALID_ID; 
      return v_ReturnErrorCode; /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
   }

   return v_ReturnErrorCode; /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
}
/*==== END =============================================================================*/
