/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_MRAM_Close.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
TE_LIBBSP_MRAM_ErrorCode LIBBSP_MRAM_Close(void)
{
   TE_LIBBSP_SPI_ErrorCode v_rc;
   uint8_t v_MramWriteBuffer[C_MRAM_TX_BUFFER_SIZE];
   uint32_t v_timer;
   const uint8_t * const c_nullDataBuffer = { 0 };
   /* WP is set to 1 by HW. A 'LIBBSP_MRAM_WRDI' command will set WEL bit to '0'. This action */
   /* will set all the MRAM blocks to protected state as well as the status register.  */
   /* When WEL bit = '0', BP1 or BP0 have no effect. Unprotected blocks are unwritable.*/
   v_MramWriteBuffer[0] = (uint8_t)LIBBSP_MRAM_WRDI; /*%RELAX<SYNCHRONe_C_Code_10.7> LIBBSP_MRAM_WRDI=0x04 so there is no loss of precision*/
   v_rc = LIBBSP_SPI_Exchange(E_LIBBSP_SPI_MRAM, 0ul, (uint8_t*)0, 1ul, v_MramWriteBuffer,
                              0ul, c_nullDataBuffer, E_LIBBSP_SPI_NORMAL_MODE);
   if (v_rc != E_LIBBSP_SPI_OK)
   {
      return (E_LIBBSP_MRAM_EXCHANGE_ESPI_ERROR);
   }
   
   /* Enter Sleep Mode */
   v_MramWriteBuffer[0] = (uint8_t)LIBBSP_MRAM_SLEEP; /*%RELAX<SYNCHRONe_C_Code_10.7> LIBBSP_MRAM_SLEEP=0xB9 so there is no loss of precision*/
   v_rc = LIBBSP_SPI_Exchange(E_LIBBSP_SPI_MRAM, 0ul, (uint8_t*)0, 1ul, v_MramWriteBuffer,
                              0ul, c_nullDataBuffer, E_LIBBSP_SPI_NORMAL_MODE);
   if (v_rc != E_LIBBSP_SPI_OK)
   {
      return (E_LIBBSP_MRAM_EXCHANGE_ESPI_ERROR);
   }
   
   /* Wait 10 microsecond > 3 microsecond min value */
   /* LIBBSP_CMN_Wait(1ul); */
   v_timer = 1ul;
   while ( LIBBSP_CMN_isElapsed(&v_timer) == 0ul)
   {
      /* do nothing */
   }
   
   /* Close eSPI resource */
   LIBBSP_SPI_Close();
   
   return (E_LIBBSP_MRAM_OK);
}
/*==== END =============================================================================*/
