/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef ETH_UDP_COMMON_H
#define ETH_UDP_COMMON_H

#include "middleware/stack_ip/ETH_common.h"
#include "middleware/stack_ip/ETH_public.h"
#include "middleware/stack_ip/ETH_DEF_HEADER_common.h"

/* ---------- provided define constants --------------------------------------- */

/* ---------- provided types: ----------------------------------------------- */


typedef PACKED_U08 struct
{
   ts_ETH_UDP_PacketHeader s_header;
   int8_t                  s_data[ K_ETH_MAX_ENET_PACKET_SIZE ];
} ts_ETH_UDP_Packet;


typedef struct
{
   uint32_t       s_PortNumber;
   tu_ETH_IPAddr  s_IP;
   uint32_t       s_Port;
   uint32_t       s_LenReceived;        /* data length in bytes */
   uint32_t       s_MaxLen ;
   int8_t *       s_BufReception;
} ts_ETH_UDP_RECEIVE_BUFF;


/* ---------- provided variables: ------------------------------------------- */

/* ---------- provided operations: ------------------------------------------ */

extern uint16_t ETH_UDP_Checksum( const tu_ETH_IPAddr *           const p_src,
                                  const tu_ETH_IPAddr *           const p_dest,
                                  const ts_ETH_UDP_PacketHeader * const p_packet ,
                                  const ts_CMN_IOSP_BUFFER *      const p_data );

extern void ETH_UDP_Init(void) ;

extern void ETH_UDP_OnRecv( const ts_CMN_IOSP_BUFFER * const p_Data );

#endif /* ETH_UDP_COMMON_H */
