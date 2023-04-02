/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "HW_CONF.h"
#include "LL.h"

#include "LIBBSP_ETSEC_Stop.h"
#include "LIBMCP_Types.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

TE_LIBBSP_ETSEC_NetworkStatus LIBBSP_ETSEC_Stop( const TE_LIBBSP_ETSEC_Network network, const TE_LIBBSP_ETSEC_NetConfigStop network_config  )
{
   boolean_t v_rx_disable;
   boolean_t v_tx_disable;
   uint32_t v_controller;
   TE_LIBBSP_ETSEC_NetworkStatus v_ret;

	if ( (network < E_LIBBSP_ETSEC_NB_NETWORK) 
		&& (network >= E_LIBBSP_ETSEC_NETWORK_1 )
	)
	{


	   /* get the v_controller that implements the network */
	   v_controller = controller_of_network((uint32_t) network ); /* %RELAX<SYNCHRONe_C_Code_10.7> Cast specific enum to generic data */

	   switch( network_config )
	   {

			case E_LIBBSP_ETSEC_STOP_NETWORK_TX:

				v_tx_disable = TRUE;
				v_rx_disable = FALSE;

				break;
			case E_LIBBSP_ETSEC_STOP_NETWORK_RX:

				v_tx_disable = FALSE;
				v_rx_disable = TRUE;

				break;
			case E_LIBBSP_ETSEC_STOP_NETWORK_RX_TX:

				v_tx_disable = TRUE;
				v_rx_disable = TRUE;

				break;
			default:

				v_tx_disable = FALSE;
				v_rx_disable = FALSE;

				break;
	   }

	   LL_MANAGEMENT_stop (v_controller, v_rx_disable, v_tx_disable);

	   v_ret = E_LIBBSP_ETSEC_OK;
	}
	else
	{
		v_ret = E_LIBBSP_ETSEC_KO;
	}

	return v_ret; /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
}

/*==== END =============================================================================*/
