/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Find and return the UDP Fifo corresponding to the input
 *               port number.
 * -------------------------------------------------------------------------- */

#include "middleware/stack_ip/ETH_UDP_common.h"
#include "middleware/stack_ip/ETH_UDP_private.h"

ts_ETH_UDP_RECEIVE_BUFF *ETH_UDP_GetReceivedBufferPort( uint32_t const p_PortNumber )
{
   uint32_t                   v_i ;
   ts_ETH_UDP_RECEIVE_BUFF *  pt_buffPort;

   /* >RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1>: cast is safe, it's used to initialize the pointer */
   pt_buffPort = (ts_ETH_UDP_RECEIVE_BUFF *) NULL ;

   for ( v_i = 0ul ; v_i < INTEG_ETH_UDP_OF_PORTS ; v_i++ )
   {
      if ( v_ETH_UDP_ControlObj.s_RcvPort[ v_i ].s_PortNumber == p_PortNumber )
      {
         /* >RELAX<SYNCHRONe_C_Code_10.7>: cast is safe, table element's address is consistent with pointer type */
         pt_buffPort = &  ( v_ETH_UDP_ControlObj.s_RcvPort[ v_i ] ) ;
         break;
      }
   }

   return ( pt_buffPort );
}
