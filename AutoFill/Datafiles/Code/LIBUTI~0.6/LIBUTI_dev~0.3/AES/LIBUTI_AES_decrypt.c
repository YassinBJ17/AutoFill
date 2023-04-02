/*----------------------------------------------------------------------------*/
/* File name  : LIBUTI_AES_decrypt.c
 * CSC name   :
 *
 * Description:
 *
 * Configuration management identification:
 *    %full_name:  sknNEXT#1/csrc/LIBUTI_AES_decrypt.c/3 %
 *    Creation: FT131472            on Fri Apr  2 18:28:20 CEST 2021
 *
 * Copyright (c) 2019,
 * Safran Electronics & Defense document. Reproduction and disclosure forbidden.
 *----------------------------------------------------------------------------*/



/* ---------- include provided interface: ----------------------------------- */
#include "LIBUTI_AES.h"
/* ---------- include required interface: ----------------------------------- */
#include "Memcpy.h"
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
boolean_t LIBUTI_AES_decrypt(
/*IN*/
	const uint8_t * const in,
	const uint32_t in_len,
	const uint8_t * const key,
	const uint8_t * const IV,
	const TE_LIBUTI_AES_KEY_SIZE keysize,
/*OUT*/
/* {{RELAX<SYNCHRONe_C_Code_8.18> Those parameters are outputs */
	uint8_t * const out,
	uint32_t * const out_length
/* }} RELAX<SYNCHRONe_C_Code_8.18> */
)
{
	uint8_t buf_in[AES_BLOCK_SIZE];
	uint8_t buf_out[AES_BLOCK_SIZE] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	uint8_t iv_buf[AES_BLOCK_SIZE];
	uint32_t key_schedule[64];
	uint32_t blocks, idx, start_position;
	boolean_t ret;
	
	ret = TRUE;
	if (IV == NULL) /* %RELAX<SYNCHRONe_C_Code_10.7> No loss of precision here */
	{
		LibC_Memcpy(iv_buf, in, AES_BLOCK_SIZE);
		start_position = 1ul;
		*out_length = in_len - AES_BLOCK_SIZE;
	}
	else
	{
		LibC_Memcpy(iv_buf, IV, AES_BLOCK_SIZE);
		start_position = 0ul;
		*out_length = in_len;
	}

	if ( (in_len % AES_BLOCK_SIZE) != 0ul)
	{
		ret = FALSE;
	}

	blocks = in_len / AES_BLOCK_SIZE;
	LIBUTI_AES_keySetup(key, key_schedule, (int32_t) keysize);

	for (idx = start_position; idx < blocks; idx++)
	{
		/*{{RELAX<SYNCHRONe_C_Code_17.4> Array indexing used because LibC_Memcpy can't guess the size of memory to copy.*/
		LibC_Memcpy(buf_in, &in[idx * (AES_BLOCK_SIZE)], AES_BLOCK_SIZE);
		LIBUTI_AES_decryptBlock(buf_in, key_schedule, keysize, buf_out);
		xor_buf(iv_buf, buf_out, AES_BLOCK_SIZE);
		LibC_Memcpy(&out[(idx - start_position) * (AES_BLOCK_SIZE)], buf_out, AES_BLOCK_SIZE);
		LibC_Memcpy(iv_buf, buf_in, AES_BLOCK_SIZE);
		/*}}RELAX<SYNCHRONe_C_Code_17.4> */
	}
	*out_length = *out_length - ((uint32_t) buf_out[AES_BLOCK_SIZE - 1ul]);
	return(ret);
}

