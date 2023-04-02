/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef LIB_CRITICAL_SERVICE_SECTION_DEF_DATA_H
#define LIB_CRITICAL_SERVICE_SECTION_DEF_DATA_H

/* ---------- include required interface: ----------------------------------- */
#include "type/mcp_types.h"
#include "memory/shared_memory_public.h"
#include "memory/memory_address_public.h"

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* Shared memory */
/* >RELAX<SYNCHRONe_C_Code_8.15> justification */
/* >RELAX<SYNCHRONe_C_Code_8.17> justification */
extern ts_shmem shmem;

/* Critical services pointers area */
extern const uint32_t critical_services_pointers_area[CRITICAL_SERVICES_POINTERS_AREA_SIZE];

/* ---------- provided operations: ------------------------------------------ */

#endif /* LIB_CRITICAL_SERVICE_SECTION_DEF_DATA_H */

