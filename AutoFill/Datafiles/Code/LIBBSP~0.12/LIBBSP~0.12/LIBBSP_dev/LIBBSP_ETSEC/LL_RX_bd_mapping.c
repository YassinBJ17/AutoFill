#include "LL_RX.h"

#ifdef ETSEC_TEST
/*#error "ETSEC_TEST RX_bd_mappings"*/
#pragma section CPM_RXBD_TABLE "sram_cpm_ll_rx_bds" "sram_cpm_ll_rx_bds" RW
#pragma use_section CPM_RXBD_TABLE V_LL_RX_bd_tables
TS_LIBBSP_ETSEC_t_ll_rx_bd_table V_LL_RX_bd_tables [C_LIBBSP_ETSEC_ETHERNET_NB_CONTROLLERS];
TS_LIBBSP_ETSEC_t_ll_rx_bd_table * p_ll_rxbd;
#endif

TS_LIBBSP_ETSEC_t_ll_p_rx_bd_tables * P_LIBBSP_ETSEC_ll_rx_bd_tables;
