#include "BOOT_TCAHW_Decrementer.h"
#include "BOOT_ManageInterrupts.h"

#include "LIBBSP_CMN.h"

volatile boolean_t DecrementerIT_TestUnderway;

void BOOT_TCAHW_LoadDecrementerWith500us(void);
void BOOT_TCAHW_EnableDecrementerIT(void);
void BOOT_TCAHW_DisableDecrementerIT(void);

void BOOT_TCAHW_Decrementer(
/*OUT*/
/* {{RELAX<SYNCHRONe_C_Code_8.18> Those parameters are outputs */
   boolean_t* p_PBIT_Failed,
   ts_PBIT_Results* p_PBIT_Results
/* }} RELAX<SYNCHRONe_C_Code_8.18> */
)
{
   uint32_t v_TimeoutCounter;

   ExpectedDecrementerIT_Raised = FALSE;
   DecrementerIT_TestUnderway = TRUE;
   v_TimeoutCounter = 1000ul; /*10000us*/
   BOOT_TCAHW_EnableDecrementerIT();
   BOOT_TCAHW_LoadDecrementerWith500us();
   while((LIBBSP_CMN_isElapsed(&v_TimeoutCounter) == 0ul)
      && (ExpectedDecrementerIT_Raised == FALSE))
   {}
   DecrementerIT_TestUnderway = FALSE;
   BOOT_TCAHW_DisableDecrementerIT();
   if(ExpectedDecrementerIT_Raised == FALSE)
   {
      *p_PBIT_Failed = TRUE;
      p_PBIT_Results->DecrementerIT_PBIT_Failed = TRUE;
   }
}
