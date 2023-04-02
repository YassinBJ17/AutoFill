/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Acquisition and check of channel identifier
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/accom/accom_gpio_common.h"
#include "middleware/accom/accom_public.h"

/* ---------- include required interface: ----------------------------------- */

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* Definition of all GPIO inputs */
uint8_t * const accom_gpi_122 = GPDI_122; /* MPC_Select */
uint8_t * const accom_gpi_161 = GPDI_161; /* MPC_decision_mon */
uint8_t * const accom_gpo_179 = GPDO_179; /* SW_force_decision_inactive_n */
uint8_t * const accom_gpo_206 = GPDO_206; /* MPC_PBIT_SELECT_TEST1_ADD */
uint8_t * const accom_gpo_207 = GPDO_207; /* MPC_PBIT_SELECT_TEST2_ADD */
uint8_t * const accom_gpo_208 = GPDO_208; /* MPC_accom_inconsistent */
uint8_t * const accom_gpo_209 = GPDO_209; /* MPC_accom_inconsistent_n */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */

/* ---------- internal operations: ------------------------------------------ */
