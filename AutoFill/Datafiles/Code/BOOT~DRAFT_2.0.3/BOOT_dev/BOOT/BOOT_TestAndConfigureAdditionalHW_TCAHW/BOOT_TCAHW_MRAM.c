#include "BOOT_TCAHW_MRAM.h"

#include "LIBBSP_MRAM.h"

#define C_MRAM_ACCESS_TEST_WORD_ADDRESS   0x0007FFFCul
#define C_MRAM_TEST_VALUE_ZERO            0x00000000ul
#define C_MRAM_TEST_VALUE_ONE             0x55555555ul
#define C_MRAM_TEST_VALUE_TWO             0xAAAAAAAAul

void BOOT_TCAHW_MRAM(
/*OUT*/
/* {{RELAX<SYNCHRONe_C_Code_8.18> Those parameters are outputs */
   boolean_t* p_PBIT_Failed,
   ts_PBIT_Results* p_PBIT_Results
/* }} RELAX<SYNCHRONe_C_Code_8.18> */
)
{
   uint32_t v_MRAM_TestBuffer;
   TE_LIBBSP_MRAM_ErrorCode v_MRAM_OpenErrorCode;
   TE_LIBBSP_MRAM_ErrorCode v_MRAM_WriteErrorCode;
   TE_LIBBSP_MRAM_ErrorCode v_MRAM_ReadErrorCode;

   v_MRAM_OpenErrorCode = LIBBSP_MRAM_Open();
   if(v_MRAM_OpenErrorCode == E_LIBBSP_MRAM_OK)
   {
      v_MRAM_TestBuffer = C_MRAM_TEST_VALUE_ONE;
      LIBBSP_MRAM_Write(C_MRAM_ACCESS_TEST_WORD_ADDRESS, sizeof(uint32_t), (uint8_t*) &v_MRAM_TestBuffer, &v_MRAM_WriteErrorCode); /* %RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> Using uint32_t as buffer */
      v_MRAM_TestBuffer = C_MRAM_TEST_VALUE_ZERO;
      LIBBSP_MRAM_Read(C_MRAM_ACCESS_TEST_WORD_ADDRESS, sizeof(uint32_t), (uint8_t*) &v_MRAM_TestBuffer, &v_MRAM_ReadErrorCode); /* %RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> Using uint32_t as buffer */
      if((v_MRAM_WriteErrorCode != E_LIBBSP_MRAM_OK)
         || (v_MRAM_ReadErrorCode != E_LIBBSP_MRAM_OK)
         || (v_MRAM_TestBuffer != C_MRAM_TEST_VALUE_ONE))
      {
         *p_PBIT_Failed = TRUE;
         p_PBIT_Results->MRAM_PBIT_Failed = TRUE;
      }
      v_MRAM_TestBuffer = C_MRAM_TEST_VALUE_TWO;
      LIBBSP_MRAM_Write(C_MRAM_ACCESS_TEST_WORD_ADDRESS, sizeof(uint32_t), (uint8_t*) &v_MRAM_TestBuffer, &v_MRAM_WriteErrorCode); /* %RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> Using uint32_t as buffer */
      v_MRAM_TestBuffer = C_MRAM_TEST_VALUE_ZERO;
      LIBBSP_MRAM_Read(C_MRAM_ACCESS_TEST_WORD_ADDRESS, sizeof(uint32_t), (uint8_t*) &v_MRAM_TestBuffer, &v_MRAM_ReadErrorCode); /* %RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> Using uint32_t as buffer */
      if((v_MRAM_WriteErrorCode != E_LIBBSP_MRAM_OK)
         || (v_MRAM_ReadErrorCode != E_LIBBSP_MRAM_OK)
         || (v_MRAM_TestBuffer != C_MRAM_TEST_VALUE_TWO))
      {
         *p_PBIT_Failed = TRUE;
         p_PBIT_Results->MRAM_PBIT_Failed = TRUE;
      }
      (void) LIBBSP_MRAM_Close();
   }
   else
   {
      *p_PBIT_Failed = TRUE;
      p_PBIT_Results->MRAM_PBIT_Failed = TRUE;
   }
}
