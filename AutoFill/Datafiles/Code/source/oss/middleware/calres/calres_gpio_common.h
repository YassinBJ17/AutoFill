/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */


#ifndef CALRES_GPIO_COMMON_H
#define CALRES_GPIO_COMMON_H


/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "type/mcp_types.h"

/* ---------- provided define constants: ------------------------------------ */
/* GPDI start adress */
#define GPDI_ADRESS ((uint8_t *) 0xFFFC1500)
/* GPDO start adress */
#define GPDO_ADRESS ((uint8_t *) 0xFFFC1300)

/** SIUL2 GPI 002 read register adress
 *  used as SELECT_XRB_CALRES_RX_N */
#define GPDI_002 ((uint8_t *) (GPDI_ADRESS +   2))

/** SIUL2 GPO 003 write register adress
 *  used as SELECT_XRB_CALRES_TX1 */
#define GPDO_003 ((uint8_t *) (GPDO_ADRESS +   3))

/** SIUL2 GPO 232 write register adress
 *  used as PBIT_CALRES_RETURN_OPEN_N */
#define GPDO_232 ((uint8_t *) (GPDO_ADRESS + 232))

/* ---------- provided types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* Declaration of all GPIO inputs. */
extern uint8_t *p_accom_gpi_002; /* SELECT_XRB_CALRES_RX_N */
extern uint8_t *p_accom_gpo_003; /* SELECT_XRB_CALRES_TX1 */
extern uint8_t *p_accom_gpo_232; /* PBIT_CALRES_RETURN_OPEN_N */


/* ---------- provided operations: ------------------------------------------ */


#endif /* CALRES_GPIO_COMMON_H */
