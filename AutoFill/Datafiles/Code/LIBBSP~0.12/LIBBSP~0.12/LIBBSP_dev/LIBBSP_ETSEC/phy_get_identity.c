#include "phy.h"

int32_t phy_get_identity   ( const t_phy_handle phy)
{
   int32_t v_ret;
   int32_t val1;
   int32_t val2;
   
   val1 = phy_read( phy, (uint32_t)MII_PHYSID1 );
   val2 = phy_read( phy, (uint32_t)MII_PHYSID2 );

   if( val1 > (int32_t)0 && val2 > (int32_t)0 )
   {
      /*CONF_PHY.init[ phy ].identity = (val1 << 16)  | (val2 & 0xffff);*/
      v_ret = (int32_t)0;
   }
   else
   {
      v_ret = (int32_t)(-1);
   }

   return v_ret;
}
