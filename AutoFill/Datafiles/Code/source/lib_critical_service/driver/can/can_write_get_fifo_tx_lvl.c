/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : this function is used to check the state of TX FIFO :
 * 1- check if the the Tx FIFO is full or not
 * 2- retrieve the Tx FIFO get level index
 * 3- retriev the number of consecutive free Tx FIFO elements,
 * Tx FIFO free level
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "driver/can/can_critical_private.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* */
/* Implements REQ_FADEX_OS_SRD-CAN-0040 */
/* Implements REQ_FADEX_OS_SRD-CAN-0050 */
void can_write_get_fifo_tx_lvl(uint32_t   const can_x_reg_addr,
                               uint32_t * const p_fifo_lvl,
                               uint32_t * const p_fifo_elt_offset,
                               uint32_t * const fifo_overflow)
{
   /* Get the driver registers in local variable */
   ts_can_reg_t * p_can_reg_descr;
   p_can_reg_descr = (ts_can_reg_t*)can_x_reg_addr;

   /* Detect if FIFO is full or not (0 fifo not full / 1 fifo full) */
   if (p_can_reg_descr->s_txfqs.u_bit.s_tfqf == (reg32_t)CAN_FIFO_NOT_FULL)
   {
      /* Tx Fifo get index  */
      *p_fifo_elt_offset = (uint32_t)p_can_reg_descr->s_txfqs.u_bit.s_tfqpi;

      /* Tx FIFO free level (Number of consecutive free Tx FIFO elements, range 0 to 32) */
      *p_fifo_lvl = (uint32_t)p_can_reg_descr->s_txfqs.u_bit.s_tffl;

      /* send back FIFO not full */
      *fifo_overflow = CAN_FIFO_NOT_FULL;
   }
   else
   {
      /* send back FIFO full */
      *fifo_overflow = CAN_FIFO_FULL;
   }
}

/* ---------- internal operation bodies: ------------------------------------ */
