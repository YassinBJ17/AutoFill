/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION :
 * -------------------------------------------------------------------------- */

#include "middleware/stack_ip/ETH_UDP_public.h"
#include "middleware/stack_ip/ETH_UDP_private.h"

void ETH_UDP_READ_GET_STATUS( uint32_t                const p_port,
                              ts_ETH_UDP_BUFF_STATS * const p_status )
{
   ts_ETH_UDP_RECEIVE_BUFF *pt_PortBuff;

   /* >RELAX<SYNCHRONe_C_Code_10.7>: Operation is safe, no precision is lost */
   pt_PortBuff = ETH_UDP_GetReceivedBufferPort( p_port );

   /* >RELAX<SYNCHRONe_C_Code_10.7>: Operation is safe, pointer is compared to NULL */
   if( pt_PortBuff == NULL ) /* port not open */
   {
      p_status->s_UDP_done = 0UL ;
      p_status->s_UDP_len = 0UL ;
   }
   else
   {
      p_status->s_UDP_len = pt_PortBuff->s_LenReceived;
      p_status->s_UDP_done = p_status->s_UDP_len ;
   }
}
