/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : mram_init function which allows MRAM initialization.
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/mram/mram_public.h"

/* ---------- include required interface: ----------------------------------- */
#include "memory/lib_critical_service_section_def_data.h" /* Access to shared memory */

/* ---------- internal define constants: ------------------------------------ */
/* Start address in the MRAM of the OSS critical data */
#define OSS_CRITICAL_DATA_START_ADDR      ((ts_mram_oss_critical_data *)0x20004600)

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* Pointer on the OSS critical data in the MRAM */
ts_mram_oss_critical_data  *mram_oss_critical_data;

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Initialize MRAM and check integrity of the OSS PU counters and the registered logbook */
/* Implements REQ_FADEX_OS_SRD-MRAM-0010 */
void mram_init(void)
{
   /* Initialize pointer on MRAM */
   mram_oss_critical_data = (ts_mram_oss_critical_data *)OSS_CRITICAL_DATA_START_ADDR;

   /* Increment the mission identifier by one */
   mram_oss_critical_data->s_mission_id++;

   /* Save in the shared memory the CSS_PU counters from MRAM */
   shmem.s_oss_counter = mram_oss_critical_data->s_oss_pu_counters;

   /* Increase the number of power up in the shared memory */
   shmem.s_oss_counter.s_pw_up_count++;

   /* Restart the number of RTC in the shared memory */
   shmem.s_oss_counter.s_last_power_up_time = (uint32_t)0;
}

/* ---------- internal operations: ------------------------------------------ */
