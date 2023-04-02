/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef SG_SHMEM_WRITE_H
#define SG_SHMEM_WRITE_H

/* ---------- include required interface: ----------------------------------- */

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- provided operations: ------------------------------------------ */
/* Copy designated strain qauge information to shared memory */
/* Implements REQ_FADEX_OS_SRD-SG-0040 */
extern void sg_shmem_write(te_sg_signal p_sensor,
                           ts_sg*       p_value);


#endif /* SG_SHMEM_WRITE_H */
