/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : 
 * -------------------------------------------------------------------------- */



/* ---------- include provided interface: ----------------------------------- */
#include "BOOT_CART_HardwareID.h"

/* ---------- include required interface: ----------------------------------- */
/* none */

/* ---------- internal define constants: ------------------------------------ */
/* none */

/* ---------- internal types: ----------------------------------------------- */
/* none */

/* ---------- internal operations: ------------------------------------------ */
/* none */

/* ---------- internal constants: ------------------------------------------- */
/* none */

/* ---------- internal data: ------------------------------------------------ */
/* none */

/* ---------- provided operation bodies: ------------------------------------ */
/* none */

/* ---------- internal operation bodies: ------------------------------------ */
/* none */

#pragma section SECTION_BOOT_DESCRIPTOR ".BOOT_DESCRIPTOR" ""
#pragma use_section SECTION_BOOT_DESCRIPTOR K_BOOT_DESCRIPTOR
const TS_BootDescriptor K_BOOT_DESCRIPTOR =
{
   /* Length of the Descriptor */
   sizeof(TS_BootDescriptor),

   0x00000001,                       /* Version of the Descriptor*/
   0x00000002,                       /* Revision of the Descriptor */
   BOOT_DESCRIPTOR_PART_NUMBER_SIZE,
   {"SFI_EECFADEX"},             /* HardwareCompatibility */
   {"BOOT_CU"},
   0x00000000, /* CRC32 */
   (uint8_t*) 0x016C0000,            /* DTL LUH address in DLD */
   (uint8_t*) 0x016FFD00,            /* DTL_SIF address in DLD */
   (uint8_t*) 0x01775000,            /* FLS_OS LUH address in DLD */
   (uint8_t*) 0x01770000,            /* TODO : FLS_OS_SIF address in DLD to be coherent with C_FLASH_SIF_BASE_ADDRESS value */
   (uint32_t) BOOT_DESCRIPTOR_NUMBER_OF_COMPAT_CRIT,
   {
      {
         "OLL_CU",
         /* ici c'est la version du boot qui est attendue et qui doit etre superieure a celle mise dans le confCMP_DTL.ini */
         0x00000001,
         0x00000000
      },
      {
         "OSS_CU",
         0x00000001,
         0x00000000
      }
   }
};
