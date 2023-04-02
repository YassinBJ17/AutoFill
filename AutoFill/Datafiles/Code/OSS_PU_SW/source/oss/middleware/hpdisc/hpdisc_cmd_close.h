/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef HPDISC_CMD_CLOSE_H
#define HPDISC_CMD_CLOSE_H

/* ---------- include required interface: ----------------------------------- */

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- provided operations: ------------------------------------------ */
/*  */
extern void hpdisc_cmd_close(ts_hpdisk_device * p_device,
                             tu_hp_fault_word * p_fault_word,
                             uint32_t         * p_command);


#endif /* HPDISC_CMD_CLOSE_H */
