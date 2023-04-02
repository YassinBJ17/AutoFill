#include "LL_RX.h"

extern TS_LIBBSP_ETSEC_t_ll_p_rx_bd_tables * P_LIBBSP_ETSEC_ll_rx_bd_tables;

/*************************************************************************************
 *                                                                                   *
 * Nom : LL_RX_flush                                                                 *
 *                                                                                   *
 * Description :                                                                     *
 * Cette fonction permet de redonner tous les BD de reception au CPM                 *
 *                                                                                   *
 * Contraintes d'utilisation :                                                       *
 *  A appeler en cas de overrun                                                      *
 *                                                                                   *
 *************************************************************************************/
void LL_RX_flush(const uint32_t controller) 
{
	TS_LIBBSP_ETSEC_t_ll_rx_bd * p_rxbdtable;
	TS_LIBBSP_ETSEC_t_ll_rx_interface * p_interface;
	TS_LIBBSP_ETSEC_t_ll_rx_bd *p_bd;
	uint32_t v_bd_index;
    uint32_t count;
    boolean_t v_empty;
    
	p_rxbdtable = P_LIBBSP_ETSEC_ll_rx_bd_tables->V_LL_RX_bd_tables[controller].rxbd;
	p_interface = &(V_LL_RX_interface[controller]);

	v_bd_index = p_interface->next_frame_to_get;

    v_empty = FALSE;

    for ( count = 0ul ; count < C_LIBBSP_ETSEC_ETHERNET_RX_FIFO_SIZE ; count ++ )
    {
        /*INCREMENT (v_bd_index, ETHERNET_RX_FIFO_SIZE);*/
        
        v_bd_index ++;

        if (v_bd_index >= C_LIBBSP_ETSEC_ETHERNET_RX_FIFO_SIZE)
        {
        	v_bd_index = 0ul;
        }



    	p_bd = &p_rxbdtable[v_bd_index]; /* %RELAX<SYNCHRONe_C_Code_10.7> No precision lost: table of the wanted type */
        
        /* Check if it is the first empty buffer */
        if ((v_empty == FALSE) &&  ((p_bd->status & C_FEC_ETSEC_RXBD_E) != (uint16_t)0 ))
        {
           v_empty = TRUE;

           /* Let's say that the next frame will */
           /* be the one of the first empty buffer */
           p_interface->next_frame_to_get = v_bd_index;
        }
        
        p_bd->status = (uint16_t)(C_FEC_ETSEC_RXBD_E + (p_bd->status & C_FEC_ETSEC_RXBD_W));
    }
}