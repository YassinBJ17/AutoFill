/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LL.h"
#include "LL_RX.h"
#include "LL_TX.h"
#include "HW_CONF.h"
#include "LIBMCP_Types.h"
#include "MAC_interface.h"
#include "LIBBSP_ETSEC_InitRxTx.h"

/*==== Definitions =====================================================================*/
TS_ETHERNET_stat_mac V_ETHERNET_stat_mac[ETHERNET_NB_NETWORKS];
extern TS_LIBBSP_ETSEC_t_ll_rx_interface V_LL_RX_interface [C_LIBBSP_ETSEC_ETHERNET_NB_CONTROLLERS];
extern TS_ll_tx_interface V_LL_TX_interface [C_LIBBSP_ETSEC_ETHERNET_NB_CONTROLLERS]; /*why is the TS_ll_tx_interface also not changed to a version with TS_LIBBSP_ETSEC appended? */
/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
/* Appel� dans ITF_T1 si Phy link est valid (flag qui est valoris� dans T3)*/
TE_LIBBSP_ETSEC_NetworkStatus LIBBSP_ETSEC_InitRxTx( const TE_LIBBSP_ETSEC_Network network, const TE_LIBBSP_ETSEC_NetConfigStart network_config)
{
	uint32_t v_controller;
	boolean_t v_rx_enable;
	boolean_t v_tx_enable;
	TS_ll_tx_interface * pt_interface_tx;
	TS_LIBBSP_ETSEC_t_ll_rx_interface * pt_interface_rx;
	TE_LIBBSP_ETSEC_NetworkStatus v_ret;

   if ( (network < E_LIBBSP_ETSEC_NB_NETWORK) 
		&& (network >= E_LIBBSP_ETSEC_NETWORK_1 )
	)
   {

		/* get the v_controller that implements the network */
		v_controller = controller_of_network((uint32_t)network ); /* %RELAX<SYNCHRONe_C_Code_10.7> Cast specific enum to generic data */

		/* {{RELAX<SYNCHRONe_C_Code_10.7> adress operand not taken in account */
		pt_interface_rx  = &(V_LL_RX_interface[v_controller]);
		pt_interface_tx = &(V_LL_TX_interface [v_controller]);
		/* }} RELAX<SYNCHRONe_C_Code_10.7> */


		pt_interface_rx -> next_frame_to_get = (uint32_t) 0;
		pt_interface_rx -> controller        = v_controller;

		pt_interface_tx->hw_txbd = (uint32_t)0;
		pt_interface_tx->next_frame_to_send = (uint32_t)0;
		pt_interface_tx->controler = v_controller;

		/* reset the statistics of the network */
		V_ETHERNET_stat_mac[network].MACIndex = (uint16_t)network; /* %RELAX<SYNCHRONe_C_Code_10.7> Cast specific enum to generic data */
		V_ETHERNET_stat_mac[network].MACInOverrun          = (uint32_t)0;
		V_ETHERNET_stat_mac[network].MACCRCErrors          = (uint32_t)0;
		V_ETHERNET_stat_mac[network].MACAlignmentErrors    = (uint32_t)0;
		V_ETHERNET_stat_mac[network].MACFrameLengthErrors  = (uint32_t)0;
		V_ETHERNET_stat_mac[network].MACIntMACRxErrors     = (uint32_t)0;
		V_ETHERNET_stat_mac[network].MACInOctets           = (uint32_t)0;
		V_ETHERNET_stat_mac[network].MACInFrames           = (uint32_t)0;
		V_ETHERNET_stat_mac[network].MACOutOctets          = (uint32_t)0;
		V_ETHERNET_stat_mac[network].MACOutFrames          = (uint32_t)0;
		V_ETHERNET_stat_mac[network].MACOutDiscards        = (uint32_t)0;

		switch( network_config )
		{

			case E_LIBBSP_ETSEC_START_NETWORK_TX:

				v_tx_enable = TRUE;
				v_rx_enable = FALSE;

				break;
			case E_LIBBSP_ETSEC_START_NETWORK_RX:

				v_tx_enable = FALSE;
				v_rx_enable = TRUE;

				break;
			case E_LIBBSP_ETSEC_START_NETWORK_RX_TX:

				v_tx_enable = TRUE;
				v_rx_enable = TRUE;

				break;
			default:

				v_tx_enable = FALSE;
				v_rx_enable = FALSE;

				break;
		}

		LL_MANAGEMENT_start( v_controller, v_rx_enable, v_tx_enable );

		v_ret = E_LIBBSP_ETSEC_OK;

   }
   else
   {
	   v_ret = E_LIBBSP_ETSEC_KO;
   }

   return v_ret; /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
}

/*==== END =============================================================================*/
