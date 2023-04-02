#ifndef BOOT_MAIN_PRIVATE_H
#define BOOT_MAIN_PRIVATE_H

/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

/* ---------- include required interface: ----------------------------------- */
/* LPOS Common Interface */
#include "CMN_TYPES_common.h"
#include "BOOT_RESET_public.h"

/* ---------- internal types: ----------------------------------------------- */
/* none */

/* ---------- provided constants: ------------------------------------------- */
/* none */

/* ---------- provided data: ------------------------------------------------ */
/* none */

/* ---------- provided operations: ------------------------------------------ */
/* */
extern void BOOT_MAIN_INIT(void);

/* */
extern void BOOT_MAIN_ENTRYPOINT_INIT( void );

/* */
extern void BOOT_MAIN_PERIPH_INIT( void );
extern void BOOT_MAIN_PERIPH_SHORT_INIT( void );
/* */
extern void BOOT_MAIN_LAUNCH_SOFTWARE( CMN_SYSTEM_ADDR_t p_soft_addr);

extern void BOOT_MAIN_SET_ASTERIOS_INPUT( uint32_t const p_astekconf_idx);
extern uint32_t BOOT_MAIN_SELECT_ASTEKCONF ( void );

#endif /* BOOT_MAIN_PRIVATE_H */
