#include "LIBMCP_Types.h"
#include "HW_CONF.h"
#include "LL.h"
#include "LL_TX.h"
#include "MAC_interface.h"

 void LL_TX_get_frame (const uint32_t controller, TS_LIBBSP_ETSEC_t_ll_tx_bd ** const p_bd) {     TS_LIBBSP_ETSEC_t_ll_tx_bd * p_txbdtable;     p_txbdtable = P_LIBBSP_ETSEC_ll_tx_bd_tables->V_LL_TX_bd_tables[controller].txbd;     *p_bd = &(p_txbdtable [V_LL_TX_interface [controller].next_frame_to_send]);  }
