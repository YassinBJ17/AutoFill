/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION :
 * -------------------------------------------------------------------------- */

#include "middleware/stack_ip/ETH_IP_private.h"
#include "middleware/stack_ip/ETH_common.h"
#include "middleware/stack_ip/ETH_DEF_HEADER_common.h"

#define K_ETH_IP_SINGLE_PKT_ID           (1)   /* arbitraire ID : should differente from the multi-frame ID */

void ETH_IP_Build_SingleFrame ( const tu_ETH_IPAddr * const  p_Destaddr,
                                const ts_CMN_IOSP_BUFFER * const p_data )
{
   ts_ETH_IP_Header * pt_IPHeader ;

   /* >RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1,SYNCHRONe_C_Code_17.4>: cast and operation are safe, IPHeader points to a byte array, with a shift over the header */
   pt_IPHeader = (ts_ETH_IP_Header * ) ( p_data->s_buffer + sizeof( ts_ETH_EthernetHeader ) ) ;

   /* {{RELAX<SYNCHRONe_C_Code_10.7> : all litteral are coded into a char.  */
   /* version & hdr len are contained in a single 8-bit value*/
   pt_IPHeader->s_IP_V = ( uint8_t )( K_ETH_IP_VERSION ) ;
   pt_IPHeader->s_IP_IHL = ( uint8_t )( sizeof(ts_ETH_IP_Header) / sizeof(uint32_t) ) ; /* len of 32 bits word */
   pt_IPHeader->s_IP_TypeOfService = ( uint8_t )( K_ETH_TYPE_OF_IP_SERVICE ) ; /* category of service*/
   pt_IPHeader->s_IP_TimeToLive = ( uint8_t )( INTEG_ETH_UDP_TIME_TO_LIVE ) ; /* time to live in secs*/

   pt_IPHeader->s_IP_TotalLength = ( uint16_t )( ( uint16_t ) p_data->s_buffer_size - ( uint16_t ) sizeof(ts_ETH_EthernetHeader) ) ; /* total len*/
   pt_IPHeader->s_IP_Id = ( uint16_t )( K_ETH_IP_SINGLE_PKT_ID ) ; /* id - multi pkt frame*/
   pt_IPHeader->s_IP_Flags_FragOffset = ( uint16_t )( K_ETH_IP_DONT_FRAGMENT ) ; /* fragment offset field*/
   /* }}RELAX<SYNCHRONe_C_Code_10.7> */


   pt_IPHeader->s_SourceAddress.u_IP = v_ETH_DRV_EtherOwnAddr.s_IpAddress.u_IP ;
   pt_IPHeader->s_DestinationAddress.u_IP = p_Destaddr->u_IP;
}
