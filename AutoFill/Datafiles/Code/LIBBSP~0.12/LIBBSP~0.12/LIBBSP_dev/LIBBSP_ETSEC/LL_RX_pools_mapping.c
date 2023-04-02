#include "LL_RX.h"

#ifdef ETSEC_TEST
#pragma section CPM_RX_POOL "sram_cpm_ll_rx_pool" "sram_cpm_ll_rx_pool" R
#pragma use_section CPM_RX_POOL V_LL_RX_pools
TS_LIBBSP_ETSEC_t_ll_rx_pool V_LL_RX_pools [C_LIBBSP_ETSEC_ETHERNET_NB_CONTROLLERS];
TS_LIBBSP_ETSEC_t_ll_rx_pool * p_ll_rxpool;
#endif

TS_LIBBSP_ETSEC_t_ll_p_rx_pools * P_LIBBSP_ETSEC_ll_rx_pools;
