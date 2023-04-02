/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Write parameters in shmem
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/powersup/powersup_private.h"
#include "middleware/powersup/powersup_public.h"

/* ---------- include required interface: ----------------------------------- */
#include "memory/oss_section_def_public.h"
#include "memory/lib_critical_service_section_def_data.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */


/* ---------- provided operation bodies: ------------------------------------- */
/* Implements REQ_FADEX_OS_SRD-POWERSUP-0010 */
/* Implements REQ_FADEX_OS_SRD-POWERSUP-0030 */
/* Transmit fault word to share memory */
void powersup_transmit(
      uint32_t* const c_alt_fault_word,
      uint32_t* const c_28v_fault_word)
{
   /* Transmit in share memory the fault word */
   /* For 28V */
   shmem.s_pw_srce.s_pw_28v_fault.u_word  = *c_28v_fault_word;

   /* For ALT */
   shmem.s_pw_srce.s_pw_alt_fault.u_word  = *c_alt_fault_word;

   /* OC_POWERED READ functionality in shared memory for opposite channel */
   shmem.s_oc_pwr                         = (uint32_t)*GPDI_197_POR_OPP_N ;

   return;
}

/* ---------- internal operations: ------------------------------------------ */
