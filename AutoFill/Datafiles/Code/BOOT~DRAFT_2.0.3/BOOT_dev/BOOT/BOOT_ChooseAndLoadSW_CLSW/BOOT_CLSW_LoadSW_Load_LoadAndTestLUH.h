#ifndef _BOOT_CLSW_LOAD_SW_LOAD_LOADANDTESTLUH_
#define _BOOT_CLSW_LOAD_SW_LOAD_LOADANDTESTLUH_

#include "BOOT_Types.h"
#include "LIBUTI_COMMON.h"

void BOOT_CLSW_LoadSW_Load_LoadAndTestLUH(
   /*IN*/
   const TS_FileInfo* const p_FileInfo,
   /*OUT*/
   uint32_t* p_NumberOfFiles,
   uint32_t* p_NumberOfDataFiles,
   uint32_t* p_NumberOfSupportFiles,
   TS_ARINC_665_FileInfo** p_ARINC_665_DataFilesInfo,
   TS_ARINC_665_FileInfo** p_ARINC_665_SupportFilesInfo,
   boolean_t* p_FlashReadFailed,
   ts_LoadStatus* p_LoadStatus
);

#endif