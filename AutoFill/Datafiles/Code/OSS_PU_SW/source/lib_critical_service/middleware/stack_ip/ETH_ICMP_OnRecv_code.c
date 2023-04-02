/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION :
 * -------------------------------------------------------------------------- */

#include "middleware/stack_ip/ETH_ICMP_private.h"
#include "middleware/stack_ip/ETH_ICMP_common.h"
#include "middleware/stack_ip/ETH_ICMP_conf.h"
#include "middleware/stack_ip/ETH_IP_common.h"
#include "middleware/stack_ip/ETH_DEF_HEADER_common.h"

#if (ETH_ICMP_TIME_CONF_ENABLE != 0)
#include "libtools/time/LIB_TIME_public.h"
#endif

#define K_ETH_ICMP_MINI_PACKET_SIZE ( sizeof ( ts_ETH_EthernetHeader ) + sizeof ( ts_ETH_IP_Header ) + sizeof ( ts_ETH_ICMP_Header )  )

#if (ETH_ICMP_TIME_CONF_ENABLE != 0)
   CMN_SYSTEM_TIME_t    v_duration_icmp_OnRecv_crc_time;
#endif


/*---------------------------------------------------------------------------*/
/* NAME: ETH_ICMP_HandleICMP()*/
/*---------------------------------------------------------------------------*/
/* PURPOSE: Process an incoming ICMP packet*/
/*---------------------------------------------------------------------------*/
/* INPUTS/OUTPUTS: See function declaration*/
/*---------------------------------------------------------------------------*/
/* ASSUMPTIONS/LIMITATIONS: None.*/
/*---------------------------------------------------------------------------*/


void ETH_ICMP_OnRecv ( const ts_CMN_IOSP_BUFFER * const p_Data )
{
   ts_ETH_ICMP_Packet * v_Pckt_pt ;
#if (ETH_ICMP_TIME_CONF_ENABLE != 0)
   CMN_SYSTEM_TIME_t    v_start_time;
   CMN_SYSTEM_TIME_t    v_end_time;
#endif
   /* TODO Integration
    * LIB_MEM CPY pour eviter de changer le checksum dans le buffer source
    * const ts_ETH_ICMP_Packet * c_Pckt_pt ;
   *  c_Pckt_pt = (const ts_ETH_ICMP_Packet *) p_Data->s_buffer ;
    */
   uint16_t v_checksum ;
   uint16_t v_icmp_checksum;

   /* >RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1>: cast needed, buffer is composed of bytes */
   v_Pckt_pt = (ts_ETH_ICMP_Packet *) p_Data->s_buffer ;

   /* >RELAX<SYNCHRONe_C_Code_10.7> No loss, size_t fits on an uint32_t */
   if ( p_Data->s_buffer_size > (uint32_t) K_ETH_ICMP_MINI_PACKET_SIZE )
   {
      v_checksum = v_Pckt_pt->s_ICMP_ICMPHeader.s_Checksum,
      v_Pckt_pt->s_ICMP_ICMPHeader.s_Checksum = 0;
      /* >RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1>: cast is only used to test if checksum is equal to zero */
#if (ETH_ICMP_TIME_CONF_ENABLE != 0 )
      LIBT_TIME_GET( &v_start_time );
#endif
#if (ETH_ICMP_CONF_ENABLE_CHK != 0 )
      v_icmp_checksum =  ETH_IP_InCheckSum( (uint16_t*)&v_Pckt_pt->s_ICMP_ICMPHeader.s_Type,
      /* >RELAX<SYNCHRONe_C_Code_10.7> No loss, size_t fits on an uint32_t */
                                       (uint32_t)v_Pckt_pt->s_ICMP_IP_Header.s_IP_TotalLength - (uint32_t)sizeof(ts_ETH_IP_Header) );
#else
      v_icmp_checksum = v_checksum;
#endif
#if (ETH_ICMP_TIME_CONF_ENABLE != 0)
      LIBT_TIME_GET( &v_end_time );
      v_duration_icmp_OnRecv_crc_time = v_end_time - v_start_time;
#endif
      v_Pckt_pt->s_ICMP_IP_Header.s_IP_Checksum = v_checksum;


      if ( v_icmp_checksum == (uint16_t)v_checksum )
      {

         /* Determine the ICMP packet type */
         switch ( v_Pckt_pt->s_ICMP_ICMPHeader.s_Type )
         {
            case K_ETH_ICMP_ECHO_REQUEST :
               ETH_ICMP_SendEchoReply ( p_Data ) ;
               break ;

            case K_ETH_ICMP_ECHO_REPLY :
            case K_ETH_ICMP_DESTINATION_UNREACHABLE :
            case K_ETH_ICMP_SOURCE_QUENCH :
            case K_ETH_ICMP_REDIRECT_MESSAGE :
            case K_ETH_ICMP_TIME_EXCEEDED :
            case K_ETH_ICMP_PARAMETER_PROBLEM_MESSAGE :
            case K_ETH_ICMP_TIMESTAMP_REQUEST :
            case K_ETH_ICMP_TIMESTAMP_REPLY :
            case K_ETH_ICMP_INFORMATION_REQUEST :
            case K_ETH_ICMP_INFORMATION_REPLY :
            default :
               /* Unhandled or unrecognized type just drop it */
               v_ETH_ICMP_ControlObj.s_ICMPstats.s_dropped++ ;
               break ;
         }
      }
      else
      {
         v_ETH_ICMP_ControlObj.s_ICMPstats.s_nok++ ;
      }
   }
   else
   {
      v_ETH_ICMP_ControlObj.s_ICMPstats.s_nok++ ;
   }

}

