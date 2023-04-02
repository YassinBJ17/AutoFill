#ifndef _BOOT_TCAHW_DECREMENTER_
#define _BOOT_TCAHW_DECREMENTER_

#include "BOOT_Types.h"

extern volatile boolean_t DecrementerIT_TestUnderway;

extern void BOOT_TCAHW_Decrementer(
/*OUT*/
   boolean_t* p_PBIT_Failed,
   ts_PBIT_Results* p_PBIT_Results
);

#endif