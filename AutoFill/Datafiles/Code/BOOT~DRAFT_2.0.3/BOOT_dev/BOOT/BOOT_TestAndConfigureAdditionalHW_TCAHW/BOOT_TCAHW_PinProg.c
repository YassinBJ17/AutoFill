#include "BOOT_TCAHW_PinProg.h"
#include "BOOT_TCAHW_PinProg_Test.h"

#include "LIBBSP_CMN.h"
#include "LIBBSP_DISC.h"
#include "LIBBSP_GPIO.h"

void BOOT_TCAHW_PinProg(
/*OUT*/
/* {{RELAX<SYNCHRONe_C_Code_8.18> Those parameters are outputs */
   ts_PinProgrammingInputsValues* p_PinProgrammingInputsValues,
   boolean_t* p_PBIT_Failed,
   ts_PBIT_Results* p_PBIT_Results
/* }} RELAX<SYNCHRONe_C_Code_8.18> */
)
{
   TE_LIBBSP_I2C_Code v_I2C_ReturnCode;
   uint32_t v_Index;
   uint32_t v_TimeoutCounter;
   uint16_t v_IO_Exp1Reading;
   boolean_t v_PAR_PinProgrammingInputReadings[C_BOOT_TCAHW_PINPROG_NB_OF_TESTS];
   boolean_t v_LABO_PinProgrammingInputReadings[C_BOOT_TCAHW_PINPROG_NB_OF_TESTS];
   boolean_t v_DTL_PinProgrammingInputReadings[C_BOOT_TCAHW_PINPROG_NB_OF_TESTS];
   boolean_t v_ID1_PinProgrammingInputReadings[C_BOOT_TCAHW_PINPROG_NB_OF_TESTS];
   boolean_t v_ID2_PinProgrammingInputReadings[C_BOOT_TCAHW_PINPROG_NB_OF_TESTS];

   (void) LIBBSP_GPIO_Configure();
   (void) LIBBSP_I2C_Initialize();
   v_I2C_ReturnCode = LIBBSP_DISC_Open(E_LIBBSP_DISC_EXPANDER_1);
   if(v_I2C_ReturnCode != E_LIBBSP_I2C_OK)
   {
      (void) LIBBSP_DISC_Close();
      *p_PBIT_Failed = TRUE;
      p_PBIT_Results->PinProgAccessPBIT_Failed = TRUE;
      return;
   }
   v_I2C_ReturnCode = LIBBSP_DISC_Configure(E_LIBBSP_DISC_EXPANDER_1);
   if(v_I2C_ReturnCode != E_LIBBSP_I2C_OK)
   {
      (void) LIBBSP_DISC_Close();
      *p_PBIT_Failed = TRUE;
      p_PBIT_Results->PinProgAccessPBIT_Failed = TRUE;
      return;
   }
   for(v_Index=0ul;v_Index<C_BOOT_TCAHW_PINPROG_NB_OF_TESTS;v_Index++)
   {
      v_LABO_PinProgrammingInputReadings[v_Index]
         = LIBBSP_GPIO_Read(E_LIBBSP_GPIO_DSI_SG_LABO);
      v_DTL_PinProgrammingInputReadings[v_Index]
         = LIBBSP_GPIO_Read(E_LIBBSP_GPIO_DSI_DL);
      v_PAR_PinProgrammingInputReadings[v_Index] = FALSE;
      v_ID1_PinProgrammingInputReadings[v_Index] = FALSE;
      v_ID2_PinProgrammingInputReadings[v_Index] = FALSE;
      LIBBSP_DISC_Read(
         E_LIBBSP_DISC_EXPANDER_1,
         &v_IO_Exp1Reading,
         &v_I2C_ReturnCode
      );
      if(v_I2C_ReturnCode != E_LIBBSP_I2C_OK)
      {
         *p_PBIT_Failed = TRUE;
         p_PBIT_Results->PinProgAccessPBIT_Failed = TRUE;
         break;
      }
      if ((v_IO_Exp1Reading & (uint16_t)0x0100) == (uint16_t)0)
      {
         v_PAR_PinProgrammingInputReadings[v_Index] = TRUE;
      }
      if ((v_IO_Exp1Reading & (uint16_t)0x0010) == (uint16_t)0)
      {
         v_ID1_PinProgrammingInputReadings[v_Index] = TRUE;
      }
      if ((v_IO_Exp1Reading & (uint16_t)0x0020) == (uint16_t)0)
      {
         v_ID2_PinProgrammingInputReadings[v_Index] = TRUE;
      }
      BOOT_TCAHW_PinProg_Test(
         v_Index,
         v_PAR_PinProgrammingInputReadings,
         v_LABO_PinProgrammingInputReadings,
         v_DTL_PinProgrammingInputReadings,
         v_ID1_PinProgrammingInputReadings,
         v_ID2_PinProgrammingInputReadings,
         p_PBIT_Failed,
         p_PBIT_Results
      );
      /*50ms wait before next reading of pin progs*/
      if(v_Index < (C_BOOT_TCAHW_PINPROG_NB_OF_TESTS - 1ul))
      {
         v_TimeoutCounter = 5000ul; /*50000us*/
         while(LIBBSP_CMN_isElapsed(&v_TimeoutCounter) == 0ul){} /*Wait 50ms*/
      }
   }
   (void) LIBBSP_DISC_Close();
   p_PinProgrammingInputsValues->PAR = v_PAR_PinProgrammingInputReadings[v_Index];
   p_PinProgrammingInputsValues->LABO = v_LABO_PinProgrammingInputReadings[v_Index];
   p_PinProgrammingInputsValues->DTL = v_DTL_PinProgrammingInputReadings[v_Index];
   p_PinProgrammingInputsValues->ID1 = v_ID1_PinProgrammingInputReadings[v_Index];
   p_PinProgrammingInputsValues->ID2 = v_ID2_PinProgrammingInputReadings[v_Index];
}
