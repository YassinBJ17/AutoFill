#ifndef BOOT_RESET_PUBLIC_H
#define BOOT_RESET_PUBLIC_H

/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */


/* ---------- include  ------------------------------------------------------ */
#include "CMN_TYPES_common.h"

/* ---------- external define constants: ------------------------------------ */
/* none */

/* ---------- external types: ----------------------------------------------- */

typedef struct
{
   uint32_t    s_MSR_val ;
   uint32_t    s_HID0_val ;
   uint32_t    s_HID1_val ;
   uint32_t    s_stack_init ;
   uint32_t    s_stack_sda2_init ;
   uint32_t    s_stack_sda_init ;
   CMN_SYSTEM_ADDR_VAL_t s_exception_table_addr ;
} ts_RESET_MAPPING;
/* ---------- external data ------------------------------------------- */
extern const ts_RESET_MAPPING CORE_0_MAPPING ;
extern const ts_RESET_MAPPING CORE_1_MAPPING ;
extern const ts_RESET_MAPPING CORE_2_MAPPING ;
/* none */
extern const uint32_t _BOOT_SDA2_BASE_ ;

/* ---------- external constants: ------------------------------------------- */
/* none */

/* ---------- provided operations: ------------------------------------------- */

extern void BOOT_RESET_PLATFORM( void );
extern void BOOT_RESET_CORE_0( void ) ;
extern void BOOT_RESET_CORE_1( void ) ;
extern void BOOT_RESET_CORE_2( void ) ;
extern void BOOT_RESET_SET_SPEFSCR ( uint32_t const p_value);
extern void BOOT_RESET_SET_USER_MODE ( void);
extern void BOOT_RESET_SET_SUPERVISOR_MODE (void);
extern void BOOT_RESET_CLEAR_MCSR(void);
#endif /* BOOT_RESET_PUBLIC_H */
