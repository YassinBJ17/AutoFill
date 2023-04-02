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
void can_init_buff_tx(uint32_t const can_x_reg_addr,
                      uint32_t const can_ram_start_addr)
{
   ts_can_reg_t            * p_can_reg_descr;
   uint32_t                  txbc_buff;

   /* Get the configuration */

   /* Get the driver registers in local variable */
   p_can_reg_descr = (ts_can_reg_t*)(can_x_reg_addr);

   /* M_CAN_TXESC */
   /* Tx Buffer Data Field Size = 8 byte data field */
   p_can_reg_descr->s_txesc.u_reg = (reg32_t)0x00000000;

   /* M_CAN_TXBC */
   /* Configuration of emission buffers size */
   /* TQFM = 0 FIFO operation */
   /* Tx mode = 0*/
   txbc_buff = (CAN_TQFM_VALUE & CAN_TQFM_MASK) << CAN_TQFM_SHIFT;
   /* TQFS = N TX FIFO */
   /* Tx nb elem = 32 */
   txbc_buff = txbc_buff | ((CAN_TQFS_VALUE & CAN_TQFS_MASK) << CAN_TQFS_SHIFT);
   /* NTDB = 0, No dedicated transmit buffers */
   txbc_buff = txbc_buff | ((CAN_NDTB_VALUE & CAN_NDTB_MASK) << CAN_NDTB_SHIFT);
   /* TX buffer start address */
   txbc_buff = (txbc_buff | (((can_ram_start_addr - CAN1_RAM_ADDR) + CAN_TX_CAN_OFF) & CAN_TBSA_MASK));

   p_can_reg_descr->s_txbc.u_reg = (reg32_t)txbc_buff;

}

/* ---------- internal operation bodies: ------------------------------------ */

