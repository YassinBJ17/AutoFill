/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : FCCU registers management
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "BOOT_FCCU_REG_private.h"
#include "BOOT_FCCU_public.h"
#include "BOOT_FAULT_public.h"

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
void BOOT_FCCU_CHECK_STATUS ( void )
{
   uint32_t v_fccu_rf_s0_val;
   uint32_t v_fccu_rf_s1_val;
   v_fccu_rf_s0_val = BOOT_FCCU_GET_RF_S0();
   v_fccu_rf_s1_val = BOOT_FCCU_GET_RF_S1();

   if ((v_fccu_rf_s0_val != (uint32_t)0) || (v_fccu_rf_s1_val!= (uint32_t)0))
   {
      BOOT_FCCU_CLEAR_FAULTS();
      /* For non-critical errors, no sanction is needed, boot execution continues */
      BOOT_FAULT_LOG(BOOT_FAULT_FCCU, FCCU_ORIGIN, v_fccu_rf_s0_val,v_fccu_rf_s1_val,LGBK_FIELD_DEFAULT_VALUE,LGBK_FIELD_DEFAULT_VALUE);

   }
   /* }}<SYNCHRONe_C_Code_10.3, SYNCHRONe_C_Code_10.7> */
}

/* ---------- internal operations: ------------------------------------------ */
/* none */
