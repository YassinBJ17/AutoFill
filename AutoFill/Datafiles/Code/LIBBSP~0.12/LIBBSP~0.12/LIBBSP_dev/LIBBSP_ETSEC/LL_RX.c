#include "LIBMCP_Types.h"
#include "LL.h"
#include "LL_RX.h"
#include "HW_CONF.h"

/* {{RELAX<SYNCHRONe_C_Code_17.4> Use of pointer array indexing :can't guess the size of the memory */

/* #define INCREMENT(n,size)    { n++; if (n>=size) { n=0;} } */


TS_LIBBSP_ETSEC_t_ll_rx_interface V_LL_RX_interface [C_LIBBSP_ETSEC_ETHERNET_NB_CONTROLLERS];

extern TS_LIBBSP_ETSEC_t_ll_p_rx_bd_tables * P_LIBBSP_ETSEC_ll_rx_bd_tables;
extern TS_LIBBSP_ETSEC_t_ll_p_rx_pools * P_LIBBSP_ETSEC_ll_rx_pools;

/*************************************************************************************
 *                                                                                   *
 * Nom : LL_RX_get_frame                                                             *
 *                                                                                   *
 * Description :                                                                     *
 * Cette fonction permet de recuperer une frame dans un BD de reception de           *
 *  l'interface specifiee                                                            *
 *                                                                                   *
 * Contraintes d'utilisation :                                                       *
 *  En cas de recuperation de trame (E_LIBBSP_ETSEC_NO_PHYSICAL_ERROR ou E_LIBBSP_ETSEC_PHYSICAL_ERROR)  *
 *  la liberation de la trame est a la charge de l'appelant.                         *
 * La liberation de la trame doit se faire avant un nouvel appel a LL_RX_get_frame   *
 * On ne retest pas l'overrun afin de depiler quand meme les trames recues           *
 *                                                                                   *
 *************************************************************************************/
void LL_RX_get_frame ( const uint32_t controller,
		               TE_LIBBSP_ETSEC_FrameStatus * const paFrame_status,
                       const uint8_t ** const paFrame) 
{
	const TS_LIBBSP_ETSEC_t_ll_rx_bd * p_rxbdtable;
	TS_LIBBSP_ETSEC_t_ll_rx_interface * p_interface;
	TS_LIBBSP_ETSEC_t_ll_rx_bd const *p_bd;

	p_interface = &(V_LL_RX_interface[controller]);

	p_rxbdtable = P_LIBBSP_ETSEC_ll_rx_bd_tables->V_LL_RX_bd_tables[controller].rxbd;
	p_bd = &(p_rxbdtable[p_interface->next_frame_to_get]); /* %RELAX<SYNCHRONe_C_Code_10.7> No precision lost: table of the wanted type */

	if ((p_bd->status & C_FEC_ETSEC_RXBD_E) == C_FEC_ETSEC_RXBD_NOT_E) {
		if ((p_bd->status & (C_FEC_ETSEC_RXBD_L_F | C_FEC_ETSEC_RXBD_ALL_ERROR))
				== C_FEC_ETSEC_RXBD_NO_ERROR) {
			*paFrame_status = E_LIBBSP_ETSEC_NO_PHYSICAL_ERROR;
			*paFrame = p_bd->address;
		} else {
			*paFrame_status = E_LIBBSP_ETSEC_PHYSICAL_ERROR;
		}
	} else {
		*paFrame_status = E_LIBBSP_ETSEC_NO_FRAME_RECEIVED;
	}
}


void LL_RX_get_bd ( const uint32_t controller, TS_LIBBSP_ETSEC_t_ll_rx_bd const ** p_bd )
{
	const TS_LIBBSP_ETSEC_t_ll_rx_bd * p_rxbdtable;
	TS_LIBBSP_ETSEC_t_ll_rx_interface * p_interface;

	p_interface = &(V_LL_RX_interface[controller]);
	p_rxbdtable = P_LIBBSP_ETSEC_ll_rx_bd_tables->V_LL_RX_bd_tables[controller].rxbd;
	*p_bd = &(p_rxbdtable[p_interface->next_frame_to_get]); /* %RELAX<SYNCHRONe_C_Code_10.7> No precision lost: table of the wanted type */
}

