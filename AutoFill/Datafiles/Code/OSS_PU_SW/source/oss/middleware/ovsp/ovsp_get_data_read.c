/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION :  Read 6 Rx get_data response frame
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "middleware/ovsp/ovsp_public.h"
#include "middleware/ovsp/ovsp_private.h"
#include "middleware/ovsp/ovsp_frame.h"
#include "memory/lib_critical_service_section_def_data.h"
#include "driver/can/can_critical_private.h"
#include "middleware/uod_bypass/uod_bypass_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */
ts_can_frame ovsp_received_frames_tab[OVSP_GET_DATA_MAX_FRAME];

/* ---------- provided operation bodies: ------------------------------------ */
/* Read 6 Rx get_data response frame */
void ovsp_get_data_read(uint32_t             const ovspx_reg_addr,
                        uint32_t             const src_ovspx_ram_addr,
                        boolean_t            const is_ovsp_ls)
{
   uint32_t              fifo_0_lvl;
   uint32_t              iter_data;
   uint32_t              fifo_0_start_offset;
   uint32_t              fifo_1_lvl;
   uint32_t              fifo_1_start_offset;
   uint32_t              idx_to_rcv;
   uint32_t              total_nb_frame_received;
   te_flag_found_state   flag_stop;
   ts_can_reg_t *        p_ovsp_reg_descr;
   /* variable used to convert data from M_CAN RX buffer format into shmem format */
   ts_can_rx_buff_elt_t* ovsp_ram_elt;
   uint32_t              local_ovsp_ram_fifo0_add;
   uint32_t              local_ovsp_ram_fifo1_add;

   idx_to_rcv              = (uint32_t)0;
   total_nb_frame_received = (uint32_t)0;
   flag_stop               = e_not_found;

   /* Get the driver registers in local variable */
   p_ovsp_reg_descr = (ts_can_reg_t*)(ovspx_reg_addr);

   do
   {
      /* Get FIFO level reception */
      /* Get fifo 0 fill level */
      fifo_0_lvl          = (uint32_t)p_ovsp_reg_descr->s_rxf0s.u_bit.s_f0fl; /* Fifo 0 full or not full */
      fifo_0_start_offset = (uint32_t)p_ovsp_reg_descr->s_rxf0s.u_bit.s_f0gi; /* fifo 0 get index */

      /* Get fifo 1 fill level */
      fifo_1_lvl          = (uint32_t)p_ovsp_reg_descr->s_rxf1s.u_bit.s_f1fl; /* Fifo 1 full or not full */
      fifo_1_start_offset = (uint32_t)p_ovsp_reg_descr->s_rxf1s.u_bit.s_f1g1; /* fifo 1 get index */

      if (fifo_0_lvl > (uint32_t)0)
      {
         /* Copy RX element buffer from CAN_RAM */

         /* Get physical address of free CAN RAM reception element buffer */
         local_ovsp_ram_fifo0_add = src_ovspx_ram_addr + CAN_RX_FIFO_0_CAN_OFF + (fifo_0_start_offset << CAN_FIFO_ELT_OFF);
         ovsp_ram_elt = (ts_can_rx_buff_elt_t*)local_ovsp_ram_fifo0_add;

         /* Convert data from CAN RX RAM format to CAN SHMEM format */
         /* Load std frame identifier */
         ovsp_received_frames_tab[idx_to_rcv].s_identifier = ((ovsp_ram_elt->s_rx_buff_elt_r0.u_word >> CAN_STD_ID_SHIFT) &
                                  CAN_FRAME_STD_ID_MASK);

         ovsp_received_frames_tab[idx_to_rcv].s_length = ovsp_ram_elt->s_rx_buff_elt_r1.u_bit.s_dlc;
         swap_data(&(ovsp_ram_elt->s_data[0]), ovsp_received_frames_tab[idx_to_rcv].s_data);


         if(is_ovsp_ls)
         {
            uod_bypass.uod_can_ovsp_rx_buffer_ls[idx_to_rcv].s_identifier = ovsp_received_frames_tab[idx_to_rcv].s_identifier;
            uod_bypass.uod_can_ovsp_rx_buffer_ls[idx_to_rcv].s_length = ovsp_received_frames_tab[idx_to_rcv].s_length;

            for (iter_data = (uint32_t)0; iter_data < OVSP_FRAME_TOT_LENGTH; iter_data++)
            {
                  uod_bypass.uod_can_ovsp_rx_buffer_ls[idx_to_rcv].s_data[iter_data] = ovsp_received_frames_tab[idx_to_rcv].s_data[iter_data];
            }
         }
         else
         {
            uod_bypass.uod_can_ovsp_rx_buffer_hs[idx_to_rcv].s_identifier = ovsp_received_frames_tab[idx_to_rcv].s_identifier;
            uod_bypass.uod_can_ovsp_rx_buffer_hs[idx_to_rcv].s_length = ovsp_received_frames_tab[idx_to_rcv].s_length;

            for (iter_data = (uint32_t)0; iter_data < OVSP_FRAME_TOT_LENGTH; iter_data++)
            {
               uod_bypass.uod_can_ovsp_rx_buffer_hs[idx_to_rcv].s_data[iter_data] = ovsp_received_frames_tab[idx_to_rcv].s_data[iter_data];
            }
         }


         /* Update FIFO fill level */
         p_ovsp_reg_descr->s_rxf0a.u_bit.s_f0ai = fifo_0_start_offset;

         total_nb_frame_received++;
      }
      else if (fifo_1_lvl > (uint32_t)0)
      {
         /* Copy RX element buffer from CAN_RAM */

         /* Get physical address of free CAN RAM reception element buffer */
         local_ovsp_ram_fifo1_add = src_ovspx_ram_addr + CAN_RX_FIFO_0_CAN_OFF + (fifo_1_start_offset << CAN_FIFO_ELT_OFF);
         ovsp_ram_elt = (ts_can_rx_buff_elt_t*)local_ovsp_ram_fifo1_add;

         /* Convert data from CAN RX RAM format to CAN SHMEM format */
         /* Load std frame identifier */
         ovsp_received_frames_tab[idx_to_rcv].s_identifier = ((ovsp_ram_elt->s_rx_buff_elt_r0.u_word >> CAN_STD_ID_SHIFT) &
                                  CAN_FRAME_STD_ID_MASK);

         ovsp_received_frames_tab[idx_to_rcv].s_length = ovsp_ram_elt->s_rx_buff_elt_r1.u_bit.s_dlc;
         swap_data(&(ovsp_ram_elt->s_data[0]), ovsp_received_frames_tab[idx_to_rcv].s_data);

         if(is_ovsp_ls)
         {
            uod_bypass.uod_can_ovsp_rx_buffer_ls[idx_to_rcv].s_identifier = ovsp_received_frames_tab[idx_to_rcv].s_identifier;
            uod_bypass.uod_can_ovsp_rx_buffer_ls[idx_to_rcv].s_length = ovsp_received_frames_tab[idx_to_rcv].s_length;

            for (iter_data = (uint32_t)0; iter_data < OVSP_FRAME_TOT_LENGTH; iter_data++)
            {
                  uod_bypass.uod_can_ovsp_rx_buffer_ls[idx_to_rcv].s_data[iter_data] = ovsp_received_frames_tab[idx_to_rcv].s_data[iter_data];
            }
         }
         else
         {
            uod_bypass.uod_can_ovsp_rx_buffer_hs[idx_to_rcv].s_identifier = ovsp_received_frames_tab[idx_to_rcv].s_identifier;
            uod_bypass.uod_can_ovsp_rx_buffer_hs[idx_to_rcv].s_length = ovsp_received_frames_tab[idx_to_rcv].s_length;

            for (iter_data = (uint32_t)0; iter_data < OVSP_FRAME_TOT_LENGTH; iter_data++)
            {
               uod_bypass.uod_can_ovsp_rx_buffer_hs[idx_to_rcv].s_data[iter_data] = ovsp_received_frames_tab[idx_to_rcv].s_data[iter_data];
            }
         }

         /* Update FIFO fill level */
          p_ovsp_reg_descr->s_rxf1a.u_bit.s_f1ai = fifo_1_start_offset;

         total_nb_frame_received++;
      }

      /* Check there is a data in FIFO */
      if ((fifo_0_lvl == (uint32_t)0) && (fifo_1_lvl == (uint32_t)0))
      {
         flag_stop = e_found;
      }

      idx_to_rcv++;

   }
   while ((idx_to_rcv < OVSP_GET_DATA_MAX_FRAME) && (flag_stop == e_not_found) );

   /* If OVSP_LS */
   if(is_ovsp_ls)
   {
      /* Decode the get_data response frames from the OVSP_LS thanks to the ID and process it  */
      ovsp_get_data_ls_decode(total_nb_frame_received);
   }
   else
   {
      /* Decode the get_data response frames from the OVSP_LS thanks to the ID and process it  */
      ovsp_get_data_hs_decode(total_nb_frame_received);

   }

}

/* ---------- internal operation bodies: ------------------------------------ */
