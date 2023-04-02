/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This function initializes the module FCCU.
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "BOOT_FCCU_REG_private.h"
#include "BOOT_FCCU_public.h"

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


/* Implements REQ.MY_REQID-LLR_0xx */
void BOOT_FCCU_INIT ( void )
{

   uint32_t v_fccu_transition_status;

   do
   {
      BOOT_FCCU_CLEAR_FAULTS();

      /*
       * Verify that the FCCU is in Normal state
       * 1. Set the OP3 operation into the FCCU_CTRL.OPR field.
       * 2. Wait for the completion of the operation (FCCU_CTRL.OPS field).
       * 3. Read the FCCU status (FCCU_STAT register).
       */

      /* enter config state - OP3 */
      /* {{RELAX<SYNCHRONe_C_Code_10.3, SYNCHRONe_C_Code_10.7> The cast is safe : from uint32_t to volatile uint32_t*/
      FCCU_CTRL = FCCU_CTRL_OPR_OP3;
      /* operational status successful */
      do
      {
         v_fccu_transition_status = (uint32_t)FCCU_CTRL_OPS;
      }
      while (v_fccu_transition_status != FCCU_CTRL_OPS_SUCCESS);
   }
   while(FCCU_STAT_STATUS != FCCU_STAT_NORMAL_STATE);

   /*******     Transition to the Configuration State     ********/

   /* Unlock configuration */
   FCCU_TRANS_LOCK_TRANSKEY = FCCU_TRANSLOCK_KEY;

   /* provide Config state key */
   FCCU_CTRLK = FCCU_CTRLK_OP_1_KEY;

   /* enter config state - OP1 */
   FCCU_CTRL = FCCU_CTRL_OPR_OP1;

   /* Verify if state change was successful */
   do
   {
      v_fccu_transition_status = (uint32_t)FCCU_CTRL_OPS;
   }
   while (v_fccu_transition_status != FCCU_CTRL_OPS_SUCCESS);

   /*******     Configure the FCCU     ********/

   /* Configure all available Fault to be recovered by SW*/
   FCCU_RF_CFG0 = FCCU_RF_CFG0_INIT_VAL;
   FCCU_RF_CFG1 = FCCU_RF_CFG1_INIT_VAL;

   /* Configure FCCU to not react in case of fault */
   FCCU_RFS_CFG0 = FCCU_RFS_CFG0_INIT_VAL;
   FCCU_RFS_CFG1 = FCCU_RFS_CFG1_INIT_VAL;
   FCCU_RFS_CFG2 = FCCU_RFS_CFG2_INIT_VAL;
   FCCU_RFS_CFG3 = FCCU_RFS_CFG3_INIT_VAL;

   /* Activate the ALARM state for all fault */
   FCCU_RF_TOE0 = FCCU_RF_TOE0_INIT_VAL;
   FCCU_RF_TOE1 = FCCU_RF_TOE1_INIT_VAL;

   /* Configure the Alarm time-out */
   FCCU_RF_TO = FCCU_RF_TO_INIT_VAL;

   /* Configure the FCCU to generate an alarm on fault */
   FCCU_IRQ_ALARM_EN0 = FCCU_IRQ_ALARM_EN0_INIT_VAL;
   FCCU_IRQ_ALARM_EN1 = FCCU_IRQ_ALARM_EN1_INIT_VAL;

   /* FCCU moves to ALARM or FAULT state on fault detection */
   FCCU_RF_E0 = FCCU_RF_E0_INIT_VAL;
   FCCU_RF_E1 = FCCU_RF_E1_INIT_VAL;

   /* set up the NORMAL mode of FCCU */
   FCCU_CTRLK = FCCU_CTRLK_OP_2_KEY;     
   FCCU_CTRL = FCCU_CTRL_OPR_OP2;       
   do
   {
      v_fccu_transition_status = (uint32_t)FCCU_CTRL_OPS;
   }
   while (v_fccu_transition_status != FCCU_CTRL_OPS_SUCCESS);

   /* Inject FCCU fault 15 */
   /*FCCU_RFF = 0xF;
   asm("nop");
   asm("nop");
   */

   /* }}<SYNCHRONe_C_Code_10.3, SYNCHRONe_C_Code_10.7> */
}



/* ---------- internal operations: ------------------------------------------ */
/* none */
