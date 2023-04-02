/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION :
 * -------------------------------------------------------------------------- */

#include "middleware/stack_ip/ETH_public.h"
#include "middleware/stack_ip/ETH_private.h"
#include "middleware/stack_ip/ETH_conf.h"
#include "middleware/stack_ip/ETH_DEF_HEADER_common.h"
#include "middleware/ethernet/ETH_porting.h"

#if (ETH_TIME_CONF_ENABLE != 0)
#include "libtools/time/LIB_TIME_public.h"
#endif

te_CMN_FLAG_QUESTION ETH_DRV_HandleReception_L_Check(const ts_CMN_IOSP_BUFFER * const p_buff ,
                                                     te_CMN_FLAG_QUESTION *     const p_broadcast );
#if (ETH_TIME_CONF_ENABLE != 0)
   CMN_SYSTEM_TIME_t    v_duration_eth_handle_reception_crc_time;
#endif

void ETH_DRV_HandleReception (void)
{

   /* Local variables */
   ts_ETH_HAL_STATS_TRANSFERT v_stats;
   ts_CMN_IOSP_BUFFER         v_buff ;
   te_CMN_FLAG_QUESTION       v_DataForMe;
   te_CMN_FLAG_QUESTION       v_broadcast;
#if (ETH_TIME_CONF_ENABLE != 0)
   CMN_SYSTEM_TIME_t    v_start_time;
   CMN_SYSTEM_TIME_t    v_end_time;
#endif

   v_stats.s_len = 0L ;
   /* if there's a pending rx message on the bus,*/
#if (ETH_TIME_CONF_ENABLE != 0 )
        LIBT_TIME_GET( &v_start_time );
#endif
   hal_get_status_read_pt( &v_stats );

   if ( v_stats.s_status == e_CMN_FLAG_COMPLETE )
   {

      /* Only process an error free msg, any errors are recorded in the MAC fault*/
      /* register and read by afdx_update_mib.*/
      hal_read_pt( &v_buff );

      /* is this packet size valid?*/
      if ( ( v_buff.s_buffer_size <= ( K_ETH_MAX_ENET_PACKET_SIZE ) ) &&
               ( v_buff.s_buffer_size >= ( K_ETH_MIN_ENET_PACKET_SIZE ) ) )
      {
         /* Increment the number of packets that have been handled*/
         v_ETH_DRV_ControlETH.s_ETHstats.s_packet_rx.s_handled++ ;

         /* check if the packet is for me */
         v_DataForMe = ETH_DRV_HandleReception_L_Check( &v_buff, & v_broadcast ) ;

         if ( ( v_DataForMe == e_CMN_FLAG_YES ) || ( v_broadcast == e_CMN_FLAG_YES ) )
         {
            ETH_DRV_OnRecv ( &v_buff , v_broadcast ) ;
         }
         /* NO ELSE: not for me so drop the packet */

      }
      /* Packet length was invalid.  This packet will be dropped*/
      else
      {
         v_ETH_DRV_ControlETH.s_ETHstats.s_packet_rx.s_dropped++ ;
      }
      /* Allow next reception */
      hal_allow_rcv_pt();

#if (ETH_TIME_CONF_ENABLE != 0)
      LIBT_TIME_GET( &v_end_time );
      v_duration_eth_handle_reception_crc_time = v_end_time - v_start_time;
#endif

   }
}

te_CMN_FLAG_QUESTION ETH_DRV_HandleReception_L_Check(const ts_CMN_IOSP_BUFFER * const p_buff ,
                                                     te_CMN_FLAG_QUESTION *     const p_broadcast)
{
   /* >RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1>: cast needed buffer is composed of bytes */
   const ts_ETH_EthernetHeader * c_Header_pt  = ( const ts_ETH_EthernetHeader * )  p_buff->s_buffer ;
   te_CMN_FLAG_QUESTION          v_isSame ;
   uint32_t                      v_i ;

   v_isSame = ETH_DRV_IsSameMAC_ADDR( &v_ETH_DRV_EtherOwnAddr.s_HwAddress ,
                           &c_Header_pt->s_DestinationHost );

   if (v_isSame == e_CMN_FLAG_NO )
   {
      /* check for broadcast */
      *p_broadcast = e_CMN_FLAG_YES ;
      for ( v_i = 0ul ; v_i < (uint32_t)K_HW_ADDR_LEN ; v_i ++ )
      {
         /* >RELAX<SYNCHRONe_C_Code_10.7> : no loss, 0xFF fits in an uint8_t */
         if ( c_Header_pt->s_DestinationHost.s_val[ v_i ] != (uint8_t)K_ETH_ARP_BROADCAST_ADDR )
         {
            *p_broadcast = e_CMN_FLAG_NO ;
         }
      }
   }
   else
   {
      *p_broadcast = e_CMN_FLAG_NO ;
   }

   return ( v_isSame );
}
