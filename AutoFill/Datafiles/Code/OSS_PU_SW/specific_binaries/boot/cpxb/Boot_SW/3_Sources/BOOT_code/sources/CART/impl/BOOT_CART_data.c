/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Declaration of the BOOT cartridge
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
/* none */

/* ---------- include required interface: ----------------------------------- */
/* LPOS Common Interface */
#include "BOOT_RESET_public.h"
#include "BOOT_CART_private.h"
#include "CMN_CARTRIDGE_public.h"

/* ---------- internal define constants: ------------------------------------ */
/* none */

/* ---------- internal types: ----------------------------------------------- */
/* none */

/* ---------- internal operations: ------------------------------------------ */
/* none */

/* ---------- internal constants: ------------------------------------------- */
#pragma section HEADER_CONST ".boot_header"
#pragma use_section HEADER_CONST BOOT_HEADER

/* {{RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> The casts are safe : conversion from function address to*/
/* uint32_t. There is no loss of precision. Moreover, the pointer is not converted to a size inferior of what */
/* is it. The conversion is valid. */

const ts_SAFRAN_HEADER BOOT_HEADER =
{
   (uint32_t)&BOOT_RESET_PLATFORM,
   
   0xDEADC0DE,      /* crc_32 */
   0x21523F21,      /* crc_32_cplt */
   0xFFFFFFFF,      /* checksum_32 */
   0x00000000,      /* checksum_32_cplt */
   
   (uint32_t)&__CODE_START,
   (uint32_t)&__CODE_END,
   
   /* project code (8 char) */
   {
      "FADEX  "
   }
   ,
   /* software code (8 char) */
   {
      "BOOT    "
   }
   ,
   /* software version (16 char) */
   {
      "VER 0.3.5 "
   }
   ,
   /* PN */
   {
      "263626962-0101  "
   }
};
/* }}<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> */

#pragma section HEADER_CONST

/* ---------- internal data: ------------------------------------------------ */
/* none */

/* ---------- provided operation bodies: ------------------------------------ */
/* none */

/* ---------- internal operation bodies: ------------------------------------ */
/* none */
