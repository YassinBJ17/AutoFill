/* ---------- include required interface: ----------------------------------- */
#include "CMN_TYPES_common.h"
/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided macros: ---------------------------------------------- */

/* ---------- provided types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- provided operation: ------------------------------------ */
void AddRoundKey( uint8_t state[][4], const uint32_t w[] );
void SubBytes( uint8_t state[][4] );
void InvSubBytes( uint8_t state[][4] );
void ShiftRows( uint8_t state[][4] );
void InvShiftRows( uint8_t state[][4] );
void MixColumns( uint8_t state[][4] );
void InvMixColumns( uint8_t state[][4] );
void xor_buf( const uint8_t in[], uint8_t out[], uint32_t len );
uint32_t SubWord( uint32_t word );
