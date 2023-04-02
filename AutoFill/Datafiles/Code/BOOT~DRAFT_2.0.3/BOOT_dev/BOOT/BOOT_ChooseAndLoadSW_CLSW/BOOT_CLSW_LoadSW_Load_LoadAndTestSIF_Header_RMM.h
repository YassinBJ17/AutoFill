#ifndef _BOOT_CLSW_LOAD_SW_LOAD_LOADANDTESTSIF_HEAD_RMM_
#define _BOOT_CLSW_LOAD_SW_LOAD_LOADANDTESTSIF_HEAD_RMM_

#include "BOOT_Types.h"

void BOOT_CLSW_LoadSW_Load_LoadAndTestSIF_Header_RMM(
/*IN*/
   const uint32_t p_SIFAddress,
   const ts_BOOT_Data* const p_BootData,
/*OUT*/
   uint8_t* p_SIF_HeaderBuffer,
   boolean_t* p_FlashReadFailed
);

#endif