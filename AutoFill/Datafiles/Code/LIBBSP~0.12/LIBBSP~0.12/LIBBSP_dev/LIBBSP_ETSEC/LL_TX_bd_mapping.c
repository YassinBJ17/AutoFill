#include "LL_TX.h"

#ifdef ETSEC_TEST
#pragma section CPM_TXBD_TABLE "sram_cpm_ll_tx_bds" "sram_cpm_ll_tx_bds" RW
#pragma use_section CPM_TXBD_TABLE V_LL_TX_bd_tables
TS_LIBBSP_ETSEC_t_ll_tx_bd_table V_LL_TX_bd_tables [C_LIBBSP_ETSEC_ETHERNET_NB_CONTROLLERS];
TS_LIBBSP_ETSEC_t_ll_tx_bd_table * p_ll_txbd;
#endif

TS_LIBBSP_ETSEC_t_ll_p_tx_bd_tables * P_LIBBSP_ETSEC_ll_tx_bd_tables;
