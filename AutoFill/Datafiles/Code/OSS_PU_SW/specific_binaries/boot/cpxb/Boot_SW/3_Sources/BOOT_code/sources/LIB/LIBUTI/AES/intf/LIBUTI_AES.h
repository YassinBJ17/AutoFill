/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef _LIBUTI_AES_H_
#define _LIBUTI_AES_H_
/* ---------- DLD symbol ---------------------------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "CMN_TYPES_common.h"
/* ---------- provided define constants: ------------------------------------ */
#define AES_BLOCK_SIZE (uint32_t)16
/* ---------- provided macros: ---------------------------------------------- */

/* ---------- provided types: ----------------------------------------------- */

typedef enum
{
   E_LIBUTI_AES_KEY_SIZE_128 = 128,
   E_LIBUTI_AES_KEY_SIZE_192 = 192,
   E_LIBUTI_AES_KEY_SIZE_256 = 256
}
TE_LIBUTI_AES_KEY_SIZE;

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- provided operations: ------------------------------------------ */
void LIBUTI_AES_decryptBlock( const uint8_t * block, const uint32_t * keySchedule, TE_LIBUTI_AES_KEY_SIZE const keySize, uint8_t * decrypted );
void LIBUTI_AES_keySetup( const uint8_t key[], uint32_t schedule[], const int32_t keysize );
/* Set IV to NULL to read IV from the start of the file */
te_CMN_FLAG_QUESTION LIBUTI_AES_decrypt(
/*IN*/
   const uint8_t * const in,
   const uint32_t in_len,
   const uint8_t * const key,
   const uint8_t * const IV,
   const TE_LIBUTI_AES_KEY_SIZE keysize,
/*OUT*/
    uint8_t * const out,
    uint32_t * const out_length
);
/* Read IV from the start of the file, and decyphers the file in the same memory zone */
te_CMN_FLAG_QUESTION LIBUTI_AES_decrypt_in_place(
/*IN/OUT*/
   uint8_t * const encrypted, /* %RELAX<SYNCHRONe_C_Code_8.18> Parameter is input/output */
/*IN*/
   const uint32_t dataLength,
   const uint8_t * const key,
   const TE_LIBUTI_AES_KEY_SIZE keySize,
/*OUT*/
/* {{RELAX<SYNCHRONe_C_Code_8.18> Those parameters are outputs */
   uint32_t * const decrypted_length
/* }} RELAX<SYNCHRONe_C_Code_8.18> */
);
#endif /* _LIBUTI_AES_H_ */
