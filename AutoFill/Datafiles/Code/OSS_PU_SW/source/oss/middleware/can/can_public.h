/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef CAN_PUBLIC_H
#define CAN_PUBLIC_H

/* ---------- include required interface: ----------------------------------- */
#include "driver/can/can_critical_private.h"

/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided types: ----------------------------------------------- */
/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- provided operations: ------------------------------------------ */
/* Function to initialize CAN  */
extern void can_init(void);

extern void can_periodic(void);

#endif /* CAN_PUBLIC_H */
