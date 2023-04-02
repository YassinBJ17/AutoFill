/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : 
 *
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "BOOT_PBIT_private.h"

/* ---------- include required interface: ----------------------------------- */

/* ---------- internal define constants: ------------------------------------ */
#define CHECK_CRC32_LENGTH 4

/* ---------- internal macros: ---------------------------------------------- */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal operation bodies: ------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */

te_CMN_FLAG_QUESTION BOOT_PBIT_ComputeCRC32(

   /* InputOutput(s) parameter(s) */
   TS_FileInfo * const                          p_FileInfo,

   /* Output(s) parameter(s) */
   TS_LoadStatus *                              p_LoadStatus
)
{
/* Declaration of local variables ------------------------------------------- */
   te_CMN_FLAG_QUESTION    ret;
   uint32_t                CRC32_Buffer;

/* Initialized local variables ---------------------------------------------- */
   ret = e_CMN_FLAG_NO;

/* Function body ------------------------------------------------------------ */

   /*Layer protocol format CRC32-B check*/
   BOOT_LIBCHK_CRC32_COMPUTE( 
      p_FileInfo->Address, 
      p_FileInfo->ARINC_665_FileInfo->Length,
      &CRC32_Buffer );

   p_LoadStatus->Corrupted = BOOT_LIBMEM_NOTEQUAL(
                              (uint8_t*)&CRC32_Buffer,
                              p_FileInfo->ARINC_665_FileInfo->CheckValue,
                              (uint32_t)CHECK_CRC32_LENGTH);
   ret = e_CMN_FLAG_YES;

   return ( ret );
}
