/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This function initializes the module FCCU.
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "BOOT_FCCU_REG_private.h"
#include "BOOT_FCCU_ERR_SRC_REG_private.h"
#include "BOOT_FCCU_public.h"
#include "BOOT_WDG_public.h"
#include "BOOT_MC_public.h"
#include "BOOT_RESET_public.h"

/* ---------- include required interface: ----------------------------------- */
/* none */
/* ---------- internal define constants: ------------------------------------ */
/* none */

/* ---------- internal types: ----------------------------------------------- */
/* none */

/* ---------- provided constants: ------------------------------------------- */
/* none */

/* ---------- provided data: ------------------------------------------------ */
/* none */

/* ---------- internal constants: ------------------------------------------- */
/* none */

/* ---------- internal data: ------------------------------------------------ */
/* none */

/* ---------- provided operation bodies: ------------------------------------ */
/* none */

/* Implements REQ.MY_REQID-LLR_0XX */
void BOOT_FCCU_CLEAR_FAULTS ( void )
{
   uint32_t v_value;
   uint32_t v_status;

   /*******          Clear Faults in source modules      ************/

   /*    Clear PMC flags   */
   /* For errors 1 and 2*/
   /* {{RELAX<SYNCHRONe_C_Code_10.7> The cast is safe : from uint32_t to volatile uint32_t */
   PMCDIG_EPR_VD3 = PMCDIG_EPR_VD3_CLEAR_VAL;
   PMCDIG_EPR_VD4 = PMCDIG_EPR_VD4_CLEAR_VAL;
   PMCDIG_EPR_VD7 = PMCDIG_EPR_VD7_CLEAR_VAL;
   PMCDIG_EPR_VD8 = PMCDIG_EPR_VD8_CLEAR_VAL;
   PMCDIG_EPR_VD9 = PMCDIG_EPR_VD9_CLEAR_VAL;
   PMCDIG_EPR_VD10 = PMCDIG_EPR_VD10_CLEAR_VAL;
   PMCDIG_EPR_VD12 = PMCDIG_EPR_VD12_CLEAR_VAL;
   PMCDIG_EPR_VD13 = PMCDIG_EPR_VD13_CLEAR_VAL;
   PMCDIG_EPR_VD14 = PMCDIG_EPR_VD14_CLEAR_VAL;
   PMCDIG_EPR_VD15 = PMCDIG_EPR_VD15_CLEAR_VAL;

   PMCDIG_EPR_TD = PMCDIG_EPR_TD_CLEAR_VAL;

   /*   Clear SSCM Status flag     */
   /* For error 4 */
   SSCM_STATUS = SSCM_STATUS_CLEAR_VAL;

   /*   Clear the STCU2 flag      */
   /* For error 6 and 7 */
   STCU2_ERR_STAT_UFSF = STCU2_UFSF_RFSF_CLEAR;
   STCU2_ERR_STAT_RFSF = STCU2_UFSF_RFSF_CLEAR;

   /*  Clear SWT  */
   /* For errors 12 to 15 and 55*/
   BOOT_WDG_CLEAR_ERROR();

   /* Clear MEMU flags */
   /* For errors 16 to 24, MEMU_ERR_FLAG */
   MEMU_ERR_FLAG = (reg32_t) MEMU_ERR_FLAG_CLEAR_VAL;

   /*Clear IMA flag */
   /* for error 25 */
   IMA_SLCT = IMA_SLCT & IMA_SLCT_CLEAR_VAL;

   /* Clear CMU_0 flag */
   /* For errors 31 to 34 */
   CMU_PLL_CMU_ISR = CMU_PLL_CMU_ISR_CLEAR_VAL;

   /* For error 36, Dummy read of flash memory */
   /* The syntax *(&v_value) is used to discard warning for unused variable */
   *(&v_value)= FLASH_ADDR_DUMMY_READ;

   /* For error 38, clear MCR[RVE] and MCR[RRE] */
   C55FMC_MCR |= C55FMC_MCR_CLEAR_VAL;

   /* For error 50, clear MCSR */
   BOOT_RESET_CLEAR_MCSR();

   /*   Clear errors 29, 30 and 52  */
   BOOT_MC_PLLDIG_CLEAR_STATUS();
   BOOT_MC_RGM_CLEAR_ERROR();

   /* For error 54, nothing to do because FI[0] is not used */

   /*******          Clear Faults in the FCCU module      ************/
   /*
    * 1. Write the proper key into the FCCU_RFK register.
    * 2. Clear the status (flag) bit RFSx => the opcode OP12 is automatically set into the
    * FCCU_CTRL.OPR field.
    * 3. Wait for the completion of the operation (FCCU_CTRL.OPS field).
    */

   /* 1. Write the proper key into the FCCU RFK register */
   /* Non-critical fault key = AB34_98FEh */

   /* {{RELAX<SYNCHRONe_C_Code_10.3> The cast is safe : from uint32_t to volatile uint32_t */
   FCCU_RFK = FCCU_RFK_KEY;

   /* 2. Clear the status (flag) bit RF_Sx => the opcode OP12 is automatically set into the FCCU_CTRL.OPR field */
   /* Read all RF_Sx registers to clear all faults.*/
   FCCU_RF_S0 = FCCU_RF_Sx_W1C;

   /* 3. Verify if state change was successful */
   do
   {
      v_status = (uint32_t)FCCU_CTRL_OPS;
   }
   while ( v_status != FCCU_CTRL_OPS_SUCCESS);

   /* RF_S1 register clear */
   FCCU_RFK = FCCU_RFK_KEY;
   FCCU_RF_S1 = FCCU_RF_Sx_W1C;
   /* Verify if state change was successful */
   do
   {
      v_status = (uint32_t)FCCU_CTRL_OPS;
   }
   while (v_status != FCCU_CTRL_OPS_SUCCESS);

   /* RF_S2 register clear */
   FCCU_RFK = FCCU_RFK_KEY;
   FCCU_RF_S2 = FCCU_RF_Sx_W1C;
   /* Verify if state change was successful */
   do
   {
      v_status = (uint32_t)FCCU_CTRL_OPS;
   }
   while (v_status != FCCU_CTRL_OPS_SUCCESS);
   /* }}<SYNCHRONe_C_Code_10.3> */
   /* }}<SYNCHRONe_C_Code_10.7> */
}



/* ---------- internal operations: ------------------------------------------ */
/* none */
