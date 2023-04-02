/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Mailbox Rx read size data function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "driver/mailbox/MBX_CFEX_public.h"
#include "driver/mailbox/MBX_HAL_public.h"
#include "driver/mailbox/MBX_REG_common.h"
#include "driver/mailbox/MBX_private.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* */
void MBX_FIFO_READ_SIZE_DATA ( CMN_IOSP_ID_t const p_MBX_FIFO_conf_id,
                               tu_RX_FIRST_DATA_REG * const p_rx_first_data )
{
   /* Local variable declaration */
   volatile ts_MBX_RX_REG *        pt_mbx_reg_descr;
   volatile tu_RX_FIRST_DATA_REG   v_data_read;

#ifdef CBIT_MBX
   tu_MBX_RX_FIFO_STATUS_REG      v_rx_fifo_status_value;
   tu_RX_FIFO_CONTROL_REG         v_fifo_control_value;
   tu_RX_FIFO_STATUS_ACK_REG      v_rx_ack_value;
#endif

   /* Local variable initialization */
   /* */

   /* Get the MBX register descriptor */
   /* >RELAX<SYNCHRONe_C_Code_10.7> No loss of precision. The structure type 'ts_MBX_RX_REG' is tailor-made for the registers starting at this address.  */
   pt_mbx_reg_descr = (ts_MBX_RX_REG volatile *)c_MBX_CFEX_CONFIGURATION_tab[p_MBX_FIFO_conf_id].s_mbx_rx_fifo_address;

   /* Read */
   v_data_read = (tu_RX_FIRST_DATA_REG)pt_mbx_reg_descr->s_RX_DATA_REG;

   /* Set tkeep (offset)  */
   p_rx_first_data->u_B.s_rx_tkeep = v_data_read.u_B.s_rx_tkeep ;

   /* Set size */
   p_rx_first_data->u_B.s_rx_tsize = v_data_read.u_B.s_rx_tsize ;

#ifdef CBIT_MBX
   MBX_READ_STATUS ( (CMN_IOSP_ID_t)e_CFEX_MBX_CONF_0 , &v_rx_fifo_status_value );

   /* 1: In case of single bitter detected by FPGA */
   if( v_rx_fifo_status_value.u_B.s_rx_fifo_single_biterr == 1 )
   {

      /* 1: Remonter le flag de panne */
      cbit_mbx_status.RX_status |= v_rx_fifo_status_value.u_B.s_rx_fifo_single_biterr << as_return_mem_corr;
      cbit_mbx_status.RX_status |= v_rx_fifo_status_value.u_B.s_rx_fifo_single_biterr << as_return_no_frame;

      /* 2: Acknowledge the status */
      v_rx_ack_value.u_R = 0;
      v_rx_ack_value.u_B.s_rx_fifo_biterr_ack = 1;
      MBX_FIFO_RX_WRITE_STATUS_ACK ( p_MBX_FIFO_conf_id, &v_rx_ack_value );
   }

   /* 2: In case of double bitter detected by FPGA */
   if( v_rx_fifo_status_value.u_B.s_rx_fifo_double_biterr == 1 )
   {
      /* 1: Remonter a l'AS le flag de panne */
      cbit_mbx_status.RX_status |= v_rx_fifo_status_value.u_B.s_rx_fifo_double_biterr << as_return_mem_corr;
      cbit_mbx_status.RX_status |= v_rx_fifo_status_value.u_B.s_rx_fifo_double_biterr << as_return_no_frame;

      /* 2: Flush de la TX FIFO CMD */
      /*
      * Flush tx fifo
      */
      v_fifo_control_value.u_R = 0;
      v_fifo_control_value.u_B.s_rx_fifo_flush = 1;
      MBX_FIFO_RX_WRITE_CONTROL ( p_MBX_FIFO_conf_id, &v_fifo_control_value );

      v_rx_ack_value.u_R = 0;
      v_rx_ack_value.u_B.s_rx_fifo_flush_ack = 1;
      MBX_FIFO_RX_WRITE_STATUS_ACK ( p_MBX_FIFO_conf_id, &v_rx_ack_value );

      /* 3: Reinit du Datagramme UDP */
      ETH_UDP_Init(); /* From ETH_UDP_Init */

      /* 4: Record the error in Log Area */
      /* TODO PAULO : No logbook available */

      /* 5: Acknowledge the status */
      v_rx_ack_value.u_R = 0;
      v_rx_ack_value.u_B.s_rx_fifo_biterr_ack = 1;
      MBX_FIFO_RX_WRITE_STATUS_ACK ( p_MBX_FIFO_conf_id, &v_rx_ack_value );
   }

   /*Set final status of RX fifo */
   if ( cbit_mbx_status.RX_status == 0 )
   {
      cbit_mbx_status.RX_status |= 1ul;
   }
#endif
}

/* ---------- internal operation bodies: ------------------------------------ */
