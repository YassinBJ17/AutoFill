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

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* */
/* Implements REQ_FADEX_OS_SRD-CAN-0030 */
void can_read_get_fifo_rx_lvl(uint32_t  const can_x_reg_addr,
                              uint32_t* const p_fifo_0_lvl,
                              uint32_t* const p_fifo_0_start_offset,
                              uint32_t* const p_fifo_1_lvl,
                              uint32_t* const p_fifo_1_start_offset)
{
   /* Get the driver registers in local variable */
   ts_can_reg_t* p_can_reg_descr;
   p_can_reg_descr = (ts_can_reg_t*)(can_x_reg_addr);

   /* Get fifo 0 fill level */
   *p_fifo_0_lvl = (uint32_t)p_can_reg_descr->s_rxf0s.u_bit.s_f0fl; /* Fifo 0 full or not full */
   *p_fifo_0_start_offset = (uint32_t)p_can_reg_descr->s_rxf0s.u_bit.s_f0gi; /* fifo 0 get index */

   /* Get fifo 1 fill level */
   *p_fifo_1_lvl = (uint32_t)p_can_reg_descr->s_rxf1s.u_bit.s_f1fl; /* Fifo 1 full or not full */
   *p_fifo_1_start_offset = (uint32_t)p_can_reg_descr->s_rxf1s.u_bit.s_f1g1; /* fifo 1 get index */

}

/* ---------- internal operation bodies: ------------------------------------ */
