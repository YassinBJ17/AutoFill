#include "middleware/ethernet/DRV_COM_MNT_ETH_conf.h"
#include "middleware/ethernet/DRV_COM_MNT_ETH_public.h"
#include "middleware/stack_ip/ETH_IP_private.h"
#include "middleware/stack_ip/ETH_COMM_public.h"
#include "middleware/stack_ip/ETH_UDP_public.h"
#include "libtools/memory/LIB_MEM_public.h"

#if (ICDL_TIME_CONF_ENABLE != 0)
   CMN_SYSTEM_TIME_t    v_duration_mnt_eth_read_crc_time;
#endif
/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
void DRV_COM_MNT_ETH_READ ( ts_DRV_COM_MNT_ETH_RX * p_eth_rx )
{
#if (ICDL_TIME_CONF_ENABLE != 0)
   CMN_SYSTEM_TIME_t    v_start_time;
   CMN_SYSTEM_TIME_t    v_end_time;
#endif
   ts_ETH_UDP_RECEIVE_BUFF *pt_port ;
   t_eth_comm_status status;
   /*
    * Check the command can be handled
    */
   pt_port = ETH_UDP_GetReceivedBufferPort ( (uint32_t)p_eth_rx->LCH_CTRL_RX_MSG_UDP_PORT_SRC ) ;

   if ( pt_port != NULL )
   {
#if (ICDL_TIME_CONF_ENABLE != 0 )
      LIBT_TIME_GET( &v_start_time );
#endif
      status = ETH_COMM_read( p_eth_rx->LCH_CTRL_RX_DATA,
                              (uint32_t)DRV_COM_MNT_ETH_MSG_RX_MAX,
                              &p_eth_rx->LCH_CTRL_RX_DATA_COUNT,
                              &p_eth_rx->LCH_CTRL_RX_MSG_UDP_PORT_DST,
                              &p_eth_rx->LCH_CTRL_RX_MSG_IP_DST,
                              pt_port->s_BufReception );
      p_eth_rx->LCH_CTRL_RX_status = status;
#if (ICDL_TIME_CONF_ENABLE != 0)
      LIBT_TIME_GET( &v_end_time );
      v_duration_mnt_eth_read_crc_time = v_end_time - v_start_time;
#endif
   }
}

/* ---------- internal operation bodies: ------------------------------------ */
