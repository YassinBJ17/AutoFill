/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_SPI_Copy_In_FIFO.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

TE_LIBBSP_SPI_ErrorCode LIBBSP_SPI_Copy_In_FIFO(const uint32_t Size, const uint8_t * const Buffer)
{
	  uint32_t v_Count, v_Index;
	  uint32_t v_Timeout;
	  
      /* Copy in transmit FIFO */
      v_Index = 0ul;
      while (v_Index < Size)
      {
         /*v_Timeout = 100;*/ /* 100 �s  >> 10�s = transmission time of 32 bytes @27MHz*/
         v_Timeout = 10ul; /* 100 �s  >> 10�s = transmission time of 32 bytes @27MHz*/
         v_Count = V_SPI_Regs->spie.B.TXCNT;
         while (v_Count == 0ul)
         {
            if ((LIBBSP_CMN_isElapsed(&v_Timeout) == 1ul))
            {
               return E_LIBBSP_SPI_TIMEOUT_TNF;
            }
            v_Count = V_SPI_Regs->spie.B.TXCNT;
         }
         while ((v_Count > 0ul) && (v_Index < Size))
         {
			/*{{RELAX<SYNCHRONe_C_Code_17.4>*/
			/*Array indexing used on poiter because its a buffer*/
            V_SPI_Regs->spitf.u8 = Buffer[v_Index];
			/*}}RELAX<SYNCHRONe_C_Code_17.4> */
            v_Count--;
            v_Index++;
         }
      }

	return E_LIBBSP_SPI_OK;
}
/*==== END =============================================================================*/
