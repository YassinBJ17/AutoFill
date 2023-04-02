#include "BOOT_TCAHW_REG.h"

#include "LIBBSP_CCSR.h"

#define C_REG_GUTS_PORPLLSR_VALID_VALUE   0x0404140Aul /* Value and Mask set to accept: */
#define C_REG_GUTS_PORPLLSR_VALID_MASK    0x3F3E3E3Eul /* e500_1_Ratio = 2:1 | e500_0_Ratio = 2:1 or 5:2 | DDR_Ratio = 10:1 | Plat_Ratio = 5:1 */

void BOOT_TCAHW_REG(
   /*OUT*/
/* {{RELAX<SYNCHRONe_C_Code_8.18> Those parameters are outputs */
   boolean_t* p_PBIT_Failed,
   ts_PBIT_Results* p_PBIT_Results
/* }} RELAX<SYNCHRONe_C_Code_8.18> */
)
{
   uint32_t v_regAddr;

   v_regAddr = C_LIBBSP_CCSR_GUTS;
   if ((*((volatile uint32_t *)v_regAddr) & C_REG_GUTS_PORPLLSR_VALID_MASK) != (uint32_t)C_REG_GUTS_PORPLLSR_VALID_VALUE)
   {
      *p_PBIT_Failed = TRUE;
      p_PBIT_Results->ConfRegPBIT_Failed = TRUE;
   }
}
