/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef LPDISC_SET_CMD_H
#define LPDISC_SET_CMD_H

/* ---------- include required interface: ----------------------------------- */

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- provided operations: ------------------------------------------ */
/*  */
extern void lpdisc_set_cmd(ts_lpdisk_device * p_device,
                           tu_lp_fault_word * p_fault_word,
                           uint32_t         * p_command);

#endif /* LPDISC_SET_CMD_H */
