/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : this function is used to retrieve the frames to transmit from
 * the shmem and write them in the can ram with the expected format
 * 1- retrieve the frames in shmem
 * 2- convert the frames format from shmem format to tx buffer format
 * 3- write the frames in can RAM
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
void can_write_put_msg_to_can_ram(ts_can_tx         * const ptr_src_shmem_can,
                                  uint32_t            const dest_can_ram_addr,
                                  ts_can_conf const * const ptr_can_conf,
                                  uint32_t            const id_elt_to_send,
                                  uint32_t            const fifo_elt_offset)
{
   uint32_t local_tmp; /*local variable used for the computation of ram address (cannot be done in 1time, rulechecker)*/
   ts_can_tx_buff_elt_t* p_can_ram_elt;
   /* variable used to convert data from shmem format into M_CAN TX buffer format */
   ts_can_tx_buff_elt_t  can_buff_tx_elt;
   /* Get physical address of free CAN RAM write element buffer */
   /* (fifo_elt_offset << CAN_FIFO_ELT_OFF) = space of 0x10 in address in RAM between each frame written */
   local_tmp = (dest_can_ram_addr + CAN_TX_CAN_OFF) +(fifo_elt_offset << CAN_FIFO_ELT_OFF);
   p_can_ram_elt = (ts_can_tx_buff_elt_t*)(local_tmp);

   /* Initialize local variable */
   can_buff_tx_elt.s_tx_buff_elt_f0.u_word = (uint32_t)0;
   can_buff_tx_elt.s_tx_buff_elt_f1.u_word = (uint32_t)0;

   /* Load std or xtd identifier */
   if (ptr_can_conf->s_can_type_id == e_can_02_a)
   {
      /* if std identifier (11 bits) is used : */
      can_buff_tx_elt.s_tx_buff_elt_f0.u_bit.s_xtd = (uint32_t)0;
      /* load std identifier */
      can_buff_tx_elt.s_tx_buff_elt_f0.u_bit.s_id = ptr_src_shmem_can->s_frames[id_elt_to_send].s_identifier
                                                    << CAN_STD_ID_SHIFT;
   }
   else
   {
      /* if xtd identifier (29 bits) is used : */
      can_buff_tx_elt.s_tx_buff_elt_f0.u_bit.s_xtd = (uint32_t)1;
      /* load xtd identifier */
      can_buff_tx_elt.s_tx_buff_elt_f0.u_bit.s_id = ptr_src_shmem_can->s_frames[id_elt_to_send].s_identifier;
   }
   /* for fadex always transmit data frame (rtr = 0) (no remote frame used) */
   can_buff_tx_elt.s_tx_buff_elt_f0.u_bit.s_rtr = (uint32_t)0;

   /* Load message markers value */
   can_buff_tx_elt.s_tx_buff_elt_f1.u_bit.s_mm = CAN_FRAME_MM_VAL;
   /* Load event TX policy value (0 Don't store Tx events) */
   can_buff_tx_elt.s_tx_buff_elt_f1.u_bit.s_efc = CAN_FRAME_EFC_VAL;
   /* Data length code, size of transmitted data frames in bytes */
   can_buff_tx_elt.s_tx_buff_elt_f1.u_bit.s_dlc = ptr_src_shmem_can->s_frames[id_elt_to_send].s_length;

   /* Write in CAN SRAM with 32 bits accesses */
   p_can_ram_elt->s_tx_buff_elt_f0.u_word = can_buff_tx_elt.s_tx_buff_elt_f0.u_word;
   /* Write in CAN SRAM with 32 bits accesses */
   p_can_ram_elt->s_tx_buff_elt_f1.u_word = can_buff_tx_elt.s_tx_buff_elt_f1.u_word;



   /* swap data endianess for the data part of the frames between shmem and CAN RAM */
   swap_data(ptr_src_shmem_can->s_frames[id_elt_to_send].s_data, p_can_ram_elt->s_data);

}



/* ---------- internal operation bodies: ------------------------------------ */
