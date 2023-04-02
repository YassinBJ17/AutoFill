/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef HANDLE_EXCEPTION_PUBLIC_H
#define HANDLE_EXCEPTION_PUBLIC_H

/* ---------- include required interface: ----------------------------------- */
#include <asterios.h>

/* ---------- Linker command file symbol: ----------------------------------- */
/* none */

/* ---------- provided define constants: ------------------------------------ */
/* none */

/* ---------- provided types: ----------------------------------------------- */
/* none */

/* ---------- provided constants: ------------------------------------------- */
/* none */

/* ---------- provided data: ------------------------------------------------ */
/* none */

/* ---------- provided operations: ------------------------------------------ */
/* Handle the fault and log the error */
extern void handle_exception(const struct k2_em_error* error);

#endif /* HANDLE_EXCEPTION_PUBLIC_H */
