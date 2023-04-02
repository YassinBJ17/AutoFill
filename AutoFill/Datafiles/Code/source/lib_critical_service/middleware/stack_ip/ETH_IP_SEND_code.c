/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION :
 * -------------------------------------------------------------------------- */

#include "middleware/stack_ip/ETH_IP_common.h"
#include "middleware/stack_ip/ETH_IP_private.h"
#include "middleware/stack_ip/ETH_common.h"
#include "middleware/stack_ip/ETH_IP_conf.h"
#include "middleware/stack_ip/ETH_DEF_HEADER_common.h"

#if (ETH_IP_TIME_CONF_ENABLE != 0)
#include "libtools/time/LIB_TIME_public.h"
#endif

#if (ETH_IP_TIME_CONF_ENABLE != 0)
   CMN_SYSTEM_TIME_t    v_duration_ip_Send_crc_time;
#endif

uint32_t ETH_IP_SEND ( const ts_ETH_EthernetAddress *  const p_dest ,
                   te_ETH_IP_PROTO                 const p_protocolType ,
                   const ts_CMN_IOSP_BUFFER *      const p_header ,
                   const ts_CMN_IOSP_BUFFER *      const p_data )
{
   uint32_t v_eth_tx_status;
   ts_ETH_IP_Header *   pt_IPHeader ;
   ts_CMN_IOSP_BUFFER   v_data ;
#if (ETH_IP_TIME_CONF_ENABLE != 0)
   CMN_SYSTEM_TIME_t    v_start_time;
   CMN_SYSTEM_TIME_t    v_end_time;
#endif

   v_eth_tx_status = 0u ;
   v_data.s_buffer_size = 0ul ;

   /* >RELAX<SYNCHRONe_C_Code_10.7>: Operation is safe, pointer is compared to NULL */
   if ( p_header == NULL )
   {
      /* direct sending */
      if ( p_data->s_buffer_size > K_ETH_MAX_ENET_PACKET_SIZE )
      {
         v_ETH_IP_ControlObj.s_IPstats.s_packet_tx.s_nok ++ ;
      }
      else
      {
         /* sending frame without fragementation */
         v_data.s_buffer = p_data->s_buffer ;
         v_data.s_buffer_size = p_data->s_buffer_size ;

         ETH_IP_Build_SingleFrame ( &p_dest->s_IpAddress ,
                                    p_data ) ;
      }
   }
   else
   {
      if ( v_ETH_IP_ControlObj.s_TxFragment.s_nbLeftToSent != 0UL ) /* using fragmentation which is inuse. */
      {
         v_ETH_IP_ControlObj.s_IPstats.s_packet_tx.s_dropped++ ;
      }
      else /* using fragmentation buffer: note that p_header is not null */
      {
         v_ETH_IP_ControlObj.s_IPstats.s_packet_tx.s_handled++ ;

         ETH_IP_Build_MultiFrame ( &p_dest->s_IpAddress ,
                                   p_header,
                                   p_data,
                                   &v_data ) ;
      }
   }

   if ( v_data.s_buffer_size > 0UL ) /*TODO gestion de fragments ?*/
   {
      /* adding the protocol */
      /* >RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1,SYNCHRONe_C_Code_17.4>: cast is safe, buffer is handled as a byte array, and shifted over header */
      pt_IPHeader = (ts_ETH_IP_Header *) ( v_data.s_buffer + sizeof(ts_ETH_EthernetHeader) ) ;
      /* >RELAX<SYNCHRONe_C_Code_10.7>: No loss, this enum fits on an uint8_t */
      pt_IPHeader->s_IP_Protocol = (uint8_t) p_protocolType ;

      /* Calculate the IP header checksum*/
      pt_IPHeader->s_IP_Checksum = (uint16_t)0 ;
      /* >RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1>: cast is safe, buffer is handled as a half-word array */
#if (ETH_IP_TIME_CONF_ENABLE != 0 )
        LIBT_TIME_GET( &v_start_time );
#endif
#if (ETH_IP_CONF_ENABLE_CHK != 0 )
      pt_IPHeader->s_IP_Checksum = ETH_IP_InCheckSum ( (uint16_t *) pt_IPHeader ,
      /* >RELAX<SYNCHRONe_C_Code_10.7>: No loss, size_t fits on an uint32_t */
                                                       (uint32_t)sizeof(ts_ETH_IP_Header) ) ;
#else
      pt_IPHeader->s_IP_Checksum = 0;
#endif
#if (ETH_IP_TIME_CONF_ENABLE != 0)
      LIBT_TIME_GET( &v_end_time );
      v_duration_ip_Send_crc_time = v_end_time - v_start_time;
#endif

      v_eth_tx_status = ETH_DRV_SEND_FRAME ( &p_dest->s_HwAddress , e_ETH_PROTO_IP , &v_data ) ;
   }

   return v_eth_tx_status;
}
