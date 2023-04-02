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
void can_read_conv_rx_frame(ts_can_rx_buff_elt_t    * src_can_ram_frame,
                            ts_can_frame      * const dest_can_frame_rx_tab,
                            ts_can_conf const * const ptr_can_conf)
{
   /* Load std or xtd identifier */
   if (ptr_can_conf->s_can_type_id == e_can_02_a)
   {
      /* Load std frame identifier */
      dest_can_frame_rx_tab->s_identifier = ((src_can_ram_frame->s_rx_buff_elt_r0.u_word >> CAN_STD_ID_SHIFT) &
                                  CAN_FRAME_STD_ID_MASK);
   }
   else
   {
      /* Load xtd frame identifier */
      dest_can_frame_rx_tab->s_identifier = src_can_ram_frame->s_rx_buff_elt_r0.u_word & CAN_FRAME_XTD_ID_MASK;
   }

   /* Load data size */
   dest_can_frame_rx_tab->s_length = src_can_ram_frame->s_rx_buff_elt_r1.u_bit.s_dlc;

   /* switch the endianess of the data part (src = CAN RAM / dest = shared mem) */
   swap_data(&(src_can_ram_frame->s_data[0]),
                     dest_can_frame_rx_tab->s_data);
}

/* ---------- internal operation bodies: ------------------------------------ */
