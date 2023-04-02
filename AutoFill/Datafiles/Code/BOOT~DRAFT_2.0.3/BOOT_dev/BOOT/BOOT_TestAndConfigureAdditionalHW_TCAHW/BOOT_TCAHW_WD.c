#include "BOOT_TCAHW_WD.h"
#include "BOOT_Consts.h"
#include "LIBBSP_PLDCMP.h"
#include "LIBBSP_SHM.h"
#include "LIBBSP_WD.h"

#define C_WATCHDOG_DELAY               (uint16_t)(1)
#define C_WATCHDOG_WIDTH               (uint16_t)(1)

void BOOT_TCAHW_WD(
/*OUT*/
/* {{RELAX<SYNCHRONe_C_Code_8.18> Those parameters are outputs */
   boolean_t* p_PBIT_Failed,
   ts_PBIT_Results* p_PBIT_Results
/* }} RELAX<SYNCHRONe_C_Code_8.18> */
)
{
   TU_LIBBSP_PLDCMP_RegValue v_PLDCMP_RegValue;

   LIBBSP_PLDCMP_GetCmpErrors(&v_PLDCMP_RegValue);
   if(v_PLDCMP_RegValue.CompErrStatus.comp_wd_rst == 0ul)
   {
      LIBBSP_SHM_SetMode(E_LIBBSP_SHM_IDLE_STATE, C_PLD_COMPAGNON_PBITOK_SWITCH_GOLDEN);
      LIBBSP_WD_InitDelay(C_WATCHDOG_DELAY, C_WATCHDOG_WIDTH);
      LIBBSP_WD_Rearm(~C_PLD_COMPAGNON_WATCHDOG_REARM_GOLDEN);
      *p_PBIT_Failed = TRUE;
      p_PBIT_Results->PLD_WatchdogPBIT_Failed = TRUE;
   }
}
