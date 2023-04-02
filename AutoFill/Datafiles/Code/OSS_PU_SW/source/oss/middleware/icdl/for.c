#include "middleware/icdl/MID_ICDL_public.h"
#include "type/common_type.h"
#include "conf/oss_conf_public.h"
#include "memory/lib_critical_service_section_def_data.h"
#include "middleware/stack_ip/ETH_public.h"
#include "middleware/stack_ip/ETH_UDP_public.h"
#include "middleware/stack_ip/ETH_UDP_private.h"
#include "middleware/icdl/ICDL_public.h"
#include "middleware/icdl/ICDL_PLT_public.h"
#include "middleware/ethernet/DRV_COM_MNT_ETH_public.h"
#include "libtools/memory/LIB_MEM_public.h"
#include "middleware/logbook/logbook_public.h"
#include "libtools/time/LIB_TIME_public.h"

    for ( i = 0; i < ICDL_AS_NB_PORT; i++ )    {       if ( shmem.s_icdl_rx.rx_message_tab[i].s_port != 0 )       {          buffer.s_buffer = (int8_t*)(&(shmem.s_icdl_rx.rx_message_tab[i].s_data_buffer));          buffer.s_buffer_size = shmem.s_icdl_rx.rx_message_tab[i].s_length;          DRV_COM_MNT_ETH_HANDLE_PORT( K_OPEN_PORT,                                       shmem.s_icdl_rx.rx_message_tab[i].s_port,                                       e_CMN_FLAG_NO,                                       (ts_CMN_IOSP_BUFFER *)&(buffer),                                       &l_eth_status );       }    }
