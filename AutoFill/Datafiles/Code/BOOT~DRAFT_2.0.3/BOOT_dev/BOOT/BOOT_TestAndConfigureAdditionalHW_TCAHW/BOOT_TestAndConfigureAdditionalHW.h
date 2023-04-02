#ifndef _BOOT_TEST_AND_CONFIGURE_ADDITIONAL_HW_
#define _BOOT_TEST_AND_CONFIGURE_ADDITIONAL_HW_

#include "BOOT_Types.h"

extern void BOOT_TestAndConfigureAdditionalHW(
/*OUT*/
   boolean_t* PinProgPBIT_Failed,
   boolean_t* CriticalPBIT_Failed,
   boolean_t* MajorPBIT_Failed,
   ts_PBIT_Results* PBIT_Results,
   ts_PinProgrammingInputsValues* PinProgrammingInputsValues
);

#endif