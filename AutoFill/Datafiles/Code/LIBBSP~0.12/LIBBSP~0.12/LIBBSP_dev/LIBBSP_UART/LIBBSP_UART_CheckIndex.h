/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "LIBBSP_UART_Globals.h"

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- provided operations: ------------------------------------------ */
void Check_Index(const uint32_t /* IN */ index,
                 const uint32_t /* IN */ toRead,
                 const uint8_t * /* IN */ bufferTemp,
                 TE_LIBBSP_UART_RxErrorCode * const /* OUT */ pa_status,
                 uint8_t * const /* OUT */ pa_buffer);

