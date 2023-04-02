/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : short description of the operations of the .c file
 * -------------------------------------------------------------------------- */

/* ---------- include interface: ----------------------------------- */
#include "LIBBSP_UART_CheckIndex.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ.MY_REQID-LLR_001 */ //TODO trouver la REQ/LLR
void Check_Index(const uint32_t /* IN */ index,
                 const uint32_t /* IN */ toRead,
                 const uint8_t * /* IN */ bufferTemp,
                 TE_LIBBSP_UART_RxErrorCode * const /* OUT */ pa_status,
                 uint8_t * const /* OUT */ pa_buffer)
{
   uint32_t v_i;

   if ( index > toRead)
   {
      *pa_status = E_LIBBSP_UART_RX_OVERFLOW_ERROR;
   }
   else
   {
      for ( v_i = 0ul; v_i < index ; v_i ++ )
      {
         pa_buffer[v_i] = bufferTemp[v_i]; /* %RELAX<SYNCHRONe_C_Code_17.4> array indexing with a "for" */
      }
   }
}

