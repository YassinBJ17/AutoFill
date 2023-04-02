/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : this function is used to set the txbar register to add a
 * send request
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
void can_write_start_tx(uint32_t    const can_x_reg_addr,
                        uint32_t    const fifo_elt_offset)
{
   /* Get the driver registers in local variable */
   ts_can_reg_t* p_can_reg_descr;
   p_can_reg_descr = (ts_can_reg_t*)(can_x_reg_addr);

   /* Launch buffer transmission thanks to txbar register*/
   /* txbar is a 32 bit register, each bit matches a Tx buffer*/
   /* setting a 1 in the txbar register order the MPC to tranmit the corresponding Tx buffer*/
   p_can_reg_descr->s_txbar.u_bit.s_ar = (reg32_t)((uint32_t)1 << fifo_elt_offset);

}

/* ---------- internal operation bodies: ------------------------------------ */
