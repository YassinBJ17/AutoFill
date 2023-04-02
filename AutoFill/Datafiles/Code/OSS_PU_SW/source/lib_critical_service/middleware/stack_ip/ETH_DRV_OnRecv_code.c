/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION :
 * -------------------------------------------------------------------------- */

#include "middleware/stack_ip/ETH_common.h"
#include "middleware/stack_ip/ETH_private.h"
#include "middleware/stack_ip/ETH_IP_common.h"
#include "middleware/stack_ip/ETH_UDP_common.h"
#include "middleware/stack_ip/ETH_ARP_common.h"
#include "middleware/stack_ip/ETH_ICMP_common.h"

/*---------------------------------------------------------------------------*/
/* NAME: ETH_DRV_OnRecv()*/
/*---------------------------------------------------------------------------*/
/* PURPOSE:  This is called by the driver level software to store a received*/
/* packet in the correct FIFO. Currently there are only 3 FIFO's supported:*/
/* (ARP, ICMP and UDP).*/
/*---------------------------------------------------------------------------*/
/* INPUTS/OUTPUTS: See function declaration*/
/*---------------------------------------------------------------------------*/
/* ASSUMPTIONS/LIMITATIONS: None.*/
/*---------------------------------------------------------------------------*/

void ETH_DRV_OnRecv ( const ts_CMN_IOSP_BUFFER * const p_Data ,
                      te_CMN_FLAG_QUESTION       const p_broadcast )
{
   const ts_ETH_EthernetHeader * c_EthHeader_pt ;
   const ts_ETH_IP_Header *      c_IPHeader_pt ;
   ts_CMN_IOSP_BUFFER            v_realBuffer ;
   uint16_t                      v_value ;

   /* >RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1>: cast needed because buffer is composed of bytes */
   c_EthHeader_pt = (const ts_ETH_EthernetHeader *) p_Data->s_buffer ;
   v_value = c_EthHeader_pt->s_ProtocolType ;

   /*  process ARP messages*/
   /* >RELAX<SYNCHRONe_C_Code_10.7> No loss, enum value fits on uint16_t */
   if ( (uint16_t)e_ETH_PROTO_ARP == v_value )
   {
      v_ETH_DRV_ControlETH.s_ETHstats.s_packet_rx.s_handled++ ;
      ETH_ARP_OnRecv ( p_Data ) ;
   }
   else
   {
      /* >RELAX<SYNCHRONe_C_Code_10.7> No loss, enum value fits on uint16_t */
      if ( (uint16_t)e_ETH_PROTO_IP == v_value )
      {
         if ( p_broadcast == e_CMN_FLAG_YES )/* no broadcast authorized on IP packet */
         {
            v_ETH_DRV_ControlETH.s_ETHstats.s_packet_rx.s_nok++ ;
         }
         else
         {
            ETH_IP_Manage ( p_Data ,
                            &v_realBuffer ) ;

            if ( v_realBuffer.s_buffer_size > 0UL )
            {
               /* >RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1,SYNCHRONe_C_Code_17.4>: cast and operations needed because buffer is composed of bytes */
               c_IPHeader_pt = (const ts_ETH_IP_Header *) ( v_realBuffer.s_buffer + sizeof(ts_ETH_EthernetHeader) ) ;

               /* >RELAX<SYNCHRONe_C_Code_10.7> No loss, uint8_t fits on uint16_t */
               v_value = (uint16_t)c_IPHeader_pt->s_IP_Protocol ;

               /* Process ICMP packets*/
               switch ( v_value )
               {
                  /* >RELAX<SYNCHRONe_C_Code_10.7> No loss, enum value fits on uint16_t */
                  case ( (uint16_t)e_ETH_IP_PROTO_ICMP ):
                     v_ETH_DRV_ControlETH.s_ETHstats.s_packet_rx.s_handled++ ;
                     ETH_ICMP_OnRecv ( &v_realBuffer ) ;
                     break;
                  /* >RELAX<SYNCHRONe_C_Code_10.7> No loss, enum value fits on uint16_t */
                  case ( (uint16_t)e_ETH_IP_PROTO_UDP ):
                     v_ETH_DRV_ControlETH.s_ETHstats.s_packet_rx.s_handled++ ;
                     ETH_UDP_OnRecv ( &v_realBuffer ) ;
                     break;
                  default:
                     v_ETH_DRV_ControlETH.s_ETHstats.s_packet_rx.s_nok++ ;
                     break;
               }
            }
            /* NO ELSE : the else is a packet has been dropped by the ETH_IP  : ignore it  */
         }
      }/* if IP/UDP packet*/
      else
      {
         v_ETH_DRV_ControlETH.s_ETHstats.s_packet_rx.s_nok++ ;
      }
   }
}
