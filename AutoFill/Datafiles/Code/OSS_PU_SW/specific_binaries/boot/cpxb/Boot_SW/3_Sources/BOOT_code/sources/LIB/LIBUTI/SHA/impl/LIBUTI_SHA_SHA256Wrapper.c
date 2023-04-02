/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "LIBUTI_SHA.h"
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

void LIBUTI_SHA_ComputeSHA256( const uint8_t * const File, const uint32_t Length, ts_LIBUTI_SHA_SHA256 * const ComputedHash ) /* %RELAX<SYNCHRONe_C_Code_8.18> ComputedHash is output */
{
   ts_LIBUTI_SHA_SHA256_ctx context;
   uint32_t pos;
   uint32_t bufsize;

   LIBUTI_SHA_initSHA256( &context );

   for( pos = (uint32_t)0; pos < Length; pos += K_CHUNK_SIZE )
   {
      bufsize = Length - pos < K_CHUNK_SIZE? Length - pos : K_CHUNK_SIZE;
      LIBUTI_SHA_updateSHA256( &context, File + pos, bufsize ); /* %RELAX<SYNCHRONe_C_Code_17.4> File + pos is calculated to determined the adresse of each chunk in the file */
   }

   LIBUTI_SHA_finalSHA256( &context, ComputedHash );
}
