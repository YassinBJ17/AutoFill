/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : PBIT global function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "middleware/pbit/pbit_public.h"
#include "middleware/pbit/pbit_private.h"


/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-PBIT-0010 */
/* Implements REQ_FADEX_OS_SRD-PBIT-0020 */
/* Implements REQ_FADEX_OS_SRD-PBIT-0030 */
/* PBIT tests function */
void pbit(const boolean_t ch_is_a)
{
   /* Execution of EBI test of external SRAM */
   pbit_ebi_ext_sram();

   /* Execution of external MRAM test */
   pbit_ext_mram();

   /* Execution of PLD configuration check test */
   pbit_pld_config(ch_is_a);

}

/* ---------- internal operations: ------------------------------------------ */
