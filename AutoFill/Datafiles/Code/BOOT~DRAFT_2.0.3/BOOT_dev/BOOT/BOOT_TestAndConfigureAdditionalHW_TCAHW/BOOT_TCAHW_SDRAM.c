#include "BOOT_TCAHW_SDRAM.h"
#include "BOOT_ManageInterrupts.h"

#include "LIBBSP_ECCMEM.h"

#define C_SDRAM_START_ADDRESS    0x00000000ul
#define C_SDRAM_END_ADDRESS      0x0F800000ul

#define C_SDRAM_TEST_VALUE_ONE   0x55555555ul
#define C_SDRAM_TEST_VALUE_TWO   0xAAAAAAAAul

#define C_SDRAM_SEU_THRESHOLD    (uint8_t)(255)

volatile boolean_t SDRAM_ECC_TestUnderway;

#pragma section SECTION_SDRAM_ECC_TEST_DATA "" ".SDRAM_ECC_TEST_DATA"
#pragma use_section SECTION_SDRAM_ECC_TEST_DATA SDRAM_ECC_TestData
uint32_t SDRAM_ECC_TestData;

void BOOT_TCAHW_SDRAM(
/*IN*/
   const boolean_t v_PIC_Ready,
/*OUT*/
/* {{RELAX<SYNCHRONe_C_Code_8.18> Those parameters are outputs */
   boolean_t* p_PBIT_Failed,
   ts_PBIT_Results* p_PBIT_Results
/* }} RELAX<SYNCHRONe_C_Code_8.18> */
)
{
   volatile uint32_t* v_FirstSDRAM_Word;
   volatile uint32_t* v_SDRAM_AddressIterator;
   TE_LIBBSP_ECCMEM_SeuStatus v_ECC_POST_Status;

   SDRAM_ECC_ExpectedExternalIT_Raised = FALSE;
   v_FirstSDRAM_Word = (uint32_t*)C_SDRAM_START_ADDRESS;
   *v_FirstSDRAM_Word = C_SDRAM_TEST_VALUE_ONE;
   if(*v_FirstSDRAM_Word != C_SDRAM_TEST_VALUE_ONE)
   {
      *p_PBIT_Failed = TRUE;
      p_PBIT_Results->SDRAM_PBIT_Failed = TRUE;
   }
   else
   {
      *v_FirstSDRAM_Word = C_SDRAM_TEST_VALUE_TWO;
      if(*v_FirstSDRAM_Word != C_SDRAM_TEST_VALUE_TWO)
      {
         *p_PBIT_Failed = TRUE;
         p_PBIT_Results->SDRAM_PBIT_Failed = TRUE;
      }
      else
      {
         for(v_SDRAM_AddressIterator = (volatile uint32_t*)C_SDRAM_START_ADDRESS;
            v_SDRAM_AddressIterator < (uint32_t*)C_SDRAM_END_ADDRESS;
            v_SDRAM_AddressIterator++) /* %RELAX<SYNCHRONe_C_Code_17.4> Used to cover a large area with pseudo dynamic start point */
         {
            *v_SDRAM_AddressIterator = (volatile uint32_t)v_SDRAM_AddressIterator; /* %RELAX<SYNCHRONe_C_Code_11.1> We want each value to store it's own address */
         }
      }
   }

   LIBBSP_ECCMEM_InitializeDDR(E_LIBBSP_ECCMEM_MBU_SEU_EN, E_LIBBSP_ECCMEM_MBU_ONLY_IT, C_SDRAM_SEU_THRESHOLD);
   if (v_PIC_Ready)
   {
      SDRAM_ECC_ExpectedExternalIT_Raised = FALSE;
      SDRAM_ECC_TestUnderway = TRUE;
      v_ECC_POST_Status = LIBBSP_ECCMEM_PostDDR(&SDRAM_ECC_TestData);
      if(v_ECC_POST_Status != E_LIBBSP_ECCMEM_SEU_OK)
      {
         *p_PBIT_Failed = TRUE;
         p_PBIT_Results->SDRAM_ECC_PBIT_Failed = TRUE;
      }
      else
      {
         if(SDRAM_ECC_ExpectedExternalIT_Raised == FALSE)
         {
            *p_PBIT_Failed = TRUE;
            p_PBIT_Results->SDRAM_ECC_PBIT_Failed = TRUE;
         }
      }
      SDRAM_ECC_TestUnderway = FALSE;
   }
   else
   {
      *p_PBIT_Failed = TRUE;
      p_PBIT_Results->SDRAM_ECC_PBIT_Failed = TRUE;
   }
}
