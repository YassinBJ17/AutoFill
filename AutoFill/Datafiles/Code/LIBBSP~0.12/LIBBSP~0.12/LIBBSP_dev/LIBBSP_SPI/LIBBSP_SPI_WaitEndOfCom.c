/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_SPI_WaitEndOfCom.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
TE_LIBBSP_SPI_ErrorCode LIBBSP_SPI_WaitEndOfCom(void)
{
   uint32_t v_Timeout;
   
   /*v_Timeout = 100;*/ /* 100 �s  >> 10�s = transmission time of 32 bytes @27MHz*/
   v_Timeout = 10ul; /* 100 �s  >> 10�s = transmission time of 32 bytes @27MHz*/
   while (V_SPI_Regs->spie.B.TXCNT < 32ul)
   {
      if ((LIBBSP_CMN_isElapsed(&v_Timeout) == 1ul))
      {
         return E_LIBBSP_SPI_TIMEOUT_TXCNT; /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
      }
   }
   /*v_Timeout = 100;*/ /* 100 �s  >> 10�s = transmission time of 32 bytes @27MHz*/
   v_Timeout = 10ul; /* 100 �s  >> 10�s = transmission time of 32 bytes @27MHz*/
   while(V_SPI_Regs->spie.B.DON == 0ul)
   {
      if ((LIBBSP_CMN_isElapsed(&v_Timeout) == 1ul))
      {
         return E_LIBBSP_SPI_TIMEOUT_DON; /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
      }
   }
   
   return E_LIBBSP_SPI_OK; /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
}
/*==== END =============================================================================*/
