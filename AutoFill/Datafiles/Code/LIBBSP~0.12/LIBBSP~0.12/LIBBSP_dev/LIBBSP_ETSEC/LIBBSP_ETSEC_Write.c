/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LL_TX.h"
#include "LL.h"
#include "HW_CONF.h"

#include "LIBBSP_ETSEC_Write.h"
#include "LIBMCP_Types.h"
#include <string.h>
#include "Memcpy.h"
/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

TE_LIBBSP_ETSEC_NetworkStatus LIBBSP_ETSEC_Write ( const TE_LIBBSP_ETSEC_Network network, const uint8_t* const v_BuffWrite, const uint32_t v_size)
{
	TE_LIBBSP_ETSEC_NetworkStatus v_ret;
	TS_LIBBSP_ETSEC_t_ll_tx_bd *pt_bd;
	uint32_t v_controller;


	if ( (network < E_LIBBSP_ETSEC_NB_NETWORK) 
		&& (network >= E_LIBBSP_ETSEC_NETWORK_1 )
	)
	{

	    /* get the v_controller that implements the network */
	    v_controller = controller_of_network( (uint32_t)network ); /* %RELAX<SYNCHRONe_C_Code_10.7> Cast specific enum to generic data */

	    /* Recuperer un bd pour envoyer la trame */
	    LL_TX_get_frame(v_controller, &pt_bd);

	    /* Recopie de la trame */ 
		/* {{RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> Pointer conversion : Use generic pointer for memccpy */
	    LibC_Memcpy((void *)pt_bd->address, v_BuffWrite, v_size);
		/* }} RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> */

	    pt_bd->length = (uint16_t)v_size;/* %RELAX<SYNCHRONe_C_Code_10.7> precision should be fine: size cannot be too long for embedded system */

	    LL_TX_send_frame(v_controller, pt_bd);

		v_ret = E_LIBBSP_ETSEC_OK;

	}
	else
	{
		v_ret = E_LIBBSP_ETSEC_KO;
	}

	return v_ret; /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */

}

/*==== END =============================================================================*/
