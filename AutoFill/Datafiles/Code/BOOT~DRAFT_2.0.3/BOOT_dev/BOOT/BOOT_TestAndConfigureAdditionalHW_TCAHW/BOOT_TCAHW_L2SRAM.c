#include "BOOT_TCAHW_L2SRAM.h"
#include "BOOT_ManageInterrupts.h"

#include "LIBBSP_ECCMEM.h"

#define C_FREE_L2SRAM_START_ADDRESS 0x20010000ul
#define C_L2SRAM_END_ADDRESS        0x20040000ul

#define C_L2SRAM_TEST_VALUE_ONE     0x55555555ul
#define C_L2SRAM_TEST_VALUE_TWO     0xAAAAAAAAul

#define C_L2SRAM_SEU_THRESHOLD      (uint8_t)(255)

volatile boolean_t L2SRAM_ECC_TestUnderway;

#pragma section SECTION_L2SRAM_ECC_TEST_DATA "" ".L2SRAM_ECC_TEST_DATA"
#pragma use_section SECTION_L2SRAM_ECC_TEST_DATA L2SRAM_ECC_TestData
uint32_t L2SRAM_ECC_TestData;

void BOOT_TCAHW_L2SRAM(
/*IN*/
   const boolean_t v_PIC_Ready,
/*OUT*/
/* {{RELAX<SYNCHRONe_C_Code_8.18> Those parameters are outputs */
   boolean_t* p_PBIT_Failed,
   ts_PBIT_Results* p_PBIT_Results
/* }} RELAX<SYNCHRONe_C_Code_8.18> */
)
{
   volatile uint32_t* FirstL2SRAM_WordAfterBoot;
   volatile uint32_t* L2SRAM_AddressIterator;
   TE_LIBBSP_ECCMEM_SeuStatus v_ECC_POST_Status;

   L2SRAM_ECC_ExpectedExternalIT_Raised = FALSE;
   FirstL2SRAM_WordAfterBoot = (uint32_t*)C_FREE_L2SRAM_START_ADDRESS;
   if(FirstL2SRAM_WordAfterBoot <= (uint32_t*)C_L2SRAM_END_ADDRESS)
   {
      *FirstL2SRAM_WordAfterBoot = C_L2SRAM_TEST_VALUE_ONE;
      if(*FirstL2SRAM_WordAfterBoot != C_L2SRAM_TEST_VALUE_ONE)
      {
         *p_PBIT_Failed = TRUE;
         p_PBIT_Results->L2SRAM_PBIT_Failed = TRUE;
      }
      else
      {
         *FirstL2SRAM_WordAfterBoot = C_L2SRAM_TEST_VALUE_TWO;
         if(*FirstL2SRAM_WordAfterBoot != C_L2SRAM_TEST_VALUE_TWO)
         {
            *p_PBIT_Failed = TRUE;
            p_PBIT_Results->L2SRAM_PBIT_Failed = TRUE;
         }
         else
         {
            for(L2SRAM_AddressIterator = (volatile uint32_t*)FirstL2SRAM_WordAfterBoot;
               L2SRAM_AddressIterator < (uint32_t*)C_L2SRAM_END_ADDRESS;
               L2SRAM_AddressIterator++) /* %RELAX<SYNCHRONe_C_Code_17.4> Used to cover a large area with pseudo dynamic start point */
            {
               *L2SRAM_AddressIterator = (volatile uint32_t)L2SRAM_AddressIterator; /* %RELAX<SYNCHRONe_C_Code_11.1> We want each value to store it's own address */
            }
         }
      }
   }
   
/*L2SRAM ECC init and test*/
   LIBBSP_ECCMEM_InitializeL2S(E_LIBBSP_ECCMEM_MBU_SEU_EN, E_LIBBSP_ECCMEM_MBU_ONLY_IT, C_L2SRAM_SEU_THRESHOLD);

   if (v_PIC_Ready)
   {
      L2SRAM_ECC_ExpectedExternalIT_Raised = FALSE;
      L2SRAM_ECC_TestUnderway = TRUE;
      v_ECC_POST_Status = LIBBSP_ECCMEM_PostL2S(&L2SRAM_ECC_TestData);
      if(v_ECC_POST_Status != E_LIBBSP_ECCMEM_SEU_OK)
      {
         *p_PBIT_Failed = TRUE;
         p_PBIT_Results->L2SRAM_ECC_PBIT_Failed = TRUE;
      }
      else
      {
         if(L2SRAM_ECC_ExpectedExternalIT_Raised == FALSE)
         {
            *p_PBIT_Failed = TRUE;
            p_PBIT_Results->L2SRAM_ECC_PBIT_Failed = TRUE;
         }
      }
      L2SRAM_ECC_TestUnderway = FALSE;
   }
   else
   {
      *p_PBIT_Failed = TRUE;
      p_PBIT_Results->L2SRAM_ECC_PBIT_Failed = TRUE;
   }
}
