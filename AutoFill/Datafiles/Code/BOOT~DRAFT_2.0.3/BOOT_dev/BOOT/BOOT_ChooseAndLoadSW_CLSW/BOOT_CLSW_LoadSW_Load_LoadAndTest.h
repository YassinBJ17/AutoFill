#ifndef _BOOT_CLSW_LOAD_SW_LOAD_LOADANDTEST_
#define _BOOT_CLSW_LOAD_SW_LOAD_LOADANDTEST_

#include "BOOT_Types.h"
#include "LIBUTI_COMMON.h"

void BOOT_CLSW_LoadSW_Load_LoadAndTest(
/*IN*/
   const TS_FileInfo* const p_FileInfo,
/*OUT*/
   boolean_t* p_FlashReadFailed,
   ts_LoadStatus* p_LoadStatus
);

#endif