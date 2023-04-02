/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef UOD_INTERFACE_TASK_PUBLIC_H
#define UOD_INTERFACE_TASK_PUBLIC_H

/* ---------- include required interface: ----------------------------------- */

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- provided operations: ------------------------------------------ */
/* UOD initialization task */
extern void uod_init(void);

/* UOD periodic task */
extern void uod_task(void);

#endif /* UOD_INTERFACE_TASK_PUBLIC_H */