/*************************************************************************************
 *                                                                                   *
 * Nom : LL_RX_free_frame                                                            *
 *                                                                                   *
 * Description :                                                                     *
 * Cette fonction permet de redonner un BD au CPM une fois les donnees utilisees et  *
 *  de faire avancer le seuil                                                        *
 * Contraintes d'utilisation :                                                       *
 *  aucunes                                                                          *
 *                                                                                   *
 *************************************************************************************/
void LL_RX_free_frame(const uint32_t controller) {
	TS_LIBBSP_ETSEC_t_ll_rx_bd * p_rxbdtable;
	TS_LIBBSP_ETSEC_t_ll_rx_interface * p_interface;
	TS_LIBBSP_ETSEC_t_ll_rx_bd *p_bd;

	p_interface = &(V_LL_RX_interface[controller]);
	p_rxbdtable = P_LIBBSP_ETSEC_ll_rx_bd_tables->V_LL_RX_bd_tables[controller].rxbd;
	p_bd = &p_rxbdtable[p_interface->next_frame_to_get]; /* %RELAX<SYNCHRONe_C_Code_10.7> No precision lost: table of the wanted type */

    /* Set the Empty bit and let the Wrap bit unchanged */    
    p_bd->status = (uint16_t)(C_FEC_ETSEC_RXBD_E + (p_bd->status & C_FEC_ETSEC_RXBD_W));

    /* Increment the index to the next received frame */
    /*INCREMENT( p_interface -> next_frame_to_get, ETHERNET_RX_FIFO_SIZE );*/

    p_interface -> next_frame_to_get ++;

    if (p_interface -> next_frame_to_get >= C_LIBBSP_ETSEC_ETHERNET_RX_FIFO_SIZE)
    {
    	p_interface -> next_frame_to_get = 0ul;
    }
}

/*************************************************************************************
 *                                                                                   *
 * Nom : LL_RX_initialize                                                            *
 *                                                                                   *
 * Description :                                                                     *
 * Cette fonction d'initialiser la gestion des BDs pour la reception ethernet sur    *
 *   une interface specifiee.                                                        *
 * Pour simplifier le driver, une frame ethernet est recue entierement dans un seul  *
 *   BD                                                                              *
 *                                                                                   *
 * Contraintes d'utilisation :                                                       *
 *  aucunes                                                                          *
 *                                                                                   *
 *************************************************************************************/
const uint8_t *LL_RX_initialize( const uint32_t controller) 

{
	TS_LIBBSP_ETSEC_t_ll_rx_bd * p_rxbdtable;
	/* t_ll_rx_interface * p_interface; */
	const uint8_t * p_bdtable;
	TS_LIBBSP_ETSEC_t_ll_rx_pool * p_rxpool;
	uint32_t v_bd_index;
	TS_LIBBSP_ETSEC_t_ll_rx_bd *p_bd;

	p_rxbdtable  = P_LIBBSP_ETSEC_ll_rx_bd_tables->V_LL_RX_bd_tables[ controller ].rxbd;
	p_rxpool     = &(P_LIBBSP_ETSEC_ll_rx_pools->V_LL_RX_pools[ controller ]);
	/*p_interface  = &(V_LL_RX_interface[ controller ]); */

	/*p_interface -> next_frame_to_get = (uint32_t) 0;
	p_interface -> controller        = controller;*/

	p_bd = &p_rxbdtable [ 0 ]; /* %RELAX<SYNCHRONe_C_Code_10.7> No precision lost: table of the wanted type */

	/* Tout les BD sont a Empty (disponibles pour le CPM) */
	for (v_bd_index = (uint32_t) 0; v_bd_index < C_LIBBSP_ETSEC_ETHERNET_RX_FIFO_SIZE; v_bd_index++) 
    {
		p_bd = &p_rxbdtable [ v_bd_index ]; /* %RELAX<SYNCHRONe_C_Code_10.7> No precision lost: table of the wanted type */
		p_bd -> address = &(p_rxpool->rxbuffer[v_bd_index].rxbyte[0]);
		p_bd -> status = C_FEC_ETSEC_RXBD_E;
	}

	/* Le dernier BD a en plus le Wrap positionn� */
	p_bd -> status = C_FEC_ETSEC_RXBD_E_W;

	p_bdtable = (const uint8_t *) p_rxbdtable; /* %RELAX<SYNCHRONe_C_Code_10.7, SYNCHRONe_C_Code_11.1> cast of pointer necessary to affect the value (adress) */

	return (p_bdtable);
}


/* }} RELAX<SYNCHRONe_C_Code_17.4> */
