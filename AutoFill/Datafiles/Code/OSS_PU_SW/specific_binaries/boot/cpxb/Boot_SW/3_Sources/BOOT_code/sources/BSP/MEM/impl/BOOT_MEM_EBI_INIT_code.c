/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This function initializes EBI bus registers.
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
/* none */

/* ---------- include required interface: ----------------------------------- */
/* LPOS Common Interface */
/* none */

/* LPOS Public Interface */
/* none */

/* LPOS Private Interface */
#include "BOOT_MEM_public.h"

/* ---------- internal define constants: ------------------------------------ */
/* none */

/* ---------- internal types: ----------------------------------------------- */
/* none */

/* ---------- internal operations: ------------------------------------------ */
/* none */

/* ---------- internal data: ------------------------------------------------ */
/* none */

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_[User Project Name]_BOOT-LLR_045 */
void BOOT_MEM_EBI_INIT( void )
{
   /* See §37 EBI */
   /* >RELAX<SYNCHRONe_C_Code_10.7> The cast is safe as the structure is used to retrieve all EBI registers which */
   /* start at this address. */
   ts_EBI_REG volatile * pt_ebi_regs = (ts_EBI_REG *)EBI_BASE_ADDR;

   pt_ebi_regs->s_EBI_MCR = (reg32_t)EBI_MCR_VAL;
   pt_ebi_regs->s_EBI_BR0 = (reg32_t)EBI_BR0_VAL;
   pt_ebi_regs->s_EBI_OR0 = (reg32_t)EBI_OR0_VAL;
   pt_ebi_regs->s_EBI_BR1 = (reg32_t)EBI_BR1_VAL;
   pt_ebi_regs->s_EBI_OR1 = (reg32_t)EBI_OR1_VAL;
   pt_ebi_regs->s_EBI_BR2 = (reg32_t)EBI_BR2_VAL;
   pt_ebi_regs->s_EBI_OR2 = (reg32_t)EBI_OR2_VAL;

}

/* ---------- internal operation bodies: ------------------------------------ */
/* none */

