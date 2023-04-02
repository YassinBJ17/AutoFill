#ifndef _BOOT_CLSW_LOAD_SW_LOAD_LOADANDDECRYPT_
#define _BOOT_CLSW_LOAD_SW_LOAD_LOADANDDECRYPT_

#include "BOOT_Types.h"
#include "LIBUTI_COMMON.h"

void BOOT_CLSW_LoadSW_Load_LoadAndDecrypt(
   /*IN*/
   const TS_FileInfo p_DataFilesInfo[C_BOOT_MAX_NUMBER_OF_DATA_FILES],
   const uint32_t p_SIFAddress,
   const uint32_t p_NumberOfDataFiles,
   const boolean_t p_LoadedByBoot,
   const boolean_t p_CheckedByBootInFlash,
   /*OUT*/
   boolean_t* p_FlashReadFailed,
   ts_LoadStatus* p_LoadStatus
);

#endif