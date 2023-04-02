#ifndef _BOOT_TCAHW_PINPROG_
#define _BOOT_TCAHW_PINPROG_

#include "BOOT_Types.h"

extern void BOOT_TCAHW_PinProg(
/*OUT*/
   ts_PinProgrammingInputsValues* p_PinProgrammingInputsValues,
   boolean_t* p_PBIT_Failed,
   ts_PBIT_Results* p_PBIT_Results
);

#endif