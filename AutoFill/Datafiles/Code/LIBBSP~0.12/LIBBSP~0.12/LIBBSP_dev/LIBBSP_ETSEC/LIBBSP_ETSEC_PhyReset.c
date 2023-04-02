/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "HW_CONF.h"
#include "phy.h"
#include "LIBBSP_ETSEC_PhyReset.h"
/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

/* Appler dans ITF_T3 lorsque le Phy link n'est pas valide*/
TE_LIBBSP_ETSEC_NetworkStatus LIBBSP_ETSEC_PhyReset( const TE_LIBBSP_ETSEC_Network network)
{
	uint32_t v_controller;
	uint32_t v_phy;
	TE_LIBBSP_ETSEC_NetworkStatus v_ret;


	if ( (network < E_LIBBSP_ETSEC_NB_NETWORK) 
		&& (network >= E_LIBBSP_ETSEC_NETWORK_1 )
	)
	{
		/* get the v_controller that implements the network */
		v_controller = controller_of_network( (uint32_t)network ); /* %RELAX<SYNCHRONe_C_Code_10.7> Cast specific enum to generic data */

		v_phy = CONF_CPU.init[v_controller].phy_device;

		phy_reset(v_phy);

		v_ret = E_LIBBSP_ETSEC_OK;
   }
	else
	{
		v_ret = E_LIBBSP_ETSEC_KO;
	}

	return v_ret; /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */

}

/*==== END =============================================================================*/
