/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "MAC_interface.h"
#include "netif.h"
#include "HW_CONF.h"
#include "LL.h"

#include "LIBMCP_Types.h"
#include "LIBBSP_ETSEC_Init.h"
/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/* External parameter of the network interface */
/*TS_ETHERNET_stat_mac V_ETHERNET_stat_mac[ETHERNET_NB_NETWORKS];*/

/*==== Services ========================================================================*/

TE_LIBBSP_ETSEC_NetworkStatus LIBBSP_ETSEC_Init( const TE_LIBBSP_ETSEC_Network network)
{
   TE_LIBBSP_ETSEC_NetworkStatus v_ret;
   uint32_t v_controller;

   if ( (network < E_LIBBSP_ETSEC_NB_NETWORK) 
		&& (network >= E_LIBBSP_ETSEC_NETWORK_1 )
	)
   {
	   /* get the current v_controller */
	   v_controller = controller_of_network((uint32_t)network ); /* %RELAX<SYNCHRONe_C_Code_10.7> Cast specific enum to generic data */

	   /* stop RX and TX of v_controller of the network */
	   LL_MANAGEMENT_stop( v_controller, TRUE, TRUE );

	   v_ret = E_LIBBSP_ETSEC_OK;

   }
   else
   {
	   v_ret = E_LIBBSP_ETSEC_KO;
   }
   return v_ret; /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
}

/*==== END =============================================================================*/
