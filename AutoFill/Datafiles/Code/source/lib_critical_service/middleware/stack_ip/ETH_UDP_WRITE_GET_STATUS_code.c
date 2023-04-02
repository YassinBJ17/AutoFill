/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION :
 * -------------------------------------------------------------------------- */

#include "middleware/stack_ip/ETH_UDP_public.h"
#include "middleware/ethernet/ETH_porting.h"

uint32_t ETH_UDP_WRITE_GET_STATUS( ts_ETH_UDP_BUFF_STATS * const p_status )
{
   ts_ETH_HAL_STATS_TRANSFERT v_stats;
   uint32_t v_eth_tx_status ;

   v_eth_tx_status = hal_get_status_write_pt( &v_stats );

   /* >RELAX<SYNCHRONe_C_Code_10.7>: cast is safe, length>0 and absval(int32_t) fits on uint32_t */
   p_status->s_UDP_len = (uint32_t)v_stats.s_len ;

   if ( v_stats.s_status == e_CMN_FLAG_COMPLETE )
   {
      p_status->s_UDP_done = p_status->s_UDP_len;
   }
   else
   {
      p_status->s_UDP_done = 0ul ;
   }

   return v_eth_tx_status;

}

