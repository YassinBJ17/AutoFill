/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_MRAM_Open.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

TE_LIBBSP_MRAM_ErrorCode LIBBSP_MRAM_Open(void)
{

   TE_LIBBSP_SPI_ErrorCode v_rc;
   uint32_t v_timer;
   uint8_t v_MramWriteBuffer[C_MRAM_TX_BUFFER_SIZE];
   
   TU_LIBBSP_SPI_Config v_MRAM_spmodex;
   
   /* Prepare bus signal configuration for MRAM */
   v_MRAM_spmodex.R = 0ul;       /* RAZ register image */
   v_MRAM_spmodex.B.CI    = 0ul; /* CLOCK_INVERT - low */
   v_MRAM_spmodex.B.CP    = 0ul; /* CLOCK_PHASE - middle */
   v_MRAM_spmodex.B.REV   = 1ul; /* FIRST_CHAR - MSB first */
   v_MRAM_spmodex.B.DIV16 = 0ul; /* DIV_16 - CCB/2 ie 333/2 = 166 Mhz */
   v_MRAM_spmodex.B.PM    = C_MRAM_PRESCALE; /* PRESCALE - (2 * (PM + 1) = 6 -> esPI CLK = 166,5/6 = 27 Mhz*/
   v_MRAM_spmodex.B.ODD   = 0ul; /* ODD_DIVISION - Even division */
   v_MRAM_spmodex.B.POL   = 1ul; /* CS_POLARITY - Asserted low */
   v_MRAM_spmodex.B.LEN   = C_MRAM_CHAR_LENGTH; /* CHAR_LENGTH - 8 bits */
   v_MRAM_spmodex.B.CSBEF = 0ul; /* CS_BEFORE_FRAME */
   v_MRAM_spmodex.B.CSAFT = 0ul; /* CS_AFTER_FRAME */
   v_MRAM_spmodex.B.CSCG  = 1ul; /* CS_CLOCK_GAP - Gap = 2 */
   
   /* Open eSPI resource */
   (void) LIBBSP_SPI_Open(E_LIBBSP_SPI_MRAM, &v_MRAM_spmodex);
   
   /* Exit MRAM from Sleep Mode */
   v_MramWriteBuffer[0] = (uint8_t)LIBBSP_MRAM_WAKE;/*%RELAX<SYNCHRONe_C_Code_10.7> LIBBSP_MRAM_WAKE=0xAB so there is no loss of precision*/
   v_rc = LIBBSP_SPI_IOCtrl(E_LIBBSP_SPI_MRAM, E_LIBBSP_SPI_WRITE1, v_MramWriteBuffer);
   if (v_rc != E_LIBBSP_SPI_OK)
   {
      asm("nop");
      return (E_LIBBSP_MRAM_EXCHANGE_ESPI_ERROR); /* %RELAX<SYNCHRONe_C_Code_16.12> returned value is part of the Enum type */
   }
   
   /* Wait 410 microsecond > 400 microsecond min value */
   v_timer = 41ul;
   while ( LIBBSP_CMN_isElapsed(&v_timer) == 0ul)
   {
      /* do nothing */
   }
   
   /* WP is set to 1 by HW. A 'LIBBSP_MRAM_WREN' command will set WEL bit to '1'. This action */
   /* will make writable the status register and the unprotected blocks but leave      */
   /* protected blocks in the protected state.                                         */
   v_MramWriteBuffer[0] = (uint8_t)LIBBSP_MRAM_WREN;/*%RELAX<SYNCHRONe_C_Code_10.7> LIBBSP_MRAM_WREN=0x06 so there is no loss of precision*/
   v_rc = LIBBSP_SPI_IOCtrl(E_LIBBSP_SPI_MRAM, E_LIBBSP_SPI_WRITE1, v_MramWriteBuffer);
   if (v_rc != E_LIBBSP_SPI_OK)
   {
      asm("nop");
      return (E_LIBBSP_MRAM_EXCHANGE_ESPI_ERROR); /* %RELAX<SYNCHRONe_C_Code_16.12> returned value is part of the Enum type */
   }
   
   /* Now, WP = 1 and WEL = 1; Clear BP1 et BP0 bits in the status register in order to*/
   /* unprotected all MRAM block. We must do such action because sometime this MRAM    */
   /* goes itself to protected mode.                                                   */
   v_MramWriteBuffer[0] = (uint8_t)LIBBSP_MRAM_WRSR;/*%RELAX<SYNCHRONe_C_Code_10.7> LIBBSP_MRAM_WRSR=0x01 so there is no loss of precision*/
   v_MramWriteBuffer[1] = (uint8_t) C_MRAM_CLEAR_BPX;
   v_rc = LIBBSP_SPI_IOCtrl(E_LIBBSP_SPI_MRAM, E_LIBBSP_SPI_WRITE2, v_MramWriteBuffer);
   if (v_rc != E_LIBBSP_SPI_OK)
   {
      asm("nop");
      return (E_LIBBSP_MRAM_EXCHANGE_ESPI_ERROR); /* %RELAX<SYNCHRONe_C_Code_16.12> returned value is part of the Enum type */
   }
   
   /* Verify Status register. Notice that read of LIBBSP_MRAM_RDSR musn't follow a normal read*/
   v_MramWriteBuffer[0] = (uint8_t)LIBBSP_MRAM_RDSR;/*%RELAX<SYNCHRONe_C_Code_10.7> LIBBSP_MRAM_RDSR=0x05 so there is no loss of precision*/
   v_rc = LIBBSP_SPI_IOCtrl(E_LIBBSP_SPI_MRAM, E_LIBBSP_SPI_READ1, v_MramWriteBuffer);
   if (v_rc != E_LIBBSP_SPI_OK)
   {
      asm("nop");
      return (E_LIBBSP_MRAM_EXCHANGE_ESPI_ERROR); /* %RELAX<SYNCHRONe_C_Code_16.12> returned value is part of the Enum type */
   }
   
   /* There is no tramsmit error,  SW can now  verify Status register : */
   /*  It should be at 0x2 to be able to R/W in the whole MRAM Area */
   if (v_MramWriteBuffer[0] == C_MRAM_STATUS_REGISTER)
   {
      return (E_LIBBSP_MRAM_OK); /* %RELAX<SYNCHRONe_C_Code_16.12> returned value is part of the Enum type */
   }
   else
   {
      asm("nop");
      return (E_LIBBSP_MRAM_EXCHANGE_ESPI_ERROR); /* %RELAX<SYNCHRONe_C_Code_16.12> returned value is part of the Enum type */
   }

}

/*==== END =============================================================================*/
