/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef OSS_TASK_PUBLIC_H
#define OSS_TASK_PUBLIC_H

/* ---------- include required interface: ----------------------------------- */
#include "memory/shared_memory_public.h"

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* Location in MRAM where are stored the max execution times of the functions */
extern ts_fct_exec_time* const max_times;

/* Times used to compute the elapsed time */
extern int64_t start_time_global;
extern int64_t current_time_previous;

extern boolean_t current_channel_is_a;

/* ---------- provided operations: ------------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-SCHED-0010 */
/* Implements REQ_FADEX_OS_SRD-SCHED-0020 */
/* Implements REQ_FADEX_OS_SRD-SCHED-0030 */
/* Global initialization function for OSS */
extern void oss_init(void);

/* Implements REQ_FADEX_OS_SRD-SCHED-0010 */
/* Implements REQ_FADEX_OS_SRD-SCHED-0020 */
/* Implements REQ_FADEX_OS_SRD-SCHED-0030 */
/* Global real time function for OSS */
extern void oss_task(void);

extern void oss_task2(void);
extern void oss_task3(void);
extern void oss_task4(void);

#endif /* OSS_TASK_PUBLIC_H */
