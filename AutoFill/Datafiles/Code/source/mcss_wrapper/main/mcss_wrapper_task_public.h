/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef MCSS_WRAPPER_TASK_PUBLIC_H
#define MCSS_WRAPPER_TASK_PUBLIC_H

/* ---------- include required interface: ----------------------------------- */

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided types: ----------------------------------------------- */

/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- provided operations: ------------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-SCHED-0010 */
/* Implements REQ_FADEX_OS_SRD-SCHED-0030 */
/* MCSS wrapper initialization function */
extern void mcss_wrapper_init(void);

/* Implements REQ_FADEX_OS_SRD-SCHED-0010 */
/* Implements REQ_FADEX_OS_SRD-SCHED-0030 */
/* MCSS wrapper task function */
extern void mcss_wrapper_task(void);

#endif /* MCSS_WRAPPER_TASK_PUBLIC_H */
