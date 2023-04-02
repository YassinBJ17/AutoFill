#include "phy.h"

void phy_connect      ( const t_phy_handle phy)
{
   uint16_t ctl;
   /*int32_t unused;*/

   /* set default page to zero */
   ctl = (uint16_t)0;
   phy_write( phy, (uint32_t)MII_PAGEADDR, ctl);

   /* connect the mii bus to the phy, based on the identity of the phy */
   phy_get_identity  (phy);

   /* LED configuration */
   ctl = (uint16_t)3;
   phy_write( phy, (uint32_t)MII_PAGEADDR, ctl); /* set page 3 */
   phy_write( phy, 17ul, (uint16_t)0x4); /* on = high, off = low */ 
   phy_write( phy, 16ul, (uint16_t)0x10); /* LED on : link up, LED blink : activity, LED off : link down */
   ctl = (uint16_t)0;
   phy_write( phy, (uint32_t)MII_PAGEADDR, ctl); /* go back to page 0 */
   
   /* the configuration is already done : each phy is connected to a bus */
}