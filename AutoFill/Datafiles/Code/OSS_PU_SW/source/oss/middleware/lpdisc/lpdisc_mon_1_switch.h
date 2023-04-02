/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef LPDISC_MON_1_SWITCH_H
#define LPDISC_MON_1_SWITCH_H

/* ---------- include required interface: ----------------------------------- */

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- provided operations: ------------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-LPDISC-0070 */
/* Manage FaultWord for LP with one switches (LP 1, 2, 3, 4, 9) */
extern void lpdisc_mon_1_switch(ts_lpdisk_device * p_device,
                                tu_lp_fault_word * p_fault_word);


#endif /* LPDISC_MON_1_SWITCH_H */
