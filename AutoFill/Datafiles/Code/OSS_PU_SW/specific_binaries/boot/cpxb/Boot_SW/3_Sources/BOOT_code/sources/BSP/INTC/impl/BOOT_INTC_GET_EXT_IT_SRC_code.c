/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This function get the external interrupt sources 
 *               (FCCU, Powercut or other case)
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "BOOT_FAULT_public.h"
#include "BOOT_INTC_private.h"
#include "BOOT_INTC_public.h"

/* ---------- internal define constants: ------------------------------------ */
/* none */

/* ---------- internal types: ----------------------------------------------- */
/* none */
/* ---------- internal operations/ data ------------------------------------- */
/* none */

/* ---------- provided operation bodies: ------------------------------------ */
/* */
/* Implements REQ_[User Project Name]_BOOT-LLR_0XX */
uint32_t BOOT_INTC_GET_EXT_IT_SRC( uint32_t const p_core_nb)
{
   /* Get the source of the interruption for the current core */
   /* >RELAX<SYNCHRONe_C_Code_10.7> The cast is safe : cast from reg32_t to uint32_t */
   const uint32_t c_irq_pri = (uint32_t) INTC_0.s_CPR[p_core_nb].u_CPR_B.s_PRI;
   uint32_t v_return_val;

   switch (c_irq_pri)
   {
      /* It is the Power down interrupt */
      case (INTC_0_PSR_POWERDOWN_IRQ_PRIN):
      v_return_val = BOOT_FAULT_POWERDOWN_IT;
      break;

      /* It is the FCCU ALARM interrupt */
      case (INTC_0_PSR_FCCU_ALARM_IRQ_PRIN):
      v_return_val = BOOT_FAULT_FCCU;
      break;

      /* Other external interrupt */
      default:
      v_return_val = BOOT_FAULT_EXT_IT;
      break;
   }

   return v_return_val;

}
/* ---------- internal operation bodies: ------------------------------------ */
/* none */
