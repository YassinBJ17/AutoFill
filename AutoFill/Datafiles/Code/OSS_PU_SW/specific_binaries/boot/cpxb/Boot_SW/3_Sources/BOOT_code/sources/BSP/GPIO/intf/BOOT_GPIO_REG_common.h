#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */


/* ---------- include required interface: ----------------------------------- */
/* LPOS Common Interface */
#include "CMN_TYPES_common.h"

/* LPOS Public Interface */
/* none */

/* LPOS Private Interface */
/* none */

/* ---------- provided define constants: ------------------------------------ */

/* GPIO  MPC577 SIUL2 Gpio register address                  */
/* SIUL2 Register address + GPIO register offset */
#define GPIO_SIUL2_GPIO_REG_ADDR    (0xFFFC0000 + 0x00001300)		/* SIUL2 Gpio Register*/

/* SIUL2 REG PROT register offset */
#define SIUL2_REG_PROT_GCR_ADDR (0xFFFC3FFCul)

/* */
#define GPIO_PIN_MAX_NB        512UL
/* */
#define GPIO_PORT_MAX_NB       32UL
/* */
#define GPIO_CLEAR_REG_VALUE   0x0000
/* */
#define GPIO_LOGIC_0           0
#define GPIO_LOGIC_1           1

/* ---------- provided types: ----------------------------------------------- */
/* In / Out Management*/
typedef struct
{
   /* Pad Data Out Register */
   reg8_t s_GPIO_OUT_PIN[GPIO_PIN_MAX_NB];
   /* Pad Data In Register */
   reg8_t s_GPIO_IN_PIN[GPIO_PIN_MAX_NB];
   /* Parallel Pad Data Out Register */
   reg16_t s_GPIO_OUT_PORT[GPIO_PORT_MAX_NB];
   /* Parallel Pad Data In Register */
   reg16_t s_GPIO_IN_PORT[GPIO_PORT_MAX_NB];
   /* Masked Parallel Pad Data Out Register */
   reg32_t s_GPIO_OUT_PORT_WITH_MASK[GPIO_PORT_MAX_NB];
}
ts_GPIO_CTRL_REG;

/* ---------- provided global variable--------------------------------------- */
/* none */

/* ---------- provided constants: ------------------------------------------- */
/* none */

/* ---------- provided operations: ------------------------------------------ */
/* none */


#endif /* GPIO_PRIVATE_H */
