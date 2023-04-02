#ifndef _BOOT_CLSW_LOAD_SW_LOAD_FILES_
#define _BOOT_CLSW_LOAD_SW_LOAD_FILES_

#include "BOOT_Types.h"
#include "LIBUTI_COMMON.h"

void BOOT_CLSW_LoadSW_Load_Files(
   /*IN*/
   const uint8_t* const p_Master_Name,
   const uint32_t p_Master_NumberOfCompatibilityRules,
   const TS_CompatibilityRule* const p_Master_CompatibilityRules,
   const uint32_t p_SIFAddress,
   const uint32_t p_NumberOfFiles,
   const uint32_t p_NumberOfDataFiles,
   const uint32_t p_NumberOfSupportFiles,
   const TS_ARINC_665_FileInfo* const p_ARINC_665_DataFilesInfo,
   const TS_ARINC_665_FileInfo* const p_ARINC_665_SupportFilesInfo,
   /*OUT*/
   uint32_t* p_NumberOfCompatibilityRules,
   TS_CompatibilityRule* p_CompatibilityRules,
   uint32_t* p_NumberOfSecondaryLoads,
   TS_SecondaryLoadInfo* p_SecondaryLoadsInfo,
   uint32_t* p_LoadedSoftwareLaunchAddress,
   boolean_t* p_FlashReadFailed,
   ts_LoadStatus* p_LoadStatus
);

#endif