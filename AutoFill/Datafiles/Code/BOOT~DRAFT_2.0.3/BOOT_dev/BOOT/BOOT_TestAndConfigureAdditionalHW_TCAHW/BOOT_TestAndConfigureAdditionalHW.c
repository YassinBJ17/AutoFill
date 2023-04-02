#include "BOOT_TestAndConfigureAdditionalHW.h"
#include "BOOT_TCAHW_MMU_Configuration.h"
#include "BOOT_TCAHW_Decrementer.h"
#include "BOOT_TCAHW_FPU.h"
#include "BOOT_TCAHW_L2SRAM.h"
#include "BOOT_TCAHW_Megatice.h"
#include "BOOT_TCAHW_MMU.h"
#include "BOOT_TCAHW_MRAM.h"
#include "BOOT_TCAHW_PIC.h"
#include "BOOT_TCAHW_PinProg.h"
#include "BOOT_TCAHW_Expander2.h"
#include "BOOT_TCAHW_REG.h"
#include "BOOT_TCAHW_SDRAM.h"
/* #include "BOOT_TCAHW_WD.h" */
#include "BOOT_ManageInterrupts.h"

#include "LIBBSP_GPIO.h"

void BOOT_TestAndConfigureAdditionalHW(
/*OUT*/
/* {{RELAX<SYNCHRONe_C_Code_8.18> Those parameters are outputs */
   boolean_t* p_PinProgPBIT_Failed,
   boolean_t* p_CriticalPBIT_Failed,
   boolean_t* p_MajorPBIT_Failed,
   ts_PBIT_Results* p_PBIT_Results,
   ts_PinProgrammingInputsValues* p_PinProgrammingInputsValues
/* }} RELAX<SYNCHRONe_C_Code_8.18> */
)
{
   boolean_t v_PIC_ready;

   L2SRAM_ECC_TestUnderway = FALSE;
   SDRAM_ECC_TestUnderway = FALSE;
   SchedulingIT_TestUnderway = FALSE;
   DecrementerIT_TestUnderway = FALSE;
   MMU_ForbiddenReadTestUnderway = FALSE;
   MMU_ForbiddenWriteTestUnderway = FALSE;
   MEGATICE_ExpectedExternalIT_Raised = FALSE;

/* Must be disabled if the PLD is not ready to handle it */
   BOOT_TCAHW_WD(
      p_MajorPBIT_Failed,
      p_PBIT_Results
   );
/**/

   BOOT_TCAHW_REG(
      p_CriticalPBIT_Failed,
      p_PBIT_Results
   );

   REG_WriteTlbEntry(
      L2SRAM_TLB_Conf.MAS_Registers.mas0,
      L2SRAM_TLB_Conf.MAS_Registers.mas1,
      L2SRAM_TLB_Conf.MAS_Registers.mas2,
      L2SRAM_TLB_Conf.MAS_Registers.mas3,
      L2SRAM_TLB_Conf.MAS_Registers.mas7
   );
   REG_WriteTlbEntry(
      SDRAM_TLB_Conf.MAS_Registers.mas0,
      SDRAM_TLB_Conf.MAS_Registers.mas1,
      SDRAM_TLB_Conf.MAS_Registers.mas2,
      SDRAM_TLB_Conf.MAS_Registers.mas3,
      SDRAM_TLB_Conf.MAS_Registers.mas7
   );
   REG_WriteTlbEntry(
      CCSR_TLB_Conf.MAS_Registers.mas0,
      CCSR_TLB_Conf.MAS_Registers.mas1,
      CCSR_TLB_Conf.MAS_Registers.mas2,
      CCSR_TLB_Conf.MAS_Registers.mas3,
      CCSR_TLB_Conf.MAS_Registers.mas7
   );
   REG_WriteTlbEntry(
      MEGATICE_PLD_TLB_Conf.MAS_Registers.mas0,
      MEGATICE_PLD_TLB_Conf.MAS_Registers.mas1,
      MEGATICE_PLD_TLB_Conf.MAS_Registers.mas2,
      MEGATICE_PLD_TLB_Conf.MAS_Registers.mas3,
      MEGATICE_PLD_TLB_Conf.MAS_Registers.mas7
   );
   REG_WriteTlbEntry(
      COMPAGNON_PLD_TLB_Conf.MAS_Registers.mas0,
      COMPAGNON_PLD_TLB_Conf.MAS_Registers.mas1,
      COMPAGNON_PLD_TLB_Conf.MAS_Registers.mas2,
      COMPAGNON_PLD_TLB_Conf.MAS_Registers.mas3,
      COMPAGNON_PLD_TLB_Conf.MAS_Registers.mas7
   );
   REG_WriteTlbEntry(
      COMPAGNON_RAM_TLB_Conf.MAS_Registers.mas0,
      COMPAGNON_RAM_TLB_Conf.MAS_Registers.mas1,
      COMPAGNON_RAM_TLB_Conf.MAS_Registers.mas2,
      COMPAGNON_RAM_TLB_Conf.MAS_Registers.mas3,
      COMPAGNON_RAM_TLB_Conf.MAS_Registers.mas7
   );

   v_PIC_ready = BOOT_TCAHW_PIC();

   BOOT_TCAHW_L2SRAM(
      v_PIC_ready,
      p_CriticalPBIT_Failed,
      p_PBIT_Results
   );

   BOOT_TCAHW_SDRAM(
      v_PIC_ready,
      p_CriticalPBIT_Failed,
      p_PBIT_Results
   );

   BOOT_TCAHW_Decrementer(
      p_CriticalPBIT_Failed,
      p_PBIT_Results
   );

   BOOT_TCAHW_Megatice(
      v_PIC_ready,
      p_MajorPBIT_Failed,
      p_PBIT_Results
   );

   BOOT_TCAHW_FPU(
      p_MajorPBIT_Failed,
      p_PBIT_Results
   );

   BOOT_TCAHW_MMU(
      p_CriticalPBIT_Failed,
      p_PBIT_Results
   );

   BOOT_TCAHW_MRAM(
      p_MajorPBIT_Failed,
      p_PBIT_Results
   );

   BOOT_TCAHW_PinProg(
      p_PinProgrammingInputsValues,
      p_PinProgPBIT_Failed,
      p_PBIT_Results
   );

   BOOT_TCAHW_Expander2(
      p_PBIT_Results
   );

   (void) LIBBSP_GPIO_Write(E_LIBBSP_GPIO_GREEN_LED, TRUE);
   (void) LIBBSP_GPIO_Write(E_LIBBSP_GPIO_YELLOW_LED, FALSE);
   (void) LIBBSP_GPIO_Write(E_LIBBSP_GPIO_RED_LED, FALSE);
}
