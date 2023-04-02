/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Opens an UDP port
 * -------------------------------------------------------------------------- */

#include "middleware/stack_ip/ETH_UDP_public.h"
#include "middleware/stack_ip/ETH_UDP_common.h"
#include "middleware/stack_ip/ETH_UDP_private.h"
#include "middleware/stack_ip/ETH_INTEG_common.h"

void ETH_UDP_OpenPort( uint32_t                    const p_port,
                       const tu_ETH_IPAddr *       const p_addr,
                       const ts_CMN_IOSP_BUFFER *  const p_buff,
                       te_ETH_UDP_PORT_Status *    const p_status  )
{
   ts_ETH_UDP_RECEIVE_BUFF * pt_portBuff ;
   uint32_t v_i ;
   /* Check the port is not yet opened and enough space to open a new port */
   /* >RELAX<SYNCHRONe_C_Code_10.7>: casts are safe, there is no loss of precision */
   pt_portBuff = ETH_UDP_GetReceivedBufferPort( p_port );

   /* >RELAX<SYNCHRONe_C_Code_10.7>: Operation is safe, pointer is compared to NULL */
   if (pt_portBuff == NULL )
   {
      /* take first port avaliable */
      for ( v_i = INTEG_ETH_UDP_OF_PORTS ; v_i > 0ul  ; v_i --)
      {
         /* >RELAX<SYNCHRONe_C_Code_10.7>: Operation is safe, pointer is compared to NULL */
         if ( v_ETH_UDP_ControlObj.s_RcvPort[ v_i - 1ul ].s_BufReception == NULL )
         {
            /* >RELAX<SYNCHRONe_C_Code_10.7>: cast is safe, table element's address is consistent with pointer type */
            pt_portBuff = & v_ETH_UDP_ControlObj.s_RcvPort[  v_i - 1ul ] ;
         }
      }

      /* >RELAX<SYNCHRONe_C_Code_10.7>: Operation is safe, pointer is compared to NULL */
      if(pt_portBuff != NULL )
      {
         pt_portBuff->s_PortNumber = p_port;
         pt_portBuff->s_IP.u_IP = p_addr->u_IP ;
         pt_portBuff->s_BufReception = p_buff->s_buffer;
         pt_portBuff->s_MaxLen = p_buff->s_buffer_size;
         pt_portBuff->s_LenReceived = 0ul ;

         *p_status = e_ETH_UDP_PORT_OPEN;
      }
      else
      {
         /* Integration error : the number of port used in less than the need. */
         *p_status = e_ETH_UDP_PORT_ACTION_FAILED ;
      }
   }
   else
   {
      *p_status = e_ETH_UDP_PORT_ALREADY_DONE;
   }
}
