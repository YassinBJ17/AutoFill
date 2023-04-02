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
 * Function to set the FCCU back to NORMAL mode, leaving the CONFIG state.
 */
void accom_fccu_cfg_validate(void)
{
   uint32_t v_fccu_transition_status;
   /* Provide NORMAL state key */
   FCCU_CTRLK = FCCU_CTRLK_OP_2_KEY;
   /* Going back to NORMAL state is known as OP2 */
   FCCU_CTRL = FCCU_CTRL_OPR_OP2;
   do
   {
      v_fccu_transition_status = (uint32_t)FCCU_CTRL_OPS;
   }
   while (v_fccu_transition_status != FCCU_CTRL_OPS_SUCCESS);
}
