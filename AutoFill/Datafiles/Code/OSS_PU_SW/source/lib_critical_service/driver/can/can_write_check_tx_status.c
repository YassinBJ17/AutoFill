/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : this function is used to retrieve the status of the send
 * frames and write it in the shared memory
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "driver/can/can_critical_private.h"


/* LPOS Public Interface */

/* LPOS Private Interface */

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* */
/* Implements REQ_FADEX_OS_SRD-CAN-0040 */
/* Implements REQ_FADEX_OS_SRD-CAN-0050 */
void can_write_check_tx_status(uint32_t    const can_x_reg_addr,
                               ts_can_tx * const ptr_src_shmem_can)
{

   /* Get the driver registers in local variable */
   ts_can_reg_t* p_can_reg_descr;
   p_can_reg_descr = (ts_can_reg_t*)(can_x_reg_addr);

   /* Check on Ackowledge error and update Tx Status */
   if ((reg32_t)1 == p_can_reg_descr->s_ir.u_bit.s_acke)
   {
      ptr_src_shmem_can->s_fault_word.u_bit.s_ack_err = CAN_ACK_INVALID;
   }

   /* Check on FIFO error and update Tx Status */
   if ((reg32_t)1 == p_can_reg_descr->s_txfqs.u_bit.s_tfqf)
   {
      ptr_src_shmem_can->s_fault_word.u_bit.s_fifo_err = CAN_FIFO_INVALID;
   }

   /* Check on Frame error and update Tx Status */
   if ((reg32_t)1 == p_can_reg_descr->s_ir.u_bit.s_be)
   {
      ptr_src_shmem_can->s_fault_word.u_bit.s_frame_err = CAN_FRAME_INVALID;
   }
   /* Check on busy error and update Tx Status */
   if ((reg32_t)1 == p_can_reg_descr->s_ir.u_bit.s_tc)
   {
      ptr_src_shmem_can->s_fault_word.u_bit.s_busy = CAN_BUSY;
   }

   /* Check on invalid error and update Tx Status */
   if (ptr_src_shmem_can->s_fault_word.u_word > (uint32_t)1 )
   {
      ptr_src_shmem_can->s_fault_word.u_bit.s_invalid = CAN_STATUS_INVALID;
   }
}

/* ---------- internal operation bodies: ------------------------------------ */
