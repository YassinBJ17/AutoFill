#include "BOOT_TCAHW_PinProg_Test.h"

void BOOT_TCAHW_PinProg_Test(
/*IN*/
   const uint32_t p_Index,
   const boolean_t p_PAR_PinProgrammingInputReadings[C_BOOT_TCAHW_PINPROG_NB_OF_TESTS],
   const boolean_t p_LABO_PinProgrammingInputReadings[C_BOOT_TCAHW_PINPROG_NB_OF_TESTS],
   const boolean_t p_DTL_PinProgrammingInputReadings[C_BOOT_TCAHW_PINPROG_NB_OF_TESTS],
   const boolean_t p_ID1_PinProgrammingInputReadings[C_BOOT_TCAHW_PINPROG_NB_OF_TESTS],
   const boolean_t p_ID2_PinProgrammingInputReadings[C_BOOT_TCAHW_PINPROG_NB_OF_TESTS],
/*OUT*/
/* {{RELAX<SYNCHRONe_C_Code_8.18> Those parameters are outputs */
   boolean_t* p_PBIT_Failed,
   ts_PBIT_Results* p_PBIT_Results
/* }} RELAX<SYNCHRONe_C_Code_8.18> */
)
{
   /*Flickering test*/
   if(p_Index > 0ul)
   {
      if ((p_PAR_PinProgrammingInputReadings[p_Index]
            ^ p_PAR_PinProgrammingInputReadings[p_Index-1ul]) != FALSE)
      {
         p_PBIT_Results->PAR_PinProgFlickeringPBIT_Failed = TRUE;
      }
      if ((p_LABO_PinProgrammingInputReadings[p_Index]
            ^ p_LABO_PinProgrammingInputReadings[p_Index-1ul]) != FALSE)
      {
         p_PBIT_Results->LABO_PinProgFlickeringPBIT_Failed = TRUE;
      }
      if ((p_DTL_PinProgrammingInputReadings[p_Index]
            ^ p_DTL_PinProgrammingInputReadings[p_Index-1ul]) != FALSE)
      {
         p_PBIT_Results->DTL_PinProgFlickeringPBIT_Failed = TRUE;
      }
      if ((p_ID1_PinProgrammingInputReadings[p_Index]
            ^ p_ID1_PinProgrammingInputReadings[p_Index-1ul]) != FALSE)
      {
         p_PBIT_Results->ID1_PinProgFlickeringPBIT_Failed = TRUE;
      }
      if ((p_ID2_PinProgrammingInputReadings[p_Index]
            ^ p_ID2_PinProgrammingInputReadings[p_Index-1ul]) != FALSE)
      {
         p_PBIT_Results->ID2_PinProgFlickeringPBIT_Failed = TRUE;
      }
   }
   if((p_PBIT_Results->PAR_PinProgFlickeringPBIT_Failed)
      || (p_PBIT_Results->LABO_PinProgFlickeringPBIT_Failed)
      || (p_PBIT_Results->DTL_PinProgFlickeringPBIT_Failed)
      || (p_PBIT_Results->ID1_PinProgFlickeringPBIT_Failed)
      || (p_PBIT_Results->ID2_PinProgFlickeringPBIT_Failed)
   )
   {
      p_PBIT_Results->PinProgFlickeringPBIT_Failed = TRUE;
   }
   /*Parity test*/
   if((p_PAR_PinProgrammingInputReadings[p_Index]
         ^ p_LABO_PinProgrammingInputReadings[p_Index]
         ^ p_DTL_PinProgrammingInputReadings[p_Index]
         ^ p_ID1_PinProgrammingInputReadings[p_Index]
         ^ p_ID2_PinProgrammingInputReadings[p_Index])
      == FALSE
   )
   {
      p_PBIT_Results->PinProgParityPBIT_Failed = TRUE;
   }
   if((p_PBIT_Results->PinProgFlickeringPBIT_Failed)
      || (p_PBIT_Results->PinProgParityPBIT_Failed)
   )
   {
      *p_PBIT_Failed = TRUE;
   }
}
