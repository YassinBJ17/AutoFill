#ifndef _BOOT_CLSW_LOAD_SW_LOAD_LOADANDTESLUD_
#define _BOOT_CLSW_LOAD_SW_LOAD_LOADANDTESLUD_

#include "BOOT_Types.h"
#include "LIBUTI_COMMON.h"

void BOOT_CLSW_LoadSW_Load_LoadAndTestLUD(
   /*IN*/
   const TS_FileInfo* const p_FileInfo,
   /*OUT*/
   uint32_t* p_NumberOfSecondaryLoads,
   TS_SecondaryLoadInfo* p_SecondaryLoadsInfo,
   boolean_t* p_FlashReadFailed,
   ts_LoadStatus* p_LoadStatus
);

#endif