/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef MRAM_PUBLIC_H
#define MRAM_PUBLIC_H

/* ---------- include required interface: ----------------------------------- */
#include "type/mcp_types.h"
#include "memory/shared_memory_public.h"

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */
#define MRAM_CRITICAL_DATA_SPARE_NB ((uint32_t)36)

/* ---------- provided types: ----------------------------------------------- */
/* OSS critical data structure in MRAM */
typedef struct
{
   ts_oss_counter s_oss_pu_counters;

   uint8_t        s_spare[MRAM_CRITICAL_DATA_SPARE_NB];

   uint32_t       s_dld_request;
   uint32_t       s_intrusive_test_request;
   uint32_t       s_intrusive_test_step;

   uint32_t       s_mission_id;
}
ts_mram_oss_critical_data;

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* Pointer on the OSS critical data in the MRAM */
extern ts_mram_oss_critical_data  *mram_oss_critical_data;

/* ---------- provided operations: ------------------------------------------ */
/* Initialize MRAM and check integrity of the data */
/* Implements REQ_FADEX_OS_SRD-MRAM-0010 */
void mram_init(void);

/* Data-loading request management, thermal wear counter computation and direct access services */
/* Implements REQ_FADEX_OS_SRD-MRAM-0020 */
/* Implements REQ_FADEX_OS_SRD-MRAM-0040 */
/* Implements REQ_FADEX_OS_SRD-MRAM-0050 */
void mram_periodic(const boolean_t p_channel_is_a);

/* MRAM management before power-down or reset */
/* Implements REQ_FADEX_OS_SRD-MRAM-0030 */
void mram_reset(void);

#endif /* MRAM_PUBLIC_H */
