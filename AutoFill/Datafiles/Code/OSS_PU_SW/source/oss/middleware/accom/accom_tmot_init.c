/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Allows init to start on the right channel, and tmot and smot
 *                 to work correctly.
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/accom/accom_fpga_common.h"
#include "middleware/accom/accom_private.h"
#include "middleware/accom/accom_gpio_common.h"


/* ---------- include required interface: ----------------------------------- */

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */

/* Implements REQ_FADEX_OS_SRD-ACCOM-0010 */
/**
 *  Function to force the channel A to start as active,
 *    which also allows the Tmot/Smot to initialize normally.
 */
void accom_tmot_init(const tu_accom_ch_bit_fault_word fault_word)
{
   /* Via the FPGA, initialize discretes for all channels */
   accom_fpga_reg->s_dis_reg.s_disconnect_clear_key_1 = DISCONNECT_CLEAR_KEY_1;
   accom_fpga_reg->s_dis_reg.s_disconnect_clear_key_2 = DISCONNECT_CLEAR_KEY_2;
   accom_fpga_reg->s_dis_reg.s_disable_clear_key_1    = DISABLE_CLEAR_KEY_1;
   accom_fpga_reg->s_dis_reg.s_disable_clear_key_2    = DISABLE_CLEAR_KEY_2;

   /* if the current channel is A, */
   if(FALSE == fault_word.u_bit.s_ch_id)
   {
       /* ...Set the GPDOs to LOW state */
       *accom_gpo_206 = (uint8_t)0; /* MPC_PBIT_SELECT_TEST1_ADD */
       *accom_gpo_207 = (uint8_t)0; /* MPC_PBIT_SELECT_TEST2_ADD */
   }
   /* if the current channel is B, */
   else
   {
      /* ...Set the GPDOs to HIGH state */
      *accom_gpo_206 = (uint8_t)1; /* MPC_PBIT_SELECT_TEST1_ADD */
      *accom_gpo_207 = (uint8_t)1; /* MPC_PBIT_SELECT_TEST2_ADD */
   }
}

/* ---------- internal operations: ------------------------------------------ */
