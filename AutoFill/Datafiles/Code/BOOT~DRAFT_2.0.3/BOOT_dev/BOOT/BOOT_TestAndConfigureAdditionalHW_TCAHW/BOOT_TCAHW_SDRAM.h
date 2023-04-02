#ifndef _BOOT_TCAHW_SDRAM_
#define _BOOT_TCAHW_SDRAM_

#include "BOOT_Types.h"

extern volatile boolean_t SDRAM_ECC_TestUnderway;

extern void BOOT_TCAHW_SDRAM(
/*IN*/
   const boolean_t v_PIC_Ready,
/*OUT*/
   boolean_t* p_PBIT_Failed,
   ts_PBIT_Results* p_PBIT_Results
);

#endif