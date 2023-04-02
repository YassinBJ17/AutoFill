/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : The FPGA torque motor initialization
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "middleware/accom/accom_fccu_private.h"
#include "type/common_type.h"
#include "middleware/accom/accom_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */

/* ---------- internal operations: ------------------------------------------ */

/* Implements REQ_FADEX_OS_SRD-RESET-0010 */
/**
 * Function to allow a transition from the NORMAL to the CONFIG state of the
 *   FCCU.
 */
void accom_fccu_cfg_unlock(void)
{
   uint32_t v_fccu_transition_status;
   /* Unlock configuration */
   FCCU_TRANS_LOCK_TRANSKEY = FCCU_TRANSLOCK_KEY;
   /* Provide CONFIG state key */
   FCCU_CTRLK = FCCU_CTRLK_OP_1_KEY;
   /* Entering CONFIG state is known as OP1 */
   FCCU_CTRL = FCCU_CTRL_OPR_OP1;
   /* Verify if state change was successful */
   do
   {
      v_fccu_transition_status = (uint32_t)FCCU_CTRL_OPS;
   }
   while (v_fccu_transition_status != FCCU_CTRL_OPS_SUCCESS);
}
