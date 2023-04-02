/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef DISCRETE_ATP_PUBLIC_H
#define DISCRETE_ATP_PUBLIC_H

/* ---------- include required interface: ----------------------------------- */
#include "type/common_type.h"

/* ---------- provided define constants: ------------------------------------ */
/* GPIO ATP_TST_MPC address  */
#define GPDO_54_ATP_TST      (reg8_t *)0xFFFC1336

/* GPIO values disable/enable */
#define GPIO_DISABLE_VALUE   (reg8_t)0x0
#define GPIO_ENABLE_VALUE    (reg8_t)0x1

/* ---------- provided types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- provided operations: ------------------------------------------ */
/* Service to set GPIO 54 ATP_TST_MPC to 0 */
extern void discrete_atp_clear(void);

/* Service to set GPIO 54 ATP_TST_MPC to 1 */
extern void discrete_atp_set(void);


#endif /* DISCRETE_ATP_PUBLIC_H */
