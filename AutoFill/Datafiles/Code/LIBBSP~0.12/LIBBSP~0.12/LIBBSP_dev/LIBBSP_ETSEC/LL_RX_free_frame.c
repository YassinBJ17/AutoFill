#include "LIBMCP_Types.h"
#include "LL.h"
#include "LL_RX.h"
#include "HW_CONF.h"

 void LL_RX_free_frame(const uint32_t controller) { 	TS_LIBBSP_ETSEC_t_ll_rx_bd * p_rxbdtable; 	TS_LIBBSP_ETSEC_t_ll_rx_interface * p_interface; 	TS_LIBBSP_ETSEC_t_ll_rx_bd *p_bd; 	p_interface = &(V_LL_RX_interface[controller]); 	p_rxbdtable = P_LIBBSP_ETSEC_ll_rx_bd_tables->V_LL_RX_bd_tables[controller].rxbd; 	p_bd = &p_rxbdtable[p_interface->next_frame_to_get];      p_bd->status = (uint16_t)(C_FEC_ETSEC_RXBD_E + (p_bd->status & C_FEC_ETSEC_RXBD_W));     p_interface -> next_frame_to_get ++;     if (p_interface -> next_frame_to_get >= C_LIBBSP_ETSEC_ETHERNET_RX_FIFO_SIZE)     {     	p_interface -> next_frame_to_get = 0ul;     } }
