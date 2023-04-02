/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "HW_CONF.h"
#include "netif.h"
#include "LL.h"

#include "LIBBSP_ETSEC_Start.h"
#include "LIBMCP_Types.h"
/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

TE_LIBBSP_ETSEC_NetworkStatus LIBBSP_ETSEC_Start( const TE_LIBBSP_ETSEC_Network network, const TS_LIBBSP_ETSEC_ConfHostMac * const mac_addr)
{
   uint32_t v_controller;
   TE_LIBBSP_ETSEC_NetworkStatus v_ret;

	if ( (network < E_LIBBSP_ETSEC_NB_NETWORK) 
		&& (network >= E_LIBBSP_ETSEC_NETWORK_1 )
	)
	{

	   /* get the v_controller that implements the network */
	   v_controller = controller_of_network( (uint32_t)network ); /* %RELAX<SYNCHRONe_C_Code_10.7> Cast specific enum to generic data */


	   /* Initialise the v_controller */
	   LL_MANAGEMENT_init( v_controller, mac_addr);

	   v_ret = E_LIBBSP_ETSEC_OK;
	}
	else
	{
		v_ret = E_LIBBSP_ETSEC_KO;
	}

	return v_ret; /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
}

/*==== END =============================================================================*/
