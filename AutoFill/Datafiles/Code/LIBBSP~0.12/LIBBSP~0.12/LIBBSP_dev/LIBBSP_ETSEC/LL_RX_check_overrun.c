#include "LL_RX.h"

extern TS_LIBBSP_ETSEC_t_ll_p_rx_bd_tables * P_LIBBSP_ETSEC_ll_rx_bd_tables;

/*************************************************************************************
 *                                                                                   *
 * Nom : LL_RX_check_overrun                                                         *
 *                                                                                   *
 * Description :                                                                     *
 * Cette fonction permet de tester si il y a eu un overrun en reception sur          *
 *  l'interface specifiee et dans ce cas de flusher les trames recues                *
 *                                                                                   *
 * Contraintes d'utilisation :                                                       *
 * Doit etre appelle dans ethernet receive avant LL_RX_get_frame                     *
 *                                                                                   *
 *************************************************************************************/
void LL_RX_check_overrun (const uint32_t controller) 
{
	const TS_LIBBSP_ETSEC_t_ll_rx_bd * p_rxbdtable;
	TS_LIBBSP_ETSEC_t_ll_rx_interface * p_interface;
	TS_LIBBSP_ETSEC_t_ll_rx_bd const *p_bd;
    uint32_t v_bd_index;
    
	p_interface = &(V_LL_RX_interface [controller]);
    p_rxbdtable = P_LIBBSP_ETSEC_ll_rx_bd_tables->V_LL_RX_bd_tables [controller].rxbd;
    /* Get the index of the buffer        */
    /* that is placed in the ring N       */
    /* times before the current buffer    */
    if( p_interface->next_frame_to_get >= ETHERNET_RX_FIFO_THRESHOLD )
    {
        v_bd_index = p_interface->next_frame_to_get - ETHERNET_RX_FIFO_THRESHOLD;
    }
    else
    {
        v_bd_index = p_interface->next_frame_to_get +
                       (C_LIBBSP_ETSEC_ETHERNET_RX_FIFO_SIZE - ETHERNET_RX_FIFO_THRESHOLD);
    }
    
    /* Get the buffer to be checked       */
	p_bd = &(p_rxbdtable [v_bd_index]); /* %RELAX<SYNCHRONe_C_Code_10.7> No precision lost: table of the wanted type */

	/* Check now that it is still empty   */
	if ((p_bd->status & C_FEC_ETSEC_RXBD_E) == C_FEC_ETSEC_RXBD_NOT_E) 
    {
		LL_RX_flush(controller);
		/*LOG0("LL_RX_get_frame : ERREUR E_LIBBSP_ETSEC_SOFTWARE_OVERRUN");*/
	}
}