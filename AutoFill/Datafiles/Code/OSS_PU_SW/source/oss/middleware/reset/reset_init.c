/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : RESET function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/reset/reset_public.h"
#include "middleware/reset/reset_private.h"

/* ---------- include required interface: ----------------------------------- */


/* ---------- internal define constants: ------------------------------------ */


/* ---------- internal types: ----------------------------------------------- */


/* ---------- provided constants: ------------------------------------------- */


/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-RESET-0001 */
void reset_init(void)
{
   /* Local Variable Declaration */
   ts_reset_reg volatile *        pt_RST_reg;

   /* Initialization Variable */
   pt_RST_reg                     = (ts_reset_reg volatile *)K_RESET_REG_ADDR ;

   /* Source code start */


   /* TEMPORARY PATCH TO AVOID FPGA RESET COUNTER DEADLOCK WHEN BOARD IS REBOOTED AND NOT POWERED OFF
   (ALLOWS UNLIMITED REBOOTS AS LONG AS FPGA DOES NOT IMPLEMENT THE MAX NB OF RESET IN PBIT MODE)
   TODO TO REMOVE */


   pt_RST_reg->s_pbit_mode_set_key_1 = RST_PBIT_MODE_SET_KEY_1_CMD_VALUE;

   pt_RST_reg->s_pbit_mode_set_key_2 = RST_PBIT_MODE_SET_KEY_2_CMD_VALUE;

   /* Keys shall normally be cleared at the end of PBIT ! TODO */

   return;
}

/* ---------- internal operations: ------------------------------------------ */
