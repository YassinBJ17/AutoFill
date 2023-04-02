/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Watchdog CBIT function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/watchdog/watchdog_private.h"

/* ---------- include required interface: ----------------------------------- */
#include "middleware/reset/reset_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */
/* At each check of activity the values to write are different to check if the value is incremented */

/* Value 1 to write in activity_check_in of register WD_ACTIVITY_CHECK_IN_REG */
#define K_CBIT_WDG_ACTIVITY_CHECK_1_IN  (reg32_t)(0xCAFDFFFF)
#define K_CBIT_WDG_ACTIVITY_CHECK_1_OUT (reg32_t)(0xCAFE0000)

/* Value 2 to write in activity_check_in of register WD_ACTIVITY_CHECK_IN_REG */
#define K_CBIT_WDG_ACTIVITY_CHECK_2_IN  (reg32_t)(0x1233FFFF)
#define K_CBIT_WDG_ACTIVITY_CHECK_2_OUT (reg32_t)(0x12340000)

/* ---------- internal data: ------------------------------------------------ */
/*-- CBIT global failure --*/
uint32_t   c_watchdog_cbit_report;

/* ---------- provided operation bodies: ------------------------------------ */


/* ---------- internal operations: ------------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-WATCHDOG-0020 */
/* Perform the CBIT on the watchdog */
void watchdog_cbit(void)
{
   /* Local Variable Declaration */
   ts_watchdog_reg volatile *        pt_WD_reg;
   tu_watchdog_cmd                   u_fpga_cmd;
   reg32_t                           v_ExpectedActivityValue;
   tu_watchdog_cbit_fail             u_cbit_fail_cr;

   /* Initialization Variable */
   pt_WD_reg                         = (ts_watchdog_reg volatile *)K_WATCHDOG_REG_ADDR;
   u_fpga_cmd.u_register             = WD_INIT_UINT_VALUE32;
   u_cbit_fail_cr.u_datafail         = WD_NOFAIL_REPPORT;
   v_ExpectedActivityValue           = WD_INIT_REG_VALUE32;

   /* Source code start */

   /* /!\ WARNING /!\ */
   /* In conformity with the FPGA system, the delay of update is to 200ns */
   /* In the first part of the source code, we write in the register to let FPGA updating its status */
   /* Increment the value of the watchdog activity check in {wdgActivityCheckIn} by one in the FPGA as defined in BSIS */
   /* Acquire the watchdog activity check out {fpga_wdgActivityCheckOut} from the FPGA as defined in BSIS. */

   if (V_CBIT_WDG_IsValue1ActivityCheck == e_CMN_FLAG_YES)
   {
      pt_WD_reg->s_ACTIVITY_CHECK_IN     = K_CBIT_WDG_ACTIVITY_CHECK_1_IN ;
      v_ExpectedActivityValue            = K_CBIT_WDG_ACTIVITY_CHECK_1_OUT;
      V_CBIT_WDG_IsValue1ActivityCheck   = e_CMN_FLAG_NO;
   }
   else
   {
      pt_WD_reg->s_ACTIVITY_CHECK_IN     = K_CBIT_WDG_ACTIVITY_CHECK_2_IN  ;
      v_ExpectedActivityValue            = K_CBIT_WDG_ACTIVITY_CHECK_2_OUT;
      V_CBIT_WDG_IsValue1ActivityCheck   = e_CMN_FLAG_YES;
   }

   /* 2 - Check the status */
   u_fpga_cmd.u_register             = (uint32_t)pt_WD_reg->s_STATUS;

   /* In operational mode no any standard reset are plan. Accordingly from BSIS document, source code include only one ARM command.*/
   if( u_fpga_cmd.u_bit_status.s_Arm_Counter != WD_ARM_COUNTER_EXPECT_32VALUE )
   {
      u_cbit_fail_cr.u_bit_cbit_fail.s_Armcounter_fail = WD_FAIL_BIT1;
   }

   if( u_fpga_cmd.u_bit_status.s_Irq_State != WD_IRQ_STATE_EXPECT_32VALUE )
   {
      u_cbit_fail_cr.u_bit_cbit_fail.s_Irqstate_fail  = WD_FAIL_BIT1;
   }

   if( u_fpga_cmd.u_bit_status.s_Irq_Config != WD_IRQ_CONF_EXPECT_32VALUE )
   {
      u_cbit_fail_cr.u_bit_cbit_fail.s_Irqconfig_fail = WD_FAIL_BIT1;
   }

   if( u_fpga_cmd.u_bit_status.s_Wd_State != WD_ARM_STATUS_EXPECT_32VALUE )
   {
      u_cbit_fail_cr.u_bit_cbit_fail.s_Armstate_fail = WD_FAIL_BIT1;
   }

   if( u_fpga_cmd.u_bit_status.s_Init_mode != WD_INIT_MODE_EXPECT_32VALUE )
   {
      u_cbit_fail_cr.u_bit_cbit_fail.s_Initmode_fail = WD_FAIL_BIT1;
   }

   /* Clean local value before the REFRESH_COUNTER control */
   u_fpga_cmd.u_register             = WD_INIT_UINT_VALUE32;

   /* 3 - Acquire the watchdog refresh counter {fpga_wdgRefreshCounter} from the FPGA as defined in BSIS */
   u_fpga_cmd.u_register             = (uint32_t)(pt_WD_reg->s_TIMER_REFRESH_COUNT);

   /* Set the watchdog refresh command fault state <isWdgRefreshNotValid> of the watchdog CBIT status {wdgCbitStatus} to #K_TRUE# */
   /* when the watchdog refresh counter acquired after the refresh command is not equal to the watchdog refresh counter */
   /* acquired before the command incremented by one, */
   if ( (uint16_t)(u_fpga_cmd.u_bit_timerrefresh.s_refresh_counter) != V_CBIT_WDG_ActivityValue )
   {
      u_cbit_fail_cr.u_bit_cbit_fail.s_Refrechcounter_fail = WD_FAIL_BIT1;
   }

   /* Set the watchdog inconsistency activity fault state <isWdgActivityFault> of the watchdog CBIT status {wdgCbitStatus}*/
   /* to #K_TRUE# when the watchdog activity check out {fpga_wdgActivityCheckOut} */
   /* is different from the value written on the activity check in {wdgActivityCheckIn} incremented by one, */
   if ( pt_WD_reg->s_ACTIVITY_CHECK_OUT != v_ExpectedActivityValue)
   {
      u_cbit_fail_cr.u_bit_cbit_fail.s_Activitycheck_fail = WD_FAIL_BIT1;
   }

   /* If there is a watchdog failure then critical failure: */
   /* TODO - log fault */
   /* - command a critical reset  */
   c_watchdog_cbit_report = u_cbit_fail_cr.u_datafail ;

   if ( u_cbit_fail_cr.u_datafail != WD_NOFAIL_REPPORT )
   {
      c_watchdog_cbit_error++;
      /* REMOVE BEFORE INTEGRATE */
      /*reset_critical();*/
   }

   return;
}

