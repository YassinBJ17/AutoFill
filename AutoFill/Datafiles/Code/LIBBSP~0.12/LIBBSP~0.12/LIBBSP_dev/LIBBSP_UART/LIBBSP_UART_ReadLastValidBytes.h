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
uint32_t read_LastValidBytes(const boolean_t /* IN */ pointerMoved,
                             const uint32_t /* IN */ lastValidBytes,
                             const uint32_t /* IN */ validBytes,
                             const TU_LIBBSP_UART_Register * /* IN */ rxBuffer,
                             uint8_t * /* OUT */ bufferTemp,
                             uint32_t * /* INOUT */ fifoPointerFirst,
                             uint32_t * const /* OUT */ pa_read);

