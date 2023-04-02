/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Definition of the global initialization function for OSS
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "type/mcp_types.h"
#include "cartridge/cartridge_public.h"
#include "libtools/memory/LIB_MEM_public.h"

/* ---------- include required interface: ----------------------------------- */

/* ---------- internal define constants: ------------------------------------ */
/* Size of compilation date and time strings (in bytes) */
#define COMPIL_INFO_SIZE (uint32_t)32

/* Version of OSS */
#define OSS_VERSION (int8_t*)"FADEX_PREBLUE_OSS_00.04.07-----"

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */
/* Date of compilation */
/* >RELAX<SYNCHRONe_C_Code_8.15> The C language can't make array address constant. */
int8_t compilation_date[COMPIL_INFO_SIZE];

/* Time of compilation */
/* >RELAX<SYNCHRONe_C_Code_8.15> The C language can't make array address constant. */
int8_t compilation_time[COMPIL_INFO_SIZE];

/* OSS version */
/* >RELAX<SYNCHRONe_C_Code_8.15> The C language can't make array address constant. */
int8_t oss_version[COMPIL_INFO_SIZE];

/* ---------- provided operation bodies: ------------------------------------ */
/* Initialize the cartridge in the memory */
void cartridge_init(void)
{
   /* Copy the current date (of compilation) in the table */
   /* >RELAX<SYNCHRONe_C_Code_11.1> The pointed data size are the same. */
   LIB_MEM_CPY((int8_t*)compilation_date, (int8_t*)__DATE__, COMPIL_INFO_SIZE);

   /* Copy the current time (of compilation) in the table */
   /* >RELAX<SYNCHRONe_C_Code_11.1> The pointed data size are the same. */
   LIB_MEM_CPY((int8_t*)compilation_time, (int8_t*)__TIME__, COMPIL_INFO_SIZE);

   /* Copy the version of OSS in the table */
   /* >RELAX<SYNCHRONe_C_Code_11.1> The pointed data size are the same. */
   LIB_MEM_CPY((int8_t*)oss_version, OSS_VERSION, COMPIL_INFO_SIZE);

   return;
}

/* ---------- internal operations: ------------------------------------------ */
