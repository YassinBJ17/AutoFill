#include "BOOT_TCAHW_FPU.h"
#include "BOOT_ManageInterrupts.h"

#include "LIBBSP_FLOAT.h"

#define C_FPU_TEST_ADDITION_OPERAND_1        1.5
#define C_FPU_TEST_ADDITION_OPERAND_2        0.125
#define C_FPU_TEST_ADDITION_EXPECTED_RES     1.625
#define C_FPU_TEST_SUBTRACTION_OPERAND_1     2.625
#define C_FPU_TEST_SUBTRACTION_OPERAND_2     1.0625
#define C_FPU_TEST_SUBTRACTION_EXPECTED_RES  1.5625
#define C_FPU_TEST_PRODUCT_OPERAND_1         12.125
#define C_FPU_TEST_PRODUCT_OPERAND_2         0.2177734375
#define C_FPU_TEST_PRODUCT_EXPECTED_RES      2.6405029296875
#define C_FPU_TEST_DIVISION_OPERAND_1        3.5
#define C_FPU_TEST_DIVISION_OPERAND_2        0.875
#define C_FPU_TEST_DIVISION_EXPECTED_RES     4.0
#define C_FPU_TEST_INV_OPERAND_1             2.0
#define C_FPU_TEST_OVF_OPERAND_2             2.0
#define C_FPU_TEST_DBZ_OPERAND_1             1.0
#define C_FPU_TEST_DBZ_OPERAND_2             0.0

volatile boolean_t FPU_TestUnderway;

