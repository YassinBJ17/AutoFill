
/* ---------- include provided interface: ------------------------------------- */
#include "LIBMCP_Types.h"
#include "HW_CONF.h"
#include "HW_TB.h"
#include "smi.h"

/* ---------- include required interface: ------------------------------------- */
#include "etsec.h"
#include "phy.h"


/* ---------- internal define constants: -------------------------------------- */

const uint8_t TAB_PHY_ENABLE[3]=
{
   0,   /* ETSEC 1 */
  14,   /* ETSEC 2 -> GPIO 14 - cf RDB for P1 and P2 Devices : GPIO 14 is wired to PHY VSC8221 reset pin */
   6    /* ETSEC 3 -> GPIO 6  - cf RDB for P1 and P2 Devices : GPIO 6 is wired to PHY VSC8641 reset pin */
};




#define MDIO_DEVAD_NONE            (-1)

void phy_config  ( const t_phy_handle phy )
{
  // TS_conf_hw_phy_init *phydev = &CONF_PHY.init[ phy ];
   //uint32_t driver;
   /*uint32_t auto_negociation;*/
   uint32_t speed;
   uint32_t duplex;
   uint16_t ctl;
   //uint16_t val;
   
   //driver = CONF_PHY.init[ phy ].driver;
   /*auto_negociation = CONF_PHY.init[ phy ].auto_negociation;*/
   speed =  CONF_PHY.init[ phy ].speed;
   duplex = CONF_PHY.init[ phy ].duplex;
   
   //switch( driver )
   //{
      /* generic driver */
      //default:
         //val = phy_read (phy, MII_BMSR); 
         
         
		/* GCH: for SGMII link only with marvell PHY */
		{
			/* Set PHY to use SGMII link */
			phy_write( phy, (uint32_t)MII_PAGEADDR, (uint16_t)18); /* Use page 18 */
			phy_write( phy, (uint32_t)20, (uint16_t)0x8001); /* Reset and configure general ctrl reg in SGMII to Copper mode */


			/* SGMII conf are done on page 1 */
			ctl = (uint16_t)1;
			phy_write( phy, (uint32_t)MII_PAGEADDR, ctl);
		}

		ctl = (uint16_t)0;
		if (duplex == HW_CONF_LINK_FULL_DUPLEX )
		{
		   ctl = ctl | (uint16_t)BMCR_FULLDPLX | (uint16_t)BMCR_ANENABLE;
		   //ctl = ctl | BMCR_FULLDPLX;
		}
		if( speed == HW_CONF_LINK_SPEED_1000_MBITS )
		{
		   ctl = ctl | (uint16_t)BMCR_SPEED1000;    
		}
		else if( speed == HW_CONF_LINK_SPEED_100_MBITS )
		{
		   ctl = ctl | (uint16_t)BMCR_SPEED100;
		}
		ctl = ctl | (uint16_t)BMCR_RESET;
		phy_write( phy, (uint32_t)MII_BMCR, ctl );
         
        //break;
   //}
}



void phy_reset        ( const t_phy_handle phy)
{
   int32_t val;
   int32_t timeout;
   uint32_t bus;
   
   bus = CONF_PHY.init[ phy ].bus;

   mii_reset( bus );

   val = phy_read(phy, (uint32_t)MII_BMCR);
   
   val = val | (int32_t)BMCR_RESET;
   
   phy_write(phy, (uint32_t)MII_BMCR, (uint16_t)val); /* %RELAX<SYNCHRONe_C_Code_10.7> necessary for the variable to be uint16 */

   /*for( timeout = 0 ; ((val & BMCR_RESET) != 0) && (timeout < 1000) ; timeout ++ )
   {
      val = phy_read(phy, MII_BMCR);
      
      HW_TB_wait(1000);
   }*/

   for( timeout = (int32_t)0 ; timeout < (int32_t)1000 ; timeout ++ )
   {
      val = (int32_t)phy_read(phy, (uint32_t)MII_BMCR);

      HW_TB_wait(1000ul);

      if((val & (int32_t)BMCR_RESET) == (int32_t)0)
      {
    	  break;
      }
   }
}

