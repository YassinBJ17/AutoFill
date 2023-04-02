/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef SMOT_GPIO_COMMON_H
#define SMOT_GPIO_COMMON_H

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "type/mcp_types.h"

/* ---------- provided define constants: ------------------------------------ */
/* SIUL2 GPDI 20 read register adress */
#define GPIO_20 ((uint8_t *) 0xFFFC1514)

/* SIUL2 GPDI 21 read register adress */
#define GPIO_21 ((uint8_t *) 0xFFFC1515)

/* SIUL2 GPDI 59 read register adress */
#define GPIO_59 ((uint8_t *) 0xFFFC153B)

/* SIUL2 GPDI 77 read register adress */
#define GPIO_77 ((uint8_t *) 0xFFFC154D)

/* TEMPORARY PATCH FOR STEPPER MOTOR / TO BE REMOVED*/
/* Adress of GPIO register */
#define MPC_PBIT_SELECT_TEST1_ADD (uint8_t *)0xFFFC13CE
#define MPC_PBIT_SELECT_TEST2_ADD (uint8_t *)0xFFFC13CF
/* TEMPORARY PATCH FOR STEPPER MOTOR / TO BE REMOVED*/

/* ---------- provided types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* Smot phase 1 state feedback */
extern uint8_t *smot_ph_1;

/* Smot phase 2 state feedback */
extern uint8_t *smot_ph_2;

/* Smot phase 3 state feedback */
extern uint8_t *smot_ph_3;

/* Smot phase 4 state feedback */
extern uint8_t *smot_ph_4;

/* ---------- provided operations: ------------------------------------------ */

#endif /* SMOT_GPIO_COMMON_H */
