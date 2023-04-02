/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION :
 * -------------------------------------------------------------------------- */

#include "middleware/stack_ip/ETH_ARP_private.h"
#include "libtools/memory/LIB_MEM_public.h"
#include "libtools/time/LIB_TIME_public.h"
#include "middleware/stack_ip/ETH_common.h"

void ETH_ARP_SendARP_Request( ts_ETH_ARP_TableEntry * const p_TableEntry_pt,
                              const tu_ETH_IPAddr   * const p_destIP )
{
   ts_ETH_MACAddr       v_BroadCastAddr;
   ts_CMN_IOSP_BUFFER   v_buff;

   /* >RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1>: cast is safe, table is initialized with 0xFF */
   LIB_MEM_SET( (int8_t*) v_BroadCastAddr.s_val,
                (int8_t) K_ETH_ARP_BROADCAST_ADDR,
                (uint32_t) K_HW_ADDR_LEN);

   ETH_ARP_BuildARPPacket (  &v_ETH_ARP_ControlObj.s_TxBuf,
                             (uint16_t) K_ETH_ARP_REQUEST,
                             &v_BroadCastAddr,
                             p_destIP ) ;

   /* Send the ARP request*/
   /* >RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1>: cast is safe, table is handled as bytes */
   v_buff.s_buffer = (int8_t *)&v_ETH_ARP_ControlObj.s_TxBuf ;
   /* >RELAX<SYNCHRONe_C_Code_10.7>: no loss of precision: size_t fits in uint32_t */
   v_buff.s_buffer_size = (uint32_t)sizeof(ts_ETH_ARP_Packet) ;

   ETH_DRV_SEND_FRAME( &v_BroadCastAddr,
                       e_ETH_PROTO_ARP,
                       &v_buff );

   /* Make sure the ARP system time is current*/
   p_TableEntry_pt->s_ARPType = e_ETH_ARP_REQUEST_IN_PROGRESS ;
   p_TableEntry_pt->s_timeoutChrono.s_ongoing = 0ul ;
   p_TableEntry_pt->s_timeoutChrono.s_end = INTEG_ETH_ARP_ARP_REQUEST_TIME_OUT ;
   LIBT_TIME_Update( & p_TableEntry_pt->s_timeoutChrono );
}
