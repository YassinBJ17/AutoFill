#ifndef _BOOT_CLSW_LOAD_APPLICATIVE_SW_
#define _BOOT_CLSW_LOAD_APPLICATIVE_SW_

#include "BOOT_Types.h"
#include "LIBUTI_COMMON.h"

void BOOT_CLSW_LoadSW(
/*IN*/
   const uint8_t* const p_BOOT_Name,
   const uint32_t p_BOOT_NumberOfCompatibilityRules,
   const TS_CompatibilityRule p_BOOT_CompatibilityRules[C_BOOT_MAX_NUMBER_OF_COMPAT_RULES],
   const uint32_t p_PrimaryLoadLUH_FlashAddress,
   const uint32_t p_PrimaryLoadSIF_Header_FlashAddress,
   const uint32_t p_PrimaryLoadSIF_SHA_EnvmAddress,
/*OUT*/
   boolean_t* p_LoadFailed,
   boolean_t* p_FlashReadFailed,
   uint32_t* p_LoadedSoftwareLaunchAddress,
   ts_LoadStatus* p_PrimaryLoadStatus,
   uint32_t* p_NumberOfSecondaryLoads,
   ts_LoadStatus p_SecondaryLoadsStatus[C_BOOT_MAX_NUMBER_OF_SECONDARY_LOAD]
);

#endif