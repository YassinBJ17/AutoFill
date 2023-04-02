#ifndef _BOOT_TCAHW_FPU_
#define _BOOT_TCAHW_FPU_

#include "BOOT_Types.h"

extern volatile boolean_t FPU_TestUnderway;

extern void BOOT_TCAHW_FPU(
/*OUT*/
   boolean_t* p_PBIT_Failed,
   ts_PBIT_Results* p_PBIT_Results
);

#endif