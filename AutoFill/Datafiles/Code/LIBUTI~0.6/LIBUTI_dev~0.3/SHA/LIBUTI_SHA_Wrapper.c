/*----------------------------------------------------------------------------*/
/* File name  : LIBUTI_SHA_Wrapper.c
 * CSC name   : LIBUTI_SHA
 *
 * Description:
 *
 * Configuration management identification:
 *    %full_name:  sknNEXT#1/csrc/LIBUTI_SHA_Wrapper.c/4 %
 *    Creation: Separated from LIBUTI_SHA_compute.c on 04-02-2021
 *
 * Copyright (c) 2019,
 * Safran Electronics & Defense document. Reproduction and disclosure forbidden.
 *----------------------------------------------------------------------------*/



/* ---------- include provided interface: ----------------------------------- */
#include "LIBUTI_SHA.h"
/* ---------- include required interface: ----------------------------------- */

/* ---------- internal define constants: ------------------------------------ */
#define C_CHUNK_SIZE (uint32_t) 2048

/* ---------- internal macros: ---------------------------------------------- */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal operation bodies: ------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */

void LIBUTI_SHA_ComputeSHA256(const uint8_t * const File, const uint32_t Length, ts_LIBUTI_SHA_SHA256 * const ComputedHash) /* %RELAX<SYNCHRONe_C_Code_8.18> ComputedHash is output */
{
   ts_LIBUTI_SHA_SHA256_ctx context;
   uint32_t pos;
   uint32_t bufsize;
   LIBUTI_SHA_initSHA256(&context);

   for(pos = (uint32_t) 0; pos < Length; pos += C_CHUNK_SIZE)
   {
      bufsize = Length - pos < C_CHUNK_SIZE? Length - pos : C_CHUNK_SIZE;
      LIBUTI_SHA_updateSHA256(&context, File + pos, bufsize); /* %RELAX<SYNCHRONe_C_Code_17.4> File + pos is calculated to determined the adresse of each chunk in the file */
   }
   LIBUTI_SHA_finalSHA256(&context, ComputedHash);
}
