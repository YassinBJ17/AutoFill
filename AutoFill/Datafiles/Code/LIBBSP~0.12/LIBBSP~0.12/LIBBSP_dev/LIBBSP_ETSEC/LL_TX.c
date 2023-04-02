#include "LIBMCP_Types.h"
#include "HW_CONF.h"
#include "LL.h"
#include "LL_TX.h"
#include "MAC_interface.h"
//#include "ethernet.h"

TS_ll_tx_interface V_LL_TX_interface [C_LIBBSP_ETSEC_ETHERNET_NB_CONTROLLERS];

extern TS_LIBBSP_ETSEC_t_ll_p_tx_bd_tables * P_LIBBSP_ETSEC_ll_tx_bd_tables;
extern TS_LIBBSP_ETSEC_t_ll_p_tx_pools * P_LIBBSP_ETSEC_ll_tx_pools;

//#define INCREMENT(n,size)    { n++; if (n>=size) { n=0;} }

/*************************************************************************************
 *                                                                                   *
 * Nom : LL_TX_get_frame                                                             *
 *                                                                                   *
 * Description :                                                                     *
 * Cette fonction permet de recuperer un BD d'emission dans l'interface specifiee    *
 *                                                                                   *
 * Contraintes d'utilisation :                                                       *
 *  aucunes                                                                          *
 *                                                                                   *
 *************************************************************************************/
void LL_TX_get_frame (const uint32_t controller, TS_LIBBSP_ETSEC_t_ll_tx_bd ** const p_bd)
{
    TS_LIBBSP_ETSEC_t_ll_tx_bd * p_txbdtable;

    p_txbdtable = P_LIBBSP_ETSEC_ll_tx_bd_tables->V_LL_TX_bd_tables[controller].txbd;
    *p_bd = &(p_txbdtable [V_LL_TX_interface [controller].next_frame_to_send]); /* %RELAX<SYNCHRONe_C_Code_10.7, SYNCHRONe_C_Code_17.4> No precision lost: table of the wanted type and  don't know table size of index */
}

/*************************************************************************************
 *                                                                                   *
 * Nom : LL_TX_send_frame                                                            *
 *                                                                                   *
 * Description :                                                                     *
 * Cette fonction permet de donner au CPM un BD a emettre pour l'interface specifiee *
 *                                                                                   *
 * Contraintes d'utilisation :                                                       *
 *  aucunes                                                                          *
 *                                                                                   *
 *************************************************************************************/
extern TS_ETHERNET_stat_mac V_ETHERNET_stat_mac[C_LIBBSP_ETSEC_ETHERNET_NB_CONTROLLERS];

void LL_TX_send_frame (const uint32_t controller,  TS_LIBBSP_ETSEC_t_ll_tx_bd * const p_bd )
{
    TS_ll_tx_interface * p_interface;

    TS_ETHERNET_stat_mac *p_stats_mac;

    p_interface = &(V_LL_TX_interface [controller]);
    
    p_stats_mac = &(V_ETHERNET_stat_mac [controller]);

    /* increment the producer pointer       */
    /* INCREMENT( p_interface -> next_frame_to_send, ETHERNET_TX_FIFO_SIZE ); */
    
    p_interface -> next_frame_to_send ++;

    if (p_interface -> next_frame_to_send  >= C_LIBBSP_ETSEC_ETHERNET_TX_FIFO_SIZE)
    {
    	p_interface -> next_frame_to_send  = 0ul;
    }


    /* Update statistics                    */
    p_stats_mac->MACOutFrames = p_stats_mac->MACOutFrames + 1ul;
    p_stats_mac->MACOutOctets = p_stats_mac->MACOutOctets + (uint32_t)p_bd->length;
        
    /* Send the frame                       */
    /* Set the status of the BD to Ready and Last buffer in the transmit frame  */
    p_bd->status |= C_FEC_ETSEC_TXBD_R_L;
}



/*************************************************************************************
 *                                                                                   *
 * Nom : LL_RX_initialize                                                            *
 *                                                                                   *
 * Description :                                                                     *
 * Cette fonction d'initialiser la gestion des BDs pour l'emission ethernet sur      *
 *   une interface specifiee.                                                        *
 * Pour simplifier le driver, une frame ethernet a emettre est contenue dans un      *
 *   seul BD                                                                         *
 *                                                                                   *
 * Contraintes d'utilisation :                                                       *
 *  aucunes                                                                          *
 *                                                                                   *
 *************************************************************************************/
/*const uint8_t *LL_TX_initialize (const uint32_t controller, TS_LIBBSP_ETSEC_t_ll_tx_pool * const pool) */
const uint8_t *LL_TX_initialize (const uint32_t controller)
{
    /* TS_ll_tx_interface * p_interface; */
    const uint8_t * p_bdtable;
    TS_LIBBSP_ETSEC_t_ll_tx_pool * p_txpool;
    uint32_t index;

    p_txpool = &(P_LIBBSP_ETSEC_ll_tx_pools->V_LL_TX_pools [controller]);

    /*p_interface->hw_txbd = (uint32_t)0;
    p_interface->next_frame_to_send = (uint32_t)0;
    p_interface->controler = controller;*/

    /* Set the buffer descriptor status to NOT READY */
    for (index=0ul ; index < C_LIBBSP_ETSEC_ETHERNET_TX_FIFO_SIZE ; index++)
    {
        P_LIBBSP_ETSEC_ll_tx_bd_tables->V_LL_TX_bd_tables [controller].txbd [index].address = &(p_txpool->txbuffer [index].txbyte[0]);
        P_LIBBSP_ETSEC_ll_tx_bd_tables->V_LL_TX_bd_tables [controller].txbd [index].status = C_FEC_ETSEC_TXBD_NOT_R;
    }
    
    /* Set the WRAP bit to the last buffer descriptor */
    P_LIBBSP_ETSEC_ll_tx_bd_tables->V_LL_TX_bd_tables [controller].txbd [C_LIBBSP_ETSEC_ETHERNET_TX_FIFO_SIZE - 1ul].status = 
         P_LIBBSP_ETSEC_ll_tx_bd_tables->V_LL_TX_bd_tables [controller].txbd [C_LIBBSP_ETSEC_ETHERNET_TX_FIFO_SIZE - 1ul].status | C_FEC_ETSEC_TXBD_W;

    p_bdtable = (const uint8_t *)(P_LIBBSP_ETSEC_ll_tx_bd_tables->V_LL_TX_bd_tables [controller].txbd); /* %RELAX<SYNCHRONe_C_Code_10.7, SYNCHRONe_C_Code_11.1> No precision lost: table of the wanted type and need of converting pointer */
    return (p_bdtable);
}
