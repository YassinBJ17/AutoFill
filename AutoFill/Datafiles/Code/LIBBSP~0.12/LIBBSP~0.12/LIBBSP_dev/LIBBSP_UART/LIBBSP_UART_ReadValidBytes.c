/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : short description of the operations of the .c file
 * -------------------------------------------------------------------------- */

/* ---------- include interface: ----------------------------------- */
#include "LIBBSP_UART_ReadValidBytes.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ.MY_REQID-LLR_001 */ //TODO trouver la REQ/LLR
void read_ValidBytes(const uint32_t /* IN */ validBytes,
                     const TU_LIBBSP_UART_Register * /* IN */ rxBuffer,
                     uint32_t * const /* INOUT */ index,
                     uint8_t * const /* OUT */ pa_buffer,
                     uint32_t * const /* OUT */ pa_read)
{
   uint32_t temporary_value ;

   switch (validBytes)
   {
   /* {{RELAX<SYNCHRONe_C_Code_10.7, SYNCHRONe_C_Code_11.1, SYNCHRONe_C_Code_17.4> use pointer for array indexing and convert it, because we dont know buffer size and only 8 bits of the uint32 value is taken */
   case 1:
      temporary_value = rxBuffer->R;
      pa_buffer[(*index)] = ((uint8_t*)&temporary_value) [3];
      *pa_read = *pa_read + 1ul;
      break;
   case 2:
      temporary_value = rxBuffer->R;
      pa_buffer[(*index)++] = ((uint8_t*)&temporary_value) [3];
      pa_buffer[(*index)] = ((uint8_t*)&temporary_value) [2];
      *pa_read = *pa_read + 2ul;
      break;
   case 3:
      temporary_value = rxBuffer->R;
      pa_buffer[(*index)++] = ((uint8_t*)&temporary_value) [3];
      pa_buffer[(*index)++] = ((uint8_t*)&temporary_value) [2];
      pa_buffer[(*index)] = ((uint8_t*)&temporary_value) [1];
      *pa_read = *pa_read + 3ul;
      break;
   default:
      break;
   /* }} RELAX<SYNCHRONe_C_Code_10.7, SYNCHRONe_C_Code_11.1, SYNCHRONe_C_Code_17.4> */
   }
}

