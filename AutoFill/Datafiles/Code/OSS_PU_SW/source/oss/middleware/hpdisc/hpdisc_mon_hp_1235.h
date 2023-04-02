/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef HPDISC_MON_HP_1235_H
#define HPDISC_MON_HP_1235_H

/* ---------- include required interface: ----------------------------------- */

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- provided operations: ------------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-HPDISC-0060 */
/* Manage FaultWord for HP 1, 2, 3 and 5 */
extern void hpdisc_mon_hp_1235(ts_hpdisk_device * p_device,
                               tu_hp_fault_word * p_fault_word);

#endif /* HPDISC_MON_HP_1235_H */
