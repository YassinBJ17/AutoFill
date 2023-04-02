/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION :
 * -------------------------------------------------------------------------- */

#include "middleware/stack_ip/ETH_IP_private.h"
#include "libtools/time/LIB_TIME_public.h"
#include "libtools/memory/LIB_MEM_public.h"
#include "middleware/stack_ip/ETH_DEF_HEADER_common.h"

/* TODO integration testing*/
int32_t   v_size_test ;

void ETH_IP_Build_MultiFrame (  const tu_ETH_IPAddr *      const  p_Destaddr,
                                const ts_CMN_IOSP_BUFFER * const p_header,
                                const ts_CMN_IOSP_BUFFER * const p_dataToSent,
                                ts_CMN_IOSP_BUFFER *       const p_dataOut  )
{
   ts_ETH_IP_Header *   pt_IPHeader ;
   CMN_SYSTEM_TIME_t    v_current_time;
   uint32_t             v_dataOffset;
   uint32_t             v_len ;
   uint16_t             v_flagFragment ;
   uint16_t             v_id;
   uint16_t             v_isFragmented;


   LIBT_TIME_GET( &v_current_time );

   /* >RELAX<SYNCHRONe_C_Code_10.7>: cast is safe, address of ts_ETH_IP_Header is indeed (ts_ETH_IP_Header*) */
   pt_IPHeader = (ts_ETH_IP_Header * ) &( v_ETH_IP_ControlObj.s_TxFragment.s_IPFTx_Packetbuff.s_IPF_ip ) ;

   v_len = p_header->s_buffer_size + p_dataToSent->s_buffer_size ;
   /* >RELAX<SYNCHRONe_C_Code_7.2>: literal is safe, we want an even integer */
   v_len = v_len + ( v_len % 2UL ) ; /*  packed for 16 bits */
   /* >RELAX<SYNCHRONe_C_Code_10.7>: cast is safe, size_t fits on uint32_t */
   if ( v_len > (uint32_t)(K_MAX_MF_DATA_SIZE + (uint32_t)sizeof(ts_ETH_IP_Header) + (uint32_t)sizeof(ts_ETH_EthernetHeader) ) )
   {
      /* activate fragmentation  */
      v_isFragmented = 1;
      /* >RELAX<SYNCHRONe_C_Code_10.7>: cast is safe, 0x2000 fits on uint16_t */
      v_flagFragment = (uint16_t)(K_ETH_IP_IS_FRAGMENT_MASK) ;
      /* >RELAX<SYNCHRONe_C_Code_10.7>: cast is safe, size_t fits on uint32_t */
      /* TODO integration testing
       * v_len = (uint32_t)(K_MAX_MF_DATA_SIZE);
       */
      v_len = (uint32_t)(K_MAX_MF_DATA_SIZE + (uint32_t)sizeof(ts_ETH_IP_Header) + (uint32_t)sizeof(ts_ETH_EthernetHeader));
      /* >RELAX<SYNCHRONe_C_Code_10.2,SYNCHRONe_C_Code_10.3,SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_7.2>: we want the 16 bits LSB, cast and literal are safe */
      v_id = (uint16_t)(v_current_time & 0xFFFF) ;
   }
   else
   {
      /* no fragmentation */
      v_isFragmented = 0;
      /* >RELAX<SYNCHRONe_C_Code_10.7>: cast is safe, 0x4000 fits on uint16_t */
      v_flagFragment = (uint16_t)(K_ETH_IP_DONT_FRAGMENT_MASK);
      v_id = (uint16_t)1 ;
   }


   /* {{RELAX<SYNCHRONe_C_Code_10.7> : all litteral are coded into a char.  */
   pt_IPHeader->s_IP_V = ( uint8_t )( K_ETH_IP_VERSION ) ;
   pt_IPHeader->s_IP_IHL = (uint8_t)(sizeof(ts_ETH_IP_Header) / sizeof(uint32_t)) ; /* len of 32 bits word */
   pt_IPHeader->s_IP_TypeOfService = ( uint8_t )( K_ETH_TYPE_OF_IP_SERVICE ) ; /* category of service*/
   pt_IPHeader->s_IP_TimeToLive = ( uint8_t )( INTEG_ETH_UDP_TIME_TO_LIVE ) ; /* time to live in secs*/
   pt_IPHeader->s_IP_TotalLength = (uint16_t) ((uint16_t)v_len - (uint16_t)sizeof(ts_ETH_EthernetHeader)  ) ; /* total len*/
   pt_IPHeader->s_IP_Id = v_id ; /* id - multi pkt frame*/
   pt_IPHeader->s_IP_Flags_FragOffset = v_flagFragment ; /* fragment offset field*/
   pt_IPHeader->s_SourceAddress.u_IP = v_ETH_DRV_EtherOwnAddr.s_IpAddress.u_IP ;
   pt_IPHeader->s_DestinationAddress.u_IP = p_Destaddr->u_IP;
   /* }}RELAX<SYNCHRONe_C_Code_10.7> */

   /* --------------------------------- fill frame ---------------------------------  */

   /* >RELAX<SYNCHRONe_C_Code_10.7>: cast is safe, size_t fits on uint32_t */
   v_dataOffset = (uint32_t)(sizeof(ts_ETH_EthernetHeader ) + sizeof(ts_ETH_IP_Header)) ;
   if ( v_dataOffset < p_header->s_buffer_size )
   {
      /* copy this header into TXHeader */
      LIB_MEM_CPY( (v_ETH_IP_ControlObj.s_TxFragment.s_IPFTx_Packetbuff.s_IPF_data  ),
      /* >RELAX<SYNCHRONe_C_Code_17.4>: operation is safe, the pointer is shifted the same way as an indexing */
                   p_header->s_buffer + v_dataOffset,
                   p_header->s_buffer_size - v_dataOffset );

      /* TODO integration testing*/
      v_size_test = p_header->s_buffer_size - v_dataOffset;


      v_dataOffset = p_header->s_buffer_size - v_dataOffset ;
   }

   /* adding data */
   /* TODO integration testing
    *
    */
   if (v_isFragmented != 0)
   {
      LIB_MEM_CPY( v_ETH_IP_ControlObj.s_TxFragment.s_IPFTx_Packetbuff.s_IPF_data + v_dataOffset,
                   (p_dataToSent->s_buffer) ,
                   v_len - p_header->s_buffer_size + v_dataOffset );

      /* TODO integration testing*/
      v_size_test = v_len - p_header->s_buffer_size + v_dataOffset;

   }
   else
   {
      /* >RELAX<SYNCHRONe_C_Code_17.4>: operation is safe, the pointer is shifted the same way as an indexing */
      LIB_MEM_CPY( v_ETH_IP_ControlObj.s_TxFragment.s_IPFTx_Packetbuff.s_IPF_data + v_dataOffset,
                   (p_dataToSent->s_buffer) ,
                   v_len - p_header->s_buffer_size );

      /* TODO integration testing*/
      v_size_test = v_len - p_header->s_buffer_size;

      if ( v_len > ( p_header->s_buffer_size + p_dataToSent->s_buffer_size ) ) /* padding due to 16 bits alignment */
      {
         v_ETH_IP_ControlObj.s_TxFragment.s_IPFTx_Packetbuff.s_IPF_data [ p_dataToSent->s_buffer_size + v_dataOffset ] = (int8_t)0x00 ;
      }

   }


   /* --------------------------------- update fragmentation controller ---------------------------------  */
   if (v_isFragmented != 0)
   {
      /* TODO integration testing
       * v_ETH_IP_ControlObj.s_TxFragment.s_NextOffset = v_len - p_header->s_buffer_size ;
       * v_ETH_IP_ControlObj.s_TxFragment.s_nbLeftToSent = p_dataToSent->s_buffer_size - v_ETH_IP_ControlObj.s_TxFragment.s_NextOffset  ;
       * v_ETH_IP_ControlObj.s_TxFragment.s_origineBuff.s_buffer_size = p_dataToSent->s_buffer_size ;
       */
      v_ETH_IP_ControlObj.s_TxFragment.s_NextOffset = v_len - (uint32_t)(sizeof(ts_ETH_EthernetHeader)) - (uint32_t)(sizeof(ts_ETH_IP_Header) + v_dataOffset)  ;
      v_ETH_IP_ControlObj.s_TxFragment.s_nbLeftToSent = p_dataToSent->s_buffer_size - v_ETH_IP_ControlObj.s_TxFragment.s_NextOffset ;
      v_ETH_IP_ControlObj.s_TxFragment.s_origineBuff.s_buffer = p_dataToSent->s_buffer ;
      v_ETH_IP_ControlObj.s_TxFragment.s_origineBuff.s_buffer_size = p_dataToSent->s_buffer_size ;
   }

   /* >RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1>: cast is safe, address of s_PacketBuff is handled as a byte array */
   p_dataOut->s_buffer = (int8_t*) &v_ETH_IP_ControlObj.s_TxFragment.s_IPFTx_Packetbuff ;
   p_dataOut->s_buffer_size = v_len ;
}
