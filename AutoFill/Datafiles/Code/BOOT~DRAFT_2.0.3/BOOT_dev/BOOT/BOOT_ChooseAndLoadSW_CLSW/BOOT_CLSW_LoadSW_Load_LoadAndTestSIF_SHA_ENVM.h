#ifndef _BOOT_CLSW_LOAD_SW_LOAD_LOADANDTESTSIF_SHA_ENVM_
#define _BOOT_CLSW_LOAD_SW_LOAD_LOADANDTESTSIF_SHA_ENVM_

#include "BOOT_Types.h"

void BOOT_CLSW_LoadSW_Load_LoadAndTestSIF_SHA_ENVM(
/*IN*/
   const uint32_t p_ENVMAddress,
/*OUT*/
   ts_BOOT_Data* p_BootData,
   boolean_t* p_FlashReadFailed
);

#endif