#include "LL_TX.h"

#ifdef ETSEC_TEST
#pragma section CPM_TX_POOL "sram_cpm_ll_tx_pool" "sram_cpm_ll_tx_pool" R
#pragma use_section CPM_TX_POOL V_LL_TX_pools
TS_LIBBSP_ETSEC_t_ll_tx_pool V_LL_TX_pools [C_LIBBSP_ETSEC_ETHERNET_NB_CONTROLLERS];
TS_LIBBSP_ETSEC_t_ll_tx_pool * p_ll_txpool;
#endif

TS_LIBBSP_ETSEC_t_ll_p_tx_pools * P_LIBBSP_ETSEC_ll_tx_pools;
