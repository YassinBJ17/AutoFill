/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : <short description of the operations of the .c file>
 * -------------------------------------------------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "libtools/time/LIBT_TIME_private.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- provided datas: ------------------------------------------- */
/* CPSP */
/* TIMER */
/* PIT 1*/
/* >RELAX<SYNCHRONe_C_Code_7.2,SYNCHRONe_C_Code_10.7>: MPC5777M register value of PIT 0. This value is not configurable. No loss of precision, the structure type 'ts_LIBT_PIT_CTRL' is tailor-made for the registers starting at this address */
volatile const ts_LIBT_PIT_CTRL * const LIBT_pit_ctrl = ( (volatile ts_LIBT_PIT_CTRL *) 0xFFF80000 ) ;
/* PIT 0*/
/* volatile ts_LIBT_PIT_CTRL * const LIBT_pit_ctrl = ( (volatile ts_LIBT_PIT_CTRL *) 0xFFF84000 ) ; */


