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

/* ---------- internal macros: ---------------------------------------------- */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal operation bodies: ------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */

te_CMN_FLAG_QUESTION BOOT_PBIT_ComputeHash(
   /* Input(s) parameter(s) */
   const TE_LIBUTI_SIF_check_algorithm * const  p_SIF_hash_algo,

   /* InputOutput(s) parameter(s) */
   TS_FileInfo * const                          p_FileInfo,

   /* Output(s) parameter(s) */
   TS_LoadStatus *                              p_LoadStatus
)
{
/* Declaration of local variables ------------------------------------------- */
   te_CMN_FLAG_QUESTION    ret;
   tu_LIBUTI_SIF_hash      Hash_Buffer;

/* Initialized local variables ---------------------------------------------- */
   ret = e_CMN_FLAG_NO;

/* Function body ------------------------------------------------------------ */

   switch ( *p_SIF_hash_algo )
   {
      case E_LIBUTI_SIF_CHECK_ALGORITHM_SHA2_256:
         /*Layer protocol format SHA2-256 check*/
         LIBUTI_SHA_ComputeSHA256(
                  p_FileInfo->Address,
                  p_FileInfo->ARINC_665_FileInfo->Length,
                  &Hash_Buffer.sha256 );

         p_LoadStatus->Corrupted = BOOT_LIBMEM_NOTEQUAL(
                                      (uint8_t*)&Hash_Buffer.sha256,
                                      p_FileInfo->ExpectedSHA256,
                                      (uint32_t)32 );
         ret = e_CMN_FLAG_YES;
      break;

      case E_LIBUTI_SIF_CHECK_ALGORITHM_SHA2_512:
         /*Layer protocol format SHA2-512 check*/
         LIBUTI_SHA_ComputeSHA512(
                  p_FileInfo->Address,
                  p_FileInfo->ARINC_665_FileInfo->Length,
                  &Hash_Buffer.sha512 );

         p_LoadStatus->Corrupted = BOOT_LIBMEM_NOTEQUAL(
                                      (uint8_t*)&Hash_Buffer.sha512,
                                      p_FileInfo->ExpectedSHA512,
                                      (uint32_t)64 );
         ret = e_CMN_FLAG_YES;
      break;

      default:
         /* unsupported algo */
         p_LoadStatus->Corrupted = e_CMN_FLAG_YES;
      break;
   }

   return ( ret );
}
