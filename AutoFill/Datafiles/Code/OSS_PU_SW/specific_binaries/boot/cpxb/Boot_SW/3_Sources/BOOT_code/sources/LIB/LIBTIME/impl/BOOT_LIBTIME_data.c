/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : PIT register
 * -------------------------------------------------------------------------- */


/* ---------- include required interface: ----------------------------------- */
#include "BOOT_LIBTIME_private.h"

/* ---------- internal define constants: ------------------------------------ */
/* none */

/* ---------- provided datas: ------------------------------------------- */
/* CPSP */
/* TIMER */
/* PIT 1*/
/* >RELAX<SYNCHRONe_C_Code_7.2> MPC5777M register value of PIT 0. This value is not configurable. */
volatile ts_LIBT_PIT_CTRL * const LIBT_pit_ctrl = ( (volatile ts_LIBT_PIT_CTRL *) 0xFFF80000 ) ;
/* PIT 0*/
/* volatile ts_LIBT_PIT_CTRL * const LIBT_pit_ctrl = ( (volatile ts_LIBT_PIT_CTRL *) 0xFFF84000 ) ; */


