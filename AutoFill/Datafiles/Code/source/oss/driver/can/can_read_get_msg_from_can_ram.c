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
#include "driver/can/can_private.h"

/* LPOS Public Interface */

/* LPOS Private Interface */

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* */
/* Implements REQ_FADEX_OS_SRD-CAN-0030 */
void can_read_get_msg_from_can_ram(uint32_t            const src_can_ram_addr,
                                   ts_can_frame      * const dest_can_frame_rx_tab,
                                   ts_can_conf const * const ptr_can_conf,
                                   te_can_fifo_rec_t   const fifo_selection,
                                   uint32_t            const buff_elt_position)
{
   /* variable used to convert data from  M_CAN RX buffer format into shmem format */
   ts_can_rx_buff_elt_t* p_can_ram_elt;
   uint32_t              local_can_ram_fifo0_add;
   uint32_t              local_can_ram_fifo1_add;


   switch (fifo_selection)
   {
      case e_can_cfex_fifo_0:
      {
         /* Get physical address of free CAN RAM reception element buffer */
         local_can_ram_fifo0_add = src_can_ram_addr + CAN_RX_FIFO_0_CAN_OFF + (buff_elt_position << CAN_FIFO_ELT_OFF);
         p_can_ram_elt = (ts_can_rx_buff_elt_t*)local_can_ram_fifo0_add;

         /* Convert data from CAN RX RAM format to CAN SHMEM format */
         can_read_conv_rx_frame(p_can_ram_elt, dest_can_frame_rx_tab, ptr_can_conf);
         break;
      }


      case e_can_cfex_fifo_1:
      {
         /* Get physical address of free CAN RAM reception element buffer */
         local_can_ram_fifo1_add = src_can_ram_addr + CAN_RX_FIFO_1_CAN_OFF + (buff_elt_position << CAN_FIFO_ELT_OFF);
         p_can_ram_elt = (ts_can_rx_buff_elt_t*)local_can_ram_fifo1_add;

         /* Convert data from CAN RX RAM in CAN data */
         can_read_conv_rx_frame(p_can_ram_elt, dest_can_frame_rx_tab, ptr_can_conf);
         break;
      }

      default:
      break;

   }
}

/* ---------- internal operation bodies: ------------------------------------ */
