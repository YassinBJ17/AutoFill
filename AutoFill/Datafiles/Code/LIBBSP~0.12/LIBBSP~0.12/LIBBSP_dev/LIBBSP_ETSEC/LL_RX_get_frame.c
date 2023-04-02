#include "LIBMCP_Types.h"
#include "LL.h"
#include "LL_RX.h"
#include "HW_CONF.h"

 void LL_RX_get_frame ( const uint32_t controller, 		               TE_LIBBSP_ETSEC_FrameStatus * const paFrame_status,                        const uint8_t ** const paFrame)  { 	const TS_LIBBSP_ETSEC_t_ll_rx_bd * p_rxbdtable; 	TS_LIBBSP_ETSEC_t_ll_rx_interface * p_interface; 	TS_LIBBSP_ETSEC_t_ll_rx_bd const *p_bd; 	p_interface = &(V_LL_RX_interface[controller]); 	p_rxbdtable = P_LIBBSP_ETSEC_ll_rx_bd_tables->V_LL_RX_bd_tables[controller].rxbd; 	p_bd = &(p_rxbdtable[p_interface->next_frame_to_get]);  	if ((p_bd->status & C_FEC_ETSEC_RXBD_E) == C_FEC_ETSEC_RXBD_NOT_E) { 		if ((p_bd->status & (C_FEC_ETSEC_RXBD_L_F | C_FEC_ETSEC_RXBD_ALL_ERROR)) 				== C_FEC_ETSEC_RXBD_NO_ERROR) { 			*paFrame_status = E_LIBBSP_ETSEC_NO_PHYSICAL_ERROR; 			*paFrame = p_bd->address; 		} else { 			*paFrame_status = E_LIBBSP_ETSEC_PHYSICAL_ERROR; 		} 	} else { 		*paFrame_status = E_LIBBSP_ETSEC_NO_FRAME_RECEIVED; 	} }
