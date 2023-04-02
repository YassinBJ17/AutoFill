/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION :
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/stack_ip/ETH_COMM_private.h"
#include "middleware/stack_ip/ETH_COMM_public.h"
#include "middleware/stack_ip/ETH_UDP_public.h"
#include "middleware/stack_ip/ETH_UDP_private.h"
#include "middleware/stack_ip/ETH_IP_private.h"
#include "middleware/stack_ip/ETH_ARP_public.h"

#include "libtools/memory/LIB_MEM_public.h"
#include "type/common_type.h"

/* ---------- function bodies: ---------------------------------------------- */

/*!@brief Write data to the communication link.
 *
 * This function must not be blocking.
 *
 * The user project driver might have to bufferize the data before sending them.
 *
 * Therefore, the status is not necessarily available when returning from this function.
 * In this case, the user project is responsible for memorizing the status, and for returning it at the next com_write() call.
 *
 * @param[in]  out_msg       Buffer containing the data to write on the communication link
 * @param[in]  nb_bytes      Number of bytes to write
 * @return The status of the write operation
 */
t_eth_comm_status ETH_COMM_write( const uint8_t *out_msg,
                                  uint32_t nb_bytes,
                                  uint16_t p_port_src,
                                  uint16_t p_port_dst,
                                  uint32_t p_ip_dst,
                                  uint32_t * p_out_tx_status )
{
   t_eth_comm_status v_eth_comm_status;
   te_ETH_UDP_Status v_status;
   ts_ETH_UDP_BUFF_STATS v_stats;
   ts_CMN_IOSP_BUFFER v_buff;
   ts_ETH_UDP_RECEIVE_BUFF *pt_port ;
   uint32_t v_port_dst;
   tu_ETH_TX_STATUS v_eth_tx_status ;

   v_eth_comm_status = ETH_COMM_STATUS_OK;

   v_eth_tx_status.u_R = ETH_UDP_WRITE_GET_STATUS ( &v_stats );

   if ( v_stats.s_UDP_done == v_stats.s_UDP_len )
   {
      v_buff.s_buffer = (int8_t *)out_msg;
      v_buff.s_buffer_size = (uint32_t)nb_bytes;

      pt_port = ETH_UDP_GetReceivedBufferPort ( p_port_src ) ;

      if ( pt_port == NULL )
      {
         /*
          * No Communication Initiated by Rx on this Port SRC - Tx only
          */
         ethUdpInfo.s_IdDest.s_IpAddress.u_IP = p_ip_dst;
         v_port_dst =  p_port_dst;
      }
      else
      {
         if ( p_port_src == ethUdpInfo.s_SrcPortUOD )
         {
            /*
             * Communication Initiated by Rx - For UOD, IP/Port from Client is used for answer
             */
            ethUdpInfo.s_IdDest.s_IpAddress.u_IP = pt_port->s_IP.u_IP;
            v_port_dst = pt_port->s_Port;
         }
         else
         {
            /*
             * Communication Initiated by Rx - For Others communications than UOD, IP/Port is not used for answer
             */
            ethUdpInfo.s_IdDest.s_IpAddress.u_IP = p_ip_dst;
            v_port_dst =  p_port_dst;
         }
      }

      /* Resolve ARP for MAC Adress */
      /*v_eth_arp_resol_status = ETH_ARP_Resolve( &ethUdpInfo.s_IdDest.s_IpAddress, &ethUdpInfo.s_IdDest.s_HwAddress );*/

      /*if ( ( v_port_dst != K_ETH_UDP_PORT_INVALID ) &&*/
      /*     ( p_port_src != K_ETH_UDP_PORT_INVALID ) &&*/
      /*     ( v_eth_arp_resol_status == e_ETH_ARP_RESOL_OK ) )*/
      {
         v_eth_tx_status.u_R = ETH_UDP_WRITE( v_port_dst, &(ethUdpInfo.s_IdDest), p_port_src, &v_buff, &v_status );

         if ( ( v_eth_tx_status.u_B.s_tx_cmd_fifo_fifo_ovf_err == 1 ) || ( v_eth_tx_status.u_B.s_tx_cmd_fifo_fifo_ovf_err == 1 ) )
         {
            *p_out_tx_status = *p_out_tx_status | ETH_TX_FIFO_OVF_ERR ;
            v_eth_comm_status = ETH_COMM_STATUS_FAILURE ;
         }
      }
      /*else*/
      /*{*/
      /*   v_eth_comm_status = ETH_COMM_STATUS_FAILURE ;*/
      /*}*/
   }
   else
   {
      if ( (v_eth_tx_status.u_B.s_tx_cmd_fifo_fifo_ovf_err == 1 ) || (v_eth_tx_status.u_B.s_tx_cmd_fifo_fifo_ovf_err == 1 ) )
      {
         *p_out_tx_status = *p_out_tx_status | ETH_TX_FIFO_OVF_ERR ;
         v_eth_comm_status = ETH_COMM_STATUS_FAILURE ;
      }
   }
   return v_eth_comm_status;
}



