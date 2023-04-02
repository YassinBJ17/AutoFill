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
void Check_UART(const TE_LIBBSP_UART_Dev /* IN */ devID,
                const uint32_t /* IN */ fifoPointerLast,
                const uint32_t /* IN */ validBytes,
                const boolean_t /* IN */ par,
                const boolean_t /* IN */ stop,
                TE_LIBBSP_UART_RxErrorCode * const /* INOUT */ pa_status,
                uint32_t * const /* OUT */ pa_read);

