/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef RESET_PUBLIC_H
#define RESET_PUBLIC_H

/* ---------- include required interface: ----------------------------------- */
#include "type/mcp_types.h"


/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */
/* RESET iip address */
#define K_RESET_REG_ADDR                (reg32_t)(0x24048000)

/* ---------- provided types: ----------------------------------------------- */


/* ---------- provided constants: ------------------------------------------- */


/* ---------- provided data: ------------------------------------------------ */

/* ---------- provided operations: ------------------------------------------ */
extern void reset_critical(void);

extern void reset_init(void);

#endif /* End of RESET_PUBLIC_H */
