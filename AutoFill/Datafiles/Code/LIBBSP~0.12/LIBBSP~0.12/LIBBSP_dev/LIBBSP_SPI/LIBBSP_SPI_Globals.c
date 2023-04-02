/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_SPI_Globals.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/
/* ESPI registers are located on "CCSR Address + 0x0_7000 */
/*#pragma section ESPI_SECTION near-absolute RW address=0xFF707000
#pragma use_section ESPI_SECTION V_SPI_Regs
volatile TS_LIBBSP_SPI_RegisterSet V_SPI_Regs;*/


volatile TS_LIBBSP_SPI_RegisterSet* const V_SPI_Regs = (volatile TS_LIBBSP_SPI_RegisterSet * const) C_LIBBSP_CCSR_SPI; /* %RELAX<SYNCHRONe_C_Code_10.7> No precision lost: adress */

/*==== Services ========================================================================*/

/*==== END =============================================================================*/
