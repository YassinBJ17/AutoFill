/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : OVSP get sw info command send
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "middleware/ovsp/ovsp_public.h"
#include "middleware/ovsp/ovsp_private.h"
#include "middleware/ovsp/ovsp_frame.h"
#include "memory/shared_memory_public.h"
#include "driver/can/can_critical_private.h"
#include "middleware/uod_bypass/uod_bypass_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-CANOVS-0030 */
void ovsp_get_sw_info_send(uint32_t const can_x_reg_addr, uint32_t const dest_can_ram_addr)
{
   uint8_t i;

   uint32_t local_tmp; /*local variable used for the computation of ram address (cannot be done in 1time, rulechecker)*/
   ts_can_tx_buff_elt_t* p_can_ram_elt;
   ts_can_frame* tmp_can_frame;
   ts_can_frame * uod_local_tx_monitor;
   /* variable used to convert data from shmem format into M_CAN TX buffer format */
   ts_can_tx_buff_elt_t  can_buff_tx_elt;
   /* Local variable definition */
   uint32_t       fifo_elt_offset;
   uint32_t       tx_fifo_lvl;
   uint32_t       is_fifo_full;
   uint32_t       j;

   /* Get physical address of free CAN RAM write element buffer */
   local_tmp = (dest_can_ram_addr + CAN_TX_CAN_OFF);
   p_can_ram_elt = (ts_can_tx_buff_elt_t*)(local_tmp);

   /* Initialize loop */
   fifo_elt_offset = (uint32_t)0; /* fifo start offset */
   tx_fifo_lvl     = (uint32_t)0; /* number of fifo free element */
   is_fifo_full   = OVSP_FIFO_NOT_FULL; /* FIFO initialise not full */

   /* Initialize local variable */
   can_buff_tx_elt.s_tx_buff_elt_f0.u_word = (uint32_t)0;
   can_buff_tx_elt.s_tx_buff_elt_f1.u_word = (uint32_t)0;

   get_sw_info_frame.s_identifier = (uint32_t)0;

   for(i= (uint8_t)0; i < OVSP_GETSWINFO_UNUSED_SIZE; i++)
   {
      get_sw_info_frame.s_unused[i] = (uint8_t)0;
   }

   get_sw_info_frame.s_oss_pu_comp_number = (uint8_t)1;
   get_sw_info_frame.s_length = OVSP_FRAME_TOT_LENGTH;

   tmp_can_frame = (ts_can_frame*)(&get_sw_info_frame);

   /* if can3 LS */
   if (can_x_reg_addr == 0xFFEEC000)
   {
      uod_local_tx_monitor = &(uod_bypass.uod_can_ovsp_tx_monitor_ls[uod_bypass.uod_can_ovsp_tx_lvl_monitor_ls]) ;
      uod_bypass.uod_can_ovsp_tx_lvl_monitor_ls++;
   }
   /* if can 4 HS */
   else
   {
      uod_local_tx_monitor = &(uod_bypass.uod_can_ovsp_tx_monitor_hs[uod_bypass.uod_can_ovsp_tx_lvl_monitor_hs]) ;
      uod_bypass.uod_can_ovsp_tx_lvl_monitor_hs++;
   }

   uod_local_tx_monitor->s_identifier = tmp_can_frame->s_identifier;
   uod_local_tx_monitor->s_length = tmp_can_frame->s_length;
   for (j = (uint32_t)0; j<(uint32_t)8; j++)
   {
      uod_local_tx_monitor->s_data[j] = tmp_can_frame->s_data[j];
   }


   /* Get TX FIFO level and detect an if fifo full */
   can_write_get_fifo_tx_lvl(can_x_reg_addr, &tx_fifo_lvl, &fifo_elt_offset, &is_fifo_full);

   /* is FIFO full ? */
   if (is_fifo_full == OVSP_FIFO_NOT_FULL)
   {
      /* Write message in CAN RAM buffer TX */
      can_buff_tx_elt.s_tx_buff_elt_f0.u_bit.s_xtd = (uint32_t)0;
      /* load std identifier */
      can_buff_tx_elt.s_tx_buff_elt_f0.u_bit.s_id = get_sw_info_frame.s_identifier << CAN_STD_ID_SHIFT;
   }
   /* for fadex always transmit data frame (rtr = 0) (no remote frame used) */
   can_buff_tx_elt.s_tx_buff_elt_f0.u_bit.s_rtr = (uint32_t)0;

   /* Load message markers value */
   can_buff_tx_elt.s_tx_buff_elt_f1.u_bit.s_mm = (uint32_t)0;
   /* Load event TX policy value (0 Don't store Tx events) */
   can_buff_tx_elt.s_tx_buff_elt_f1.u_bit.s_efc = (uint32_t)0;
   /* Data length code, size of transmitted data frames in bytes */
   can_buff_tx_elt.s_tx_buff_elt_f1.u_bit.s_dlc = get_sw_info_frame.s_length;

   /* Write in CAN SRAM with 32 bits accesses */
   p_can_ram_elt->s_tx_buff_elt_f0.u_word = can_buff_tx_elt.s_tx_buff_elt_f0.u_word;
   /* Write in CAN SRAM with 32 bits accesses */
   p_can_ram_elt->s_tx_buff_elt_f1.u_word = can_buff_tx_elt.s_tx_buff_elt_f1.u_word;

   /* swap data endianess for the data part of the frames between shmem and CAN RAM */
   swap_data(get_sw_info_frame.s_unused, p_can_ram_elt->s_data);

   /* Launch CAN transmission */
   can_write_start_tx(can_x_reg_addr, fifo_elt_offset);
}

/* ---------- internal operations: ------------------------------------------ */
