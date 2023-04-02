#ifndef _BOOT_CLSW_LOAD_SW_LOAD_LOADANDTESTSIF_SHA_RMM_
#define _BOOT_CLSW_LOAD_SW_LOAD_LOADANDTESTSIF_SHA_RMM_

#include "BOOT_Types.h"

void BOOT_CLSW_LoadSW_Load_LoadAndTestSIF_SHA_RMM(
/*IN*/
   const uint32_t p_SIFAddress,
/*OUT*/
   ts_BOOT_Data* p_BootData,
   boolean_t* p_FlashReadFailed,
   ts_LoadStatus* p_LoadStatus
);

#endif