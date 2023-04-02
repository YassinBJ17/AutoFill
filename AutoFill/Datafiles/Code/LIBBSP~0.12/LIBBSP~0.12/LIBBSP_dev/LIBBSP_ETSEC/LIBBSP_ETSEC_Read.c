/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LL.h"
#include "LL_RX.h"
#include "HW_CONF.h"

#include "LIBBSP_ETSEC_Read.h"
#include "LIBMCP_Types.h"
#include <string.h>
#include "Memcpy.h"

/*==== Definitions =====================================================================*/

#define C_ETSEC_CHECKSUM_LENGTH 4
/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

void LIBBSP_ETSEC_Read ( const TE_LIBBSP_ETSEC_Network network,
						uint8_t * const Buffer_read, /* %RELAX<SYNCHRONe_C_Code_8.18> Output used only by subfunction is not detected as output */
						uint32_t * const v_size,
						TE_LIBBSP_ETSEC_FrameStatus * const v_frame_status_out,
						TE_LIBBSP_ETSEC_NetworkStatus * const v_ret)
{
    TE_LIBBSP_ETSEC_FrameStatus v_frame_status;
    void *pt_frame;
    TS_LIBBSP_ETSEC_t_ll_rx_bd const * pt_bd;
    uint32_t v_controller;

	/* *v_size = 0ul; */
	*v_frame_status_out = E_LIBBSP_ETSEC_NO_FRAME_RECEIVED;

	if ( (network < E_LIBBSP_ETSEC_NB_NETWORK) 
		&& (network >= E_LIBBSP_ETSEC_NETWORK_1 )
	)
	{


	    v_controller = controller_of_network( (uint32_t)network ); /* %RELAX<SYNCHRONe_C_Code_10.7> Cast specific enum to generic data */

	    /* Verifier qu'il n'y a pas eu d'overrun en reception */
	    LL_RX_check_overrun (v_controller);

	    /* Verifier si le CPM a recue une trame sans erreur */
	    LL_RX_get_frame(v_controller, &v_frame_status, &pt_frame);
	    if (v_frame_status == E_LIBBSP_ETSEC_NO_PHYSICAL_ERROR)
	    {
	        /* Taille de la frame */
	        LL_RX_get_bd(v_controller, &pt_bd);
	       		   
			*v_size = ((uint32_t)pt_bd->length - (uint32_t)C_ETSEC_CHECKSUM_LENGTH); /* %RELAX<SYNCHRONe_C_Code_10.7> switch from 16 to 32 bits , no loss of precision */
			
	        /* Recopie de la trame recu */
	        LibC_Memcpy(&Buffer_read[0], (void *) pt_frame, *v_size); /* %RELAX<SYNCHRONe_C_Code_17.4> Use of pointer array indexing :can't guess the size of the memory */

	    }
	    if (v_frame_status != E_LIBBSP_ETSEC_NO_FRAME_RECEIVED)
	    {
	        /* Rendre le BD au CPM */
	        LL_RX_free_frame(v_controller);
	    }

	    *v_frame_status_out = v_frame_status;

	    *v_ret = E_LIBBSP_ETSEC_OK;


	}
	else
	{
		*v_ret = E_LIBBSP_ETSEC_KO;
	}

}

/*==== END =============================================================================*/
