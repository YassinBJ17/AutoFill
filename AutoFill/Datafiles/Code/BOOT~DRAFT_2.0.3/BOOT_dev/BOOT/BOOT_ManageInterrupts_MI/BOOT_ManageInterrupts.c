#include "BOOT_ManageInterrupts.h"
#include "BOOT_FailMode.h"
#include "BOOT_TCAHW_Decrementer.h"
#include "BOOT_TCAHW_FPU.h"
#include "BOOT_TCAHW_L2SRAM.h"
#include "BOOT_TCAHW_Megatice.h"
#include "BOOT_TCAHW_MMU.h"
#include "BOOT_TCAHW_SDRAM.h"
#include "LIBBSP_ECCMEM.h"
#include "LIBBSP_CCSR.h"

#define C_PIC_REG_IACK_ADDRESS   (C_LIBBSP_CCSR_PIC + 0x000A0ul)
#define C_PIC_REG_EOI_ADDRESS    (C_LIBBSP_CCSR_PIC + 0x000B0ul)

/*XXXXXXXXXXXXXXXX*/
volatile boolean_t MEGATICE_ExpectedExternalIT_Raised;             /*Needs to be initialized to FALSE*/
volatile boolean_t L2SRAM_ECC_ExpectedExternalIT_Raised;   /*Needs to be initialized to FALSE*/
volatile boolean_t SDRAM_ECC_ExpectedExternalIT_Raised;    /*Needs to be initialized to FALSE*/
volatile boolean_t ExpectedDataTLB_ErrorIT_Raised;             /*Needs to be initialized to FALSE*/
volatile boolean_t ExpectedDataStorageIT_Raised;               /*Needs to be initialized to FALSE*/
volatile boolean_t ExpectedDecrementerIT_Raised;               /*Needs to be initialized to FALSE*/
volatile boolean_t ExpectedEFP_DataExceptionIT_Raised;         /*Needs to be initialized to FALSE*/

void ExternalInputInterruptHandler(void)
{
   uint32_t v_HighestPendingInterruptVector;
   uint32_t v_regAddr;

   /*Clear interrupt*/
   v_regAddr = C_PIC_REG_IACK_ADDRESS;
   v_HighestPendingInterruptVector = ((volatile tu_PIC_IACK*)v_regAddr)->Fields.VECTOR; /* %RELAX<SYNCHRONe_C_Code_10.7> Reading 16 bits in a 32bit register; there is no loss of precision */
   v_regAddr = C_PIC_REG_EOI_ADDRESS;
   ((volatile tu_PIC_EOI*)v_regAddr)->Fields.EOI_CODE = 0ul; /* %RELAX<SYNCHRONe_C_Code_10.7> Changing 1 bit in a 32bit register; there is no loss of precision */
   if((SchedulingIT_TestUnderway) && (v_HighestPendingInterruptVector == C_BMI_SCHEDULING_IT_VECTOR))
   {
      MEGATICE_ExpectedExternalIT_Raised = TRUE;
   }
   else if((L2SRAM_ECC_TestUnderway) && (v_HighestPendingInterruptVector == C_BMI_ERROR_INTERNAL_IT_VECTOR))
   {
      /* Here, we should clear MBE by writing 1 to the L2_Cache_L2ERRDET register, but if we do that, the LIBBSP would not be able to detect the error */
      /* Instead, we disable the IT */
      LIBBSP_ECCMEM_InitializeL2S(E_LIBBSP_ECCMEM_MBU_SEU_EN, E_LIBBSP_ECCMEM_MBU_SEU_IT_DIS, (uint8_t)255);
      L2SRAM_ECC_ExpectedExternalIT_Raised = TRUE;
   }
   else if((SDRAM_ECC_TestUnderway) && (v_HighestPendingInterruptVector == C_BMI_ERROR_INTERNAL_IT_VECTOR))
   {
      /* Here, we should clear MBE by writing 1 to the DDR_ERR_DETECT register, but if we do that, the LIBBSP would not be able to detect the error */
      /* Instead, we disable the IT */
      LIBBSP_ECCMEM_InitializeDDR(E_LIBBSP_ECCMEM_MBU_SEU_EN, E_LIBBSP_ECCMEM_MBU_SEU_IT_DIS, (uint8_t)255);
      SDRAM_ECC_ExpectedExternalIT_Raised = TRUE;
   }
   else
   {
      BOOT_FailMode();
   }
}
void DecrementerInterruptHandler(void)
{
   if(DecrementerIT_TestUnderway)
   {
      ExpectedDecrementerIT_Raised = TRUE;
   }
   else
   {
      BOOT_FailMode();
   }
}
void EFP_DataExceptionInterruptHandler(void)
{
   if(FPU_TestUnderway)
   {
      ExpectedEFP_DataExceptionIT_Raised = TRUE;
   }
   else
   {
      BOOT_FailMode();
   }
}
void DataTLB_InterruptHandler(void)
{
   if(MMU_ForbiddenReadTestUnderway)
   {
      ExpectedDataTLB_ErrorIT_Raised = TRUE;
   }
   else
   {
      BOOT_FailMode();
   }
}

void DataStorageInterruptHandler(void)
{
   if(MMU_ForbiddenWriteTestUnderway)
   {
      ExpectedDataStorageIT_Raised = TRUE;
   }
   else
   {
      BOOT_FailMode();
   }
}