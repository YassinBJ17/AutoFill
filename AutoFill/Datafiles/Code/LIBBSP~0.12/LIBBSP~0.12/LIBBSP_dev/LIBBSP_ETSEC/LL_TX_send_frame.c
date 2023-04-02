#include "LIBMCP_Types.h"
#include "HW_CONF.h"
#include "LL.h"
#include "LL_TX.h"
#include "MAC_interface.h"

 void LL_TX_send_frame (const uint32_t controller,  TS_LIBBSP_ETSEC_t_ll_tx_bd * const p_bd ) {     TS_ll_tx_interface * p_interface;     TS_ETHERNET_stat_mac *p_stats_mac;     p_interface = &(V_LL_TX_interface [controller]);     p_stats_mac = &(V_ETHERNET_stat_mac [controller]);     p_interface -> next_frame_to_send ++;     if (p_interface -> next_frame_to_send  >= C_LIBBSP_ETSEC_ETHERNET_TX_FIFO_SIZE)     {     	p_interface -> next_frame_to_send  = 0ul;     }     p_stats_mac->MACOutFrames = p_stats_mac->MACOutFrames + 1ul;     p_stats_mac->MACOutOctets = p_stats_mac->MACOutOctets + (uint32_t)p_bd->length;     p_bd->status |= C_FEC_ETSEC_TXBD_R_L; }
