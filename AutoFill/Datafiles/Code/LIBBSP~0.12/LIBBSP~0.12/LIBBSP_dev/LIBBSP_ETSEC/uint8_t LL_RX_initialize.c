#include "LIBMCP_Types.h"
#include "LL.h"
#include "LL_RX.h"
#include "HW_CONF.h"

 const uint8_t *LL_RX_initialize( const uint32_t controller)  { 	TS_LIBBSP_ETSEC_t_ll_rx_bd * p_rxbdtable; 	const uint8_t * p_bdtable; 	TS_LIBBSP_ETSEC_t_ll_rx_pool * p_rxpool; 	uint32_t v_bd_index; 	TS_LIBBSP_ETSEC_t_ll_rx_bd *p_bd; 	p_rxbdtable  = P_LIBBSP_ETSEC_ll_rx_bd_tables->V_LL_RX_bd_tables[ controller ].rxbd; 	p_rxpool     = &(P_LIBBSP_ETSEC_ll_rx_pools->V_LL_RX_pools[ controller ]); 	p_bd = &p_rxbdtable [ 0 ];  	for (v_bd_index = (uint32_t) 0; v_bd_index < C_LIBBSP_ETSEC_ETHERNET_RX_FIFO_SIZE; v_bd_index++)      { 		p_bd = &p_rxbdtable [ v_bd_index ];  		p_bd -> address = &(p_rxpool->rxbuffer[v_bd_index].rxbyte[0]); 		p_bd -> status = C_FEC_ETSEC_RXBD_E; 	} 	p_bd -> status = C_FEC_ETSEC_RXBD_E_W; 	p_bdtable = (const uint8_t *) p_rxbdtable;  	return (p_bdtable); }
