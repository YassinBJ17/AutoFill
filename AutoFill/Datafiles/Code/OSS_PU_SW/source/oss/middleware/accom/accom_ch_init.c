/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Acquisition and check of channel identifier
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/accom/accom_fpga_common.h"
#include "middleware/accom/accom_public.h"
#include "middleware/accom/accom_private.h"
#include "middleware/accom/accom_fccu_private.h"

/* ---------- include required interface: ----------------------------------- */

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
uint32_t ch_id;
uint32_t ch_id_backup;

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */

/* Implements REQ_FADEX_OS_SRD-ACCOM-0010 */
/**
 * Function to perform checks on the channel identifier, at power-up.
 */
tu_accom_ch_bit_fault_word accom_ch_init(void)
{
   tu_accom_ch_bit_fault_word accom_ch_bit_fault_word;
   accom_ch_bit_fault_word.u_word = 0;
   accom_info.u_word = 0;

   /* Initialize the FCCU */
   accom_fccu_init();
   /** Function to NOT force the disconnection
    *    (Allows to NOT cripple the channel A, upon reset). */
   accom_force_disconnection_clear();


   /** The FPGA is responsible for telling its corresponding CPxB which channel
    *    is currently in use on this CPxB.
    *  This data and its complement can be read in the FPGA's status register.*/
   if (( ((uint32_t) 0) == accom_fpga_reg->s_status_reg.u_field.s_channel_id1)
     &&( ((uint32_t) 1) == accom_fpga_reg->s_status_reg.u_field.s_channel_id0))
   {
      ch_id = CHANNEL_ID_A;
      ch_id_backup = CHANNEL_ID_A;
      accom_ch_bit_fault_word.u_bit.s_ch_id_is_invalid = (uint32_t) 0;
      accom_ch_bit_fault_word.u_bit.s_ch_id = ACCOM_CHANNEL_ID_IS_A;

   }
   else if (( ((uint32_t) 1) == accom_fpga_reg->s_status_reg.u_field.s_channel_id1)
          &&( ((uint32_t) 0) == accom_fpga_reg->s_status_reg.u_field.s_channel_id0))
   {
      ch_id = CHANNEL_ID_B;
      ch_id_backup = CHANNEL_ID_B;
      accom_ch_bit_fault_word.u_bit.s_ch_id_is_invalid = (uint32_t) 0;
      accom_ch_bit_fault_word.u_bit.s_ch_id = ACCOM_CHANNEL_ID_IS_B;
   }
   /** If the data given by the FPGA is different from the two combinations
    *   above, there is an error. */
   else
   {
      accom_ch_bit_fault_word.u_bit.s_ch_id_is_invalid = (uint32_t) 1;
   }

   /* Configure the last GPDOs  (they need the channel ID) */
   accom_tmot_init(accom_ch_bit_fault_word);

   return accom_ch_bit_fault_word;
}

/* ---------- internal operations: ------------------------------------------ */
