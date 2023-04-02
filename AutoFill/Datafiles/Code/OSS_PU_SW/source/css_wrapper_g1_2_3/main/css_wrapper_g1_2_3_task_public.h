/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef CSS_WRAPPER_G1_2_3_TASK_PUBLIC_H
#define CSS_WRAPPER_G1_2_3_TASK_PUBLIC_H

/* ---------- include required interface: ----------------------------------- */

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided types: ----------------------------------------------- */

/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- provided operations: ------------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-SCHED-0010 */
/* Implements REQ_FADEX_OS_SRD-SCHED-0040 */
/* CSS wrapper G1_2_3 init task */
extern void css_wrapper_g1_2_3_init_task(void);

/* Implements REQ_FADEX_OS_SRD-SCHED-0010 */
/* Implements REQ_FADEX_OS_SRD-SCHED-0040 */
/* CSS wrapper G1_2_3 fast task */
extern void css_wrapper_g1_2_3_fast_task(void);

/* Implements REQ_FADEX_OS_SRD-SCHED-0010 */
/* Implements REQ_FADEX_OS_SRD-SCHED-0040 */
/* CSS wrapper G1_2_3 slow task */
extern void css_wrapper_g1_2_3_slow_task(void);

/* Implements REQ_FADEX_OS_SRD-SCHED-0010 */
/* Implements REQ_FADEX_OS_SRD-SCHED-0040 */
/* CSS wrapper G1_2_3 very slow task */
extern void css_wrapper_g1_2_3_very_slow_task(void);

/* Implements REQ_FADEX_OS_SRD-SCHED-0010 */
/* Implements REQ_FADEX_OS_SRD-SCHED-0040 */
/* CSS wrapper G1_2_3 background task */
extern void css_wrapper_g1_2_3_background_task(void);

#endif /* CSS_WRAPPER_G1_2_3_TASK_PUBLIC_H */
