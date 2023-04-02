/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : short description of the operations of the .c file
 * -------------------------------------------------------------------------- */

/* ---------- include interface: ----------------------------------- */
#include "LIBBSP_UART_ReadLastValidBytes.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ.MY_REQID-LLR_001 */ //TODO trouver la REQ/LLR
uint32_t read_LastValidBytes(const boolean_t /* IN */ pointerMoved,
                             const uint32_t /* IN */ lastValidBytes,
                             const uint32_t /* IN */ validBytes,
                             const TU_LIBBSP_UART_Register * /* IN */ rxBuffer,
                             uint8_t * /* OUT */ bufferTemp,
                             uint32_t * /* INOUT */ fifoPointerFirst,
                             uint32_t * const /* OUT */ pa_read)
{
   uint32_t v_temporary_value;
   uint32_t v_i;
   uint32_t v_i_max;
   uint32_t v_j;
   uint32_t v_ret = 0ul; /* v_index */

   /* verification if the pointers has moved */
   /* {{RELAX<SYNCHRONe_C_Code_10.7, SYNCHRONe_C_Code_11.1, SYNCHRONe_C_Code_17.4> use pointer for array indexing and convert it, because we dont know buffer size and only 8 bits of the uint32 value is taken */
   if ( pointerMoved )
   {
      /* read all the word */
      switch (lastValidBytes)
      {
      case 1:
         v_temporary_value = (rxBuffer[*fifoPointerFirst].R);
         bufferTemp[v_ret++] = ((uint8_t*)&v_temporary_value) [2];
         bufferTemp[v_ret++] = ((uint8_t*)&v_temporary_value) [1];
         bufferTemp[v_ret++] = ((uint8_t*)&v_temporary_value) [0];
         *pa_read += 3ul;
         break;
      case 2:
         v_temporary_value = rxBuffer[*fifoPointerFirst].R;
         bufferTemp[v_ret++] = ((uint8_t*)&v_temporary_value) [1];
         bufferTemp[v_ret++] = ((uint8_t*)&v_temporary_value) [0];
         *pa_read += 2ul;
         break;
      case 3:
         v_temporary_value = rxBuffer[*fifoPointerFirst].R;
         bufferTemp[v_ret++] = ((uint8_t*)&v_temporary_value) [0];
         *pa_read += 1ul;
         break;
      default:
         break;
      }
      *fifoPointerFirst = (*fifoPointerFirst + 1ul) % 512ul;
   }
   else
   {
      v_i_max = validBytes-lastValidBytes;
      v_temporary_value = rxBuffer[*fifoPointerFirst].R;
      for ( v_i = 0ul; v_i < v_i_max; v_i ++ )
      {
         v_j = 3ul - lastValidBytes - v_i;
         bufferTemp[v_ret++] = ((uint8_t*)&v_temporary_value) [v_j];
         *pa_read += 1ul;
      }
   }
   /* }} RELAX<SYNCHRONe_C_Code_10.7, SYNCHRONe_C_Code_11.1, SYNCHRONe_C_Code_17.4> */

   return v_ret;
}

