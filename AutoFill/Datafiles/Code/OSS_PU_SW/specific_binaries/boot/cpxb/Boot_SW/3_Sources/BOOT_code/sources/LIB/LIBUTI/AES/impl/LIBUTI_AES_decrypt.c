/* ---------- include provided interface: ----------------------------------- */
#include "LIBUTI_AES.h"
/* ---------- include required interface: ----------------------------------- */
#include "BOOT_LIBMEM_public.h"
#include "LIBUTI_AES_byteOperations.h"
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
te_CMN_FLAG_QUESTION LIBUTI_AES_decrypt( const uint8_t * in, const uint32_t in_len, const uint8_t * key, const uint8_t * IV, 
                                         const TE_LIBUTI_AES_KEY_SIZE keysize, uint8_t * out, uint32_t * out_length )
{
   uint8_t buf_in[AES_BLOCK_SIZE];
   uint8_t buf_out[AES_BLOCK_SIZE];
   uint8_t iv_buf[AES_BLOCK_SIZE];
   uint32_t key_schedule[64];
   int32_t blocks, idx, ret, start_position;

   ret = e_CMN_FLAG_YES;
   if ( IV == NULL )
   {
      BOOT_LIBMEM_CPY( iv_buf, in, AES_BLOCK_SIZE );
      start_position = 1;
      *out_length = in_len - AES_BLOCK_SIZE;
   }
   else
   {
      BOOT_LIBMEM_CPY( iv_buf, IV, AES_BLOCK_SIZE );
      start_position = 0;
      *out_length = in_len;
   }

   if ( ( in_len % AES_BLOCK_SIZE ) != 0 )
   {
      ret = e_CMN_FLAG_NO;
   }

   blocks = in_len / AES_BLOCK_SIZE;
   LIBUTI_AES_keySetup( key, key_schedule, (uint32_t) keysize );

   for ( idx = start_position; idx < blocks; idx++ )
   {
      BOOT_LIBMEM_CPY(buf_in, &in[idx * AES_BLOCK_SIZE], AES_BLOCK_SIZE);
      LIBUTI_AES_decryptBlock(buf_in, key_schedule, (uint32_t) keysize, buf_out);
      xor_buf(iv_buf, buf_out, AES_BLOCK_SIZE);
      BOOT_LIBMEM_CPY(&out[(idx - start_position) * AES_BLOCK_SIZE], buf_out, AES_BLOCK_SIZE);
      BOOT_LIBMEM_CPY(iv_buf, buf_in, AES_BLOCK_SIZE);
   }
   *out_length = *out_length - buf_out[AES_BLOCK_SIZE - 1];
   return ( ret );
}

te_CMN_FLAG_QUESTION LIBUTI_AES_decrypt_in_place( uint8_t * encrypted, const uint32_t dataLength, const uint8_t * key, 
                                                  const TE_LIBUTI_AES_KEY_SIZE keySize, uint32_t * decrypted_length )
{
   te_CMN_FLAG_QUESTION status;
   status = LIBUTI_AES_decrypt( &encrypted[AES_BLOCK_SIZE], dataLength - AES_BLOCK_SIZE, 
                                key, encrypted, keySize, encrypted, decrypted_length );
   return ( status );
}
