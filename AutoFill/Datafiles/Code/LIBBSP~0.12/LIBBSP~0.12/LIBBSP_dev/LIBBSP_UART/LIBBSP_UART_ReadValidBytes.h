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
void read_ValidBytes(const uint32_t /* IN */ validBytes,
                     const TU_LIBBSP_UART_Register * /* IN */ rxBuffer,
                     uint32_t * const /* INOUT */ index,
                     uint8_t * const /* OUT */ pa_buffer,
                     uint32_t * const /* OUT */ pa_read);

