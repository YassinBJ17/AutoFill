#ifndef _BOOT_INIT_STATUS_
#define _BOOT_INIT_STATUS_

#include "BOOT_Consts.h"
#include "BOOT_Types.h"

void BOOT_InitStatus(
    /* IN/OUT */
    boolean_t *p_PinProgPBIT_Failed,
    boolean_t *p_CriticalPBIT_Failed,
    boolean_t *p_MajorPBIT_Failed,
    ts_PBIT_Results *p_PBIT_Results,
    ts_PinProgrammingInputsValues *p_PinProgrammingInputsValues,
    boolean_t *p_LoadFailed,
    boolean_t *p_FlashReadFailed,
    uint32_t *p_LoadedSoftwareLaunchAddress,
    ts_LoadStatus *p_PrimaryLoadStatus,
    uint32_t *p_NumberOfSecondaryLoads,
    ts_LoadStatus p_SecondaryLoadsStatus[C_BOOT_MAX_NUMBER_OF_SECONDARY_LOAD] 
);

#endif