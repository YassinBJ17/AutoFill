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
#include "middleware/stack_ip/ETH_DEF_HEADER_common.h"
#if (ETH_UDP_ARP_ENTRY_SEARCH_CONF_ENABLE != 0 )
#include "middleware/stack_ip/ETH_ARP_common.h"
#endif

#include "libtools/memory/LIB_MEM_public.h"
#if (ETH_UDP_TIME_CONF_ENABLE != 0)
#include "libtools/time/LIB_TIME_public.h"
#endif

#define K_ETH_UDP_MINI_PACKET_SIZE ( sizeof( ts_ETH_EthernetHeader ) \
                                    + sizeof( ts_ETH_IP_Header )     \
                                    + sizeof( ts_ETH_UDP_Header ) )

#if (ETH_UDP_TIME_CONF_ENABLE != 0 )
CMN_SYSTEM_TIME_t    v_duration_udp_OnRecvcrc_time;
#endif
uint32_t dsp_debug;
void ETH_UDP_OnRecv ( const ts_CMN_IOSP_BUFFER * const p_Data )
{
   const ts_ETH_UDP_PacketHeader *  c_UDP_Packet_pt ;
   ts_ETH_UDP_RECEIVE_BUFF *        pt_port ;
   uint16_t                         v_chcksum ;
   uint32_t                         v_lenData ;
   ts_CMN_IOSP_BUFFER               v_DataBuff;
#if (ETH_UDP_ARP_ENTRY_SEARCH_CONF_ENABLE != 0 )
   ts_ETH_ARP_TableEntry *          pt_arp_entry;
#endif
   te_CMN_FLAG_QUESTION             v_found ;
#if (ETH_UDP_TIME_CONF_ENABLE != 0 )
   CMN_SYSTEM_TIME_t    v_start_time;
   CMN_SYSTEM_TIME_t    v_end_time;
#endif

   /* >RELAX<SYNCHRONe_C_Code_10.7>: No loss, size_t fits on an uint32_t */
   if ( p_Data->s_buffer_size <= (uint32_t)K_ETH_UDP_MINI_PACKET_SIZE )
   {
      v_ETH_UDP_ControlObj.s_UDPstats.s_packet_rx.s_nok++ ;
   }
   else
   {
      /* >RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1>: cast is safe and needed, buffer is a byte array */
      c_UDP_Packet_pt = (const ts_ETH_UDP_PacketHeader *) p_Data->s_buffer ;

      /* >RELAX<SYNCHRONe_C_Code_10.7>: No loss, uint16_t fits on an uint32_t */
      pt_port = ETH_UDP_GetReceivedBufferPort ( (uint32_t)c_UDP_Packet_pt->s_UDP_Header.s_UDP_DestinationPort ) ;

#if (ETH_UDP_ARP_ENTRY_SEARCH_CONF_ENABLE != 0 )
      /* >RELAX<SYNCHRONe_C_Code_10.7>: Operation is safe, pointer type is consistent */
      pt_arp_entry = ETH_ARP_SearchInTable(&c_UDP_Packet_pt->s_IP_Header.s_SourceAddress) ;
      /* go for checks */
#endif

      /*   (Port is not open ) OR (IP address has not been resolved) */
      /* >RELAX<SYNCHRONe_C_Code_10.7>: Operations are safe, pointers are compared to NULL */
#if (ETH_UDP_ARP_ENTRY_SEARCH_CONF_ENABLE != 0 )
      if ( ( pt_port == NULL ) || ( pt_arp_entry == NULL ) )
#else
      if ( pt_port == NULL )
#endif
      {
         v_ETH_UDP_ControlObj.s_UDPstats.s_packet_rx.s_nok++ ;
      }
      else
      {
         if (pt_port->s_PortNumber == 49800)
            dsp_debug+=1;

#if (ETH_UDP_ARP_ENTRY_SEARCH_CONF_ENABLE != 0 )
         v_found = ETH_DRV_IsSameMAC_ADDR ( &pt_arp_entry->s_PhysicalAddress ,
                                  &c_UDP_Packet_pt->s_MAC_Header.s_SourceHost ) ;
#else
         v_found = e_CMN_FLAG_YES;
#endif

         if ( v_found == e_CMN_FLAG_NO ) /* not the good MAC Address */
         {
            v_ETH_UDP_ControlObj.s_UDPstats.s_packet_rx.s_nok++ ;
         }
         else
         {
            ETH_UDP_SetDestOnReceivedBufferPort ( pt_port , (uint32_t)c_UDP_Packet_pt->s_UDP_Header.s_UDP_SourcePort , &c_UDP_Packet_pt->s_IP_Header.s_SourceAddress ) ;

            if ( p_Data->s_buffer_size > pt_port->s_MaxLen ) /* Size of the packet too wide */
            {
               v_ETH_UDP_ControlObj.s_UDPstats.s_packet_rx.s_nok++ ;
            }
            else
            {
               v_lenData =  p_Data->s_buffer_size  ;

               /* >RELAX<SYNCHRONe_C_Code_10.7>: No loss, size_t and uint16_t fit on uint32_t */
               if( v_lenData > ((uint32_t)c_UDP_Packet_pt->s_UDP_Header.s_UDP_Length + (uint32_t)sizeof(ts_ETH_IP_PacketHeader) ) )
               {
                  /* host has added some padding */
                  /* >RELAX<SYNCHRONe_C_Code_10.7>: No loss, size_t and uint16_t fit on uint32_t */
                  v_lenData = (uint32_t)c_UDP_Packet_pt->s_UDP_Header.s_UDP_Length + (uint32_t)sizeof(ts_ETH_IP_PacketHeader) ;
               }

               /* >RELAX<SYNCHRONe_C_Code_17.4>: operation is safe, it's equivalent as an array indexing */
               v_DataBuff.s_buffer = p_Data->s_buffer + sizeof(ts_ETH_UDP_PacketHeader) ;
               /* >RELAX<SYNCHRONe_C_Code_10.7>: No loss, size_t fits on an uint32_t */
               v_DataBuff.s_buffer_size = v_lenData - (uint32_t)sizeof(ts_ETH_UDP_PacketHeader)  ;

               /* check sum check */
#if (ETH_UDP_TIME_CONF_ENABLE != 0 )
               LIBT_TIME_GET( &v_start_time );
#endif
#if (ETH_UDP_CONF_ENABLE_CHK_RX != 0 )
               v_chcksum = ETH_UDP_Checksum( &c_UDP_Packet_pt->s_IP_Header.s_SourceAddress,
                                             &c_UDP_Packet_pt->s_IP_Header.s_DestinationAddress,
                                             c_UDP_Packet_pt,
                                             &v_DataBuff);
#else
               v_chcksum = c_UDP_Packet_pt->s_UDP_Header.s_UDP_Checksum;
#endif
#if (ETH_UDP_TIME_CONF_ENABLE != 0 )
               LIBT_TIME_GET( &v_end_time );
               v_duration_udp_OnRecvcrc_time = v_end_time - v_start_time;
#endif

               if ( v_chcksum != c_UDP_Packet_pt->s_UDP_Header.s_UDP_Checksum )
               {
                  v_ETH_UDP_ControlObj.s_UDPstats.s_packet_rx.s_nok++ ;
               }
               else
               {
                  v_ETH_UDP_ControlObj.s_UDPstats.s_packet_rx.s_handled++ ;
                  pt_port->s_LenReceived = v_lenData;

                  /* >RELAX<SYNCHRONe_C_Code_10.7>: cast is safe, the pointer is simply casted as const */
                  LIB_MEM_CPY ( (int8_t* const) pt_port->s_BufReception ,
                                p_Data->s_buffer ,
                                v_lenData ) ;
               }
            }
         }
      }
   }
}
