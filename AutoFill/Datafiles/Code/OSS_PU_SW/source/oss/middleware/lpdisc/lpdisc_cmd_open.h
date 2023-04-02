/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef LPDISC_CMD_OPEN_H
#define LPDISC_CMD_OPEN_H

/* ---------- include required interface: ----------------------------------- */

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- provided operations: ------------------------------------------ */
/*  */
extern void lpdisc_cmd_open(ts_lpdisk_device * p_device,
                            tu_lp_fault_word * p_fault_word,
                            uint32_t         * p_command);


#endif /* LPDISC_CMD_OPEN_H */
