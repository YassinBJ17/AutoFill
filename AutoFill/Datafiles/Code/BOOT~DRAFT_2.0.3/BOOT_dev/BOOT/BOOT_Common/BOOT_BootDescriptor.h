#ifndef _BOOT_BOOT_DESCRIPTOR_
#define _BOOT_BOOT_DESCRIPTOR_

#include "LIBUTI_BOOT.h"
#include "BOOT_Consts.h"

#define C_BOOT_DESCRIPTOR_NUMBER_OF_COMPAT_CRIT 2ul

#define C_BOOT_BOOTDESCRIPTOR_HEADER_SIZE (uint32_t)(sizeof(TS_BOOT_BootDescriptor) - (C_BOOT_MAX_NUMBER_OF_COMPAT_RULES * sizeof(TS_CompatibilityRule)))
#define C_BOOT_BOOTDESCRIPTOR_SIZE (uint32_t)(C_BOOT_BOOTDESCRIPTOR_HEADER_SIZE + (C_BOOT_DESCRIPTOR_NUMBER_OF_COMPAT_CRIT * sizeof(TS_CompatibilityRule)))

extern const TS_BOOT_BootDescriptor C_BOOT_DESCRIPTOR;

#endif