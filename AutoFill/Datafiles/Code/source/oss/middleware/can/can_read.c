/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : <short description of the operations of the .c file>
 * ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "driver/can/can_critical_private.h"
#include "driver/can/can_private.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* */
/* Implements REQ_FADEX_OS_SRD-CAN-0030 */
void can_read(uint32_t            const can_x_reg_addr,
              uint32_t            const src_can_ram_addr,
              ts_can_rx         * const ptr_dest_shmem_can,
              ts_can_conf const * const ptr_can_conf)
{
   uint32_t            rx_count; /* number of received frames */
   uint32_t            fifo_0_lvl;
   uint32_t            fifo_0_start_offset;
   uint32_t            fifo_1_lvl;
   uint32_t            fifo_1_start_offset;
   uint32_t            idx_to_rcv;
   uint32_t            total_nb_frame_received;
   te_flag_found_state flag_stop;
   ts_can_frame        can_frame_rx_tab[CAN_FRAME_MAX_NB];

   idx_to_rcv              = (uint32_t)0;
   rx_count                = (uint32_t)0;
   total_nb_frame_received = (uint32_t)0;
   flag_stop               = e_not_found;


   do
   {
      /* Get FIFO level reception */
      can_read_get_fifo_rx_lvl(can_x_reg_addr,
                          &fifo_0_lvl,
                          &fifo_0_start_offset,
                          &fifo_1_lvl,
                          &fifo_1_start_offset);

      if (fifo_0_lvl > (uint32_t)0)
      {
         /* Copy RX element buffer from CAN_RAM */
         can_read_get_msg_from_can_ram(src_can_ram_addr,
                                       &can_frame_rx_tab[idx_to_rcv],
                                       ptr_can_conf,
                                       e_can_cfex_fifo_0,
                                       fifo_0_start_offset);

         /* Update FIFO fill level */
         can_read_ack_index_fifo_rx(can_x_reg_addr,
                                   e_can_cfex_fifo_0,
                                   fifo_0_start_offset);
         total_nb_frame_received++;

      }
      else if (fifo_1_lvl > (uint32_t)0)
      {
         /* Copy RX element buffer from CAN_RAM */
         can_read_get_msg_from_can_ram(src_can_ram_addr,
                                       &can_frame_rx_tab[idx_to_rcv],
                                       ptr_can_conf,
                                       e_can_cfex_fifo_0,
                                       fifo_0_start_offset);

         /* Update FIFO fill level */
         can_read_ack_index_fifo_rx(can_x_reg_addr,
                                    e_can_cfex_fifo_1,
                                    fifo_1_start_offset);
         total_nb_frame_received++;
      }

      /* Check there is a data in FIFO */
      if ((fifo_0_lvl == (uint32_t)0) && (fifo_1_lvl == (uint32_t)0))
      {
         flag_stop = e_found;
      }

      idx_to_rcv++;

   }
   while ((idx_to_rcv < CAN_FRAME_MAX_NB) && (flag_stop == e_not_found) );
   /* filter the frames thanks to the ID to keep only the last frame in case multiple id are the same and write the  */
   /* kept frames in shared memory                                                                                  */
   if ((uint32_t)0 < total_nb_frame_received)
   {
      can_read_filter_frames_by_id(can_frame_rx_tab, ptr_dest_shmem_can, total_nb_frame_received, &rx_count);

      /* write in shared mem the number of received frames */
      ptr_dest_shmem_can->s_frames_nb = rx_count;
   }
   /* write in shared mem the rx status */
   can_read_check_rx_status(can_x_reg_addr, ptr_dest_shmem_can);


}

/* ---------- internal operation bodies: ------------------------------------ */
