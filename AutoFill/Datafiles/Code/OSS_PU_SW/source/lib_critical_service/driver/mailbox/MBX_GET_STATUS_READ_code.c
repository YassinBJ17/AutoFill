/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Mailbox Tx get status read function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "driver/mailbox/MBX_CFEX_public.h"
#include "driver/mailbox/MBX_HAL_public.h"
#include "driver/mailbox/MBX_REG_common.h"
#include "driver/mailbox/MBX_private.h"
#include "driver/mailbox/MAC_ETH_HAL_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* */
void MBX_GET_STATUS_READ( ts_MBX_HAL_STATS_TRANSFERT * const p_pt_stats )
{
   tu_MBX_RX_FIFO_STATUS_REG  v_fifo_status_value;
#ifdef CBIT_MBX
   tu_MAC_ETH_RX_STATUS_2_REG v_mac_eth_status_value;
   tu_RX_FIFO_CONTROL_REG     v_fifo_control_value;
   tu_RX_FIFO_STATUS_ACK_REG  v_rx_ack_value;
#endif

   MBX_READ_STATUS ( (CMN_IOSP_ID_t)e_CFEX_MBX_CONF_0, &v_fifo_status_value );

#ifdef CBIT_MBX
   MAC_ETH_READ_RX_STATUS2 ( (CMN_IOSP_ID_t)e_CFEX_MBX_CONF_0 , &v_mac_eth_status_value );
   /* No ACK: mac_eth */
   cbit_mbx_status.RX_status |= ( v_mac_eth_status_value.u_B.s_eth_rx_stat_frame_err_fcs << as_return_crc_err );
   cbit_mbx_status.RX_status |= ( v_mac_eth_status_value.u_B.s_eth_rx_stat_frame_err_sz  << as_return_sz_error );
   cbit_mbx_status.RX_status |= ( v_mac_eth_status_value.u_B.s_eth_rx_stat_frame_err_ifg << as_return_frmt_err );
   cbit_mbx_status.RX_status |= ( v_mac_eth_status_value.u_B.s_eth_rx_stat_frame_err_phy << as_return_no_frame );
#endif

   /* The length is refresh by the FEC Module once the BD is closed */
   if ( v_fifo_status_value.u_B.s_rx_fifo_empty != 1 )
   {
      /* Extract the frame */
      p_pt_stats->s_status = e_CMN_FLAG_COMPLETE ;

#ifdef CBIT_MBX
      /* Not empty but ( overflow or mac_eth pb found) => Frame lost */
      if( ( v_fifo_status_value.u_B.s_rx_fifo_overflow == 1 ) || ( v_mac_eth_status_value.u_R  != 0 ) )
      {
         /* 1: Remonter a l'AS le flag de panne */
         cbit_mbx_status.RX_status |= (uint32_t)( 1 << as_return_no_frame );

         /* 2: Flush de la RX FIFO */
         v_fifo_control_value.u_R = 0;
         v_fifo_control_value.u_B.s_rx_fifo_flush = 1;
         MBX_FIFO_RX_WRITE_CONTROL ( (CMN_IOSP_ID_t)e_CFEX_MBX_CONF_0, &v_fifo_control_value );

         v_rx_ack_value.u_R = 0;
         v_rx_ack_value.u_B.s_rx_fifo_flush_ack = 1;
         MBX_FIFO_RX_WRITE_STATUS_ACK ( (CMN_IOSP_ID_t)e_CFEX_MBX_CONF_0, &v_rx_ack_value );

         /* 3: Reinit du Datagramme UDP */
         ETH_UDP_Init();

         /* 4: Record the error in Log Area */
         /* TODO PAULO : No logbook available */

         /* Lost of frame */
         p_pt_stats->s_status = e_CMN_FLAG_NOT_COMPLETE;
      }

      if( v_fifo_status_value.u_B.s_rx_fifo_overflow == 1 )
      {
         /* 5: Acknowledge the status */
         v_rx_ack_value.u_R = 0;
         v_rx_ack_value.u_B.s_rx_fifo_overflow_ack = 1;
         MBX_FIFO_RX_WRITE_STATUS_ACK ( (CMN_IOSP_ID_t)e_CFEX_MBX_CONF_0, &v_rx_ack_value );
      }
#endif
   }

   else
   {
#ifdef CBIT_MBX
      /* Fifo is empty  Error found on MAC_ETH => Frame lost and not sent */
      if( v_mac_eth_status_value.u_R  != 0 )
      {
         /* 1: Remonter a l'AS le flag de panne */
         cbit_mbx_status.RX_status |= (uint32_t)( 1 << as_return_no_frame );

         /* 2: Flush de la TX FIFO CMD: Nothing to flush, fifo is empty */

         /* 3: Reinit du Datagramme UDP */
         ETH_UDP_Init();

         /* 4: Record the error in Log Area */
         /* TODO PAULO : No logbook available */

         /* 5: Acknowledge the status, No possibility to ack the mac_eth, is it done by itself ? */
      }
#endif
      /* Frame lost */
      p_pt_stats->s_status = e_CMN_FLAG_NOT_COMPLETE ;
   }
}

/* ---------- internal operation bodies: ------------------------------------ */
