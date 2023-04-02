/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : <short description of the operations of the .c file>
 * --------------------------------------------------------------------------
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
/* Implements REQ_FADEX_OS_SRD-CAN-0030 */
void can_read_check_rx_status(uint32_t  const can_x_reg_addr,
                              ts_can_rx     * ptr_dest_shmem_can)
{

   ts_can_reg_t* p_can_reg_descr;
   reg32_t local_logical_fifo_full;

   /* Get the driver registers in local variable */
   p_can_reg_descr = (ts_can_reg_t*)(can_x_reg_addr);

   /* Check on FIFO Full / lost and update Rx Status */
   /* initialisation to 0 */
   local_logical_fifo_full = (reg32_t)0;
   /* if one of the bit is equal to 1 then local_logical_fifo_full = 1 */
   local_logical_fifo_full =  p_can_reg_descr->s_ir.u_bit.s_rf0f | p_can_reg_descr->s_ir.u_bit.s_rf1f |
   p_can_reg_descr->s_ir.u_bit.s_rf0l | p_can_reg_descr->s_ir.u_bit.s_rf1l;

   if ((reg32_t)1 == local_logical_fifo_full)
   {
      /* set the invalid bit */
      ptr_dest_shmem_can->s_fault_word.u_bit.s_fifo_err = CAN_FIFO_INVALID;
   }

   /* check on crc error and update rx status */
   if ((reg32_t)1 == p_can_reg_descr->s_ir.u_bit.s_crce)
   {
      ptr_dest_shmem_can->s_fault_word.u_bit.s_crc_err = CAN_CRC_INVALID;
   }

   /* check on frame error and update rx status */
   if (((reg32_t)1 == p_can_reg_descr->s_ir.u_bit.s_ste) || ((reg32_t)1 == p_can_reg_descr->s_ir.u_bit.s_foe))
   {
      ptr_dest_shmem_can->s_fault_word.u_bit.s_frame_err = CAN_FRAME_INVALID;
   }

   /* check the status word and set if necessary the invalid fault state = if one of the other bit is faulty (= 1) */
   if (ptr_dest_shmem_can->s_fault_word.u_word > (uint32_t)1 )
   {
      ptr_dest_shmem_can->s_fault_word.u_bit.s_invalid = CAN_STATUS_INVALID;
   }
}

/* ---------- internal operation bodies: ------------------------------------ */
