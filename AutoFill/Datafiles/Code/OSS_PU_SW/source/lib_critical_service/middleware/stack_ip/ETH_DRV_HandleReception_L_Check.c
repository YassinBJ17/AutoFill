#include "middleware/stack_ip/ETH_public.h"
#include "middleware/stack_ip/ETH_private.h"
#include "middleware/stack_ip/ETH_conf.h"
#include "middleware/stack_ip/ETH_DEF_HEADER_common.h"
#include "middleware/ethernet/ETH_porting.h"
#include "libtools/time/LIB_TIME_public.h"

 te_CMN_FLAG_QUESTION ETH_DRV_HandleReception_L_Check(const ts_CMN_IOSP_BUFFER * const p_buff ,                                                      te_CMN_FLAG_QUESTION *     const p_broadcast) {    const ts_ETH_EthernetHeader * c_Header_pt  = ( const ts_ETH_EthernetHeader * )  p_buff->s_buffer ;    te_CMN_FLAG_QUESTION          v_isSame ;    uint32_t                      v_i ;    v_isSame = ETH_DRV_IsSameMAC_ADDR( &v_ETH_DRV_EtherOwnAddr.s_HwAddress ,                            &c_Header_pt->s_DestinationHost );    if (v_isSame == e_CMN_FLAG_NO )    {       *p_broadcast = e_CMN_FLAG_YES ;       for ( v_i = 0ul ; v_i < (uint32_t)K_HW_ADDR_LEN ; v_i ++ )       {          if ( c_Header_pt->s_DestinationHost.s_val[ v_i ] != (uint8_t)K_ETH_ARP_BROADCAST_ADDR )          {             *p_broadcast = e_CMN_FLAG_NO ;          }       }    }    else    {       *p_broadcast = e_CMN_FLAG_NO ;    }    return ( v_isSame ); }
