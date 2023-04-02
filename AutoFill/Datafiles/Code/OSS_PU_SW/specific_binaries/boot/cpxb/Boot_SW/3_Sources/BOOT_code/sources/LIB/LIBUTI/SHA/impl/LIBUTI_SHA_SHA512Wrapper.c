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

void LIBUTI_SHA_ComputeSHA512(
   /* IN */
   const uint8_t * const File,
   const uint32_t Length,
   /* OUT */
   ts_LIBUTI_SHA_SHA512 * const ComputedHash
) /* %RELAX<SYNCHRONe_C_Code_8.18> ComputedHash is output */
{

   ts_LIBUTI_SHA_SHA512_ctx context;

   LIBUTI_SHA_initSHA512( &context );

   LIBUTI_SHA_updateSHA512( &context, File, Length ); /* %RELAX<SYNCHRONe_C_Code_17.4> File + pos is calculated to determined the adresse of each chunk in the file */

   LIBUTI_SHA_finalSHA512( &context, ComputedHash );

}
