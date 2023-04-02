#ifndef _BOOT_CART_HARDWAREID_H_
#define _BOOT_CART_HARDWAREID_H_

/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
 
/* ---------- include provided interface: ----------------------------------- */
/* none */

/* ---------- include required interface: ----------------------------------- */
#include "CMN_TYPES_common.h"
#include "LIBUTI_COMMON.h"

/* ---------- internal define constants: ------------------------------------ */
#define BOOT_DESCRIPTOR_NUMBER_OF_COMPAT_CRIT ((uint32_t)2)
#define BOOT_DESCRIPTOR_MAX_NAME_SIZE 32
#define BOOT_DESCRIPTOR_PART_NUMBER_SIZE 15

/* ---------- internal types: ----------------------------------------------- */
typedef struct
{
   uint32_t             DescriptorLength;
   uint32_t             DescriptorVersion;
   uint32_t             DescriptorRevision;
   uint8_t              PartNumberSize;
   uint8_t              PartNumber[BOOT_DESCRIPTOR_PART_NUMBER_SIZE];
   uint8_t              HardwareCompatibilityID[BOOT_DESCRIPTOR_MAX_NAME_SIZE];
   uint32_t             BOOT_CRC32;
   uint8_t *            DTL_LoadFlashAddress;
   uint8_t *            DTL_LoadSIF_HeaderENVM_Address;
   uint8_t *            OpeLoadFlashAddress;
   uint8_t *            OpeLoadSIF_HeaderENVM_Address;
   uint32_t             NumberOfCompatibilityCriteria;
   TS_CompatibilityRule CompatibilityCriterias[BOOT_DESCRIPTOR_NUMBER_OF_COMPAT_CRIT];
}
TS_BootDescriptor;

/* ---------- internal operations: ------------------------------------------ */
/* none */

/* ---------- internal constants: ------------------------------------------- */
extern const TS_BootDescriptor K_BOOT_DESCRIPTOR;

/* ---------- internal data: ------------------------------------------------ */
/* none */

/* ---------- provided operation bodies: ------------------------------------ */
/* none */

/* ---------- internal operation bodies: ------------------------------------ */


#endif /* End of _BOOT_CART_HARDWARE_ID_H_ */
