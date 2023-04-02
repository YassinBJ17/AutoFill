/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION :
 * -------------------------------------------------------------------------- */

#include "middleware/stack_ip/ETH_UDP_public.h"
#include "middleware/stack_ip/ETH_UDP_common.h"
#include "middleware/stack_ip/ETH_UDP_private.h"

#include "libtools/memory/LIB_MEM_public.h"


void ETH_UDP_READ_CPY( uint32_t              const p_port,
                       ts_CMN_IOSP_BUFFER *  const p_data,
                       CMN_SYSTEM_SIZE_t *   const p_nbBytesWritten)
{
   ts_ETH_UDP_RECEIVE_BUFF *  pt_PortBuff;
   uint32_t                   v_len ;

   /* >RELAX<SYNCHRONe_C_Code_10.7>: Operation is safe, no precision is lost */
   pt_PortBuff = ETH_UDP_GetReceivedBufferPort( p_port );

   /* >RELAX<SYNCHRONe_C_Code_10.7>: Operation is safe, pointer is compared to NULL */
   /*  (    port not open    ) OR (   robustess: no data received    ) */
   if( ( pt_PortBuff == NULL ) || ( pt_PortBuff->s_LenReceived == 0ul) )
   {
      *p_nbBytesWritten = 0UL ;
      /* >RELAX<SYNCHRONe_C_Code_10.7>: Operation is safe, pointer is compared to NULL */
      p_data->s_buffer = NULL ;
   }
   else
   {
      /* >RELAX<SYNCHRONe_C_Code_10.7>: No loss, size_t fits on an uint32_t */
      v_len = pt_PortBuff->s_LenReceived - (uint32_t)sizeof(ts_ETH_UDP_PacketHeader);

      if ( v_len >  p_data->s_buffer_size )
      {
         v_len = p_data->s_buffer_size ;
      }
      LIB_MEM_CPY( p_data->s_buffer,
      /* >RELAX<SYNCHRONe_C_Code_17.4>: operation is safe, it's an array indexing on a pointer */
                   & (pt_PortBuff->s_BufReception[ sizeof(ts_ETH_UDP_PacketHeader)]),
                   v_len );
      *p_nbBytesWritten = v_len ;
      pt_PortBuff->s_LenReceived = 0UL ;
   }
}
