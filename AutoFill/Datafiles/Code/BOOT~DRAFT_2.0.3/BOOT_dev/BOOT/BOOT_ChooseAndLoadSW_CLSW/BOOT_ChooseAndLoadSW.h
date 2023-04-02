#ifndef _BOOT_CHOOSE_AND_LOAD_SW_
#define _BOOT_CHOOSE_AND_LOAD_SW_

#include "BOOT_Types.h"

void BOOT_ChooseAndLoadSW(
/*IN*/
   const boolean_t p_PinProgPBIT_Failed,
   const boolean_t p_MajorPBIT_Failed,
   const boolean_t v_CriticalPBIT_Failed,
   const ts_PinProgrammingInputsValues* const p_PinProgrammingInputsValues,
/*OUT*/
   boolean_t* p_LoadFailed,
   boolean_t* p_FlashReadFailed,
   uint32_t* p_LoadedSoftwareLaunchAddress,
   ts_LoadStatus* p_PrimaryLoadStatus,
   uint32_t* p_NumberOfSecondaryLoads,
   ts_LoadStatus p_SecondaryLoadsStatus[C_BOOT_MAX_NUMBER_OF_SECONDARY_LOAD]
);

#endif
