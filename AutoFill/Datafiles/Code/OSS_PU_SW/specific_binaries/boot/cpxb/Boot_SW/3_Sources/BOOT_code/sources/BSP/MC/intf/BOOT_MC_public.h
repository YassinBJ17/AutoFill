#ifndef BOOT_MC_PUBLIC_H
#define BOOT_MC_PUBLIC_H

/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */


/* ---------- include  ------------------------------------------------------ */
#include "CMN_TYPES_common.h"

/* ---------- external define constants: ------------------------------------ */

#define MC_CCTL_CORE_DIS_VAL (uint16_t)0
#define MC_CCTL_CORE_RUNNING_VAL (uint16_t)0xFE

/*************/
/*    ECC    */
/*************/


/* ---------- external types: ----------------------------------------------- */
/* none */

/* ---------- external operations: ------------------------------------------ */
/* none */

/* ---------- external datas: ----------------------------------------------- */
/*none */

/* ---------- external constants: ------------------------------------------- */
/* none */

/* ---------- provided operations: ------------------------------------------- */
/* none */

extern void BOOT_MC_CHANGE_MODE_INIT( void );

extern void BOOT_MC_MODE_INIT( void );

extern void BOOT_MC_SET_PLL( void ) ;

extern void BOOT_MC_SET_CONF(uint32_t const p_numCore,
                             const void* p_start_addr,
                             te_CMN_FLAG_QUESTION const p_ResetCore,
                             uint16_t const p_cctl );

extern void BOOT_MC_PLLDIG_CLEAR_STATUS( void );
extern void BOOT_MC_RGM_CLEAR_ERROR(void);
extern uint32_t BOOT_MC_GET_SELF_TEST_STATUS(void);

extern void BOOT_MC_BIST_MODE_CHANGE (void);
extern void BOOT_MC_BIST_MODE_INIT(void);
extern void BOOT_MC_BIST_CORE_RST_ADDR(void);
#endif /* BOOT_MC_PUBLIC_H */
