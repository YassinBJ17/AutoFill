#include "LIBMCP_Types.h"
#include "HW_CONF.h"
#include "HW_TB.h"
#include "smi.h"
#include "etsec.h"
#include "phy.h"

 void phy_config  ( const t_phy_handle phy ) {    uint32_t speed;    uint32_t duplex;    uint16_t ctl;    speed =  CONF_PHY.init[ phy ].speed;    duplex = CONF_PHY.init[ phy ].duplex; 		{ 			phy_write( phy, (uint32_t)MII_PAGEADDR, (uint16_t)18);  			phy_write( phy, (uint32_t)20, (uint16_t)0x8001);  			ctl = (uint16_t)1; 			phy_write( phy, (uint32_t)MII_PAGEADDR, ctl); 		}
