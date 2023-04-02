/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Smot initialization function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "middleware/smot/smot_fpga_reg_common.h"
#include "memory/memory_address_public.h"
#include "middleware/smot/smot_gpio_common.h"
#include "middleware/smot/smot_write_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* Smot previous increment number command */
int32_t smot_previous_incr_cmd;

/* Smot previous common phase state index */
uint32_t smot_ph_prev_state_idx;

/* Smot expected position */
uint32_t smot_expected_position;

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ------ --- provided operation bodies: ------------------------------------ */

/* ---------- internal operations: ------------------------------------------ */
