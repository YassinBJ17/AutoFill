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
void Check_RollOver(const uint32_t /* IN */ fifoRollover,
                    const uint32_t /* IN */ fifoPointerFirst,
                    const uint32_t /* IN */ fifoPointerLast,
                    TE_LIBBSP_UART_RxErrorCode * const /* OUT */ pa_status);

