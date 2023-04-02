#ifndef _BOOT_TCAHW_PINPROG_TEST_
#define _BOOT_TCAHW_PINPROG_TEST_

#include "BOOT_Types.h"

#define C_BOOT_TCAHW_PINPROG_NB_OF_TESTS 3ul

extern void BOOT_TCAHW_PinProg_Test(
/*IN*/
   const uint32_t p_Index,
   const boolean_t p_PAR_PinProgrammingInputReadings[C_BOOT_TCAHW_PINPROG_NB_OF_TESTS],
   const boolean_t p_LABO_PinProgrammingInputReadings[C_BOOT_TCAHW_PINPROG_NB_OF_TESTS],
   const boolean_t p_DTL_PinProgrammingInputReadings[C_BOOT_TCAHW_PINPROG_NB_OF_TESTS],
   const boolean_t p_ID1_PinProgrammingInputReadings[C_BOOT_TCAHW_PINPROG_NB_OF_TESTS],
   const boolean_t p_ID2_PinProgrammingInputReadings[C_BOOT_TCAHW_PINPROG_NB_OF_TESTS],
/*OUT*/
   boolean_t* p_PBIT_Failed,
   ts_PBIT_Results* p_PBIT_Results
);

#endif