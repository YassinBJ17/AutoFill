/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */


#ifndef ACCOM_GPIO_COMMON_H
#define ACCOM_GPIO_COMMON_H


/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "type/mcp_types.h"

/* ---------- provided define constants: ------------------------------------ */
/* GPDI start adress */
#define GPDI_ADRESS ((uint8_t *) 0xFFFC1500)
/* GPDO start adress */
#define GPDO_ADRESS ((uint8_t *) 0xFFFC1300)

/** SIUL2 GPO 122 write register adress
 *  used as MPC_select */
#define GPDI_122 ((uint8_t *) (GPDI_ADRESS + 122))
/** SIUL2 GPO 161 write register adress
 *  used as MPC_decision_mon */
#define GPDI_161 ((uint8_t *) (GPDI_ADRESS + 161))
/** SIUL2 GPO 179 write register adress
 *  used as SW_force_decision_inactive_n */
#define GPDO_179 ((uint8_t *) (GPDO_ADRESS + 179))
/** SIUL2 GPO 206 write register adress
 *  used as MPC_PBIT_SELECT_TEST1_ADD */
#define GPDO_206 ((uint8_t *) (GPDO_ADRESS + 206))
/** SIUL2 GPO 207 write register adress
 *  used as MPC_PBIT_SELECT_TEST2_ADD */
#define GPDO_207 ((uint8_t *) (GPDO_ADRESS + 207))
/** SIUL2 GPO 208 write register adress
 *  used as MPC_accom_inconsistent */
#define GPDO_208 ((uint8_t *) (GPDO_ADRESS + 208))
/** SIUL2 GPO 209 write register adress
 *  used as MPC_accom_inconsistent_n */
#define GPDO_209 ((uint8_t *) (GPDO_ADRESS + 209))


/* ---------- provided types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* Declaration of all GPIO inputs. */
extern uint8_t * const accom_gpi_122; /* MPC_select */
extern uint8_t * const accom_gpi_161; /* MPC_decision_mon */
extern uint8_t * const accom_gpo_179; /* SW_force_decision_inactive_n */
extern uint8_t * const accom_gpo_206; /* MPC_PBIT_SELECT_TEST1_ADD */
extern uint8_t * const accom_gpo_207; /* MPC_PBIT_SELECT_TEST2_ADD */
extern uint8_t * const accom_gpo_208; /* MPC_accom_inconsistent */
extern uint8_t * const accom_gpo_209; /* MPC_accom_inconsistent_n */

/* ---------- provided operations: ------------------------------------------ */


#endif /* ACCOM_GPIO_COMMON_H */
