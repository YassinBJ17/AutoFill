/*------------------------------------------------------------------------------*/
/* PROJECT : X4                                                                 */
/* COMPANY : Sagem Defense Securite                                             */
/* CSU NAME : LL_MANAGEMENT                                                     */
/* FILENAME : LL_MANAGEMENT.c                                                   */
/* DESCRIPTION : this CSU is used initialize the Enhanced Three-Speed Ethernet  */
/*               Controllers                                                    */
/*+--------+-------------------+-----+-----------------------------------------+*/
/*| DATE   |    Name/Company   | PR  |               PR                         */
/*|        |                   | Num |              Title                       */
/*+--------+-------------------+-----+-----------------------------------------+*/
/*|01/01/01| My_Name/Sagem     | -   |                                          */
/*+--------+-------------------+-----+-----------------------------------------+*/

/* ---------- include provided interface: ------------------------------------- */
#include "LIBMCP_Types.h"
#include "HW_TB.h"

#if P1020
    #include "HW_CONF.h"
    #include "etsec.h"
    #include "smi.h"
    #include "tbi.h"
    #include "phy.h"
#endif

/* ---------- include required interface: ------------------------------------- */
#include "LL.h"
#include "LL_RX.h"
#include "LL_TX.h"
#include "etsec.h"
#include "tbi.h"
#include "phy.h"

#define C_DELAY_RESET (0x3f7a00)
#define C_NB_RESET (10)

/*************************************************************************************
 *                                                                                   *
 * Nom : LL_MANAGEMENT_stop_controller                                               *
 *                                                                                   *
 * Description :                                                                     *
 * This function enables the stop of tx or rx etherner activity                      *
 *                                                                                   *
 * Contraintes d'utilisation :                                                       *
 *                                                                                   *
 *************************************************************************************/
void LL_MANAGEMENT_stop( const uint32_t controller, 
                         const boolean_t rx_stop, 
                         const boolean_t tx_stop)
{
   uint32_t v_driver;
   
   v_driver    = CONF_CPU.init[controller].driver;


   if( v_driver == ETSEC )
   {
        /* desactivate emission */    
        if (tx_stop != FALSE)
        {
            etsec_tx_enable (controller, FALSE);
        }

        /* desactivate reception */    
        if (rx_stop != FALSE)
        {
            etsec_rx_enable (controller, FALSE);
        }
   }
   else if (v_driver == FEC)
   {
   }
}

void LL_MANAGEMENT_configure( const uint32_t controller )
{
   uint32_t    v_driver;
   uint32_t    v_interface;
   uint32_t    v_phy;

   v_driver =    CONF_CPU.init[controller].driver;
   v_phy =       CONF_CPU.init[controller].phy_device;
   v_interface = CONF_CPU.init[controller].interface;

   if( v_driver == ETSEC )
   {
      /* Note that P1020 define is used instead of the driver indication */
       etsec_reset( controller );

       if (v_interface == HW_CONF_LINK_TYPE_SGMII)
       {
          tbi_config( controller );     
       }

       if (v_phy != NO_PHY)
       {   
          phy_connect( v_phy );
          phy_reset  ( v_phy );
          phy_config ( v_phy );
       }
    }
    else /* FEC */
    {
    }
}
/*************************************************************************************
 *                                                                                   *
 * Nom : LL_MANAGEMENT_init                                                          *
 *                                                                                   *
 * Description :                                                                     *
 *    This function initialises                                                      *
 *                                                                                   *
 * Contraintes d'utilisation :                                                       *
 *                                                                                   *
 *************************************************************************************/


void LL_MANAGEMENT_init (const uint32_t controller, const TS_LIBBSP_ETSEC_ConfHostMac * const p_mac )
{
    const uint8_t * pt_rxbds_address;
    const uint8_t * pt_txbds_address;
    uint32_t v_driver;

    v_driver = CONF_CPU.init[ controller ].driver;
    
    /* Recuperer les adresses des BD de reception et d'emission */
    pt_rxbds_address = LL_RX_initialize (controller);
    pt_txbds_address = LL_TX_initialize (controller);

    if( v_driver == ETSEC )
    {
        /* initialise ETSEC registers */ 
        etsec_init (controller, 
                    pt_txbds_address,
                    pt_rxbds_address, 
                    p_mac);
    }
    else if ( v_driver == FEC )
    {
    }
    else
    {
        /* none */
    }
	
    /*Removed phy_is_link_up test and phy_reset calls to ITF_T3*/
	/*HW_TB_wait(C_DELAY_RESET);
	for(v_i=0; (v_i<C_NB_RESET) && !phy_is_link_up(v_phy); v_i++)
	{
		phy_reset  ( v_phy );
		HW_TB_wait(C_DELAY_RESET);
	}*/
	
}


/*************************************************************************************
 *                                                                                   *
 * Nom : LL_MANAGEMENT_start_controller                                              *
 *                                                                                   *
 * Description :                                                                     *
 *    This function starts the ethernet controller                                   *
 *                                                                                   *
 * Contraintes d'utilisation :                                                       *
 *                                                                                   *
 *************************************************************************************/
void LL_MANAGEMENT_start (const uint32_t controller, 
                          const boolean_t rx_start, 
                          const boolean_t tx_start)
{  
    /* activate emission and recepetion */    
    if (tx_start != FALSE)
    {
        etsec_tx_enable(controller, TRUE);
    }
    if (rx_start != FALSE)
    {
        etsec_rx_enable(controller, TRUE);
    }
}
