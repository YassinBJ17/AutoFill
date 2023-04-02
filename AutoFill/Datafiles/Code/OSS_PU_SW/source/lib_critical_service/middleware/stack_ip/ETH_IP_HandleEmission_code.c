/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION :
 * -------------------------------------------------------------------------- */

#include "middleware/stack_ip/ETH_IP_common.h"
#include "middleware/stack_ip/ETH_IP_private.h"
#include "middleware/stack_ip/ETH_IP_conf.h"
#include "middleware/stack_ip/ETH_common.h"
#include "libtools/memory/LIB_MEM_public.h"
#include "middleware/stack_ip/ETH_DEF_HEADER_common.h"

#if (ETH_IP_TIME_CONF_ENABLE != 0)
#include "libtools/time/LIB_TIME_public.h"
#endif

#if (ETH_IP_TIME_CONF_ENABLE != 0)
   CMN_SYSTEM_TIME_t    v_duration_ip_handleEmissioncrc_time;
#endif

void ETH_IP_HandleEmission(void)
{
   ts_ETH_IP_FRAGMENT_TX_MNGT * pt_TxFragment ;
   ts_CMN_IOSP_BUFFER v_buff;
   uint32_t v_offset;
   uint32_t v_offset_flag;
   uint32_t v_flag;
   uint32_t v_nbData ;
#if (ETH_IP_TIME_CONF_ENABLE != 0)
   CMN_SYSTEM_TIME_t    v_start_time;
   CMN_SYSTEM_TIME_t    v_end_time;
#endif

   /* >RELAX<SYNCHRONe_C_Code_10.7>: cast is safe, address of s_TxFragment is indeed (ts_ETH_IP_FRAGMENT_TX_MNGT*) */
   pt_TxFragment = & v_ETH_IP_ControlObj.s_TxFragment;

   if ( pt_TxFragment->s_nbLeftToSent > 0ul )
   {
      /* >RELAX<SYNCHRONe_C_Code_10.7>: no loss, size_t fits on an uint32_t */
      if ( pt_TxFragment->s_nbLeftToSent > K_MAX_MF_DATA_SIZE )
      {
         v_flag = (uint32_t)K_ETH_IP_IS_FRAGMENT_MASK ;
         v_offset_flag = K_MAX_MF_DATA_SIZE ;
         v_offset = pt_TxFragment->s_NextOffset ;
         /* >RELAX<SYNCHRONe_C_Code_10.7>: no loss, K_MAX_MF_DATA_SIZE fits on an uint32_t */
         v_nbData = K_MAX_MF_DATA_SIZE ;
      }
      else
      {
         v_flag =  0ul ;
         v_offset = pt_TxFragment->s_NextOffset ;
         v_offset_flag = v_offset + (uint32_t)sizeof(ts_ETH_UDP_Header) ;
         v_nbData = pt_TxFragment->s_nbLeftToSent ;
      }

      pt_TxFragment->s_NextOffset += v_nbData ;
      pt_TxFragment->s_nbLeftToSent -= v_nbData ;

      /*
       *  TODO on FADEX
       *  if (  ( v_offset + v_nbData ) < pt_TxFragment->s_origineBuff.s_buffer_size)
       *
      */
      if (  ( v_offset + v_nbData ) <= pt_TxFragment->s_origineBuff.s_buffer_size)
      {
         /* >RELAX<SYNCHRONe_C_Code_10.7>: no loss, flag and offset < K_MAX_MF_DATA_SIZE, which fits on an uint16_t */
         pt_TxFragment->s_IPFTx_Packetbuff.s_IPF_ip.s_IP_Flags_FragOffset = (uint16_t)( (uint16_t)v_flag | ((uint16_t)v_offset_flag / (uint16_t)K_ETH_IP_FRAG_OFFSET_LSB ) )  ; /* fragment offset field*/
         /* >RELAX<SYNCHRONe_C_Code_10.7>: no loss, v_nbData < K_MAX_MF_DATA_SIZE, which fits on an uint16_t */
         pt_TxFragment->s_IPFTx_Packetbuff.s_IPF_ip.s_IP_TotalLength = (uint16_t)( (uint16_t)v_nbData + (uint16_t)sizeof(ts_ETH_IP_Header) ) ;

         /* Calculate the IP header checksum*/
         /* >RELAX<SYNCHRONe_C_Code_10.7>: 0 fits in uint16_t, no loss */
         pt_TxFragment->s_IPFTx_Packetbuff.s_IPF_ip.s_IP_Checksum = (uint16_t)0 ;
         /* >RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1>: casts are safe, buffer is handled as a half-word array */
#if (ETH_IP_TIME_CONF_ENABLE != 0 )
        LIBT_TIME_GET( &v_start_time );
#endif
#if (ETH_IP_CONF_ENABLE_CHK != 0 )
        pt_TxFragment->s_IPFTx_Packetbuff.s_IPF_ip.s_IP_Checksum = ETH_IP_InCheckSum ( (uint16_t *) &(pt_TxFragment->s_IPFTx_Packetbuff.s_IPF_ip) ,
                                                                                       (uint32_t)sizeof(ts_ETH_IP_Header) ) ;
         /* >RELAX<SYNCHRONe_C_Code_10.7>: no loss, size_t fits on uint32_t */
#else
        pt_TxFragment->s_IPFTx_Packetbuff.s_IPF_ip.s_IP_Checksum = 0;
#endif
#if (ETH_IP_TIME_CONF_ENABLE != 0)
        LIBT_TIME_GET( &v_end_time );
        v_duration_ip_handleEmissioncrc_time = v_end_time - v_start_time;
#endif

         LIB_MEM_CPY( (pt_TxFragment->s_IPFTx_Packetbuff.s_IPF_data) ,
         /* >RELAX<SYNCHRONe_C_Code_17.4>: operation is safe, equal to an array indexing */
                      (pt_TxFragment->s_origineBuff.s_buffer + v_offset ),
                      v_nbData);

         /* >RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1>: cast is safe, buffer is handled as a byte array */
         v_buff.s_buffer = (int8_t*) & (pt_TxFragment->s_IPFTx_Packetbuff);
         /* >RELAX<SYNCHRONe_C_Code_10.7>: no loss, uint16_t fits on uint32_t and size_t fits on uint16_t */
         v_buff.s_buffer_size = (uint32_t)pt_TxFragment->s_IPFTx_Packetbuff.s_IPF_ip.s_IP_TotalLength + (uint32_t)sizeof(ts_ETH_EthernetHeader) ;

         ETH_DRV_SEND_FRAME( & (pt_TxFragment->s_IPFTx_Packetbuff.s_IPF_eth.s_DestinationHost)  ,
                             e_ETH_PROTO_IP,
                             &v_buff );

         pt_TxFragment->s_IPFstats.s_handled ++ ;

      }
      else
      {
         pt_TxFragment->s_nbLeftToSent = 0ul ;
         pt_TxFragment->s_IPFstats.s_nok ++ ;
      }
   }
}
