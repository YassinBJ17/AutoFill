/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : mram_reset function which allows MRAM management before reset
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/mram/mram_public.h"

/* ---------- include required interface: ----------------------------------- */
#include "memory/lib_critical_service_section_def_data.h" /* Access to shared memory */

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* MRAM management before power-down or reset */
/* Implements REQ_FADEX_OS_SRD-MRAM-0030 */
void mram_reset(void)
{
   /* Save OSS PU counters in MRAM */
   mram_oss_critical_data->s_oss_pu_counters = shmem.s_oss_counter;
}

/* ---------- internal operations: ------------------------------------------ */
