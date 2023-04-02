/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef BOOT_FCCU_PUBLIC_H
#define BOOT_FCCU_PUBLIC_H

/* ---------- include required interface: ----------------------------------- */
#include "CMN_TYPES_common.h"

/* ---------- Linker command file symbol: ----------------------------------- */


/* ---------- provided define constants: ------------------------------------ */


/* ---------- provided types: ----------------------------------------------- */



/* ---------- provided constants: ------------------------------------------- */


/* ---------- provided data: ------------------------------------------------ */


/* ---------- provided operations: ------------------------------------------ */

extern void BOOT_FCCU_INIT ( void );
extern void BOOT_FCCU_CLEAR_FAULTS ( void );
extern uint32_t BOOT_FCCU_GET_RF_S0 ( void );
extern uint32_t BOOT_FCCU_GET_RF_S1 ( void );
extern void BOOT_FCCU_CHECK_STATUS ( void );

#endif /* BOOT_FCCU_PUBLIC_H */