void BOOT_TCAHW_FPU(
/*OUT*/
/* {{RELAX<SYNCHRONe_C_Code_8.18> Those parameters are outputs */
   boolean_t* p_PBIT_Failed,
   ts_PBIT_Results* p_PBIT_Results
/* }} RELAX<SYNCHRONe_C_Code_8.18> */
)
{
   volatile float64_t FPU_TestBuffer;
   volatile float64_t FPU_Test_Operand;
   TS_LIBBSP_FLOAT_RegSpefscr SPEFSCR_Buffer;

   ExpectedEFP_DataExceptionIT_Raised = FALSE;
   FPU_TestBuffer = C_FPU_TEST_ADDITION_OPERAND_1 + C_FPU_TEST_ADDITION_OPERAND_2;
   if(FPU_TestBuffer != C_FPU_TEST_ADDITION_EXPECTED_RES)
   {
      *p_PBIT_Failed = TRUE;
      p_PBIT_Results->FPU_PBIT_Failed = TRUE;
   }
   FPU_TestBuffer = C_FPU_TEST_SUBTRACTION_OPERAND_1 - C_FPU_TEST_SUBTRACTION_OPERAND_2;
   if(FPU_TestBuffer != C_FPU_TEST_SUBTRACTION_EXPECTED_RES)
   {
      *p_PBIT_Failed = TRUE;
      p_PBIT_Results->FPU_PBIT_Failed = TRUE;
   }
   FPU_TestBuffer = C_FPU_TEST_PRODUCT_OPERAND_1 * C_FPU_TEST_PRODUCT_OPERAND_2;
   if(FPU_TestBuffer != C_FPU_TEST_PRODUCT_EXPECTED_RES)
   {
      *p_PBIT_Failed = TRUE;
      p_PBIT_Results->FPU_PBIT_Failed = TRUE;
   }
   FPU_TestBuffer = C_FPU_TEST_DIVISION_OPERAND_1 / C_FPU_TEST_DIVISION_OPERAND_2;
   if(FPU_TestBuffer != C_FPU_TEST_DIVISION_EXPECTED_RES)
   {
      *p_PBIT_Failed = TRUE;
      p_PBIT_Results->FPU_PBIT_Failed = TRUE;
   }
   /*set FINVE FOVFE FDBZE*/
   SPEFSCR_Buffer = LIBBSP_FLOAT_GetFPR(); /* %RELAX<SYNCHRONe_C_Code_10.7> Those are the same types */
   SPEFSCR_Buffer.FpscrFields.FINVE = 1ul;
   SPEFSCR_Buffer.FpscrFields.FOVFE = 1ul;
   SPEFSCR_Buffer.FpscrFields.FDBZE = 1ul;
   LIBBSP_FLOAT_SetFPR(SPEFSCR_Buffer.FpscrValue);
   FPU_TestUnderway = TRUE;
   *((uint64_t*)&FPU_Test_Operand) = 0x7ff0000000000001ull; /* %RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> Manually setting to sNaN */
   FPU_TestBuffer = C_FPU_TEST_INV_OPERAND_1 * FPU_Test_Operand; /* %RELAX<SYNCHRONe_C_Code_9.1> Assignment done using pointer */
   SPEFSCR_Buffer = LIBBSP_FLOAT_GetFPR(); /* %RELAX<SYNCHRONe_C_Code_10.7> Those are the same types */
   if((SPEFSCR_Buffer.FpscrFields.FINVS == 0ul) || (ExpectedEFP_DataExceptionIT_Raised == FALSE))
   {
      *p_PBIT_Failed = TRUE;
      p_PBIT_Results->FPU_PBIT_Failed = TRUE;
   }
   ExpectedEFP_DataExceptionIT_Raised = FALSE;
   *((uint64_t*)&FPU_Test_Operand) = 0x7fefffffffffffffull; /* %RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> Manually setting to Max double */
   FPU_TestBuffer = FPU_Test_Operand * C_FPU_TEST_OVF_OPERAND_2; /* %RELAX<SYNCHRONe_C_Code_9.1> Assignment done using pointer */
   SPEFSCR_Buffer = LIBBSP_FLOAT_GetFPR(); /* %RELAX<SYNCHRONe_C_Code_10.7> Those are the same types */
   if((SPEFSCR_Buffer.FpscrFields.FOVFS == 0ul) || (ExpectedEFP_DataExceptionIT_Raised == FALSE))
   {
      *p_PBIT_Failed = TRUE;
      p_PBIT_Results->FPU_PBIT_Failed = TRUE;
   }
   ExpectedEFP_DataExceptionIT_Raised = FALSE;
   FPU_Test_Operand = C_FPU_TEST_DBZ_OPERAND_1;
   FPU_TestBuffer = FPU_Test_Operand / C_FPU_TEST_DBZ_OPERAND_2;
   FPU_TestUnderway = FALSE;
   SPEFSCR_Buffer = LIBBSP_FLOAT_GetFPR(); /* %RELAX<SYNCHRONe_C_Code_10.7> Those are the same types */
   if((SPEFSCR_Buffer.FpscrFields.FDBZS == 0ul) || (ExpectedEFP_DataExceptionIT_Raised == FALSE))
   {
      *p_PBIT_Failed = TRUE;
      p_PBIT_Results->FPU_PBIT_Failed = TRUE;
   }
   ExpectedEFP_DataExceptionIT_Raised = FALSE;
   /*clear EFP enables and sticky bits*/
   SPEFSCR_Buffer = LIBBSP_FLOAT_GetFPR(); /* %RELAX<SYNCHRONe_C_Code_10.7> Those are the same types */
   SPEFSCR_Buffer.FpscrFields.FINVE = 0ul;
   SPEFSCR_Buffer.FpscrFields.FOVFE = 0ul;
   SPEFSCR_Buffer.FpscrFields.FDBZE = 0ul;
   SPEFSCR_Buffer.FpscrFields.FINV = 0ul;
   SPEFSCR_Buffer.FpscrFields.FDBZ = 0ul;
   SPEFSCR_Buffer.FpscrFields.FOVF = 0ul;
   SPEFSCR_Buffer.FpscrFields.FINVS = 0ul;
   SPEFSCR_Buffer.FpscrFields.FOVFS = 0ul;
   SPEFSCR_Buffer.FpscrFields.FDBZS = 0ul;
   LIBBSP_FLOAT_SetFPR(SPEFSCR_Buffer.FpscrValue);
}
