#include "LIBMCP_Types.h"
#include "LL.h"
#include "LL_RX.h"
#include "HW_CONF.h"

 void LL_RX_get_bd ( const uint32_t controller, TS_LIBBSP_ETSEC_t_ll_rx_bd const ** p_bd ) { 	const TS_LIBBSP_ETSEC_t_ll_rx_bd * p_rxbdtable; 	TS_LIBBSP_ETSEC_t_ll_rx_interface * p_interface; 	p_interface = &(V_LL_RX_interface[controller]); 	p_rxbdtable = P_LIBBSP_ETSEC_ll_rx_bd_tables->V_LL_RX_bd_tables[controller].rxbd; 	*p_bd = &(p_rxbdtable[p_interface->next_frame_to_get]);  }
