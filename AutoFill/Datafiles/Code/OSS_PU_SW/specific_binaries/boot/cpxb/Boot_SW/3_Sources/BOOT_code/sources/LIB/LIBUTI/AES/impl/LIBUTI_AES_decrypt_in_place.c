/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "LIBUTI_AES.h"
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
)
{
   te_CMN_FLAG_QUESTION status;
	
   /*{{RELAX<SYNCHRONe_C_Code_17.4>*/
   /* LIBUTI_AES_decrypt function can't guess the size of the encrypted block to decrypt.*/
   /* So, it's not possible to used fixed Array. Solution is kept*/
   status = LIBUTI_AES_decrypt( &encrypted[AES_BLOCK_SIZE], dataLength - AES_BLOCK_SIZE, key, encrypted, keySize, encrypted, decrypted_length );
   /*}}RELAX<SYNCHRONe_C_Code_17.4> */
	
   return ( status );
}