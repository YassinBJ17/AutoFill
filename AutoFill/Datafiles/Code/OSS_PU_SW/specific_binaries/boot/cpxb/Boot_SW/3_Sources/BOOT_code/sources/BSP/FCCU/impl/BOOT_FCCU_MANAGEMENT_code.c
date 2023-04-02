/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : FCCU registers management
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
uint32_t BOOT_FCCU_GET_RF_S0 ( void )
{
   uint32_t v_get_S0_status;
   /*
    * Read FCCU_RF_S0
    * 1. Set the OP10 operation into the FCCU_CTRL.OPR field.
    * 2. Wait for the completion of the operation (FCCU_CTRL.OPS field).
    * 3. Read the FCCU status (FCCU_STAT register).
    */
   /* {{RELAX<SYNCHRONe_C_Code_10.3, SYNCHRONe_C_Code_10.7> The cast is safe : from uint32_t to volatile uint32_t */
   FCCU_CTRL = FCCU_CTRL_OPR_OP10;
   do
   {
      v_get_S0_status = (uint32_t)FCCU_CTRL_OPS;
   }
   while (v_get_S0_status != FCCU_CTRL_OPS_SUCCESS);

   return ((uint32_t)FCCU_RF_S0);
   /* }}<SYNCHRONe_C_Code_10.3, SYNCHRONe_C_Code_10.7> */
}

/* Implements REQ.MY_REQID-LLR_0xx */
uint32_t BOOT_FCCU_GET_RF_S1 ( void )
{
   uint32_t v_get_S1_status;
   /*
    * Read FCCU_RF_S1
    * 1. Set the OP10 operation into the FCCU_CTRL.OPR field.
    * 2. Wait for the completion of the operation (FCCU_CTRL.OPS field).
    * 3. Read the FCCU status (FCCU_STAT register).
    */
   /* {{RELAX<SYNCHRONe_C_Code_10.7> The cast is safe : from uint32_t to volatile uint32_t*/
   FCCU_CTRL = FCCU_CTRL_OPR_OP10;
   do
   {
      v_get_S1_status = (uint32_t)FCCU_CTRL_OPS;
   }
   while (v_get_S1_status != FCCU_CTRL_OPS_SUCCESS);

   return ((uint32_t)FCCU_RF_S1);
   /* }}<SYNCHRONe_C_Code_10.7> */
}

/* }}<SYNCHRONe_C_Code_10.3, SYNCHRONe_C_Code_10.7> */

/* ---------- internal operations: ------------------------------------------ */
/* none */
