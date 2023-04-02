#ifndef _BOOT_CLSW_LOAD_SW_LOAD_AESDECRYPT_
#define _BOOT_CLSW_LOAD_SW_LOAD_AESDECRYPT_

#include "BOOT_Types.h"
#include "LIBUTI_COMMON.h"

void BOOT_CLSW_LoadSW_Load_AESdecrypt(
   /*IN*/
   const TS_FileInfo* const p_FileInfo,
   const uint32_t p_SIFAddress,
   /*OUT*/
   boolean_t* p_FlashReadFailed,
   ts_LoadStatus* p_LoadStatus
);

#endif