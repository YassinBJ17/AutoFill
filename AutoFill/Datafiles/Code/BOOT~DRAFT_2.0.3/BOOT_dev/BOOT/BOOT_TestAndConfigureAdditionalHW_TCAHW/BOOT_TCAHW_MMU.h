#ifndef _BOOT_TCAHW_MMU_
#define _BOOT_TCAHW_MMU_

#include "BOOT_Types.h"

extern volatile boolean_t MMU_ForbiddenReadTestUnderway;
extern volatile boolean_t MMU_ForbiddenWriteTestUnderway;

extern void BOOT_TCAHW_MMU(
/*OUT*/
   boolean_t* p_PBIT_Failed,
   ts_PBIT_Results* p_PBIT_Results
);

#endif