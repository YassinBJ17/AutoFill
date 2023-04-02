/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
   DESCRIPT : this function is used to set the ack level of the rx FIFO 0/1
   "Rx FIFO 0 Acknowledge Index. After the Host has read a message or a
   sequence of messages from Rx FIFO it has to write the buffer index of the
   last element read from Rx FIFO to FxAI. This will set the Rx FIFO 0 Get
   Index to FxAI + 1 and update the FIFO Fill Level "
   -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "driver/can/can_critical_private.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* ---------- Function description: ----------------------------------------- */
/* inputs :                                                                   */
/*          can_x_reg_addr = adrres pointing toward mpc registers             */
/*          wich_fifo = wich fifo is used (FIFO 0/1)                          */
/*          idx_fifo = fifo index                                             */
/* outputs :                                                                  */
/*          set MPC577 register M_CAN_RXFxA.FxAI with index value             */

/* Implements REQ_FADEX_OS_SRD-CAN-0030 */
void can_read_ack_index_fifo_rx(uint32_t          const can_x_reg_addr,
                                te_can_fifo_rec_t const wich_fifo,
                                uint32_t          const idx_fifo)
{
   /* Get the driver registers in local variable */
   ts_can_reg_t* p_can_reg_descr;
   p_can_reg_descr = (ts_can_reg_t*)(can_x_reg_addr);

   /* case we use fifo 0  */
   if (e_can_cfex_fifo_0 == wich_fifo)
   {
      /*set the ack level of the rx FIFO 0 */
      /* This will automatically update the Rx FIFO 0 Get Index and the FIFO Fill Level */
      p_can_reg_descr->s_rxf0a.u_bit.s_f0ai = (reg32_t)idx_fifo;
   }
   /* case we use fifo 1  */
   else
   {
      /*set the ack level of the rx FIFO 1 */
      /* This will automatically update the Rx FIFO 1 Get Index and the FIFO Fill Level */
      p_can_reg_descr->s_rxf1a.u_bit.s_f1ai = (reg32_t)idx_fifo;
   }
}

/* ---------- internal operation bodies: ------------------------------------ */
