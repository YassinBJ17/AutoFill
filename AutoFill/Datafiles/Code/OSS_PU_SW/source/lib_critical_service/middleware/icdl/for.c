#include "middleware/icdl/ICDL_public.h"
#include "type/common_type.h"
#include "memory/lib_critical_service_section_def_data.h"
#include "middleware/stack_ip/ETH_public.h"
#include "middleware/stack_ip/ETH_UDP_public.h"
#include "middleware/stack_ip/ETH_UDP_private.h"
#include "middleware/icdl/ICDL_public.h"
#include "middleware/icdl/ICDL_PLT_public.h"
#include "middleware/ethernet/DRV_COM_MNT_ETH_public.h"
#include "middleware/accom/accom_public.h"
#include "libtools/memory/LIB_MEM_public.h"

    for ( i = 0; i < ICDL_AS_NB_PORT; i++ )    {       if ( shmem.s_icdl_tx.tx_message_tab[i].s_length != 0 )       {          if ( ( shmem.s_icdl_tx.tx_message_tab[i].s_port >= 50000 ) &&               ( shmem.s_icdl_tx.tx_message_tab[i].s_port < 60000 ) )          {             msg.health_word     = shmem.s_health_wd_status.u_word;             msg.opp_health_word = shmem.s_o_health_wd_status_ccdl.u_word;             LIB_MEM_CPY( (int8_t * const) msg.data,                          (int8_t const * const) shmem.s_icdl_tx.tx_message_tab[i].s_data_buffer, 248 );             ICDL_PLT_SendToMU( &msg, sizeof(msg), shmem.s_icdl_tx.tx_message_tab[i].s_port );          }          else          {             l_eth_tx.LCH_CTRL_TX_MSG_DATA         = &(shmem.s_icdl_tx.tx_message_tab[i].s_data_buffer[0]);             l_eth_tx.LCH_CTRL_TX_MSG_SIZE         = shmem.s_icdl_tx.tx_message_tab[i].s_length;             l_eth_tx.LCH_CTRL_TX_MSG_UDP_PORT_SRC = (uint16_t)shmem.s_icdl_tx.tx_message_tab[i].s_port;             l_eth_tx.LCH_CTRL_TX_MSG_UDP_PORT_DST = (uint16_t)shmem.s_icdl_tx.tx_message_tab[i].s_port;             if ( shmem.s_icdl_tx.tx_message_tab[i].s_port == K_UOD_UDP_PORTS_SRC )             {                l_eth_tx.LCH_CTRL_TX_MSG_IP_DST = (uint32_t)(ETH_CFEX_BENCH_EtherAddr.u_IP);             }             else             {                l_eth_tx.LCH_CTRL_TX_MSG_IP_DST = (uint32_t)(ETH_CFEX_CDM_AS_EtherAddr.u_IP);             }             DRV_COM_MNT_ETH_WRITE( &l_eth_tx );          }          shmem.s_icdl_tx.tx_message_tab[i].s_length = 0;        }    }
