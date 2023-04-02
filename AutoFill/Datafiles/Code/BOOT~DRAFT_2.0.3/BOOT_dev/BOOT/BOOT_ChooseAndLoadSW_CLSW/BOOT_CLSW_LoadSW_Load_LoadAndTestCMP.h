#ifndef _BOOT_CLSW_LOAD_SW_LOAD_LOADANDTESTCMP_
#define _BOOT_CLSW_LOAD_SW_LOAD_LOADANDTESTCMP_

#include "BOOT_Types.h"
#include "LIBUTI_COMMON.h"

void BOOT_CLSW_LoadSW_Load_LoadAndTestCMP(
   /*IN*/
   const TS_FileInfo* const p_FileInfo,
   const uint8_t* const p_Master_Name,
   const uint32_t p_Master_NumberOfCompatibilityRules,
   const TS_CompatibilityRule* const p_Master_CompatibilityRules,
   /*OUT*/
   boolean_t* p_LoadedByBoot,
   boolean_t* p_CheckedByBootInFlash,
   uint32_t* p_NumberOfCompatibilityRules,
   TS_CompatibilityRule* p_CompatibilityRules,
   boolean_t* p_FlashReadFailed,
   ts_LoadStatus* p_LoadStatus
);

#endif