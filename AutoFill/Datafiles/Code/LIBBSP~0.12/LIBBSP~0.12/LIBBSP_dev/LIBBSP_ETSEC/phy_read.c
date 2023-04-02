#include "phy.h"

int32_t phy_read( const t_phy_handle phy, const uint32_t reg_number )
{
   return mii_phy_read( CONF_PHY.init[ phy ].bus,
                         CONF_PHY.init[ phy ].address,
                         reg_number);
}