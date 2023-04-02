/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION :
 * -------------------------------------------------------------------------- */

#include "middleware/stack_ip/ETH_ICMP_private.h"
#include "middleware/stack_ip/ETH_ICMP_conf.h"
#include "middleware/stack_ip/ETH_common.h"
#include "middleware/stack_ip/ETH_IP_common.h"
#include "libtools/memory/LIB_MEM_public.h"
#include "middleware/stack_ip/ETH_DEF_HEADER_common.h"

#if (ETH_ICMP_TIME_CONF_ENABLE != 0)
#include "libtools/time/LIB_TIME_public.h"
#endif

#define K_ETH_ICMP_TIME_TO_LIVE        (64)  /* time to live in secs */
#define K_ETH_ICMP_IP_PKT_ID                (1)  /* arbitraire ID */

#define K_ETH_ICMP_ECHO_DATA_MAX_SIZE   (K_ETH_MAX_ENET_PACKET_SIZE - (uint32_t)(sizeof(ts_ETH_ICMP_EchoPacket)))

#if (ETH_ICMP_TIME_CONF_ENABLE != 0)
   CMN_SYSTEM_TIME_t    v_duration_icmp_SendEchoReply_crc_time;
#endif

/*---------------------------------------------------------------------------*/
/* NAME: ETH_ICMP_SendEchoReply()*/
/*---------------------------------------------------------------------------*/
/* PURPOSE: Send an ICMP echo reply message*/
/*---------------------------------------------------------------------------*/
/* INPUTS/OUTPUTS: See function declaration*/
/*---------------------------------------------------------------------------*/
/* ASSUMPTIONS/LIMITATIONS: None.*/
/*---------------------------------------------------------------------------*/
void ETH_ICMP_SendEchoReply( const ts_CMN_IOSP_BUFFER * const p_Data )
{
   ts_ETH_ICMP_EchoPacket *         pt_ICMPEcho;
   const ts_ETH_ICMP_EchoPacket *   c_DataICMP_pt;
   ts_ETH_EthernetAddress           v_addrDest;

   ts_CMN_IOSP_BUFFER   v_buffData;
   uint32_t             v_DataEchoSize ;
#if (ETH_ICMP_TIME_CONF_ENABLE != 0)
   CMN_SYSTEM_TIME_t    v_start_time;
   CMN_SYSTEM_TIME_t    v_end_time;
#endif

   /* >RELAX<SYNCHRONe_C_Code_10.7> No loss, size_t fits on an uint32_t */
   if ( p_Data->s_buffer_size > (uint32_t) sizeof ( ts_ETH_ICMP_EchoPacket )  )
   {
      /* >RELAX<SYNCHRONe_C_Code_10.7> No loss, size_t fits on an uint32_t */
      v_DataEchoSize = p_Data->s_buffer_size - (uint32_t) sizeof(ts_ETH_ICMP_EchoPacket) ;
      /* >RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> safe cast, TxPacket is handled as a byte array */
      pt_ICMPEcho = ( ts_ETH_ICMP_EchoPacket* )v_ETH_ICMP_ControlObj.s_TxPacket;
      /* >RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> safe cast, buffer is handled as a byte array */
      c_DataICMP_pt = ( const ts_ETH_ICMP_EchoPacket* )p_Data->s_buffer ;

      /* >RELAX<SYNCHRONe_C_Code_10.7> No loss, size_t fits on an uint32_t */
      if( v_DataEchoSize > (uint32_t) K_ETH_ICMP_ECHO_DATA_MAX_SIZE )
      {
         /* >RELAX<SYNCHRONe_C_Code_10.7> No loss, size_t fits on an uint32_t */
         v_DataEchoSize = (uint32_t) K_ETH_ICMP_ECHO_DATA_MAX_SIZE ;
      }
      /* Copy data to ICMP buffer */
      /* >RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_17.4> sizeof used to shift address in table, equ. uint32_t */
      LIB_MEM_CPY( (int8_t*)( v_ETH_ICMP_ControlObj.s_TxPacket + sizeof ( ts_ETH_ICMP_EchoPacket ) ) ,
      /* >RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_17.4> sizeof used to shift address in table, equ. uint32_t */
                   (int8_t*)( p_Data->s_buffer + sizeof( ts_ETH_ICMP_EchoPacket ) ),
                   v_DataEchoSize );

      /* Fill the ICMP packet*/
      pt_ICMPEcho->s_ICMPEcho_ICMPHeader.s_Type = (uint8_t) K_ETH_ICMP_ECHO_REPLY;
      pt_ICMPEcho->s_ICMPEcho_ICMPHeader.s_Code = (uint8_t) K_ETH_ICMP_ECH_REPLY_CODE;
      pt_ICMPEcho->s_ICMPEcho_Identifier = c_DataICMP_pt->s_ICMPEcho_Identifier;
      pt_ICMPEcho->s_ICMPEcho_SequenceNo = c_DataICMP_pt->s_ICMPEcho_SequenceNo;


      pt_ICMPEcho->s_ICMPEcho_ICMPHeader.s_Checksum = (uint16_t)0;
      /* >RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> cast is safe, pointer not used in its dereferenced form */
#if (ETH_ICMP_TIME_CONF_ENABLE != 0 )
        LIBT_TIME_GET( &v_start_time );
#endif
#if (ETH_ICMP_CONF_ENABLE_CHK != 0 )
      pt_ICMPEcho->s_ICMPEcho_ICMPHeader.s_Checksum = ETH_IP_InCheckSum( (uint16_t*)&pt_ICMPEcho->s_ICMPEcho_ICMPHeader,
      /* >RELAX<SYNCHRONe_C_Code_10.7> cast is safe, uint32_t can contain a size_t */
                                                            v_DataEchoSize + (uint32_t)sizeof(ts_ETH_ICMP_EchoPacket));

#else
      pt_ICMPEcho->s_ICMPEcho_ICMPHeader.s_Checksum = 0;
#endif
#if (ETH_ICMP_TIME_CONF_ENABLE != 0)
      LIBT_TIME_GET( &v_end_time );
      v_duration_icmp_SendEchoReply_crc_time = v_end_time - v_start_time;
#endif
      /* Send the ARP response*/
      /* >RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> safe cast, buffers are both bytes arrays or pointers */
      v_buffData.s_buffer = (int8_t *)&v_ETH_ICMP_ControlObj.s_TxPacket;
      /* >RELAX<SYNCHRONe_C_Code_10.7> size_t fits in uint32_t */
      v_buffData.s_buffer_size =  v_DataEchoSize + (uint32_t) sizeof(ts_ETH_ICMP_EchoPacket ) ;

      ETH_COPY_MAC_ADD( &v_addrDest.s_HwAddress ,
                      & c_DataICMP_pt->s_ICMPEcho_EtherHeader.s_SourceHost );
      /* >RELAX<SYNCHRONe_C_Code_10.7> safe cast, both operands are the same type */
      v_addrDest.s_IpAddress = c_DataICMP_pt->s_ICMPEcho_IP_Header.s_SourceAddress;

      ETH_IP_SEND( &v_addrDest,
                e_ETH_IP_PROTO_ICMP,
      /* >RELAX<SYNCHRONe_C_Code_10.7> cast is safe, parameter is tested if equal to NULL before use */
                NULL,
                & v_buffData );

      v_ETH_ICMP_ControlObj.s_ICMPstats.s_handled ++ ;
   }
   else
   {
      v_ETH_ICMP_ControlObj.s_ICMPstats.s_nok ++ ;
   }
}
