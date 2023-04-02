#ifndef _BOOT_CLSW_LOAD_SW_LOAD_LOADANDTESTSUP_
#define _BOOT_CLSW_LOAD_SW_LOAD_LOADANDTESTSUP_

#include "BOOT_Types.h"
#include "LIBUTI_COMMON.h"

void BOOT_CLSW_LoadSW_Load_LoadAndTestSUP(
   /*IN*/
   const TS_FileInfo* const p_FileInfo,
   const uint32_t p_NumberOfDataFiles,
   /*INOUT*/
   TS_FileInfo* p_DataFilesInfo,
   /*OUT*/
   uint32_t* p_LoadedSoftwareLaunchAddress,
   boolean_t* p_FlashReadFailed,
   ts_LoadStatus* p_LoadStatus
);

#endif