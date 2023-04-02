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
/* Implements REQ_FADEX_OS_SRD-CAN-0010 */
void can_init_buff_rx(uint32_t const can_x_reg_addr,
                      uint32_t const can_ram_start_addr)
{
   ts_can_reg_t            * p_can_reg_descr;
   uint32_t                  rxbc_buff;

   /* Get the configuration */

   /* Get the driver registers in local variable */
   p_can_reg_descr = (ts_can_reg_t*)(can_x_reg_addr);

   /* M_CAN_RXESC */
   /* Rx Buffer Data Field Size, Rx FIFO 1 Data Field Size, Rx FIFO 0 Data Field Size = 8 byte data field */
   p_can_reg_descr->s_rxesc.u_reg = (reg32_t)0x00000000;

   /* Configure RX FIFO 0 */
   /* Initialize local variable */
   rxbc_buff = (uint32_t)0;

   /* M_CAN_RXF0C */
   /* F0OM = Blocking mode */
   rxbc_buff = rxbc_buff | (CAN_F0M_VALUE << CAN_FOM_SHIFT);
   /* F0WM = 0, no watermark */
   rxbc_buff = rxbc_buff | (CAN_FWM_VALUE << CAN_FWM_SHIFT);
   /* F0S = N => Use N messages on FIFO (N = 64) */
   rxbc_buff = rxbc_buff | (CAN_RX_FIFO_F0_ELT_MAX<< CAN_FOS_SHIFT);
   /* F0SA = address of reception buffer */
   p_can_reg_descr->s_rxf0c.u_reg = (reg32_t)(rxbc_buff | (((can_ram_start_addr - CAN1_RAM_ADDR)
                                                + CAN_RX_FIFO_0_CAN_OFF) & CAN_FSA_MASK));

   /* Configure RX FIFO 1 */
   /* Initialize local variable */
   rxbc_buff = (uint32_t)0;

   /* M_CAN_RXF1C */
   /* F1OM = Blocking mode */
   rxbc_buff = rxbc_buff | (CAN_F0M_VALUE << CAN_FOM_SHIFT);
   /* F1WM = 0, no watermark */
   rxbc_buff = rxbc_buff | (CAN_FWM_VALUE << CAN_FWM_SHIFT);
   /* F1S = N => Use N messages on FIFO(N = 0, FIFO 1 not used) */
   rxbc_buff = rxbc_buff | (CAN_RX_FIFO_F1_ELT_MAX << CAN_FOS_SHIFT);
   /* F1SA = address of reception buffer */
   p_can_reg_descr->s_rxf1c.u_reg = (reg32_t)(rxbc_buff | (((can_ram_start_addr - CAN1_RAM_ADDR)
                                                + CAN_RX_FIFO_1_CAN_OFF) & CAN_FSA_MASK));

}

/* ---------- internal operation bodies: ------------------------------------ */

