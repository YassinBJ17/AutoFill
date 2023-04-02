#include "LIBMCP_Types.h"
#include "HW_CONF.h"
#include "LL.h"
#include "LL_TX.h"
#include "MAC_interface.h"

 const uint8_t *LL_TX_initialize (const uint32_t controller) {     const uint8_t * p_bdtable;     TS_LIBBSP_ETSEC_t_ll_tx_pool * p_txpool;     uint32_t index;     p_txpool = &(P_LIBBSP_ETSEC_ll_tx_pools->V_LL_TX_pools [controller]);     for (index=0ul ; index < C_LIBBSP_ETSEC_ETHERNET_TX_FIFO_SIZE ; index++)     {         P_LIBBSP_ETSEC_ll_tx_bd_tables->V_LL_TX_bd_tables [controller].txbd [index].address = &(p_txpool->txbuffer [index].txbyte[0]);         P_LIBBSP_ETSEC_ll_tx_bd_tables->V_LL_TX_bd_tables [controller].txbd [index].status = C_FEC_ETSEC_TXBD_NOT_R;     }     P_LIBBSP_ETSEC_ll_tx_bd_tables->V_LL_TX_bd_tables [controller].txbd [C_LIBBSP_ETSEC_ETHERNET_TX_FIFO_SIZE - 1ul].status =           P_LIBBSP_ETSEC_ll_tx_bd_tables->V_LL_TX_bd_tables [controller].txbd [C_LIBBSP_ETSEC_ETHERNET_TX_FIFO_SIZE - 1ul].status | C_FEC_ETSEC_TXBD_W;     p_bdtable = (const uint8_t *)(P_LIBBSP_ETSEC_ll_tx_bd_tables->V_LL_TX_bd_tables [controller].txbd);      return (p_bdtable); }
