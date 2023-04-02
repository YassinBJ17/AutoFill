/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_ECCMEM_Globals.h"
#include "LIBBSP_CCSR.h"

/*==== Definitions =====================================================================*/
#define C_LIBBSP_ECCMEM_ERR_DELTA 0xE00

/*==== Variables =======================================================================*/

volatile TS_LIBBSP_ECCMEM_DDRRegisters * const V_EccmemDdrRegs = (volatile TS_LIBBSP_ECCMEM_DDRRegisters * const) (C_LIBBSP_CCSR_ECCMEM_DDR + C_LIBBSP_ECCMEM_ERR_DELTA); /* %RELAX<SYNCHRONe_C_Code_10.7> No precision lost: adress */
volatile TS_LIBBSP_ECCMEM_L2SRAMRegisters * const V_EccmemL2SRAMRegs = (volatile TS_LIBBSP_ECCMEM_L2SRAMRegisters * const) (C_LIBBSP_CCSR_ECCMEM_L2S + C_LIBBSP_ECCMEM_ERR_DELTA); /* %RELAX<SYNCHRONe_C_Code_10.7> No precision lost: adress */

/*==== Services ========================================================================*/

/*==== END =============================================================================*/
