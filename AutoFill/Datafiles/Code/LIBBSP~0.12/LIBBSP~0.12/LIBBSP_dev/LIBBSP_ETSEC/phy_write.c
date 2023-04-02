#include "phy.h"

void phy_write( const t_phy_handle phy, const uint32_t reg_number, const uint16_t value)
{
   mii_phy_write( CONF_PHY.init[ phy ].bus,
                   CONF_PHY.init[ phy ].address,
                   reg_number,
                   (int32_t)value);
}