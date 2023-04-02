/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Find and return the UDP Fifo corresponding to the input
 *               port number.
 * -------------------------------------------------------------------------- */

#include "middleware/stack_ip/ETH_UDP_common.h"
#include "middleware/stack_ip/ETH_UDP_private.h"

void ETH_UDP_SetDestOnReceivedBufferPort( ts_ETH_UDP_RECEIVE_BUFF *  p_buffPort,
                                          uint32_t const p_PortNumber,
                                          const tu_ETH_IPAddr * const p_IP )
{
   if ( p_buffPort != NULL )
   {
      p_buffPort->s_IP.u_IP = p_IP->u_IP ;
      p_buffPort->s_Port = p_PortNumber ;
   }
}
