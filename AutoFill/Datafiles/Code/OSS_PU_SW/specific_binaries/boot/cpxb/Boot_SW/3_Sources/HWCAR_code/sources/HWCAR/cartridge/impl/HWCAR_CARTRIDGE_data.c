/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Hardware cartridge constant definition
 * -------------------------------------------------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "CMN_CARTRIDGE_public.h"

/* ---------- internal define constants: ------------------------------------ */
/* none */

/* ---------- internal types: ----------------------------------------------- */
/* none */

/* ---------- internal operations: ------------------------------------------ */
/* none */

/* ---------- internal constants: ------------------------------------------- */
#pragma section HEADER_CONST ".hwcar_header" ""
#pragma use_section HEADER_CONST HWCAR_HEADER

/* {{RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> The casts are safe : conversion from function address to*/
/* uint32_t. There is no loss of precision. Moreover, the pointer is not converted to a size inferior of what is it.*/
/* The conversion is valid. */

const ts_SAFRAN_HW_HEADER HWCAR_HEADER =
{
   0xFFFFFFFF,      /* non entry point */
   
   0xDEADC0DE,      /* crc_32 */
   0x21523F21,      /* crc_32_cplt */
   0xFFFFFFFF,      /* checksum_32 */
   0x00000000,      /* checksum_32_cplt */
   
   (uint32_t)&HWCAR_HEADER,
   (((uint32_t)&HWCAR_HEADER) + (uint32_t)sizeof(ts_SAFRAN_HW_HEADER)) -1ul,
   
   { 
      "FADEX" 
   }
   ,  /* project code (8 char) */
   { 
      "HW_CAR" 
   }
   ,  /* software code (8 char) */
   { 
      "ALL.1" 
   }  /* software version (8 char) */
};
/* }}<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> */

#pragma section HEADER_CONST

/* ---------- internal data: ------------------------------------------------ */
/* none */

/* ---------- provided operation bodies: ------------------------------------ */
/* none */

/* ---------- internal operation bodies: ------------------------------------ */
/* none */
