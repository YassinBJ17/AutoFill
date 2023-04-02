/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : this function is used to transmit the frames from the shared *
 * memory through the CAN, the process is :                                   *
 * 1- check if the the Tx FIFO is full or not                                 *
 * 2- if not write the frames from SHMEM to the can RAM                       *
 * 3- Set the MPC register to start the transmission of the frames            *
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "driver/can/can_critical_private.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */

/* ---------- Function description: ----------------------------------------- */
/**/
/**/
/**/
/**/
/**/
/**/

/* Implements REQ_FADEX_OS_SRD-CAN-0040 */
/* Implements REQ_FADEX_OS_SRD-CAN-0050 */
void can_write( ts_can_tx         * const ptr_src_shmem_can,
                uint32_t            const dest_can_ram_addr,
                uint32_t            const can_x_reg_addr,
                ts_can_conf const * const ptr_can_conf)
{
   /* Local variable definition */
   uint32_t       fifo_elt_offset;
   uint32_t       tx_fifo_lvl;
   uint32_t       id_elt_to_send;
   uint32_t       is_fifo_full;
   uint32_t       nb_frames_to_write;

   /* Initialize loop */
   id_elt_to_send  = (uint32_t)0;
   fifo_elt_offset = (uint32_t)0; /* fifo start offset */
   tx_fifo_lvl     = (uint32_t)0; /* number of fifo free element */
   is_fifo_full   = CAN_FIFO_NOT_FULL; /* FIFO initialise not full */

   nb_frames_to_write = ptr_src_shmem_can->s_frames_nb;


   do
   {
      /* Get TX FIFO level and detect an if fifo full */
      can_write_get_fifo_tx_lvl(can_x_reg_addr, &tx_fifo_lvl, &fifo_elt_offset, &is_fifo_full);

      /* is FIFO full ? */
      if (is_fifo_full == CAN_FIFO_NOT_FULL)
      {
         /* Write message in CAN RAM buffer TX */
         can_write_put_msg_to_can_ram(ptr_src_shmem_can,
                                      dest_can_ram_addr,
                                      ptr_can_conf,
                                      id_elt_to_send,
                                      fifo_elt_offset);

         /* Launch CAN transmission */
         can_write_start_tx(can_x_reg_addr, fifo_elt_offset);
      }
      id_elt_to_send++;
   }
   while ((id_elt_to_send < nb_frames_to_write) && (is_fifo_full == CAN_FIFO_NOT_FULL));

   /* reset the number of frames to send to 0 in shmem */
   ptr_src_shmem_can->s_frames_nb = (uint32_t)0;
   /* check the status of send frames */
   can_write_check_tx_status(can_x_reg_addr, ptr_src_shmem_can);
}

/* ---------- internal operation bodies: ------------------------------------ */
