#ifndef _BOOT_MANAGE_FAILURES_AND_LAUNCH_SW_
#define _BOOT_MANAGE_FAILURES_AND_LAUNCH_SW_

#include "LIBMCP_Types.h"
#include "BOOT_Types.h"

extern void BOOT_ManageFailuresAndLaunchSW(
   const ts_PBIT_Results* const PBIT_Results,
   const ts_PinProgrammingInputsValues* const PinProgrammingInputsValues,
   const boolean_t LoadFailed,
   const boolean_t FlashReadFailed,
   const uint32_t LoadedSoftwareLaunchAddress,
   const ts_LoadStatus* const PrimaryLoadStatus,
   const uint32_t NumberOfSecondaryLoads,
   const ts_LoadStatus p_SecondaryLoadsStatus[C_BOOT_MAX_NUMBER_OF_SECONDARY_LOAD]
);

#endif