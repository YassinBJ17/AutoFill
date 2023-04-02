/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_SPI_Open.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/
/* ESPI registers are located on "CCSR Address + 0x0_7000 */
/*#pragma section ESPI_SECTION near-absolute RW address=0xFF707000
#pragma use_section ESPI_SECTION V_SPI_Regs
volatile TS_LIBBSP_SPI_RegisterSet V_SPI_Regs;*/

/*==== Services ========================================================================*/
TE_LIBBSP_SPI_ErrorCode LIBBSP_SPI_Open(const TE_LIBBSP_SPI_Device SpiID, const TU_LIBBSP_SPI_Config * const bus_Config)
{
   TE_LIBBSP_SPI_ErrorCode v_ret;
   volatile TU_LIBBSP_SPI_Spmode v_reg_spmode;

   /* Check if the device ID is correct */
   if ((uint64_t)SpiID < (uint64_t)C_SPI_DEVICES_COUNT) /* %RELAX<SYNCHRONe_C_Code_10.7> No precision lost: Enum max value is 2 and constant is uint32 so cast to uint64 is OK */
   {
      /* spmode should be configured only one time.  No change when enabled */
      if (V_SPI_Regs->spmode.B.EN == 0ul)
      {
         /* Prepare register image */
         v_reg_spmode.R = 0x100Ful;

         /* Enable eSPI */
         v_reg_spmode.B.EN = 1ul;

         /* Effective access  */
         V_SPI_Regs->spmode.R = v_reg_spmode.R;

         /* Mask All eSPI interrupts */
         V_SPI_Regs->spim.R = 0ul;

         /* Clear All eSPI events */
         V_SPI_Regs->spie.R = C_SPI_CLEAR_GLOBAL_REG_MASK;
      }

      /* Link the SPI chip select (SpiID) with the given bus config */
      V_SPI_Regs->spmodex[SpiID].R = bus_Config->R;

      /* espi is configured */
      v_ret = E_LIBBSP_SPI_OK;
   }
   else
   {
	   v_ret = E_LIBBSP_SPI_INVALID_ID;
   }

   return v_ret; /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
}
/*==== END =============================================================================*/
