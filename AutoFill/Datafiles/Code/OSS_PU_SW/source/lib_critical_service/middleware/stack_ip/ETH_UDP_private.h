/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef ETH_UDP_PRIVATE_H
#define ETH_UDP_PRIVATE_H

#include "middleware/stack_ip/ETH_UDP_common.h"
#include "middleware/stack_ip/ETH_common.h"
#include "middleware/stack_ip/ETH_DEF_HEADER_common.h"
#include "middleware/stack_ip/ETH_INTEG_common.h"

#define K_ETH_UDP_PORT_INVALID (0ul)

/* ---------- provided types: ----------------------------------------------- */
typedef struct
{
   ts_ETH_UDP_RECEIVE_BUFF s_RcvPort[INTEG_ETH_UDP_OF_PORTS];
   ts_ETH_UDP_PacketHeader s_TxHeaderBuff;
   ts_ETH_STATS s_UDPstats;
} ts_ETH_UDP_CONTROL;

/* ---------- provided variables: ------------------------------------------- */

extern ts_ETH_UDP_CONTROL v_ETH_UDP_ControlObj  ;

/* ---------- provided operations: ------------------------------------------ */

extern void ETH_UDP_SetDestOnReceivedBufferPort( ts_ETH_UDP_RECEIVE_BUFF *  p_buffPort,
                                                 uint32_t const p_PortNumber,
                                                 const tu_ETH_IPAddr * const p_IP );

extern uint32_t ETH_UDP_GetIPDestOnReceivedBufferPort( uint32_t const p_PortNumber );


#endif /* ETH_UDP_PRIVATE_H */
