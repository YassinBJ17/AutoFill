/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "HW_CONF.h"
#include "phy.h"
#include "LIBBSP_ETSEC_GetPhyState.h"
/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

/* Appeler dans ITF_T3 pour connaitrre l'etat phy*/
void LIBBSP_ETSEC_GetPhyState( const TE_LIBBSP_ETSEC_Network network, boolean_t * const PhyState, TE_LIBBSP_ETSEC_NetworkStatus * const v_ret)
{
	uint32_t v_controller;
	uint32_t v_phy;


	if ( (network < E_LIBBSP_ETSEC_NB_NETWORK) 
		&& (network >= E_LIBBSP_ETSEC_NETWORK_1 )
	)
	{
		/* get the v_controller that implements the network */
		v_controller = controller_of_network((uint32_t)network ); /* %RELAX<SYNCHRONe_C_Code_10.7> Cast specific enum to generic data */

		v_phy = CONF_CPU.init[v_controller].phy_device;

		*PhyState = phy_is_link_up(v_phy);

		*v_ret = E_LIBBSP_ETSEC_OK;
   }
	else
	{
		*v_ret = E_LIBBSP_ETSEC_KO;

		*PhyState = FALSE;
	}

}

/*==== END =============================================================================*/
