/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_SPI_ReceiveData.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
TE_LIBBSP_SPI_ErrorCode LIBBSP_SPI_ReceiveData(const uint32_t           inSize,
                                               uint8_t *          const inBuffer,
                                               const TE_LIBBSP_SPI_Mode mode)
{
   uint32_t v_Timeout;
   uint32_t v_Index;
   uint32_t v_Count;
   
   /* Receive data */
   if (mode == E_LIBBSP_SPI_DUAL_MODE)
   {
      /* 2 bytes for dummy cycles */
      for (v_Index = 0ul; v_Index < 2ul; v_Index++)
      {
         /*v_Timeout = 100;*/ /* 100 µs  >> 10µs = transmission time of 32 bytes @27MHz*/
         v_Timeout = 10ul; /* 100 µs  >> 10µs = transmission time of 32 bytes @27MHz*/
         while (V_SPI_Regs->spie.B.RXCNT == 0ul)
         {
            if ((LIBBSP_CMN_isElapsed(&v_Timeout) == 1ul))
            {
               return E_LIBBSP_SPI_TIMEOUT_RXCNT; /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
            }
         }
         inBuffer[v_Index] = V_SPI_Regs->spirf.u8; /*%RELAX<SYNCHRONe_C_Code_17.4> Array indexing used on poiter because its a buffer*/
      }
   }
   v_Index = 0ul;
   while (v_Index < inSize)
   {
      /*v_Timeout = 100;*/ /* 100 µs  >> 10µs = transmission time of 32 bytes @27MHz*/
      v_Timeout = 10ul; /* 100 µs  >> 10µs = transmission time of 32 bytes @27MHz*/
      v_Count = V_SPI_Regs->spie.B.RXCNT;
      while (v_Count == 0ul)
      {
         if ((LIBBSP_CMN_isElapsed(&v_Timeout) == 1ul))
         {
            return E_LIBBSP_SPI_TIMEOUT_RXCNT; /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
         }
         v_Count = V_SPI_Regs->spie.B.RXCNT;
      }
      while (v_Count >= 4ul)
      {
		 /*{{RELAX<SYNCHRONe_C_Code_11.1,SYNCHRONe_C_Code_17.4> Array indexing on poiter because its a buffer */  
		 /*Conversion of the poiter buffer to copy uint32_t value in it. Can't do that in an other way because uint8_t and uint32_t needed to be copied*/
         *((uint32_t *) &inBuffer[v_Index]) = V_SPI_Regs->spirf.u32;
		 /*}}RELAX<SYNCHRONe_C_Code_11.1,SYNCHRONe_C_Code_17.4> */
         v_Count = v_Count - 4ul;
         v_Index = v_Index + 4ul;
      }
      while (v_Count > 0ul)
      {
         inBuffer[v_Index] = V_SPI_Regs->spirf.u8; /*%RELAX<SYNCHRONe_C_Code_17.4> Array indexing used on poiter because its a buffer*/
         v_Count = v_Count - 1ul;
         v_Index = v_Index + 1ul;
      }
   }
   return E_LIBBSP_SPI_OK; /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
}
/*==== END =============================================================================*/
