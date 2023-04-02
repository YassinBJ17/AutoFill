/*----------------------------------------------------------------------------*/
/* File name  : LIBUTI_AES_decryptBlock.c
 * CSC name   :
 *
 * Description:
 *
 * Configuration management identification:
 *    %full_name:  sknNEXT#1/csrc/LIBUTI_AES_decryptBlock.c/4 %
 *    Creation: FT131472            on Thu Mar 25 17:52:35 CET 2021
 *
 * Copyright (c) 2019,
 * Safran Electronics & Defense document. Reproduction and disclosure forbidden.
 *----------------------------------------------------------------------------*/



/* ---------- include provided interface: ----------------------------------- */
#include "LIBUTI_AES.h"
/* ---------- include required interface: ----------------------------------- */
#include "LIBUTI_AES_byteOperations.h"
/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal macros: ---------------------------------------------- */
/*#define KE_ROTWORD(x) (((x) << 8) | ((x) >> 24))*/

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal operation bodies: ------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
void LIBUTI_AES_decryptBlock(const uint8_t *block, const uint32_t *key, TE_LIBUTI_AES_KEY_SIZE const keySize, uint8_t *decrypted)
{
	uint8_t state[4][4];
	/*{{RELAX<SYNCHRONe_C_Code_17.4> Array indexing used on pointer because used as buffer. Array not used because we don't now the size.*/
	/* Copy the input to the state. */
	state[0][0] = block[0];
	state[1][0] = block[1];
	state[2][0] = block[2];
	state[3][0] = block[3];
	state[0][1] = block[4];
	state[1][1] = block[5];
	state[2][1] = block[6];
	state[3][1] = block[7];
	state[0][2] = block[8];
	state[1][2] = block[9];
	state[2][2] = block[10];
	state[3][2] = block[11];
	state[0][3] = block[12];
	state[1][3] = block[13];
	state[2][3] = block[14];
	state[3][3] = block[15];

	/* Perform the necessary number of rounds. The round key is added first. */
	/* The last round does not perform the MixColumns step. */
	if (keySize > E_LIBUTI_AES_KEY_SIZE_128) 
	{
		if (keySize > E_LIBUTI_AES_KEY_SIZE_192) 
		{
			AddRoundKey(state,&key[56]);
			InvShiftRows(state);
			InvSubBytes(state);
			AddRoundKey(state,&key[52]);
			InvMixColumns(state);
			InvShiftRows(state);
			InvSubBytes(state);
			AddRoundKey(state,&key[48]);
			InvMixColumns(state);
		}
		else 
		{
			AddRoundKey(state,&key[48]);
		}
		InvShiftRows(state);
		InvSubBytes(state);
		AddRoundKey(state,&key[44]);
		InvMixColumns(state);
		InvShiftRows(state);
		InvSubBytes(state);
		AddRoundKey(state,&key[40]);
		InvMixColumns(state);
	}
	else 
	{
		AddRoundKey(state,&key[40]);
	}
	InvShiftRows(state);
	InvSubBytes(state);
	AddRoundKey(state,&key[36]);
	InvMixColumns(state);
	InvShiftRows(state);
	InvSubBytes(state);
	AddRoundKey(state,&key[32]);
	InvMixColumns(state);
	InvShiftRows(state);
	InvSubBytes(state);
	AddRoundKey(state,&key[28]);
	InvMixColumns(state);
	InvShiftRows(state);
	InvSubBytes(state);
	AddRoundKey(state,&key[24]);
	InvMixColumns(state);
	InvShiftRows(state);
	InvSubBytes(state);
	AddRoundKey(state,&key[20]);
	InvMixColumns(state);
	InvShiftRows(state);
	InvSubBytes(state);
	AddRoundKey(state,&key[16]);
	InvMixColumns(state);
	InvShiftRows(state);
	InvSubBytes(state);
	AddRoundKey(state,&key[12]);
	InvMixColumns(state);
	InvShiftRows(state);
	InvSubBytes(state);
	AddRoundKey(state,&key[8]);
	InvMixColumns(state);
	InvShiftRows(state);
	InvSubBytes(state);
	AddRoundKey(state,&key[4]);
	InvMixColumns(state);
	InvShiftRows(state);
	InvSubBytes(state);
	AddRoundKey(state,&key[0]);

	/* Copy the state to the output array. */
	decrypted[0] = state[0][0];
	decrypted[1] = state[1][0];
	decrypted[2] = state[2][0];
	decrypted[3] = state[3][0];
	decrypted[4] = state[0][1];
	decrypted[5] = state[1][1];
	decrypted[6] = state[2][1];
	decrypted[7] = state[3][1];
	decrypted[8] = state[0][2];
	decrypted[9] = state[1][2];
	decrypted[10] = state[2][2];
	decrypted[11] = state[3][2];
	decrypted[12] = state[0][3];
	decrypted[13] = state[1][3];
	decrypted[14] = state[2][3];
	decrypted[15] = state[3][3];
	/*}}RELAX<SYNCHRONe_C_Code_17.4> */
}

void LIBUTI_AES_keySetup(const uint8_t key[], uint32_t schedule[], const int32_t keysize) /* %RELAX<SYNCHRONe_C_Code_8.12> The size of the arrays are not known at this point */
{
	int32_t Nb,Nr,Nk,idx;
	uint32_t temp;
	const uint32_t Rcon[]={0x01000000,0x02000000,0x04000000,0x08000000,0x10000000,0x20000000,
	                  0x40000000,0x80000000,0x1b000000,0x36000000,0x6c000000,0xd8000000,
	                  0xab000000,0x4d000000,0x9a000000};
	Nb = 4l;
	switch (keysize)
	{
		case 128: 
		   Nr = 10l;
		   Nk = 4l;
		   break;
		case 192:
		   Nr = 12l;
		   Nk = 6l;
		   break;
		case 256:
		   Nr = 14l;
		   Nk = 8l;
		   break;
		default:
		   return;
		   break;
	}

	for (idx=0l; idx < Nk; ++idx) /* %RELAX<SYNCHRONe_C_Code_9.1> Nk always has a value here */
	{
		schedule[idx] = ( (((uint32_t) key[4l * idx]) << 24) | (((uint32_t) key[(4l * idx) + 1l]) << 16) |
				   (((uint32_t) key[(4l * idx) + 2l]) << 8) | ((uint32_t) (key[(4l * idx) + 3l])) );
	}

	for (idx = Nk; idx < Nb * (Nr + 1l); ++idx)  /* %RELAX<SYNCHRONe_C_Code_9.1> Nr always has a value here */
	{
		temp = schedule[idx - 1l];
		if ((idx % Nk) == 0l)
		{
			temp = SubWord(((temp) << 8) | ((temp) >> 24)) ^ Rcon[(idx-1l)/Nk]; 
		}
		else if (Nk > 6l && (idx % Nk) == 4l)
		{
			temp = SubWord(temp);
		}
		schedule[idx] = schedule[idx-Nk] ^ temp;
	}
}
