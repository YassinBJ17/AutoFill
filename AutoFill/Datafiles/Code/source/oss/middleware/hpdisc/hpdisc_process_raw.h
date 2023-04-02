/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef HPDISC_PROCESS_RAW_H
#define HPDISC_PROCESS_RAW_H

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
extern uint16_t hpdisc_process_raw(uint8_t p_task, ts_hpdisk_item * p_item);

#endif /* HPDISC_PROCESS_RAW_H */
