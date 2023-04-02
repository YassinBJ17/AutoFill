#include "BOOT_TCAHW_MMU.h"
#include "BOOT_TCAHW_MMU_Configuration.h"
#include "BOOT_ManageInterrupts.h"

#define C_MMU_TEST_WORD_BASE_ADDRESS   0x00000000ul
#define C_MMU_TEST_VALUE               0xA5A5A5A5ul

volatile boolean_t MMU_ForbiddenReadTestUnderway;
volatile boolean_t MMU_ForbiddenWriteTestUnderway;

void BOOT_TCAHW_MMU(
/*OUT*/
/* {{RELAX<SYNCHRONe_C_Code_8.18> Those parameters are outputs */
   boolean_t* p_PBIT_Failed,
   ts_PBIT_Results* p_PBIT_Results
/* }} RELAX<SYNCHRONe_C_Code_8.18> */
)
{
   volatile uint32_t v_MMU_TestBuffer;

   ExpectedDataStorageIT_Raised = FALSE;
   ExpectedDataTLB_ErrorIT_Raised = FALSE;

   /* Resize MMU to only allow vital SDRAM (heap & stack) */
   REG_WriteTlbEntry(
      MMU_PBIT_MIN_ZoneTLB_Conf.MAS_Registers.mas0,
      MMU_PBIT_MIN_ZoneTLB_Conf.MAS_Registers.mas1,
      MMU_PBIT_MIN_ZoneTLB_Conf.MAS_Registers.mas2,
      MMU_PBIT_MIN_ZoneTLB_Conf.MAS_Registers.mas3,
      MMU_PBIT_MIN_ZoneTLB_Conf.MAS_Registers.mas7
   );

   MMU_ForbiddenReadTestUnderway = TRUE;
   /*Read unmapped start of SDRAM*/
   v_MMU_TestBuffer = *((uint32_t*)C_MMU_TEST_WORD_BASE_ADDRESS);
   MMU_ForbiddenReadTestUnderway = FALSE;
   if(!ExpectedDataTLB_ErrorIT_Raised)
   {
      *p_PBIT_Failed = TRUE;
      p_PBIT_Results->MMU_PBIT_Failed = TRUE;
   }
   /* Create RO page containing MMU test word*/
   REG_WriteTlbEntry(
      MMU_PBIT_RO_ZoneTLB_Conf.MAS_Registers.mas0,
      MMU_PBIT_RO_ZoneTLB_Conf.MAS_Registers.mas1,
      MMU_PBIT_RO_ZoneTLB_Conf.MAS_Registers.mas2,
      MMU_PBIT_RO_ZoneTLB_Conf.MAS_Registers.mas3,
      MMU_PBIT_RO_ZoneTLB_Conf.MAS_Registers.mas7
   );
   MMU_ForbiddenWriteTestUnderway = TRUE;
   /*Write to test word in RO page*/
   *((uint32_t*)C_MMU_TEST_WORD_BASE_ADDRESS) = C_MMU_TEST_VALUE;
   MMU_ForbiddenWriteTestUnderway = FALSE;
   if(!ExpectedDataStorageIT_Raised)
   {
      *p_PBIT_Failed = TRUE;
      p_PBIT_Results->MMU_PBIT_Failed = TRUE;
   }

   /* Remove RO page containing MMU test word*/
   REG_WriteTlbEntry(
      MMU_PBIT_DIS_ZoneTLB_Conf.MAS_Registers.mas0,
      MMU_PBIT_DIS_ZoneTLB_Conf.MAS_Registers.mas1,
      MMU_PBIT_DIS_ZoneTLB_Conf.MAS_Registers.mas2,
      MMU_PBIT_DIS_ZoneTLB_Conf.MAS_Registers.mas3,
      MMU_PBIT_DIS_ZoneTLB_Conf.MAS_Registers.mas7
   );

   /* Reopen full SDRAM */
   REG_WriteTlbEntry(
      SDRAM_TLB_Conf.MAS_Registers.mas0,
      SDRAM_TLB_Conf.MAS_Registers.mas1,
      SDRAM_TLB_Conf.MAS_Registers.mas2,
      SDRAM_TLB_Conf.MAS_Registers.mas3,
      SDRAM_TLB_Conf.MAS_Registers.mas7
   );
}
