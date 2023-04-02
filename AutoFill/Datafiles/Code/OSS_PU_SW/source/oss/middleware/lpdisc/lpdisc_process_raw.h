/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef LPDISC_PROCESS_RAW_H
#define LPDISC_PROCESS_RAW_H

/* ---------- include required interface: ----------------------------------- */

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */
/* Possible task on raw data */
#define C_RAW_CLOSE  ((uint8_t)'C')
#define C_RAW_OPEN   ((uint8_t)'O')
#define C_RAW_READ   ((uint8_t)'R')

/* ---------- provided types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- provided operations: ------------------------------------------ */
/* Process raw data from interfaces */
extern uint16_t lpdisc_process_raw(uint8_t p_task, ts_lpdisk_item * p_item);

#endif /* LPDISC_PROCESS_RAW_H */
