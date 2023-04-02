/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION :
 * -------------------------------------------------------------------------- */

#include "middleware/stack_ip/ETH_UDP_public.h"
#include "middleware/stack_ip/ETH_UDP_common.h"
#include "middleware/stack_ip/ETH_UDP_private.h"
#include "middleware/stack_ip/ETH_UDP_conf.h"

#include "middleware/stack_ip/ETH_common.h"
#include "middleware/stack_ip/ETH_IP_common.h"

#if (ETH_UDP_TIME_CONF_ENABLE != 0)
#include "libtools/time/LIB_TIME_public.h"
#endif

/* Maximum datagram size after reassembly */
#define K_MAX_DATA_SIZE_TO_SEND (8188 + 4)

void
ETH_UDP_SendTo_L_Chck_Send ( const tu_ETH_IPAddr* const p_srcIPAddr ,
                             const tu_ETH_IPAddr* const p_destIPAddr ) ;

#if (ETH_UDP_TIME_CONF_ENABLE != 0)
CMN_SYSTEM_TIME_t    v_duration_udp_crc_time;
#endif

/*---------------------------------------------------------------------------*/
/* NAME: ETH_DRV_SendTo()*/
/*---------------------------------------------------------------------------*/
/* PURPOSE:  generic transmit routine to interface with device layer as follows:*/
/* 1) create the udp and ip header*/
/* 2) concatenate the information to the beginning of the data buffer*/
/* 3) call the driver to send the packet*/
/*---------------------------------------------------------------------------*/
/* INPUTS/OUTPUTS: See function declaration*/
/*---------------------------------------------------------------------------*/
/* ASSUMPTIONS/LIMITATIONS:*/
/* At this layer, we assume the data is in the byte order that we want.*/
/**/
/* Also, the data is not being padded with zeroes.  Underflow can occur*/
/* if the ethernet device is not set to automatically pad the data*/
/**/
/* Finally, it assumes that the ethernet packet is word-aligned.  Otherwise*/
/* all of the two-byte writes would have to be done using a temporary*/
/* variable and writing MSB and LSB independently*/
/*---------------------------------------------------------------------------*/
uint32_t ETH_UDP_WRITE ( uint32_t                         const p_Destport ,
                     const ts_ETH_EthernetAddress *   const p_Destaddr ,
                     uint32_t                         const p_SrcPort ,
                     const ts_CMN_IOSP_BUFFER *       const p_data ,
                     te_ETH_UDP_Status *              const p_status )
{
   uint32_t v_eth_tx_status ;
   const ts_ETH_EthernetAddress *   c_OwnAddr_pt ;
   ts_CMN_IOSP_BUFFER               v_buff ;
#if (ETH_UDP_TIME_CONF_ENABLE != 0)
   CMN_SYSTEM_TIME_t    v_start_time;
   CMN_SYSTEM_TIME_t    v_end_time;
#endif

   /* Initialize local variables */
   /* >RELAX<SYNCHRONe_C_Code_10.7>: Operation is safe, no precision is lost */
   c_OwnAddr_pt = &v_ETH_DRV_EtherOwnAddr ;

   v_ETH_UDP_ControlObj.s_UDPstats.s_packet_tx.s_handled++ ;
   *p_status = e_ETH_UDP_OK ;


   /* Build the UDP header*/
   /* {{RELAX<SYNCHRONe_C_Code_10.7>: No loss, a port number fits on an uint16_t (less or equal than 65535) */
   v_ETH_UDP_ControlObj.s_TxHeaderBuff.s_UDP_Header.s_UDP_SourcePort = (uint16_t) p_SrcPort ;
   v_ETH_UDP_ControlObj.s_TxHeaderBuff.s_UDP_Header.s_UDP_DestinationPort = (uint16_t) p_Destport ;
   /* }}RELAX<SYNCHRONe_C_Code_10.7> */
   /* >RELAX<SYNCHRONe_C_Code_10.7>: if (s_buffer_size + 8) is less than 65535, there is no loss */
   v_ETH_UDP_ControlObj.s_TxHeaderBuff.s_UDP_Header.s_UDP_Length = (uint16_t)p_data->s_buffer_size + (uint16_t)sizeof(ts_ETH_UDP_Header) ;

   /* Calculate UDP header checksum*/
   v_ETH_UDP_ControlObj.s_TxHeaderBuff.s_UDP_Header.s_UDP_Checksum = (uint16_t)0 ; /* FUDP checksum is not used  */
#if (ETH_UDP_TIME_CONF_ENABLE != 0)
   LIBT_TIME_GET( &v_start_time );
#endif
#if (ETH_UDP_CONF_ENABLE_CHK_TX != 0 )
   v_ETH_UDP_ControlObj.s_TxHeaderBuff.s_UDP_Header.s_UDP_Checksum =
            ETH_UDP_Checksum ( &c_OwnAddr_pt->s_IpAddress ,
                               &p_Destaddr->s_IpAddress ,
                               &v_ETH_UDP_ControlObj.s_TxHeaderBuff ,
                               p_data ) ;
#else
   v_ETH_UDP_ControlObj.s_TxHeaderBuff.s_UDP_Header.s_UDP_Checksum = 0;
#endif
#if (ETH_UDP_TIME_CONF_ENABLE != 0 )
   LIBT_TIME_GET( &v_end_time );
   v_duration_udp_crc_time = v_end_time - v_start_time;
#endif


   /* >RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1>: cast is safe, buffer is handled as a byte array */
   v_buff.s_buffer = (int8_t*) ( &v_ETH_UDP_ControlObj.s_TxHeaderBuff ) ;
   /* >RELAX<SYNCHRONe_C_Code_10.7>: No loss, size_t fits on an uint32_t */
   v_buff.s_buffer_size = (uint32_t)sizeof(ts_ETH_UDP_PacketHeader) ;

   v_eth_tx_status = ETH_IP_SEND ( p_Destaddr , e_ETH_IP_PROTO_UDP , &v_buff , p_data ) ;

   return v_eth_tx_status;
}
