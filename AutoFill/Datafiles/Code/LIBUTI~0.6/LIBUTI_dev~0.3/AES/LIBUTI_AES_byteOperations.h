/*----------------------------------------------------------------------------*/
/* File name  : LIBUTI_AES_byteOperations.h
 * CSC name   :
 *
 * Description:
 *
 * Configuration management identification:
 *    %full_name:  sknNEXT#1/incl/LIBUTI_AES_byteOperations.h/2 %
 *    Creation: FT131472            on Thu Mar 25 17:52:32 CET 2021
 *
 * Copyright (c) 2019,
 * Safran Electronics & Defense document. Reproduction and disclosure forbidden.
 *----------------------------------------------------------------------------*/


/* ---------- include required interface: ----------------------------------- */
#include "LIBMCP_Types.h"
/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided macros: ---------------------------------------------- */

/* ---------- provided types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- provided operation: ------------------------------------ */
void AddRoundKey(uint8_t state[4][4], const uint32_t w[4]);
void SubBytes(uint8_t state[4][4]);
void InvSubBytes(uint8_t state[4][4]);
void ShiftRows(uint8_t state[4][4]);
void InvShiftRows(uint8_t state[4][4]);
void MixColumns(uint8_t state[4][4]);
void InvMixColumns(uint8_t state[4][4]);
void xor_buf(const uint8_t in[], uint8_t out[], uint32_t const len);
uint32_t SubWord(uint32_t const word);
