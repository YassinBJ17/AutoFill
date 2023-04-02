/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION :
 * -------------------------------------------------------------------------- */

#include "middleware/stack_ip/ETH_common.h"
#include "middleware/stack_ip/ETH_private.h"
#include "middleware/ethernet/ETH_porting.h"
#include "middleware/stack_ip/ETH_DEF_HEADER_common.h"

uint32_t ETH_DRV_SEND_FRAME ( const ts_ETH_MACAddr *     const p_dest,
                              te_ETH_PROTO_TYPE          const p_ProtocolType,
                              const ts_CMN_IOSP_BUFFER * const p_buff )
{
   /* Local variables */
   ts_ETH_HAL_STATS_TRANSFERT v_stats;
   ts_ETH_EthernetHeader *    pt_Header ;
   uint32_t v_eth_tx_status ;

   v_stats.s_len = 0L ;

   v_eth_tx_status = hal_get_status_write_pt( &v_stats );

   if (  v_stats.s_status == e_CMN_FLAG_COMPLETE )
   {
      /* Prepare transfer */
      /* >RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1>: cast needed, buffer is composed of bytes */
      pt_Header = ( ts_ETH_EthernetHeader * ) ( p_buff->s_buffer) ;
      /* >RELAX<SYNCHRONe_C_Code_10.7>: no loss, values are 0x800 or 0x806 */
      pt_Header->s_ProtocolType = (uint16_t) p_ProtocolType ;

      /* Fill up the MAC header*/
      ETH_COPY_MAC_ADD ( &pt_Header->s_DestinationHost ,
                          p_dest ) ;
      ETH_COPY_MAC_ADD ( &pt_Header->s_SourceHost ,
                         &v_ETH_DRV_EtherOwnAddr.s_HwAddress ) ;

      hal_write_pt( p_buff );
      v_ETH_DRV_ControlETH.s_ETHstats.s_packet_tx.s_handled ++ ;
   }
   else
   {
      v_ETH_DRV_ControlETH.s_ETHstats.s_packet_tx.s_dropped ++ ;
   }

   return v_eth_tx_status;

}
