#ifndef _BOOT_CLSW_LOAD_SW_LOAD_LOADANDTESTSIF_
#define _BOOT_CLSW_LOAD_SW_LOAD_LOADANDTESTSIF_

#include "BOOT_Types.h"

void BOOT_CLSW_LoadSW_Load_LoadAndTestSIF(
/*IN*/
   const uint32_t p_SIFAddress,
   const uint32_t p_ENVMAddress,
/*OUT*/
   boolean_t* p_FlashReadFailed,
   ts_LoadStatus* p_LoadStatus
);

#endif